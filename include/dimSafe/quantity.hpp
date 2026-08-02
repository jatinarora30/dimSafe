#pragma once

namespace dimSafe {

template<typename Tag, typename Dimension, typename Rep>
class Quantity {
public:
    using rep = Rep;
    using value_type = Rep;

    Rep value_;

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

template<typename LeftQuantity, typename RightQuantity>
struct DivideRule;

template<typename LeftQuantity, typename RightQuantity>
struct MultiplyRule;

} // namespace dimSafe
