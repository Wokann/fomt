#include "hardware_dma.hh"

#include "gbaio.h"

u32 func_08008E28(void const * source, void * destination, u32 byte_count)
{
    if (byte_count != 0 && (((u32)source | (u32)destination | byte_count) & 1) == 0) {
        if ((((u32)source | (u32)destination | byte_count) & 3) == 0)
            byte_count = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
        else
            byte_count = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
    } else {
        byte_count = 0;
    }
    return byte_count;
}

void func_08008E64(void const * source, void * destination, u32 byte_count)
{
    void const * saved_source;
    if (source == 0 || destination == 0)
        return;
    saved_source = source;
    if (byte_count != 0 && (((u32)saved_source | (u32)destination | byte_count) & 1) == 0) {
        if ((((u32)saved_source | (u32)destination | byte_count) & 3) == 0)
            byte_count = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
        else
            byte_count = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
    } else {
        byte_count = 0;
    }
    func_080D0EBC(saved_source, destination, byte_count, (volatile struct HardwareDmaRegisters *)&REG_DMA3SAD);
}

void func_08008EB8(u32 value, void * destination, u32 byte_count)
{
    u32 fill_value = value;
    if (destination != 0) {
        u32 control;
        if (byte_count != 0 && (((u32)destination | byte_count) & 1) == 0) {
            if ((((u32)destination | byte_count) & 3) == 0)
                control = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
            else
                control = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
        } else {
            control = 0;
        }
        control |= DMA_SRC_FIXED << 16;
        func_080D0EBC(&fill_value, destination, control, (volatile struct HardwareDmaRegisters *)&REG_DMA3SAD);
    }
}
