#pragma once

#include "base_dimesions.hpp"

namespace dimSafe {

using AreaDimension = Dimension<2, 0, 0, 0, 0, 0, 0>;
using VolumeDimension = Dimension<3, 0, 0, 0, 0, 0, 0>;
using ForceDimension = Dimension<1, 1, -2, 0, 0, 0, 0>;
using MomentumDimension = Dimension<1, 1, -1, 0, 0, 0, 0>;
using EnergyDimension = Dimension<2, 1, -2, 0, 0, 0, 0>;
using PowerDimension = Dimension<2, 1, -3, 0, 0, 0, 0>;
using PressureDimension = Dimension<-1, 1, -2, 0, 0, 0, 0>;
using DensityDimension = Dimension<-3, 1, 0, 0, 0, 0, 0>;

} // namespace dimSafe
