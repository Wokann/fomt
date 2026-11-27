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

enum HorseRacePrizeId {
    HORSE_RACE_PRIZE_JEWEL_OF_TRUTH = 0,
    HORSE_RACE_PRIZE_POWER_BERRY = 1,
    HORSE_RACE_PRIZE_FACIAL_PACK = 2,
    HORSE_RACE_PRIZE_SKIN_LOTION = 3,
    HORSE_RACE_PRIZE_SUNBLOCK = 4,
    HORSE_RACE_PRIZE_NECKLACE = 5,
    HORSE_RACE_PRIZE_BROOCH = 6,
    HORSE_RACE_PRIZE_DIAMOND = 7,
    HORSE_RACE_PRIZE_TRUFFLE = 8,
    HORSE_RACE_PRIZE_ADAMANTITE = 9,
    HORSE_RACE_PRIZE_DRESS = 10,
    HORSE_RACE_PRIZE_PERFUME = 11,
    HORSE_RACE_PRIZE_COUNT
};

enum {
    HORSE_RACE_PRIZE_MENU_COUNT = HORSE_RACE_PRIZE_ADAMANTITE + 1,
    HORSE_RACE_PRIZE_VISIBLE_ROWS = 8
};

// The prize name is an inline field in the original 20-byte catalog entry,
// followed by the medal cost.  It is not a pointer to separately stored text.
struct HorseRacePrize {
    char name[16];
    i16 medal_cost;
};


extern HorseRacePrize const gHorseRacePrizeCatalog[HORSE_RACE_PRIZE_COUNT];
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
extern u16 const gHorseRacePrizeItemIds[HORSE_RACE_PRIZE_COUNT];
struct HorseRacePrizeSpriteState {
    HorseRacePrizeSpriteState(IndexedResourceProvider * provider, u32 index)
        : resource(provider, index, 256), parameters(), unk_30(0) {}

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
// Native glyph records are halfword aligned; the tilemap following their
// count is a complete 32-by-32 screen block.
struct PACKED ALIGN(2) HorseRacePrizeGlyph {
    i16 x;
    i16 y;
    i16 glyph_index;
    u16 priority;
};
struct HorseRaceMedalExchangeCore : HardwareContext {
    HorseRaceMedalExchangeCore(GameStateSaveImage * image);
    SceneTransitionOwner Run();
    GameStateSaveImage * save;
    u32 unk_00C;
    GameSceneTalkWindowOwner ui_state;
    HardwareMusicPlayerSlot music_1;
    HardwareMusicPlayerSlot music_0;
    HardwareMusicPlayerSlot music_2;
    IndexedResourceArchive arrow_archive;
    IndexedResourceArchive cursor_archive;
    HorseRacePrizeSpriteState up_arrow;
    HorseRacePrizeSpriteState down_arrow;
    HorseRacePrizeSpriteState cursor;
    ObjTileCollectionEntry glyph_tiles;
    ObjPaletteCollectionEntry glyph_palette;
    ObjTileCollectionEntry arrow_tiles;
    ObjPaletteCollectionEntry arrow_palette;
    ObjTileCollectionEntry cursor_tiles;
    ObjPaletteCollectionEntry cursor_palette;
    u16 scroll_y;
    HorseRacePrizeGlyph glyphs[48];
    i16 glyph_count;
    u16 name_tilemap[32][32];
    i32 medals;
    i16 selection;
    i16 first_visible_row;
    i16 selected_prize;
    i16 phase;
    i16 dialogue_state;
    i16 dialogue_choice;
    u8 menu_prize_ids[HORSE_RACE_PRIZE_MENU_COUNT];
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


#pragma interface "horse_race_medal_exchange.hh"


// Direct ABI declaration of this compiler constructor, not a wrapper.
// Retained until ordinary owner-return lowering matches the native factory.
// The second argument is the actual single-word continuation transfer slot.
extern "C" HorseRaceMedalExchangeScene * __27HorseRaceMedalExchangeSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * storage, SceneTransition ** next, GameStateSaveImage * image);


extern u8 const gUnk_08527094[];

EXTERN_C
void UpdateHorseRacePrizeDialogue(HorseRaceMedalExchangeCore * core);
void InitializeHorseRacePrizeGraphics(HorseRaceMedalExchangeCore * core);
void InitializeHorseRacePrizeCatalogGraphics(HorseRaceMedalExchangeCore * core);
void BuildHorseRacePrizeGlyphs(HorseRaceMedalExchangeCore * core);
void AppendHorseRacePrizeNumber(HorseRaceMedalExchangeCore * core, i32 x, i32 y,
    i32 priority, i32 value, i32 digits, i32 suffix);
void AppendHorseRacePrizeGlyph(HorseRaceMedalExchangeCore * core, i32 x, i32 y,
    i32 glyph, i32 priority);
void RenderHorseRacePrizeSprites(HorseRaceMedalExchangeCore * core);
EXTERN_C_END

#endif // HORSE_RACE_MEDAL_EXCHANGE_HH
