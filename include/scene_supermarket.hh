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

// Owns the scene core. The native scene destructor destroys the core implicitly,
// in reverse declaration order together with `continuation`, which is only
// possible if the member carries a destructor of its own. The bodies are defined
// below the core classes, where the pointee is complete; they stay inline so the
// scene destructor expands them in place.
struct SupermarketSceneCoreOwner {
    explicit SupermarketSceneCoreOwner(SupermarketSceneCore * input = nullptr);
    ~SupermarketSceneCoreOwner();
    SupermarketSceneCore * operator->() const { return value; }
    SupermarketSceneCore * value;
};

struct SupermarketPurchaseSceneCoreOwner {
    explicit SupermarketPurchaseSceneCoreOwner(
        SupermarketPurchaseSceneCore * input = nullptr);
    ~SupermarketPurchaseSceneCoreOwner();
    SupermarketPurchaseSceneCore * operator->() const { return value; }
    SupermarketPurchaseSceneCore * value;
};

// Native scene destructors release the continuation before deleting the core.
struct SupermarketScene : AScene {
    SupermarketScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~SupermarketScene();
    virtual SceneTransitionOwner Run();

    SupermarketSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct SupermarketPurchaseScene : AScene {
    SupermarketPurchaseScene(SceneTransitionOwner next, GameStateSaveImage * image, MarySupermarketItemId item);
    virtual ~SupermarketPurchaseScene();
    virtual SceneTransitionOwner Run();

    SupermarketPurchaseSceneCoreOwner core;
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

inline SupermarketSceneCoreOwner::SupermarketSceneCoreOwner(
    SupermarketSceneCore * input) : value(input) {}
inline SupermarketSceneCoreOwner::~SupermarketSceneCoreOwner() { delete value; }

inline SupermarketPurchaseSceneCoreOwner::SupermarketPurchaseSceneCoreOwner(
    SupermarketPurchaseSceneCore * input) : value(input) {}
inline SupermarketPurchaseSceneCoreOwner::~SupermarketPurchaseSceneCoreOwner()
{
    delete value;
}


EXTERN_C

// Direct references to the real GCC 2.9 continuation-slot constructor ABI.
SupermarketScene * __16SupermarketSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);
SupermarketPurchaseScene * __24SupermarketPurchaseSceneG20SceneTransitionOwnerP18GameStateSaveImage21MarySupermarketItemId(
    void * object, SceneTransition ** next, GameStateSaveImage * image, MarySupermarketItemId item);

EXTERN_C_END

#pragma interface "scene_supermarket.hh"

#pragma interface "scene_supermarket.hh"



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
