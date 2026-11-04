#include "hardware_state_accessors.hh"
#include "hardware_nested_accessors.hh"
#include "hardware_input_repeat.hh"

void UpdateHardwareInput(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    UpdateHardwareKeyRepeat(&state->input);
}

u16 GetHardwareHeldKeys(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return state->input.held;
}

u32 GetHardwarePressedKeys(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return state->input.pressed;
}

u32 GetHardwareRepeatedKeys(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return state->input.repeated;
}

struct HardwareCoreState * GetHardwareCoreState(void * const * state_slot)
{
    return *state_slot;
}

void SetHardwareRepeatDelay(void * const * state_slot, u16 value)
{
    struct HardwareCoreState * state = *state_slot;
    SetHardwareKeyRepeatDelay(&state->input, value);
}

void SetHardwareRepeatInterval(void * const * state_slot, u16 value)
{
    struct HardwareCoreState * state = *state_slot;
    SetHardwareKeyRepeatInterval(&state->input, value);
}

u16 GetHardwareRepeatDelay(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return state->input.repeat_delay;
}

u16 GetHardwareRepeatInterval(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return state->input.repeat_interval;
}

struct HardwareDmaQueue * GetHardwareDmaQueue(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return &state->dma_queue;
}

struct HardwareDisplayState * GetHardwareDisplayState(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return &state->display;
}

struct HardwareSpriteBufferState * GetHardwareSpriteBuffer(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return &state->sprite_buffer;
}

struct HardwareDmaQueue * func_08008928(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return &state->dma_queue;
}

struct HardwareDisplayState * func_08008930(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return &state->display;
}

struct HardwareSpriteBufferState * func_08008938(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return &state->sprite_buffer;
}

struct HardwareLinkedList * GetHardwareCommandList(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return &state->links;
}

struct HardwareInterruptList * GetHardwareInterruptList(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return func_08008AE0(&state->manager);
}

struct HardwareLinkedList * func_08008960(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return &state->links;
}

struct HardwareInterruptList * func_0800896C(void * const * state_slot)
{
    struct HardwareCoreState * state = *state_slot;
    return func_08008AE0(&state->manager);
}
