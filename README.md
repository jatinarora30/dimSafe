# dimSafe

dimSafe is a header-only C++ library for type-safe physical quantities.
It uses compile-time dimension checking so operations such as adding incompatible units fail at compile time.

## Features

- Strongly-typed quantities using `Quantity<Tag, Dimension, Rep>`
- Base dimensions: length, mass, time, current, temperature, amount, luminous intensity
- Derived mechanical quantities: distance, velocity, acceleration, force, energy, power, pressure, density, momentum, area, volume
- Electrical quantities: charge, electric potential, resistance, capacitance, inductance, conductance
- Thermal quantities: entropy, heat capacity
- Compile-time relationships for multiplication and division
- Minimal header-only design, C++20 compatible

## Quick start

Include the library header in your project:

```cpp
#include <dimSafe/dimSafe.hpp>
```

The library defines `Quantity` alias types for many common dimensions:

```cpp
using namespace dimSafe;

Distance<> distance{10.0};
Duration<> duration{2.0};
Velocity<> velocity = distance / duration;
```

## Mechanical examples

```cpp
#include <dimSafe/dimSafe.hpp>

using namespace dimSafe;

Distance<double> distance{10.0};
Duration<double> duration{2.0};
Velocity<double> velocity = distance / duration; // length / time
Acceleration<double> accel{2.5};
Mass<double> mass{4.0};
Force<double> force = mass * accel; // mass * acceleration
Energy<double> energy = force * distance; // force * distance
Pressure<double> pressure = force / Area<double>{2.0}; // force / area
Density<double> density = mass / Volume<double>{0.5}; // mass / volume
```

## Electrical examples

```cpp
#include <dimSafe/dimSafe.hpp>

using namespace dimSafe;

ElectricPotential<double> voltage{12.0};
Resistance<double> resistance{4.0};
Current<double> current = voltage / resistance; // electric potential / resistance
Charge<double> charge = current * Duration<double>{5.0}; // current * time
Energy<double> energy = voltage * charge; // potential * charge
```

## Thermal examples

```cpp
#include <dimSafe/dimSafe.hpp>

using namespace dimSafe;

Energy<double> heat{500.0};
Temperature<double> deltaT{25.0};
Entropy<double> entropy = heat / deltaT; // energy / temperature
Power<double> power = heat / Duration<double>{10.0}; // energy / time
```

## Build and test

```bash
mkdir -p build
cd build
cmake ..
make
ctest --output-on-failure
```

## Notes

- The library is header-only and works with C++20.
- Quantity operations are intentionally limited to supported dimension rules.
- The examples are available in `include/dimSafe/examples.hpp` and `test/test.cpp`.
