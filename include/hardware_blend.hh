#ifndef HARDWARE_BLEND_HH
#define HARDWARE_BLEND_HH

#include "hardware_display_state.hh"

// The ARM bank mixer reads only these ten bits. Each stored factor is
// one less than its actual weight (1..32); channels are divided by 32.
struct Rgb5BlendWeights {
    u32 first : 5;
    u32 second : 5;
};


struct HardwareBlendState {
    // Null selects the hardware registers instead of a display-state shadow.
    struct HardwareDisplayState * display;
    i16 step;
    u16 unk_06;
    u32 mode;
    u8 mosaic_enabled;
    u8 unk_0d;
    u16 progress;
#ifdef __cplusplus
    HardwareBlendState(HardwareDisplayState * value)
        : display(value), step(0), mode(0), mosaic_enabled(0), progress(0) {}
#endif
};

struct HardwareBlendController {
    struct HardwareBlendState * state;
#ifdef __cplusplus
    HardwareBlendController(HardwareDisplayState * display);
    ~HardwareBlendController();
    HardwareDisplayState * SetDisplay(HardwareDisplayState * display);
    // Begin decreases from full progress; End increases from zero.
    void Begin(i16 step, u32 mode, u32 mosaic);
    void End(i16 step, u32 mode, u32 mosaic);
    i16 SetStep(i16 step);
    i16 GetStep() const;
    bool Update();
#endif
};


EXTERN_C

void BlendRgb5PaletteBank(u16 * destination, u16 const * first, u16 const * second,
    struct Rgb5BlendWeights weights) __attribute__((long_call));

// Direction-specific implementations also called by native consumers.
void BeginHardwareBlend(struct HardwareBlendController *, i16 step, u32 mode, u32 mosaic);
void EndHardwareBlend(struct HardwareBlendController *, i16 step, u32 mode, u32 mosaic);

EXTERN_C_END

#ifdef __cplusplus
inline void HardwareBlendController::Begin(i16 step, u32 mode, u32 mosaic)
{
    BeginHardwareBlend(this, step, mode, mosaic);
}

inline void HardwareBlendController::End(i16 step, u32 mode, u32 mosaic)
{
    EndHardwareBlend(this, step, mode, mosaic);
}
#endif

#include "hardware_linked_list.hh"

#ifdef __cplusplus
#pragma interface "hardware_blend.hh"
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


#ifdef __cplusplus
inline HardwareBlendObject::HardwareBlendObject(HardwareDisplayState * display)
    : HardwareLinkBase(), blend(display)
{
}

// Restore ordinary inline emission for the following owner and its callers.

#endif

#endif // HARDWARE_BLEND_HH
