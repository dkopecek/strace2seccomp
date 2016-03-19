#pragma once

#include <string>
#include <unordered_map>
#include <ostream>
#include "Syscall.hpp"

namespace st2se
{
  class DataSet
  {
    public:
      DataSet();
      void upsert(const Syscall& syscall);
      void write(std::ostream& stream);

    private:
      std::unordered_map<std::string, Syscall> _syscalls;
  };
} /* namespace st2se */

