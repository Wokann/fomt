#ifndef HARDWARE_REFCOUNT_HH
#define HARDWARE_REFCOUNT_HH

#include "prelude.h"

// This lifetime owner only retains/reserves the shared state. Its original
// constructor does not write the owner's four-byte storage.
struct HardwareSharedStateOwner {
    u32 unk_00;
#ifdef __cplusplus
    void Reserve(u32 first, u32 count) asm("func_08007A28");
#endif
};

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
void * func_08007874(void * owner); // Constructs the shared state if needed.
void * func_080079D0(void * owner);
void func_080079E8(void * owner, u32 flags);
u32 func_08007B54(void * owner, u32 group_index); // Still in asm/hardware.s.

EXTERN_C_END

#endif // HARDWARE_REFCOUNT_HH
