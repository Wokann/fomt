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
typedef char HarvestSpriteAnimalCareSetupSizeCheck[sizeof(HarvestSpriteAnimalCareSetup) == 8 ? 1 : -1];

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

typedef char AnimalCareMinigameSpriteSizeCheck[sizeof(AnimalCareMinigameSprite) == 0x28 ? 1 : -1];
typedef char AnimalCareMinigameHandleOwnerSizeCheck[sizeof(AnimalCareMinigameResourceHandleOwner) == 4 ? 1 : -1];
typedef char AnimalCareMinigameParametersOwnerSizeCheck[sizeof(AnimalCareMinigameSpriteParametersOwner) == 4 ? 1 : -1];
typedef char AnimalCareMinigameArchiveOwnerSizeCheck[sizeof(AnimalCareMinigameArchiveOwner) == 4 ? 1 : -1];
typedef char AnimalCareMinigameTileHandlesSizeCheck[sizeof(AnimalCareMinigameTileHandles) == 0x58 ? 1 : -1];

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
    u8 unk_838[0x888 - 0x838];
    AnimalCareMinigameTileHandles tiles;
    u8 unk_8E0[0x910 - 0x8E0];
    u32 unk_910;
    u8 unk_914[0x92C - 0x914];
    bool succeeded;
    u8 unk_92D[0x930 - 0x92D];
    u32 sprite_variant;
    u8 unk_934[0x938 - 0x934];
    u8 experience;
};

typedef char HarvestSpriteAnimalCareCoreTimerTilesCheck[offsetof(HarvestSpriteAnimalCareCore, timer_tiles) == 8 ? 1 : -1];
typedef char HarvestSpriteAnimalCareCoreResultTilesCheck[offsetof(HarvestSpriteAnimalCareCore, result_tiles) == 0x10C ? 1 : -1];

typedef char HarvestSpriteAnimalCareCoreSizeCheck[sizeof(HarvestSpriteAnimalCareCore) == 0x93C ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_ui_state_check[offsetof(HarvestSpriteAnimalCareCore, ui_state) == 0x418 ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_archives_check[offsetof(HarvestSpriteAnimalCareCore, archive_41C) == 0x41C ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_blend_check[offsetof(HarvestSpriteAnimalCareCore, blend) == 0x43C ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_music_players_check[offsetof(HarvestSpriteAnimalCareCore, music_players) == 0x80C ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_sound_vsync_check[offsetof(HarvestSpriteAnimalCareCore, sound_vsync) == 0x820 ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_sound_main_check[offsetof(HarvestSpriteAnimalCareCore, sound_main) == 0x82C ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_tiles_check[offsetof(HarvestSpriteAnimalCareCore, tiles) == 0x888 ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_unk_910_check[offsetof(HarvestSpriteAnimalCareCore, unk_910) == 0x910 ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_succeeded_check[offsetof(HarvestSpriteAnimalCareCore, succeeded) == 0x92C ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_sprite_variant_check[offsetof(HarvestSpriteAnimalCareCore, sprite_variant) == 0x930 ? 1 : -1];
typedef char HarvestSpriteAnimalCareCore_experience_check[offsetof(HarvestSpriteAnimalCareCore, experience) == 0x938 ? 1 : -1];

typedef char AnimalCareMinigameMember460OffsetCheck[offsetof(HarvestSpriteAnimalCareCore, sprite_460) == 0x460 ? 1 : -1];
typedef char AnimalCareMinigameMember550OffsetCheck[offsetof(HarvestSpriteAnimalCareCore, handles_550) == 0x550 ? 1 : -1];
typedef char AnimalCareMinigameMember618OffsetCheck[offsetof(HarvestSpriteAnimalCareCore, handles_618) == 0x618 ? 1 : -1];
typedef char AnimalCareMinigameMember6E0OffsetCheck[offsetof(HarvestSpriteAnimalCareCore, parameters_6E0) == 0x6E0 ? 1 : -1];
typedef char AnimalCareMinigameMember7BCOffsetCheck[offsetof(HarvestSpriteAnimalCareCore, sprite_7BC) == 0x7BC ? 1 : -1];

typedef char HarvestSpriteAnimalCareUiSceneSizeCheck[sizeof(HarvestSpriteAnimalCareUiScene) == 8 ? 1 : -1];

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
#if !defined(REGION_JP)
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultPrefix[];
#endif
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreSummary[];
extern u8 const gUnk_HarvestSpriteMiniGameAnimalHusbandryMatchValues[5];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandrySelectionValues[4];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues0[3];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues1[5];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues2[3];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues3[7];

#endif // SCENE_ANIMAL_CARE_MINIGAME_HH
