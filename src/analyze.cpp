#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "analyze.hpp"
#include "grammar.hpp"

static bool parseFile(const std::string& filepath);

int analyze(int argc, char *argv[], const std::string& datadir)
{
  if (argc < 1) {
    std::cerr << "Nothing to analyze. Give me some input files!" << std::endl;
    return EXIT_FAILURE;
  }

  for (int i = 0; i < argc; ++i) {
    if (!parseFile(argv[i])) {
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}

bool parseFile(const std::string& filepath)
{
  std::ifstream stream(filepath);

  if (!stream.good()) {
      std::cerr << "Failed to open file " << filepath << std::endl;
      return false;
  }

  size_t line_number = 0;

  while(stream.good()) {
    std::string line;
    std::getline(stream, line);
    ++line_number;

    if (line.empty()) {
       continue;
    }

    try {
      pegtl::parse<st2se::strace_line>(line, filepath);
    }
    catch(const pegtl::parse_error& ex) {
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

  return true;
}
