#pragma once

#include <vector>
#include <string>
#include <ostream>

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
        std::string toString() const;

        ArgumentType type;
        std::string value;
      };

      struct Invocation
      {
        Invocation();
        void addArgument(const Argument& argument);
        void setComplete(bool _complete = true);

        std::vector<Argument> arguments;
        bool complete;
      };

      Syscall(const std::string& name = "");

      operator bool() const;

      const std::string& name() const;
      void setName(const std::string& name);

      size_t invocationCount() const;
      void addInvocation(const Invocation& invocation);
      const Invocation& lastInvocation() const;
      Invocation& lastInvocation();
      const std::vector<Invocation>& invocations() const;

      void write(std::ostream& stream) const;
      void merge(const Syscall& syscall);

    private:
      std::string _name;
      std::vector<Invocation> _invocations;
  };
} /* namespace st2se */
