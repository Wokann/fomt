#ifndef HARDWARE_NESTED_ACCESSORS_HH
#define HARDWARE_NESTED_ACCESSORS_HH

#include "hardware_manager.hh"

EXTERN_C

// The retail image retains two distinct entries for this same member view.
struct HardwareInterruptList * func_08008AE0(struct HardwareManagerOwner const * owner);
struct HardwareInterruptList * func_08008AE8(struct HardwareManagerOwner const * owner);

EXTERN_C_END

#endif // HARDWARE_NESTED_ACCESSORS_HH
