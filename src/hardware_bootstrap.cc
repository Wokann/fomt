#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_nested_accessors.hh"
#include "hardware_oam_state.hh"
#include "gbaio.h"
#include <new>

EXTERN_C
extern void * vtable_unk_080E5B00[];
extern void func_08008AF0(void * object);
extern void __builtin_delete(void * pointer);
extern void free(void * pointer);
EXTERN_C_END

struct HardwareBootstrap * func_08008444(struct HardwareBootstrap * owner)
{
    owner->vtable = vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, 0, 0x20);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    owner->state = state;
    return owner;
}

struct HardwareBootstrap * func_080084DC(struct HardwareBootstrap * owner, struct HardwareInputRepeatParameters const * input)
{
    owner->vtable = vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(input->delay, input->interval, 0, 0x20);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    owner->state = state;
    return owner;
}

struct HardwareBootstrap * func_08008574(struct HardwareBootstrap * owner, struct HardwareSpriteBufferParameters const * buffer)
{
    owner->vtable = vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, *buffer);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    owner->state = state;
    return owner;
}

struct HardwareBootstrap * func_08008618(struct HardwareBootstrap * owner, struct HardwareInputRepeatParameters const * input, struct HardwareSpriteBufferParameters const * buffer)
{
    owner->vtable = vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(input->delay, input->interval, *buffer);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    owner->state = state;
    return owner;
}

void func_080086BC(struct HardwareBootstrap * owner, u32 flags)
{
    struct HardwareCoreState * state;
    owner->vtable = vtable_unk_080E5B00;
    if (owner->state != 0) {
        state = owner->state;
        struct HardwareDmaQueue * queue;
        struct DmaTransferDescriptor * current;
        struct DmaTransferDescriptor * end;
        func_080098DC(&state->links, 2);
        func_08008A68(&state->manager, 2);
        queue = &state->dma_queue;
        end = queue->last;
        current = queue->first;
        while (current != end)
            current++;
        if (queue->first != nullptr)
            free(queue->first);
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
    command.previous_slot = (HardwareLink **)zero;
    command.next = (HardwareLink *)zero;
    command.vtable = &gHardwareDisplayCommandVTable;
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
    command.previous_slot = (HardwareLink **)zero;
    command.next = (HardwareLink *)zero;
    command.vtable = &gHardwareDisplayCommandVTable;
    command.display = &state->display;

    void * manager = &state->manager;
    void * object = func_08008AE0((void * const *)manager);
    void ** vtable = *(void ***)((u8 *)object + 8);
    ((void (*)(void *, struct HardwareDisplayCommand *))vtable[4])(object, &command);
    func_08008AF0(manager);
    func_080098AC(&command, 2);
}

u32 RunHardwareDisplayCommand(struct HardwareDisplayCommand * command)
{
    func_080096F0(command->display);
    return 0;
}

u32 RunHardwareSpriteBufferCommand(struct HardwareSpriteBufferCommand * command)
{
    func_08009864(command->buffer);
    return 0;
}

void DestroyHardwareDmaQueueCommand(struct HardwareDmaQueueCommand * command, u32 flags)
{
    func_080098AC(command, flags);
}

void DestroyHardwareSpriteBufferCommand(struct HardwareSpriteBufferCommand * command, u32 flags)
{
    func_080098AC(command, flags);
}

void DestroyHardwareDisplayCommand(struct HardwareDisplayCommand * command, u32 flags)
{
    func_080098AC(command, flags);
}
