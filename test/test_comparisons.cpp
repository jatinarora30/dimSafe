#include <cassert>
#include <dimSafe/dimSafe.hpp>

int main() {
    using namespace dimSafe;

    Distance<double> d1{10.0};
    Distance<double> d2{8.0};
    Distance<double> d3{10.0};

    assert(d1 == d3);
    assert(d1 != d2);
    assert(d2 < d1);
    assert(d2 <= d1);
    assert(d1 > d2);
    assert(d1 >= d2);

    Duration<double> t1{5.0};
    Duration<double> t2{5.0};
    assert(t1 == t2);
    assert(!(t1 != t2));

    // Comparisons with different quantity types are intentionally disabled by the type system.
    static_assert(std::is_same_v<decltype(d1 == d3), bool>);
    static_assert(std::is_same_v<decltype(t1 >= t2), bool>);

    return 0;
}
