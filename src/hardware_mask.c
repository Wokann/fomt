#include "hardware_mask.hh"

u32 func_080077DC(u32 * mask, u32 size)
{
    u32 full = 0;
    u32 bits = *mask;
    u32 empty;
    if (bits + 1 == 0)
        full = 1;
    if (full)
        return 0x20;
    empty = bits == 0;
    if (empty) {
        u32 width = 1u << size;
        bits |= (1u << width) - 1;
        *mask = bits;
        return 0;
    }
    if (size <= 4) {
        u32 width = 1u << size;
        u32 offset = 0;
        u32 slot = (1u << width) - 1;
        do {
            if ((bits & slot) == 0) {
                *mask |= slot;
                return offset;
            }
            offset += width;
            slot <<= width;
        } while (slot != 0);
    }
    return 0x20;
}

void func_08007844(u32 * mask, u32 offset, u32 size)
{
    if (size <= 4) {
        u32 width = 1u << size;
        u32 slot = ((1u << width) - 1) << (offset & 31);
        *mask &= ~slot;
    } else if (size == 5) {
        *mask = 0;
    }
}
