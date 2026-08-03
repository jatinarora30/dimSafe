#pragma once

#include "../quantity.hpp"
#include "../dimensions/electrical_dimensions.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {

struct ChargeTag {};
struct ElectricPotentialTag {};
struct ResistanceTag {};
struct CapacitanceTag {};
struct InductanceTag {};
struct ConductanceTag {};

template<typename Rep = double>
using Charge = Quantity<ChargeTag, ChargeDimension, Rep>;

template<typename Rep = double>
using ElectricPotential = Quantity<ElectricPotentialTag, ElectricPotentialDimension, Rep>;

template<typename Rep = double>
using Resistance = Quantity<ResistanceTag, ResistanceDimension, Rep>;

template<typename Rep = double>
using Capacitance = Quantity<CapacitanceTag, CapacitanceDimension, Rep>;

template<typename Rep = double>
using Inductance = Quantity<InductanceTag, InductanceDimension, Rep>;

template<typename Rep = double>
using Conductance = Quantity<ConductanceTag, ConductanceDimension, Rep>;

} // namespace dimSafe
