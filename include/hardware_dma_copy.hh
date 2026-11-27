#ifndef HARDWARE_DMA_COPY_HH
#define HARDWARE_DMA_COPY_HH

#include "hardware_dma.hh"
#include "hardware_linked_list.hh"

#pragma interface "hardware_dma_copy_commands.hh"

// Shared by the HUD and menus. A completed DMA copy leaves the hardware list.
struct HardwareDmaCopyLink : HardwareLinkBase {
    void const * source;
    void * destination;
    u32 byte_count;

    HardwareDmaCopyLink();

    bool IsQueued() const;

    virtual bool Run();
};


#pragma interface "hardware_dma_copy.hh"

inline HardwareDmaCopyLink::HardwareDmaCopyLink()
    : source(0), destination(0), byte_count(0) {}

inline bool HardwareDmaCopyLink::IsQueued() const { return previous_slot != 0; }

#include "hardware_dma_copy_commands.hh"


#endif // HARDWARE_DMA_COPY_HH
