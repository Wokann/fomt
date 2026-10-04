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

u32 func_08008E28(void const * source, void * destination, u32 byte_count);
void func_08008E64(void const * source, void * destination, u32 byte_count);
void func_08008EB8(u32 value, void * destination, u32 byte_count);
void func_080D0EBC(void const * source, void * destination, u32 control, volatile struct HardwareDmaRegisters * registers);

EXTERN_C_END

#endif // HARDWARE_DMA_HH
