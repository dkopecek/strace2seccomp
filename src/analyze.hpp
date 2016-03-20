#include <string>
#include <pegtl.hh>
#include <iostream>
#include <stdexcept>
#include <memory>

#include "grammar.hpp"
#include "Syscall.hpp"

int analyze(int argc, char *argv[], const std::string& datadir);

namespace st2se
{
  enum ParserState
  {
    INITIAL,
    ARGUMENTS
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
  struct ParserActions<syscall_full>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall, ParserState& state)
    {
      if (state == ParserState::ARGUMENTS) {
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
        const Syscall::Argument argument(Syscall::ArgumentType::CONSTANT, in.string());
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
        const Syscall::Argument argument(Syscall::ArgumentType::STRING, in.string());
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
        const Syscall::Argument argument(Syscall::ArgumentType::ARRAY, in.string());
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
        const Syscall::Argument argument(Syscall::ArgumentType::STRUCTURE, in.string());
        syscall.lastInvocation()->addArgument(argument);
        syscall.mapInvocation(syscall.lastInvocation());
      }
    }
  };
} /* namespace st2se */
