#ifndef HARDWARE_REFCOUNT_HH
#define HARDWARE_REFCOUNT_HH

#include "prelude.h"
#include "hardware_mask.hh"

// This lifetime owner only retains/reserves the shared state. Its original
// constructor does not write the owner's four-byte storage.
struct HardwareSharedStateOwner {
    u32 unk_00;
#ifdef __cplusplus
    HardwareSharedStateOwner() asm("func_08007874");
    HardwareSharedStateOwner(HardwareSharedStateOwner const &);
    ~HardwareSharedStateOwner();
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

    // The caller passes the current head; return the pool's previous head.
    HardwareSharedStateEntry * AllocEntry(HardwareSharedStateEntry * entry)
    {
        HardwareSharedStateEntry * previous = first_free;
        if (entry != 0)
            first_free = entry->data.next_free;
        return previous;
    }
#endif
} HardwareSharedStatePool;

// The 1024-tile allocation tree has two children per level and 32-bit leaves.
// The native clear/reserve routines use the two flag bytes at each node head.
// Old agbcc's C bool is an int; keep the same one-byte ABI for C consumers.
#ifdef __cplusplus
typedef bool HardwareTileTreeFlag;
#else
typedef u8 HardwareTileTreeFlag;
#endif

typedef struct HardwareTileTree64 {
    HardwareTileTreeFlag full;
    HardwareTileTreeFlag empty;
    HardwareTileBitmap32 children[2];
#ifdef __cplusplus
    HardwareTileTree64() : full(false), empty(true) {}
    // Allocate 2^size_shift tiles, or return this node's capacity on failure.
    u32 Allocate(u32 size_shift) SECTION(".text.hardware_shared_state_tile_tree_operations");
    void Free(u32 offset, u32 size_shift) SECTION(".text.hardware_shared_state_tile_tree_operations");
    void Reserve(u32 offset, u32 length) SECTION(".text.hardware_shared_state_tile_tree");
    void Unreserve(u32 offset, u32 length) SECTION(".text.hardware_shared_state_tile_tree_unreserve");
#endif
} HardwareTileTree64;

typedef struct HardwareTileTree128 {
    HardwareTileTreeFlag full;
    HardwareTileTreeFlag empty;
    HardwareTileTree64 children[2];
#ifdef __cplusplus
    HardwareTileTree128() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift) SECTION(".text.hardware_shared_state_tile_tree_operations");
    void Free(u32 offset, u32 size_shift) SECTION(".text.hardware_shared_state_tile_tree_operations");
    // These two bodies remain in asm/code_linkonce.s with this member ABI.
    void Reserve(u32 offset, u32 length);
    void Unreserve(u32 offset, u32 length);
#endif
} HardwareTileTree128;

typedef struct HardwareTileTree256 {
    HardwareTileTreeFlag full;
    HardwareTileTreeFlag empty;
    HardwareTileTree128 children[2];
#ifdef __cplusplus
    HardwareTileTree256() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift) SECTION(".text.hardware_shared_state_tile_tree_operations");
    void Free(u32 offset, u32 size_shift) SECTION(".text.hardware_shared_state_tile_tree_operations");
    // These two bodies remain in asm/code_linkonce.s with this member ABI.
    void Reserve(u32 offset, u32 length);
    void Unreserve(u32 offset, u32 length);
#endif
} HardwareTileTree256;

typedef struct HardwareTileTree512 {
    HardwareTileTreeFlag full;
    HardwareTileTreeFlag empty;
    HardwareTileTree256 children[2];
#ifdef __cplusplus
    HardwareTileTree512() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift) SECTION(".text.hardware_shared_state_tile_tree_operations");
    void Free(u32 offset, u32 size_shift) SECTION(".text.hardware_shared_state_tile_tree_operations");
    void Reserve(u32 offset, u32 length) SECTION(".text.hardware_shared_state_tile_tree_after");
    void Unreserve(u32 offset, u32 length) SECTION(".text.hardware_shared_state_tile_tree_unreserve_after");
#endif
} HardwareTileTree512;

typedef struct HardwareTileTree1024 {
    HardwareTileTreeFlag full;
    HardwareTileTreeFlag empty;
    HardwareTileTree512 children[2];
#ifdef __cplusplus
    HardwareTileTree1024();
    void Fill();
    void Clear();
    void Reserve(u32 offset, u32 length);
    void Unreserve(u32 offset, u32 length);
    // Allocate 2^size_shift tiles, or return 1024 when no range is available.
    u32 Allocate(u32 size_shift);
    void Free(u32 offset, u32 size_shift);
    bool IsEmpty() const;
    bool IsFull() const;
#endif
} HardwareTileTree1024;

typedef struct HardwareSharedState {
    u32 occupied[8];
    HardwareSharedStatePool pool;
    HardwareTileTree1024 tile_tree;
    u16 allocation_count;
    u16 next_generation;
    u32 reference_count;
    u16 reserved_first;
    u16 reserved_count;
#ifdef __cplusplus
    bool IsAllocated(u32 index) const
    {
        return index < 256 && (occupied[index / 32] & (1u << (index % 32u))) != 0;
    }
#endif
} HardwareSharedState;

typedef char HardwareSharedStateOwnerSizeCheck[sizeof(struct HardwareSharedStateOwner) == 4 ? 1 : -1];
typedef char HardwareSharedStateHandleSizeCheck[sizeof(HardwareSharedStateHandle) == 4 ? 1 : -1];
typedef char HardwareSharedStateEntrySizeCheck[sizeof(HardwareSharedStateEntry) == 8 ? 1 : -1];
typedef char HardwareSharedStateEntryRefcountCheck[offsetof(HardwareSharedStateEntry, data.params.reference_count) == 2 ? 1 : -1];
typedef char HardwareSharedStateEntryGenerationCheck[offsetof(HardwareSharedStateEntry, generation) == 4 ? 1 : -1];
typedef char HardwareSharedStatePoolEntriesCheck[offsetof(HardwareSharedStatePool, entries) == 4 ? 1 : -1];
typedef char HardwareTileTreeFlagSizeCheck[sizeof(HardwareTileTreeFlag) == 1 ? 1 : -1];
typedef char HardwareTileTree64SizeCheck[sizeof(HardwareTileTree64) == 0xC ? 1 : -1];
typedef char HardwareTileTree128SizeCheck[sizeof(HardwareTileTree128) == 0x1C ? 1 : -1];
typedef char HardwareTileTree256SizeCheck[sizeof(HardwareTileTree256) == 0x3C ? 1 : -1];
typedef char HardwareTileTree512SizeCheck[sizeof(HardwareTileTree512) == 0x7C ? 1 : -1];
typedef char HardwareTileTree1024SizeCheck[sizeof(HardwareTileTree1024) == 0xFC ? 1 : -1];
typedef char HardwareTileTreeChildrenOffsetCheck[offsetof(HardwareTileTree1024, children) == 4 ? 1 : -1];
typedef char HardwareSharedStatePoolOffsetCheck[offsetof(HardwareSharedState, pool) == 0x20 ? 1 : -1];
typedef char HardwareSharedStateTreeOffsetCheck[offsetof(HardwareSharedState, tile_tree) == 0x824 ? 1 : -1];
typedef char HardwareSharedStateCountOffsetCheck[offsetof(HardwareSharedState, allocation_count) == 0x920 ? 1 : -1];
typedef char HardwareSharedStateGenerationOffsetCheck[offsetof(HardwareSharedState, next_generation) == 0x922 ? 1 : -1];
typedef char HardwareSharedStateRefcountOffsetCheck[offsetof(HardwareSharedState, reference_count) == 0x924 ? 1 : -1];
typedef char HardwareSharedStateReservedOffsetCheck[offsetof(HardwareSharedState, reserved_first) == 0x928 ? 1 : -1];
typedef char HardwareSharedStateSizeCheck[sizeof(HardwareSharedState) == 0x92C ? 1 : -1];

EXTERN_C

extern HardwareSharedState * gUnk_03000408;

// The default constructor remains in assembly. Raw-storage initialization
// sites use the same entry without invoking an enclosing C++ constructor.
void * func_08007874(void * owner);

// Allocate a 2^size_shift tile range and a generation-checked slot handle.
// A failed slot allocation returns the tile range and yields the zero handle.
u32 AllocateHardwareSharedStateHandle(void * owner, u32 size_shift);

// Returns the same validated handle; overflow restores the count and returns 0.
u32 RetainHardwareSharedStateHandle(void * owner, u32 handle);
// The last reference frees the tile range and returns the slot to its free list.
void ReleaseHardwareSharedStateHandle(void * owner, u32 handle);

// Fill both children before marking the parent tile range full.
void FillHardwareTileTree64(HardwareTileTree64 * tree);
void FillHardwareTileTree128(HardwareTileTree128 * tree);
void FillHardwareTileTree256(HardwareTileTree256 * tree);
void FillHardwareTileTree512(HardwareTileTree512 * tree);

// Clear both children before marking the parent tile range empty.
void ClearHardwareTileTree64(HardwareTileTree64 * tree);
void ClearHardwareTileTree128(HardwareTileTree128 * tree);
void ClearHardwareTileTree256(HardwareTileTree256 * tree);
void ClearHardwareTileTree512(HardwareTileTree512 * tree);

// count must be positive; each eight-byte entry links to the following entry.
HardwareSharedStateEntry * InitializeHardwareSharedStateFreeList(
    HardwareSharedStateEntry * entries, i32 count, HardwareSharedStateEntry * tail);

// The receiver is unused; each query validates a handle in the shared pool.
u32 GetHardwareSharedStateTileIndex(void const * owner, u32 handle);
u32 GetHardwareSharedStateSizeShift(void * owner, u32 handle);
u32 GetHardwareSharedStateReferenceCount(void * owner, u32 handle);

EXTERN_C_END

#endif // HARDWARE_REFCOUNT_HH
