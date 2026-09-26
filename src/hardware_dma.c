#include "hardware_dma.hh"

u32 func_08008E28(u32 source, u32 destination, u32 byte_count)
{
    if (byte_count != 0 && ((source | destination | byte_count) & 1) == 0) {
        if (((source | destination | byte_count) & 3) == 0)
            byte_count = 0x84000000 | ((byte_count >> 2) & 0xffff);
        else
            byte_count = 0x80000000 | ((byte_count >> 1) & 0xffff);
    } else {
        byte_count = 0;
    }
    return byte_count;
}
