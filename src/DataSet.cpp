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
    _syscalls[syscall.name()].merge(syscall);
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

