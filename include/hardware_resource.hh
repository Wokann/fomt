#ifndef HARDWARE_RESOURCE_HH
#define HARDWARE_RESOURCE_HH

#include "prelude.h"

struct HardwareResourceEntry {
    u32 unk_00;
    u32 handle;
};

struct HardwareResourceStorage {
    struct HardwareResourceEntry * start;
    struct HardwareResourceEntry * end;
    u8 unk_08[8];
    struct HardwareResourceEntry * cursor;
};

struct HardwareResource {
    struct HardwareResourceStorage * storage;
    u32 handle;
};

EXTERN_C

void func_0800770C(struct HardwareResource * object);
void func_08007714(struct HardwareResource * object, u32 flags);

EXTERN_C_END

#endif // HARDWARE_RESOURCE_HH
