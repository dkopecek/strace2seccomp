#pragma once

#include <ostream>
#include <string>
#include <unordered_map>
#include "DataSet.hpp"

namespace st2se
{
  class SeccompCode
  {
    public:
      SeccompCode();

      bool setParameter(const std::string& name, const char * value);
      bool setParameter(const std::string& name, const std::string& value);
      bool getParameter(const std::string& name, std::string& value) const;
      bool setParameter(const std::string& name, bool state);
      bool getParameter(const std::string& name) const;
      bool isKnownParameter(const std::string& name) const;
 
      void addMask(const std::string& syscall, unsigned mask);
      void generate(std::ostream& stream, const DataSet& dataset) const;

    private:
      struct Parameter
      {
        Parameter(bool _state = false, const std::string& _value = std::string())
        {
          set = _state;
          value = _value;
        }
        bool set;
        std::string value;
      };

      struct Rule
      {
        std::string toString(const std::string& ctxvar) const;
        std::string syscall;
      };

      std::unordered_map<std::string, Parameter> _parameters;
      std::unordered_map<std::string, unsigned> _masks;
  };
} /* namespace st2se */
