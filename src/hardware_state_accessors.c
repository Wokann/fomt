#include "hardware_state_accessors.hh"
#include "hardware_nested_accessors.hh"
#include "hardware_input_repeat.hh"

void UpdateHardwareInput(void * const * state)
{
    UpdateHardwareKeyRepeat(&((struct HardwareCoreState *)*state)->input);
}

u16 GetHardwareHeldKeys(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.held;
}

u32 GetHardwarePressedKeys(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.pressed;
}

u32 GetHardwareRepeatedKeys(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.repeated;
}

struct HardwareCoreState * GetHardwareCoreState(void * const * state)
{
    return *state;
}

void SetHardwareRepeatDelay(void * const * state, u16 value)
{
    SetHardwareKeyRepeatDelay(&((struct HardwareCoreState *)*state)->input, value);
}

void SetHardwareRepeatInterval(void * const * state, u16 value)
{
    SetHardwareKeyRepeatInterval(&((struct HardwareCoreState *)*state)->input, value);
}

u16 GetHardwareRepeatDelay(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.repeat_delay;
}

u16 GetHardwareRepeatInterval(void * const * state)
{
    return ((struct HardwareCoreState *)*state)->input.repeat_interval;
}

struct HardwareDmaQueue * GetHardwareDmaQueue(void * const * state)
{
    return &((struct HardwareCoreState *)*state)->dma_queue;
}

struct HardwareDisplayState * GetHardwareDisplayState(void * const * state)
{
    return &((struct HardwareCoreState *)*state)->display;
}

struct HardwareSpriteBufferState * GetHardwareSpriteBuffer(void * const * state)
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

u8 * GetHardwareCommandList(void * const * state)
{
    return (u8 *)&((struct HardwareCoreState *)*state)->links;
}

u8 * GetHardwareInterruptList(void * const * state)
{
    return (u8 *)func_08008AE0(&((struct HardwareCoreState *)*state)->manager);
}

u8 * func_08008960(void * const * state)
{
    return (u8 *)&((struct HardwareCoreState *)*state)->links;
}

u8 * func_0800896C(void * const * state)
{
    return (u8 *)func_08008AE0(&((struct HardwareCoreState *)*state)->manager);
}
