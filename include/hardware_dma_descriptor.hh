#ifndef HARDWARE_DMA_DESCRIPTOR_HH
#define HARDWARE_DMA_DESCRIPTOR_HH

#include "prelude.h"

enum DmaDescriptorMode {
    DMA_DESCRIPTOR_COPY = 0,
    DMA_DESCRIPTOR_FILL = 1,
};

struct DmaTransferDescriptor {
    u32 mode;
    u32 source_or_value;
    u32 destination;
    u32 control;
};

EXTERN_C

struct DmaTransferDescriptor * func_08008F0C(struct DmaTransferDescriptor * descriptor, u32 source, u32 destination, u32 byte_count);
struct DmaTransferDescriptor * func_08008F60(struct DmaTransferDescriptor * descriptor, u32 value, u32 destination, u32 byte_count);

EXTERN_C_END

#endif // HARDWARE_DMA_DESCRIPTOR_HH
