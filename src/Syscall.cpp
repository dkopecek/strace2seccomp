#include "Syscall.hpp"

namespace st2se
{
  Syscall::Argument::Argument(ArgumentType _type, const std::string& _value)
  {
    type = _type;
    value = _value;
  }

  void Syscall::Invocation::addArgument(const Argument& argument)
  {
    arguments.push_back(argument);
  }

  Syscall::Syscall(const std::string& name)
  {
    _name = name;
  }

  const std::string& Syscall::name() const
  {
    return _name;
  }

  void Syscall::setName(const std::string& name)
  {
    _name = name;
  }

  size_t Syscall::invocationCount() const
  {
    return _invocations.size();
  }

  void Syscall::addInvocation(const Invocation& invocation)
  {
    _invocations.push_back(invocation);
  }

  const Syscall::Invocation& Syscall::lastInvocation() const
  {
    return _invocations.at(_invocations.size());
  }

  Syscall::Invocation& Syscall::lastInvocation()
  {
    return _invocations.at(_invocations.size());
  }
} /* namespace st2se */

