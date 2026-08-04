#include <cassert>
#include <dimSafe/dimSafe.hpp>

int main() {
    using namespace dimSafe;

    Distance<double> d1{5.0};
    Distance<double> d2{3.5};
    Distance<double> sum = d1 + d2;
    Distance<double> diff = d1 - d2;
    Distance<double> scaled = d1.scale(2.0);

    assert(sum.value_ == 8.5);
    assert(diff.value_ == 1.5);
    assert(scaled.value_ == 10.0);

    Duration<double> t1{4.0};
    Duration<double> t2{1.25};
    Duration<double> sumTime = t1 + t2;
    Duration<double> diffTime = t1 - t2;
    Duration<double> scaledTime = t2.scale(3.0);

    assert(sumTime.value_ == 5.25);
    assert(diffTime.value_ == 2.75);
    assert(scaledTime.value_ == 3.75);

    // Same-dimension arithmetic is valid; mixing different dimensions is a compile-time error.
    static_assert(std::is_same_v<decltype(sum), Distance<double>>);
    static_assert(std::is_same_v<decltype(sumTime), Duration<double>>);

    return 0;
}
