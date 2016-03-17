#include <iostream>
#include <cstdlib>
#include "collect.hpp"

int collect(int argc, char *argv[], const std::string& datadir)
{
  if (argc < 1) {
    std::cerr << "No binary path specified. Nothing to do here." << std::endl;
    return EXIT_FAILURE;
  }

  const char * binary_path = argv[0];
  char **binary_argv = argv + 1;

  return EXIT_SUCCESS;
}
