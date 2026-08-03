#pragma once

#include "../quantity.hpp"
#include "../dimensions/mechanical_dimensions.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {

struct ForceTag {};
struct MomentumTag {};
struct EnergyTag {};
struct PowerTag {};
struct AreaTag {};
struct VolumeTag {};
struct PressureTag {};
struct DensityTag {};

template<typename Rep = double>
using Force = Quantity<ForceTag, ForceDimension, Rep>;

template<typename Rep = double>
using Momentum = Quantity<MomentumTag, MomentumDimension, Rep>;

template<typename Rep = double>
using Energy = Quantity<EnergyTag, EnergyDimension, Rep>;

template<typename Rep = double>
using Power = Quantity<PowerTag, PowerDimension, Rep>;

template<typename Rep = double>
using Area = Quantity<AreaTag, AreaDimension, Rep>;

template<typename Rep = double>
using Volume = Quantity<VolumeTag, VolumeDimension, Rep>;

template<typename Rep = double>
using Pressure = Quantity<PressureTag, PressureDimension, Rep>;

template<typename Rep = double>
using Density = Quantity<DensityTag, DensityDimension, Rep>;

} // namespace dimSafe
