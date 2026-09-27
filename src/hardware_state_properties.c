#include "hardware_state_properties.hh"
#include "hardware_refcount.hh"

extern void func_080D6EEC(void *);
extern void func_080D6F5C(void *);
extern void func_080D7118(void *, u32, u32);
extern void func_080D734C(void *, u32, u32);
extern u32 func_080D7568(void *, u32);

u16 func_08007E8C(void)
{
    // The meaning of the halfword at this state offset is not yet known.
    return ((HardwareSharedState *)gUnk_03000408)->unk_920;
}

u32 func_08007EA0(void)
{
    return 0x100;
}

void func_08007EA8(u8 * state)
{
    register u32 inactive;
    register u32 active;
    func_080D6EEC(state + 4);
    func_080D6EEC(state + 0x80);
    inactive = 0;
    active = 1;
    state[0] = active;
    state[1] = inactive;
}

void func_08007EC8(u8 * state)
{
    func_080D6F5C(state + 0x80);
    func_080D6F5C(state + 4);
    state[0] = 0;
    state[1] = 1;
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
    register u32 active;
    register u32 inactive;

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
    register u32 first_limit;
    u8 * first_buffer;
    u8 * second_buffer;
    register u32 active;

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

u32 func_08008020(u8 * state, u32 kind)
{
    u32 index;
    u8 * buffer;

    if (kind <= 9) {
        for (index = 0, buffer = state + 4; (int)index <= 1; buffer += 0x7C, index++) {
            u32 offset;
            u32 active;
            u32 valid;
            // Keep the flag live across the helper call with the old compiler.
            register u8 empty __asm__("r5");
            empty = buffer[0];
            if (empty == 0) {
                offset = func_080D7568(buffer, kind);
                valid = 0;
                if (offset <= 0x1FF)
                    valid = 1;
                if (valid != 0) {
                    state[1] = empty;
                    active = 0;
                    if (state[4] != 0)
                        active = (0u - state[0x80]) >> 31;
                    state[0] = active;
                    return (index << 9) | offset;
                }
            }
        }
    } else if (kind == 10 && state[1] != 0) {
        func_08007EA8(state);
        return 0;
    }
    return 0x400;
}
