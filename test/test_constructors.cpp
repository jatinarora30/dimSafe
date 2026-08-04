#include <cassert>
#include <type_traits>
#include <dimSafe/dimSafe.hpp>

int main() {
    using namespace dimSafe;

    // Aggregate initialization of a quantity.
    Distance<double> d1{4.5};
    assert(d1.value_ == 4.5);

    // Default construction is allowed, but value_ is uninitialized.
    Distance<double> d2{};
    d2 = d1;
    assert(d2.value_ == 4.5);

    // Copy construction from same quantity type.
    Distance<double> d3 = d1;
    assert(d3.value_ == 4.5);

    // Copy assignment from same quantity type.
    Distance<double> d4{1.0};
    d4 = d1;
    assert(d4.value_ == 4.5);

    // Same-dimension quantities use the implicitly generated assignment operators.
    static_assert(std::is_copy_constructible_v<Distance<double>>);
    static_assert(std::is_copy_assignable_v<Distance<double>>);
    static_assert(std::is_move_constructible_v<Distance<double>>);
    static_assert(std::is_move_assignable_v<Distance<double>>);

    // Different repetitions are different types, so assignment is not allowed.
    static_assert(!std::is_assignable_v<Distance<float>&, const Distance<double>&>);

    // Duration assignment uses the same quantity semantics.
    Duration<double> t1{2.0};
    Duration<double> t2{};
    t2 = t1;
    assert(t2.value_ == 2.0);

    return 0;
}
