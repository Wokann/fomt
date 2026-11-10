#ifndef HARDWARE_CONTEXT_COMMANDS_HH
#define HARDWARE_CONTEXT_COMMANDS_HH

#include "hardware_context.hh"

#pragma interface "hardware_context_commands.hh"

// The original frontend retains the Run bodies in reverse definition order.
// The class owner also emits their implicit base-only destructors and tables.

inline bool HardwareDmaQueueCommand::Run()
{
    HardwareDmaQueue * storage = queue;
    if (!storage->IsEmpty()) {
        ExecuteDmaTransfers(storage->first, storage->first + storage->Size());
        storage->Clear();
    }
    return 0;
}

inline bool HardwareSpriteBufferCommand::Run()
{
    WriteAndResetHardwareSpriteBuffer(buffer);
    return 0;
}

inline bool HardwareDisplayCommand::Run()
{
    WriteHardwareDisplayState(display);
    return 0;
}


#endif // HARDWARE_CONTEXT_COMMANDS_HH
