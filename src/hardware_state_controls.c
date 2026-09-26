#include "hardware_state_controls.hh"

extern void func_080092C8(void * state, u16 value);
extern void func_080092FC(void * state, u16 value);

void func_080088E0(void * const * state, u16 value)
{
    func_080092C8(*state, value);
}

void func_080088F0(void * const * state, u16 value)
{
    func_080092FC(*state, value);
}

u16 func_08008900(void * const * state)
{
    return *(u16 *)((u8 *)*state + 0xA);
}

u16 func_08008908(void * const * state)
{
    return *(u16 *)((u8 *)*state + 0xC);
}
