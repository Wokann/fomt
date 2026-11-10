#ifndef HORSE_RACE_HH
#define HORSE_RACE_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "scene.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"
#include "ui_state.hh"
struct Animal;
// The race generator, name renderer and race updater share these native tables.
struct AnimalFestivalRandomRangePair
{
    u32 first_minimum;
    u32 first_maximum;
    u32 second_minimum;
    u32 second_maximum;
};

extern AnimalFestivalRandomRangePair const gAnimalFestivalRandomRangePairs[];

enum
{
    ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_COUNT = 40,
    ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_WIDTH = 13,
};

// Direct-indexed fixed-width rows, not a pointer table.
extern char const gText_AnimalFestival_LivestockContestantNames[ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_COUNT][ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_WIDTH];

// Native code indexes each contestant row as four unclassified byte values.
extern u8 const gAnimalFestivalLivestockContestantValues[][4];
#include "font_decimal.hh"

#include "horse_race_medal_exchange.hh"


extern char const gText_HorseRace_BuyTicketDeclined[];
extern char const gText_HorseRace_Yes[];
extern char const gText_HorseRace_No[];
extern char const gText_HorseRace_ComeAgain[];
extern char const gText_HorseRace_TakeYourTime[];
extern char const gText_HorseRace_TicketPurchaseConfirmation[];
extern char const gText_HorseRace_TicketPurchaseApproval[];
extern char const gText_HorseRace_TicketPurchaseEncouragement[];
extern char const gText_HorseRace_ChangeMind[];
extern char const gText_HorseRace_ExplanationQuestion[];
extern char const gText_HorseRace_ExplanationBasics[];
extern char const gText_HorseRace_ExplanationGreenStamina[];
extern char const gText_HorseRace_ExplanationYellowStamina[];
extern char const gText_HorseRace_ExplanationRedStamina[];
extern char const gText_HorseRace_ExplanationStaminaRecovery[];
extern char const gText_HorseRace_ExplanationUnderstoodQuestion[];
extern char const gText_HorseRace_ExplanationUnderstood[];
extern char const gText_HorseRace_ExplanationRepeat[];
extern char const gText_HorseRace_StartRace[];
extern char const gText_HorseRace_RaceStartAnnouncement[];
extern char const gText_HorseRace_RaceResults[];
extern char const gText_HorseRace_RacePayouts[];
extern char const gText_HorseRace_MedalExchangeExplanation[];
// This ticket-rendering path reads one encoded glyph value at a time rather
// than a normal NUL-terminated text byte stream.
extern u16 const gHorseRaceTicketCharacterCodes[];
extern char const gText_HorseRace_TicketPurchaseTitle[];
extern char const gText_HorseRace_TicketPurchaseConfirm[];
extern char const gText_HorseRace_TicketPurchaseMedalsToWin[];
extern char const gText_HorseRace_TicketControls_DPadUpDown[];
extern char const gText_HorseRace_TicketControls_SelectHorse[];
extern char const gText_HorseRace_TicketControls_DPadLeftRight[];
extern char const gText_HorseRace_TicketControls_ChangeQuantity[];
extern char const gText_HorseRace_TicketControls_LRButtons[];
extern char const gText_HorseRace_TicketControls_ChangeQuantityByTen[];
extern char const gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation[];
extern char const gText_HorseRace_TicketControls_MoveCursorToConfirm[];
extern char const gText_HorseRace_TicketControls_Buy[];
extern char const gText_HorseRace_TicketControls_Cancel[];

extern char const * const gHorseRaceTicketControls[];

struct UiStateOwner;

struct GameStateSaveImage;

// The race uses eighteen 0x38-byte records; the exchange uses three
// 0x34-byte records. They have distinct native trailing fields.
struct HorseRaceSpriteState {
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u32 unk_30;
    u8 unk_34;
};


struct HorseRaceContestantTiles {
    ObjTileCollectionEntry tiles;
    ObjPaletteCollectionEntry palettes[2];
};

struct HorseRaceCore;

#pragma interface "horse_race.hh"
// The wrapper constructor, destructor, and Run body remain native assembly.
struct HorseRaceScene : AScene {
    HorseRaceScene(SceneTransitionOwner next, GameStateSaveImage * image, bool compete);
    virtual ~HorseRaceScene();
    virtual SceneTransitionOwner Run();

    HorseRaceCore * core;
    SceneTransitionOwner continuation;
};

#pragma interface "horse_race.hh"
// FA is the result amount, FB the player's horse name, and FC-FF the four
// selected contestant names. Index 0x80 selects the player's horse name.
struct HorseRaceTextVariables : ScriptTextVariableStore {
    virtual ~HorseRaceTextVariables() {}
    virtual UiTextSubstitution Lookup(u32 code);
    u32 contestant_name_ids[4];
    i32 result_amount;
    char const * player_horse_name;
};

#pragma interface "horse_race.hh"
struct HorseRaceCore : HardwareContext {
    HorseRaceCore(GameStateSaveImage * image, bool compete);
    SceneTransitionOwner Run();
    GameStateSaveImage * save;
    u32 unk_00C;
    GameSceneTalkWindowOwner ui_state;
    HardwareMusicPlayerSlot music_players[3];
    IndexedResourceArchive unk_archive_020;
    IndexedResourceArchive unk_archive_050;
    IndexedResourceArchive unk_archive_080;
    IndexedResourceArchive unk_archive_0B0;
    IndexedResourceArchive unk_archive_0E0;
    IndexedResourceArchive unk_archive_110;
    IndexedResourceArchive unk_archive_140;
    IndexedResourceArchive cursor_archive;
    IndexedResourceArchive actor_archive;
    HorseRaceSpriteState sprites[18];
    ObjTileCollectionEntry tiles_5C0;
    ObjPaletteCollectionEntry palette_5C8;
    ObjTileCollectionEntry tiles_5D0;
    ObjPaletteCollectionEntry palette_5D8;
    ObjTileCollectionEntry tiles_5E0;
    ObjPaletteCollectionEntry palette_5E8;
    ObjTileCollectionEntry tiles_5F0;
    ObjPaletteCollectionEntry palette_5F8;
    ObjTileCollectionEntry tiles_600;
    ObjPaletteCollectionEntry palette_608;
    ObjTileCollectionEntry tiles_610;
    ObjPaletteCollectionEntry palette_618;
    ObjPaletteCollectionEntry palette_620;
    ObjTileCollectionEntry tiles_628;
    ObjTileCollectionEntry tiles_630;
    ObjPaletteCollectionEntry palette_638;
    ObjTileCollectionEntry tiles_640;
    ObjPaletteCollectionEntry palette_648;
    ObjTileCollectionEntry tiles_650;
    HorseRaceContestantTiles contestant_tiles[4];
#if defined(REGION_JP)
    u8 unk_6B8[0x11BC - 0x6B8];
#else
    u8 unk_6B8[0x14DC - 0x6B8];
#endif
    Animal * player_horse;
    HorseRaceTextVariables text_variables;
};

#pragma interface "horse_race.hh"

#pragma interface "horse_race.hh"

typedef char HorseRaceTextVariablesSizeCheck[sizeof(HorseRaceTextVariables) == 0x1C ? 1 : -1];
typedef char HorseRaceTextVariablesNamesCheck[offsetof(HorseRaceTextVariables, contestant_name_ids) == 4 ? 1 : -1];
typedef char HorseRaceTextVariablesAmountCheck[offsetof(HorseRaceTextVariables, result_amount) == 0x14 ? 1 : -1];
typedef char HorseRaceTextVariablesPlayerCheck[offsetof(HorseRaceTextVariables, player_horse_name) == 0x18 ? 1 : -1];

typedef char HorseRaceSpriteStateSizeCheck[sizeof(HorseRaceSpriteState) == 0x38 ? 1 : -1];
typedef char HorseRaceContestantTilesSizeCheck[sizeof(HorseRaceContestantTiles) == 24 ? 1 : -1];
#if defined(REGION_JP)
typedef char HorseRaceCoreSizeCheck[sizeof(HorseRaceCore) == 0x11DC ? 1 : -1];
#else
typedef char HorseRaceCoreSizeCheck[sizeof(HorseRaceCore) == 0x14FC ? 1 : -1];
#endif
typedef char HorseRaceCoreUiCheck[offsetof(HorseRaceCore, ui_state) == 0x10 ? 1 : -1];
typedef char HorseRaceCoreArchiveCheck[offsetof(HorseRaceCore, unk_archive_020) == 0x20 ? 1 : -1];
typedef char HorseRaceCoreCursorArchiveCheck[offsetof(HorseRaceCore, cursor_archive) == 0x170 ? 1 : -1];
typedef char HorseRaceCoreActorArchiveCheck[offsetof(HorseRaceCore, actor_archive) == 0x1A0 ? 1 : -1];
typedef char HorseRaceCoreSpritesCheck[offsetof(HorseRaceCore, sprites) == 0x1D0 ? 1 : -1];
typedef char HorseRaceCoreTilesCheck[offsetof(HorseRaceCore, tiles_5C0) == 0x5C0 ? 1 : -1];
typedef char HorseRaceCoreContestantTilesCheck[offsetof(HorseRaceCore, contestant_tiles) == 0x658 ? 1 : -1];
typedef char HorseRaceCoreUnknownRamCheck[offsetof(HorseRaceCore, unk_6B8) == 0x6B8 ? 1 : -1];
#if defined(REGION_JP)
typedef char HorseRaceCorePlayerHorseCheck[offsetof(HorseRaceCore, player_horse) == 0x11BC ? 1 : -1];
#else
typedef char HorseRaceCorePlayerHorseCheck[offsetof(HorseRaceCore, player_horse) == 0x14DC ? 1 : -1];
#endif
#if defined(REGION_JP)
typedef char HorseRaceCoreTextVariablesCheck[offsetof(HorseRaceCore, text_variables) == 0x11C0 ? 1 : -1];
#else
typedef char HorseRaceCoreTextVariablesCheck[offsetof(HorseRaceCore, text_variables) == 0x14E0 ? 1 : -1];
#endif

#pragma interface "horse_race.hh"

typedef char HorseRaceSceneSizeCheck[sizeof(HorseRaceScene) == 12 ? 1 : -1];
typedef char HorseRaceSceneCoreCheck[offsetof(HorseRaceScene, core) == 4 ? 1 : -1];
typedef char HorseRaceSceneContinuationCheck[offsetof(HorseRaceScene, continuation) == 8 ? 1 : -1];



#pragma interface "horse_race.hh"

#pragma interface "horse_race.hh"


#endif
