#ifndef SCENE_GIFT_WRAPPING_HH
#define SCENE_GIFT_WRAPPING_HH

#include "game_scene.hh"
#pragma interface "scene_gift_wrapping.hh"

struct GiftWrappingSceneCore;
struct GiftWrappingScene : AScene {
    GiftWrappingScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~GiftWrappingScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct GiftWrappingTransition : SceneTransition {
    GiftWrappingTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char GiftWrappingSceneSizeCheck[sizeof(GiftWrappingScene) == 12 ? 1 : -1];
typedef char GiftWrappingSceneCoreCheck[offsetof(GiftWrappingScene, core) == 4 ? 1 : -1];
typedef char GiftWrappingSceneContinuationCheck[offsetof(GiftWrappingScene, continuation) == 8 ? 1 : -1];
typedef char GiftWrappingTransitionSizeCheck[sizeof(GiftWrappingTransition) == 12 ? 1 : -1];

EXTERN_C

// The native core keeps its verified UI base prefix and opaque remaining layout.
GiftWrappingSceneCore * ConstructGiftWrappingSceneCore(void * object, GameStateSaveImage * image);
void RunGiftWrappingSceneCore(GiftWrappingSceneCore * core);

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
GiftWrappingScene * __17GiftWrappingSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_GIFT_WRAPPING_HH
