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
      auto const& syscall = node.second;
      stream << "# " << syscall.name() << ", called " << syscall.invocationCount() << " time(s)" << std::endl;
      syscall.write(stream);
      stream << std::endl;
    }
  }

  const DataSet::SyscallMap& DataSet::syscallMap() const
  {
    return _syscalls;
  }
} /* namespace st2se */

