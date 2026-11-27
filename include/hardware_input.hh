#ifndef HARDWARE_INPUT_HH
#define HARDWARE_INPUT_HH

#include "prelude.h"

struct HardwareInputRepeatParameters {
    u16 delay;
    u16 interval;
#ifdef __cplusplus
    HardwareInputRepeatParameters(u16 delay, u16 interval)
        : delay(delay), interval(interval) {}
#endif
};



#ifdef __cplusplus
// A value snapshot of the returned key word, independent of live input state.
// Native readers use both the word and its bytes in GBA little-endian order.
struct HardwareKeySnapshot {
    union {
        u32 value;
        u8 bytes[4];
    };

    static u32 ShoulderBits(u32 keys, u32 mask)
    {
        u32 shoulders = keys >> 8;
        mask >>= 8;
        mask &= shoulders;
        return mask;
    }

    u8 Byte(u32 index) const
    {
        return reinterpret_cast<u8 const *>(&value)[index];
    }
};

#endif

struct HardwareInputState {
    u16 held;
    u16 unk_02;
    u16 pressed;
    u16 unk_06;
    u16 repeated;
    u16 repeat_delay;
    u16 repeat_interval;
    i16 held_frames[10];
#ifdef __cplusplus
    HardwareInputState(u16 delay, u16 interval);
    HardwareInputState(u32 held_value);
    HardwareInputState(u16 delay, u16 interval, u32 held_value);
#endif
};

EXTERN_C

u32 ReadHardwareKeys(void);
u16 * InitializeHardwareHeldKeys(u16 * held);
void AssignHardwareHeldKeys(u16 * held, u32 value);
u32 RefreshHardwareHeldKeys(u16 * held);
struct HardwareInputState * InitializeHardwareInputSnapshot(struct HardwareInputState * input);
struct HardwareInputState * InitializeHardwareInputSnapshotFromKeys(struct HardwareInputState * input, u32 value);
u32 UpdateHardwareKeySnapshot(struct HardwareInputState * input);

u32 UpdateHardwareKeyRepeat(struct HardwareInputState * input);
void SetHardwareKeyRepeatDelay(struct HardwareInputState * input, u16 delay);
void SetHardwareKeyRepeatInterval(struct HardwareInputState * input, u16 interval);

EXTERN_C_END

#endif // HARDWARE_INPUT_HH
