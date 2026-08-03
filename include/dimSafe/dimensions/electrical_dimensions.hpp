#pragma once

#include "base_dimesions.hpp"

namespace dimSafe {

using ChargeDimension = Dimension<0, 0, 1, 1, 0, 0, 0>;
using ElectricPotentialDimension = Dimension<2, 1, -3, -1, 0, 0, 0>;
using ResistanceDimension = Dimension<2, 1, -3, -2, 0, 0, 0>;
using CapacitanceDimension = Dimension<-2, -1, 4, 2, 0, 0, 0>;
using InductanceDimension = Dimension<2, 1, -2, -2, 0, 0, 0>;
using ConductanceDimension = Dimension<-2, -1, 3, 2, 0, 0, 0>;

} // namespace dimSafe
