#pragma once

#include "../dimension.hpp"

namespace dimSafe {

using LengthDimension =
    Dimension<1, 0, 0, 0, 0, 0, 0>;

using MassDimension =
    Dimension<0, 1, 0, 0, 0, 0, 0>;

using TimeDimension =
    Dimension<0, 0, 1, 0, 0, 0, 0>;

using CurrentDimension =
    Dimension<0, 0, 0, 1, 0, 0, 0>;

using TemperatureDimension =
    Dimension<0, 0, 0, 0, 1, 0, 0>;

using AmountDimension =
    Dimension<0, 0, 0, 0, 0, 1, 0>;

using LuminousIntensityDimension =
    Dimension<0, 0, 0, 0, 0, 0, 1>;

using AreaDimension =
    Dimension<2, 0, 0, 0, 0, 0, 0>;

using VolumeDimension =
    Dimension<3, 0, 0, 0, 0, 0, 0>;

using VelocityDimension =
    Dimension<1, 0, -1, 0, 0, 0, 0>;

using AccelerationDimension =
    Dimension<1, 0, -2, 0, 0, 0, 0>;

using ForceDimension =
    Dimension<1, 1, -2, 0, 0, 0, 0>;

using MomentumDimension =
    Dimension<1, 1, -1, 0, 0, 0, 0>;

using EnergyDimension =
    Dimension<2, 1, -2, 0, 0, 0, 0>;

using PowerDimension =
    Dimension<2, 1, -3, 0, 0, 0, 0>;

using PressureDimension =
    Dimension<-1, 1, -2, 0, 0, 0, 0>;

using DensityDimension =
    Dimension<-3, 1, 0, 0, 0, 0, 0>;

} // namespace dimSafe
