#ifndef SCENE_WON_SHOP_HH
#define SCENE_WON_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "scene.hh"
#include "shop_common.hh"
#include "utility/fixed_str.hh"

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

struct WonShopSceneCore : ShopScreenCore {
    WonShopSceneCore(GameStateSaveImage * image);
    virtual ~WonShopSceneCore();
    void UpdateDescription(u32 selection);
    i32 DrawCatalog();
    void Run();
    bool IsArticle(i32 catalog_index) const;

    // The native formatter reserves 99 content bytes and one terminating NUL.
    FixedStr<99> description;
    i32 phase;
    bool has_purchased;
};

typedef char WonCoreDescriptionCheck[offsetof(WonShopSceneCore, description) == 0x6A4 ? 1 : -1];
typedef char WonCorePhaseCheck[offsetof(WonShopSceneCore, phase) == 0x708 ? 1 : -1];
typedef char WonCorePurchasedCheck[offsetof(WonShopSceneCore, has_purchased) == 0x70C ? 1 : -1];
typedef char WonCoreSizeCheck[sizeof(WonShopSceneCore) == 0x710 ? 1 : -1];

#pragma interface "scene_won_shop.hh"

typedef char WonShopSceneSizeCheck[sizeof(WonShopScene) == 12 ? 1 : -1];
typedef char WonShopSceneCoreCheck[offsetof(WonShopScene, core) == 4 ? 1 : -1];
typedef char WonShopSceneContinuationCheck[offsetof(WonShopScene, continuation) == 8 ? 1 : -1];

EXTERN_C

// Direct GCC 2.9 constructor ABI: caller-made owner slot, returned this pointer.
// This names the sole C++ constructor body; it defines no additional function.
WonShopScene * __12WonShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** continuation, GameStateSaveImage * save);

EXTERN_C_END

#pragma interface "scene_won_shop.hh"


// The original menu determines item kind from position: entries 0-2 are
// ArticleUi items, while entries 3-9 are ToolUi items.
struct WonShopCatalogEntry
{
    u32 item_id;
    u32 price;
};

extern WonShopCatalogEntry const gWonShopCatalog[];

extern char const gText_WonShop_ToolCapacityFull[];
extern char const gText_WonShop_ItemCapacityFull[];
extern char const gText_WonShop_BlankLinePair[];
extern char const gText_WonShop_ArticleDelivery[];
extern char const gText_WonShop_ArticleDeliveryMultiple[];
extern char const gText_WonShop_ToolDelivery[];
extern char const gText_WonShop_ToolDeliveryMultiple[];
extern char const gText_WonShop_Delivery[];
extern char const gText_WonShop_DeliveryMultiple[];
extern char const gText_WonShop_PurchaseComplete[];
extern char const gText_WonShop_InsufficientGold[];
extern char const gText_WonShop_PurchaseMorePrompt[];
extern char const gText_WonShop_NoPurchase[];
extern char const gText_WonShop_NoAdditionalPurchase[];

#endif // SCENE_WON_SHOP_HH
