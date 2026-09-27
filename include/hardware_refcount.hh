#ifndef HARDWARE_REFCOUNT_HH
#define HARDWARE_REFCOUNT_HH

#include "prelude.h"

EXTERN_C

extern u8 * gUnk_03000408;

// Only the trailing fields accessed by the decoded hardware-state routines
// are classified. Keep the preceding bytes opaque until their layout is known.
typedef struct HardwareSharedState {
    u8 unk_000[0x920];
    u16 unk_920;
    u16 unk_922;
    u32 reference_count;
    u16 unk_928;
    u16 unk_92A;
} HardwareSharedState;

// Retain the shared hardware state and return the supplied owner unchanged.
void * func_080079D0(void * owner);
void func_080079E8(void * owner, u32 flags);

EXTERN_C_END

#endif // HARDWARE_REFCOUNT_HH
