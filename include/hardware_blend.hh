#ifndef HARDWARE_BLEND_HH
#define HARDWARE_BLEND_HH

#include "hardware_display_output.hh"

struct HardwareBlendState {
    // Null selects the hardware registers instead of a display-state shadow.
    struct HardwareDisplayState * display;
    i16 step;
    u16 unk_06;
    u32 mode;
    u8 mosaic_enabled;
    u8 unk_0d;
    u16 progress;
};

struct HardwareBlendController {
    struct HardwareBlendState * state;
};

typedef char HardwareBlendState_size_check[(sizeof(struct HardwareBlendState) == 0x10) ? 1 : -1];
typedef char HardwareBlendState_progress_offset_check[(offsetof(struct HardwareBlendState, progress) == 0x0E) ? 1 : -1];

EXTERN_C

struct HardwareBlendController * func_08009300(struct HardwareBlendController * controller, struct HardwareDisplayState * display);
void func_08009324(struct HardwareBlendController * controller, u32 flags);
struct HardwareDisplayState * func_08009344(struct HardwareBlendController * controller, struct HardwareDisplayState * display);
void func_0800934C(struct HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic);
void func_08009378(struct HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic);
i16 func_080093A0(struct HardwareBlendController * controller, i16 step);
u32 func_080093AC(struct HardwareBlendController * controller);

EXTERN_C_END

#endif // HARDWARE_BLEND_HH
