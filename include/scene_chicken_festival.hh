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


#pragma interface "scene_chicken_festival.hh"

// Copied into the minigame's participant records. The old ARM ABI rounds
// FixedStr<12> to 16 bytes; year and affection are scalar byte fields.
struct ChickenFestivalEntrant {
    ChickenFestivalEntrant();
    FixedStr<12> name;
    u8 year;
    u8 affection;
};


// Per-slot record of the minigame's 0x40-byte stride array at +0x6C.
// Offsets proven by func_080B9F0C (+0x00 state, +0x08 value) and
// func_080B97FC (+0x14 flags, seen at +0x80 for slot 0 and +0xC0 for slot 1).
struct ChickenFestivalSlot {
    u32 state;                    /* +0x00 */
    u8 unk_04[4];                 /* +0x04 */
    u32 value;                    /* +0x08 */
    u8 unk_0C[0x14 - 0x0C];       /* +0x0C */
    u32 flags;                    /* +0x14 */
    u32 unk_18;                   /* +0x18, signed countdown */
    u8 unk_1C;                    /* +0x1C */
    u8 unk_1D[3];                 /* +0x1D */
    u16 unk_20;                   /* +0x20, scroll accumulator */
    u8 unk_22[0x26 - 0x22];       /* +0x22 */
    u8 unk_26;                    /* +0x26 */
    u8 unk_27[2];                 /* +0x27 */
    u8 unk_29;                    /* +0x29 */
    u16 unk_2A;                   /* +0x2A, resolved offset */
    u8 unk_2C[4];                 /* +0x2C, +0x2D used by the phase updater */
    u8 unk_30[0x40 - 0x30];       /* +0x30 */
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

    u32 unk_008;               /* +0x008, direction selector */
    u8 unk_00C[0x10 - 0x00C];  /* +0x00C */
    u32 unk_010;               /* +0x10, behaviour result */
    u8 unk_014[0x1E - 0x14];   /* +0x14 */
    u16 unk_1E;                /* +0x1E, vertical position */
    u16 unk_20;                /* +0x20, horizontal position */
    u8 unk_22;                 /* +0x22, selection bucket */
    u8 unk_23;                 /* +0x23, step */
    u8 unk_24[0x2F - 0x24];    /* +0x24 */
    u8 unk_2F;                 /* +0x2F, table selector */
    u8 unk_30[0x6C - 0x30];    /* +0x30 */
    ChickenFestivalSlot slots[26];  /* +0x6C, 0x40 bytes each, up to 0x6EC */
    u8 unk_6EC[0x704 - 0x6EC];
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
    u8 unk_B33[0xB35 - 0xB33];
    u8 unk_B35[5];             /* +0xB35 */
    u8 unk_B3A;                /* +0xB3A */
    u8 unk_B3B[0xB40 - 0xB3B]; /* +0xB3B */
    u32 unk_B40[2];            /* +0xB40, per-slot timers */
    u8 unk_B48[8];             /* +0xB48 */
    u32 unk_B50;               /* +0xB50 */
    u8 unk_B54[0xB5A - 0xB54]; /* +0xB54 */
    u8 unk_B5A;                /* +0xB5A */
    u8 unk_B5B[0xB78 - 0xB5B]; /* +0xB5B */
};




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
