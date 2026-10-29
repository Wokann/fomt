#include "prelude.h"
#pragma implementation "hardware_bootstrap.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_nested_accessors.hh"
#include "hardware_sprite_buffer.hh"
#include "gbaio.h"

void * operator new(unsigned long);
void operator delete(void *);

HardwareBootstrap::HardwareBootstrap()
{
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, 0, 0x20);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::HardwareBootstrap(HardwareInputRepeatParameters const & input)
{
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, 0, 0x20);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::HardwareBootstrap(HardwareSpriteBufferParameters const & buffer)
{
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
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, buffer);
    u16 status = state->display.status;
    status |= 8;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareBootstrap::~HardwareBootstrap()
{
    delete state;
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

    HardwareManagerOwner * manager = &state->manager;
    func_08008AE0(manager)->Append(&commands);
    func_08008AF0(manager);
    func_08008AE0(manager)->Remove(&commands);

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
