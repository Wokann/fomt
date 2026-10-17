#include "prelude.h"
#pragma implementation "hardware_bootstrap.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_nested_accessors.hh"
#include "hardware_oam_state.hh"
#include "gbaio.h"

void * operator new(unsigned long);
void operator delete(void *);

EXTERN_C
extern void __builtin_delete(void * pointer);
extern void free(void * pointer);
EXTERN_C_END

HardwareBootstrap::HardwareBootstrap()
{
    this->vtable = (void **)vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, 0, 0x20);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::HardwareBootstrap(HardwareInputRepeatParameters const & input)
{
    this->vtable = (void **)vtable_unk_080E5B00;
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, 0, 0x20);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::HardwareBootstrap(HardwareSpriteBufferParameters const & buffer)
{
    this->vtable = (void **)vtable_unk_080E5B00;
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
    this->vtable = (void **)vtable_unk_080E5B00;
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
    this->vtable = (void **)vtable_unk_080E5B00;
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

void UpdateHardwareFrame(struct HardwareBootstrap * owner)
{
    struct HardwareCoreState * state = owner->state;
    HardwareDisplayCommand display(&state->display);
    HardwareSpriteBufferCommand sprite(&state->sprite_buffer);
    HardwareDmaQueueCommand dma(&state->dma_queue);
    HardwareLinkedList commands;

    func_08009940(&commands, &state->links);
    func_08009940(&commands, &display);
    func_08009940(&commands, &dma);
    func_08009940(&commands, &sprite);

    void * manager = &state->manager;
    void * object = func_08008AE0(reinterpret_cast<void * const *>(manager));
    void ** vtable = *reinterpret_cast<void ***>((u8 *)object + 8);
    ((void (*)(void *, HardwareLinkedList *))vtable[4])(object, &commands);
    func_08008AF0(manager);
    object = func_08008AE0(reinterpret_cast<void * const *>(manager));
    vtable = *reinterpret_cast<void ***>((u8 *)object + 8);
    ((void (*)(void *, HardwareLinkedList *))vtable[5])(object, &commands);

    // The list and commands unlink in reverse construction order at scope exit.
}

bool HardwareDisplayCommand::Run()
{
    WriteHardwareDisplayState(display);
    return 0;
}

bool HardwareSpriteBufferCommand::Run()
{
    func_08009864(buffer);
    return 0;
}

bool HardwareDmaQueueCommand::Run()
{
    HardwareDmaQueue * storage = queue;
    if (!storage->IsEmpty()) {
        func_08008FE4(storage->first, storage->first + storage->Size());
        storage->Clear();
    }
    return 0;
}

// Bootstrap itself is still a partial ABI view, unlike the command classes.
extern HardwareLinkVirtualFunction const vtable_unk_080E5B00[] = {
    nullptr,
    nullptr,
    reinterpret_cast<HardwareLinkVirtualFunction>(func_080086BC),
};
