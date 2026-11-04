#ifndef OBJ_PALETTE_COLLECTION_HH
#define OBJ_PALETTE_COLLECTION_HH

#include "prelude.h"
#include "obj_palette_pool.hh"

struct ObjPaletteCollectionEntry {
    ObjPalettePoolOwner owner;
    u32 handle;

    ObjPaletteCollectionEntry()
    {
        handle = AllocateObjPaletteHandle(this);
    }

    ObjPaletteCollectionEntry(ObjPaletteCollectionEntry const & value)
    {
        handle = RetainObjPaletteHandle(this, value.handle);
    }

    u32 GetIndex()
    {
        return GetObjPaletteBank(this, handle);
    }

    ~ObjPaletteCollectionEntry()
    {
        ReleaseObjPaletteHandle(this, handle);
    }
};

// Neither native default nor copy construction writes these bytes.
// Keep their meaning unknown rather than inventing allocator state.
struct ObjPaletteCollectionStoragePrefix {
    u8 unk_00[4];
    ObjPaletteCollectionStoragePrefix() {}
    ObjPaletteCollectionStoragePrefix(ObjPaletteCollectionStoragePrefix const &) {}
};

struct ObjPaletteCollectionStorageBounds {
    ObjPaletteCollectionStoragePrefix prefix;
    ObjPaletteCollectionEntry * end;
    ObjPaletteCollectionStorageBounds(ObjPaletteCollectionStoragePrefix const & prefix)
        : prefix(prefix), end(0) {}
};

struct ObjPaletteCollectionStorage {
    explicit ObjPaletteCollectionStorage(u8 const & count, ObjPaletteCollectionStoragePrefix const & prefix = ObjPaletteCollectionStoragePrefix());
    ~ObjPaletteCollectionStorage();
    struct ObjPaletteCollectionEntry * start;
    struct ObjPaletteCollectionEntry * end;
    ObjPaletteCollectionStorageBounds allocation;
    struct ObjPaletteCollectionEntry * cursor;

    // Reserve is used before population; it does not retarget an existing cursor.
    void Reserve(u32 count);

private:
    ObjPaletteCollectionEntry * CopyEntries(ObjPaletteCollectionEntry const * first,
        ObjPaletteCollectionEntry const * last, ObjPaletteCollectionEntry * result);
    ObjPaletteCollectionEntry * FillEntries(ObjPaletteCollectionEntry * first,
        u32 count, ObjPaletteCollectionEntry const & value);
    void Grow(ObjPaletteCollectionEntry * old_end, u32 count, ObjPaletteCollectionEntry const & value);
    void PushBack(ObjPaletteCollectionEntry const & value);
    static void * AllocateBytes(u32 bytes);
    ObjPaletteCollectionEntry * Allocate(u32 count);
    ObjPaletteCollectionEntry * AllocateAndCopy(u32 count,
        ObjPaletteCollectionEntry * first, ObjPaletteCollectionEntry * last);
};

typedef char ObjPaletteCollectionStoragePrefixSizeCheck[sizeof(ObjPaletteCollectionStoragePrefix) == 4 ? 1 : -1];
typedef char ObjPaletteCollectionStorageBoundsSizeCheck[sizeof(ObjPaletteCollectionStorageBounds) == 8 ? 1 : -1];
typedef char ObjPaletteCollectionStorageBoundsEndCheck[offsetof(ObjPaletteCollectionStorageBounds, end) == 4 ? 1 : -1];
typedef char ObjPaletteCollectionEntrySizeCheck[sizeof(ObjPaletteCollectionEntry) == 8 ? 1 : -1];
typedef char ObjPaletteCollectionEntryHandleCheck[offsetof(ObjPaletteCollectionEntry, handle) == 4 ? 1 : -1];
typedef char ObjPaletteCollectionStorageSizeCheck[sizeof(ObjPaletteCollectionStorage) == 20 ? 1 : -1];
typedef char ObjPaletteCollectionStorageCapacityCheck[(offsetof(ObjPaletteCollectionStorage, allocation) + offsetof(ObjPaletteCollectionStorageBounds, end)) == 12 ? 1 : -1];
typedef char ObjPaletteCollectionStorageCursorCheck[offsetof(ObjPaletteCollectionStorage, cursor) == 16 ? 1 : -1];

struct ObjPaletteCollection {
    struct ObjPaletteCollectionStorage * storage;

    explicit ObjPaletteCollection(u8 const & count);
    ObjPaletteCollection();
    ~ObjPaletteCollection();
    // Reuse an entry held only by this collection, retaining it for the caller.
    // If all entries are busy, retain the original cursor entry instead.
    // No storage allocates a fresh entry; allocated storage must not be empty.
    ObjPaletteCollectionEntry Get() const;
};

typedef char ObjPaletteCollectionSizeCheck[sizeof(ObjPaletteCollection) == 4 ? 1 : -1];

#endif // OBJ_PALETTE_COLLECTION_HH
