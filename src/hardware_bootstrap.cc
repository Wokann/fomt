#include "hardware_bootstrap.hh"

EXTERN_C
extern void * vtable_unk_080E5B00[];
extern void func_08008A68(void * object, u32 flags);
extern void __builtin_delete(void * pointer);
extern void free(void * pointer);
EXTERN_C_END

void func_080086BC(struct HardwareBootstrap * owner, u32 flags)
{
    struct HardwareCoreState * state;
    owner->vtable = vtable_unk_080E5B00;
    if (owner->state != 0) {
        state = owner->state;
        u32 * buffer;
        u32 current;
        u32 end;
        func_080098DC(&state->links, 2);
        func_08008A68(&state->manager, 2);
        buffer = &state->unk_24;
        end = buffer[1];
        current = buffer[0];
        while (current != end)
            current += 0x10;
        if (buffer[0] != 0)
            free((void *)buffer[0]);
        __builtin_delete(state);
    }
    if (flags & 1)
        __builtin_delete(owner);
}
