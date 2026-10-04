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

// OBJ allocation handles contain an eight-bit slot and a sixteen-bit
// generation. The upper byte does not participate in validation.
typedef union HardwareSharedStateHandle {
    u32 value;
    struct {
        u32 index : 8;
        u32 generation : 16;
        u32 : 8;
    } fields;
#ifdef __cplusplus
    u32 Index() const { return fields.index; }
#endif
} HardwareSharedStateHandle;

typedef struct HardwareSharedStateEntry HardwareSharedStateEntry;
struct HardwareSharedStateEntry {
    union {
        HardwareSharedStateEntry * next_free;
        struct {
            u16 tile_index : 10;
            u16 size_shift : 4;
            u16 unk_0E : 2;
            u16 reference_count;
        } params;
    } data;
    u16 generation;
    u16 unk_06;
};

typedef struct HardwareSharedStatePool {
    HardwareSharedStateEntry * first_free;
    HardwareSharedStateEntry entries[256];
#ifdef __cplusplus
    HardwareSharedStateEntry & GetEntry(u32 index) { return entries[index]; }
#endif
} HardwareSharedStatePool;

typedef struct HardwareSharedState {
    u32 occupied[8];
    HardwareSharedStatePool pool;
    u8 unk_824[0xFC];
    u16 unk_920;
    u16 unk_922;
    u32 reference_count;
    u16 unk_928;
    u16 unk_92A;
#ifdef __cplusplus
    bool IsAllocated(u32 index) const
    {
        return index < 256 && (occupied[index / 32] & (1u << (index % 32u))) != 0;
    }
#endif
} HardwareSharedState;

typedef char HardwareSharedStateHandleSizeCheck[sizeof(HardwareSharedStateHandle) == 4 ? 1 : -1];
typedef char HardwareSharedStateEntrySizeCheck[sizeof(HardwareSharedStateEntry) == 8 ? 1 : -1];
typedef char HardwareSharedStateEntryRefcountCheck[offsetof(HardwareSharedStateEntry, data.params.reference_count) == 2 ? 1 : -1];
typedef char HardwareSharedStateEntryGenerationCheck[offsetof(HardwareSharedStateEntry, generation) == 4 ? 1 : -1];
typedef char HardwareSharedStatePoolEntriesCheck[offsetof(HardwareSharedStatePool, entries) == 4 ? 1 : -1];
typedef char HardwareSharedStatePoolOffsetCheck[offsetof(HardwareSharedState, pool) == 0x20 ? 1 : -1];
typedef char HardwareSharedStateTailOffsetCheck[offsetof(HardwareSharedState, unk_824) == 0x824 ? 1 : -1];
typedef char HardwareSharedStateRefcountOffsetCheck[offsetof(HardwareSharedState, reference_count) == 0x924 ? 1 : -1];
typedef char HardwareSharedStateSizeCheck[sizeof(HardwareSharedState) == 0x92C ? 1 : -1];

EXTERN_C

extern u8 * gUnk_03000408;

// Retain the shared hardware state and return the supplied owner unchanged.
void * func_08007874(void * owner); // Constructs the shared state if needed.
void * func_080079D0(void * owner);
void func_080079E8(void * owner, u32 flags);
u32 func_08007B54(void * owner, u32 group_index); // Still in asm/hardware.s.

// Returns the same validated handle; overflow restores the count and returns 0.
u32 RetainHardwareSharedStateHandle(void * owner, u32 handle);

// count must be positive; each eight-byte entry links to the following entry.
HardwareSharedStateEntry * InitializeHardwareSharedStateFreeList(
    HardwareSharedStateEntry * entries, i32 count, HardwareSharedStateEntry * tail);

// The receiver is unused; each query validates a handle in the shared pool.
u32 GetHardwareSharedStateTileIndex(void * owner, u32 handle);
u32 GetHardwareSharedStateSizeShift(void * owner, u32 handle);
u32 GetHardwareSharedStateReferenceCount(void * owner, u32 handle);

EXTERN_C_END

#endif // HARDWARE_REFCOUNT_HH
