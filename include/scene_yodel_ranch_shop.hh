#ifndef SCENE_YODEL_RANCH_SHOP_HH
#define SCENE_YODEL_RANCH_SHOP_HH

#include "scene.hh"

struct GameStateSaveImage;
#pragma interface "scene_yodel_ranch_shop.hh"

// Verified nonuniform scene layouts; unknown scalar semantics stay unnamed.
struct YodelRanchShopSceneCore;
struct YodelRanchShopScene : AScene {
    YodelRanchShopScene(SceneTransitionOwner next, GameStateSaveImage * image, u32 input);
    virtual ~YodelRanchShopScene();
    virtual SceneTransitionOwner Run();
    YodelRanchShopSceneCore * core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    GameStateSaveImage * save;
};

struct YodelRanchShopTransition : SceneTransition {
    YodelRanchShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
};
typedef char YodelRanchShopSceneSizeCheck[sizeof(YodelRanchShopScene) == 20 ? 1 : -1];
typedef char YodelRanchShopSceneSaveCheck[offsetof(YodelRanchShopScene, save) == 16 ? 1 : -1];
typedef char YodelRanchShopTransitionSizeCheck[sizeof(YodelRanchShopTransition) == 16 ? 1 : -1];

EXTERN_C

// The core returns a naming index, or -1 when no naming scene is needed.
i32 RunYodelRanchShopCore(YodelRanchShopSceneCore * core);
// Returns 0 for cows, 1 for sheep, or the native 999 invalid-choice sentinel.
u32 GetYodelRanchShopAnimalChoice(YodelRanchShopSceneCore * core);

// Actual GCC 2.9 constructor ABI: the continuation is transferred through
// its single pointer slot. The constructor body remains native assembly.
YodelRanchShopScene * __19YodelRanchShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUi(
    void * storage, SceneTransition ** next, GameStateSaveImage * image, u32 input);

EXTERN_C_END

#endif // SCENE_YODEL_RANCH_SHOP_HH
