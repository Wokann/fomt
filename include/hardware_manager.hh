#ifndef HARDWARE_MANAGER_HH
#define HARDWARE_MANAGER_HH

#include "prelude.h"

// The constructor allocates 0x6C bytes.  The nested objects at +0x0C,
// +0x28, +0x34 and +0x50 still need their full types established.
struct HardwareManagerState {
    u8 unk_00[0x68];
    u8 unk_68;
    u8 unk_69[3];
};

typedef char HardwareManagerState_size_check[sizeof(struct HardwareManagerState) == 0x6C ? 1 : -1];

struct HardwareManagerOwner {
    struct HardwareManagerState * state;
#ifdef __cplusplus
    HardwareManagerOwner() asm("func_08008980");
#endif
};

EXTERN_C

struct HardwareManagerOwner * func_08008980(struct HardwareManagerOwner * owner);
void func_08008A68(struct HardwareManagerOwner * owner, u32 flags);

EXTERN_C_END

#endif // HARDWARE_MANAGER_HH
