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
    HardwareBlendObject(HardwareDisplayState * display);
    virtual bool Run();
    // Member destruction and base unlinking use the compiler's native ABI.
    virtual ~HardwareBlendObject();
    // Step state, not linked-list membership; a queued command may finish.
    u32 IsActive() const;
    i16 GetStep() const;
    i16 SetStep(i16 step);
    void End(i16 step, u32 mode, u32 mosaic);
    void Begin(i16 step, u32 mode, u32 mosaic);
    HardwareDisplayState * SetDisplay(HardwareDisplayState * display);
#endif
};

typedef char HardwareBlendObject_size_check[(sizeof(struct HardwareBlendObject) == 0x10) ? 1 : -1];
typedef char HardwareBlendObject_payload_check[(offsetof(struct HardwareBlendObject, blend) == 0x0C) ? 1 : -1];

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
