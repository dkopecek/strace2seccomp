#include <string>
#include <pegtl.hh>
#include <iostream>

#include "grammar.hpp"
#include "Syscall.hpp"

int analyze(int argc, char *argv[], const std::string& datadir);

namespace st2se
{

  template<typename Rule>
  struct ParserActions
    : pegtl::nothing<Rule> {};

  template<>
  struct ParserActions<syscall_name>
  {
    template<typename Input>
    static void apply(const Input& in, Syscall& syscall)
    {
      syscall.setName(in.string());
    }
  };

} /* namespace st2se */
