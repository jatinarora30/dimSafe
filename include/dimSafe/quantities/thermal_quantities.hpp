#pragma once

#include "../quantity.hpp"
#include "../dimensions/thermal_dimensions.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {


template<typename Rep = double>
using HeatCapacity = Quantity<HeatCapacityDimension, Rep>;

template<typename Rep = double>
using Entropy = Quantity<EntropyDimension, Rep>;

} // namespace dimSafe
