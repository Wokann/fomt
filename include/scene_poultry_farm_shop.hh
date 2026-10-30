#ifndef SCENE_POULTRY_FARM_SHOP_HH
#define SCENE_POULTRY_FARM_SHOP_HH

#include "game_scene.hh"
#pragma interface "scene_poultry_farm_shop.hh"

struct PoultryFarmShopSceneCore;
struct PoultryFarmShopScene : AScene {
    PoultryFarmShopScene(SceneTransitionOwner next, GameStateSaveImage * image, u32 input);
    virtual ~PoultryFarmShopScene();
    virtual SceneTransitionOwner Run();
    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    GameStateSaveImage * save;
};

struct PoultryFarmShopTransition : SceneTransition {
    PoultryFarmShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
};
typedef char PoultryFarmShopSceneSizeCheck[sizeof(PoultryFarmShopScene) == 20 ? 1 : -1];
typedef char PoultryFarmShopSceneSaveCheck[offsetof(PoultryFarmShopScene, save) == 16 ? 1 : -1];
typedef char PoultryFarmShopTransitionSizeCheck[sizeof(PoultryFarmShopTransition) == 16 ? 1 : -1];

EXTERN_C

// The native core keeps its actual constructor and naming-result contract.
PoultryFarmShopSceneCore * ConstructPoultryFarmShopSceneCore(
    void * object, GameStateSaveImage * image, u32 input);
i32 RunPoultryFarmShopSceneCore(PoultryFarmShopSceneCore * core);

// Direct reference to the real GCC 2.9 continuation-slot constructor ABI.
PoultryFarmShopScene * __20PoultryFarmShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUi(
    void * object, SceneTransition ** next, GameStateSaveImage * image, u32 input);

EXTERN_C_END

#endif // SCENE_POULTRY_FARM_SHOP_HH
