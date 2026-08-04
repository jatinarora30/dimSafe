#pragma once

namespace dimSafe {

template<typename Dimension, typename Rep>
class Quantity {
public:
    using rep = Rep;
    using value_type = Rep;

    Rep value_;

    // Addition and subtraction are only valid for quantities of the same dimension type.
    // The template parameter `Dimension` ensures incompatible units cannot be combined.
    constexpr Quantity operator+(const Quantity& other) const noexcept {
        return Quantity{value_ + other.value_};
    }

    constexpr Quantity operator-(const Quantity& other) const noexcept {
        return Quantity{value_ - other.value_};
    }

    // Equality and ordering comparisons require the same quantity type.
    // A mismatch would be a compile-time error because the dimensions differ.
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


} // namespace dimSafe
