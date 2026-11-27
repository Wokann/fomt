#ifndef SCENE_CLINIC_SHOP_HH
#define SCENE_CLINIC_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "shop_common.hh"
#include "utility/fixed_str.hh"

#pragma interface "scene_clinic_shop.hh"

struct ClinicShopSceneCore;

struct ClinicShopSceneCoreOwner {
    explicit ClinicShopSceneCoreOwner(ClinicShopSceneCore * input) : value(input) {}
    ~ClinicShopSceneCoreOwner();
    ClinicShopSceneCore * value;
};

#pragma interface "scene_clinic_shop.hh"
struct ClinicShopScene : AScene {
    ClinicShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~ClinicShopScene();
    virtual SceneTransitionOwner Run();

    ClinicShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct ClinicShopSceneCore : ShopScreenCore {
    ClinicShopSceneCore(GameStateSaveImage * image);
    virtual ~ClinicShopSceneCore();
    void UpdateDescription(u32 selection);
    void Run();

    // Native RAM capacity: 99 content bytes followed by the terminating NUL.
    FixedStr<99> description;
    i32 phase;
    bool has_purchased;
};


// Member order releases the continuation before this owned core.
#pragma interface "scene_clinic_shop.hh"

#pragma interface "scene_clinic_shop.hh"


EXTERN_C

// Sole C++ constructor body, declared in its actual GCC 2.9 owner-slot ABI.
ClinicShopScene * __15ClinicShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * save);

EXTERN_C_END

#pragma interface "scene_clinic_shop.hh"


struct ClinicCatalogEntry
{
    u32 food_id;
    u32 price;
};

extern ClinicCatalogEntry const gClinicCatalog[];

extern char const gText_Clinic_InventoryFull[];
extern char const gText_Clinic_BlankLinePair[];
extern char const gText_Clinic_InsufficientGold[];
extern char const gText_Clinic_NoAdditionalPurchase[];
extern char const gText_Clinic_NoPurchaseRestAdvice[];
extern char const gText_Clinic_PurchaseMorePrompt[];
extern char const gText_Clinic_Delivery[];
extern char const gText_Clinic_DeliveryPartial[];
extern char const gText_Clinic_PurchaseComplete[];

#endif // SCENE_CLINIC_SHOP_HH
