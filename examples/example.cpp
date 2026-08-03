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
    dimSafe::Distance<double> distance2{10.0};
    dimSafe::Duration<double> duration{2.0};

    auto velocity = distance / duration;

    auto dist = velocity * duration;
    auto sum = distance + distance2;
    std::cout << "[Divide Operation] Distance / Duration : " << velocity.value_ << std::endl; // Output: 5.0

    std::cout << "[Multiply Operation] Velocity * Duration : " << dist.value_ << std::endl; // Output: 5.0
    std::cout << "[Addition Operation] Distance + Distance2 : " << sum.value_ << std::endl; // Output: 20.0
    std::cout << "[Subtraction Operation] Distance - Distance2 : " << (distance - distance2).value_ << std::endl; // Output: 0.0
    std::cout << "[Scale Operation] Distance * 2.0 : " << distance.scale(2.0).value_ << std::endl; // Output: 20.0
    std::cout << "[Comparison ==] Distance == Distance2 : " << (distance == distance2) << std::endl; // Output: 1 (true)
    std::cout << "[Comparison !=] Distance != Distance2 : " << (distance != distance2) << std::endl; // Output: 0 (false)
    std::cout << "[Comparison <] Distance < Distance2 : " << (distance < distance2) << std::endl; // Output: 0 (false)
    std::cout << "[Comparison <=] Distance <= Distance2 : " << (distance <= distance2) << std::endl; // Output: 1 (true)
    std::cout << "[Comparison >] Distance > Distance2 : " << (distance > distance2) << std::endl; // Output: 0 (false)
    std::cout << "[Comparison >=] Distance >= Distance2 : " << (distance >= distance2) << std::endl; // Output: 1 (true)
}