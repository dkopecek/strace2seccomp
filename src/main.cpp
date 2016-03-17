#include <build-config.h>
#include <iostream>
#include <cstdlib>
#include <getopt.h>
#include "grammar.hpp"

#include "collect.hpp"
#include "analyze.hpp"

const char *options_short = "hcp";
const struct ::option options_long[] = {
  { "collect", no_argument, nullptr, 'c' },
  { "analyze", no_argument, nullptr, 'a' },
  { "help", no_argument, nullptr, 'h' },
  { "datadir", required_argument, nullptr, 'd' },
  { nullptr, 0, nullptr, 0 }
};

static void showUsage(const char *arg0, std::ostream& stream)
{
  stream << "Usage: " << ::basename(arg0) << " --collect <binary> [<arg#1> ...]" << std::endl;
  stream << "       " << ::basename(arg0) << " --analyze <strace-log> [<strace-log> ...]" << std::endl;
  stream << "       " << ::basename(arg0) << " --help" << std::endl;
  stream << std::endl;
  return;
}

int main(int argc, char *argv[])
{
  const char * arg0 = argv[0];
  bool collect_mode = false;
  bool analyze_mode = false;
  std::string datadir = ".";
  int opt = -1;

  while ((opt = getopt_long(argc, argv, options_short, options_long, nullptr)) != -1) {
    switch (opt) {
      case 'c':
        if (analyze_mode) {
          std::cerr << "Invalid usage; --collect cannot be used with --analyze" << std::endl;
          showUsage(arg0, std::cerr);
          return EXIT_FAILURE;
        }
        else {
          collect_mode = true;
          break;
        }
      case 'a':
        if (collect_mode) {
          std::cerr << "Invalid usage; --analyze cannot be used with --collect" << std::endl;
          showUsage(arg0, std::cerr);
          return EXIT_FAILURE;
        }
        else {
          analyze_mode = true;
          break;
        }
      case 'd':
        datadir = std::string(optarg);
        break;
      case 'h':
        showUsage(arg0, std::cerr);
        return EXIT_SUCCESS;
      case '?':
        std::cerr << "Unknown option" << std::endl;
      default:
        showUsage(arg0, std::cerr);
        return EXIT_FAILURE;
    }
  }

  if (analyze_mode == collect_mode) {
    showUsage(arg0, std::cerr);
    return EXIT_FAILURE;
  }

  argv += optind;
  argc -= optind;

  if (collect_mode) {
    return collect(argc, argv, datadir);
  }
  else if (analyze_mode) {
    return analyze(argc, argv, datadir);
  }
  else {
    return EXIT_SUCCESS;
  }
}

