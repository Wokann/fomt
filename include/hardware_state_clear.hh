#ifndef HARDWARE_STATE_CLEAR_HH
#define HARDWARE_STATE_CLEAR_HH

#include "prelude.h"
#include "hardware_refcount.hh"

struct HardwareStateEntry {
    struct HardwareSharedStateOwner owner;
    u32 handle;
#ifdef __cplusplus
    HardwareStateEntry()
    {
        func_08007874(this);
        handle = 0;
    }

    HardwareStateEntry & operator=(HardwareStateEntry const & value)
    {
        if (&value != this)
        {
            ReleaseHardwareSharedStateHandle(this, handle);
            handle = RetainHardwareSharedStateHandle(this, value.handle);
        }
        return *this;
    }

    HardwareStateEntry(u32 size_shift)
    {
        func_08007874(this);
        handle = AllocateHardwareSharedStateHandle(this, size_shift);
    }

    HardwareStateEntry(HardwareStateEntry const & value)
    {
        func_08007874(this);
        handle = RetainHardwareSharedStateHandle(this, value.handle);
    }

    ~HardwareStateEntry()
    {
        ReleaseHardwareSharedStateHandle(this, handle);
        func_080079E8(this, 2);
    }
#endif
};

struct HardwareStateGroup {
    struct HardwareStateEntry * start;
    struct HardwareStateEntry * end;
    u8 unk_08[4];
    struct HardwareStateEntry * capacity_end;
    struct HardwareStateEntry * cursor;
#ifdef __cplusplus
    void Reserve(u32 count) SECTION(".text.hardware_shared_state_free_list_after");

private:
    static void * AllocateBytes(u32 bytes);
    HardwareStateEntry * Allocate(u32 count);
    HardwareStateEntry * AllocateAndCopy(u32 count,
        HardwareStateEntry * first, HardwareStateEntry * last);
#endif
};

struct HardwareStateStorage {
    struct HardwareStateGroup groups[8];
};

struct HardwareStateOwner {
    struct HardwareStateStorage * storage;
#ifdef __cplusplus
    HardwareStateOwner();
    ~HardwareStateOwner();
    // Return a retained entry, not another owner. Without storage, allocate
    // an independent entry with group_index as the tile-size shift.
    HardwareStateEntry Get(u32 group_index) const;
#endif
};

typedef char HardwareStateEntrySizeCheck[sizeof(struct HardwareStateEntry) == 8 ? 1 : -1];
typedef char HardwareStateEntryHandleCheck[offsetof(struct HardwareStateEntry, handle) == 4 ? 1 : -1];
typedef char HardwareStateGroupSizeCheck[sizeof(struct HardwareStateGroup) == 20 ? 1 : -1];
typedef char HardwareStateGroupCapacityCheck[offsetof(struct HardwareStateGroup, capacity_end) == 12 ? 1 : -1];
typedef char HardwareStateGroupCursorCheck[offsetof(struct HardwareStateGroup, cursor) == 16 ? 1 : -1];
typedef char HardwareStateStorageSizeCheck[sizeof(struct HardwareStateStorage) == 160 ? 1 : -1];
typedef char HardwareStateOwnerSizeCheck[sizeof(struct HardwareStateOwner) == 4 ? 1 : -1];

#endif // HARDWARE_STATE_CLEAR_HH
