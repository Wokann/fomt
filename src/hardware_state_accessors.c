#include "hardware_state_accessors.hh"
#include "hardware_nested_accessors.hh"
#include "hardware_input_repeat.hh"

void func_080088B8(void * const * state)
{
    func_08009268(&((struct HardwareCoreState *)*state)->input);
}

u16 func_080088C4(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.held;
}

u32 func_080088CC(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.pressed;
}

u32 func_080088D4(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.repeated;
}

void * func_080088DC(void * const * state)
{
    return *state;
}

void func_080088E0(void * const * state, u16 value)
{
    func_080092C8(&((struct HardwareCoreState *)*state)->input, value);
}

void func_080088F0(void * const * state, u16 value)
{
    func_080092FC(&((struct HardwareCoreState *)*state)->input, value);
}

u16 func_08008900(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.repeat_delay;
}

u16 func_08008908(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.repeat_interval;
}

struct HardwareDmaQueue * func_08008910(void * const * state)
{
    return &((struct HardwareCoreState *)*state)->dma_queue;
}

struct HardwareDisplayState * func_08008918(void * const * state)
{
    return &((struct HardwareCoreState *)*state)->display;
}

struct HardwareSpriteBufferState * func_08008920(void * const * state)
{
    return &((struct HardwareCoreState *)*state)->sprite_buffer;
}

u8 * func_08008928(void * const * state)
{
    return (u8 *)&((struct HardwareCoreState *)*state)->dma_queue;
}

struct HardwareDisplayState * func_08008930(void * const * state)
{
    return &((struct HardwareCoreState *)*state)->display;
}

struct HardwareSpriteBufferState * func_08008938(void * const * state)
{
    return &((struct HardwareCoreState *)*state)->sprite_buffer;
}

u8 * func_08008940(void * const * state)
{
    return (u8 *)&((struct HardwareCoreState *)*state)->links;
}

u8 * func_0800894C(void * const * state)
{
    return func_08008AE0((void * const *)&((struct HardwareCoreState *)*state)->manager);
}

u8 * func_08008960(void * const * state)
{
    return (u8 *)&((struct HardwareCoreState *)*state)->links;
}

u8 * func_0800896C(void * const * state)
{
    return func_08008AE0((void * const *)&((struct HardwareCoreState *)*state)->manager);
}
