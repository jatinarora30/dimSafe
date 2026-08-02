#pragma once

#include "../quantity.hpp"
#include "../dimensions/base_dimesions.hpp"

namespace dimSafe {

struct DistanceTag {};
struct VelocityTag {};
struct DurationTag {};
struct AccelerationTag {};

template<typename Rep = double>
using Distance = Quantity<DistanceTag, LengthDimension, Rep>;

template<typename Rep = double>
using Duration = Quantity<DurationTag, TimeDimension, Rep>;

template<typename Rep = double>
using Velocity = Quantity<VelocityTag, VelocityDimension, Rep>;

template<typename Rep = double>
using Acceleration = Quantity<AccelerationTag, AccelerationDimension, Rep>;

} // namespace dimSafe
