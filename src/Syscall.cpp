#include <stdexcept>
#include "Syscall.hpp"

namespace st2se
{
  Syscall::Argument::Argument(ArgumentType _type, const std::string& _value)
  {
    setValue(_type, _value);
    hints = 0;
  }

  std::string Syscall::Argument::toTypeString() const
  {
    switch(type) {
      case ArgumentType::INTEGER:
        return std::string("integer");
      case ArgumentType::POINTER:
        return std::string("pointer");
      case ArgumentType::UNKNOWN:
        break;
    }
    return std::string("unknown");
  }

  std::string Syscall::Argument::toKey() const
  {
    switch(type) {
      case ArgumentType::INTEGER:
        return std::string("$i:") + value;
      case ArgumentType::POINTER:
        return std::string("$p:") + value;
      case ArgumentType::UNKNOWN:
        break;
    }
    return std::string("$u:*");
  }

  bool Syscall::Argument::matches(ArgumentType _type) const
  {
    return type == _type;
  }

  bool Syscall::Argument::matches(ArgumentHint _hint) const
  {
    return !!(hints & (1 << (int)_hint));
  }

  bool Syscall::Argument::matches(const std::string& _value) const
  {
    return value == _value;
  }

  void Syscall::Argument::setHint(ArgumentHint _hint)
  {
    hints |= 1 << (int)_hint;
  }

  void Syscall::Argument::setValue(ArgumentType _type, const std::string& _value)
  {
    type = _type;
    value = _value;
  }

  Syscall::Invocation::Invocation()
  {
    setComplete(false);
    key = "KK";
    key_c = "CC";
    key_i = "II";
    key_ci = "CI";
    type_mask = 0;
    hint_mask = 0;
  }

  Syscall::Invocation::Invocation(const Invocation& orig)
  {
    arguments = orig.arguments;
    complete = orig.complete;
    key = orig.key;
    key_c = orig.key_c;
    key_i = orig.key_i;
    key_ci = orig.key_ci;
    type_mask = orig.type_mask;
    hint_mask = orig.hint_mask;
  }

  void Syscall::Invocation::addArgument(const Argument& argument)
  {
    arguments.push_back(argument);

    /* Update keys */
    key.append(argument.toKey());

    if (argument.matches(ArgumentHint::CONSTANT)) {
      key_c.append(argument.toKey());
    }
    else {
      key_c.append("$_");
    }

    if (argument.matches(ArgumentType::INTEGER)) {
      key_i.append(argument.toKey());
    }
    else {
      key_i.append("$_");
    }

    if (argument.matches(ArgumentHint::CONSTANT) ||
        argument.matches(ArgumentType::INTEGER)) {
      key_ci.append(argument.toKey());
    }
    else {
      key_ci.append("$_");
    }
    /* Update type and hint masks */
    type_mask |= 1<<(int)argument.type;
    hint_mask |= argument.hints;
  }

  void Syscall::Invocation::setComplete(bool _complete)
  {
    complete = _complete;
    const std::string key_suffix = complete ? "$." : "$*";
    key.append(key_suffix);
    key_c.append(key_suffix);
    key_i.append(key_suffix);
    key_ci.append(key_suffix);
  }

  bool Syscall::Invocation::contains(ArgumentType type) const
  {
    return !!(type_mask & (1 << (int)type));
  }

  bool Syscall::Invocation::contains(ArgumentHint hint) const
  {
    return !!(hint_mask & (1 << (int)hint));
  }

  bool Syscall::Invocation::contains(const std::string& value) const
  {
    for (auto const& argument : arguments) {
      if (argument.matches(value)) {
        return true;
      }
    }
    return false;
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

  void Syscall::addInvocation(InvocationPtr invocation)
  {
    _invocations.push_back(invocation);
  }

  const Syscall::InvocationPtr Syscall::lastInvocation() const
  {
    return _invocations.at(_invocations.size() - 1);
  }

  Syscall::InvocationPtr Syscall::lastInvocation()
  {
    return _invocations.at(_invocations.size() - 1);
  }

  const Syscall::InvocationVec& Syscall::invocations() const
  {
    return _invocations;
  }

  const Syscall::InvocationVecMap& Syscall::mappedInvocations() const
  {
    return _mapped_invocations;
  }

  void Syscall::writeInvocation(std::ostream& stream, InvocationPtr invocation, unsigned type_mask) const
  {
    if (!(type_mask & invocation->type_mask)) {
      return;
    }
    stream << _name << "(";
    size_t index = 0;
    const size_t count = invocation->arguments.size();
    for (const auto& argument : invocation->arguments) {
      if (type_mask & 1<<(int)argument.type) {
        if (argument.matches(Syscall::ArgumentHint::CONSTANT) ||
            argument.matches(Syscall::ArgumentType::INTEGER)) {
          stream << argument.value;
        }
        else {
          stream << argument.toTypeString();
        }
      }
      else {
        stream << "*";
      }
      if ((index + 1) < count) {
        stream << ", ";
      }
      ++index;
    }
    if (invocation->complete) {
      stream << ")";
    }
    else {
      stream << " ...<incomplete call>";
    }
    stream << std::endl;
  }

  void Syscall::write(std::ostream& stream) const
  {
    if (_invocations.empty()) {
      return;
    }
    for (const auto& invocation : _invocations) {
      writeInvocation(stream, invocation);
    }
#if 0
    stream << "## Group: INTEGER type masked invocations" << std::endl;
    stream << "```" << std::endl;
    for (const auto& node : _mapped_invocations) {
      auto const& key = node.first;
      auto const& invocation_vec = node.second;
      auto key_beg = key.substr(0, 2);
      auto key_end = key.substr(key.size() - 2, key.size());

      if (key_beg == "II" && key_end == "$.") {
        writeInvocation(stream, invocation_vec[0], 1<<ArgumentType::INTEGER);
      }
    }
    stream << "```" << std::endl;
    stream << std::endl;
    stream << "## Group: CONSTANT type masked invocations" << std::endl;
    stream << "```" << std::endl;
    for (const auto& node : _mapped_invocations) {
      auto const& key = node.first;
      auto const& invocation_vec = node.second;
      auto key_beg = key.substr(0, 2);
      auto key_end = key.substr(key.size() - 2, key.size());

      if (key_beg == "CC" && key_end == "$.") {
        writeInvocation(stream, invocation_vec[0], 1<<ArgumentType::CONSTANT);
      }
    }
    stream << "```" << std::endl;
    stream << std::endl;
    stream << "## Group: CONSTANT & INTEGER type masked invocations" << std::endl;
    stream << "```" << std::endl;
    for (const auto& node : _mapped_invocations) {
      auto const& key = node.first;
      auto const& invocation_vec = node.second;
      auto key_beg = key.substr(0, 2);
      auto key_end = key.substr(key.size() - 2, key.size());

      if (key_beg == "CI" && key_end == "$.") {
        writeInvocation(stream, invocation_vec[0], 1<<ArgumentType::CONSTANT|1<<ArgumentType::INTEGER);
      }
    }
    stream << "```" << std::endl;
#endif
  }

  void Syscall::merge(const Syscall& syscall)
  {
    if (name() != syscall.name()) {
      throw std::runtime_error("Cannot merge syscalls with different names");
    }
    for (auto const& invocation : syscall.invocations()) {
      addInvocation(invocation);
    }

    for (auto const& node : syscall.mappedInvocations()) {
      auto const& invocation_vec = node.second;
      auto const& invocation_key = node.first;

      for (auto const& invocation : invocation_vec) {
        _mapped_invocations[invocation_key].push_back(invocation);
      }
    }
  }

  void Syscall::mapInvocation(InvocationPtr invocation)
  {
    _mapped_invocations[invocation->key].push_back(invocation);
    _mapped_invocations[invocation->key_c].push_back(invocation);
    _mapped_invocations[invocation->key_i].push_back(invocation);
    _mapped_invocations[invocation->key_ci].push_back(invocation);
  }
} /* namespace st2se */
