#ifndef HARDWARE_BLEND_HH
#define HARDWARE_BLEND_HH

#include "hardware_display_output.hh"

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
    HardwareBlendController(HardwareDisplayState * display) asm("func_08009300");
    ~HardwareBlendController() asm("func_08009324");
    void Begin(i16 step, u32 mode, u32 mosaic);
    void End(i16 step, u32 mode, u32 mosaic);
    // The body remains native assembly; every exit returns false or true.
    bool Update();
#endif
};

typedef char HardwareBlendState_size_check[(sizeof(struct HardwareBlendState) == 0x10) ? 1 : -1];
typedef char HardwareBlendState_progress_offset_check[(offsetof(struct HardwareBlendState, progress) == 0x0E) ? 1 : -1];

EXTERN_C

void BlendRgb5PaletteBank(u16 * destination, u16 const * first, u16 const * second,
    struct Rgb5BlendWeights weights) __attribute__((long_call));

struct HardwareBlendController * func_08009300(struct HardwareBlendController * controller, struct HardwareDisplayState * display);
void func_08009324(struct HardwareBlendController * controller, u32 flags);
struct HardwareDisplayState * func_08009344(struct HardwareBlendController * controller, struct HardwareDisplayState * display);
void func_0800934C(struct HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic);
void func_08009378(struct HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic);
i16 func_080093A0(struct HardwareBlendController * controller, i16 step);

EXTERN_C_END

#ifdef __cplusplus
inline void HardwareBlendController::Begin(i16 step, u32 mode, u32 mosaic)
{
    func_0800934C(this, step, mode, mosaic);
}

inline void HardwareBlendController::End(i16 step, u32 mode, u32 mosaic)
{
    func_08009378(this, step, mode, mosaic);
}
#endif

#endif // HARDWARE_BLEND_HH
