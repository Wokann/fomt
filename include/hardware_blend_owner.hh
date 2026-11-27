#ifndef HARDWARE_BLEND_OWNER_HH
#define HARDWARE_BLEND_OWNER_HH

#include "hardware_blend.hh"

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


#endif // HARDWARE_BLEND_OWNER_HH
