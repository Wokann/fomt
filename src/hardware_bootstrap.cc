#include "hardware_bootstrap.hh"
#include "hardware_nested_accessors.hh"

EXTERN_C
extern void * vtable_unk_080E5B00[];
extern void * vtable_unk_080E5AF0[];
extern void func_08008A68(void * object, u32 flags);
extern void func_08008AF0(void * object);
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

void func_08008724(struct HardwareBootstrap * owner)
{
    struct HardwareCoreState * state = owner->state;
    struct HardwareDisplayCommand command;
    u16 * control = (u16 *)&state->display.control;
    u32 zero = 0;
    *control |= 0x80;
    command.previous_slot = (void *)zero;
    command.next = (void *)zero;
    command.vtable = vtable_unk_080E5AF0;
    command.display = &state->display;

    void * manager = &state->manager;
    void * object = func_08008AE0((void * const *)manager);
    void ** vtable = *(void ***)((u8 *)object + 8);
    ((void (*)(void *, struct HardwareDisplayCommand *))vtable[4])(object, &command);
    func_08008AF0(manager);
    func_080098AC(&command, 2);
}

void func_08008774(struct HardwareBootstrap * owner)
{
    struct HardwareCoreState * state = owner->state;
    struct HardwareDisplayCommand command;
    u16 * control = (u16 *)&state->display.control;
    u32 zero = 0;
    *control &= 0xFF7F;
    command.previous_slot = (void *)zero;
    command.next = (void *)zero;
    command.vtable = vtable_unk_080E5AF0;
    command.display = &state->display;

    void * manager = &state->manager;
    void * object = func_08008AE0((void * const *)manager);
    void ** vtable = *(void ***)((u8 *)object + 8);
    ((void (*)(void *, struct HardwareDisplayCommand *))vtable[4])(object, &command);
    func_08008AF0(manager);
    func_080098AC(&command, 2);
}
