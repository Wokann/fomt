#ifndef HARDWARE_DMA_COPY_COMMANDS_HH
#define HARDWARE_DMA_COPY_COMMANDS_HH

#include "hardware_dma_copy.hh"

#pragma interface "hardware_dma_copy_commands.hh"

// This interface owns the run entry and the implicit command cleanup.
inline bool HardwareDmaCopyLink::Run()
{
    CopyHardwareDma3(source, destination, byte_count);
    return false;
}


#endif // HARDWARE_DMA_COPY_COMMANDS_HH
