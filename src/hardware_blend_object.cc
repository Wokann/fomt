#include "prelude.h"
#pragma implementation "hardware_blend_object.hh"
#include "hardware_blend_object.hh"

i16 HardwareBlendController::GetStep() const
{
    return this->state->step;
}

bool HardwareBlendObject::Run()
{
    return blend.Update();
}

HardwareBlendObject::~HardwareBlendObject()
{
}

u32 HardwareBlendObject::IsActive() const
{
    return blend.GetStep() != 0;
}

i16 HardwareBlendObject::GetStep() const
{
    return blend.GetStep();
}

i16 HardwareBlendObject::SetStep(i16 step)
{
    return blend.SetStep(step);
}

void HardwareBlendObject::End(i16 step, u32 mode, u32 mosaic)
{
    EndHardwareBlend(&blend, step, mode, mosaic);
}

void HardwareBlendObject::Begin(i16 step, u32 mode, u32 mosaic)
{
    BeginHardwareBlend(&blend, step, mode, mosaic);
}

HardwareDisplayState * HardwareBlendObject::SetDisplay(HardwareDisplayState * display)
{
    return blend.SetDisplay(display);
}
