#pragma once

#include "../quantity.hpp"
#include "../dimensions/mechanical_dimensions.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {


template<typename Rep = double>
using Force = Quantity<ForceDimension, Rep>;

template<typename Rep = double>
using Momentum = Quantity<MomentumDimension, Rep>;

template<typename Rep = double>
using Energy = Quantity<EnergyDimension, Rep>;

template<typename Rep = double>
using Power = Quantity<PowerDimension, Rep>;

template<typename Rep = double>
using Area = Quantity<AreaDimension, Rep>;

template<typename Rep = double>
using Volume = Quantity<VolumeDimension, Rep>;

template<typename Rep = double>
using Pressure = Quantity<PressureDimension, Rep>;

template<typename Rep = double>
using Density = Quantity<DensityDimension, Rep>;

} // namespace dimSafe
