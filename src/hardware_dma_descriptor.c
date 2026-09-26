#include "hardware_dma_descriptor.hh"

#include "gbaio.h"

struct DmaTransferDescriptor * func_08008F0C(struct DmaTransferDescriptor * descriptor, u32 source, u32 destination, u32 byte_count)
{
    if (source != 0 && destination != 0 && byte_count != 0 && ((source | destination | byte_count) & 1) == 0) {
        if (((source | destination | byte_count) & 3) == 0)
            byte_count = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
        else
            byte_count = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
    } else {
        byte_count = 0;
    }
    descriptor->mode = DMA_DESCRIPTOR_COPY;
    descriptor->source_or_value = source;
    descriptor->destination = destination;
    descriptor->control = byte_count;
    return descriptor;
}

struct DmaTransferDescriptor * func_08008F60(struct DmaTransferDescriptor * descriptor, u32 value, u32 destination, u32 byte_count)
{
    u32 control;
    if (destination != 0) {
        if (byte_count != 0 && ((destination | byte_count) & 1) == 0) {
            if (((destination | byte_count) & 3) == 0)
                byte_count = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
            else
                byte_count = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
        } else {
            byte_count = 0;
        }
        control = byte_count | (DMA_SRC_FIXED << 16);
    } else {
        control = 0;
    }
    descriptor->mode = DMA_DESCRIPTOR_FILL;
    descriptor->source_or_value = value;
    descriptor->destination = destination;
    descriptor->control = control;
    return descriptor;
}
