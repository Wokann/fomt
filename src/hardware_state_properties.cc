#include "hardware_state_properties.hh"
#include "hardware_refcount.hh"
#include <algorithm>

u16 func_08007E8C(void)
{
    return gUnk_03000408->allocation_count;
}

u32 func_08007EA0(void)
{
    return 0x100;
}

void HardwareTileTree1024::Fill()
{
    FillHardwareTileTree512(&children[0]);
    FillHardwareTileTree512(&children[1]);
    full = true;
    empty = false;
}

void HardwareTileTree1024::Clear()
{
    ClearHardwareTileTree512(&children[1]);
    ClearHardwareTileTree512(&children[0]);
    full = false;
    empty = true;
}

void HardwareTileTree1024::Reserve(u32 offset, u32 length)
{
    if (offset > 1023 || length == 0)
        return;
    if (offset == 0 && length > 1023) {
        Fill();
        return;
    }
    if (offset <= 511) {
        u32 first_capacity = 512 - offset;
        u32 count = std::min(length, first_capacity);
        children[0].Reserve(offset, count);
    }
    if (offset + length > 512) {
        u32 second_offset = offset > 511 ? offset - 512 : 0;
        u32 second_length = offset + length;
        second_length -= 512;
        second_length -= second_offset;
        children[1].Reserve(second_offset, second_length);
    }
    u32 active = 0;
    if (children[0].full != 0)
        active = (0u - children[1].full) >> 31;
    full = active;
    empty = false;
}

void HardwareTileTree1024::Unreserve(u32 offset, u32 length)
{
    if (offset > 1023 || length == 0)
        return;
    if (offset == 0 && length > 1023) {
        Clear();
        return;
    }
    u32 first_limit = 511;
    HardwareTileTree512 * first = &children[0];
    if (offset <= first_limit) {
        u32 first_capacity = 512 - offset;
        u32 count = std::min(length, first_capacity);
        first->Unreserve(offset, count);
    }
    if (offset + length > 512) {
        u32 second_offset = offset > 511 ? offset - 512 : 0;
        u32 second_length = offset + length;
        second_length -= 512;
        second_length -= second_offset;
        children[1].Unreserve(second_offset, second_length);
    }
    full = false;
    u32 active = 0;
    if (first->empty != 0) {
        HardwareTileTree512 * second = &children[1];
        active = (0u - second->empty) >> 31;
    }
    empty = active;
}

u32 HardwareTileTree1024::Allocate(u32 size_shift)
{
    u32 index;
    HardwareTileTree512 * child;

    if (size_shift <= 9) {
        for (index = 0, child = children; (int)index <= 1; ++child, ++index) {
            u32 offset;
            u32 active;
            u32 valid;
            // Snapshot the flag before the child allocator changes its state.
            u8 const child_full = child->full;
            if (child_full == 0) {
                offset = child->Allocate(size_shift);
                valid = 0;
                if (offset <= 0x1FF)
                    valid = 1;
                if (valid != 0) {
                    empty = child_full;
                    active = 0;
                    if (children[0].full != 0)
                        active = (0u - children[1].full) >> 31;
                    full = active;
                    return (index << 9) | offset;
                }
            }
        }
    } else if (size_shift == 10 && empty != 0) {
        Fill();
        return 0;
    }
    return 0x400;
}

void HardwareTileTree1024::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 9) {
        u32 use_second = offset & 512;
        HardwareTileTree512 * first = &children[0];
        HardwareTileTree512 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->empty != 0) {
            HardwareTileTree512 * second = &children[1];
            active = (0u - second->empty) >> 31;
        }
        empty = active;
    } else if (size_shift == 10) {
        Clear();
    }
}

bool HardwareTileTree1024::IsEmpty() const
{
    return empty;
}

bool HardwareTileTree1024::IsFull() const
{
    return full;
}

HardwareTileTree1024::HardwareTileTree1024() : full(false), empty(true)
{
}
