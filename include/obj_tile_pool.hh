#ifndef OBJ_TILE_POOL_HH
#define OBJ_TILE_POOL_HH

// The handle format has an eight-bit slot index. This is independent of
// the OBJ tile address range; an 8bpp tile occupies two 32-byte units.
#define OBJ_TILE_HANDLE_INDEX_BITS 8
#define OBJ_TILE_HANDLE_COUNT (1 << OBJ_TILE_HANDLE_INDEX_BITS)
#define OBJ_TILE_INDEX_BITS 10
#define OBJ_TILE_SIZE_SHIFT_BITS 4
#define OBJ_TILE_SLOT_WORD_SHIFT 5
#define OBJ_TILE_SLOT_WORD_BITS (1 << OBJ_TILE_SLOT_WORD_SHIFT)
#define OBJ_TILE_POOL_ENTRY_BYTES 8
#define OBJ_TILE_ENTRY_GENERATION_OFFSET 4

// Shared with the two native routines below. The type checks bind these
// field and child-stride expressions to the C++ declarations, not ROM addresses.
#define OBJ_TILE_TREE_CHILDREN_OFFSET 4
#define OBJ_TILE_TREE64_BYTES (OBJ_TILE_TREE_CHILDREN_OFFSET + 2 * 4)
#define OBJ_TILE_TREE128_BYTES (OBJ_TILE_TREE_CHILDREN_OFFSET + 2 * OBJ_TILE_TREE64_BYTES)
#define OBJ_TILE_TREE256_BYTES (OBJ_TILE_TREE_CHILDREN_OFFSET + 2 * OBJ_TILE_TREE128_BYTES)
#define OBJ_TILE_TREE512_BYTES (OBJ_TILE_TREE_CHILDREN_OFFSET + 2 * OBJ_TILE_TREE256_BYTES)
#define OBJ_TILE_TREE1024_BYTES (OBJ_TILE_TREE_CHILDREN_OFFSET + 2 * OBJ_TILE_TREE512_BYTES)
#define OBJ_TILE_POOL_FREE_LIST_OFFSET (OBJ_TILE_HANDLE_COUNT / OBJ_TILE_SLOT_WORD_BITS * 4)
#define OBJ_TILE_POOL_ENTRIES_OFFSET (OBJ_TILE_POOL_FREE_LIST_OFFSET + 4)
#define OBJ_TILE_POOL_TREE_OFFSET (OBJ_TILE_POOL_ENTRIES_OFFSET + OBJ_TILE_HANDLE_COUNT * OBJ_TILE_POOL_ENTRY_BYTES)
#define OBJ_TILE_POOL_COUNT_OFFSET (OBJ_TILE_POOL_TREE_OFFSET + OBJ_TILE_TREE1024_BYTES)
#define OBJ_TILE_POOL_GENERATION_OFFSET (OBJ_TILE_POOL_COUNT_OFFSET + 2)
#define OBJ_TILE_POOL_REFCOUNT_OFFSET (OBJ_TILE_POOL_GENERATION_OFFSET + 2)
#define OBJ_TILE_POOL_RESERVED_FIRST_OFFSET (OBJ_TILE_POOL_REFCOUNT_OFFSET + 4)
#define OBJ_TILE_POOL_RESERVED_COUNT_OFFSET (OBJ_TILE_POOL_RESERVED_FIRST_OFFSET + 2)
#define OBJ_TILE_POOL_BYTES (OBJ_TILE_POOL_RESERVED_COUNT_OFFSET + 2)

#ifndef __ASSEMBLER__

#include "prelude.h"
#include "gbaio.h"
#include "obj_tile_bitmap.hh"

// This lifetime owner only retains/reserves the shared state. Its original
// constructor does not write the owner's four-byte storage.
struct ObjTilePoolOwner {
    u32 unk_00;
#ifdef __cplusplus
    ObjTilePoolOwner() asm("InitializeObjTilePoolOwner");
    ObjTilePoolOwner(ObjTilePoolOwner const &);
    ~ObjTilePoolOwner();
    // Replaces one global reserved range, invalidating whole overlapping
    // allocations even if their handles still have outstanding references.
    void Reserve(u32 first, u32 count) asm("SetObjTileReservation");
#endif
};

// OBJ allocation handles contain an eight-bit slot and a sixteen-bit
// generation. The upper byte does not participate in validation.
typedef union ObjTileHandle {
    u32 value;
    struct {
        u32 index : OBJ_TILE_HANDLE_INDEX_BITS;
        u32 generation : 16;
        u32 : (32 - OBJ_TILE_HANDLE_INDEX_BITS - 16);
    } fields;
#ifdef __cplusplus
    u32 Index() const { return fields.index; }
#endif
} ObjTileHandle;

typedef struct ObjTilePoolEntry ObjTilePoolEntry;
struct ObjTilePoolEntry {
    union {
        ObjTilePoolEntry * next_free;
        struct {
            u16 tile_index : OBJ_TILE_INDEX_BITS;
            u16 size_shift : OBJ_TILE_SIZE_SHIFT_BITS;
            u16 unk_0E : (16 - OBJ_TILE_INDEX_BITS - OBJ_TILE_SIZE_SHIFT_BITS);
            u16 reference_count;
        } params;
    } data;
    u16 generation;
    u16 unk_06;
};

typedef struct ObjTileHandlePool {
    ObjTilePoolEntry * first_free;
    ObjTilePoolEntry entries[OBJ_TILE_HANDLE_COUNT];
#ifdef __cplusplus
    ObjTilePoolEntry & GetEntry(u32 index) { return entries[index]; }

    // The caller passes the current head; return the pool's previous head.
    ObjTilePoolEntry * AllocEntry(ObjTilePoolEntry * entry)
    {
        ObjTilePoolEntry * previous = first_free;
        if (entry != 0)
            first_free = entry->data.next_free;
        return previous;
    }
#endif
} ObjTileHandlePool;

// The 1024-tile allocation tree has two children per level and 32-bit leaves.
// The native clear/reserve routines use the two flag bytes at each node head.
// Old agbcc's C bool is an int; keep the same one-byte ABI for C consumers.
#ifdef __cplusplus
typedef bool ObjTileTreeFlag;
#else
typedef u8 ObjTileTreeFlag;
#endif

typedef struct ObjTileTree64 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileBitmap32 children[2];
#ifdef __cplusplus
    ObjTileTree64() : full(false), empty(true) {}
    // Allocate 2^size_shift tiles, or return this node's capacity on failure.
    u32 Allocate(u32 size_shift) SECTION(".text.obj_tile_tree_operations");
    void Free(u32 offset, u32 size_shift) SECTION(".text.obj_tile_tree_operations");
    void Reserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree");
    void Unreserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_unreserve");
#endif
} ObjTileTree64;

typedef struct ObjTileTree128 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileTree64 children[2];
#ifdef __cplusplus
    ObjTileTree128() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift) SECTION(".text.obj_tile_tree_operations");
    void Free(u32 offset, u32 size_shift) SECTION(".text.obj_tile_tree_operations");
    void Reserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_after");
    void Unreserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_unreserve_after");
#endif
} ObjTileTree128;

typedef struct ObjTileTree256 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileTree128 children[2];
#ifdef __cplusplus
    ObjTileTree256() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift) SECTION(".text.obj_tile_tree_operations");
    void Free(u32 offset, u32 size_shift) SECTION(".text.obj_tile_tree_operations");
    void Reserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_after");
    void Unreserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_unreserve_after");
#endif
} ObjTileTree256;

typedef struct ObjTileTree512 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileTree256 children[2];
#ifdef __cplusplus
    ObjTileTree512() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift) SECTION(".text.obj_tile_tree_operations");
    void Free(u32 offset, u32 size_shift) SECTION(".text.obj_tile_tree_operations");
    void Reserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_after");
    void Unreserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_unreserve_after");
#endif
} ObjTileTree512;

typedef struct ObjTileTree1024 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileTree512 children[2];
#ifdef __cplusplus
    ObjTileTree1024() SECTION(".text.obj_tile_tree_root");
    void Fill() SECTION(".text.obj_tile_tree_root");
    void Clear() SECTION(".text.obj_tile_tree_root");
    void Reserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_root");
    void Unreserve(u32 offset, u32 length) SECTION(".text.obj_tile_tree_root");
    // Allocate 2^size_shift tiles, or return 1024 when no range is available.
    u32 Allocate(u32 size_shift) SECTION(".text.obj_tile_tree_root");
    void Free(u32 offset, u32 size_shift) SECTION(".text.obj_tile_tree_root");
    bool IsEmpty() const SECTION(".text.obj_tile_tree_root");
    bool IsFull() const SECTION(".text.obj_tile_tree_root");
#endif
} ObjTileTree1024;

typedef struct ObjTilePoolState {
    u32 occupied[OBJ_TILE_HANDLE_COUNT / OBJ_TILE_SLOT_WORD_BITS];
    ObjTileHandlePool pool;
    ObjTileTree1024 tile_tree;
    u16 allocation_count;
    u16 next_generation;
    u32 reference_count;
    u16 reserved_first;
    u16 reserved_count;
#ifdef __cplusplus
    bool IsAllocated(u32 index) const
    {
        return index < ARRAY_COUNT(pool.entries) && (occupied[index / OBJ_TILE_SLOT_WORD_BITS] & (1u << (index % OBJ_TILE_SLOT_WORD_BITS))) != 0;
    }
#endif
} ObjTilePoolState;

typedef char ObjTilePoolOwnerSizeCheck[sizeof(struct ObjTilePoolOwner) == 4 ? 1 : -1];
typedef char ObjTileHandleSizeCheck[sizeof(ObjTileHandle) == 4 ? 1 : -1];
typedef char ObjTilePoolEntrySizeCheck[sizeof(ObjTilePoolEntry) == OBJ_TILE_POOL_ENTRY_BYTES ? 1 : -1];
typedef char ObjTilePoolEntryRefcountCheck[offsetof(ObjTilePoolEntry, data.params.reference_count) == 2 ? 1 : -1];
typedef char ObjTilePoolEntryGenerationCheck[offsetof(ObjTilePoolEntry, generation) == OBJ_TILE_ENTRY_GENERATION_OFFSET ? 1 : -1];
typedef char ObjTileHandlePoolEntriesCheck[offsetof(ObjTileHandlePool, entries) == 4 ? 1 : -1];
typedef char ObjTileTreeFlagSizeCheck[sizeof(ObjTileTreeFlag) == 1 ? 1 : -1];
typedef char ObjTileTree64SizeCheck[sizeof(ObjTileTree64) == OBJ_TILE_TREE64_BYTES ? 1 : -1];
typedef char ObjTileTree128SizeCheck[sizeof(ObjTileTree128) == OBJ_TILE_TREE128_BYTES ? 1 : -1];
typedef char ObjTileTree256SizeCheck[sizeof(ObjTileTree256) == OBJ_TILE_TREE256_BYTES ? 1 : -1];
typedef char ObjTileTree512SizeCheck[sizeof(ObjTileTree512) == OBJ_TILE_TREE512_BYTES ? 1 : -1];
typedef char ObjTileTree1024SizeCheck[sizeof(ObjTileTree1024) == OBJ_TILE_TREE1024_BYTES ? 1 : -1];
typedef char ObjTileTreeChildrenOffsetCheck[offsetof(ObjTileTree1024, children) == OBJ_TILE_TREE_CHILDREN_OFFSET ? 1 : -1];
typedef char ObjTileHandlePoolOffsetCheck[offsetof(ObjTilePoolState, pool) == OBJ_TILE_POOL_FREE_LIST_OFFSET ? 1 : -1];
typedef char ObjTilePoolStateTreeOffsetCheck[offsetof(ObjTilePoolState, tile_tree) == OBJ_TILE_POOL_TREE_OFFSET ? 1 : -1];
typedef char ObjTilePoolStateCountOffsetCheck[offsetof(ObjTilePoolState, allocation_count) == OBJ_TILE_POOL_COUNT_OFFSET ? 1 : -1];
typedef char ObjTilePoolStateGenerationOffsetCheck[offsetof(ObjTilePoolState, next_generation) == OBJ_TILE_POOL_GENERATION_OFFSET ? 1 : -1];
typedef char ObjTilePoolStateRefcountOffsetCheck[offsetof(ObjTilePoolState, reference_count) == OBJ_TILE_POOL_REFCOUNT_OFFSET ? 1 : -1];
typedef char ObjTilePoolStateReservedOffsetCheck[offsetof(ObjTilePoolState, reserved_first) == OBJ_TILE_POOL_RESERVED_FIRST_OFFSET ? 1 : -1];
typedef char ObjTilePoolStateSizeCheck[sizeof(ObjTilePoolState) == OBJ_TILE_POOL_BYTES ? 1 : -1];

typedef char ObjTilePoolEntriesOffsetCheck[(offsetof(ObjTilePoolState, pool) + offsetof(ObjTileHandlePool, entries)) == OBJ_TILE_POOL_ENTRIES_OFFSET ? 1 : -1];
typedef char ObjTilePoolReservedCountOffsetCheck[offsetof(ObjTilePoolState, reserved_count) == OBJ_TILE_POOL_RESERVED_COUNT_OFFSET ? 1 : -1];
typedef char ObjTileAddressBitsCheck[(1 << OBJ_TILE_INDEX_BITS) == TOTAL_OBJ_TILE_COUNT ? 1 : -1];

EXTERN_C

u16 GetAllocatedObjTileHandleCount(void) SECTION(".text.obj_tile_tree_root");
u32 GetObjTileHandleCapacity(void) SECTION(".text.obj_tile_tree_root");

extern ObjTilePoolState * gObjTilePool;

// The default constructor remains in assembly. Raw-storage initialization
// sites use the same entry without invoking an enclosing C++ constructor.
void * InitializeObjTilePoolOwner(void * owner);

// Allocate a 2^size_shift tile range and a generation-checked slot handle.
// A failed slot allocation returns the tile range and yields the zero handle.
u32 AllocateObjTileHandle(void * owner, u32 size_shift);

// Returns the same validated handle; overflow restores the count and returns 0.
u32 RetainObjTileHandle(void * owner, u32 handle);
// The last reference frees the tile range and returns the slot to its free list.
void ReleaseObjTileHandle(void * owner, u32 handle);

// Fill both children before marking the parent tile range full.
void FillObjTileTree64(ObjTileTree64 * tree);
void FillObjTileTree128(ObjTileTree128 * tree);
void FillObjTileTree256(ObjTileTree256 * tree);
void FillObjTileTree512(ObjTileTree512 * tree);

// Clear both children before marking the parent tile range empty.
void ClearObjTileTree64(ObjTileTree64 * tree);
void ClearObjTileTree128(ObjTileTree128 * tree);
void ClearObjTileTree256(ObjTileTree256 * tree);
void ClearObjTileTree512(ObjTileTree512 * tree);

// count must be positive; each eight-byte entry links to the following entry.
ObjTilePoolEntry * InitializeObjTileFreeList(
    ObjTilePoolEntry * entries, i32 count, ObjTilePoolEntry * tail);

// The receiver is unused; each query validates a handle in the shared pool.
u32 GetObjTileIndex(void const * owner, u32 handle);
u32 GetObjTileSizeShift(void * owner, u32 handle);
u32 GetObjTileHandleReferenceCount(void * owner, u32 handle);

EXTERN_C_END

#endif // !__ASSEMBLER__

#endif // OBJ_TILE_POOL_HH
