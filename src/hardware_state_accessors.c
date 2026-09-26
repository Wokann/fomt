#include "hardware_state_accessors.hh"

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

// The owner holds one pointer to the display state. Only these offsets
// are established here; the surrounding state layout remains unclassified.
u8 * func_08008910(void * const * state)
{
    return (u8 *)*state + 0x24;
}

u8 * func_08008918(void * const * state)
{
    return (u8 *)*state + 0x34;
}

u8 * func_08008920(void * const * state)
{
    return (u8 *)*state + 0x8C;
}
