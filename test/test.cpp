#include <cassert>
#include <chrono>
#include <concepts>
#include <iostream>
#include <type_traits>
#include <dimSafe/dimSafe.hpp>

using namespace std::chrono;

static double benchmarkQuantity(size_t iterations) {
    dimSafe::Distance<double> distance{1.234};
    dimSafe::Duration<double> duration{0.567};
    dimSafe::Distance<double> accumulated{0.0};

    for (size_t i = 0; i < iterations; ++i) {
        auto velocity = distance / duration;
        auto result = velocity * duration;
        accumulated = accumulated + result;
    }

    return accumulated.value_;
}

static double benchmarkRaw(size_t iterations) {
    double distance = 1.234;
    double duration = 0.567;
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        double velocity = distance / duration;
        double result = velocity * duration;
        accumulated += result;
    }

    return accumulated;
}

int main() {
    // Compile-time guarantees: the wrapper type is a zero-overhead alias around its rep.
    static_assert(std::same_as<dimSafe::Distance<>, dimSafe::Quantity<dimSafe::DistanceTag, dimSafe::LengthDimension, double>>);
    static_assert(std::same_as<dimSafe::Duration<>, dimSafe::Quantity<dimSafe::DurationTag, dimSafe::TimeDimension, double>>);
    static_assert(std::same_as<dimSafe::Velocity<>, dimSafe::Quantity<dimSafe::VelocityTag, dimSafe::VelocityDimension, double>>);

    static_assert(sizeof(dimSafe::Distance<>) == sizeof(double));
    static_assert(sizeof(dimSafe::Duration<>) == sizeof(double));
    static_assert(sizeof(dimSafe::Velocity<>) == sizeof(double));

    static_assert(std::is_trivially_copyable_v<dimSafe::Distance<>>);
    static_assert(std::is_trivially_copy_constructible_v<dimSafe::Distance<>>);
    static_assert(std::is_trivial_v<dimSafe::Distance<>>);

    // Functional correctness check.
    dimSafe::Distance<double> distance{10.0};
    dimSafe::Duration<double> duration{2.0};
    auto velocity = distance / duration;
    auto dist = velocity * duration;

    assert(velocity.value_ == 5.0);
    assert(dist.value_ == 10.0);

    // Runtime comparison to observe overhead in a meaningful loop.
    const size_t iterations = 5'000'000;
    auto startQuantity = high_resolution_clock::now();
    double sumQuantity = benchmarkQuantity(iterations);
    auto endQuantity = high_resolution_clock::now();
    auto quantityDuration = duration_cast<microseconds>(endQuantity - startQuantity);

    auto startRaw = high_resolution_clock::now();
    double sumRaw = benchmarkRaw(iterations);
    auto endRaw = high_resolution_clock::now();
    auto rawDuration = duration_cast<microseconds>(endRaw - startRaw);

    assert(sumQuantity == sumRaw);

    std::cout << "Compile-time size check passed: sizeof(Distance) == sizeof(double)\n";
    std::cout << "Runtime result check passed: " << sumQuantity << " == " << sumRaw << "\n";
    std::cout << "Quantity loop time: " << quantityDuration.count() << " us\n";
    std::cout << "Raw loop time:      " << rawDuration.count() << " us\n";

    return 0;
}
