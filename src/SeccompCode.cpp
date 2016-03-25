#include "SeccompCode.hpp"
#include <map>

namespace st2se
{
  SeccompCode::SeccompCode()
  {
    if (!setParameter("int", true) ||
        !setParameter("const", true) ||
        !setParameter("ranges", false) ||
        !setParameter("nowrap", false) ||
        !setParameter("ctxvar", "ctx")) {
      throw std::runtime_error("BUG: Failed to set default parameter values in SeccompCode ctor");
    }
  }

  bool SeccompCode::isKnownParameter(const std::string& name) const
  {
    if (name == "int" ||
        name == "const" ||
        name == "ranges" ||
        name == "nowrap" ||
        name == "ctxvar") {
      return true;
    }
    else {
      return false;
    }
  }

  bool SeccompCode::setParameter(const std::string& name, const char * value)
  {
    return setParameter(name, std::string(value));
  }

  bool SeccompCode::setParameter(const std::string& name, const std::string& value)
  {
    if (!isKnownParameter(name)) {
      return false;
    }

    _parameters[name] = { true, value};
    
    return true;
  }

  bool SeccompCode::getParameter(const std::string& name, std::string& value) const
  {
    if (!isKnownParameter(name)) {
      return false;
    }

    auto const& parameter = _parameters.at(name);
    value = parameter.value;

    return parameter.set;
  }

  bool SeccompCode::setParameter(const std::string& name, bool state)
  {
    if (!isKnownParameter(name)) {
      return false;
    }

    _parameters[name].set = state;

    return true;
  }

  bool SeccompCode::getParameter(const std::string& name) const
  {
    return _parameters.at(name).set;
  }

  void SeccompCode::addMask(const std::string& syscall, unsigned mask)
  {
    _masks[syscall] = mask;
  }

  void SeccompCode::generate(std::ostream& stream, const DataSet& dataset) const
  {
    std::map<std::string, Rule> rules;

    for (auto const& node : dataset.syscallMap()) {
      auto const& syscall = node.first;
      rules[syscall].syscall = syscall;
    }

    std::string ctxvar;

    if (!getParameter("ctxvar", ctxvar) || ctxvar.empty()) {
      throw std::runtime_error("BUG: empty ctxvar parameter in SeccompCode::generate");
    }

    const bool wrap = !getParameter("nowrap");
    std::string wrap_name = "setupSeccompWhitelist";

    if (wrap) {
      stream << "int " << wrap_name << "(void)" << std::endl;
      stream << "{" << std::endl;
      stream << "  seccomp_filter_ctx " << ctxvar << " = seccomp_init(SCMP_ACT_TRAP);" << std::endl;
      stream << "  if (!" << ctxvar << ") {" << std::endl;
      stream << "    return -1;" << std::endl;
      stream << "  }" << std::endl;
      stream << "  int ret = 0;" << std::endl;
    }

    for (auto const& node : rules) {
      auto const& rule = node.second;
      if (wrap) {
        stream << "  ret |= ";
      }
      stream << rule.toString(ctxvar) << std::endl;
    }

    if (wrap) {
      stream << "  if (ret != 0) {" << std::endl;
      stream << "    ret = -1;" << std::endl;
      stream << "  }" << std::endl;
      stream << "  seccomp_release(" << ctxvar << ");" << std::endl;
      stream << "  return ret;" << std::endl;
      stream << "}" << std::endl;
    }
  }

  std::string SeccompCode::Rule::toString(const std::string& ctxvar) const
  {
    std::string code;

    /* open function call */
    code.append("seccomp_rule_add(");

    /* scmp_filter_ctx */
    code.append(ctxvar);

    /* action */
    code.append(", SCMP_ACT_ALLOW");

    /* syscall name */
    code.append(", SCMP_SYS(");
    code.append(syscall);
    code.append(")");

    /* number of syscall argument filters */
    code.append(", 0");

    /* close function call */
    code.append(");");

    return code;
  }
} /* namespace st2se */
