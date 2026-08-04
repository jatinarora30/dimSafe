#include <cassert>
#include <type_traits>
#include <dimSafe/dimSafe.hpp>

int main() {
    using namespace dimSafe;

    Distance<double> distance{10.0};
    Duration<double> duration{2.0};
    Mass<double> mass{4.0};

    auto velocity = distance / duration;
    static_assert(std::is_same_v<decltype(velocity), Velocity<double>>);
    assert(velocity.value_ == 5.0);

    auto acceleration = velocity / duration;
    static_assert(std::is_same_v<decltype(acceleration), Acceleration<double>>);
    assert(acceleration.value_ == 2.5);

    auto area = distance * distance;
    static_assert(std::is_same_v<decltype(area), Area<double>>);
    assert(area.value_ == 100.0);

    auto volume = area * distance;
    static_assert(std::is_same_v<decltype(volume), Volume<double>>);
    assert(volume.value_ == 1000.0);

    auto force = mass * acceleration;
    static_assert(std::is_same_v<decltype(force), Force<double>>);
    assert(force.value_ == 10.0);

    auto energy = force * distance;
    static_assert(std::is_same_v<decltype(energy), Energy<double>>);
    assert(energy.value_ == 100.0);

    auto power = energy / duration;
    static_assert(std::is_same_v<decltype(power), Power<double>>);
    assert(power.value_ == 50.0);

    auto pressure = force / area;
    static_assert(std::is_same_v<decltype(pressure), Pressure<double>>);
    assert(pressure.value_ == 0.1);

    auto density = mass / volume;
    static_assert(std::is_same_v<decltype(density), Density<double>>);
    assert(density.value_ == 0.004);

    return 0;
}
