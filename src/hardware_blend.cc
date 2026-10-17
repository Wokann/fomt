#include "hardware_blend.hh"

void * operator new(unsigned long);
void operator delete(void *);

HardwareBlendController::HardwareBlendController(HardwareDisplayState * display)
    : state(new HardwareBlendState(display))
{
}

HardwareBlendController::~HardwareBlendController()
{
    delete state;
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
