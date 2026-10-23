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

HardwareDisplayState * HardwareBlendController::SetDisplay(HardwareDisplayState * display)
{
    struct HardwareDisplayState * previous = this->state->display;
    this->state->display = display;
    return previous;
}

void BeginHardwareBlend(HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic)
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

void EndHardwareBlend(HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic)
{
    struct HardwareBlendState * state = controller->state;
    i32 magnitude = step < 0 ? -step : step;
    u8 enabled = mosaic != 0;
    state->step = magnitude;
    state->mode = mode;
    state->mosaic_enabled = enabled;
    state->progress = 0;
}

i16 HardwareBlendController::SetStep(i16 step)
{
    i16 previous = this->state->step;
    this->state->step = step;
    return previous;
}
