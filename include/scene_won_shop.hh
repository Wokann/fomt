#ifndef SCENE_WON_SHOP_HH
#define SCENE_WON_SHOP_HH

#include "scene.hh"

#pragma interface "scene_won_shop.hh"

struct GameStateSaveImage;
struct WonShopSceneCore;

struct WonShopScene : AScene {
    WonShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~WonShopScene();
    virtual SceneTransitionOwner Run();

    WonShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct WonShopTransition : SceneTransition {
    WonShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char WonShopSceneSizeCheck[sizeof(WonShopScene) == 12 ? 1 : -1];
typedef char WonShopSceneCoreCheck[offsetof(WonShopScene, core) == 4 ? 1 : -1];
typedef char WonShopSceneContinuationCheck[offsetof(WonShopScene, continuation) == 8 ? 1 : -1];
typedef char WonShopTransitionSizeCheck[sizeof(WonShopTransition) == 12 ? 1 : -1];

EXTERN_C

// The native core's allocation is known; its internal layout stays opaque.
WonShopSceneCore * ConstructWonShopSceneCore(void * object, GameStateSaveImage * save);
void RunWonShopSceneCore(WonShopSceneCore * core);

// Direct GCC 2.9 constructor ABI: caller-made owner slot, returned this pointer.
// This names the sole C++ constructor body; it defines no additional function.
WonShopScene * __12WonShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** continuation, GameStateSaveImage * save);

EXTERN_C_END

#endif // SCENE_WON_SHOP_HH
