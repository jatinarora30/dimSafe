#pragma once

#include "../relationships.hpp"
#include "../quantities/electrical_quantities.hpp"
#include "../quantities/mechanical_quantities.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    ElectricPotential<LeftRep>,
    Charge<RightRep>>
{
    using result_tag = EnergyTag;
    using result_dimension = EnergyDimension;
};

template<typename LeftRep, typename RightRep>
struct DivideRule<
    ElectricPotential<LeftRep>,
    Resistance<RightRep>>
{
    using result_tag = CurrentTag;
    using result_dimension = CurrentDimension;
};

template<typename LeftRep, typename RightRep>
struct DivideRule<
    Charge<LeftRep>,
    Current<RightRep>>
{
    using result_tag = DurationTag;
    using result_dimension = TimeDimension;
};

} // namespace dimSafe
