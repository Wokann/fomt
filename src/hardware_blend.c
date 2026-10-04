#include "hardware_blend.hh"

extern void * __builtin_new(u32 size);
extern void __builtin_delete(void * pointer);

struct HardwareBlendController * func_08009300(struct HardwareBlendController * controller, struct HardwareDisplayState * display)
{
    struct HardwareBlendState * state = __builtin_new(sizeof(*state));
    state->display = display;
    state->step = 0;
    state->mode = 0;
    state->mosaic_enabled = 0;
    state->progress = 0;
    controller->state = state;
    return controller;
}

void func_08009324(struct HardwareBlendController * controller, u32 flags)
{
    __builtin_delete(controller->state);
    if (flags & 1)
        __builtin_delete(controller);
}

struct HardwareDisplayState * func_08009344(struct HardwareBlendController * controller, struct HardwareDisplayState * display)
{
    struct HardwareDisplayState * previous = controller->state->display;
    controller->state->display = display;
    return previous;
}

void func_0800934C(struct HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic)
{
    struct HardwareBlendState * state = controller->state;
    i32 magnitude = step < 0 ? -step : step;
    i16 signed_step = -magnitude;
    u8 enabled = mosaic != 0;
    state->step = signed_step;
    state->mode = mode;
    state->mosaic_enabled = enabled;
    state->progress = 0xffff;
}

void func_08009378(struct HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic)
{
    struct HardwareBlendState * state = controller->state;
    i32 magnitude = step < 0 ? -step : step;
    u8 enabled = mosaic != 0;
    state->step = magnitude;
    state->mode = mode;
    state->mosaic_enabled = enabled;
    state->progress = 0;
}

i16 func_080093A0(struct HardwareBlendController * controller, i16 step)
{
    i16 previous = controller->state->step;
    controller->state->step = step;
    return previous;
}
