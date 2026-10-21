#include "hardware_dma_descriptor.hh"
#include "hardware_dma.hh"

#include "gbaio.h"
#include "gbasvc.h"

DmaTransferDescriptor::DmaTransferDescriptor(void const * source, void * target, u32 byte_count)
{
    if (source != 0 && target != 0 && byte_count != 0 && (((u32)source | (u32)target | byte_count) & 1) == 0) {
        if ((((u32)source | (u32)target | byte_count) & 3) == 0)
            byte_count = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
        else
            byte_count = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
    } else {
        byte_count = 0;
    }
    mode = DMA_DESCRIPTOR_COPY;
    source_or_value.source = source;
    destination = target;
    control = byte_count;
}

DmaTransferDescriptor::DmaTransferDescriptor(u32 value, void * target, u32 byte_count)
{
    u32 result;
    if (target != 0) {
        if (byte_count != 0 && (((u32)target | byte_count) & 1) == 0) {
            if ((((u32)target | byte_count) & 3) == 0)
                byte_count = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
            else
                byte_count = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
        } else {
            byte_count = 0;
        }
        result = byte_count | (DMA_SRC_FIXED << 16);
    } else {
        result = 0;
    }
    mode = DMA_DESCRIPTOR_FILL;
    source_or_value.fill_value = value;
    destination = target;
    control = result;
}

void ExecuteDmaTransfer(struct DmaTransferDescriptor const * descriptor)
{
    void const * source = descriptor->source_or_value.source;
    u32 fill_value;
    if (descriptor->mode == DMA_DESCRIPTOR_FILL) {
        fill_value = descriptor->source_or_value.fill_value;
        source = &fill_value;
    }
    WriteHardwareDmaRegisters(source, descriptor->destination, descriptor->control, (volatile struct HardwareDmaRegisters *)&REG_DMA3SAD);
}

void ExecuteDmaTransfers(struct DmaTransferDescriptor const * first, struct DmaTransferDescriptor const * end)
{
    struct DmaTransferDescriptor const * stop = end;
    volatile struct HardwareDmaRegisters * registers = (volatile struct HardwareDmaRegisters *)&REG_DMA3SAD;
    struct DmaTransferDescriptor const * current = first;
    while (current != stop) {
        void const * source = current->source_or_value.source;
        u32 fill_value;
        if (current->mode == DMA_DESCRIPTOR_FILL) {
            fill_value = current->source_or_value.fill_value;
            source = &fill_value;
        }
        WriteHardwareDmaRegisters(source, current->destination, current->control, registers);
        ++current;
    }
}

void ExecuteBiosTransfer(struct DmaTransferDescriptor const * descriptor)
{
    u8 const * source;
    u32 fill_value;
    u32 control;
    u8 * destination;
    u32 remainder;
    u32 aligned_count;

    source = (u8 const *)descriptor->source_or_value.source;
    if (descriptor->mode == DMA_DESCRIPTOR_FILL) {
        fill_value = descriptor->source_or_value.fill_value;
        source = (u8 const *)&fill_value;
    }
    control = descriptor->control;
    destination = (u8 *)descriptor->destination;
    if ((control & CPUSET_32BIT) != 0) {
        aligned_count = control & 0xffff;
        remainder = aligned_count & 7;
        aligned_count -= remainder;
        if (aligned_count != 0 || remainder == 0) {
            CpuFastSet((void const *)source, (void *)destination, control - remainder);
            destination += aligned_count << 2;
            if ((control & CPUSET_SRC_FIXED) == 0)
                source += aligned_count << 2;
        }
        if (remainder != 0)
            CpuSet((void const *)source, (void *)destination, control - aligned_count);
    } else {
        CpuSet((void const *)source, (void *)destination, control);
    }
}

void ExecuteBiosTransfers(struct DmaTransferDescriptor const * first, struct DmaTransferDescriptor const * end)
{
    struct DmaTransferDescriptor const * stop = end;
    struct DmaTransferDescriptor const * current = first;
    while (current != stop) {
        u8 const * source;
        u32 fill_value;
        u32 control;
        u8 * destination;
        u32 remainder;
        u32 aligned_count;

        source = (u8 const *)current->source_or_value.source;
        if (current->mode == DMA_DESCRIPTOR_FILL) {
            fill_value = current->source_or_value.fill_value;
            source = (u8 const *)&fill_value;
        }
        control = current->control;
        destination = (u8 *)current->destination;
        if ((control & CPUSET_32BIT) != 0) {
            aligned_count = control & 0xffff;
            remainder = aligned_count & 7;
            aligned_count -= remainder;
            if (aligned_count != 0 || remainder == 0) {
                CpuFastSet((void const *)source, (void *)destination, control - remainder);
                destination += aligned_count << 2;
                if ((control & CPUSET_SRC_FIXED) == 0)
                    source += aligned_count << 2;
            }
            if (remainder != 0)
                CpuSet((void const *)source, (void *)destination, control - aligned_count);
        } else {
            CpuSet((void const *)source, (void *)destination, control);
        }
        ++current;
    }
}
