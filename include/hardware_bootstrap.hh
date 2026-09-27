#ifndef HARDWARE_BOOTSTRAP_HH
#define HARDWARE_BOOTSTRAP_HH

#include "hardware_state_accessors.hh"

struct HardwareBootstrap {
    struct HardwareCoreState * state;
    void ** vtable;
};

EXTERN_C

void func_080086BC(struct HardwareBootstrap * owner, u32 flags);

EXTERN_C_END

#endif // HARDWARE_BOOTSTRAP_HH
