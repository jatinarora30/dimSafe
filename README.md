# dimSafe

dimSafe is a header-only C++ library for type-safe physical quantities.
It performs compile-time dimension checking so invalid operations such as adding incompatible units fail at compile time.

## Features

- Strongly-typed quantities using `Quantity<Dimension, Rep>`
- Base dimensions: length, mass, time, current, temperature, amount, luminous intensity
- Mechanical quantities: distance, velocity, acceleration, force, energy, power, pressure, density, momentum, area, volume
- Electrical quantities: charge, electric potential, resistance, capacitance, inductance, conductance
- Thermal quantities: entropy, heat capacity
- Compile-time multiplication and division relationships for derived units
- Addition, subtraction and comparison operators require the same quantity type (same dimension)
- Header-only design with C++20 compatibility

## Quick start

Include the library header in your project:

```cpp
#include <dimSafe/dimSafe.hpp>
```

For convenience, import the `dimSafe` namespace and instantiate common quantities:

```cpp
using namespace dimSafe;

Distance<> distance{10.0};
Duration<> duration{2.0};
Velocity<> velocity = distance / duration; // length / time
```

## Example usage

### Mechanical quantities

```cpp
#include <dimSafe/dimSafe.hpp>

using namespace dimSafe;

Distance<double> distance{10.0};
Duration<double> duration{2.0};
Velocity<double> velocity = distance / duration;        // length / time
Acceleration<double> accel{2.5};
Mass<double> mass{4.0};
Force<double> force = mass * accel;                    // mass * acceleration
Energy<double> energy = force * distance;              // force * distance
Pressure<double> pressure = force / Area<double>{2.0}; // force / area
Density<double> density = mass / Volume<double>{0.5};  // mass / volume
```

### Electrical quantities

```cpp
#include <dimSafe/dimSafe.hpp>

using namespace dimSafe;

ElectricPotential<double> voltage{12.0};
Resistance<double> resistance{4.0};
Current<double> current = voltage / resistance;       // electric potential / resistance
Charge<double> charge = current * Duration<double>{5.0}; // current * time
Energy<double> energy = voltage * charge;             // potential * charge
```

### Thermal quantities

```cpp
#include <dimSafe/dimSafe.hpp>

using namespace dimSafe;

Energy<double> heat{500.0};
Temperature<double> deltaT{25.0};
Entropy<double> entropy = heat / deltaT;              // energy / temperature
Power<double> power = heat / Duration<double>{10.0};  // energy / time
```

## Example execution

The project includes a sample executable in `examples/example.cpp`.

Build and run it from the repository root:

```bash
mkdir -p build
cd build
cmake ..
make
./dimSafe_example
```

The example demonstrates chained dimension arithmetic, comparisons, and how `std::boolalpha` prints boolean results as `true`/`false` for clarity.

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
- Quantity operations are only enabled for supported dimension rules; incompatible operations are rejected at compile time.
- Example source is `examples/example.cpp`.
- Test coverage is in `test/test.cpp`.
- Detailed code documentation is available in `DOCS.md`.
