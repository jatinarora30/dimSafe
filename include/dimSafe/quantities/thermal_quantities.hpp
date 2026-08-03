#pragma once

#include "../quantity.hpp"
#include "../dimensions/thermal_dimensions.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {

struct HeatCapacityTag {};
struct EntropyTag {};

template<typename Rep = double>
using HeatCapacity = Quantity<HeatCapacityTag, HeatCapacityDimension, Rep>;

template<typename Rep = double>
using Entropy = Quantity<EntropyTag, EntropyDimension, Rep>;

} // namespace dimSafe
