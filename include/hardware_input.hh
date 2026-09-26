#ifndef HARDWARE_INPUT_HH
#define HARDWARE_INPUT_HH

#include "prelude.h"

struct HardwareInputState {
    u16 held;
    u16 unk_02;
    u16 pressed;
    u16 unk_06;
    u16 repeated;
    u16 repeat_delay;
    u16 repeat_interval;
    i16 held_frames[10];
};

EXTERN_C

u32 func_0800912C(void);
u16 * func_08009140(u16 * held);
void func_08009154(u16 * held, u32 value);
u32 func_08009158(u16 * held);
struct HardwareInputState * func_08009168(struct HardwareInputState * input);
struct HardwareInputState * func_0800917C(struct HardwareInputState * input, u32 value);
u32 func_08009190(struct HardwareInputState * input);

EXTERN_C_END

#endif // HARDWARE_INPUT_HH
