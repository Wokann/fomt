#include "hardware_input_repeat.hh"
#include "gbaio.h"

u32 UpdateHardwareKeyRepeat(struct HardwareInputState * input)
{
    u32 pressed = UpdateHardwareKeySnapshot(input);
    u16 held = input->held;
    u16 interval = input->repeat_interval;
    u16 delay = input->repeat_delay;
    u32 repeated = 0;
    u32 mask = L_BUTTON;
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

void SetHardwareKeyRepeatDelay(struct HardwareInputState * input, u16 delay)
{
    u16 held = input->held;
    u32 mask = L_BUTTON;
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

void SetHardwareKeyRepeatInterval(struct HardwareInputState * input, u16 interval)
{
    input->repeat_interval = interval;
}
