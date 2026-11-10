#ifndef HORSE_RACE_MEDAL_EXCHANGE_HH
#define HORSE_RACE_MEDAL_EXCHANGE_HH

#include "scene.hh"
#include "fomt_constants.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"
#include "ui_state.hh"

struct GameStateSaveImage;

// The prize name is an inline field in the original 20-byte catalog entry,
// followed by the medal cost.  It is not a pointer to separately stored text.
struct HorseRacePrize {
    char name[16];
    u32 medal_cost;
};

extern HorseRacePrize const gHorseRacePrizeCatalog[];
extern char const gText_HorseRace_PrizeExchangePrompt[];
extern char const gText_HorseRace_PrizeExchangeYes[];
extern char const gText_HorseRace_PrizeExchangeNo[];
extern char const gText_HorseRace_PrizeExchangeComeAgain[];
extern char const gText_HorseRace_PrizeExchangeTakeYourTime[];
extern char const gText_HorseRace_PrizeSelectionConfirmation[];
extern char const gText_HorseRace_PrizeExchangeLeaveConfirmation[];
extern char const gText_HorseRace_PrizeExchangeInsufficientMedals[];
extern u16 const gHorseRacePrizeExchangeCharacterCodes[];
// One entry per gHorseRacePrizeCatalog entry. The native path distinguishes
// Article and Food values itself; the Power Berry slot retains its unused
// ITEM_ARTICLE_FLOWER_MOON_DROP placeholder because it has a dedicated branch.
extern u16 const gHorseRacePrizeItemIds[];
struct HorseRacePrizeSpriteState {
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u8 unk_30;
};

struct HorseRaceMedalExchangeCore;

struct HorseRaceMedalExchangeCoreOwner {
    explicit HorseRaceMedalExchangeCoreOwner(HorseRaceMedalExchangeCore * core) : value(core) {}
    ~HorseRaceMedalExchangeCoreOwner();
    HorseRaceMedalExchangeCore * operator->() const { return value; }
    HorseRaceMedalExchangeCore * value;
private:
    HorseRaceMedalExchangeCoreOwner(HorseRaceMedalExchangeCoreOwner const &);
    HorseRaceMedalExchangeCoreOwner & operator=(HorseRaceMedalExchangeCoreOwner const &);
};

#pragma interface "horse_race_medal_exchange.hh"
struct HorseRaceMedalExchangeScene : AScene {
    HorseRaceMedalExchangeScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~HorseRaceMedalExchangeScene();
    virtual SceneTransitionOwner Run();
    HorseRaceMedalExchangeCoreOwner core;
    SceneTransitionOwner continuation;
};

#pragma interface "horse_race_medal_exchange.hh"
struct HorseRacePrizeTextVariables : ScriptTextVariableStore {
    virtual ~HorseRacePrizeTextVariables() {}
    virtual inline UiTextSubstitution Lookup(u32 code);
    u32 prize_index;
};

#pragma interface "horse_race_medal_exchange.hh"
// The allocation bound and initialized prefix agree in all four native ROMs.
// unk_... is unparsed runtime storage, not padding or recovered ROM data.
struct HorseRaceMedalExchangeCore : HardwareContext {
    HorseRaceMedalExchangeCore(GameStateSaveImage * image);
    SceneTransitionOwner Run();
    GameStateSaveImage * save;
    u32 unk_00C;
    GameSceneTalkWindowOwner ui_state;
    HardwareMusicPlayerSlot music_players[3];
    IndexedResourceArchive unk_archive_020;
    IndexedResourceArchive cursor_archive;
    HorseRacePrizeSpriteState sprites[3];
    ObjTileCollectionEntry tiles_11C;
    ObjPaletteCollectionEntry palette_124;
    ObjTileCollectionEntry tiles_12C;
    ObjPaletteCollectionEntry palette_134;
    ObjTileCollectionEntry tiles_13C;
    ObjPaletteCollectionEntry palette_144;
    u8 unk_14C[0xAEC - 0x14C];
    HorseRacePrizeTextVariables text_variables;
};


#pragma interface "horse_race_medal_exchange.hh"
inline UiTextSubstitution HorseRacePrizeTextVariables::Lookup(u32 code)
{
    if (code == 0xFF)
        return UiTextSubstitution(true, FixedStr<31>(gHorseRacePrizeCatalog[prize_index].name));
    return UiTextSubstitution(false, FixedStr<31>());
}

#pragma interface "horse_race_medal_exchange.hh"
typedef char HorseRacePrizeTextVariablesSizeCheck[sizeof(HorseRacePrizeTextVariables) == 8 ? 1 : -1];
typedef char HorseRacePrizeTextVariablesIndexCheck[offsetof(HorseRacePrizeTextVariables, prize_index) == 4 ? 1 : -1];
typedef char HorseRacePrizeSpriteStateSizeCheck[sizeof(HorseRacePrizeSpriteState) == 0x34 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreSizeCheck[sizeof(HorseRaceMedalExchangeCore) == 0xAF4 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreSaveCheck[offsetof(HorseRaceMedalExchangeCore, save) == 8 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_unk_00C[offsetof(HorseRaceMedalExchangeCore, unk_00C) == 0xC ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_ui_state[offsetof(HorseRaceMedalExchangeCore, ui_state) == 0x10 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_music_players[offsetof(HorseRaceMedalExchangeCore, music_players) == 0x14 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_unk_archive_020[offsetof(HorseRaceMedalExchangeCore, unk_archive_020) == 0x20 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_cursor_archive[offsetof(HorseRaceMedalExchangeCore, cursor_archive) == 0x50 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreSpritesCheck[offsetof(HorseRaceMedalExchangeCore, sprites) == 0x80 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreTilesCheck[offsetof(HorseRaceMedalExchangeCore, tiles_11C) == 0x11C ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreUnknownRamCheck[offsetof(HorseRaceMedalExchangeCore, unk_14C) == 0x14C ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreTextVariablesCheck[offsetof(HorseRaceMedalExchangeCore, text_variables) == 0xAEC ? 1 : -1];

typedef char HorseRaceMedalExchangeCoreOwnerSizeCheck[sizeof(HorseRaceMedalExchangeCoreOwner) == 4 ? 1 : -1];

#pragma interface "horse_race_medal_exchange.hh"

typedef char HorseRaceMedalExchangeSceneSizeCheck[sizeof(HorseRaceMedalExchangeScene) == 12 ? 1 : -1];
typedef char HorseRaceMedalExchangeSceneCoreCheck[offsetof(HorseRaceMedalExchangeScene, core) == 4 ? 1 : -1];
typedef char HorseRaceMedalExchangeSceneContinuationCheck[offsetof(HorseRaceMedalExchangeScene, continuation) == 8 ? 1 : -1];

// Direct ABI declaration of this compiler constructor, not a wrapper.
// Retained until ordinary owner-return lowering matches the native factory.
// The second argument is the actual single-word continuation transfer slot.
extern "C" HorseRaceMedalExchangeScene * __27HorseRaceMedalExchangeSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * storage, SceneTransition ** next, GameStateSaveImage * image);

#endif // HORSE_RACE_MEDAL_EXCHANGE_HH
