#ifndef HARDWARE_BLEND_HH
#define HARDWARE_BLEND_HH

#include "hardware_display_state.hh"

// The ARM bank mixer reads only these ten bits. Each stored factor is
// one less than its actual weight (1..32); channels are divided by 32.
struct Rgb5BlendWeights {
    u32 first : 5;
    u32 second : 5;
};

typedef char Rgb5BlendWeightsSizeCheck[sizeof(struct Rgb5BlendWeights) == 4 ? 1 : -1];

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
    // The body remains native assembly; every exit returns false or true.
    bool Update();
#endif
};

typedef char HardwareBlendState_size_check[(sizeof(struct HardwareBlendState) == 0x10) ? 1 : -1];
typedef char HardwareBlendState_progress_offset_check[(offsetof(struct HardwareBlendState, progress) == 0x0E) ? 1 : -1];

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

#endif // HARDWARE_BLEND_HH
