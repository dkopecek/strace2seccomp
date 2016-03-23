#include "SeccompCode.hpp"

namespace st2se
{
  SeccompCode::SeccompCode()
  {
    setParameter("int", true);
    setParameter("const", true);
    setParameter("ranges", false);
    setParameter("nowrap", false);
    setParameter("ctxvar", "ctx");
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

  bool SeccompCode::setParameter(const std::string& name, const std::string& value)
  {
    if (!isKnownParameter(name)) {
      return false;
    }

    auto& parameter = _parameters[name];
    parameter.set = true;
    parameter.value = value;
    
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
  }
} /* namespace st2se */
