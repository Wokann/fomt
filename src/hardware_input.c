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
