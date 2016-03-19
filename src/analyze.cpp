#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <getopt.h>

#include "analyze.hpp"
#include "grammar.hpp"
#include "DataSet.hpp"

#ifndef NDEBUG
#include <pegtl/analyze.hh>
#endif

#include <pegtl/trace.hh>

static const char *options_short = "t";
static const struct ::option options_long[] = {
  { "trace", no_argument, nullptr, 't' },
  { nullptr, 0, nullptr, 0 }
};

static bool parseFile(const std::string& filepath, bool trace, st2se::DataSet& dataset);

int analyze(int argc, char *argv[], const std::string& datadir)
{
  bool trace = false;
  int opt;

  while ((opt = getopt_long(argc, argv, options_short, options_long, nullptr)) != -1) {
    switch(opt) {
      case 't':
        trace = true;
        break;
      default:
        std::cerr << "Unknown option" << std::endl;
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

  dataset.write(std::cout);

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

      if (trace) {
        pegtl::parse<st2se::grammar, st2se::ParserActions, pegtl::tracer>(line, filepath, syscall);
      }
      else {
        pegtl::parse<st2se::grammar, st2se::ParserActions>(line, filepath, syscall);
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
