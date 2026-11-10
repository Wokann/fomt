#ifndef OBJ_TILE_POOL_STORAGE_HH
#define OBJ_TILE_POOL_STORAGE_HH

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

#ifndef __ASSEMBLER__

#include "prelude.h"
#include "obj_tile_bitmap.hh"

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
    u32 Allocate(u32 size_shift);
    void Free(u32 offset, u32 size_shift);
    void Reserve(u32 offset, u32 length);
    void Unreserve(u32 offset, u32 length);
#endif
} ObjTileTree64;

typedef struct ObjTileTree128 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileTree64 children[2];
#ifdef __cplusplus
    ObjTileTree128() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift);
    void Free(u32 offset, u32 size_shift);
    void Reserve(u32 offset, u32 length);
    void Unreserve(u32 offset, u32 length);
#endif
} ObjTileTree128;

typedef struct ObjTileTree256 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileTree128 children[2];
#ifdef __cplusplus
    ObjTileTree256() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift);
    void Free(u32 offset, u32 size_shift);
    void Reserve(u32 offset, u32 length);
    void Unreserve(u32 offset, u32 length);
#endif
} ObjTileTree256;

typedef struct ObjTileTree512 {
    ObjTileTreeFlag full;
    ObjTileTreeFlag empty;
    ObjTileTree256 children[2];
#ifdef __cplusplus
    ObjTileTree512() : full(false), empty(true) {}
    u32 Allocate(u32 size_shift);
    void Free(u32 offset, u32 size_shift);
    void Reserve(u32 offset, u32 length);
    void Unreserve(u32 offset, u32 length);
#endif
} ObjTileTree512;

typedef char ObjTilePoolEntrySizeCheck[sizeof(ObjTilePoolEntry) == OBJ_TILE_POOL_ENTRY_BYTES ? 1 : -1];
typedef char ObjTilePoolEntryRefcountCheck[offsetof(ObjTilePoolEntry, data.params.reference_count) == 2 ? 1 : -1];
typedef char ObjTilePoolEntryGenerationCheck[offsetof(ObjTilePoolEntry, generation) == OBJ_TILE_ENTRY_GENERATION_OFFSET ? 1 : -1];
typedef char ObjTileHandlePoolEntriesCheck[offsetof(ObjTileHandlePool, entries) == 4 ? 1 : -1];
typedef char ObjTileTreeFlagSizeCheck[sizeof(ObjTileTreeFlag) == 1 ? 1 : -1];
typedef char ObjTileTree64SizeCheck[sizeof(ObjTileTree64) == OBJ_TILE_TREE64_BYTES ? 1 : -1];
typedef char ObjTileTree128SizeCheck[sizeof(ObjTileTree128) == OBJ_TILE_TREE128_BYTES ? 1 : -1];
typedef char ObjTileTree256SizeCheck[sizeof(ObjTileTree256) == OBJ_TILE_TREE256_BYTES ? 1 : -1];
typedef char ObjTileTree512SizeCheck[sizeof(ObjTileTree512) == OBJ_TILE_TREE512_BYTES ? 1 : -1];
EXTERN_C

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

EXTERN_C_END

#endif // !__ASSEMBLER__

#endif // OBJ_TILE_POOL_STORAGE_HH
