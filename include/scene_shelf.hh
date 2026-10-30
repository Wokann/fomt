#ifndef SCENE_SHELF_HH
#define SCENE_SHELF_HH

#include "game_scene.hh"
#pragma interface "scene_shelf.hh"

struct ShelfSceneCore;
struct ShelfScene : AScene {
    ShelfScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~ShelfScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct ShelfTransition : SceneTransition {
    ShelfTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ShelfSceneSizeCheck[sizeof(ShelfScene) == 12 ? 1 : -1];
typedef char ShelfSceneCoreCheck[offsetof(ShelfScene, core) == 4 ? 1 : -1];
typedef char ShelfSceneContinuationCheck[offsetof(ShelfScene, continuation) == 8 ? 1 : -1];
typedef char ShelfTransitionSizeCheck[sizeof(ShelfTransition) == 12 ? 1 : -1];

EXTERN_C

// The native core keeps its verified UI base prefix and opaque remaining layout.
ShelfSceneCore * ConstructShelfSceneCore(void * object, GameStateSaveImage * image);
void RunShelfSceneCore(ShelfSceneCore * core);

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
ShelfScene * __10ShelfSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_SHELF_HH
