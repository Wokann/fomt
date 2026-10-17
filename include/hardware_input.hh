#ifndef HARDWARE_INPUT_HH
#define HARDWARE_INPUT_HH

#include "prelude.h"

struct HardwareInputRepeatParameters {
    u16 delay;
    u16 interval;
};

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
    HardwareInputState(u16 delay, u16 interval) asm("func_080091A4");
    HardwareInputState(u32 held_value) asm("func_080091E8");
    HardwareInputState(u16 delay, u16 interval, u32 held_value) asm("func_08009224");
#endif
};

EXTERN_C

u32 func_0800912C(void);
u16 * func_08009140(u16 * held);
void func_08009154(u16 * held, u32 value);
u32 func_08009158(u16 * held);
struct HardwareInputState * func_08009168(struct HardwareInputState * input);
struct HardwareInputState * func_0800917C(struct HardwareInputState * input, u32 value);
u32 func_08009190(struct HardwareInputState * input);
struct HardwareInputState * func_080091A4(struct HardwareInputState * input, u16 delay, u16 interval);
struct HardwareInputState * func_080091E8(struct HardwareInputState * input, u32 held);
struct HardwareInputState * func_08009224(struct HardwareInputState * input, u16 delay, u16 interval, u32 held);

EXTERN_C_END

#endif // HARDWARE_INPUT_HH
