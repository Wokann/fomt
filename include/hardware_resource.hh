#ifndef HARDWARE_RESOURCE_HH
#define HARDWARE_RESOURCE_HH

#include "prelude.h"
#include "obj_palette_pool.hh"

struct HardwareResourceEntry {
    ObjPalettePoolOwner owner;
    u32 handle;

    HardwareResourceEntry()
    {
        handle = AllocateObjPaletteHandle(this);
    }

    HardwareResourceEntry(HardwareResourceEntry const & value)
    {
        handle = RetainObjPaletteHandle(this, value.handle);
    }

    u32 GetIndex()
    {
        return GetObjPaletteBank(this, handle);
    }

    ~HardwareResourceEntry()
    {
        ReleaseObjPaletteHandle(this, handle);
    }
};

// Neither native default nor copy construction writes these bytes.
// Keep their meaning unknown rather than inventing allocator state.
struct HardwareResourceStoragePrefix {
    u8 unk_00[4];
    HardwareResourceStoragePrefix() {}
    HardwareResourceStoragePrefix(HardwareResourceStoragePrefix const &) {}
};

struct HardwareResourceStorageBounds {
    HardwareResourceStoragePrefix prefix;
    HardwareResourceEntry * end;
    HardwareResourceStorageBounds(HardwareResourceStoragePrefix const & prefix)
        : prefix(prefix), end(0) {}
};

struct HardwareResourceStorage {
    explicit HardwareResourceStorage(u8 const & count, HardwareResourceStoragePrefix const & prefix = HardwareResourceStoragePrefix());
    ~HardwareResourceStorage();
    struct HardwareResourceEntry * start;
    struct HardwareResourceEntry * end;
    HardwareResourceStorageBounds allocation;
    struct HardwareResourceEntry * cursor;

    void Reserve(u32 count);

private:
    HardwareResourceEntry * CopyEntries(HardwareResourceEntry const * first,
        HardwareResourceEntry const * last, HardwareResourceEntry * result);
    HardwareResourceEntry * FillEntries(HardwareResourceEntry * first,
        u32 count, HardwareResourceEntry const & value);
    void Grow(HardwareResourceEntry * old_end, u32 count, HardwareResourceEntry const & value);
    void PushBack(HardwareResourceEntry const & value);
    static void * AllocateBytes(u32 bytes);
    HardwareResourceEntry * Allocate(u32 count);
    HardwareResourceEntry * AllocateAndCopy(u32 count,
        HardwareResourceEntry * first, HardwareResourceEntry * last);
};

typedef char HardwareResourceStoragePrefixSizeCheck[sizeof(HardwareResourceStoragePrefix) == 4 ? 1 : -1];
typedef char HardwareResourceStorageBoundsSizeCheck[sizeof(HardwareResourceStorageBounds) == 8 ? 1 : -1];
typedef char HardwareResourceStorageBoundsEndCheck[offsetof(HardwareResourceStorageBounds, end) == 4 ? 1 : -1];
typedef char HardwareResourceEntrySizeCheck[sizeof(HardwareResourceEntry) == 8 ? 1 : -1];
typedef char HardwareResourceEntryHandleCheck[offsetof(HardwareResourceEntry, handle) == 4 ? 1 : -1];
typedef char HardwareResourceStorageSizeCheck[sizeof(HardwareResourceStorage) == 20 ? 1 : -1];
typedef char HardwareResourceStorageCapacityCheck[(offsetof(HardwareResourceStorage, allocation) + offsetof(HardwareResourceStorageBounds, end)) == 12 ? 1 : -1];
typedef char HardwareResourceStorageCursorCheck[offsetof(HardwareResourceStorage, cursor) == 16 ? 1 : -1];

struct HardwareResource {
    struct HardwareResourceStorage * storage;

    explicit HardwareResource(u8 const & count);
    HardwareResource();
    ~HardwareResource();
    // Copy a retained pool entry, or allocate one when storage is absent.
    HardwareResourceEntry Get() const;
};

typedef char HardwareResourceSizeCheck[sizeof(HardwareResource) == 4 ? 1 : -1];

#endif // HARDWARE_RESOURCE_HH
