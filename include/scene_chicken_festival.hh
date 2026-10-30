#ifndef SCENE_CHICKEN_FESTIVAL_HH
#define SCENE_CHICKEN_FESTIVAL_HH

#include "scene.hh"

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

// Direct declarations of the old GCC member ABI for the remaining transition
// catalog. They bind the real methods and emit no alias or forwarding body.
extern "C" void DestroyChickenFestivalContestTransition(
    ChickenFestivalContestTransition *, int) asm("_._32ChickenFestivalContestTransition");
extern "C" SceneOwner CreateScene__32ChickenFestivalContestTransition(
    ChickenFestivalContestTransition *);

#endif // SCENE_CHICKEN_FESTIVAL_HH
