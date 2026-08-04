#pragma once

#include "../quantity.hpp"
#include "../dimensions/base_dimesions.hpp"

namespace dimSafe {

template<typename Rep = double>
using Distance = Quantity<LengthDimension, Rep>;

template<typename Rep = double>
using Duration = Quantity<TimeDimension, Rep>;

template<typename Rep = double>
using Velocity = Quantity<VelocityDimension, Rep>;

template<typename Rep = double>
using Acceleration = Quantity< AccelerationDimension, Rep>;

template<typename Rep = double>
using Mass = Quantity<MassDimension, Rep>;

template<typename Rep = double>
using Current = Quantity<CurrentDimension, Rep>;

template<typename Rep = double>
using Temperature = Quantity<TemperatureDimension, Rep>;

template<typename Rep = double>
using Amount = Quantity<AmountDimension, Rep>;

template<typename Rep = double>
using LuminousIntensity = Quantity<LuminousIntensityDimension, Rep>;

} // namespace dimSafe
