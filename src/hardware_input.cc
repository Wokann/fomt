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
    fill_inl(held_frames, held_frames + ARRAY_COUNT(held_frames), 0);
}

HardwareInputState::HardwareInputState(u32 held_value)
{
    InitializeHardwareInputSnapshotFromKeys(this, held_value);
    repeated = pressed;
    repeat_delay = 30;
    repeat_interval = 4;
    fill_inl(held_frames, held_frames + ARRAY_COUNT(held_frames), 0);
}

HardwareInputState::HardwareInputState(u16 delay, u16 interval, u32 held_value)
{
    InitializeHardwareInputSnapshotFromKeys(this, held_value);
    repeated = pressed;
    repeat_delay = delay;
    repeat_interval = interval;
    fill_inl(held_frames, held_frames + ARRAY_COUNT(held_frames), 0);
}

u32 UpdateHardwareKeyRepeat(struct HardwareInputState * input)
{
    u32 pressed = UpdateHardwareKeySnapshot(input);
    u16 held = input->held;
    u16 interval = input->repeat_interval;
    u16 delay = input->repeat_delay;
    u32 repeated = 0;
    u32 mask = L_BUTTON;
    uptr frame_address = reinterpret_cast<uptr>(&input->held_frames[ARRAY_COUNT(input->held_frames) - 1]);

    do {
        if (held & mask) {
            i32 frame_count;
            if (!(pressed & mask)) {
                frame_count = *reinterpret_cast<i16 *>(frame_address);
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
            *reinterpret_cast<i16 *>(frame_address) = frame_count;
        }
        frame_address -= sizeof(i16);
        mask >>= 1;
    } while (mask != 0);

    input->repeated = repeated;
    return repeated;
}

void SetHardwareKeyRepeatDelay(struct HardwareInputState * input, u16 delay)
{
    u16 held = input->held;
    u32 mask = L_BUTTON;
    uptr frame_address = reinterpret_cast<uptr>(&input->held_frames[ARRAY_COUNT(input->held_frames) - 1]);
    i32 adjustment = delay - input->repeat_delay;

    do {
        if (held & mask)
            *reinterpret_cast<i16 *>(frame_address) += adjustment;
        frame_address -= sizeof(i16);
        mask >>= 1;
    } while (mask != 0);

    input->repeat_delay = delay;
}

void SetHardwareKeyRepeatInterval(struct HardwareInputState * input, u16 interval)
{
    input->repeat_interval = interval;
}
