#ifndef SCENE_WINERY_SHOP_HH
#define SCENE_WINERY_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "shop_common.hh"
#include "utility/fixed_str.hh"

#pragma interface "scene_winery_shop.hh"

struct WineryShopSceneCore;

struct WineryShopSceneCoreOwner {
    explicit WineryShopSceneCoreOwner(WineryShopSceneCore * input) : value(input) {}
    ~WineryShopSceneCoreOwner();
    WineryShopSceneCore * value;
};

#pragma interface "scene_winery_shop.hh"
struct WineryShopScene : AScene {
    WineryShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~WineryShopScene();
    virtual SceneTransitionOwner Run();

    WineryShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct WineryShopSceneCore : ShopScreenCore {
    WineryShopSceneCore(GameStateSaveImage * image);
    virtual ~WineryShopSceneCore();
    void Run();

    i32 phase;
    bool has_purchased;
    // Native RAM capacity: 99 content bytes followed by the terminating NUL.
    FixedStr<99> description;
};


// Member order releases the continuation before this owned core.
#pragma interface "scene_winery_shop.hh"

#pragma interface "scene_winery_shop.hh"


EXTERN_C

// The real constructor's GCC 2.9 continuation-slot ABI, without a wrapper body.
WineryShopScene * __15WineryShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_winery_shop.hh"


struct WineryShopCatalogEntry
{
    u32 food_id;
    u32 price;
};

extern WineryShopCatalogEntry const gWineryShopCatalog[];

extern char const gText_WineryShop_InventoryFull[];
extern char const gText_WineryShop_BlankLinePair[];
extern char const gText_WineryShop_InsufficientGold[];
extern char const gText_WineryShop_ReturnCustomer[];
extern char const gText_WineryShop_NoPurchase[];
extern char const gText_WineryShop_DeliveryRemainder[];
extern char const gText_WineryShop_DeliveryAll[];
extern char const gText_WineryShop_Delivery[];
extern char const gText_WineryShop_PurchaseComplete[];
extern char const gText_WineryShop_PurchaseMorePrompt[];

#endif // SCENE_WINERY_SHOP_HH
