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
        Parameter()
        {
          set = false;
        }
        bool set;
        std::string value;
      };
      std::unordered_map<std::string, Parameter> _parameters;
      std::unordered_map<std::string, unsigned> _masks;
  };
} /* namespace st2se */
