#ifndef HARDWARE_STATE_CLEAR_HH
#define HARDWARE_STATE_CLEAR_HH

#include "prelude.h"

struct HardwareStateEntry {
    void * unk_00;
    void * unk_04;
};

struct HardwareStateGroup {
    struct HardwareStateEntry * start;
    struct HardwareStateEntry * end;
    u8 unk_08[8];
    struct HardwareStateEntry * cursor;
};

struct HardwareStateStorage {
    struct HardwareStateGroup groups[8];
};

struct HardwareStateOwner {
    struct HardwareStateStorage * storage;
    u32 unk_04;
};

EXTERN_C

void func_0800835C(void ** slot);
void func_08008364(struct HardwareStateOwner * owner, u32 flags);
struct HardwareStateOwner * func_080083D0(
    struct HardwareStateOwner * owner,
    struct HardwareStateStorage * const * storage_ref,
    u32 group_index);

EXTERN_C_END

#endif // HARDWARE_STATE_CLEAR_HH
