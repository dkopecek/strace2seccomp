#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <getopt.h>

#include "ParserActions.hpp"
#include "Grammar.hpp"
#include "DataSet.hpp"
#include "SeccompCode.hpp"

#ifndef NDEBUG
#include <pegtl/analyze.hh>
#endif

#include <pegtl/trace.hh>

static const char *options_short = "tm:ls:o:h";
static const struct ::option options_long[] = {
  { "trace", no_argument, nullptr, 't' },
  { "mask", required_argument, nullptr, 'm' },
  { "list", no_argument, nullptr, 'l' },
  { "seccomp", required_argument, nullptr, 's' },
  { "output", required_argument, nullptr, 'o' },
  { "help", no_argument, nullptr, 'h' },
  { nullptr, 0, nullptr, 0 }
};

static void showUsage(const char *arg0, std::ostream& stream)
{
  stream << "Usage: " << ::basename(arg0) << " [OPTIONS] <strace-log> [<strace-log> ...]" << std::endl;
  stream << std::endl;
  stream << "Options:" << std::endl;
  stream << "  -t, --trace            Enable strace log parser tracing to stderr" << std::endl;
  stream << "  -l, --list             Show a list of parsed syscalls." << std::endl;
  stream << "  -m, --mask <mask>      Use a syscall argument mask <mask>." << std::endl;
  stream << "                         See Argument Masking for more details." << std::endl;
  stream << "  -s, --seccomp <flags>  Tweak the output seccomp code." << std::endl;
  stream << "                         See Seccomp Code Flags section for more details." << std::endl;
  stream << "  -o, --output <path>    Write the result to <path> instead of stdout." << std::endl;
  stream << "  -h, --help             Show help." << std::endl;
  stream << std::endl;
}

static bool parseFile(const std::string& filepath, bool trace, st2se::DataSet& dataset);

int main(int argc, char *argv[])
{
  const char * arg0 = argv[0];
  bool trace = false;
  int opt;
  bool syscall_list = false;
  std::string output_file;
  st2se::SeccompCode seccomp_code;

  while ((opt = getopt_long(argc, argv, options_short, options_long, nullptr)) != -1) {
    switch(opt) {
      case 't':
        trace = true;
        break;
      case 'l':
        syscall_list = true;
        break;
      case 'm':
         
        break;
      case 's':
        syscall_list = false;
#if 0
        {
          char * const token[] = {
            const_cast<char*>("int"), /* match unmasked integer arguments */
            const_cast<char*>("const"), /* match unmasked arguments which are marked as constants */
            const_cast<char*>("ranges"), /* analyze integer arguments for ranges and create rules that allow these ranges instead of specific values */
            const_cast<char*>("ctxvar"), /* use a different variable name for the seccomp context */
            const_cast<char*>("nowrap") /* do not wrap the seccomp_rule_add calls inside a function */
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
              case 3: /* intgrp */
                seccomp_code_integer_range_matching = true;
                break;
              default:
                std::cerr << "Unknown --seccomp-code subtoption." << std::endl;
                return EXIT_FAILURE;
            }
          }
        }
#endif
        break;
      case 'o':
        output_file = std::string(optarg);
        break;
      case 'h':
        showUsage(arg0, std::cerr);
        return EXIT_SUCCESS;
      default:
        showUsage(arg0, std::cerr);
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
  else {
    if (output_file.empty()) {
      seccomp_code.generate(std::cout, dataset);
    }
    else {
      std::ofstream stream(output_file, std::ios::trunc);
      seccomp_code.generate(stream, dataset);
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
