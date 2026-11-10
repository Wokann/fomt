#ifndef HARDWARE_DMA_HH
#define HARDWARE_DMA_HH

#include "prelude.h"

// Source, destination, and count/control are the three adjacent DMA MMIO words.
struct HardwareDmaRegisters {
    u32 source;
    u32 destination;
    u32 control;
};

typedef char HardwareDmaRegisters_size_check[(sizeof(struct HardwareDmaRegisters) == 0x0C) ? 1 : -1];
typedef char HardwareDmaRegisters_destination_offset_check[(offsetof(struct HardwareDmaRegisters, destination) == 4) ? 1 : -1];
typedef char HardwareDmaRegisters_control_offset_check[(offsetof(struct HardwareDmaRegisters, control) == 8) ? 1 : -1];

EXTERN_C

// Choose word transfers only when both addresses and the byte count permit
// them; otherwise use halfwords. Zero/odd lengths produce a disabled control.
u32 MakeHardwareDmaCopyControl(void const * source, void * destination, u32 byte_count);

// Immediate DMA3 operations. The fill value is a word; halfword transfers use
// its low halfword. Keep the original null/alignment handling in each routine.
void CopyHardwareDma3(void const * source, void * destination, u32 byte_count);
void FillHardwareDma3(u32 value, void * destination, u32 byte_count);

// The native four-byte leaf stores these three words consecutively to the
// selected DMA register bank; it neither builds nor validates the control.
void WriteHardwareDmaRegisters(void const * source, void * destination, u32 control, volatile struct HardwareDmaRegisters * registers);

EXTERN_C_END

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
    // DMA3 and CpuSet use the same bits for word transfers (26) and fixed
    // sources (24). The constructors store the transfer count in bits 0-15.
    u32 control;
};

typedef char DmaTransferDescriptor_size_check[(sizeof(struct DmaTransferDescriptor) == 0x10) ? 1 : -1];
typedef char DmaTransferDescriptor_source_offset_check[(offsetof(struct DmaTransferDescriptor, source_or_value) == 4) ? 1 : -1];
typedef char DmaTransferDescriptor_destination_offset_check[(offsetof(struct DmaTransferDescriptor, destination) == 8) ? 1 : -1];
typedef char DmaTransferDescriptor_control_offset_check[(offsetof(struct DmaTransferDescriptor, control) == 0x0C) ? 1 : -1];

EXTERN_C

// Execute one descriptor, or the half-open [first, end) range, through DMA3.
void ExecuteDmaTransfer(struct DmaTransferDescriptor const * descriptor);
void ExecuteDmaTransfers(struct DmaTransferDescriptor const * first, struct DmaTransferDescriptor const * end);

// The BIOS path uses CpuFastSet for complete groups of eight words, then
// CpuSet for the remaining words or for a halfword transfer.
void ExecuteBiosTransfer(struct DmaTransferDescriptor const * descriptor);
void ExecuteBiosTransfers(struct DmaTransferDescriptor const * first, struct DmaTransferDescriptor const * end);

EXTERN_C_END

#ifdef __cplusplus
#include "hardware_dma_copy.hh"
#endif

#endif // HARDWARE_DMA_HH
