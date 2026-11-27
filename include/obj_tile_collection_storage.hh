#ifndef OBJ_TILE_COLLECTION_STORAGE_HH
#define OBJ_TILE_COLLECTION_STORAGE_HH

// Native software size classes (size_shift 0..7), not a hardware maximum.
#define OBJ_TILE_COLLECTION_GROUP_COUNT 8

// The retained initializer shares these member offsets with C++.
// Entries also occupy this eight-byte layout in its temporary stack slot.
#define OBJ_TILE_COLLECTION_ENTRY_SHIFT 3
#define OBJ_TILE_COLLECTION_ENTRY_BYTES (1 << OBJ_TILE_COLLECTION_ENTRY_SHIFT)
#define OBJ_TILE_COLLECTION_HANDLE_OFFSET 4
#define OBJ_TILE_COLLECTION_GROUP_END_OFFSET 4
#define OBJ_TILE_COLLECTION_GROUP_UNKNOWN_OFFSET 8
#define OBJ_TILE_COLLECTION_GROUP_UNKNOWN_BYTES 4
#define OBJ_TILE_COLLECTION_GROUP_CAPACITY_OFFSET (OBJ_TILE_COLLECTION_GROUP_UNKNOWN_OFFSET + OBJ_TILE_COLLECTION_GROUP_UNKNOWN_BYTES)
#define OBJ_TILE_COLLECTION_GROUP_CURSOR_OFFSET (OBJ_TILE_COLLECTION_GROUP_CAPACITY_OFFSET + 4)
#define OBJ_TILE_COLLECTION_GROUP_BYTES (OBJ_TILE_COLLECTION_GROUP_CURSOR_OFFSET + 4)
#define OBJ_TILE_COLLECTION_STORAGE_BYTES (OBJ_TILE_COLLECTION_GROUP_COUNT * OBJ_TILE_COLLECTION_GROUP_BYTES)

#ifndef __ASSEMBLER__

#include "prelude.h"
#include "obj_tile_pool.hh"

struct ObjTileCollectionEntry {
    struct ObjTilePoolOwner owner;
    u32 handle;
#ifdef __cplusplus
    ObjTileCollectionEntry()
    {
        handle = 0;
    }

    ObjTileCollectionEntry & operator=(ObjTileCollectionEntry const & value)
    {
        if (&value != this)
        {
            ReleaseObjTileHandle(this, handle);
            handle = RetainObjTileHandle(this, value.handle);
        }
        return *this;
    }

    ObjTileCollectionEntry(u32 size_shift)
    {
        handle = AllocateObjTileHandle(this, size_shift);
    }

    ObjTileCollectionEntry(ObjTileCollectionEntry const & value)
    {
        handle = RetainObjTileHandle(this, value.handle);
    }

    void Clear()
    {
        ReleaseObjTileHandle(this, handle);
        handle = 0;
    }

    void Reset(u32 size_shift)
    {
        ReleaseObjTileHandle(this, handle);
        handle = AllocateObjTileHandle(this, size_shift);
    }

    u32 GetTileIndex() const
    { return GetObjTileIndex(this, handle); }

    ~ObjTileCollectionEntry()
    {
        ReleaseObjTileHandle(this, handle);
    }
#endif
};

struct ObjTileCollectionGroup {
    struct ObjTileCollectionEntry * start;
    struct ObjTileCollectionEntry * end;
    u8 unk_08[OBJ_TILE_COLLECTION_GROUP_UNKNOWN_BYTES];
    struct ObjTileCollectionEntry * capacity_end;
    struct ObjTileCollectionEntry * cursor;
#ifdef __cplusplus
    // Native initialization reserves before setting cursor; this method does
    // not relocate a cursor that already points into an existing buffer.
    void Reserve(u32 count);

private:
    static void * AllocateBytes(u32 bytes);
    ObjTileCollectionEntry * Allocate(u32 count);
    ObjTileCollectionEntry * AllocateAndCopy(u32 count,
        ObjTileCollectionEntry * first, ObjTileCollectionEntry * last);
#endif
};

struct ObjTileCollectionStorage {
    struct ObjTileCollectionGroup groups[OBJ_TILE_COLLECTION_GROUP_COUNT];
};

#endif // !__ASSEMBLER__

#endif // OBJ_TILE_COLLECTION_STORAGE_HH
