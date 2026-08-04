#include <cassert>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <type_traits>
#include <dimSafe/dimSafe.hpp>
using namespace std;

int main() {
    dimSafe::Distance<double> distance{10.0};
    dimSafe::Distance<double> distance2{8.0};
    dimSafe::Duration<double> duration{2.0};
    dimSafe::Mass<double> mass{4.0};

    auto velocity = distance / duration;
    static_assert(std::is_same_v<decltype(velocity), dimSafe::Velocity<double>>);

    auto acceleration = velocity / duration;
    static_assert(std::is_same_v<decltype(acceleration), dimSafe::Acceleration<double>>);

    auto recoveredDistance = acceleration * duration * duration;
    static_assert(std::is_same_v<decltype(recoveredDistance), dimSafe::Distance<double>>);

    auto area = distance * distance;
    static_assert(std::is_same_v<decltype(area), dimSafe::Area<double>>);

    auto volume = area * distance;
    static_assert(std::is_same_v<decltype(volume), dimSafe::Volume<double>>);

    auto force = mass * acceleration;
    static_assert(std::is_same_v<decltype(force), dimSafe::Force<double>>);

    auto energy = force * distance;
    static_assert(std::is_same_v<decltype(energy), dimSafe::Energy<double>>);

    auto power = energy / duration;
    static_assert(std::is_same_v<decltype(power), dimSafe::Power<double>>);

    auto pressure = force / area;
    static_assert(std::is_same_v<decltype(pressure), dimSafe::Pressure<double>>);

    auto density = mass / volume;
    static_assert(std::is_same_v<decltype(density), dimSafe::Density<double>>);

    auto sum = distance + dimSafe::Distance<double>{3.0};
    auto diff = distance - dimSafe::Distance<double>{3.0};
    auto scaled = distance.scale(1.5);
    auto equalDistance = dimSafe::Distance<double>{10.0};

    cout << "[Divide] Distance / Duration = Velocity: " << velocity.value_ << "\n";
    cout << "[Divide chain] Velocity / Duration = Acceleration: " << acceleration.value_ << "\n";
    cout << "[Multiply chain] Acceleration * Duration * Duration = Distance: " << recoveredDistance.value_ << "\n";
    cout << "[Multiply] Distance * Distance = Area: " << area.value_ << "\n";
    cout << "[Multiply] Area * Distance = Volume: " << volume.value_ << "\n";
    cout << "[Multiply] Mass * Acceleration = Force: " << force.value_ << "\n";
    cout << "[Multiply] Force * Distance = Energy: " << energy.value_ << "\n";
    cout << "[Divide] Energy / Duration = Power: " << power.value_ << "\n";
    cout << "[Divide] Force / Area = Pressure: " << pressure.value_ << "\n";
    cout << "[Divide] Mass / Volume = Density: " << density.value_ << "\n";
    cout << "[Add] Distance + 3 = " << sum.value_ << "\n";
    cout << "[Subtract] Distance - 3 = " << diff.value_ << "\n";
    cout << "[Scale] Distance * 1.5 = " << scaled.value_ << "\n";

    // Comparison operators return bool values. std::boolalpha prints them as true/false
    // instead of 1/0, which makes the examples easier to read.
    cout << boolalpha;
    cout << "[Compare ==] distance == equalDistance: " << (distance == equalDistance) << "\n";
    cout << "[Compare !=] distance != distance2: " << (distance != distance2) << "\n";
    cout << "[Compare <] distance2 < distance: " << (distance2 < distance) << "\n";
    cout << "[Compare <=] distance2 <= distance: " << (distance2 <= distance) << "\n";
    cout << "[Compare >] distance > distance2: " << (distance > distance2) << "\n";
    cout << "[Compare >=] distance >= distance2: " << (distance >= distance2) << "\n";
    cout << noboolalpha;

    assert(sum.value_ == 13.0);
    assert(diff.value_ == 7.0);
    assert(scaled.value_ == 15.0);
    assert(pressure.value_ == 0.1);
    assert(density.value_ == 0.004);
    assert(distance == equalDistance);
    assert(distance != distance2);
    assert(distance2 < distance);
    assert(distance2 <= distance);
    assert(distance > distance2);
    assert(distance >= distance2);
}
