#ifndef SCENE_WATERING_MINIGAME_HH
#define SCENE_WATERING_MINIGAME_HH

#include "hardware_blend_owner.hh"
#include "scene.hh"
#include "ui_state.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "hardware_blend.hh"
#include "resource_handle.hh"

struct HarvestSpriteWateringSetup {
    HarvestSpriteWateringSetup() : sprite_variant(3), experience(15) {}
    u32 sprite_variant;
    u8 experience;
};
typedef char HarvestSpriteWateringSetupSizeCheck[sizeof(HarvestSpriteWateringSetup) == 8 ? 1 : -1];

// Handles and drawing parameters are separately allocated. The four
// resource ranges borrow their archive payload and are not freed here.
struct WateringMinigameSprite {
    IndexedResourceHandle * handle;
    IndexedResourceSpriteParameters * parameters;
    IndexedResourceGroupResult group;

    WateringMinigameSprite()
        : handle(nullptr), parameters(nullptr),
          group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0) {}

    ~WateringMinigameSprite()
    {
        delete parameters;
        delete handle;
    }
};

struct WateringMinigameHandleOwner {
    IndexedResourceHandle * value;
    WateringMinigameHandleOwner() : value(nullptr) {}
    ~WateringMinigameHandleOwner() { delete value; }
};

struct WateringMinigameParametersOwner {
    IndexedResourceSpriteParameters * value;
    WateringMinigameParametersOwner() : value(nullptr) {}
    ~WateringMinigameParametersOwner() { delete value; }
};

// Each set shares one handle and has 25 independent drawing parameters.
// Reverse member destruction frees the parameters before the shared handle.
struct WateringMinigameSpriteSet {
    WateringMinigameSpriteSet()
        : group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0) {}
    WateringMinigameHandleOwner handle;
    WateringMinigameParametersOwner parameters[25];
    IndexedResourceGroupResult group;
};

struct WateringMinigameArchiveOwner {
    IndexedResourceArchive * value;
    WateringMinigameArchiveOwner(IndexedResourceArchive * archive) : value(archive) {}
    ~WateringMinigameArchiveOwner() { delete value; }
};

// The native constructor visits twelve independent handles in this order.
// Default construction and reverse destruction follow those real members.
#pragma interface "scene_watering_minigame.hh"
struct WateringMinigameTileHandles {
    WateringMinigameTileHandles();
    ~WateringMinigameTileHandles();
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
    ObjTileCollectionEntry unk_58;
};

typedef char WateringMinigameSpriteSizeCheck[sizeof(WateringMinigameSprite) == 0x28 ? 1 : -1];
typedef char WateringMinigameSpriteGroupCheck[offsetof(WateringMinigameSprite, group) == 8 ? 1 : -1];
typedef char WateringMinigameHandleOwnerSizeCheck[sizeof(WateringMinigameHandleOwner) == 4 ? 1 : -1];
typedef char WateringMinigameParametersOwnerSizeCheck[sizeof(WateringMinigameParametersOwner) == 4 ? 1 : -1];
typedef char WateringMinigameSpriteSetSizeCheck[sizeof(WateringMinigameSpriteSet) == 0x88 ? 1 : -1];
typedef char WateringMinigameSpriteSetParametersCheck[offsetof(WateringMinigameSpriteSet, parameters) == 4 ? 1 : -1];
typedef char WateringMinigameSpriteSetGroupCheck[offsetof(WateringMinigameSpriteSet, group) == 0x68 ? 1 : -1];
typedef char WateringMinigameArchiveOwnerSizeCheck[sizeof(WateringMinigameArchiveOwner) == 4 ? 1 : -1];
typedef char WateringMinigameTileHandlesSizeCheck[sizeof(WateringMinigameTileHandles) == 0x60 ? 1 : -1];

#pragma interface "scene_watering_minigame.hh"
// The native constructor calls HardwareContext, stores this class's vptr at
// +4, and owns the resources declared below. Unrecovered RAM fields remain
// explicit unknown storage. Owned members reproduce the native cleanup order.
struct HarvestSpriteWateringCore;

struct HarvestSpriteWateringUiScene : AScene {
    HarvestSpriteWateringUiScene(HarvestSpriteWateringSetup const & setup);
    virtual ~HarvestSpriteWateringUiScene();
    virtual SceneTransitionOwner Run();
    bool Succeeded();
    u32 GetUnkRecordValue();
    HarvestSpriteWateringCore * core;
};

struct HarvestSpriteWateringCore : HardwareContext {
    ~HarvestSpriteWateringCore();
    HarvestSpriteWateringCore(HarvestSpriteWateringSetup const & setup);
    bool Succeeded();
    SceneTransitionOwner Run();
    void PrepareDisplay();

    // Four-by-two tile buffers: one timer and the result rows.
    // Drawing starts at +4 in each 0x104-byte buffer; the prefix stays unk.
    UnkUiSelectionTileBuffer timer_tiles;
    UnkUiSelectionTileBuffer result_tiles[4];
    GameSceneTalkWindowOwner ui_state;
    WateringMinigameArchiveOwner archive_520;
    WateringMinigameArchiveOwner archive_524;
    WateringMinigameArchiveOwner archive_528;
    WateringMinigameArchiveOwner archive_52C;
    WateringMinigameArchiveOwner archive_530;
    WateringMinigameArchiveOwner archive_534;
    WateringMinigameArchiveOwner archive_538;
    WateringMinigameArchiveOwner archive_53C;
    WateringMinigameArchiveOwner archive_540;
    HardwareBlendOwner blend;
    u8 unk_548[8];
    WateringMinigameSprite sprite_550;
    WateringMinigameSprite sprite_578;
    WateringMinigameSprite sprite_5A0;
    WateringMinigameSprite sprite_5C8;
    WateringMinigameSprite sprite_5F0;
    WateringMinigameSpriteSet sprites_618;
    WateringMinigameSpriteSet sprites_6A0;
    WateringMinigameSprite sprite_728;
    WateringMinigameSprite sprite_750;
    u8 unk_778[0x20];
    WateringMinigameSprite sprite_798;
    WateringMinigameSprite sprite_7C0;
    WateringMinigameSprite sprite_7E8;
    HardwareMusicPlayerSlot music_player_0;
    HardwareMusicPlayerSlot music_player_1;
    HardwareMusicPlayerSlot music_player_2;
    HardwareMusicPlayerSlot music_player_3;
    HardwareMusicPlayerSlot music_player_4;
    HardwareSoundVSyncCommand sound_vsync;
    HardwareSoundMainCommand sound_main;
    WateringMinigameTileHandles tiles;
    u8 unk_89C[0x96A - 0x89C];
    bool succeeded;
    u8 unk_96B[0x974 - 0x96B];
    u32 unk_974;
    u8 unk_978[0x980 - 0x978];
    u32 sprite_variant;
    u8 unk_984[0x988 - 0x984];
    u8 experience;
};

typedef char HarvestSpriteWateringCoreTimerTilesCheck[offsetof(HarvestSpriteWateringCore, timer_tiles) == 8 ? 1 : -1];
typedef char HarvestSpriteWateringCoreResultTilesCheck[offsetof(HarvestSpriteWateringCore, result_tiles) == 0x10C ? 1 : -1];

typedef char HarvestSpriteWateringCoreSizeCheck[sizeof(HarvestSpriteWateringCore) == 0x98C ? 1 : -1];
typedef char HarvestSpriteWateringCore_ui_state_check[offsetof(HarvestSpriteWateringCore, ui_state) == 0x51C ? 1 : -1];
typedef char HarvestSpriteWateringCore_archives_check[offsetof(HarvestSpriteWateringCore, archive_520) == 0x520 ? 1 : -1];
typedef char HarvestSpriteWateringCore_blend_check[offsetof(HarvestSpriteWateringCore, blend) == 0x544 ? 1 : -1];
typedef char HarvestSpriteWateringCore_music_player_0_check[offsetof(HarvestSpriteWateringCore, music_player_0) == 0x810 ? 1 : -1];
typedef char HarvestSpriteWateringCore_sound_vsync_check[offsetof(HarvestSpriteWateringCore, sound_vsync) == 0x824 ? 1 : -1];
typedef char HarvestSpriteWateringCore_sound_main_check[offsetof(HarvestSpriteWateringCore, sound_main) == 0x830 ? 1 : -1];
typedef char HarvestSpriteWateringCore_tiles_check[offsetof(HarvestSpriteWateringCore, tiles) == 0x83C ? 1 : -1];
typedef char HarvestSpriteWateringCore_succeeded_check[offsetof(HarvestSpriteWateringCore, succeeded) == 0x96A ? 1 : -1];
typedef char HarvestSpriteWateringCore_unk_974_check[offsetof(HarvestSpriteWateringCore, unk_974) == 0x974 ? 1 : -1];
typedef char HarvestSpriteWateringCore_sprite_variant_check[offsetof(HarvestSpriteWateringCore, sprite_variant) == 0x980 ? 1 : -1];
typedef char HarvestSpriteWateringCore_experience_check[offsetof(HarvestSpriteWateringCore, experience) == 0x988 ? 1 : -1];

typedef char WateringMinigameMember540Check[offsetof(HarvestSpriteWateringCore, archive_540) == 0x540 ? 1 : -1];
typedef char WateringMinigameMember550Check[offsetof(HarvestSpriteWateringCore, sprite_550) == 0x550 ? 1 : -1];
typedef char WateringMinigameMember5F0Check[offsetof(HarvestSpriteWateringCore, sprite_5F0) == 0x5F0 ? 1 : -1];
typedef char WateringMinigameMember618Check[offsetof(HarvestSpriteWateringCore, sprites_618) == 0x618 ? 1 : -1];
typedef char WateringMinigameMember6A0Check[offsetof(HarvestSpriteWateringCore, sprites_6A0) == 0x6A0 ? 1 : -1];
typedef char WateringMinigameMember728Check[offsetof(HarvestSpriteWateringCore, sprite_728) == 0x728 ? 1 : -1];
typedef char WateringMinigameMember750Check[offsetof(HarvestSpriteWateringCore, sprite_750) == 0x750 ? 1 : -1];
typedef char WateringMinigameMember798Check[offsetof(HarvestSpriteWateringCore, sprite_798) == 0x798 ? 1 : -1];
typedef char WateringMinigameMember7E8Check[offsetof(HarvestSpriteWateringCore, sprite_7E8) == 0x7E8 ? 1 : -1];

typedef char WateringMinigameMusicPlayer1Check[offsetof(HarvestSpriteWateringCore, music_player_1) == 0x814 ? 1 : -1];
typedef char WateringMinigameMusicPlayer2Check[offsetof(HarvestSpriteWateringCore, music_player_2) == 0x818 ? 1 : -1];
typedef char WateringMinigameMusicPlayer3Check[offsetof(HarvestSpriteWateringCore, music_player_3) == 0x81C ? 1 : -1];
typedef char WateringMinigameMusicPlayer4Check[offsetof(HarvestSpriteWateringCore, music_player_4) == 0x820 ? 1 : -1];

// The UI methods below still have native implementations with these actual ABIs.

typedef char HarvestSpriteWateringUiSceneSizeCheck[sizeof(HarvestSpriteWateringUiScene) == 8 ? 1 : -1];

extern u16 const gUnk_080C3B18Values[8][2];
extern char const gText_HarvestSpriteWatering_Zero[];
extern u32 const gUnk_080C3B18IndexValues[7];
extern char const gText_HarvestSpriteMiniGame_Watering_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_Watering_Yes[];
extern char const gText_HarvestSpriteMiniGame_Watering_No[];
extern char const gText_HarvestSpriteMiniGame_Watering_Introduction[];
extern char const gText_HarvestSpriteMiniGame_Watering_Instructions[];
extern char const gText_HarvestSpriteMiniGame_Watering_SuccessInstructions[];
extern char const gText_HarvestSpriteMiniGame_Watering_MistakeWarning[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_Watering_Start[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScorePrefix[];
#if defined(REGION_US) || defined(REGION_EU)
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreResultPrefix[];
#endif
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreSummary[];
extern u16 const gUnk_080C7B38Values[10];
extern u16 const gUnk_080C7B64Values[7];

extern u8 const gUnk_0873DE44[];

#if defined(REGION_JP)
extern u8 const gUnk_084C4718[];
extern u8 const gUnk_084C6708[];
extern u8 const gUnk_084C3764[];
extern u8 const gUnk_084C6A70[];
extern u8 const gUnk_084A3678[];
extern u8 const gUnk_084B1FCC[];
extern u8 const gUnk_084C3840[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern u8 const gUnk_0873E5B0[];
extern u8 const gUnk_087405A0[];
extern u8 const gUnk_0873D5FC[];
extern u8 const gUnk_08740908[];
extern u8 const gUnk_0871D51C[];
extern u8 const gUnk_0872BE64[];
extern u8 const gUnk_0873D6D8[];
#endif

#endif // SCENE_WATERING_MINIGAME_HH
