#ifndef FRISBEE_CORE_HH
#define FRISBEE_CORE_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"
#include "ui_state.hh"
#include "smart_ptr.hh"
#include "item.hh"

// Native core lookup tables. Unknown axes retain their existing labels.
extern u8 const gUnk_080FA246[];
extern u8 const gUnk_080FA264[];
extern u8 const gUnk_080FA2E8[];
extern u16 const gUnk_080FA36C[];
extern u8 const gAnimalFestivalRewardChanceWeights[];
extern u32 const gAnimalFestivalRewardArticleIds[];

// Static UI text used by the Frisbee practice and tournament flow.
extern char const gText_Frisbee_ExplanationQuestion[];
extern char const gText_Frisbee_Yes[];
extern char const gText_Frisbee_No[];
extern char const gText_Frisbee_ExplanationCursorTiming[];
extern char const gText_Frisbee_ExplanationGreenZone[];
extern char const gText_Frisbee_ExplanationRedZone[];
extern char const gText_Frisbee_ExplanationPractice[];
extern char const gText_Frisbee_ExplanationTournament[];
extern char const gText_Frisbee_ExplainAgain[];
extern char const gText_Frisbee_ThrowAgain[];
extern char const gText_Frisbee_TournamentFinished[];
extern char const gText_Frisbee_PlayAgain[];
extern char const gText_Frisbee_DogNoLongerWantsToPlay[];
extern char const gText_Frisbee_FoundItem[];
extern char const gText_Frisbee_FoundNothing[];

struct GameStateSaveImage;

// FF substitutes the Article found by the dog. The native variable store
// owns the 16-bit item ID; the returned substitution is limited to 31 bytes.
#pragma interface "frisbee.hh"
struct FrisbeeTextVariables : ScriptTextVariableStore {
    virtual ~FrisbeeTextVariables() {}
    virtual UiTextSubstitution Lookup(u32 code);
    u16 article_id;
};

// Eleven sprite records have a 0x38-byte stride. The word at +0x30 is not
// initialized by the constructor; its meaning is still unknown.
struct FrisbeeSpriteState {
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u32 unk_30;
    u8 unk_34;
};

struct FrisbeeSpriteTiles {
    ObjTileCollectionEntry tiles;
    ObjPaletteCollectionEntry palette;
};

struct FrisbeePalettePairTiles {
    ObjTileCollectionEntry tiles;
    ObjPaletteCollectionEntry palettes[2];
};

#pragma interface "frisbee.hh"

// Owned resources are released in reverse construction order. The remaining
// unknown RAM contains native game state, not invented padding or ROM data.
struct FrisbeeCore : HardwareContext {
    FrisbeeCore(GameStateSaveImage * image, bool contest);
    ~FrisbeeCore();
    SceneTransitionOwner Run();
    void UpdatePowerGauge(i32 power);
    GameStateSaveImage * save;
    u32 unk_00C;
    SmartPtr<UiStateOwner> ui_state;
    HardwareMusicPlayerSlot music_players[3];
    IndexedResourceArchive actor_archive;
    IndexedResourceArchive unk_archive_050;
    IndexedResourceArchive unk_archive_080;
    IndexedResourceArchive unk_archive_0B0;
    IndexedResourceArchive unk_archive_0E0;
    IndexedResourceArchive unk_archive_110;
    IndexedResourceArchive unk_archive_140;
    IndexedResourceArchive unk_archive_170;
    IndexedResourceArchive unk_archive_1A0;
    IndexedResourceArchive unk_archive_1D0;
    FrisbeeSpriteState sprites[11];
    ObjTileCollectionEntry tiles_468;
    ObjPaletteCollectionEntry palette_470;
    ObjTileCollectionEntry tiles_478;
    ObjPaletteCollectionEntry palette_480;
    ObjTileCollectionEntry tiles_488;
    ObjPaletteCollectionEntry palette_490;
    ObjTileCollectionEntry tiles_498;
    ObjPaletteCollectionEntry palette_4A0;
    ObjTileCollectionEntry tiles_4A8;
    ObjPaletteCollectionEntry palette_4B0;
    ObjTileCollectionEntry tiles_4B8;
    ObjPaletteCollectionEntry palette_4C0;
    ObjTileCollectionEntry tiles_4C8;
    ObjTileCollectionEntry tiles_4D0;
    ObjPaletteCollectionEntry palette_4D8;
    ObjTileCollectionEntry tiles_4E0;
    ObjPaletteCollectionEntry palette_4E8;
    ObjTileCollectionEntry tiles_4F0;
    ObjPaletteCollectionEntry palette_4F8;
    FrisbeeSpriteTiles sprite_tiles[4];
    FrisbeePalettePairTiles palette_pair_tiles;
    u8 unk_558[0x1D5A - 0x558];
    // Loaded by the background initializer and copied to BG screen block30.
    u16 background_tilemap[20][32];
    u8 unk_225A[0x22DC - 0x225A];
    u8 power_gauge_endpoint_y;
    u8 unk_22DD[0x23A0 - 0x22DD];
    FrisbeeTextVariables text_variables;
};

#pragma interface "frisbee.hh"

typedef char FrisbeeTextVariablesSizeCheck[sizeof(FrisbeeTextVariables) == 8 ? 1 : -1];
typedef char FrisbeeTextVariablesItemCheck[offsetof(FrisbeeTextVariables, article_id) == 4 ? 1 : -1];
typedef char FrisbeeSpriteStateSizeCheck[sizeof(FrisbeeSpriteState) == 0x38 ? 1 : -1];
typedef char FrisbeeSpriteTilesSizeCheck[sizeof(FrisbeeSpriteTiles) == 16 ? 1 : -1];
typedef char FrisbeePalettePairTilesSizeCheck[sizeof(FrisbeePalettePairTiles) == 24 ? 1 : -1];
typedef char FrisbeeCoreSpritesCheck[offsetof(FrisbeeCore, sprites) == 0x200 ? 1 : -1];
typedef char FrisbeeCoreTilesCheck[offsetof(FrisbeeCore, tiles_468) == 0x468 ? 1 : -1];
typedef char FrisbeeCoreSpriteTilesCheck[offsetof(FrisbeeCore, sprite_tiles) == 0x500 ? 1 : -1];
typedef char FrisbeeCorePalettePairCheck[offsetof(FrisbeeCore, palette_pair_tiles) == 0x540 ? 1 : -1];
typedef char FrisbeeCoreBackgroundTilemapCheck[offsetof(FrisbeeCore, background_tilemap) == 0x1D5A ? 1 : -1];
typedef char FrisbeeCoreGaugeEndpointCheck[offsetof(FrisbeeCore, power_gauge_endpoint_y) == 0x22DC ? 1 : -1];
typedef char FrisbeeCoreUnknownRamCheck[offsetof(FrisbeeCore, unk_558) == 0x558 ? 1 : -1];
typedef char FrisbeeCoreTextVariablesCheck[offsetof(FrisbeeCore, text_variables) == 0x23A0 ? 1 : -1];

typedef char FrisbeeCoreSizeCheck[sizeof(FrisbeeCore) == 0x23A8 ? 1 : -1];
typedef char FrisbeeCoreSaveCheck[offsetof(FrisbeeCore, save) == 8 ? 1 : -1];
typedef char FrisbeeCoreOffset_unk_00C[offsetof(FrisbeeCore, unk_00C) == 0xC ? 1 : -1];
typedef char FrisbeeCoreOffset_ui_state[offsetof(FrisbeeCore, ui_state) == 0x10 ? 1 : -1];
typedef char FrisbeeCoreOffset_music_players[offsetof(FrisbeeCore, music_players) == 0x14 ? 1 : -1];
typedef char FrisbeeCoreOffset_actor_archive[offsetof(FrisbeeCore, actor_archive) == 0x20 ? 1 : -1];
typedef char FrisbeeCoreOffset_unk_archive_050[offsetof(FrisbeeCore, unk_archive_050) == 0x50 ? 1 : -1];
typedef char FrisbeeCoreOffset_unk_archive_080[offsetof(FrisbeeCore, unk_archive_080) == 0x80 ? 1 : -1];


#endif // FRISBEE_CORE_HH
