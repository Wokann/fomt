#ifndef HARDWARE_INPUT_REPEAT_HH
#define HARDWARE_INPUT_REPEAT_HH

#include "hardware_input.hh"

EXTERN_C

u32 UpdateHardwareKeyRepeat(struct HardwareInputState * input);
void SetHardwareKeyRepeatDelay(struct HardwareInputState * input, u16 delay);
void SetHardwareKeyRepeatInterval(struct HardwareInputState * input, u16 interval);

EXTERN_C_END

#endif // HARDWARE_INPUT_REPEAT_HH
