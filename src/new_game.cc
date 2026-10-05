#include "new_game.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend_object.hh"
#include "ui_state.hh"

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

void func_08003C28(NewGameMenuCore * core)
{
    void * const * hardware = reinterpret_cast<void * const *>(core);
    HardwareCoreState * state = static_cast<HardwareCoreState *>(func_080088DC(hardware));
    HardwareSpriteBufferState * sprites = func_08008920(hardware);
    HardwareDisplayState * display = func_08008918(hardware);
    u8 * links = func_08008940(hardware);
    u8 * manager = func_0800894C(hardware);
    u8 ** owner = &core->unk_10;
    MusicPlayer ** music = &core->music_players[0];
    func_08050D3C(owner, state, sprites, display, links, manager, music);
}
