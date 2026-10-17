#include "prelude.h"
#pragma implementation "hardware_blend_object.hh"
#include "hardware_blend_object.hh"

i16 func_080094A4(struct HardwareBlendController * controller)
{
    return controller->state->step;
}

bool HardwareBlendObject::Run()
{
    return blend.Update();
}

HardwareBlendObject::~HardwareBlendObject()
{
}

u32 func_080094E0(struct HardwareBlendObject * object)
{
    return func_080094A4(&object->blend) != 0;
}

i16 func_080094F8(struct HardwareBlendObject * object)
{
    return func_080094A4(&object->blend);
}

i16 func_08009508(struct HardwareBlendObject * object, i16 step)
{
    return func_080093A0(&object->blend, step);
}

void func_0800951C(struct HardwareBlendObject * object, i16 step, u32 mode, u32 mosaic)
{
    func_08009378(&object->blend, step, mode, mosaic);
}

void func_0800952C(struct HardwareBlendObject * object, i16 step, u32 mode, u32 mosaic)
{
    func_0800934C(&object->blend, step, mode, mosaic);
}

struct HardwareDisplayState * func_0800953C(struct HardwareBlendObject * object, struct HardwareDisplayState * display)
{
    return func_08009344(&object->blend, display);
}
