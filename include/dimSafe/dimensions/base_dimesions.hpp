#include "dimSafe/dimension.hpp"


using LengthDimension =
    Dimension<1, 0, 0, 0, 0, 0, 0>;

using TimeDimension =
    Dimension<0, 0, 1, 0, 0, 0, 0>;

using VelocityDimension =
    Dimension<1, 0, -1, 0, 0, 0, 0>;

using AccelerationDimension =
    Dimension<1, 0, -2, 0, 0, 0, 0>;