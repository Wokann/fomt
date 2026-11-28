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
    void WaitForStart();

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
    u32 phase;
    u8 unk_5A4[0x5B0 - 0x5A4];
    HarvestingMinigameTileHandles tiles;
    u8 unk_5F8[0x604 - 0x5F8];
    u32 unk_604;
    u8 unk_608[0x610 - 0x608];
    bool succeeded;
    u8 unk_611[0x614 - 0x611];
    u32 sprite_variant;
    u32 unk_618;
    u8 experience;
};

// The UI methods below still have native implementations with these actual ABIs.

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
