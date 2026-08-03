#include <cassert>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <type_traits>
#include <dimSafe/dimSafe.hpp>

using Clock = std::chrono::steady_clock;
using Microseconds = std::chrono::microseconds;

static bool approxEqual(double a, double b, double relTol = 1e-9, double absTol = 1e-12) {
    double diff = std::abs(a - b);
    double maxAbs = std::max(std::abs(a), std::abs(b));
    return diff <= std::max(absTol, relTol * maxAbs);
}

static double benchmarkQuantityChainDouble(size_t iterations) {
    dimSafe::Distance<double> distance{1.234};
    dimSafe::Duration<double> duration{0.567};
    dimSafe::Distance<double> accumulated{0.0};

    for (size_t i = 0; i < iterations; ++i) {
        auto velocity = distance / duration;
        auto result = velocity * duration;
        auto scaled = result.scale(1.1);
        accumulated = accumulated + scaled;
        distance = distance + dimSafe::Distance<double>{0.000001 * (i % 1000)};
        duration = duration + dimSafe::Duration<double>{0.0000005 * ((i + 1) % 1000)};
    }

    return accumulated.value_ + distance.value_ + duration.value_;
}

static double benchmarkRawChainDouble(size_t iterations) {
    double distance = 1.234;
    double duration = 0.567;
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        double velocity = distance / duration;
        double result = velocity * duration;
        double scaled = result * 1.1;
        accumulated += scaled;
        distance += 0.000001 * (i % 1000);
        duration += 0.0000005 * ((i + 1) % 1000);
    }

    return accumulated + distance + duration;
}

static double benchmarkQuantityDivide(size_t iterations) {
    dimSafe::Distance<double> distance{1.234};
    dimSafe::Duration<double> duration{0.567};
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        auto velocity = distance / duration;
        accumulated += velocity.value_;
        distance = distance + dimSafe::Distance<double>{0.0000001 * (i % 16)};
        duration = duration + dimSafe::Duration<double>{0.00000005 * ((i + 1) % 16)};
    }

    return accumulated + distance.value_ + duration.value_;
}

static double benchmarkRawDivide(size_t iterations) {
    double distance = 1.234;
    double duration = 0.567;
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        double velocity = distance / duration;
        accumulated += velocity;
        distance += 0.0000001 * (i % 16);
        duration += 0.00000005 * ((i + 1) % 16);
    }

    return accumulated + distance + duration;
}

static double benchmarkQuantityMultiply(size_t iterations) {
    dimSafe::Distance<double> distance{1.234};
    dimSafe::Duration<double> duration{0.567};
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        auto velocity = distance / duration;
        auto result = velocity * duration;
        accumulated += result.value_;
        distance = distance + dimSafe::Distance<double>{0.0000001 * (i % 16)};
        duration = duration + dimSafe::Duration<double>{0.00000005 * ((i + 1) % 16)};
    }

    return accumulated + distance.value_ + duration.value_;
}

static double benchmarkRawMultiply(size_t iterations) {
    double distance = 1.234;
    double duration = 0.567;
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        double velocity = distance / duration;
        double result = velocity * duration;
        accumulated += result;
        distance += 0.0000001 * (i % 16);
        duration += 0.00000005 * ((i + 1) % 16);
    }

    return accumulated + distance + duration;
}

static double benchmarkQuantityAdd(size_t iterations) {
    dimSafe::Distance<double> value{1.234};
    dimSafe::Distance<double> accumulated{0.0};

    for (size_t i = 0; i < iterations; ++i) {
        accumulated = accumulated + value;
    }

    return accumulated.value_;
}

static double benchmarkRawAdd(size_t iterations) {
    double value = 1.234;
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        accumulated += value;
    }

    return accumulated;
}

static double benchmarkQuantitySubtract(size_t iterations) {
    dimSafe::Distance<double> value{0.567};
    dimSafe::Distance<double> accumulated{1000000.0};

    for (size_t i = 0; i < iterations; ++i) {
        accumulated = accumulated - value;
    }

    return accumulated.value_;
}

static double benchmarkRawSubtract(size_t iterations) {
    double value = 0.567;
    double accumulated = 1000000.0;

    for (size_t i = 0; i < iterations; ++i) {
        accumulated -= value;
    }

    return accumulated;
}

static double benchmarkQuantityScale(size_t iterations) {
    dimSafe::Distance<double> value{1.234};
    dimSafe::Distance<double> accumulated{0.0};

    for (size_t i = 0; i < iterations; ++i) {
        accumulated = accumulated + value.scale(1.1);
        value = value + dimSafe::Distance<double>{0.0000001 * (i % 16)};
    }

    return accumulated.value_;
}

static double benchmarkRawScale(size_t iterations) {
    double value = 1.234;
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        accumulated += value * 1.1;
        value += 0.0000001 * (i % 16);
    }

    return accumulated;
}

static double benchmarkQuantityChainFloat(size_t iterations) {
    dimSafe::Distance<float> distance{1.234f};
    dimSafe::Duration<float> duration{0.567f};
    dimSafe::Distance<float> accumulated{0.0f};

    for (size_t i = 0; i < iterations; ++i) {
        auto velocity = distance / duration;
        auto result = velocity * duration;
        auto scaled = result.scale(1.1f);
        accumulated = accumulated + scaled;
        distance = distance + dimSafe::Distance<float>{0.000001f * float(i % 1000)};
        duration = duration + dimSafe::Duration<float>{0.0000005f * float((i + 1) % 1000)};
    }

    return double(accumulated.value_) + double(distance.value_) + double(duration.value_);
}

static double benchmarkRawChainFloat(size_t iterations) {
    float distance = 1.234f;
    float duration = 0.567f;
    float accumulated = 0.0f;

    for (size_t i = 0; i < iterations; ++i) {
        float velocity = distance / duration;
        float result = velocity * duration;
        float scaled = result * 1.1f;
        accumulated += scaled;
        distance += 0.000001f * float(i % 1000);
        duration += 0.0000005f * float((i + 1) % 1000);
    }

    return double(accumulated) + double(distance) + double(duration);
}

static double benchmarkQuantityMixedReps(size_t iterations) {
    dimSafe::Distance<float> distance{1.234f};
    dimSafe::Duration<double> duration{0.567};
    dimSafe::Distance<double> accumulated{0.0};

    for (size_t i = 0; i < iterations; ++i) {
        auto velocity = distance / duration;
        auto result = velocity * duration;
        auto scaled = result.scale(1.1);
        accumulated = accumulated + scaled;
        distance = distance + dimSafe::Distance<float>{0.000001f};
        duration = duration + dimSafe::Duration<double>{0.0000005};
    }

    return accumulated.value_ + double(distance.value_) + duration.value_;
}

static double benchmarkRawMixedReps(size_t iterations) {
    float distance = 1.234f;
    double duration = 0.567;
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        double velocity = distance / duration;
        double result = velocity * duration;
        double scaled = result * 1.1;
        accumulated += scaled;
        distance += 0.000001f;
        duration += 0.0000005;
    }

    return accumulated + distance + duration;
}

static double benchmarkQuantityAddSubScale(size_t iterations) {
    dimSafe::Distance<double> value{1.234};
    dimSafe::Distance<double> accumulated{0.0};

    for (size_t i = 0; i < iterations; ++i) {
        accumulated = (accumulated + value).scale(1.0000001);
        accumulated = accumulated - dimSafe::Distance<double>{0.000001};
    }

    return accumulated.value_;
}

static double benchmarkRawAddSubScale(size_t iterations) {
    double value = 1.234;
    double accumulated = 0.0;

    for (size_t i = 0; i < iterations; ++i) {
        accumulated = (accumulated + value) * 1.0000001;
        accumulated -= 0.000001;
    }

    return accumulated;
}

int main() {
    static_assert(std::same_as<dimSafe::Distance<>, dimSafe::Quantity<dimSafe::DistanceTag, dimSafe::LengthDimension, double>>);
    static_assert(std::same_as<dimSafe::Duration<>, dimSafe::Quantity<dimSafe::DurationTag, dimSafe::TimeDimension, double>>);
    static_assert(std::same_as<dimSafe::Velocity<>, dimSafe::Quantity<dimSafe::VelocityTag, dimSafe::VelocityDimension, double>>);
    static_assert(std::same_as<dimSafe::Force<>, dimSafe::Quantity<dimSafe::ForceTag, dimSafe::ForceDimension, double>>);
    static_assert(std::same_as<dimSafe::Energy<>, dimSafe::Quantity<dimSafe::EnergyTag, dimSafe::EnergyDimension, double>>);
    static_assert(sizeof(dimSafe::Distance<>) == sizeof(double));
    static_assert(sizeof(dimSafe::Duration<>) == sizeof(double));
    static_assert(sizeof(dimSafe::Velocity<>) == sizeof(double));
    static_assert(sizeof(dimSafe::Force<>) == sizeof(double));
    static_assert(sizeof(dimSafe::Energy<>) == sizeof(double));
    static_assert(std::is_trivially_copyable_v<dimSafe::Distance<>>);
    static_assert(std::is_trivially_copy_constructible_v<dimSafe::Distance<>>);
    static_assert(std::is_trivial_v<dimSafe::Distance<>>);

    dimSafe::Distance<double> distance{10.0};
    dimSafe::Duration<double> duration{2.0};
    auto velocity = distance / duration;
    auto dist = velocity * duration;
    auto increment = dimSafe::Distance<double>{1.5};
    auto adjusted = dist + increment;
    auto delta = adjusted - distance;
    auto mass = dimSafe::Mass<double>{4.0};
    auto acceleration = dimSafe::Acceleration<double>{2.5};
    auto force = mass * acceleration;
    auto energy = force * distance;
    auto pressure = force / dimSafe::Area<double>{2.0};
    auto density = mass / dimSafe::Volume<double>{0.5};
    auto momentum = mass * velocity;
    auto power = energy / duration;

    assert(std::abs(velocity.value_ - 5.0) < 1e-12);
    assert(std::abs(dist.value_ - 10.0) < 1e-12);
    assert(std::abs(adjusted.value_ - 11.5) < 1e-12);
    assert(std::abs(delta.value_ - 1.5) < 1e-12);
    assert(std::abs(force.value_ - 10.0) < 1e-12);
    assert(std::abs(energy.value_ - 100.0) < 1e-12);
    assert(std::abs(pressure.value_ - 5.0) < 1e-12);
    assert(std::abs(density.value_ - 8.0) < 1e-12);
    assert(std::abs(momentum.value_ - 20.0) < 1e-12);
    assert(std::abs(power.value_ - 50.0) < 1e-12);

    dimSafe::Distance<float> floatDistance{3.5f};
    dimSafe::Duration<double> doubleDuration{1.4};
    auto floatVelocity = floatDistance / doubleDuration;
    static_assert(std::same_as<decltype(floatVelocity), dimSafe::Quantity<dimSafe::VelocityTag, dimSafe::VelocityDimension, double>>);
    assert(std::abs(floatVelocity.value_ - (3.5 / 1.4)) < 1e-12);

    const size_t iterations = 10'000'000;
    const size_t repeats = 10;

    struct BenchResult {
        double result;
        Microseconds best;
        long double avg;
    };

    auto measure = [&](const char* label, double (*fn)(size_t)) {
        double warmup = fn(iterations);
        (void)warmup;

        BenchResult result{0.0, Microseconds::max(), 0.0L};
        for (size_t r = 0; r < repeats; ++r) {
            auto start = Clock::now();
            double value = fn(iterations);
            auto end = Clock::now();
            auto duration = std::chrono::duration_cast<Microseconds>(end - start);
            if (duration < result.best) {
                result.best = duration;
            }
            result.result = value;
            result.avg += duration.count();
        }
        result.avg /= repeats;
        std::cout << label << "\n"
                  << "  best time = " << result.best.count() << " us\n"
                  << "  avg time  = " << std::fixed << std::setprecision(1) << result.avg << " us\n"
                  << "  result    = " << result.result << "\n\n";
        return result;
    };

    std::cout << "Compile-time size check passed: sizeof(Distance) == sizeof(double)\n";
    std::cout << "Benchmark iterations: " << iterations << ", repeats: " << repeats << "\n\n";

    auto q1 = measure("Quantity chain double", benchmarkQuantityChainDouble);
    auto r1 = measure("Raw chain double", benchmarkRawChainDouble);
    assert(approxEqual(q1.result, r1.result, 1e-8, 1e-6));
    std::cout << "  overhead ratio = " << (double)q1.best.count() / r1.best.count() << "\n\n";

    auto q2 = measure("Quantity chain float", benchmarkQuantityChainFloat);
    auto r2 = measure("Raw chain float", benchmarkRawChainFloat);
    assert(approxEqual(q2.result, r2.result, 1e-6, 1e-5));
    std::cout << "  overhead ratio = " << (double)q2.best.count() / r2.best.count() << "\n\n";

    auto q2a = measure("Quantity divide", benchmarkQuantityDivide);
    auto r2a = measure("Raw divide", benchmarkRawDivide);
    assert(approxEqual(q2a.result, r2a.result, 1e-9, 1e-6));
    std::cout << "  overhead ratio = " << (double)q2a.best.count() / r2a.best.count() << "\n\n";

    auto q2b = measure("Quantity multiply", benchmarkQuantityMultiply);
    auto r2b = measure("Raw multiply", benchmarkRawMultiply);
    assert(approxEqual(q2b.result, r2b.result, 1e-9, 1e-6));
    std::cout << "  overhead ratio = " << (double)q2b.best.count() / r2b.best.count() << "\n\n";

    auto q2c = measure("Quantity add", benchmarkQuantityAdd);
    auto r2c = measure("Raw add", benchmarkRawAdd);
    assert(approxEqual(q2c.result, r2c.result, 1e-9, 1e-6));
    std::cout << "  overhead ratio = " << (double)q2c.best.count() / r2c.best.count() << "\n\n";

    auto q2d = measure("Quantity subtract", benchmarkQuantitySubtract);
    auto r2d = measure("Raw subtract", benchmarkRawSubtract);
    assert(approxEqual(q2d.result, r2d.result, 1e-9, 1e-6));
    std::cout << "  overhead ratio = " << (double)q2d.best.count() / r2d.best.count() << "\n\n";

    auto q2e = measure("Quantity scale", benchmarkQuantityScale);
    auto r2e = measure("Raw scale", benchmarkRawScale);
    assert(approxEqual(q2e.result, r2e.result, 1e-9, 1e-6));
    std::cout << "  overhead ratio = " << (double)q2e.best.count() / r2e.best.count() << "\n\n";

    auto q3 = measure("Quantity mixed reps", benchmarkQuantityMixedReps);
    auto r3 = measure("Raw mixed reps", benchmarkRawMixedReps);
    assert(approxEqual(q3.result, r3.result, 1e-8, 1e-6));
    std::cout << "  overhead ratio = " << (double)q3.best.count() / r3.best.count() << "\n\n";

    auto q4 = measure("Quantity add/sub/scale", benchmarkQuantityAddSubScale);
    auto r4 = measure("Raw add/sub/scale", benchmarkRawAddSubScale);
    assert(approxEqual(q4.result, r4.result, 1e-8, 1e-6));
    std::cout << "  overhead ratio = " << (double)q4.best.count() / r4.best.count() << "\n\n";

    return 0;
}
