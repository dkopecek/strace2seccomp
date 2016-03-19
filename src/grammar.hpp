#pragma once
#include <pegtl.hh>

using namespace pegtl;

namespace st2se
{
  struct str_hexprefix
    : pegtl_string_t("0x") {};

  struct str_unfinished
    : pegtl_string_t("<unfinished ...>") {};

  struct str_sigprefix
    : pegtl_string_t("+++") {};

  struct str_killprefix
    : pegtl_string_t("---") {};

  struct str_nullpointer
    : pegtl_string_t("NULL") {};

  struct str_ellipsis
    : pegtl_string_t("...") {};

  struct integer
    : seq<opt<one<'-'>>, plus<ascii::digit>> {};

  struct pointer
    : seq<str_hexprefix, plus<ascii::xdigit>> {};

  struct hexbyte
    : if_must<one<'x'>, xdigit, xdigit> {};

  struct decbyte
    : if_must<digit, rep_opt<2, digit>> {};

  struct single
    : one<'a', 'b', 'f', 'n', 'r', 't', 'v', '\\', '"', '\'', '0', '\n'> {};

  struct character_escaped
    : if_must<one<'\\'>, sor<hexbyte, decbyte, single>> {};

  struct character_regular
    : not_one<'\r', '\n'> {};

  struct character
    : sor<character_escaped, character_regular> {};

  struct string
    : seq<if_must<one<'"'>, until<one<'"'>, character>>, opt<str_ellipsis>> {};

  struct constant
    : seq<ranges<'A','Z','_'>, star<ranges<'A','Z','0','9','_'>>> {};

  struct constants
    : list_must<constant, one<'|'>> {};

  template<char open_char, char close_char>
  struct container
  {
    using analyze_t = analysis::generic<analysis::rule_type::ANY>;

    template<typename Input>
    static bool match(Input& in)
    {
      if (in.size() >= 2) {
        if (in.begin()[0] == open_char) {
          int level;
          size_t i;
          for (i = 1, level = 1; i < in.size() && level > 0; ++i) {
            switch(in.begin()[i]) {
              case open_char:
                ++level;
                break;
              case close_char:
                --level;
                break;
            }
          }
          if (level == 0) {
            in.bump(i);
            return true;
          }
        }
      }
      return false;
    }
  };

  struct array
    : seq<opt<one<'~'>>, container<'[',']'>> {};

  struct structure
    : container<'{','}'> {};

  struct value
    : sor<pointer, integer, string, constants, array, structure> {};

  struct key_value
    : seq<ascii::identifier, one<'='>, value> {};

  struct argument
    : sor<value, key_value, at<str_unfinished>> {};

  struct rest
    : star<ascii::any> {};

  struct return_value
    : seq<sor<pointer, integer, one<'?'>>, opt<ascii::space, rest>> {};

  struct syscall_args
    : opt<list<argument, one<','>, ascii::space>> {};

  struct syscall_full
    : seq<one<')'>, pad<one<'='>, ascii::space>, return_value> {};

  struct syscall_unfinished
    : pad<str_unfinished, ascii::space> {};

  struct syscall_end
    : sor<syscall_full, syscall_unfinished> {};

  struct syscall_name
    : ascii::identifier {};

  struct syscall_start
    : seq<syscall_name, one<'('>, syscall_args> {};

  struct syscall_line
    : seq<syscall_start, syscall_end> {};

  struct signal_line
    : seq<str_sigprefix, plus<ascii::any>> {};

  struct killed_line
    : seq<str_killprefix, plus<ascii::any>> {};

  struct ignored_line
    : sor<signal_line, killed_line> {};

  struct strace_line
    : sor<syscall_line, ignored_line> {};

  struct grammar
    : until<eof, must<strace_line>> {};

} /* namespace strace */
