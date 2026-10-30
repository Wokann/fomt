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

#endif
