#ifndef HARDWARE_INPUT_REPEAT_HH
#define HARDWARE_INPUT_REPEAT_HH

#include "hardware_input.hh"

EXTERN_C

u32 func_08009268(struct HardwareInputState * input);
void func_080092C8(struct HardwareInputState * input, u16 delay);
void func_080092FC(struct HardwareInputState * input, u16 interval);

EXTERN_C_END

#endif // HARDWARE_INPUT_REPEAT_HH
