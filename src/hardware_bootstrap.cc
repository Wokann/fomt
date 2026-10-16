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

HardwareBootstrap::HardwareBootstrap()
{
    this->vtable = vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, 0, 0x20);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::HardwareBootstrap(HardwareInputRepeatParameters const & input)
{
    this->vtable = vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, 0, 0x20);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::HardwareBootstrap(HardwareSpriteBufferParameters const & buffer)
{
    this->vtable = vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, buffer);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::HardwareBootstrap(HardwareInputRepeatParameters const & input,
    HardwareSpriteBufferParameters const & buffer)
{
    this->vtable = vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, buffer);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::~HardwareBootstrap()
{
    struct HardwareCoreState * state;
    this->vtable = vtable_unk_080E5B00;
    if (this->state != 0) {
        state = this->state;
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
}

void func_08008724(struct HardwareBootstrap * owner)
{
    struct HardwareCoreState * state = owner->state;
    u16 * control = (u16 *)&state->display.control;
    HardwareDisplayCommand command;
    u32 zero = 0;
    *control |= 0x80;
    command.previous_slot = (HardwareLink **)zero;
    command.next = (HardwareLink *)zero;
    command.vtable = (void **)&gHardwareDisplayCommandVTable;
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
    u16 * control = (u16 *)&state->display.control;
    HardwareDisplayCommand command;
    u32 zero = 0;
    *control &= 0xFF7F;
    command.previous_slot = (HardwareLink **)zero;
    command.next = (HardwareLink *)zero;
    command.vtable = (void **)&gHardwareDisplayCommandVTable;
    command.display = &state->display;

    void * manager = &state->manager;
    void * object = func_08008AE0((void * const *)manager);
    void ** vtable = *(void ***)((u8 *)object + 8);
    ((void (*)(void *, struct HardwareDisplayCommand *))vtable[4])(object, &command);
    func_08008AF0(manager);
    func_080098AC(&command, 2);
}

void UpdateHardwareFrame(struct HardwareBootstrap * owner)
{
    struct HardwareCoreState * state = owner->state;
    HardwareDisplayCommand display(&state->display);
    HardwareSpriteBufferCommand sprite(&state->sprite_buffer);
    HardwareDmaQueueCommand dma(&state->dma_queue);
    HardwareLinkedList commands;

    func_08009940(&commands, reinterpret_cast<HardwareLink *>(&state->links));
    func_08009940(&commands, reinterpret_cast<HardwareLink *>(&display));
    func_08009940(&commands, reinterpret_cast<HardwareLink *>(&dma));
    func_08009940(&commands, reinterpret_cast<HardwareLink *>(&sprite));

    void * manager = &state->manager;
    void * object = func_08008AE0(reinterpret_cast<void * const *>(manager));
    void ** vtable = *reinterpret_cast<void ***>((u8 *)object + 8);
    ((void (*)(void *, HardwareLinkedList *))vtable[4])(object, &commands);
    func_08008AF0(manager);
    object = func_08008AE0(reinterpret_cast<void * const *>(manager));
    vtable = *reinterpret_cast<void ***>((u8 *)object + 8);
    ((void (*)(void *, HardwareLinkedList *))vtable[5])(object, &commands);

    func_080098DC(&commands, 2);
    func_080098AC(&dma, 2);
    func_080098AC(&sprite, 2);
    func_080098AC(&display, 2);
}

u32 RunHardwareDisplayCommand(struct HardwareDisplayCommand * command)
{
    WriteHardwareDisplayState(command->display);
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
