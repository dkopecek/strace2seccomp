#pragma once

#include <ostream>
#include "DataSet.hpp"

namespace st2se
{
  struct SeccompCodeParameters
  {
      bool match_constants;
      bool match_integers;
      std::pair<int,int> integer_range;
      bool integer_range_matching;
  };

  void generateSeccompCode(std::ostream& stream, const DataSet& dataset, const SeccompCodeParameters& parameters);
} /* namespace st2se */
