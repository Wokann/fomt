#ifndef SCENE_CHICKEN_FESTIVAL_HH
#define SCENE_CHICKEN_FESTIVAL_HH

#include "scene.hh"
#include "utility/fixed_str.hh"
#include "hardware_bootstrap.hh"
#include "hardware_music_player.hh"

struct GameStateSaveImage;

#pragma interface "scene_chicken_festival.hh"

// This scene runs the entered chicken through the contest and resumes the
// original world scene. The contest Run body remains native assembly.
struct ChickenFestivalContestScene : AScene {
    ChickenFestivalContestScene(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneTransitionOwner Run();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct ChickenFestivalContestTransition : SceneTransition {
    ChickenFestivalContestTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ChickenFestivalContestSceneSizeCheck[sizeof(ChickenFestivalContestScene) == 12 ? 1 : -1];
typedef char ChickenFestivalContestSceneContinuationCheck[offsetof(ChickenFestivalContestScene, continuation) == 4 ? 1 : -1];
typedef char ChickenFestivalContestSceneSaveCheck[offsetof(ChickenFestivalContestScene, save) == 8 ? 1 : -1];
typedef char ChickenFestivalContestTransitionSizeCheck[sizeof(ChickenFestivalContestTransition) == 12 ? 1 : -1];
typedef char ChickenFestivalContestTransitionContinuationCheck[offsetof(ChickenFestivalContestTransition, continuation) == 4 ? 1 : -1];
typedef char ChickenFestivalContestTransitionSaveCheck[offsetof(ChickenFestivalContestTransition, save) == 8 ? 1 : -1];

// Copied into the minigame's participant records. The old ARM ABI rounds
// FixedStr<12> to 16 bytes; year and affection are scalar byte fields.
struct ChickenFestivalEntrant {
    ChickenFestivalEntrant();
    FixedStr<12> name;
    u8 year;
    u8 affection;
};

struct UiStateOwner;

// Native allocation and constructor/destructor accesses verify this layout.
// Unrecovered fields remain RAM storage, not fabricated semantic objects.
struct ChickenFestivalMinigameCore : HardwareBootstrap {
    ChickenFestivalMinigameCore(ChickenFestivalEntrant const & entrant);
    virtual ~ChickenFestivalMinigameCore();
    bool HasWon() const;
    SceneTransitionOwner Run();

    u8 unk_008;
    u8 unk_009[0x704 - 0x009];
    HardwareMusicPlayerSlot music_players[5];
    UiStateOwner * ui_state;
    u8 unk_71C[0xB1C - 0x71C];
    ChickenFestivalEntrant unk_B1C;
    bool won;
    u8 unk_B31[0xB78 - 0xB31];
};

typedef char ChickenFestivalMinigameCoreSizeCheck[sizeof(ChickenFestivalMinigameCore) == 0xB78 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreFlagCheck[offsetof(ChickenFestivalMinigameCore, unk_008) == 8 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreMusicCheck[offsetof(ChickenFestivalMinigameCore, music_players) == 0x704 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreUiStateCheck[offsetof(ChickenFestivalMinigameCore, ui_state) == 0x718 ? 1 : -1];
typedef char ChickenFestivalMinigameCoreEntrantCheck[offsetof(ChickenFestivalMinigameCore, unk_B1C) == 0xB1C ? 1 : -1];
typedef char ChickenFestivalMinigameCoreWinnerCheck[offsetof(ChickenFestivalMinigameCore, won) == 0xB30 ? 1 : -1];

struct ChickenFestivalMinigameScene : AScene {
    ChickenFestivalMinigameScene(ChickenFestivalEntrant const & entrant);
    virtual ~ChickenFestivalMinigameScene();
    virtual SceneTransitionOwner Run();
    bool HasWon() const;

    ChickenFestivalMinigameCore * core;
};

typedef char ChickenFestivalEntrantSizeCheck[sizeof(ChickenFestivalEntrant) == 20 ? 1 : -1];
typedef char ChickenFestivalEntrantYearCheck[offsetof(ChickenFestivalEntrant, year) == 16 ? 1 : -1];
typedef char ChickenFestivalEntrantAffectionCheck[offsetof(ChickenFestivalEntrant, affection) == 17 ? 1 : -1];
typedef char ChickenFestivalMinigameSceneSizeCheck[sizeof(ChickenFestivalMinigameScene) == 8 ? 1 : -1];
typedef char ChickenFestivalMinigameSceneCoreCheck[offsetof(ChickenFestivalMinigameScene, core) == 4 ? 1 : -1];

// Direct declarations of the old GCC member ABI for the remaining transition
// catalog. They bind the real methods and emit no alias or forwarding body.
extern "C" void DestroyChickenFestivalContestTransition(
    ChickenFestivalContestTransition *, int) asm("_._32ChickenFestivalContestTransition");
extern "C" SceneOwner CreateScene__32ChickenFestivalContestTransition(
    ChickenFestivalContestTransition *);

#endif // SCENE_CHICKEN_FESTIVAL_HH
