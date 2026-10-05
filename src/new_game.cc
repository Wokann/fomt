#include "new_game.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend_object.hh"

static inline void QueueMenuBlend(HardwareBootstrap * core, HardwareBlendObject & blend)
{
    u8 * list = func_08008940(reinterpret_cast<void * const *>(core));
    void * const * vtable = *reinterpret_cast<void * const **>(list + 8);
    ((void (*)(u8 *, HardwareBlendObject *))vtable[4])(list, &blend);
}

static inline bool MenuBlendIsQueued(HardwareBlendObject const & blend)
{
    return blend.unk_00 != nullptr;
}

void func_08003B40(HardwareBootstrap * core)
{
    func_08008918(reinterpret_cast<void * const *>(core))->SetBlendControl(0x3F);
    HardwareBlendObject blend(func_08008918(reinterpret_cast<void * const *>(core)));
    i16 step = 0x889;
    func_0800934C(&blend.blend, step, 1, 1);
    QueueMenuBlend(core, blend);
    while (MenuBlendIsQueued(blend))
        UpdateHardwareFrame(core);
    func_080094B8(&blend, 2);
}

void func_08003BB4(HardwareBootstrap * core)
{
    func_08008918(reinterpret_cast<void * const *>(core))->SetBlendControl(0x3F);
    HardwareBlendObject blend(func_08008918(reinterpret_cast<void * const *>(core)));
    i16 step = 0x889;
    func_08009378(&blend.blend, step, 1, 1);
    QueueMenuBlend(core, blend);
    while (MenuBlendIsQueued(blend))
        UpdateHardwareFrame(core);
    func_080094B8(&blend, 2);
}
