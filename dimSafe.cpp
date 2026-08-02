#include <iostream>
using namespace std;
struct DistanceTag {};
struct VelocityTag {};
struct DurationTag {};
struct AccelerationTag {};


template<int Length,int Mass,int Time,int Current,int Temperature,int Amount,int LuminousIntensity>
struct Dimension{
    static constexpr int length = Length;
    static constexpr int mass = Mass;
    static constexpr int time = Time;
    static constexpr int current = Current;
    static constexpr int temperature = Temperature;
    static constexpr int amount = Amount;
    static constexpr int luminous_intensity = LuminousIntensity;
};

using LengthDimension =
    Dimension<1, 0, 0, 0, 0, 0, 0>;

using TimeDimension =
    Dimension<0, 0, 1, 0, 0, 0, 0>;

using VelocityDimension =
    Dimension<1, 0, -1, 0, 0, 0, 0>;

using AccelerationDimension =
    Dimension<1, 0, -2, 0, 0, 0, 0>;

template<typename Tag,typename Dimension, typename Rep>
class Quantity {


public:
    Rep value_;
    explicit Quantity(Rep value)
        : value_(value) {}

    Quantity operator+(const Quantity& other) const {
        return Quantity{value_ + other.value_};
    }

    Quantity operator-(const Quantity& other) const {
        return Quantity{value_ - other.value_};
    }

    Quantity scale(const float s) const {
        return Quantity{value_ * s};
    }



  
};
template<typename Rep = double>
using Distance =
    Quantity<DistanceTag, LengthDimension, Rep>;

template<typename Rep = double>
using Duration =
    Quantity<DurationTag, TimeDimension, Rep>;

template<typename Rep = double>
using Velocity =
    Quantity<VelocityTag, VelocityDimension, Rep>;

template<typename Rep = double>
using Acceleration =
    Quantity<AccelerationTag, AccelerationDimension, Rep>;


template<typename LeftQuantity, typename RightQuantity>
struct DivideRule;

template<typename LeftQuantity, typename RightQuantity>
struct MultiplyRule;

template<typename LeftRep, typename RightRep>
struct MultiplyRule<
    Velocity<LeftRep>,
    Duration<RightRep>>
{
    using result_tag = DistanceTag;
    using result_dimension = LengthDimension;
};



template<typename LeftRep, typename RightRep>
struct DivideRule<
    Distance<LeftRep>,
    Duration<RightRep>>
{
    using result_tag = VelocityTag;
    using result_dimension = VelocityDimension;
};
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


int main() {
    Distance<double> distance{10.0};
    Duration<double> duration{2.0};

    auto velocity = distance / duration;

    auto dist = velocity * duration;

    std::cout << velocity.value_ << std::endl; // Output: 5.0

    std::cout << dist.value_ << std::endl; // Output: 5.0

 
}