#ifndef HARDWARE_BLEND_OBJECT_HH
#define HARDWARE_BLEND_OBJECT_HH

#include "hardware_blend.hh"

#ifdef __cplusplus
#pragma interface "hardware_blend_object.hh"
#endif

struct HardwareBlendObject {
    void * unk_00;
    void * unk_04;
    void * const * vtable;
    struct HardwareBlendController blend;
#ifdef __cplusplus
    HardwareBlendObject(u8 * register_base) asm("func_08009548");
#endif
};

typedef char HardwareBlendObject_size_check[(sizeof(struct HardwareBlendObject) == 0x10) ? 1 : -1];

EXTERN_C

extern void * const vtable_unk_080E5B80[];

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

#ifdef __cplusplus
inline HardwareBlendObject::HardwareBlendObject(u8 * register_base)
    : unk_00(nullptr), unk_04(nullptr), vtable(vtable_unk_080E5B80)
{
    func_08009300(&blend, register_base);
}

// One-word owner used by scenes while a blend command is on the hardware
// list.  The original virtual destructor takes the allocation flags too.
struct HardwareBlendOwner {
    HardwareBlendObject * object;

    HardwareBlendOwner(HardwareBlendObject * value) : object(value) {}

    ~HardwareBlendOwner()
    {
        if (object != nullptr)
            ((void (*)(HardwareBlendObject *, u32))object->vtable[3])(object, 3);
    }

    bool IsQueued() const { return object->unk_00 != nullptr; }
};

typedef char HardwareBlendOwner_size_check[(sizeof(HardwareBlendOwner) == 4) ? 1 : -1];
#endif

#endif // HARDWARE_BLEND_OBJECT_HH
