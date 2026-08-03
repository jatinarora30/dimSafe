#pragma once

#include "../relationships.hpp"
#include "../quantities/mechanical_quantities.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Distance<LeftRep>,
    Distance<RightRep>>
{
    using result_tag = AreaTag;
    using result_dimension = AreaDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Area<LeftRep>,
    Distance<RightRep>>
{
    using result_tag = VolumeTag;
    using result_dimension = VolumeDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Velocity<LeftRep>,
    Duration<RightRep>>
{
    using result_tag = DistanceTag;
    using result_dimension = LengthDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Acceleration<LeftRep>,
    Duration<RightRep>>
{
    using result_tag = VelocityTag;
    using result_dimension = VelocityDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Mass<LeftRep>,
    Velocity<RightRep>>
{
    using result_tag = MomentumTag;
    using result_dimension = MomentumDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Mass<LeftRep>,
    Acceleration<RightRep>>
{
    using result_tag = ForceTag;
    using result_dimension = ForceDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Acceleration<LeftRep>,
    Mass<RightRep>>
{
    using result_tag = ForceTag;
    using result_dimension = ForceDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Force<LeftRep>,
    Distance<RightRep>>
{
    using result_tag = EnergyTag;
    using result_dimension = EnergyDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Distance<LeftRep>,
    Force<RightRep>>
{
    using result_tag = EnergyTag;
    using result_dimension = EnergyDimension;
};

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Pressure<LeftRep>,
    Area<RightRep>>
{
    using result_tag = ForceTag;
    using result_dimension = ForceDimension;
};

template<typename LeftRep, typename RightRep>
struct DivideRule<
    Distance<LeftRep>,
    Duration<RightRep>>
{
    using result_tag = VelocityTag;
    using result_dimension = VelocityDimension;
};

template<typename LeftRep, typename RightRep>
struct DivideRule<
    Force<LeftRep>,
    Area<RightRep>>
{
    using result_tag = PressureTag;
    using result_dimension = PressureDimension;
};

template<typename LeftRep, typename RightRep>
struct DivideRule<
    Mass<LeftRep>,
    Volume<RightRep>>
{
    using result_tag = DensityTag;
    using result_dimension = DensityDimension;
};

} // namespace dimSafe
