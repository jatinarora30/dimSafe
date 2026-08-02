#include <iostream>
#include "dimSafe/dimensions/base_dimesions.hpp"
#include "dimSafe/relationships/base_relationships.hpp"
#include "dimSafe/quantities/base_quantities.hpp"
#include "dimSafe/quantity.hpp"
using namespace std;

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
