#ifndef OBJ_TILE_COLLECTION_HH
#define OBJ_TILE_COLLECTION_HH

#include "obj_tile_collection_storage.hh"

#ifndef __ASSEMBLER__

struct ObjTileCollection {
    struct ObjTileCollectionStorage * storage;
#ifdef __cplusplus
    ObjTileCollection();
    // counts contains GROUP_COUNT per-size-class reservation counts.
    explicit ObjTileCollection(u8 const * counts) asm("InitializeObjTileCollectionGroups");
    ~ObjTileCollection();
    // Return a retained entry, not another owner. Without storage, allocate
    // an independent entry with group_index as the tile-size shift.
    // Stored groups must be nonempty. If every entry is retained elsewhere,
    // the native loop returns the original cursor entry rather than failing.
    ObjTileCollectionEntry Get(u32 group_index) const;
private:
    // The collection owns its storage; callers retain entries through Get().
    ObjTileCollection(ObjTileCollection const &);
    ObjTileCollection & operator=(ObjTileCollection const &);
#endif
};

typedef char ObjTileCollectionSizeCheck[sizeof(struct ObjTileCollection) == 4 ? 1 : -1];

#endif // !__ASSEMBLER__

#endif // OBJ_TILE_COLLECTION_HH
