#ifndef HARDWARE_BLEND_OBJECT_HH
#define HARDWARE_BLEND_OBJECT_HH

#include "hardware_blend.hh"
#include "hardware_linked_list.hh"

#ifdef __cplusplus
#pragma interface "hardware_blend_object.hh"
#endif

struct HardwareBlendObject
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void * const * vtable;
#endif
    struct HardwareBlendController blend;
#ifdef __cplusplus
    HardwareBlendObject(HardwareDisplayState * display) asm("func_08009548");
    virtual bool Run() asm("func_080094AC");
    // Member destruction and base unlinking use the compiler's native ABI.
    virtual ~HardwareBlendObject() asm("func_080094B8");
#endif
};

typedef char HardwareBlendObject_size_check[(sizeof(struct HardwareBlendObject) == 0x10) ? 1 : -1];
typedef char HardwareBlendObject_payload_check[(offsetof(struct HardwareBlendObject, blend) == 0x0C) ? 1 : -1];

EXTERN_C

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
    : HardwareLinkBase(), blend(display)
{
}

// Restore ordinary inline emission for the following owner and its callers.
#pragma implementation

// One-word owner used by scenes while a blend command is on the hardware list.
struct HardwareBlendOwner {
    HardwareBlendObject * object;

    HardwareBlendOwner(HardwareBlendObject * value) : object(value) {}

    ~HardwareBlendOwner()
    {
        if (object != nullptr)
            delete object;
    }

    bool IsQueued() const { return object->previous_slot != nullptr; }
};

typedef char HardwareBlendOwner_size_check[(sizeof(HardwareBlendOwner) == 4) ? 1 : -1];
#endif

#endif // HARDWARE_BLEND_OBJECT_HH
