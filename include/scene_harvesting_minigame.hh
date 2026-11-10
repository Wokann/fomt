#ifndef SCENE_HARVESTING_MINIGAME_HH
#define SCENE_HARVESTING_MINIGAME_HH

#include "hardware_blend_owner.hh"
#include "scene.hh"
#include "ui_state.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "hardware_blend.hh"
#include "resource_handle.hh"

struct HarvestSpriteHarvestingSetup {
    HarvestSpriteHarvestingSetup() : sprite_variant(4), experience(18) {}
    u32 sprite_variant;
    u8 experience;
};
typedef char HarvestSpriteHarvestingSetupSizeCheck[sizeof(HarvestSpriteHarvestingSetup) == 8 ? 1 : -1];

// Each sprite owns a resolved resource handle and its drawing parameters.
// The four ranges borrow archive payload; only the first two pointers are freed.
struct HarvestingMinigameSprite {
    IndexedResourceHandle * handle;
    IndexedResourceSpriteParameters * parameters;
    IndexedResourceGroupResult group;

    ~HarvestingMinigameSprite()
    {
        delete parameters;
        delete handle;
    }
};

struct HarvestingMinigameArchiveOwner {
    IndexedResourceArchive * value;
    ~HarvestingMinigameArchiveOwner() { delete value; }
};

// These are nine individually constructed handles. Their native cleanup
// releases them from +0x40 back to +0x00; they are not a counted container.
struct HarvestingMinigameTileHandles {
    ~HarvestingMinigameTileHandles();
    ObjTileCollectionEntry unk_00;
    ObjTileCollectionEntry unk_08;
    ObjTileCollectionEntry unk_10;
    ObjTileCollectionEntry unk_18;
    ObjTileCollectionEntry unk_20;
    ObjTileCollectionEntry unk_28;
    ObjTileCollectionEntry unk_30;
    ObjTileCollectionEntry unk_38;
    ObjTileCollectionEntry unk_40;
};

typedef char HarvestingMinigameSpriteSizeCheck[sizeof(HarvestingMinigameSprite) == 0x28 ? 1 : -1];
typedef char HarvestingMinigameSpriteParametersCheck[offsetof(HarvestingMinigameSprite, parameters) == 4 ? 1 : -1];
typedef char HarvestingMinigameSpriteGroupCheck[offsetof(HarvestingMinigameSprite, group) == 8 ? 1 : -1];
typedef char HarvestingMinigameArchiveOwnerSizeCheck[sizeof(HarvestingMinigameArchiveOwner) == 4 ? 1 : -1];
typedef char HarvestingMinigameTileHandlesSizeCheck[sizeof(HarvestingMinigameTileHandles) == 0x48 ? 1 : -1];

#pragma interface "scene_harvesting_minigame.hh"
// The native constructor calls HardwareContext, stores this class's vptr at
// +4, and owns the resources declared below. Unrecovered RAM fields remain
// explicit unknown storage. Owned members reproduce the native cleanup order.
struct HarvestSpriteHarvestingCore;

struct HarvestSpriteHarvestingUiScene : AScene {
    HarvestSpriteHarvestingUiScene(HarvestSpriteHarvestingSetup const & setup);
    virtual ~HarvestSpriteHarvestingUiScene();
    virtual SceneTransitionOwner Run();
    bool Succeeded();
    u32 GetUnkRecordValue();
    HarvestSpriteHarvestingCore * core;
};

struct HarvestSpriteHarvestingCore : HardwareContext {
    ~HarvestSpriteHarvestingCore();
    HarvestSpriteHarvestingCore(HarvestSpriteHarvestingSetup const & setup);
    bool Succeeded();
    SceneTransitionOwner Run();
    void PrepareDisplay();

    // Four-by-two tile buffers: one timer and the result rows.
    // Drawing starts at +4 in each 0x104-byte buffer; the prefix stays unk.
    UnkUiSelectionTileBuffer timer_tiles;
    UnkUiSelectionTileBuffer result_tiles[3];
    GameSceneTalkWindowOwner ui_state;
    HarvestingMinigameArchiveOwner archive_41C;
    HarvestingMinigameArchiveOwner archive_420;
    HarvestingMinigameArchiveOwner archive_424;
    HarvestingMinigameArchiveOwner archive_428;
    HarvestingMinigameArchiveOwner archive_42C;
    HarvestingMinigameArchiveOwner archive_430;
    HarvestingMinigameArchiveOwner archive_434;
    HarvestingMinigameArchiveOwner archive_438;
    HardwareBlendOwner blend;
    u8 unk_440[0x20];
    HarvestingMinigameSprite sprite_460;
    HarvestingMinigameSprite sprite_488;
    HarvestingMinigameSprite sprite_4B0;
    HarvestingMinigameSprite sprite_4D8;
    HarvestingMinigameSprite sprite_500;
    HarvestingMinigameSprite sprite_528;
    HarvestingMinigameSprite sprite_550;
    HardwareMusicPlayerSlot music_players[4];
    HardwareSoundVSyncCommand sound_vsync;
    HardwareSoundMainCommand sound_main;
    u8 unk_5A0[0x5B0 - 0x5A0];
    HarvestingMinigameTileHandles tiles;
    u8 unk_5F8[0x604 - 0x5F8];
    u32 unk_604;
    u8 unk_608[0x610 - 0x608];
    bool succeeded;
    u8 unk_611[0x614 - 0x611];
    u32 sprite_variant;
    u8 unk_618[0x61C - 0x618];
    u8 experience;
};

typedef char HarvestSpriteHarvestingCoreTimerTilesCheck[offsetof(HarvestSpriteHarvestingCore, timer_tiles) == 8 ? 1 : -1];
typedef char HarvestSpriteHarvestingCoreResultTilesCheck[offsetof(HarvestSpriteHarvestingCore, result_tiles) == 0x10C ? 1 : -1];

typedef char HarvestSpriteHarvestingCoreSizeCheck[sizeof(HarvestSpriteHarvestingCore) == 0x620 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_ui_state_check[offsetof(HarvestSpriteHarvestingCore, ui_state) == 0x418 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_archives_check[offsetof(HarvestSpriteHarvestingCore, archive_41C) == 0x41C ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_blend_check[offsetof(HarvestSpriteHarvestingCore, blend) == 0x43C ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_music_players_check[offsetof(HarvestSpriteHarvestingCore, music_players) == 0x578 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_sound_vsync_check[offsetof(HarvestSpriteHarvestingCore, sound_vsync) == 0x588 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_sound_main_check[offsetof(HarvestSpriteHarvestingCore, sound_main) == 0x594 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_tiles_check[offsetof(HarvestSpriteHarvestingCore, tiles) == 0x5B0 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_unk_604_check[offsetof(HarvestSpriteHarvestingCore, unk_604) == 0x604 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_succeeded_check[offsetof(HarvestSpriteHarvestingCore, succeeded) == 0x610 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_sprite_variant_check[offsetof(HarvestSpriteHarvestingCore, sprite_variant) == 0x614 ? 1 : -1];
typedef char HarvestSpriteHarvestingCore_experience_check[offsetof(HarvestSpriteHarvestingCore, experience) == 0x61C ? 1 : -1];

typedef char HarvestingMinigameSprite460OffsetCheck[offsetof(HarvestSpriteHarvestingCore, sprite_460) == 0x460 ? 1 : -1];
typedef char HarvestingMinigameSprite550OffsetCheck[offsetof(HarvestSpriteHarvestingCore, sprite_550) == 0x550 ? 1 : -1];
typedef char HarvestingMinigameArchiveEndCheck[offsetof(HarvestSpriteHarvestingCore, archive_438) == 0x438 ? 1 : -1];

// The UI methods below still have native implementations with these actual ABIs.

typedef char HarvestSpriteHarvestingUiSceneSizeCheck[sizeof(HarvestSpriteHarvestingUiScene) == 8 ? 1 : -1];

extern char const gText_HarvestSpriteHarvesting_Zero[];
extern u32 const gUnk_080BE954Values[7];
extern char const gText_HarvestSpriteMiniGame_Harvest_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Yes[];
extern char const gText_HarvestSpriteMiniGame_Harvest_No[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Introduction[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Instructions[];
extern char const gText_HarvestSpriteMiniGame_Harvest_FatigueWarning[];
extern char const gText_HarvestSpriteMiniGame_Harvest_RestInstructions[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Start[];
extern char const gText_HarvestSpriteMiniGame_Harvest_ScorePrefix[];
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreResultPrefix[];
#endif
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreSummary[];
extern u16 const gUnk_080C09D8Values[11];
extern u16 const gUnk_080C0B58Values[7];

#endif // SCENE_HARVESTING_MINIGAME_HH
