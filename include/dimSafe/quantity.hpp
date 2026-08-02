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