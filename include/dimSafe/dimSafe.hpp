#pragma once
#include <type_traits>
#include "quantity.hpp"
#include "dimensions/base_dimesions.hpp"
#include "quantities/base_quantities.hpp"
#include "relationships/base_relationships.hpp"
namespace dimSafe {
template<

    typename LeftTag,

    typename LeftDimension,

    typename LeftRep,

    typename RightTag,

    typename RightDimension,

    typename RightRep>

constexpr auto operator/(

    const Quantity<LeftTag, LeftDimension, LeftRep>& lhs,

    const Quantity<RightTag, RightDimension, RightRep>& rhs)

{

    using LeftQuantity =

        Quantity<LeftTag, LeftDimension, LeftRep>;



    using RightQuantity =

        Quantity<RightTag, RightDimension, RightRep>;



    using Rule =

        DivideRule<LeftQuantity, RightQuantity>;



    using ResultRep =

        std::common_type_t<LeftRep, RightRep>;



    using ResultQuantity =

        Quantity<

            typename Rule::result_tag,

            typename Rule::result_dimension,

            ResultRep>;



    return ResultQuantity{

        static_cast<ResultRep>(lhs.value_) /

        static_cast<ResultRep>(rhs.value_)

    };}

    template<

    typename LeftTag,

    typename LeftDimension,

    typename LeftRep,

    typename RightTag,

    typename RightDimension,

    typename RightRep>

constexpr auto operator*(

    const Quantity<LeftTag, LeftDimension, LeftRep>& lhs,

    const Quantity<RightTag, RightDimension, RightRep>& rhs)

{

    using LeftQuantity =

        Quantity<LeftTag, LeftDimension, LeftRep>;



    using RightQuantity =

        Quantity<RightTag, RightDimension, RightRep>;



    using Rule =

        MultiplyRule<LeftQuantity, RightQuantity>;



    using ResultRep =

        std::common_type_t<LeftRep, RightRep>;



    using ResultQuantity =

        Quantity<

            typename Rule::result_tag,

            typename Rule::result_dimension,

            ResultRep>;



    return ResultQuantity{

        static_cast<ResultRep>(lhs.value_) *

        static_cast<ResultRep>(rhs.value_)

    };
}
}
