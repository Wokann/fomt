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

#endif // HARDWARE_DMA_HH
