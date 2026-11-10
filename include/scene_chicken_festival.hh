#ifndef SCENE_CHICKEN_FESTIVAL_HH
#define SCENE_CHICKEN_FESTIVAL_HH

#include "hardware_blend_owner.hh"
#include "scene.hh"
#include "utility/fixed_str.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "hardware_blend.hh"
#include "scene.hh"
#include "ui_state.hh"
#include "resource_handle.hh"

struct GameStateSaveImage;

// The sprite borrows the archive's four resource ranges. Its resolved
// handle and drawing parameters are separate owned allocations.
struct ChickenFestivalSprite {
    IndexedResourceHandle * handle;
    IndexedResourceSpriteParameters * parameters;
    IndexedResourceGroupResult group;

    ~ChickenFestivalSprite()
    {
        delete parameters;
        delete handle;
    }
};

struct ChickenFestivalResourceHandleOwner {
    IndexedResourceHandle * value;
    ~ChickenFestivalResourceHandleOwner() { delete value; }
};

struct ChickenFestivalSpriteParametersOwner {
    IndexedResourceSpriteParameters * value;
    ~ChickenFestivalSpriteParametersOwner() { delete value; }
};

struct ChickenFestivalArchiveOwner {
    IndexedResourceArchive * value;
    ~ChickenFestivalArchiveOwner() { delete value; }
};

typedef char ChickenFestivalSpriteSizeCheck[sizeof(ChickenFestivalSprite) == 0x28 ? 1 : -1];
typedef char ChickenFestivalHandleOwnerSizeCheck[sizeof(ChickenFestivalResourceHandleOwner) == 4 ? 1 : -1];
typedef char ChickenFestivalParametersOwnerSizeCheck[sizeof(ChickenFestivalSpriteParametersOwner) == 4 ? 1 : -1];
typedef char ChickenFestivalArchiveOwnerSizeCheck[sizeof(ChickenFestivalArchiveOwner) == 4 ? 1 : -1];

#pragma interface "scene_chicken_festival.hh"

// Copied into the minigame's participant records. The old ARM ABI rounds
// FixedStr<12> to 16 bytes; year and affection are scalar byte fields.
struct ChickenFestivalEntrant {
    ChickenFestivalEntrant();
    FixedStr<12> name;
    u8 year;
    u8 affection;
};

struct ChickenFestivalMinigameCore;

struct ChickenFestivalMinigameScene : AScene {
    ChickenFestivalMinigameScene(ChickenFestivalEntrant const & entrant);
    virtual ~ChickenFestivalMinigameScene();
    virtual SceneTransitionOwner Run();
    bool HasWon() const;

    ChickenFestivalMinigameCore * core;
};

// Native allocation and constructor/destructor accesses verify this layout.
// Unrecovered fields remain RAM storage, not fabricated semantic objects.
struct ChickenFestivalMinigameCore : HardwareContext {
    ~ChickenFestivalMinigameCore();
    ChickenFestivalMinigameCore(ChickenFestivalEntrant const & entrant);
    bool HasWon() const;
    SceneTransitionOwner Run();
    void PrepareDisplay();
    void ResetRun();
    void UpdateUnkPhase0();
    void UpdateUnkPhase1();
    void UpdateUnkPhase2();
    void UpdateUnkPhase3();

    u8 unk_008;
    u8 unk_009[0x704 - 0x009];
    HardwareMusicPlayerSlot music_players[5];
    GameSceneTalkWindowOwner ui_state;
    ObjPaletteCollectionEntry palette_71C;
    ObjPaletteCollectionEntry palette_724;
    ObjPaletteCollectionEntry palettes_72C[2];
    ObjPaletteCollectionEntry palettes_73C[8];
    ChickenFestivalArchiveOwner archive_77C;
    ChickenFestivalArchiveOwner archive_780;
    ChickenFestivalArchiveOwner archive_784;
    ChickenFestivalArchiveOwner archive_788;
    ChickenFestivalArchiveOwner archive_78C;
    ChickenFestivalArchiveOwner archive_790;
    ChickenFestivalArchiveOwner archive_794;
    ChickenFestivalArchiveOwner archive_798;
    ChickenFestivalArchiveOwner archive_79C;
    HardwareBlendOwner blend;
    ChickenFestivalResourceHandleOwner handles_7A4[2];
    ChickenFestivalSpriteParametersOwner parameters_7AC[2];
    ChickenFestivalResourceHandleOwner handles_7B4[5];
    ChickenFestivalSpriteParametersOwner parameters_7C8[5];
    IndexedResourceGroupResult groups_7DC[5];
    ChickenFestivalResourceHandleOwner handles_87C[2];
    ChickenFestivalSpriteParametersOwner parameters_884[2];
    IndexedResourceGroupResult groups_88C[2];
    ChickenFestivalSprite sprite_8CC;
    ChickenFestivalSprite sprite_8F4;
    ChickenFestivalResourceHandleOwner handles_91C[2];
    ChickenFestivalSpriteParametersOwner parameters_924[2];
    IndexedResourceGroupResult groups_92C[2];
    ChickenFestivalSprite sprite_96C;
    ChickenFestivalSprite sprite_994;
    ChickenFestivalSprite sprite_9BC;
    ChickenFestivalResourceHandleOwner handle_9E4;
    ChickenFestivalSpriteParametersOwner parameters_9E8[2];
    IndexedResourceGroupResult groups_9F0[2];
    ChickenFestivalResourceHandleOwner handle_A30;
    ChickenFestivalSpriteParametersOwner parameters_A34[2];
    IndexedResourceGroupResult groups_A3C[2];
    ChickenFestivalSprite sprite_A7C;
    ChickenFestivalResourceHandleOwner handle_AA4;
    IndexedResourceGroupResult group_AA8;
    ChickenFestivalResourceHandleOwner handle_AC8;
    IndexedResourceGroupResult group_ACC;
    ChickenFestivalSpriteParametersOwner parameters_AEC[10];
    i32 phase;
    u32 unk_B18;
    ChickenFestivalEntrant unk_B1C;
    bool won;
    u8 unk_B31;
    bool finished;
    u8 unk_B33[0xB78 - 0xB33];
};

typedef char ChickenFestivalMinigameCoreSizeCheck[sizeof(ChickenFestivalMinigameCore) == 0xB78 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreFlagCheck[offsetof(ChickenFestivalMinigameCore, unk_008) == 8 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreMusicCheck[offsetof(ChickenFestivalMinigameCore, music_players) == 0x704 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreUiStateCheck[offsetof(ChickenFestivalMinigameCore, ui_state) == 0x718 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreEntrantCheck[offsetof(ChickenFestivalMinigameCore, unk_B1C) == 0xB1C ? 1 : -1];
typedef char ChickenFestivalMinigameCoreBlendCheck[offsetof(ChickenFestivalMinigameCore, blend) == 0x7A0 ? 1 : -1];
typedef char ChickenFestivalMinigameCorePhaseCheck[offsetof(ChickenFestivalMinigameCore, phase) == 0xB14 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreFinishedCheck[offsetof(ChickenFestivalMinigameCore, finished) == 0xB32 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreWinnerCheck[offsetof(ChickenFestivalMinigameCore, won) == 0xB30 ? 1 : -1];

typedef char ChickenFestivalMember77COffsetCheck[offsetof(ChickenFestivalMinigameCore, archive_77C) == 0x77C ? 1 : -1];
typedef char ChickenFestivalMember7A4OffsetCheck[offsetof(ChickenFestivalMinigameCore, handles_7A4) == 0x7A4 ? 1 : -1];
typedef char ChickenFestivalMember87COffsetCheck[offsetof(ChickenFestivalMinigameCore, handles_87C) == 0x87C ? 1 : -1];
typedef char ChickenFestivalMember91COffsetCheck[offsetof(ChickenFestivalMinigameCore, handles_91C) == 0x91C ? 1 : -1];
typedef char ChickenFestivalMember9E4OffsetCheck[offsetof(ChickenFestivalMinigameCore, handle_9E4) == 0x9E4 ? 1 : -1];
typedef char ChickenFestivalMemberA30OffsetCheck[offsetof(ChickenFestivalMinigameCore, handle_A30) == 0xA30 ? 1 : -1];
typedef char ChickenFestivalMemberAA4OffsetCheck[offsetof(ChickenFestivalMinigameCore, handle_AA4) == 0xAA4 ? 1 : -1];
typedef char ChickenFestivalMemberAECOffsetCheck[offsetof(ChickenFestivalMinigameCore, parameters_AEC) == 0xAEC ? 1 : -1];

typedef char ChickenFestivalEntrantSizeCheck[sizeof(ChickenFestivalEntrant) == 20 ? 1 : -1];
typedef char ChickenFestivalEntrantYearCheck[offsetof(ChickenFestivalEntrant, year) == 16 ? 1 : -1];
typedef char ChickenFestivalEntrantAffectionCheck[offsetof(ChickenFestivalEntrant, affection) == 17 ? 1 : -1];
typedef char ChickenFestivalMinigameSceneSizeCheck[sizeof(ChickenFestivalMinigameScene) == 8 ? 1 : -1];
typedef char ChickenFestivalMinigameSceneCoreCheck[offsetof(ChickenFestivalMinigameScene, core) == 4 ? 1 : -1];

enum
{
    CHICKEN_FESTIVAL_CONTESTANT_NAME_COUNT = 20,
    CHICKEN_FESTIVAL_CONTESTANT_NAME_WIDTH = 13,
};

extern char const gText_ChickenFestival_EmptyEntrantName[];
// Contestant names have twenty fixed-width thirteen-byte rows.
extern char const gText_ChickenFestival_ContestantNames[CHICKEN_FESTIVAL_CONTESTANT_NAME_COUNT][CHICKEN_FESTIVAL_CONTESTANT_NAME_WIDTH];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsAnnouncement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalRoundAnnouncement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationNo[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationYes[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Start[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Stop[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_WinnerSuffix[];
extern u16 const gUnk_HarvestSpriteMiniGameChickenFestivalValues[4][6];
extern u8 const gUnk_HarvestSpriteMiniGameChickenFestivalOffsets[4];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandYes[];
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandAgain[];
#endif
#if defined(REGION_DE)
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStartPageBreak[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStartPageBreak[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStartPageBreak[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_StartPageBreak[];
#endif
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Introduction[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Rules[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Encouragement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_CautionAtRingEdge[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_CautionLeavingRing[];
extern u32 const gUnk_080BAC9CValues[16];
extern u16 const gUnk_080BB890FirstValues[5];
extern u16 const gUnk_080BB890TableValues[4][4];
extern u16 const gUnk_080BB890LastValues[3];
extern u32 const gUnk_080BC288Values[16];


#endif // SCENE_CHICKEN_FESTIVAL_HH
