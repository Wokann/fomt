#include "new_game_menu.hh"
#include "new_game_data.hh"
#include "hardware_state_accessors.hh"
#include "intro_scene.hh"
#include "game_scene.hh"
#include "hardware_blend_object.hh"
#include "hardware_interrupt_guard.hh"
#include "hardware_music_player.hh"
#include "sram_image.hh"
#include <string.h>

void * operator new(unsigned long);
void operator delete(void *);
inline void * operator new(unsigned long, void * location) { return location; }
inline void * operator new[](unsigned long, void * location) { return location; }

inline SceneOwner NewGameLoadedSaveTransition::CreateScene()
{
    return SceneOwner(new GameSceneScriptController(state));
}

extern NewGameMenuVTableEntry const gNewGameMenuCoreVTable[] = {
    nullptr, nullptr,
    reinterpret_cast<NewGameMenuVTableEntry>(DestroyNewGameMenuCore),
};

static inline void QueueMenuBlend(HardwareBootstrap * core, HardwareBlendObject & blend)
{
    HardwareLinkedList * list = reinterpret_cast<HardwareLinkedList *>(
        GetHardwareCommandList(reinterpret_cast<void * const *>(core)));
    list->Append(&blend);
}

static inline bool MenuBlendIsQueued(HardwareBlendObject const & blend)
{
    return blend.previous_slot != nullptr;
}

void RunNewGameMenuOpeningBlend(HardwareBootstrap * core)
{
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBlendControl(0x3F);
    HardwareBlendObject blend(GetHardwareDisplayState(reinterpret_cast<void * const *>(core)));
    i16 step = 0x889;
    BeginHardwareBlend(&blend.blend, step, 1, 1);
    QueueMenuBlend(core, blend);
    while (MenuBlendIsQueued(blend))
        UpdateHardwareFrame(core);
}

void RunNewGameMenuClosingBlend(HardwareBootstrap * core)
{
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBlendControl(0x3F);
    HardwareBlendObject blend(GetHardwareDisplayState(reinterpret_cast<void * const *>(core)));
    i16 step = 0x889;
    EndHardwareBlend(&blend.blend, step, 1, 1);
    QueueMenuBlend(core, blend);
    while (MenuBlendIsQueued(blend))
        UpdateHardwareFrame(core);
}

void UpdateNewGameMenuUi(NewGameMenuCore * core)
{
    void * const * hardware = reinterpret_cast<void * const *>(core);
    HardwareCoreState * state = static_cast<HardwareCoreState *>(GetHardwareCoreState(hardware));
    HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(hardware);
    HardwareDisplayState * display = GetHardwareDisplayState(hardware);
    u8 * links = GetHardwareCommandList(hardware);
    u8 * manager = GetHardwareInterruptList(hardware);
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

void SubmitNewGameMenuChoiceSprite(NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes attributes)
{
    attributes.y += 8 + (row * 2 + 1) * 8;
    attributes.x += core->choices[row] != 0 ? 192 : 128;
    if (row == 1 && core->active_row != 1)
        attributes.affine_mode = 2;

    HardwareSpriteBufferState * buffer = GetHardwareSpriteBuffer(
        reinterpret_cast<void * const *>(core));
    StoreMenuSpriteAttributes(buffer, row, attributes);
}

void SubmitNewGameMenuCursorSprite(NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes const initial)
{
    if (row == 1)
        row = 0;
    NewGameMenuSpriteAttributes attributes = initial;
    attributes.y += 8 + (row * 2 + 1) * 8;
    attributes.x += 16;

    HardwareSpriteBufferState * buffer = GetHardwareSpriteBuffer(
        reinterpret_cast<void * const *>(core));
    StoreMenuSpriteAttributes(buffer, 6, attributes);
}

void UpdateNewGameMenuStatusText(NewGameMenuCore * core)
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

bool TrySaveNewGameMenuSlot(NewGameMenuCore * core)
{
    if (core->current_save != nullptr) {
        u32 slot = core->choices[1];
        u32 offset = GetSramSaveSlotOffset(&core->sram, slot);
        u32 attempts = 3;
        do {
            InterruptGuard guard(0x1000);
            if (WriteGameStateSaveImage(core->current_save, &core->sram, offset) == 0) {
                FormatNewGameSaveSlotSummary(core, core->save_slot_status[slot],
                    core->current_save);
                func_08050DC8(reinterpret_cast<void * const *>(&core->ui_state),
                    reinterpret_cast<u32>(core->save_slot_status[slot].Data()), 0, 0);
                core->phase = NEW_GAME_MENU_NOTICE;
                func_08008B6C(&core->music_players[1], 0xC5);
                MarkSramSaveSlotPresent(&core->sram, slot);
                SetLastUsedSramSaveSlot(&core->sram, slot);
                return true;
            }
        } while (--attempts != 0);
    }
    func_08050DC8(reinterpret_cast<void * const *>(&core->ui_state),
        reinterpret_cast<u32>(gText_NewGameSave_SaveFailed), 0, 0);
    core->phase = NEW_GAME_MENU_NOTICE;
    func_08008B6C(&core->music_players[1], 0xC7);
    return false;
}

static inline SceneTransition * CreateLoadedMenuSaveTransition(GameStateSaveImageOwner & owner)
{
    return new NewGameLoadedSaveTransition(owner);
}

static inline void SetMenuContinuation(SceneTransitionOwner & owner, SceneTransition * next)
{
    if (next != owner.get())
        delete owner.get();
    owner.value = next;
}

bool TryLoadNewGameMenuSlot(NewGameMenuCore * core)
{
    u32 slot = core->choices[1];
    u32 offset = GetSramSaveSlotOffset(&core->sram, slot);
    u32 status = 0;
    u32 attempts = 3;
    do {
        InterruptGuard guard(0x1000);
        GameStateSaveImageOwner loaded(func_08011650(::operator new(sizeof(GameStateSaveImage)),
            &core->sram, offset, &status));
        if (status == 0) {
            if (core->current_save != nullptr) {
                core->current_save->~GameStateSaveImage();
                if (core->current_save != nullptr)
                    func_080D4178(core->current_save, loaded.get());
            } else {
                SetMenuContinuation(core->continuation, CreateLoadedMenuSaveTransition(loaded));
            }
            func_08008B6C(&core->music_players[1], 0xC5);
            SetLastUsedSramSaveSlot(&core->sram, slot);
            return true;
        }
        ::operator delete(loaded.release());
    } while (--attempts != 0);

    func_08050DC8(reinterpret_cast<void * const *>(&core->ui_state),
        reinterpret_cast<u32>(gText_NewGameSave_LoadFailed), 0, 0);
    core->phase = NEW_GAME_MENU_NOTICE;
    func_08008B6C(&core->music_players[1], 0xC7);
    return false;
}

static inline GameDisplayOptions const & SavedDisplayOptions(GameStateSaveImage const * image)
{
    return image->display_options;
}

static inline void CopySavedDisplayOptions(GameDisplayOptions & destination,
    GameStateSaveImage const * image)
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
    // The selector stores byte-valued choices; keep boolean extraction in
    // that width before inverting the display options.
    core->choices[2] = options.control_scheme == 1;
    SubmitNewGameMenuChoiceSprite(core, 2, MenuSpriteAttributes(core->option_attributes));
    core->choices[3] = !static_cast<u8>(options.show_clock);
    SubmitNewGameMenuChoiceSprite(core, 3, MenuSpriteAttributes(core->option_attributes));
    core->choices[4] = !static_cast<u8>(options.show_portrait);
    SubmitNewGameMenuChoiceSprite(core, 4, MenuSpriteAttributes(core->option_attributes));
    core->choices[5] = !static_cast<u8>(options.show_nameplate);
    SubmitNewGameMenuChoiceSprite(core, 5, MenuSpriteAttributes(core->option_attributes));
}

static inline bool HasSaveSlot(SramAccess & access, u32 slot)
{
    return (1 << slot) & GetSramSaveSlotMask(&access);
}

static inline u32 SpriteTileIndex(HardwareStateEntry & entry)
{
    return GetHardwareSharedStateTileIndex(&entry, entry.handle);
}

static inline u32 SpritePaletteBank(HardwareResourceEntry & entry)
{
    return GetHardwarePoolHandleIndex(&entry, entry.handle);
}

NewGameMenuCore * InitializeNewGameMenuCore(NewGameMenuCore * core, GameStateSaveImage * save,
    SceneTransition *& continuation)
{
    HardwareSpriteBufferParameters buffers(7, 0);
    func_08008574(core, &buffers);
    core->vtable = reinterpret_cast<void **>(
        const_cast<NewGameMenuVTableEntry *>(gNewGameMenuCoreVTable));
    core->current_save = save;
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
        &core->resources, 0, 256);
    core->active_row = 0;
    core->phase = NEW_GAME_MENU_SELECTION;
    new (&core->sram) SramAccess;
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
            u32 offset = GetSramSaveSlotOffset(&core->sram, slot);
            u32 status = 0;
            int retries = 3;
            do {
                GameStateSaveImageOwner loaded(func_08011650(
                    ::operator new(sizeof(GameStateSaveImage)), &core->sram,
                    offset, &status));
                if (status == 0) {
                    FormatNewGameSaveSlotSummary(core, core->save_slot_status[slot],
                        static_cast<GameStateSaveImage *>(loaded.get()));
                    CopySavedDisplayOptions(core->saved_display_options[slot], loaded.get());
                    break;
                }
                ::operator delete(loaded.release());
            } while (--retries != -1);
        }
    }
    u32 recent_slot = GetLastUsedSramSaveSlot(&core->sram);
    if (core->current_save != nullptr) {
        core->choices[0] = 0;
        core->choices[1] = recent_slot != 0;
        SetInitialChoices(core, SavedDisplayOptions(core->current_save));
    } else {
        core->active_row = 1;
        core->choices[0] = 1;
        core->choices[1] = recent_slot != 0;
        SetInitialChoices(core, core->saved_display_options[core->choices[1]]);
    }
    delete continuation;
    return core;
}

NewGameMenuScene::NewGameMenuScene()
{
    SceneTransition * continuation = new MenuIntroTransition;
    core = InitializeNewGameMenuCore(
        static_cast<NewGameMenuCore *>(::operator new(sizeof(NewGameMenuCore))),
        nullptr, continuation);
}

// Move out of the native input slot before constructing the menu core.
static inline SceneTransition * TakeMenuContinuation(SceneTransition *& source)
{
    SceneTransition * value = source;
    source = nullptr;
    return value;
}

NewGameMenuScene::NewGameMenuScene(GameStateSaveImage * save, SceneTransition *& continuation)
{
    SceneTransition * next = TakeMenuContinuation(continuation);
    core = InitializeNewGameMenuCore(
        static_cast<NewGameMenuCore *>(::operator new(sizeof(NewGameMenuCore))),
        save, next);
    delete continuation;
}

NewGameMenuScene::~NewGameMenuScene()
{
    NewGameMenuCore * object = core;
    if (object != nullptr)
        ((void (*)(NewGameMenuCore *, int))object->vtable[2])(object, 3);
}

SceneTransitionOwner NewGameMenuScene::Run()
{
    return RunNewGameMenuCore(core);
}

// The members and the bootstrap base unwind in reverse construction order.
NewGameMenuCore::~NewGameMenuCore()
{
}
