#ifndef HARDWARE_BLEND_OBJECT_HH
#define HARDWARE_BLEND_OBJECT_HH

#include "hardware_blend.hh"

struct HardwareBlendObject {
    void * unk_00;
    void * unk_04;
    void * const * vtable;
    struct HardwareBlendController blend;
};

EXTERN_C

i16 func_080094A4(struct HardwareBlendController * controller);
u32 func_080094AC(struct HardwareBlendObject * object);
void func_080094B8(struct HardwareBlendObject * object, u32 flags);
u32 func_080094E0(struct HardwareBlendObject * object);
i16 func_080094F8(struct HardwareBlendObject * object);
i16 func_08009508(struct HardwareBlendObject * object, i16 step);
void func_0800951C(struct HardwareBlendObject * object, i16 step, u32 mode, u32 mosaic);
void func_0800952C(struct HardwareBlendObject * object, i16 step, u32 mode, u32 mosaic);
u8 * func_0800953C(struct HardwareBlendObject * object, u8 * register_base);
struct HardwareBlendObject * func_08009548(struct HardwareBlendObject * object, u8 * register_base);

EXTERN_C_END

#endif // HARDWARE_BLEND_OBJECT_HH
