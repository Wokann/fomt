#ifndef HARDWARE_BLEND_HH
#define HARDWARE_BLEND_HH

#include "prelude.h"

struct HardwareBlendState {
    u8 * register_base;
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

EXTERN_C

struct HardwareBlendController * func_08009300(struct HardwareBlendController * controller, u8 * register_base);
void func_08009324(struct HardwareBlendController * controller, u32 flags);
u8 * func_08009344(struct HardwareBlendController * controller, u8 * register_base);
void func_0800934C(struct HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic);
void func_08009378(struct HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic);
i16 func_080093A0(struct HardwareBlendController * controller, i16 step);
u32 func_080093AC(struct HardwareBlendController * controller);

EXTERN_C_END

#endif // HARDWARE_BLEND_HH
