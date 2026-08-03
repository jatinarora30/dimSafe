#pragma once

#include "../relationships.hpp"
#include "../quantities/thermal_quantities.hpp"
#include "../quantities/mechanical_quantities.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {

template<typename LeftRep, typename RightRep>
struct DivideRule<
    Energy<LeftRep>,
    Temperature<RightRep>>
{
    using result_tag = EntropyTag;
    using result_dimension = EntropyDimension;
};

template<typename LeftRep, typename RightRep>
struct DivideRule<
    Energy<LeftRep>,
    Duration<RightRep>>
{
    using result_tag = PowerTag;
    using result_dimension = PowerDimension;
};

} // namespace dimSafe
