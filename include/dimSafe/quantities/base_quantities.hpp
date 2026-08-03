#pragma once

#include "../quantity.hpp"
#include "../dimensions/base_dimesions.hpp"

namespace dimSafe {

struct DistanceTag {};
struct VelocityTag {};
struct DurationTag {};
struct AccelerationTag {};
struct MassTag {};
struct CurrentTag {};
struct TemperatureTag {};
struct AmountTag {};
struct LuminousIntensityTag {};

template<typename Rep = double>
using Distance = Quantity<DistanceTag, LengthDimension, Rep>;

template<typename Rep = double>
using Duration = Quantity<DurationTag, TimeDimension, Rep>;

template<typename Rep = double>
using Velocity = Quantity<VelocityTag, VelocityDimension, Rep>;

template<typename Rep = double>
using Acceleration = Quantity<AccelerationTag, AccelerationDimension, Rep>;

template<typename Rep = double>
using Mass = Quantity<MassTag, MassDimension, Rep>;

template<typename Rep = double>
using Current = Quantity<CurrentTag, CurrentDimension, Rep>;

template<typename Rep = double>
using Temperature = Quantity<TemperatureTag, TemperatureDimension, Rep>;

template<typename Rep = double>
using Amount = Quantity<AmountTag, AmountDimension, Rep>;

template<typename Rep = double>
using LuminousIntensity = Quantity<LuminousIntensityTag, LuminousIntensityDimension, Rep>;

} // namespace dimSafe
