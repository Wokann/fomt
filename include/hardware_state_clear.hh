#ifndef HARDWARE_STATE_CLEAR_HH
#define HARDWARE_STATE_CLEAR_HH

#include "prelude.h"
#include "hardware_refcount.hh"

struct HardwareStateEntry {
    struct HardwareSharedStateOwner owner;
    u32 handle;
#ifdef __cplusplus
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
    u32 unk_04;
};

typedef char HardwareStateEntrySizeCheck[sizeof(struct HardwareStateEntry) == 8 ? 1 : -1];
typedef char HardwareStateEntryHandleCheck[offsetof(struct HardwareStateEntry, handle) == 4 ? 1 : -1];
typedef char HardwareStateGroupSizeCheck[sizeof(struct HardwareStateGroup) == 20 ? 1 : -1];
typedef char HardwareStateGroupCapacityCheck[offsetof(struct HardwareStateGroup, capacity_end) == 12 ? 1 : -1];
typedef char HardwareStateGroupCursorCheck[offsetof(struct HardwareStateGroup, cursor) == 16 ? 1 : -1];
typedef char HardwareStateStorageSizeCheck[sizeof(struct HardwareStateStorage) == 160 ? 1 : -1];

EXTERN_C

void func_0800835C(void ** slot);
void func_08008364(struct HardwareStateOwner * owner, u32 flags);
struct HardwareStateOwner * func_080083D0(
    struct HardwareStateOwner * owner,
    struct HardwareStateStorage * const * storage_ref,
    u32 group_index);

EXTERN_C_END

#endif // HARDWARE_STATE_CLEAR_HH
