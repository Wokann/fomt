#include "hardware_dma.hh"

#include "gbaio.h"

extern void func_080D0EBC(u32 source, u32 destination, u32 control, volatile u32 * registers);

u32 func_08008E28(u32 source, u32 destination, u32 byte_count)
{
    if (byte_count != 0 && ((source | destination | byte_count) & 1) == 0) {
        if (((source | destination | byte_count) & 3) == 0)
            byte_count = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
        else
            byte_count = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
    } else {
        byte_count = 0;
    }
    return byte_count;
}

void func_08008E64(u32 source, u32 destination, u32 byte_count)
{
    u32 saved_source;
    if (source == 0 || destination == 0)
        return;
    saved_source = source;
    if (byte_count != 0 && ((saved_source | destination | byte_count) & 1) == 0) {
        if (((saved_source | destination | byte_count) & 3) == 0)
            byte_count = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
        else
            byte_count = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
    } else {
        byte_count = 0;
    }
    func_080D0EBC(saved_source, destination, byte_count, &REG_DMA3SAD);
}

void func_08008EB8(u32 value, u32 destination, u32 byte_count)
{
    u32 fill_value = value;
    if (destination != 0) {
        u32 control;
        if (byte_count != 0 && ((destination | byte_count) & 1) == 0) {
            if (((destination | byte_count) & 3) == 0)
                control = ((DMA_ENABLE | DMA_32BIT) << 16) | ((byte_count >> 2) & 0xffff);
            else
                control = (DMA_ENABLE << 16) | ((byte_count >> 1) & 0xffff);
        } else {
            control = 0;
        }
        control |= DMA_SRC_FIXED << 16;
        func_080D0EBC((u32)&fill_value, destination, control, &REG_DMA3SAD);
    }
}
