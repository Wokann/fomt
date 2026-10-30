#ifndef SCENE_HORSE_RACE_HH
#define SCENE_HORSE_RACE_HH

#include "scene.hh"

struct GameStateSaveImage;
struct HorseRaceCore;

#pragma interface "scene_horse_race.hh"

// The wrapper constructor, destructor, and Run body remain native assembly.
struct HorseRaceScene : AScene {
    HorseRaceScene(SceneTransitionOwner next, GameStateSaveImage * image, bool compete);
    virtual ~HorseRaceScene();
    virtual SceneTransitionOwner Run();

    HorseRaceCore * core;
    SceneTransitionOwner continuation;
};

struct HorseRaceTransition : SceneTransition {
    HorseRaceTransition(SceneTransitionOwner next, GameStateSaveImage * image, bool compete)
        : continuation(next), save(image), player_competes(compete) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    bool player_competes;
};

typedef char HorseRaceSceneSizeCheck[sizeof(HorseRaceScene) == 12 ? 1 : -1];
typedef char HorseRaceSceneCoreCheck[offsetof(HorseRaceScene, core) == 4 ? 1 : -1];
typedef char HorseRaceSceneContinuationCheck[offsetof(HorseRaceScene, continuation) == 8 ? 1 : -1];
typedef char HorseRaceTransitionSizeCheck[sizeof(HorseRaceTransition) == 16 ? 1 : -1];
typedef char HorseRaceTransitionContinuationCheck[offsetof(HorseRaceTransition, continuation) == 4 ? 1 : -1];
typedef char HorseRaceTransitionSaveCheck[offsetof(HorseRaceTransition, save) == 8 ? 1 : -1];
typedef char HorseRaceTransitionModeCheck[offsetof(HorseRaceTransition, player_competes) == 12 ? 1 : -1];

// The scene shell and native constructor establish these pointer/owner fields.
// Constructor, destructor, Run and the core body remain native assembly.
struct HorseRaceMedalExchangeCore;
struct HorseRaceMedalExchangeScene : AScene {
    HorseRaceMedalExchangeScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~HorseRaceMedalExchangeScene();
    virtual SceneTransitionOwner Run();
    HorseRaceMedalExchangeCore * core;
    SceneTransitionOwner continuation;
};

struct HorseRaceMedalExchangeTransition : SceneTransition {
    HorseRaceMedalExchangeTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char HorseRaceMedalExchangeSceneSizeCheck[sizeof(HorseRaceMedalExchangeScene) == 12 ? 1 : -1];
typedef char HorseRaceMedalExchangeSceneCoreCheck[offsetof(HorseRaceMedalExchangeScene, core) == 4 ? 1 : -1];
typedef char HorseRaceMedalExchangeSceneContinuationCheck[offsetof(HorseRaceMedalExchangeScene, continuation) == 8 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionSizeCheck[sizeof(HorseRaceMedalExchangeTransition) == 12 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionContinuationCheck[offsetof(HorseRaceMedalExchangeTransition, continuation) == 4 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionSaveCheck[offsetof(HorseRaceMedalExchangeTransition, save) == 8 ? 1 : -1];

// Direct ABI declaration of this still-native constructor, not a wrapper.
// The second argument is the actual single-word continuation transfer slot.
extern "C" HorseRaceMedalExchangeScene * __27HorseRaceMedalExchangeSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * storage, SceneTransition ** next, GameStateSaveImage * image);

#endif
