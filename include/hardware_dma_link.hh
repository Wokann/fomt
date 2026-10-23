#ifndef HARDWARE_DMA_LINK_HH
#define HARDWARE_DMA_LINK_HH

#include "prelude.h"
#include "hardware_dma.hh"
#include "hardware_linked_list.hh"

#pragma interface "hardware_dma_link.hh"

// Shared by the HUD and menus. A completed DMA copy leaves the hardware list.
struct HardwareDmaCopyLink : HardwareLinkBase {
    void const * source;
    void * destination;
    u32 byte_count;

    HardwareDmaCopyLink() : source(0), destination(0), byte_count(0) {}

    virtual bool Run()
    {
        CopyHardwareDma3(source, destination, byte_count);
        return false;
    }
};

typedef char HardwareDmaCopyLinkSize[sizeof(HardwareDmaCopyLink) == 24 ? 1 : -1];
typedef char HardwareDmaCopyLinkSourceOffset[offsetof(HardwareDmaCopyLink, source) == 0xC ? 1 : -1];
typedef char HardwareDmaCopyLinkDestinationOffset[offsetof(HardwareDmaCopyLink, destination) == 0x10 ? 1 : -1];
typedef char HardwareDmaCopyLinkCountOffset[offsetof(HardwareDmaCopyLink, byte_count) == 0x14 ? 1 : -1];

#pragma implementation

#endif // HARDWARE_DMA_LINK_HH
