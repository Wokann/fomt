#include "prelude.h"
#pragma implementation "hardware_context.hh"
#include "hardware_context.hh"
#include "hardware_state_accessors.hh"
#include "hardware_manager.hh"
#include "hardware_sprite_buffer.hh"
#include "gbaio.h"

void * operator new(unsigned long);
void operator delete(void *);

HardwareContext::HardwareContext()
{
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, 0, 0x20);
    u16 status = state->display.status;
    status |= DISPSTAT_VBLANK_INTR;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareContext::HardwareContext(HardwareInputRepeatParameters const & input)
{
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, 0, 0x20);
    u16 status = state->display.status;
    status |= DISPSTAT_VBLANK_INTR;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareContext::HardwareContext(HardwareSpriteBufferParameters const & buffer)
{
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, buffer);
    u16 status = state->display.status;
    status |= DISPSTAT_VBLANK_INTR;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareContext::HardwareContext(HardwareInputRepeatParameters const & input,
    HardwareSpriteBufferParameters const & buffer)
{
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, buffer);
    u16 status = state->display.status;
    status |= DISPSTAT_VBLANK_INTR;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareContext::~HardwareContext()
{
    delete state;
}

void UpdateHardwareFrame(struct HardwareContext * owner)
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

    HardwareManagerOwner * manager = &state->manager;
    GetHardwareManagerFrameCommands(manager)->Append(&commands);
    WaitForHardwareVBlank(manager);
    GetHardwareManagerFrameCommands(manager)->Remove(&commands);

    // The list and commands unlink in reverse construction order at scope exit.
}

bool HardwareDisplayCommand::Run()
{
    WriteHardwareDisplayState(display);
    return 0;
}

bool HardwareSpriteBufferCommand::Run()
{
    WriteAndResetHardwareSpriteBuffer(buffer);
    return 0;
}

bool HardwareDmaQueueCommand::Run()
{
    HardwareDmaQueue * storage = queue;
    if (!storage->IsEmpty()) {
        ExecuteDmaTransfers(storage->first, storage->first + storage->Size());
        storage->Clear();
    }
    return 0;
}
