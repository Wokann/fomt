#ifndef SCENE_ANIMAL_CARE_MINIGAME_HH
#define SCENE_ANIMAL_CARE_MINIGAME_HH

#include "hardware_blend_owner.hh"
#include "scene.hh"
#include "ui_state.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "hardware_blend.hh"
#include "resource_handle.hh"

struct HarvestSpriteAnimalCareSetup {
    HarvestSpriteAnimalCareSetup() : sprite_variant(2), experience(18) {}
    u32 sprite_variant;
    u8 experience;
};

// Resource ranges borrow their archive payload. Only the resolved handle
// and the separately allocated drawing parameters are owned by each sprite.
struct AnimalCareMinigameSprite {
    IndexedResourceHandle * handle;
    IndexedResourceSpriteParameters * parameters;
    IndexedResourceGroupResult group;

    ~AnimalCareMinigameSprite()
    {
        delete parameters;
        delete handle;
    }
};

struct AnimalCareMinigameResourceHandleOwner {
    IndexedResourceHandle * value;
    ~AnimalCareMinigameResourceHandleOwner() { delete value; }
};

struct AnimalCareMinigameSpriteParametersOwner {
    IndexedResourceSpriteParameters * value;
    ~AnimalCareMinigameSpriteParametersOwner() { delete value; }
};

struct AnimalCareMinigameArchiveOwner {
    IndexedResourceArchive * value;
    ~AnimalCareMinigameArchiveOwner() { delete value; }
};

// Native construction and cleanup visit these eleven handles individually.
struct AnimalCareMinigameTileHandles {
    ~AnimalCareMinigameTileHandles();
    ObjTileCollectionEntry unk_00;
    ObjTileCollectionEntry unk_08;
    ObjTileCollectionEntry unk_10;
    ObjTileCollectionEntry unk_18;
    ObjTileCollectionEntry unk_20;
    ObjTileCollectionEntry unk_28;
    ObjTileCollectionEntry unk_30;
    ObjTileCollectionEntry unk_38;
    ObjTileCollectionEntry unk_40;
    ObjTileCollectionEntry unk_48;
    ObjTileCollectionEntry unk_50;
};

#pragma interface "scene_animal_care_minigame.hh"
struct HarvestSpriteAnimalCareCore;

// The UI methods below still have native implementations with these actual ABIs.
struct HarvestSpriteAnimalCareUiScene : AScene {
    HarvestSpriteAnimalCareUiScene(HarvestSpriteAnimalCareSetup const & setup);
    virtual ~HarvestSpriteAnimalCareUiScene();
    virtual SceneTransitionOwner Run();
    bool Succeeded();
    u32 GetUnkRecordValue();
    HarvestSpriteAnimalCareCore * core;
};

// The native constructor calls HardwareContext, stores this class's vptr at
// +4, and owns the resources declared below. Unrecovered RAM fields remain
// explicit unknown storage. Owned members reproduce the native cleanup order.
struct HarvestSpriteAnimalCareCore : HardwareContext {
    ~HarvestSpriteAnimalCareCore();
    HarvestSpriteAnimalCareCore(HarvestSpriteAnimalCareSetup const & setup);
    bool Succeeded();
    SceneTransitionOwner Run();
    void RunInstructions();

    // Four-by-two tile buffers: one timer and the result rows.
    // Drawing starts at +4 in each 0x104-byte buffer; the prefix stays unk.
    UnkUiSelectionTileBuffer timer_tiles;
    UnkUiSelectionTileBuffer result_tiles[3];
    GameSceneTalkWindowOwner ui_state;
    AnimalCareMinigameArchiveOwner archive_41C;
    AnimalCareMinigameArchiveOwner archive_420;
    AnimalCareMinigameArchiveOwner archive_424;
    AnimalCareMinigameArchiveOwner archive_428;
    AnimalCareMinigameArchiveOwner archive_42C;
    AnimalCareMinigameArchiveOwner archive_430;
    AnimalCareMinigameArchiveOwner archive_434;
    AnimalCareMinigameArchiveOwner archive_438;
    HardwareBlendOwner blend;
    u8 unk_440[0x20];
    AnimalCareMinigameSprite sprite_460;
    AnimalCareMinigameSprite sprite_488;
    AnimalCareMinigameSprite sprite_4B0;
    AnimalCareMinigameSprite sprite_4D8;
    AnimalCareMinigameSprite sprite_500;
    AnimalCareMinigameSprite sprite_528;
    AnimalCareMinigameResourceHandleOwner handles_550[5];
    AnimalCareMinigameSpriteParametersOwner parameters_564[5];
    IndexedResourceGroupResult groups_578[5];
    AnimalCareMinigameResourceHandleOwner handles_618[5];
    AnimalCareMinigameSpriteParametersOwner parameters_62C[5];
    IndexedResourceGroupResult groups_640[5];
    AnimalCareMinigameSpriteParametersOwner parameters_6E0[5];
    AnimalCareMinigameResourceHandleOwner handles_6F4[5];
    AnimalCareMinigameSpriteParametersOwner parameters_708[5];
    IndexedResourceGroupResult groups_71C[5];
    AnimalCareMinigameSprite sprite_7BC;
    AnimalCareMinigameSprite sprite_7E4;
    HardwareMusicPlayerSlot music_players[5];
    HardwareSoundVSyncCommand sound_vsync;
    HardwareSoundMainCommand sound_main;
    u32 unk_838;
    u32 animations_paused;
    u32 unk_840;
    u32 selection_index;      /* +0x844, indexes the husbandry selection values */
    u32 unk_848[5];           /* +0x848, five zeroed words */
    i32 timers[5];            /* +0x85C, state timer per slot (1..2 means running) */
    u32 unk_870[5];           /* +0x870, five zeroed words */
    u32 match_index;          /* +0x884, husbandry match index (5 = none) */
    AnimalCareMinigameTileHandles tiles;
    u8 match_value;           /* +0x8E0, compared against the husbandry table */
    u8 unk_8E1[0xF]; /* unknown storage */
    u16 unk_8F0[5];           /* +0x8F0, zeroed per slot */
    u8 unk_8FA;               /* +0x8FA */
    u8 unk_8FB;               /* +0x8FB */
    u16 unk_8FC[5];           /* +0x8FC, zeroed per slot */
    u8 counters[5];           /* +0x906, counts up to 0x3C */
    u8 unk_90B[0x910 - 0x90B];
    u32 unk_910;
    u8 unk_914;               /* +0x914 */
    u8 unk_915[5];            /* +0x915, set to 1 per slot */
    u8 unk_91A[0x91F - 0x91A];
    u8 phase_flags[5];        /* +0x91F, set when a counter wraps */
    u8 unk_924[7];            /* +0x924 */
    u8 unk_92B;               /* +0x92B */
    bool succeeded;
    u8 unk_92D[0x930 - 0x92D];
    u32 sprite_variant;
    u32 unk_934;
    u8 experience;
};

extern u32 const gUnk_080AE894InitialValues[5];
extern u32 const gUnk_080AE894LayoutValues[10];
extern char const gText_HarvestSpriteAnimalCare_Zero[];
extern u32 const gUnk_080B09B0IndexValues[7];
extern u32 const gUnk_080B0BB8FirstValues[5];
extern u32 const gUnk_080B0BB8SecondValues[5];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Yes[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_No[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Introduction[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_FeedingInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ChickenBehaviorInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_WatchInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Start[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScorePrefix[];
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultPrefix[];
#endif
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreSummary[];
extern u8 const gUnk_HarvestSpriteMiniGameAnimalHusbandryMatchValues[5];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandrySelectionValues[4];

extern "C" void PauseAnimalCareAnimations(HarvestSpriteAnimalCareCore * core);
extern "C" void ResumeAnimalCareAnimations(HarvestSpriteAnimalCareCore * core);

extern "C" u16 func_080B3990(HarvestSpriteAnimalCareCore * self);
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues0[3];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues1[5];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues2[3];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues3[7];

#endif // SCENE_ANIMAL_CARE_MINIGAME_HH
