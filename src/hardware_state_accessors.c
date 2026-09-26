#include "hardware_state_accessors.hh"

extern void func_080092C8(void * state, u16 value);
extern void func_080092FC(void * state, u16 value);
extern u8 * func_08008AE0(void * const * state);

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

u8 * func_08008928(void * const * state)
{
    return (u8 *)*state + 0x24;
}

u8 * func_08008930(void * const * state)
{
    return (u8 *)*state + 0x34;
}

u8 * func_08008938(void * const * state)
{
    return (u8 *)*state + 0x8C;
}

u8 * func_08008940(void * const * state)
{
    return (u8 *)*state + 0x494;
}

u8 * func_0800894C(void * const * state)
{
    return func_08008AE0((void * const *)((u8 *)*state + 0x490));
}

u8 * func_08008960(void * const * state)
{
    return (u8 *)*state + 0x494;
}

u8 * func_0800896C(void * const * state)
{
    return func_08008AE0((void * const *)((u8 *)*state + 0x490));
}
