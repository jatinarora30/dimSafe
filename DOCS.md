# dimSafe Documentation

## Overview

dimSafe is a header-only C++20 library for dimension-safe physical quantities.
It stores physical measurements as strongly typed quantities and uses compile-time dimension arithmetic to prevent invalid operations.

The library is built around two core concepts:

- `Dimension`: encodes the exponent vector for base physical dimensions.
- `Quantity<Dimension, Rep>`: wraps a numeric value and carries a dimension type.

This allows the compiler to reject operations such as adding distance to time or comparing force with velocity.

## Core Concepts

### Dimension

Defined in `include/dimSafe/dimension.hpp`:

```cpp
template<int Length,int Mass,int Time,int Current,int Temperature,int Amount,int LuminousIntensity>
struct Dimension {
    static constexpr int length = Length;
    static constexpr int mass = Mass;
    static constexpr int time = Time;
    static constexpr int current = Current;
    static constexpr int temperature = Temperature;
    static constexpr int amount = Amount;
    static constexpr int luminous_intensity = LuminousIntensity;
};
```

Each type parameter represents the exponent for a SI base dimension.
For example, distance is `Dimension<1,0,0,0,0,0,0>` and duration is `Dimension<0,0,1,0,0,0,0>`.

### Quantity

Defined in `include/dimSafe/quantity.hpp`:

```cpp
template<typename Dimension, typename Rep>
class Quantity {
public:
    Rep value_;
    // ... arithmetic and comparison operators ...
};
```

`Quantity` holds a numeric value and a compile-time dimension type.
The dimension type is part of the value's type, so incompatible quantities cannot be combined.

## Supported Operators

### Addition and subtraction

Implemented as member operators in `Quantity`.
They require both operands to have the same `Dimension`.

```cpp
Distance<> a{5.0};
Distance<> b{3.0};
Distance<> sum = a + b;
```

Attempting to add or subtract quantities with different dimensions is rejected at compile time.

### Comparison operators

The operators `==`, `!=`, `<`, `<=`, `>`, and `>=` are defined between quantities of the same dimension.
These comparisons are also compile-time dimension-safe.

### Scaling

A convenience method `scale(Scalar s)` multiplies the quantity by a scalar value:

```cpp
Distance<> d{4.0};
Distance<> scaled = d.scale(1.5);
```

### Multiplication and division

Defined in `include/dimSafe/dimSafe.hpp`.
The library computes result dimensions using:

- `MultiplyDimension<LeftDimension, RightDimension>`
- `DivideDimension<LeftDimension, RightDimension>`

For example:

```cpp
auto velocity = distance / duration;         // Dimension<1,0,-1,0,0,0,0>
auto force = mass * acceleration;           // Dimension<1,1,-2,0,0,0,0>
```

The resulting quantity type is automatically deduced from the dimension arithmetic.

## Quantity aliases

Common quantity aliases are defined under `include/dimSafe/quantities`.

### Base quantities (`base_quantities.hpp`)

- `Distance`
- `Duration`
- `Velocity`
- `Acceleration`
- `Mass`
- `Current`
- `Temperature`
- `Amount`
- `LuminousIntensity`

### Mechanical quantities (`mechanical_quantities.hpp`)

- `Force`
- `Momentum`
- `Energy`
- `Power`
- `Area`
- `Volume`
- `Pressure`
- `Density`

### Electrical quantities

- `Charge`
- `ElectricPotential`
- `Resistance`
- `Capacitance`
- `Inductance`
- `Conductance`

### Thermal quantities

- `HeatCapacity`
- `Entropy`

## Dimension definitions

Dimension aliases are provided in `include/dimSafe/dimensions`.
The mechanical and electrical units are built from the seven SI base exponents.

Example mechanical definitions:

```cpp
using ForceDimension = Dimension<1,1,-2,0,0,0,0>;
using EnergyDimension = Dimension<2,1,-2,0,0,0,0>;
```

Example electrical definitions:

```cpp
using ElectricPotentialDimension = Dimension<2,1,-3,-1,0,0,0>;
using ResistanceDimension = Dimension<2,1,-3,-2,0,0,0>;
```

## Typical usage

```cpp
#include <dimSafe/dimSafe.hpp>
using namespace dimSafe;

Distance<> distance{10.0};
Duration<> duration{2.0};
Velocity<> velocity = distance / duration;
Acceleration<> accel = velocity / duration;
Mass<> mass{4.0};
Force<> force = mass * accel;
Energy<> energy = force * distance;
```

## Example categories

### Mechanical

```cpp
Force<double> force = mass * accel;
Energy<double> energy = force * distance;
Pressure<double> pressure = force / Area<double>{2.0};
Density<double> density = mass / Volume<double>{0.5};
```

### Electrical

```cpp
ElectricPotential<double> voltage{12.0};
Resistance<double> resistance{4.0};
Current<double> current = voltage / resistance;
Charge<double> charge = current * Duration<double>{5.0};
Energy<double> energy = voltage * charge;
```

### Thermal

```cpp
Energy<double> heat{500.0};
Temperature<double> deltaT{25.0};
Entropy<double> entropy = heat / deltaT;
Power<double> power = heat / Duration<double>{10.0};
```

## Testing

The repository includes dedicated test sources in `test/`.

- `test/test_arithmetic.cpp` verifies addition, subtraction, and scaling for same-dimension quantities.
- `test/test_dimension_math.cpp` verifies compile-time derived dimensions for multiplication and division.
- `test/test_comparisons.cpp` verifies compare operators for same dimension quantities.

The `CMakeLists.txt` file registers these as CTest targets.

## Build instructions

From the repository root:

```bash
mkdir -p build
cd build
cmake ..
make
ctest --output-on-failure
```

## Design notes

- The library is intentionally minimal and header-only.
- It does not perform automatic unit conversion between different unit systems.
- Incompatible operations are prevented by the C++ type system.
- Addition / subtraction and comparisons must use the same quantity type.

## Robotics suitability

`dimSafe` is a good fit for robotics when you need:

- safe kinematic calculations
- consistent physical units in motion and dynamics code
- compile-time checks for unit correctness

However, robotics frameworks usually also need frame transforms, pose math, and middleware integration. `dimSafe` is best used as the quantity layer in a larger robotics stack.
