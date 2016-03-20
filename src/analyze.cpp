#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <getopt.h>

#include "analyze.hpp"
#include "grammar.hpp"
#include "DataSet.hpp"
#include "SeccompCode.hpp"

#ifndef NDEBUG
#include <pegtl/analyze.hh>
#endif

#include <pegtl/trace.hh>

static const char *options_short = "tls:o:";
static const struct ::option options_long[] = {
  { "trace", no_argument, nullptr, 't' },
  { "syscall-list", no_argument, nullptr, 'l' },
  { "seccomp-code", required_argument, nullptr, 's' },
  { "output-file", required_argument, nullptr, 'o' },
  { nullptr, 0, nullptr, 0 }
};

static bool parseFile(const std::string& filepath, bool trace, st2se::DataSet& dataset);

int analyze(int argc, char *argv[], const std::string& datadir)
{
  bool trace = false;
  int opt;
  bool syscall_list = false;
  bool seccomp_code = true;
  bool seccomp_code_match_integers = false;
  bool seccomp_code_match_constants = false;
  std::pair<int,int> seccomp_code_integer_range(-1, 1024);
  bool seccomp_code_integer_range_matching = false;
  std::string output_file;

  while ((opt = getopt_long(argc, argv, options_short, options_long, nullptr)) != -1) {
    switch(opt) {
      case 't':
        trace = true;
        break;
      case 'l':
        syscall_list = true;
        seccomp_code = false;
        break;
      case 's':
        seccomp_code = true;
        syscall_list = false;
        {
          char * const token[] = {
            const_cast<char*>("int"),
            const_cast<char*>("const"),
            const_cast<char*>("name"),
            const_cast<char*>("int-match-range"),
            nullptr
          };

          char *subopts = optarg;
          int not_found = 0;
          char *value = nullptr;

          while (*subopts != '\0' && !not_found) {
            switch(getsubopt(&subopts, token, &value)) {
              case 0: /* int */
                seccomp_code_match_integers = true;
                if (value) {
                  int min, max;
                  if (std::sscanf(value, "%d:%d", &min, &max) != 2) {
                    std::cerr << "Invalid \"int\" suboption syntax. Correct syntax is <int>:<int>." << std::endl;
                    return EXIT_FAILURE;
                  }
                  seccomp_code_integer_range = std::pair<int,int>(min, max);
                }
                break;
              case 1: /* const */
                seccomp_code_match_constants = true;
                break;
              case 2: /* name */
                break;
              case 3: /* int-match-range */
                seccomp_code_integer_range_matching = true;
                break;
              default:
                std::cerr << "Unknown --seccomp-code subtoption." << std::endl;
                return EXIT_FAILURE;
            }
          }
        }
        break;
      case 'o':
        output_file = std::string(optarg);
      default:
        return EXIT_FAILURE;
    }
  }

  argv += optind;
  argc -= optind;

#ifndef NDEBUG
  const size_t issues_found = pegtl::analyze<st2se::grammar>();
  if (issues_found > 0) {
    std::cerr << "pegtl::analyze found some grammar issues: count=" << issues_found << std::endl;
    return EXIT_FAILURE;
  }
#endif
  if (argc < 1) {
    std::cerr << "Nothing to analyze. Give me some input files!" << std::endl;
    return EXIT_FAILURE;
  }

  st2se::DataSet dataset;

  for (int i = 0; i < argc; ++i) {
    if (!parseFile(argv[i], trace, dataset)) {
      return EXIT_FAILURE;
    }
  }

  if (syscall_list) {
    if (output_file.empty()) {
      dataset.write(std::cout);
    }
    else {
      std::ofstream stream(output_file, std::ios::trunc);
      dataset.write(stream);
    }
  }
  else if (seccomp_code) {
    st2se::SeccompCodeParameters parameters = {
      .match_constants = seccomp_code_match_constants,
      .match_integers = seccomp_code_match_integers,
      .integer_range = seccomp_code_integer_range,
      .integer_range_matching = seccomp_code_integer_range_matching
    };

    if (output_file.empty()) {
      st2se::generateSeccompCode(std::cout, dataset, parameters);
    }
    else {
      std::ofstream stream(output_file, std::ios::trunc);
      st2se::generateSeccompCode(stream, dataset, parameters);
    }
  }

  return EXIT_SUCCESS;
}

bool parseFile(const std::string& filepath, bool trace, st2se::DataSet& dataset)
{
  std::ifstream stream(filepath);

  if (!stream.good()) {
      std::cerr << "Failed to open file " << filepath << std::endl;
      return false;
  }

  size_t line_number = 0;
  size_t fail_count = 0;

  while(stream.good()) {
    std::string line;
    std::getline(stream, line);

    if (line.empty()) {
       continue;
    }

    ++line_number;

    try {
      st2se::Syscall syscall;
      st2se::ParserState state = st2se::ParserState::INITIAL;

      if (trace) {
        pegtl::parse<st2se::grammar, st2se::ParserActions, pegtl::tracer>(line, filepath, syscall, state);
      }
      else {
        pegtl::parse<st2se::grammar, st2se::ParserActions>(line, filepath, syscall, state);
      }

      if (syscall) {
        dataset.upsert(syscall);
      }
    }
    catch(const pegtl::parse_error& ex) {
      ++fail_count;
      std::cerr << "! Parsing failed at line #" << line_number << " in file " << filepath << ":" << std::endl;
      std::cerr << "!!  " << line << std::endl;
      std::cerr << "!!  ";
      std::cerr.width(4 + ex.positions[0].column);
      std::cerr << "^---" << std::endl;
      std::cerr.width(1);
    }
  }

  if (!stream.eof()) {
    std::cerr << "An error ocured while parsing file " << filepath << std::endl;
    return false;
  }

  if (fail_count > 0) {
    std::cerr << "! Failed to parse " << fail_count << " line(s) out of " 
              << line_number << " in " << filepath << std::endl;
  }

  return true;
}
