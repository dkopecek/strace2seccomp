#include "Syscall.hpp"

namespace st2se
{
  Syscall::Argument::Argument(ArgumentType _type, const std::string& _value)
  {
    type = _type;
    value = _value;
  }

  std::string Syscall::Argument::toString() const
  {
    switch(type) {
      case ArgumentType::CONSTANT:
        return value;
      case ArgumentType::INTEGER:
        return value;
      case ArgumentType::STRING:
        return std::string("string");
      case ArgumentType::POINTER:
        return std::string("pointer");
      case ArgumentType::ARRAY:
        return std::string("array");
      case ArgumentType::STRUCTURE:
        return std::string("struct");
      case ArgumentType::UNKNOWN:
        return std::string("<unknown>");
    }
  }

  Syscall::Invocation::Invocation()
  {
    setComplete(false);
  }

  void Syscall::Invocation::addArgument(const Argument& argument)
  {
    arguments.push_back(argument);
  }

  void Syscall::Invocation::setComplete(bool _complete)
  {
    complete = _complete;
  }

  Syscall::Syscall(const std::string& name)
  {
    setName(name);
  }

  Syscall::operator bool() const
  {
    return !_name.empty();
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

  const std::vector<Syscall::Invocation>& Syscall::invocations() const
  {
    return _invocations;
  }

  void Syscall::write(std::ostream& stream) const
  {
    for (const auto& invocation : _invocations) {
      stream << _name << "(";
      for (const auto& argument : invocation.arguments) {
        stream << argument.toString();
        stream << " ";
      }
      if (invocation.complete) {
        stream << ")";
      }
      else {
        stream << "...";
      }
      stream << std::endl;
    }
  }

  void Syscall::merge(const Syscall& syscall)
  {
  }
} /* namespace st2se */

