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
    : if_must<one<'"'>, until<one<'"'>, character>> {};

  struct value
    : sor<integer, pointer, string> {};

  struct rest
    : star<ascii::any> {};

  struct return_value
    : must<integer, opt<ascii::space, rest>> {};

  struct syscall_args
    : list<value, one<','>, ascii::space> {};

  struct syscall_full
    : must<ascii::identifier, one<'('>, syscall_args, one<')'>, pad<one<'='>, ascii::space>, return_value> {};

  struct syscall_unfinished
    : must<ascii::identifier, one<'('>, syscall_args, str_unfinished> {};

  struct syscall
    : sor<syscall_full, syscall_unfinished> {};

  struct signal_line
    : must<str_sigprefix, plus<ascii::any>> {};

  struct killed_line
    : must<str_killprefix, plus<ascii::any>> {};

  struct ignored_line
    : sor<signal_line, killed_line> {};

  struct strace_line
    : must<sor<syscall, ignored_line>, eof> {};
} /* namespace strace */
