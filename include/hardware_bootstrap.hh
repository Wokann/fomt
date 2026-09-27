#ifndef HARDWARE_BOOTSTRAP_HH
#define HARDWARE_BOOTSTRAP_HH

#include "hardware_state_accessors.hh"

struct HardwareBootstrap {
    struct HardwareCoreState * state;
    void ** vtable;
};

struct HardwareDisplayCommand {
    void * previous_slot;
    void * next;
    void ** vtable;
    struct HardwareDisplayState * display;
};

EXTERN_C

void func_080086BC(struct HardwareBootstrap * owner, u32 flags);
void func_08008724(struct HardwareBootstrap * owner);
void func_08008774(struct HardwareBootstrap * owner);

EXTERN_C_END

#endif // HARDWARE_BOOTSTRAP_HH
