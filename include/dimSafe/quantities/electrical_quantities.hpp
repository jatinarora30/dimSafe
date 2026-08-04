#pragma once

#include "../quantity.hpp"
#include "../dimensions/electrical_dimensions.hpp"
#include "../quantities/base_quantities.hpp"

namespace dimSafe {



template<typename Rep = double>
using Charge = Quantity<ChargeDimension, Rep>;

template<typename Rep = double>
using ElectricPotential = Quantity<ElectricPotentialDimension, Rep>;

template<typename Rep = double>
using Resistance = Quantity<ResistanceDimension, Rep>;

template<typename Rep = double>
using Capacitance = Quantity<CapacitanceDimension, Rep>;

template<typename Rep = double>
using Inductance = Quantity<InductanceDimension, Rep>;

template<typename Rep = double>
using Conductance = Quantity<ConductanceDimension, Rep>;

} // namespace dimSafe
