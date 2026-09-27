#include "hardware_manager.hh"
#include "hardware_interrupt_guard.hh"
#include "hardware_song.hh"
#include "hardware_linked_list.hh"

EXTERN_C
extern void * vtable_unk_080E5B0C[];
extern void * vtable_unk_080E5B18[];
extern void func_080D7944(void * object, u32 flags);
extern void __builtin_delete(void * object);
EXTERN_C_END

void func_08008A68(struct HardwareManagerOwner * owner, u32 flags)
{
    u8 * state = (u8 *)owner->state;
    if (state != 0) {
        if (state[0x68] != 0)
            func_08008D90();

        u8 * secondary = state + 0x34;
        *(void **)(secondary + 0x30) = vtable_unk_080E5B0C;
        *(void **)(secondary + 8) = vtable_unk_080E5B18;
        func_080D7944(state + 0x50, 0);
        func_0800959C((struct HardwareBlendObject *)secondary, 2);
        func_080098AC(state + 0x28, 2);
        func_0800959C((struct HardwareBlendObject *)(state + 0x0C), 2);
        func_080098AC(state, 2);
        __builtin_delete(state);
    }
    if (flags & 1)
        __builtin_delete(owner);
}
