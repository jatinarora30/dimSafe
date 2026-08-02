#pragma once

#include "../relationships.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Velocity<LeftRep>,
    Duration<RightRep>>
{
    using result_tag = DistanceTag;
    using result_dimension = LengthDimension;
};

template<typename LeftRep, typename RightRep>
struct DivideRule<
    Distance<LeftRep>,
    Duration<RightRep>>
{
    using result_tag = VelocityTag;
    using result_dimension = VelocityDimension;
};

} // namespace dimSafe
