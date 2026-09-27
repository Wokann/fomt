#ifndef HARDWARE_MANAGER_HH
#define HARDWARE_MANAGER_HH

#include "prelude.h"

struct HardwareManagerOwner {
    void * state;
};

EXTERN_C

void func_08008A68(struct HardwareManagerOwner * owner, u32 flags);

EXTERN_C_END

#endif // HARDWARE_MANAGER_HH
