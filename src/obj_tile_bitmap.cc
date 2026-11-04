#include "obj_tile_bitmap.hh"

u32 ObjTileBitmap32::Allocate(u32 size_shift)
{
    u32 full = 0;
    u32 current_bits = bits;
    u32 empty;
    if (current_bits + 1 == 0)
        full = 1;
    if (full)
        return 0x20;
    empty = current_bits == 0;
    if (empty) {
        u32 width = 1u << size_shift;
        // size_shift == 5 uses the original agbcp/ARM register-shift result:
        // LSL by 32 yields zero. This expression is not portable C++.
        current_bits |= (1u << width) - 1;
        bits = current_bits;
        return 0;
    }
    if (size_shift <= 4) {
        u32 width = 1u << size_shift;
        u32 offset = 0;
        u32 slot = (1u << width) - 1;
        do {
            if ((current_bits & slot) == 0) {
                bits |= slot;
                return offset;
            }
            offset += width;
            slot <<= width;
        } while (slot != 0);
    }
    return 0x20;
}

void ObjTileBitmap32::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 4) {
        u32 width = 1u << size_shift;
        u32 slot = ((1u << width) - 1) << (offset & 31);
        bits &= ~slot;
    } else if (size_shift == 5) {
        bits = 0;
    }
}
