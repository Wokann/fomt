#ifndef SCENE_SUPERMARKET_HH
#define SCENE_SUPERMARKET_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "scene.hh"
#include "fomt_constants.hh"
#include "shop_common.hh"
#include "utility/fixed_str.hh"

#pragma interface "scene_supermarket.hh"

struct GameStateSaveImage;

struct SupermarketSceneCore;
struct SupermarketPurchaseSceneCore;

// Native scene destructors release the continuation before deleting the core.
struct SupermarketScene : AScene {
    SupermarketScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~SupermarketScene();
    virtual SceneTransitionOwner Run();

    SupermarketSceneCore * core;
    SceneTransitionOwner continuation;
};

struct SupermarketPurchaseScene : AScene {
    SupermarketPurchaseScene(SceneTransitionOwner next, GameStateSaveImage * image, MarySupermarketItemId item);
    virtual ~SupermarketPurchaseScene();
    virtual SceneTransitionOwner Run();

    SupermarketPurchaseSceneCore * core;
    SceneTransitionOwner continuation;
};

struct SupermarketSceneCore : ShopScreenCore {
    SupermarketSceneCore(GameStateSaveImage * image);
    virtual ~SupermarketSceneCore();
    void UpdateDescription(u32 selection);
    void Run();

    // The native append path admits 99 bytes plus the terminating NUL.
    FixedStr<99> description;
    i32 phase;
    bool has_purchased;
};

struct SupermarketPurchaseSceneCore : ShopScreenCore {
    SupermarketPurchaseSceneCore(GameStateSaveImage * image, MarySupermarketItemId item);
    virtual ~SupermarketPurchaseSceneCore();
    void UpdateDescription(u32 selection);
    void Run();

    MarySupermarketItemId item_id;
    FixedStr<99> description;
    i32 phase;
};

typedef char SupermarketCoreDescriptionCheck[offsetof(SupermarketSceneCore, description) == 0x6A4 ? 1 : -1];
typedef char SupermarketCorePhaseCheck[offsetof(SupermarketSceneCore, phase) == 0x708 ? 1 : -1];
typedef char SupermarketCorePurchasedCheck[offsetof(SupermarketSceneCore, has_purchased) == 0x70C ? 1 : -1];
typedef char SupermarketCoreSizeCheck[sizeof(SupermarketSceneCore) == 0x710 ? 1 : -1];
typedef char SupermarketPurchaseCoreItemCheck[offsetof(SupermarketPurchaseSceneCore, item_id) == 0x6A4 ? 1 : -1];
typedef char SupermarketPurchaseCoreDescriptionCheck[offsetof(SupermarketPurchaseSceneCore, description) == 0x6A8 ? 1 : -1];
typedef char SupermarketPurchaseCorePhaseCheck[offsetof(SupermarketPurchaseSceneCore, phase) == 0x70C ? 1 : -1];
typedef char SupermarketPurchaseCoreSizeCheck[sizeof(SupermarketPurchaseSceneCore) == 0x710 ? 1 : -1];

EXTERN_C

// Direct references to the real GCC 2.9 continuation-slot constructor ABI.
SupermarketScene * __16SupermarketSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);
SupermarketPurchaseScene * __24SupermarketPurchaseSceneG20SceneTransitionOwnerP18GameStateSaveImage21MarySupermarketItemId(
    void * object, SceneTransition ** next, GameStateSaveImage * image, MarySupermarketItemId item);

EXTERN_C_END

#pragma interface "scene_supermarket.hh"

#pragma interface "scene_supermarket.hh"

typedef char SupermarketSceneSizeCheck[sizeof(SupermarketScene) == 12 ? 1 : -1];
typedef char SupermarketSceneCoreCheck[offsetof(SupermarketScene, core) == 4 ? 1 : -1];
typedef char SupermarketSceneContinuationCheck[offsetof(SupermarketScene, continuation) == 8 ? 1 : -1];
typedef char SupermarketPurchaseSceneSizeCheck[sizeof(SupermarketPurchaseScene) == 12 ? 1 : -1];
typedef char SupermarketPurchaseSceneCoreCheck[offsetof(SupermarketPurchaseScene, core) == 4 ? 1 : -1];
typedef char SupermarketPurchaseSceneContinuationCheck[offsetof(SupermarketPurchaseScene, continuation) == 8 ? 1 : -1];


// Both catalogs store an item identifier and price. The seed menu uses
// ToolUi; the separate grocery purchase flow uses FoodUi and MarySupermarketItemId.
struct SupermarketCatalogEntry
{
    u32 item_id;
    u32 price;
};

extern SupermarketCatalogEntry const gSupermarketCropSeedCatalog[];
extern SupermarketCatalogEntry const gSupermarketFoodCatalog[];

extern char const gText_Supermarket_EquipmentCapacityFull[];
extern char const gText_Supermarket_BlankLinePair[];
extern char const gText_Supermarket_InsufficientGold[];
extern char const gText_Supermarket_ThankYou[];
extern char const gText_Supermarket_PurchaseConfirmation[];
extern char const gText_Supermarket_PurchaseMorePrompt[];
extern char const gText_Supermarket_EquipmentDelivery[];
extern char const gText_Supermarket_FoodDelivery[];
extern char const gText_Supermarket_FoodPurchaseConfirmation[];

#if defined(REGION_JP)
extern char const gText_Supermarket_EquipmentDeliveryPartial[];
extern char const gText_Supermarket_FoodDeliveryPartial[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
// The US-family ROMs reuse this one object for both shop flows.
extern char const gText_Supermarket_DeliveryPartial[];
#endif

#endif // SCENE_SUPERMARKET_HH
