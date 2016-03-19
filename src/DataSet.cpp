#include "DataSet.hpp"
#include <stdexcept>
#include <iomanip>

namespace st2se
{
  DataSet::DataSet()
  {
  }

  void DataSet::upsert(const Syscall& syscall)
  {
    if (syscall.name().empty()) {
      throw std::runtime_error("Invalid Syscall object passed to DataSet::upsert");
    }
    auto& map_syscall = _syscalls[syscall.name()];

    if (!map_syscall) {
      map_syscall.setName(syscall.name());
    }
    map_syscall.merge(syscall);
  }

  void DataSet::write(std::ostream& stream)
  {
    for (const auto& node : _syscalls) {
      stream << node.first << ":" << std::endl;
      stream << std::setw(4);
      node.second.write(stream);
      stream << std::setw(1);
    }
  }
} /* namespace st2se */

