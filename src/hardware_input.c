#include "hardware_input.hh"

#include "gbaio.h"

u32 func_0800912C(void)
{
    return 0x3ff & ~REG_KEYINPUT;
}

u16 * func_08009140(u16 * held)
{
    *held = func_0800912C();
    return held;
}

void func_08009154(u16 * held, u32 value)
{
    *held = value;
}

u32 func_08009158(u16 * held)
{
    u32 value = func_0800912C();
    *held = value;
    return value;
}

struct HardwareInputState * func_08009168(struct HardwareInputState * input)
{
    func_08009140(&input->held);
    input->pressed = input->held;
    return input;
}

struct HardwareInputState * func_0800917C(struct HardwareInputState * input, u32 value)
{
    func_08009154(&input->held, value);
    input->pressed = input->held;
    return input;
}

u32 func_08009190(struct HardwareInputState * input)
{
    u16 previous = input->held;
    u32 current = func_08009158(&input->held);
    u32 pressed = current & ~previous;
    input->pressed = pressed;
    return pressed;
}

struct HardwareInputState * func_080091A4(struct HardwareInputState * input, u16 delay, u16 interval)
{
    i16 * frame;
    i16 * end;
    func_08009168(input);
    input->repeated = input->pressed;
    input->repeat_delay = delay;
    input->repeat_interval = interval;
    // The original constructor stores this zero word on its stack before
    // initializing the ten per-key counters.
    {
        volatile u32 initial_frame_count = 0;
    }
    frame = input->held_frames;
    end = input->held_frames + 10;
    while (frame != end)
        *frame++ = 0;
    return input;
}

struct HardwareInputState * func_080091E8(struct HardwareInputState * input, u32 held)
{
    i16 * frame;
    i16 * end;
    func_0800917C(input, held);
    input->repeated = input->pressed;
    input->repeat_delay = 30;
    input->repeat_interval = 4;
    {
        volatile u32 initial_frame_count = 0;
    }
    frame = input->held_frames;
    end = input->held_frames + 10;
    while (frame != end)
        *frame++ = 0;
    return input;
}

struct HardwareInputState * func_08009224(struct HardwareInputState * input, u16 delay, u16 interval, u32 held)
{
    i16 * frame;
    i16 * end;
    func_0800917C(input, held);
    input->repeated = input->pressed;
    input->repeat_delay = delay;
    input->repeat_interval = interval;
    {
        volatile u32 initial_frame_count = 0;
    }
    frame = input->held_frames;
    end = input->held_frames + 10;
    while (frame != end)
        *frame++ = 0;
    return input;
}
