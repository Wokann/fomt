#ifndef SCENE_CARPENTER_SHOP_HH
#define SCENE_CARPENTER_SHOP_HH

#include "scene.hh"

#pragma interface "scene_carpenter_shop.hh"

struct GameStateSaveImage;
struct CarpenterShopSceneCore;

struct CarpenterShopScene : AScene {
    CarpenterShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~CarpenterShopScene();
    virtual SceneTransitionOwner Run();

    CarpenterShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct CarpenterShopTransition : SceneTransition {
    CarpenterShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char CarpenterShopSceneSizeCheck[sizeof(CarpenterShopScene) == 12 ? 1 : -1];
typedef char CarpenterShopSceneCoreCheck[offsetof(CarpenterShopScene, core) == 4 ? 1 : -1];
typedef char CarpenterShopSceneContinuationCheck[offsetof(CarpenterShopScene, continuation) == 8 ? 1 : -1];
typedef char CarpenterShopTransitionSizeCheck[sizeof(CarpenterShopTransition) == 12 ? 1 : -1];

EXTERN_C

// The native core's allocation is known; its internal layout stays opaque.
CarpenterShopSceneCore * ConstructCarpenterShopSceneCore(void * object, GameStateSaveImage * save);
void RunCarpenterShopSceneCore(CarpenterShopSceneCore * core);

// Direct GCC 2.9 constructor ABI: caller-made owner slot, returned this pointer.
// This names the sole C++ constructor body; it defines no additional function.
CarpenterShopScene * __18CarpenterShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** continuation, GameStateSaveImage * save);

EXTERN_C_END

#endif // SCENE_CARPENTER_SHOP_HH
