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

    HardwareHandle() {}
    HardwareHandle(u32 index, Unk_hardware_ent_080D6D98 const & entry) : value(0)
    {
        fields.index = index;
        fields.generation = entry.params.unk_02;
    }

    u32 Index() const { return fields.index; }
};

typedef char HardwareHandleSizeCheck[sizeof(HardwareHandle) == 4 ? 1 : -1];

EXTERN_C

// These entries use the shared allocator, not the receiver passed in r0.
u32 AllocateHardwarePoolHandle(void * self);
// Null, inactive and stale-generation handles leave the pool unchanged.
// Dropping the last reference returns the slot to the free list.
void ReleaseHardwarePoolHandle(void * self, u32 handle);
// Return the original handle on success, or zero on validation failure
// or 16-bit reference-count overflow; overflow restores the old count.
u32 RetainHardwarePoolHandle(void * self, u32 handle);
// Invalid handles return UINT32_MAX here, but zero from the count query.
u32 GetHardwarePoolHandleIndex(void * self, u32 handle);
u32 GetHardwarePoolHandleReferenceCount(void * self, u32 handle);

// Number of occupied pool slots, independent of each slot's references.
u16 GetHardwarePoolAllocatedCount(void);
u32 GetHardwarePoolCapacity(void);

EXTERN_C_END

#endif // HARDWARE_ALLOCATOR_HH
