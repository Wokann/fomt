#include "hardware_state_properties.hh"
#include "hardware_refcount.hh"

EXTERN_C
void func_080D7118(void *, u32, u32);
void func_080D734C(void *, u32, u32);
u32 func_080D7568(void *, u32);
void func_080D76C0(void *, u32, u32);
EXTERN_C_END

u16 func_08007E8C(void)
{
    return ((HardwareSharedState *)gUnk_03000408)->allocation_count;
}

u32 func_08007EA0(void)
{
    return 0x100;
}

void func_08007EA8(u8 * state)
{
    HardwareTileTree1024 * tree = reinterpret_cast<HardwareTileTree1024 *>(state);
    u32 inactive;
    u32 active;
    FillHardwareTileTree512(&tree->children[0]);
    FillHardwareTileTree512(&tree->children[1]);
    inactive = 0;
    active = 1;
    tree->full = active;
    tree->empty = inactive;
}

void func_08007EC8(u8 * state)
{
    HardwareTileTree1024 * tree = (HardwareTileTree1024 *)state;
    ClearHardwareTileTree512(&tree->children[1]);
    ClearHardwareTileTree512(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

void func_08007EE8(u8 * state, u32 offset, u32 length)
{
    u32 first_capacity;
    u32 * first_length;
    u32 * length_pointer;
    u32 * capacity_pointer;
    u32 selected_length;
    u32 second_offset;
    u32 second_length;
    u32 active;
    u32 inactive;

    if (offset > 0x3FF || length == 0)
        return;
    if (offset == 0 && length > 0x3FF) {
        func_08007EA8(state);
        return;
    }
    if (offset <= 0x1FF) {
        first_capacity = 0x200 - offset;
        length_pointer = &length;
        capacity_pointer = &first_capacity;
        first_length = length > first_capacity ? capacity_pointer : length_pointer;
        selected_length = *first_length;
        func_080D7118(state + 4, offset, selected_length);
    }
    if (offset + length > 0x200) {
        second_offset = offset > 0x1FF ? offset - 0x200 : 0;
        second_length = offset + length;
        second_length -= 0x200;
        second_length -= second_offset;
        func_080D7118(state + 0x80, second_offset, second_length);
    }
    active = 0;
    if (state[4] != 0)
        active = (0u - state[0x80]) >> 31;
    inactive = 0;
    state[0] = active;
    state[1] = inactive;
}

void func_08007F84(u8 * state, u32 offset, u32 length)
{
    u32 first_capacity;
    u32 * first_length;
    u32 * length_pointer;
    u32 * capacity_pointer;
    u32 selected_length;
    u32 second_offset;
    u32 second_length;
    u32 first_limit;
    u8 * first_buffer;
    u8 * second_buffer;
    u32 active;

    if (offset > 0x3FF || length == 0)
        return;
    if (offset == 0 && length > 0x3FF) {
        func_08007EC8(state);
        return;
    }
    first_limit = 0x1FF;
    first_buffer = state + 4;
    if (offset <= first_limit) {
        first_capacity = 0x200 - offset;
        length_pointer = &length;
        capacity_pointer = &first_capacity;
        first_length = length > first_capacity ? capacity_pointer : length_pointer;
        selected_length = *first_length;
        func_080D734C(first_buffer, offset, selected_length);
    }
    if (offset + length > 0x200) {
        second_offset = offset > 0x1FF ? offset - 0x200 : 0;
        second_length = offset + length;
        second_length -= 0x200;
        second_length -= second_offset;
        func_080D734C(state + 0x80, second_offset, second_length);
    }
    state[0] = 0;
    active = 0;
    if (first_buffer[1] != 0) {
        second_buffer = state + 0x80;
        active = (0u - second_buffer[1]) >> 31;
    }
    state[1] = active;
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
                offset = func_080D7568(child, size_shift);
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
        func_08007EA8(reinterpret_cast<u8 *>(this));
        return 0;
    }
    return 0x400;
}

void func_080080A0(u8 * state, u32 offset, u32 kind)
{
    u8 * first_buffer;
    u8 * chosen_buffer;
    u8 * second_buffer;
    u32 active;
    u32 use_second;

    if (kind <= 9) {
        use_second = offset & 0x200;
        first_buffer = state + 4;
        chosen_buffer = first_buffer;
        if (use_second)
            chosen_buffer = state + 0x80;
        func_080D76C0(chosen_buffer, offset, kind);
        state[0] = 0;
        active = 0;
        if (first_buffer[1] != 0) {
            second_buffer = state + 0x80;
            active = (0u - second_buffer[1]) >> 31;
        }
        state[1] = active;
    } else if (kind == 10) {
        func_08007EC8(state);
    }
}

u8 func_080080EC(u8 const * state)
{
    return state[1];
}

u8 func_080080F0(u8 const * state)
{
    return state[0];
}

HardwareTileTree1024::HardwareTileTree1024() : full(false), empty(true)
{
}
