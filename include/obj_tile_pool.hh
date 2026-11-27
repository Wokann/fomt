#ifndef OBJ_TILE_POOL_HH
#define OBJ_TILE_POOL_HH

#include "obj_tile_pool_storage.hh"

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

typedef struct ObjTileTree1024 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileTree512 children[2];
#ifdef __cplusplus
    ObjTileTree1024();
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



EXTERN_C

u16 GetAllocatedObjTileHandleCount(void);
u32 GetObjTileHandleCapacity(void);

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



// The receiver is unused; each query validates a handle in the shared pool.
u32 GetObjTileIndex(void const * owner, u32 handle);
u32 GetObjTileSizeShift(void * owner, u32 handle);
u32 GetObjTileHandleReferenceCount(void * owner, u32 handle);

EXTERN_C_END

#endif // !__ASSEMBLER__

#endif // OBJ_TILE_POOL_HH
