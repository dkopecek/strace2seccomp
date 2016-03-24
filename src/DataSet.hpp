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
      using SyscallMap = std::unordered_map<std::string, Syscall>;

      DataSet();
      void upsert(const Syscall& syscall);
      void write(std::ostream& stream);
      const SyscallMap& syscallMap() const;

    private:
      SyscallMap _syscalls;
  };
} /* namespace st2se */

