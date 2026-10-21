#include "joy_bus.hh"

#include "gbaio.h"

JoyBusCommand * gCurrentJoyBusCommand;
JoyBusContext * gJoyBusContext;

void InitializeJoyBusContext(JoyBusContext * context)
{
    gJoyBusContext = context;
    context->state = 0;
    ResetJoyBusCommandQueue();
    gJoyBusContext->unk_04 = 0;
    gJoyBusContext->unk_08 = 0;
}

void StartJoyBusCommunication(void)
{
    JoyBusContext * context = gJoyBusContext;
    JoyBusCommand command;
    if (context->state == 0) {
        context->state = 1;
        context->unk_14 = 0;
        context->unk_18 = 0;
        context->unk_1C = 0;
        context->unk_20 = 1;
        context->result = 0;
        context->unk_184 = 0;
        context->unk_17C = 0;
        context->unk_0C = 0;
        context->unk_10 = 0;
        // The native initializer sets only kind; do not zero the payload.
        command.kind = 0;
        EnqueueJoyBusCommand(&command);
        ConfigureJoyBusRegisters(0, 0);
        EnableJoyBusInterrupt();
    }
}

void StopJoyBusCommunication(void)
{
    JoyBusContext * context = gJoyBusContext;
    if (context->state != 0) {
        context->state = 0;
        DisableJoyBusInterrupt();
    }
}

void FinishJoyBusCommand(u32 result)
{
    gCurrentJoyBusCommand->kind = 0;
    gJoyBusContext->result = result;
}

void ResetJoyBusCommandResult(void)
{
    gCurrentJoyBusCommand->kind = 0;
    gJoyBusContext->result = 0;
}

void EnableJoyBusInterrupt(void)
{
    u16 enabled = REG_IME;
    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = enabled;
}

void DisableJoyBusInterrupt(void)
{
    u16 enabled = REG_IME;
    REG_IME = 0;
    REG_IE &= 0xFF7F;
    REG_IF = 0x80;
    REG_IME = enabled;
}

void ResetJoyBusCommandQueue(void)
{
    JoyBusContext * context = gJoyBusContext;
    context->read_index = 0;
    context->write_index = 0;
    gCurrentJoyBusCommand = &context->commands[0];
    context->commands[0].kind = 0;
}

void EnqueueJoyBusCommand(JoyBusCommand * command)
{
    JoyBusContext * context = gJoyBusContext;
    context->write_index = (context->write_index + 1) % JOY_BUS_COMMAND_SLOT_COUNT;
    command->unk_04 = 0;
    command->unk_08 = 0;
    context->commands[context->write_index] = *command;
}

void AdvanceJoyBusCommandQueue(void)
{
    JoyBusContext * context = gJoyBusContext;
    if (context->read_index != context->write_index) {
        context->read_index = (context->read_index + 1) % JOY_BUS_COMMAND_SLOT_COUNT;
        gCurrentJoyBusCommand = &context->commands[context->read_index];
    }
}

u32 IsJoyBusCommandQueueEmpty(void)
{
    return gJoyBusContext->read_index == gJoyBusContext->write_index;
}

void ClearJoyBusCommandQueue(void)
{
    JoyBusContext * context = gJoyBusContext;
    context->write_index = (context->read_index + 1) % JOY_BUS_COMMAND_SLOT_COUNT;
    context->commands[context->write_index].kind = 0;
    context->read_index = context->write_index;
    gCurrentJoyBusCommand = &context->commands[context->read_index];
}
