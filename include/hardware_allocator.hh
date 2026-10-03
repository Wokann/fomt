#ifndef HARDWARE_ALLOCATOR_HH
#define HARDWARE_ALLOCATOR_HH

#include "hardware.hh"

// The allocated handle uses bits 0..3 for the slot and bits 4..19 for its
// generation. Validation ignores the remaining bits.
union HardwareHandle
{
    u32 value;
    struct
    {
        u32 index : 4;
        u32 generation : 16;
        u32 : 12;
    } fields;

    u32 Index() const { return fields.index; }
};

typedef char HardwareHandleSizeCheck[sizeof(HardwareHandle) == 4 ? 1 : -1];

EXTERN_C

// These entries use the shared allocator, not the receiver passed in r0.
u32 func_0800736C(void * self); // Still implemented in asm/hardware.s.
void func_080073E0(void * self, u32 handle);
u32 func_0800745C(void * self, u32 handle);
u32 func_080074C0(void * self, u32 handle);
u32 func_08007510(void * self, u32 handle);

u16 func_08007564(void);
u32 func_08007574(void);

EXTERN_C_END

#endif // HARDWARE_ALLOCATOR_HH
