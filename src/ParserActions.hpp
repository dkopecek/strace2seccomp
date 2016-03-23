#include <string>
#include <pegtl.hh>
#include <iostream>
#include <stdexcept>
#include <memory>

#include "Grammar.hpp"
#include "Syscall.hpp"

namespace st2se
{
  enum ParserState
  {
    INITIAL,
    ARGUMENTS,
    RETURN_VALUE
  };

  template<typename Rule>
  struct ParserActions
    : pegtl::nothing<Rule> {};

  template<>
  struct ParserActions<syscall_name>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ParserState::INITIAL) {
        syscall.setName(in.string());
        syscall.addInvocation(std::make_shared<Syscall::Invocation>());
        state = ParserState::ARGUMENTS;
      }
      else {
        throw std::runtime_error("Invalid parser state in syscall_name action");
      }
    }
  };

  template<>
  struct ParserActions<syscall_return>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ParserState::ARGUMENTS) {
        state = ParserState::RETURN_VALUE;
      }
    }
  };

  template<>
  struct ParserActions<syscall_full>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ParserState::RETURN_VALUE) {
        syscall.lastInvocation()->setComplete(true);
        syscall.mapInvocation(syscall.lastInvocation());
      }
    }
  };

  template<>
  struct ParserActions<constants>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ARGUMENTS) {
        Syscall::Argument argument;

        if (in.string().compare("NULL") == 0) {
          argument.setValue(Syscall::ArgumentType::POINTER, "NULL");
        }
        else {
          argument.setValue(Syscall::ArgumentType::INTEGER, in.string());
        }
        argument.setHint(Syscall::ArgumentHint::CONSTANT);

        syscall.lastInvocation()->addArgument(argument);
        syscall.mapInvocation(syscall.lastInvocation());
      }
    }
  };

  template<>
  struct ParserActions<integer>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ARGUMENTS) {
        const Syscall::Argument argument(Syscall::ArgumentType::INTEGER, in.string());
        syscall.lastInvocation()->addArgument(argument);
        syscall.mapInvocation(syscall.lastInvocation());
      }
    }
  };

  template<>
  struct ParserActions<pointer>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ARGUMENTS) {
        const Syscall::Argument argument(Syscall::ArgumentType::POINTER, in.string());
        syscall.lastInvocation()->addArgument(argument);
        syscall.mapInvocation(syscall.lastInvocation());
     }
    }
  };

  template<>
  struct ParserActions<string>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ARGUMENTS) {
        Syscall::Argument argument(Syscall::ArgumentType::POINTER, in.string());
        argument.setHint(Syscall::ArgumentHint::STRING);
        syscall.lastInvocation()->addArgument(argument);
        syscall.mapInvocation(syscall.lastInvocation());
      }
    }
  };

  template<>
  struct ParserActions<array>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ARGUMENTS) {
        Syscall::Argument argument(Syscall::ArgumentType::POINTER, in.string());
        argument.setHint(Syscall::ArgumentHint::ARRAY);
        syscall.lastInvocation()->addArgument(argument);
        syscall.mapInvocation(syscall.lastInvocation());
      }
   }
  };

  template<>
  struct ParserActions<structure>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ARGUMENTS) {
        Syscall::Argument argument(Syscall::ArgumentType::POINTER, in.string());
        argument.setHint(Syscall::ArgumentHint::STRUCTURE);
        syscall.lastInvocation()->addArgument(argument);
        syscall.mapInvocation(syscall.lastInvocation());
      }
    }
  };
} /* namespace st2se */
