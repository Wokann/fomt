#include "new_game.hh"
#include "new_game_data.hh"
#include "game_state.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend_object.hh"
#include "hardware_display_output.hh"
#include "hardware_interrupt_guard.hh"
#include "hardware_music_player.hh"
#include "sram_proxy_1.hh"
#include "ui_state.hh"
#include <string.h>

void * operator new(unsigned long);
void operator delete(void *);
inline void * operator new(unsigned long, void * location) { return location; }
inline void * operator new[](unsigned long, void * location) { return location; }

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
    UiStateOwner const * owner = &core->ui_state;
    MusicPlayer ** music = &core->music_players[0];
    owner->Update(state, sprites, display, links, manager, music);
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
    void * const * owner = reinterpret_cast<void * const *>(&core->ui_state);
    func_08050DC8(owner,
        reinterpret_cast<u32>(text != nullptr ? text : gText_NewGameMenu_Blank),
        0, 0);
}

bool func_08003F9C(NewGameMenuCore * core)
{
    if (core->unk_08 != nullptr) {
        u32 slot = core->choices[1];
        u32 offset = func_080003DC(reinterpret_cast<u32>(&core->sram), slot);
        u32 attempts = 3;
        do {
            InterruptGuard guard(0x1000);
            if (func_080115B0(core->unk_08, &core->sram, offset) == 0) {
                func_08003788(core, core->save_slot_status[slot], core->unk_08);
                func_08050DC8(reinterpret_cast<void * const *>(&core->ui_state),
                    reinterpret_cast<u32>(core->save_slot_status[slot].Data()), 0, 0);
                core->unk_8C = 3;
                func_08008B6C(&core->music_players[1], 0xC5);
                func_080003E8(&core->sram, slot);
                func_08000470(&core->sram, slot);
                return true;
            }
        } while (--attempts != 0);
    }
    func_08050DC8(reinterpret_cast<void * const *>(&core->ui_state),
        reinterpret_cast<u32>(gText_NewGameSave_SaveFailed), 0, 0);
    core->unk_8C = 3;
    func_08008B6C(&core->music_players[1], 0xC7);
    return false;
}

static inline SceneTransition * CreateLoadedMenuSaveTransition(NewGameLoadedSaveOwner & owner)
{
    NewGameLoadedSaveTransition * object = static_cast<NewGameLoadedSaveTransition *>(
        ::operator new(sizeof(NewGameLoadedSaveTransition)));
    object->vtable = vtable_unk_080E5A4C;
    object->state = owner.release();
    return reinterpret_cast<SceneTransition *>(object);
}

static inline void SetMenuContinuation(SceneTransitionOwner & owner, SceneTransition * next)
{
    if (next != owner.value)
        delete owner.value;
    owner.value = next;
}

bool func_080040A0(NewGameMenuCore * core)
{
    u32 slot = core->choices[1];
    u32 offset = func_080003DC(reinterpret_cast<u32>(&core->sram), slot);
    u32 status = 0;
    u32 attempts = 3;
    do {
        InterruptGuard guard(0x1000);
        NewGameLoadedSaveOwner loaded(func_08011650(::operator new(0x34F4),
            &core->sram, offset, &status));
        if (status == 0) {
            if (core->unk_08 != nullptr) {
                func_080D4480(core->unk_08, 2);
                if (core->unk_08 != nullptr)
                    func_080D4178(core->unk_08, loaded.get());
            } else {
                SetMenuContinuation(core->continuation, CreateLoadedMenuSaveTransition(loaded));
            }
            func_08008B6C(&core->music_players[1], 0xC5);
            func_08000470(&core->sram, slot);
            return true;
        }
        ::operator delete(loaded.release());
    } while (--attempts != 0);

    func_08050DC8(reinterpret_cast<void * const *>(&core->ui_state),
        reinterpret_cast<u32>(gText_NewGameSave_LoadFailed), 0, 0);
    core->unk_8C = 3;
    func_08008B6C(&core->music_players[1], 0xC7);
    return false;
}

static inline GameDisplayOptions const & SavedDisplayOptions(void const * image)
{
    return static_cast<GameStateSaveImage const *>(image)->display_options;
}

static inline void CopySavedDisplayOptions(GameDisplayOptions & destination,
    void const * image)
{
    destination = SavedDisplayOptions(image);
}

static inline NewGameMenuSpriteAttributes const & MenuSpriteAttributes(
    HardwareSpriteOamRecord const & attributes)
{
    return reinterpret_cast<NewGameMenuSpriteAttributes const &>(attributes);
}

static inline void SetInitialChoices(NewGameMenuCore * core,
    GameDisplayOptions const & options)
{
    core->choices[2] = options.control_scheme == 1;
    func_08003DF0(core, 2, MenuSpriteAttributes(core->option_attributes));
    core->choices[3] = !options.show_clock;
    func_08003DF0(core, 3, MenuSpriteAttributes(core->option_attributes));
    core->choices[4] = !options.show_portrait;
    func_08003DF0(core, 4, MenuSpriteAttributes(core->option_attributes));
    core->choices[5] = !options.show_nameplate;
    func_08003DF0(core, 5, MenuSpriteAttributes(core->option_attributes));
}

static inline bool HasSaveSlot(SramAccess & access, u32 slot)
{
    return (1 << slot) & func_080003A0(&access);
}

static inline u32 SpriteTileIndex(HardwareStateEntry & entry)
{
    return GetHardwareSharedStateTileIndex(&entry, entry.handle);
}

static inline u32 SpritePaletteBank(HardwareResourceEntry & entry)
{
    return func_080074C0(&entry, entry.handle);
}

NewGameMenuCore * func_080041DC(NewGameMenuCore * core, void * state,
    SceneTransition *& continuation)
{
    HardwareSpriteBufferParameters buffers(7, 0);
    func_08008574(core, &buffers);
    core->vtable = reinterpret_cast<void **>(
        const_cast<NewGameSceneVTableFunction *>(vtable_unk_080E5A5C));
    core->unk_08 = state;
    SceneTransition * next = continuation;
    continuation = nullptr;
    core->continuation.value = next;
    {
        HardwareStateOwner shared;
        HardwareResource resources;
        new (&core->ui_state) UiStateOwner(0, 31, 15, 0, shared, resources);
    }
    func_08008B54(&core->music_players[0], 1);
    func_08008B54(&core->music_players[1], 2);
    new (&core->resources) IndexedResourceArchive(gUiHandCursorArchive);
    new (&core->state_entry) HardwareStateEntry(2);
    new (&core->resource_entry) HardwareResourceEntry;
    HardwareSpriteOamRecord initial_sprite = {};
    core->option_attributes = initial_sprite;
    new (&core->selector_resource) IndexedResourceHandle(
        reinterpret_cast<IndexedResourceProvider *>(&core->resources), 0, 256);
    core->active_row = 0;
    core->unk_8C = 0;
    func_08000640(&core->sram);
    new (core->save_slot_status) NewGameMenuSaveSlotStatus[2];
    new (core->saved_display_options) GameDisplayOptions[2];
    IndexedResourceGroupResult group = core->resources.GetGroupData(0);
    core->option_attributes = group.sprites.Data()[0];
    core->option_attributes.tile_index = SpriteTileIndex(core->state_entry);
    core->option_attributes.palette_bank = SpritePaletteBank(core->resource_entry);
    core->option_attributes.mosaic = 1;
    core->selector_attributes = core->option_attributes;
    for (u32 slot = 0; slot < 2; ++slot) {
        if (HasSaveSlot(core->sram, slot)) {
            u32 offset = func_080003DC(reinterpret_cast<u32>(&core->sram), slot);
            u32 status = 0;
            int retries = 3;
            do {
                NewGameLoadedSaveOwner loaded(func_08011650(
                    ::operator new(sizeof(GameStateSaveImage)), &core->sram,
                    offset, &status));
                if (status == 0) {
                    func_08003788(core, core->save_slot_status[slot], loaded.get());
                    CopySavedDisplayOptions(core->saved_display_options[slot], loaded.get());
                    break;
                }
                ::operator delete(loaded.release());
            } while (--retries != -1);
        }
    }
    u32 recent_slot = func_08000488(&core->sram);
    if (core->unk_08 != nullptr) {
        core->choices[0] = 0;
        core->choices[1] = recent_slot != 0;
        SetInitialChoices(core, SavedDisplayOptions(core->unk_08));
    } else {
        core->active_row = 1;
        core->choices[0] = 1;
        core->choices[1] = recent_slot != 0;
        SetInitialChoices(core, core->saved_display_options[core->choices[1]]);
    }
    delete continuation;
    return core;
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
    scene->core = func_080041DC(
        static_cast<NewGameMenuCore *>(::operator new(sizeof(NewGameMenuCore))),
        nullptr, continuation);
    return reinterpret_cast<AScene *>(scene);
}

AScene * func_08004B94(void * object, void * state, SceneTransitionOwner continuation)
{
    NewGameMenuScene * scene = static_cast<NewGameMenuScene *>(object);
    scene->vtable = vtable_unk_080E5A68;
    SceneTransition * next = continuation.release();
    scene->core = func_080041DC(
        static_cast<NewGameMenuCore *>(::operator new(sizeof(NewGameMenuCore))),
        state, next);
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

NewGameIdentityScene * func_0800598C(NewGameIdentityScene * scene,
    char const * player_name, u32 birthday, char const * farm_name, char const * dog_name)
{
    scene->vtable = vtable_unk_080E5AA4;
    scene->core = func_08004EFC(static_cast<NewGameIdentityCore *>(
        ::operator new(sizeof(NewGameIdentityCore))), player_name, birthday, farm_name, dog_name);
    return scene;
}

void func_080059D0(NewGameIdentityScene * scene, int flags)
{
    scene->vtable = vtable_unk_080E5AA4;
    NewGameIdentityCore * core = scene->core;
    if (core != nullptr)
        ((void (*)(NewGameIdentityCore *, int))core->vtable[2])(core, 3);
    DestroySceneBase(reinterpret_cast<AScene *>(scene), flags);
}

SceneTransitionOwner func_08005A00(NewGameIdentityScene * scene)
{
    return func_080050F8(scene->core);
}

u8 func_08005A3C(NewGameIdentityScene const * scene)
{
    return scene->core->unk_1A76;
}

u8 func_08005A4C(NewGameIdentityCore const * core)
{
    return core->unk_1A76;
}
