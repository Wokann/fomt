#ifndef HARDWARE_DMA_DESCRIPTOR_HH
#define HARDWARE_DMA_DESCRIPTOR_HH

#include "prelude.h"

enum DmaDescriptorMode {
    DMA_DESCRIPTOR_COPY = 0,
    DMA_DESCRIPTOR_FILL = 1,
};

struct DmaTransferDescriptor {
#ifdef __cplusplus
    DmaTransferDescriptor(void const * source, void * destination, u32 byte_count);
    DmaTransferDescriptor(u32 value, void * destination, u32 byte_count);
#endif
    u32 mode;
    union {
        void const * source;
        u32 fill_value;
    } source_or_value;
    void * destination;
    u32 control;
};

typedef char DmaTransferDescriptor_size_check[(sizeof(struct DmaTransferDescriptor) == 0x10) ? 1 : -1];
typedef char DmaTransferDescriptor_source_offset_check[(offsetof(struct DmaTransferDescriptor, source_or_value) == 4) ? 1 : -1];
typedef char DmaTransferDescriptor_destination_offset_check[(offsetof(struct DmaTransferDescriptor, destination) == 8) ? 1 : -1];
typedef char DmaTransferDescriptor_control_offset_check[(offsetof(struct DmaTransferDescriptor, control) == 0x0C) ? 1 : -1];

EXTERN_C

void func_08008FB8(struct DmaTransferDescriptor const * descriptor);
void func_08008FE4(struct DmaTransferDescriptor const * first, struct DmaTransferDescriptor const * end);
void func_0800901C(struct DmaTransferDescriptor const * descriptor);
void func_08009094(struct DmaTransferDescriptor const * first, struct DmaTransferDescriptor const * end);

EXTERN_C_END

#endif // HARDWARE_DMA_DESCRIPTOR_HH
