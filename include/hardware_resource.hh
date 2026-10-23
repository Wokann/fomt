#ifndef HARDWARE_RESOURCE_HH
#define HARDWARE_RESOURCE_HH

#include "prelude.h"
#include "hardware_allocator.hh"

struct HardwareResourceEntry {
    HardwarePoolOwner owner;
    u32 handle;

    HardwareResourceEntry()
    {
        handle = AllocateHardwarePoolHandle(this);
    }

    HardwareResourceEntry(HardwareResourceEntry const & value)
    {
        handle = RetainHardwarePoolHandle(this, value.handle);
    }

    ~HardwareResourceEntry()
    {
        ReleaseHardwarePoolHandle(this, handle);
    }
};

struct HardwareResourceStorage {
    struct HardwareResourceEntry * start;
    struct HardwareResourceEntry * end;
    u8 unk_08[4];
    struct HardwareResourceEntry * capacity_end;
    struct HardwareResourceEntry * cursor;

    void Reserve(u32 count) SECTION(".text.code_080D6DB8");

private:
    static void * AllocateBytes(u32 bytes);
    HardwareResourceEntry * Allocate(u32 count);
    HardwareResourceEntry * AllocateAndCopy(u32 count,
        HardwareResourceEntry * first, HardwareResourceEntry * last);
};

typedef char HardwareResourceEntrySizeCheck[sizeof(HardwareResourceEntry) == 8 ? 1 : -1];
typedef char HardwareResourceEntryHandleCheck[offsetof(HardwareResourceEntry, handle) == 4 ? 1 : -1];
typedef char HardwareResourceStorageSizeCheck[sizeof(HardwareResourceStorage) == 20 ? 1 : -1];
typedef char HardwareResourceStorageCapacityCheck[offsetof(HardwareResourceStorage, capacity_end) == 12 ? 1 : -1];
typedef char HardwareResourceStorageCursorCheck[offsetof(HardwareResourceStorage, cursor) == 16 ? 1 : -1];

struct HardwareResource {
    struct HardwareResourceStorage * storage;

    HardwareResource();
    ~HardwareResource();
    // Copy a retained pool entry, or allocate one when storage is absent.
    HardwareResourceEntry Get() const;
};

typedef char HardwareResourceSizeCheck[sizeof(HardwareResource) == 4 ? 1 : -1];

#endif // HARDWARE_RESOURCE_HH
