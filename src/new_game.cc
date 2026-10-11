#include "new_game.hh"
#include "new_game_data.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend_object.hh"
#include "hardware_display_output.hh"
#include "ui_state.hh"
#include <string.h>

void * operator new(unsigned long);

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

static inline void StoreMenuSpriteAttributes(HardwareSpriteBufferState * buffer,
    u32 index, NewGameMenuSpriteAttributes const & attributes)
{
    HardwareSpriteOamRecord * destination = &buffer->sprites[index & 0x7F];
    memcpy(destination, &attributes,
        offsetof(HardwareSpriteOamRecord, affine_coefficient));
}

void func_08003DF0(NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes attributes)
{
    attributes.y += 8 + (row * 2 + 1) * 8;
    attributes.x += core->choices[row] != 0 ? 192 : 128;
    if (row == 1 && core->active_row != 1)
        attributes.affine_mode = 2;

    HardwareSpriteBufferState * buffer = func_08008920(
        reinterpret_cast<void * const *>(core));
    StoreMenuSpriteAttributes(buffer, row, attributes);
}

void func_08003E88(NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes const initial)
{
    if (row == 1)
        row = 0;
    NewGameMenuSpriteAttributes attributes = initial;
    attributes.y += 8 + (row * 2 + 1) * 8;
    attributes.x += 16;

    HardwareSpriteBufferState * buffer = func_08008920(
        reinterpret_cast<void * const *>(core));
    StoreMenuSpriteAttributes(buffer, 6, attributes);
}

void func_08003EEC(NewGameMenuCore * core)
{
    char const * text = nullptr;
    switch (core->active_row) {
    case 0:
        text = core->choices[0] != 0 ? gText_NewGameStatus_ReadDiary :
            gText_NewGameStatus_WriteDiary;
        break;
    case 1: {
        bool empty = core->save_slot_status[core->choices[1]].IsEmpty();
        if (!empty)
            text = core->save_slot_status[core->choices[1]].Data();
        else
            text = gText_NewGameStatus_NoSavedData;
        break;
    }
    case 2:
        text = gText_NewGameHelp_Controls;
        break;
    case 3:
        text = gText_NewGameHelp_ClockDisplay;
        break;
    case 4:
        text = gText_NewGameHelp_FaceDisplay;
        break;
    case 5:
        text = gText_NewGameHelp_NameDisplay;
        break;
    }
    void * const * owner = reinterpret_cast<void * const *>(&core->unk_10);
    func_08050DC8(owner,
        reinterpret_cast<u32>(text != nullptr ? text : gText_NewGameMenu_Blank),
        0, 0);
}

static inline SceneTransition * CreateMenuIntroContinuation()
{
    NewGameSceneVTableFunction const ** object =
        static_cast<NewGameSceneVTableFunction const **>(::operator new(sizeof(SceneTransition)));
    *object = vtable_unk_080E5A3C;
    return reinterpret_cast<SceneTransition *>(object);
}

AScene * func_08004B58(void * object)
{
    NewGameMenuScene * scene = static_cast<NewGameMenuScene *>(object);
    scene->vtable = vtable_unk_080E5A68;
    SceneTransition * continuation = CreateMenuIntroContinuation();
    scene->core = func_080041DC(::operator new(sizeof(NewGameMenuCore)), nullptr,
        &continuation);
    return reinterpret_cast<AScene *>(scene);
}

AScene * func_08004B94(void * object, void * state, SceneTransitionOwner continuation)
{
    NewGameMenuScene * scene = static_cast<NewGameMenuScene *>(object);
    scene->vtable = vtable_unk_080E5A68;
    SceneTransition * next = continuation.release();
    scene->core = func_080041DC(::operator new(sizeof(NewGameMenuCore)), state, &next);
    return reinterpret_cast<AScene *>(scene);
}

void func_08004BDC(NewGameMenuScene * scene, int flags)
{
    scene->vtable = vtable_unk_080E5A68;
    NewGameMenuCore * core = scene->core;
    if (core != nullptr)
        ((void (*)(NewGameMenuCore *, int))core->vtable[2])(core, 3);
    DestroySceneBase(reinterpret_cast<AScene *>(scene), flags);
}

SceneTransitionOwner func_08004C0C(NewGameMenuScene * scene)
{
    return func_08004570(scene->core);
}

AScene * func_08004C48(void * object)
{
    NewGameNameEntryScene * scene = static_cast<NewGameNameEntryScene *>(object);
    scene->vtable = vtable_unk_080E5A88;
    return reinterpret_cast<AScene *>(scene);
}

void func_08004C54(NewGameNameEntryScene * scene, int flags)
{
    scene->vtable = vtable_unk_080E5A88;
    DestroySceneBase(reinterpret_cast<AScene *>(scene), flags);
}
