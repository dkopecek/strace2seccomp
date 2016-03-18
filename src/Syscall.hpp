#pragma once

#include <vector>
#include <string>

namespace st2se
{
  class Syscall
  {
    public:
      enum ArgumentType
      {
        CONSTANT,
        INTEGER,
        STRING,
        POINTER,
        ARRAY,
        STRUCTURE,
        UNKNOWN
      };

      struct Argument
      {
        Argument(ArgumentType _type = ArgumentType::UNKNOWN, const std::string& _value = "");

        ArgumentType type;
        std::string value;
      };

      struct Invocation
      {
        void addArgument(const Argument& argument);

        std::vector<Argument> arguments;
      };

      Syscall(const std::string& name = "");

      const std::string& name() const;
      void setName(const std::string& name);

      size_t invocationCount() const;
      void addInvocation(const Invocation& invocation);
      const Invocation& lastInvocation() const;
      Invocation& lastInvocation();
 
    private:
      std::string _name;
      std::vector<Invocation> _invocations;
  };
} /* namespace st2se */
