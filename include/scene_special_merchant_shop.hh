#ifndef SCENE_SPECIAL_MERCHANT_SHOP_HH
#define SCENE_SPECIAL_MERCHANT_SHOP_HH

#include "game_scene.hh"

#pragma interface "scene_special_merchant_shop.hh"

struct SpecialMerchantShopSceneCore;
struct SpecialMerchantShopScene : AScene {
    SpecialMerchantShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~SpecialMerchantShopScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct SpecialMerchantShopTransition : SceneTransition {
    SpecialMerchantShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char SpecialMerchantShopSceneSizeCheck[sizeof(SpecialMerchantShopScene) == 12 ? 1 : -1];
typedef char SpecialMerchantShopSceneCoreCheck[offsetof(SpecialMerchantShopScene, core) == 4 ? 1 : -1];
typedef char SpecialMerchantShopSceneContinuationCheck[offsetof(SpecialMerchantShopScene, continuation) == 8 ? 1 : -1];
typedef char SpecialMerchantShopTransitionSizeCheck[sizeof(SpecialMerchantShopTransition) == 12 ? 1 : -1];

EXTERN_C

// The existing zero-offset destruction prefix is typed; the native core is opaque.
SpecialMerchantShopSceneCore * ConstructSpecialMerchantShopSceneCore(void * object, GameStateSaveImage * image);
void RunSpecialMerchantShopSceneCore(SpecialMerchantShopSceneCore * core);

// The real constructor's GCC 2.9 continuation-slot ABI, without a wrapper body.
SpecialMerchantShopScene * __24SpecialMerchantShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_SPECIAL_MERCHANT_SHOP_HH
