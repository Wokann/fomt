#include "hardware_input_repeat.hh"

u32 func_08009268(struct HardwareInputState * input)
{
    u32 pressed = func_08009190(input);
    u16 held = input->held;
    u16 interval = input->repeat_interval;
    u16 delay = input->repeat_delay;
    u32 repeated = 0;
    u32 mask = 0x200;
    i16 * frames = &input->held_frames[9];

    do {
        if (held & mask) {
            i32 frame_count;
            if (!(pressed & mask)) {
                frame_count = *frames;
                if (frame_count != delay) {
                    frame_count++;
                } else {
                    repeated |= mask;
                    frame_count -= interval;
                }
            } else {
                repeated |= mask;
                frame_count = 0;
            }
            *frames = frame_count;
        }
        frames--;
        mask >>= 1;
    } while (mask != 0);

    input->repeated = repeated;
    return repeated;
}

void func_080092C8(struct HardwareInputState * input, u16 delay)
{
    u16 held = input->held;
    u32 mask = 0x200;
    i16 * frames = &input->held_frames[9];
    i32 adjustment = delay - input->repeat_delay;

    do {
        if (held & mask)
            *frames += adjustment;
        frames--;
        mask >>= 1;
    } while (mask != 0);

    input->repeat_delay = delay;
}

void func_080092FC(struct HardwareInputState * input, u16 interval)
{
    input->repeat_interval = interval;
}
