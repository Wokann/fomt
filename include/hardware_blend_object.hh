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
    HardwareBlendObject(HardwareDisplayState * display) asm("func_08009548");
    // The native destructor accepts the old C++ allocation flags (2 on the
    // stack, 3 when deleting an owned command) and unlinks the command.
    ~HardwareBlendObject() asm("func_080094B8");
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
struct HardwareDisplayState * func_0800953C(struct HardwareBlendObject * object, struct HardwareDisplayState * display);
struct HardwareBlendObject * func_08009548(struct HardwareBlendObject * object, struct HardwareDisplayState * display);

EXTERN_C_END

#ifdef __cplusplus
inline HardwareBlendObject::HardwareBlendObject(HardwareDisplayState * display)
    : unk_00(nullptr), unk_04(nullptr), vtable(vtable_unk_080E5B80)
{
    func_08009300(&blend, display);
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
