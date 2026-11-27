#ifndef HORSE_RACE_HH
#define HORSE_RACE_HH

#include "scene.hh"
#include "fomt_constants.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"
#include "ui_state.hh"
struct Animal;
struct Horse;
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

// Four boost probabilities per contestant, selected by position and gap.
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
#if defined(REGION_JP)
extern char const gText_HorseRace_TicketPurchaseEncouragement[];
#endif
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
    HorseRaceSpriteState(IndexedResourceProvider * provider, u32 index)
        : resource(provider, index, 256), parameters(), unk_34(0) {}

    IndexedResourceGroupResult FrameGroup() const
    {
        return resource.resource->GetGroupData(resource.CurrentGroupIndex());
    }

    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    IndexedResourceUpdateResult update_result;
    u8 unk_34;
};

// These entries start empty; the enclosing contestant setup allocates them.
struct HorseRaceContestantPaletteEntry : ObjPaletteCollectionEntry {
    HorseRaceContestantPaletteEntry() : ObjPaletteCollectionEntry(false) {}
};

struct HorseRaceContestantTiles {
    HorseRaceContestantTiles();

    ObjTileCollectionEntry tiles;
    HorseRaceContestantPaletteEntry palettes[2];
};

inline HorseRaceContestantTiles::HorseRaceContestantTiles()
    : tiles(5)
{
    for (u32 index = 0; index < 2; ++index)
        palettes[index].Reset();
}

// The four runners share 32 dust positions, with eight ring entries per lane.
// The native initializer updates the two signed 16-bit coordinate fields separately.
typedef i16 HorseRaceDustPoint[2];
enum HorseRaceDustCoordinate { HorseRaceDustX, HorseRaceDustY };

struct HorseRaceGlyph {
    i16 x;
    i16 y;
    i16 glyph_index;
    u16 priority;
} PACKED ALIGN(2);

// Race positions and velocities are signed 16.16 fixed-point values.
// The four probability bytes are selected by distance and the gap ahead.
struct HorseRaceRunner {
    i32 normal_speed;
    i32 boosted_speed;
    i32 acceleration;
    i32 deceleration;
    i32 speed;
    i32 x_fixed;
    i16 timer;
    i16 stamina;
    u8 stamina_recovery_ticks;
    u8 adequacy;
    u8 affection;
    u8 finishing_place;
    u16 contestant_name_id;
    u16 boost_phase;
    u8 boost_probabilities[4];
    i16 odds;
    i16 ticket_count;
};


struct HorseRaceCore;

// Native helpers share these interfaces in all four regions. Their bodies
// retain the verified regional object layout and rendering differences.
struct HorseRaceSaveData;
extern "C" void PrepareHorseRaceEntries(HorseRaceSaveData *, bool, u32);
extern "C" void AdvanceHorseRaceRound(HorseRaceSaveData *, u32);
extern "C" bool AreHorseRacesComplete(HorseRaceSaveData *);
extern "C" void GenerateHorseRaceRoundEntries(HorseRaceSaveData *, u32);
extern "C" void InitializeHorseRaceTicketGraphics(HorseRaceCore *);
extern "C" void RenderHorseRaceTicketPurchaseScreen(HorseRaceCore *, i32);
extern "C" void LoadHorseRaceTicketControls(HorseRaceCore *);
extern "C" void BuildHorseRaceTicketGlyphs(HorseRaceCore *, i32);
extern "C" void AppendHorseRaceNumber(HorseRaceCore *, i32, i32, u32, i32, i32, i32);
extern "C" void AppendHorseRaceGlyph(HorseRaceCore *, i32, i32, i32, u32);
extern "C" void RenderHorseRaceTicketSprites(HorseRaceCore *);
extern "C" void InitializeHorseRaceBackground(HorseRaceCore *);
extern "C" void UpdateHorseRaceBackground(HorseRaceCore *);
extern "C" void LoadHorseRaceSpriteResources(HorseRaceCore *);
extern "C" void RenderHorseRaceSprites(HorseRaceCore *);
extern "C" void DrawHorseRaceContestantSprites(HorseRaceCore *, HardwareSpriteOamRecord const *,
    u32, IndexedResourceSpriteParameters const *, HorseRaceContestantTiles *);
extern "C" i32 UpdateHorseRaceRunners(HorseRaceCore *);

extern "C" i32 AdjustHorseRaceTicketQuantity(HorseRaceCore * core, i32 delta);
extern "C" void UpdateHorseRaceDialogue(HorseRaceCore * core);
extern "C" void InitializeHorseRaceRunners(HorseRaceCore * core);

struct HorseRaceCoreOwner {
    explicit HorseRaceCoreOwner(HorseRaceCore * core) : value(core) {}
    ~HorseRaceCoreOwner();
    HorseRaceCore * value;
private:
    HorseRaceCoreOwner(HorseRaceCoreOwner const &);
    HorseRaceCoreOwner & operator=(HorseRaceCoreOwner const &);
};

#pragma interface "horse_race.hh"
struct HorseRaceScene : AScene {
    HorseRaceScene(SceneTransitionOwner next, GameStateSaveImage * image, bool compete);
    virtual ~HorseRaceScene();
    virtual SceneTransitionOwner Run();

    HorseRaceCoreOwner core;
    SceneTransitionOwner continuation;
};

#pragma interface "horse_race.hh"
// FA is the one-based round number, FB the player's horse name, and FC-FF the four
// selected contestant names. Index 0x80 selects the player's horse name.
struct HorseRaceTextVariables : ScriptTextVariableStore {
    virtual ~HorseRaceTextVariables() {}
    virtual UiTextSubstitution Lookup(u32 code);
    u32 contestant_name_ids[4];
    i32 round_number;
    char const * player_horse_name;
};

#pragma interface "horse_race.hh"
struct HorseRaceCore : HardwareContext {
    HorseRaceCore(GameStateSaveImage * image, bool compete);
    SceneTransitionOwner Run();
    GameStateSaveImage * save;
    u32 unk_00C;
    GameSceneTalkWindowOwner ui_state;
    HardwareMusicPlayerSlot music_1;
    HardwareMusicPlayerSlot music_0;
    HardwareMusicPlayerSlot music_2;
    IndexedResourceArchive unk_archive_020;
    IndexedResourceArchive unk_archive_050;
    IndexedResourceArchive unk_archive_080;
    IndexedResourceArchive unk_archive_0B0;
    IndexedResourceArchive unk_archive_0E0;
    IndexedResourceArchive unk_archive_110;
    IndexedResourceArchive unk_archive_140;
    IndexedResourceArchive cursor_archive;
    IndexedResourceArchive actor_archive;
    HorseRaceSpriteState lane_marker;
    HorseRaceSpriteState runner_sprite_1;
    HorseRaceSpriteState runner_sprite_2;
    HorseRaceSpriteState runner_sprite_3;
    HorseRaceSpriteState runner_sprite_4;
    HorseRaceSpriteState player_runner_sprite;
    HorseRaceSpriteState stamina_indicator;
    HorseRaceSpriteState ticket_entry_marker;
    HorseRaceSpriteState runner_effect_1;
    HorseRaceSpriteState runner_effect_2;
    HorseRaceSpriteState runner_effect_3;
    HorseRaceSpriteState runner_effect_4;
    HorseRaceSpriteState boost_overlay_1;
    HorseRaceSpriteState boost_overlay_2;
    HorseRaceSpriteState boost_overlay_3;
    HorseRaceSpriteState boost_overlay_4;
    HorseRaceSpriteState ticket_cursor;
    HorseRaceSpriteState shared_runner_sprite;
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
    HorseRaceDustPoint dust_points[32];
#if defined(REGION_JP)
    HorseRaceGlyph glyphs[48];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    HorseRaceGlyph glyphs[148];
#endif
    i16 glyph_count;
    u16 runner_effect_tile_offsets[4];
    u16 runner_overlay_tile_offsets[4];
    // The ticket screen and the race background reuse this same work area.
    // Race unpack destinations are 0x100 bytes apart; readers can span those
    // destinations, so they are not independent 0x100-byte array objects.
    union PACKED ALIGN(2) {
        u16 ticket[32][32];
        u16 race[32 * 32];
    } background_tilemap;
    u16 background_x[3];
    u16 previous_background_x[3];
    i16 background_column[3];
    i16 finish_count;
    i16 finishing_order[4];
    i16 timer;
    i16 player_stamina_level;
    i16 selected_ticket;
    u16 unk_10EC;
    u8 player_competes_this_round;
    u32 money;
    u32 money_after_tickets;
    i32 medals;
    i16 round;
    i16 payout_remaining;
    i16 total_tickets;
    i16 payout_delay;
    i16 phase;
    bool showing_controls;
    u8 pause_flags;
    bool compete;
    u8 dialogue_state;
    u8 dialogue_choice;
    HorseRaceRunner runners[4];
    Horse * player_horse;
    HorseRaceTextVariables text_variables;
};

#pragma interface "horse_race.hh"

#pragma interface "horse_race.hh"


#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif
#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif
#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif

#pragma interface "horse_race.hh"


#pragma interface "horse_race.hh"

#pragma interface "horse_race.hh"

#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif

extern "C" {
extern u8 const gFarmStatusCreatureIcon11Tiles[];
extern u8 const gFarmStatusCreatureIcon11Palette[];
extern u8 const gAnimalFestivalIcon01Tiles[];
extern u8 const gAnimalFestivalIcon01Palette[];
extern u8 const gUiThreeLayerBackgroundTilemap0[];
extern u8 const gUiThreeLayerBackgroundTilemap1[];
extern u8 const gUiThreeLayerBackgroundTilemap2[];
extern u8 const gUiThreeLayerBackgroundTilemap3[];
extern u8 const gUiThreeLayerBackgroundTiles[];
extern u8 const gUiThreeLayerBackgroundPalette[];
}

extern "C" {
extern u8 const gUnk_0872EE78[];
extern u8 const gUnk_0873CCB4[];
extern u8 const gUnk_0873D234[];
extern u8 const gUnk_0873CF90[];
extern u8 const gUnk_0873DE44[];
extern u8 const gUnk_0873ED1C[];
extern u8 const gUnk_087401A4[];
extern u8 const gActorIndexedResourceArchive[];
}

#endif
