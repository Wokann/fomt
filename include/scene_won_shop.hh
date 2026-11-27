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

// Owns the scene core. The native destructor destroys it implicitly, in reverse
// declaration order together with `continuation`, which is only possible if the
// member carries a destructor of its own. The bodies are defined below the core
// class, where the pointee is complete, and stay inline so the scene destructor
// expands them in place.
struct WonShopSceneCoreOwner {
    explicit WonShopSceneCoreOwner(WonShopSceneCore * input = nullptr);
    ~WonShopSceneCoreOwner();
    WonShopSceneCore * operator->() const { return value; }
    WonShopSceneCore * value;
};

struct WonShopScene : AScene {
    WonShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~WonShopScene();
    virtual SceneTransitionOwner Run();

    WonShopSceneCoreOwner core;
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

inline WonShopSceneCoreOwner::WonShopSceneCoreOwner(WonShopSceneCore * input)
    : value(input) {}
inline WonShopSceneCoreOwner::~WonShopSceneCoreOwner() { delete value; }


#pragma interface "scene_won_shop.hh"


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
