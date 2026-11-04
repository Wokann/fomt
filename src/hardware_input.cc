#include "hardware_input.hh"

#include "gbaio.h"
#include "unknown_inlines.hh"

u32 ReadHardwareKeys(void)
{
    return KEYS_MASK & ~REG_KEYINPUT;
}

u16 * InitializeHardwareHeldKeys(u16 * held)
{
    *held = ReadHardwareKeys();
    return held;
}

void AssignHardwareHeldKeys(u16 * held, u32 value)
{
    *held = value;
}

u32 RefreshHardwareHeldKeys(u16 * held)
{
    u32 value = ReadHardwareKeys();
    *held = value;
    return value;
}

struct HardwareInputState * InitializeHardwareInputSnapshot(struct HardwareInputState * input)
{
    InitializeHardwareHeldKeys(&input->held);
    input->pressed = input->held;
    return input;
}

struct HardwareInputState * InitializeHardwareInputSnapshotFromKeys(struct HardwareInputState * input, u32 value)
{
    AssignHardwareHeldKeys(&input->held, value);
    input->pressed = input->held;
    return input;
}

u32 UpdateHardwareKeySnapshot(struct HardwareInputState * input)
{
    u16 previous = input->held;
    u32 current = RefreshHardwareHeldKeys(&input->held);
    u32 pressed = current & ~previous;
    input->pressed = pressed;
    return pressed;
}

HardwareInputState::HardwareInputState(u16 delay, u16 interval)
{
    InitializeHardwareInputSnapshot(this);
    repeated = pressed;
    repeat_delay = delay;
    repeat_interval = interval;
    fill_inl(held_frames, held_frames + 10, 0);
}

HardwareInputState::HardwareInputState(u32 held_value)
{
    InitializeHardwareInputSnapshotFromKeys(this, held_value);
    repeated = pressed;
    repeat_delay = 30;
    repeat_interval = 4;
    fill_inl(held_frames, held_frames + 10, 0);
}

HardwareInputState::HardwareInputState(u16 delay, u16 interval, u32 held_value)
{
    InitializeHardwareInputSnapshotFromKeys(this, held_value);
    repeated = pressed;
    repeat_delay = delay;
    repeat_interval = interval;
    fill_inl(held_frames, held_frames + 10, 0);
}
