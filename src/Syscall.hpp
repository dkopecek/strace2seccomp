#pragma once

#include <vector>
#include <string>
#include <ostream>
#include <memory>
#include <unordered_map>

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
        std::string toKey() const;

        ArgumentType type;
        std::string value;
      };

      struct Invocation
      {
        Invocation();
        Invocation(const Invocation& orig);
        void addArgument(const Argument& argument);
        void setComplete(bool _complete = true);

        std::vector<Argument> arguments;
        bool complete;
        std::string key; /* key constructed from all argument values */
        std::string key_c; /* key constructed from CONSTANT argument values */
        std::string key_i; /* key constructed from INTEGER argument values */
        std::string key_ci; /* key constructed from CONTANTS and INTEGER argument values */
        unsigned type_mask;
      };

      using InvocationPtr = std::shared_ptr<Invocation>;
      using InvocationVec = std::vector<InvocationPtr>;
      using InvocationVecMap = std::unordered_map<std::string, InvocationVec>;

      Syscall(const std::string& name = std::string());

      operator bool() const;

      const std::string& name() const;
      void setName(const std::string& name);

      size_t invocationCount() const;
      void addInvocation(InvocationPtr invocation);
      const InvocationPtr lastInvocation() const;
      InvocationPtr lastInvocation();
      const InvocationVec& invocations() const;
      const InvocationVecMap& mappedInvocations() const;

      void write(std::ostream& stream) const;
      void merge(const Syscall& syscall);

      void mapInvocation(InvocationPtr invocation);

    private:
      void writeInvocation(std::ostream& stream, InvocationPtr invocation, unsigned type_mask = 0xff) const;
      std::string _name;
      InvocationVec _invocations;
      InvocationVecMap _mapped_invocations;
  };
} /* namespace st2se */
