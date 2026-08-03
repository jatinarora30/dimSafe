#pragma once

namespace dimSafe {

template<typename Tag, typename Dimension, typename Rep>
class Quantity {
public:
    using rep = Rep;
    using value_type = Rep;

    Rep value_;

    constexpr Quantity operator+(const Quantity& other) const noexcept {
        return Quantity{value_ + other.value_};
    }

    constexpr Quantity operator-(const Quantity& other) const noexcept {
        return Quantity{value_ - other.value_};
    }

    constexpr bool operator==(const Quantity& other) const noexcept {
        return value_ == other.value_;
    }

    constexpr bool operator!=(const Quantity& other) const noexcept {
        return value_ != other.value_;
    }

    constexpr bool operator<(const Quantity& other) const noexcept {
        return value_ < other.value_;
    }

    constexpr bool operator<=(const Quantity& other) const noexcept {
        return value_ <= other.value_;
    }

    constexpr bool operator>(const Quantity& other) const noexcept {
        return value_ > other.value_;
    }

    constexpr bool operator>=(const Quantity& other) const noexcept {
        return value_ >= other.value_;
    }

    template<typename Scalar>
    constexpr Quantity scale(Scalar s) const noexcept {
        return Quantity{static_cast<Rep>(value_ * static_cast<Rep>(s))};
    }
};

template<typename LeftQuantity, typename RightQuantity>
struct DivideRule;

template<typename LeftQuantity, typename RightQuantity>
struct MultiplyRule;

} // namespace dimSafe
