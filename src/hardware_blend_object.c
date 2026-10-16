#include "hardware_blend_object.hh"
#include "hardware_linked_list.hh"

i16 func_080094A4(struct HardwareBlendController * controller)
{
    return controller->state->step;
}

u32 func_080094AC(struct HardwareBlendObject * object)
{
    return func_080093AC(&object->blend);
}

void func_080094B8(struct HardwareBlendObject * object, u32 flags)
{
    object->vtable = vtable_unk_080E5B80;
    func_08009324(&object->blend, 2);
    func_080098AC(object, flags);
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

struct HardwareBlendObject * func_08009548(struct HardwareBlendObject * object, struct HardwareDisplayState * display)
{
    object->unk_00 = 0;
    object->unk_04 = 0;
    object->vtable = vtable_unk_080E5B80;
    func_08009300(&object->blend, display);
    return object;
}

// This controller still uses a native ABI field view, not a recovered class.
void * const vtable_unk_080E5B80[] = {
    0,
    0,
    (void *)func_080094AC,
    (void *)func_080094B8,
};
