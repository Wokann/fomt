#ifndef SCENE_REFRIGERATOR_HH
#define SCENE_REFRIGERATOR_HH

#include "game_scene.hh"
#pragma interface "scene_refrigerator.hh"

struct RefrigeratorSceneCore;
struct RefrigeratorScene : AScene {
    RefrigeratorScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~RefrigeratorScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct RefrigeratorTransition : SceneTransition {
    RefrigeratorTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char RefrigeratorSceneSizeCheck[sizeof(RefrigeratorScene) == 12 ? 1 : -1];
typedef char RefrigeratorSceneCoreCheck[offsetof(RefrigeratorScene, core) == 4 ? 1 : -1];
typedef char RefrigeratorSceneContinuationCheck[offsetof(RefrigeratorScene, continuation) == 8 ? 1 : -1];
typedef char RefrigeratorTransitionSizeCheck[sizeof(RefrigeratorTransition) == 12 ? 1 : -1];

EXTERN_C

// The native core keeps its verified UI base prefix and opaque remaining layout.
RefrigeratorSceneCore * ConstructRefrigeratorSceneCore(void * object, GameStateSaveImage * image);
void RunRefrigeratorSceneCore(RefrigeratorSceneCore * core);

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
RefrigeratorScene * __17RefrigeratorSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_REFRIGERATOR_HH
