#include<iostream>
#include "dimSafe/include/dimSafe.hpp"

int main() {
    Distance<double> distance{10.0};
    Duration<double> duration{2.0};

    auto velocity = distance / duration;

    auto dist = velocity * duration;

    std::cout << velocity.value_ << std::endl; // Output: 5.0

    std::cout << dist.value_ << std::endl; // Output: 5.0

 
}