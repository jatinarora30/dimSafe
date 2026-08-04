#pragma once
#include <type_traits>
#include "quantity.hpp"
#include "dimensions/base_dimesions.hpp"
#include "dimensions/mechanical_dimensions.hpp"
#include "dimensions/electrical_dimensions.hpp"
#include "dimensions/thermal_dimensions.hpp"
#include "quantities/base_quantities.hpp"
#include "quantities/mechanical_quantities.hpp"
#include "quantities/electrical_quantities.hpp"
#include "quantities/thermal_quantities.hpp"
namespace dimSafe {

    template<typename LeftDimension, typename RightDimension >
    using MultiplyDimension = Dimension<
        LeftDimension::length + RightDimension::length,
        LeftDimension::mass + RightDimension::mass,
        LeftDimension::time + RightDimension::time,
        LeftDimension::current + RightDimension::current,
        LeftDimension::temperature + RightDimension::temperature,
        LeftDimension::amount + RightDimension::amount,
        LeftDimension::luminous_intensity + RightDimension::luminous_intensity
    >;

    template<typename LeftDimension, typename RightDimension>
    using DivideDimension = Dimension<
        LeftDimension::length - RightDimension::length,
        LeftDimension::mass - RightDimension::mass,
        LeftDimension::time - RightDimension::time,
        LeftDimension::current - RightDimension::current,
        LeftDimension::temperature - RightDimension::temperature,
        LeftDimension::amount - RightDimension::amount,
        LeftDimension::luminous_intensity - RightDimension::luminous_intensity
    >;
    
    
    template< typename LeftDimension, typename LeftRep,
     typename RightDimension, typename RightRep>

constexpr auto operator/(

    const Quantity< LeftDimension, LeftRep>& lhs,

    const Quantity<RightDimension, RightRep>& rhs)

{
    using result_dimension = DivideDimension<LeftDimension,RightDimension >;


    using ResultRep =

        std::common_type_t<LeftRep, RightRep>;

        return Quantity<result_dimension, ResultRep>{lhs.value_ / rhs.value_};

    };

       template< typename LeftDimension, typename LeftRep,
     typename RightDimension, typename RightRep>

constexpr auto operator*(

    const Quantity< LeftDimension, LeftRep>& lhs,

    const Quantity<RightDimension, RightRep>& rhs)

{
    using result_dimension = MultiplyDimension<LeftDimension,RightDimension >;


    using ResultRep =

        std::common_type_t<LeftRep, RightRep>;

        return Quantity<result_dimension, ResultRep>{lhs.value_ * rhs.value_};

    };
}
