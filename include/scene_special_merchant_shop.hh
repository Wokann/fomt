#ifndef SCENE_SPECIAL_MERCHANT_SHOP_HH
#define SCENE_SPECIAL_MERCHANT_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "shop_common.hh"
#include "utility/fixed_str.hh"

#pragma interface "scene_special_merchant_shop.hh"

struct SpecialMerchantShopSceneCore;

struct SpecialMerchantShopSceneCoreOwner {
    explicit SpecialMerchantShopSceneCoreOwner(SpecialMerchantShopSceneCore * input) : value(input) {}
    ~SpecialMerchantShopSceneCoreOwner();
    SpecialMerchantShopSceneCore * value;
};

#pragma interface "scene_special_merchant_shop.hh"
struct SpecialMerchantShopScene : AScene {
    SpecialMerchantShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~SpecialMerchantShopScene();
    virtual SceneTransitionOwner Run();

    SpecialMerchantShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct SpecialMerchantShopSceneCore : ShopScreenCore {
    SpecialMerchantShopSceneCore(GameStateSaveImage * image);
    virtual ~SpecialMerchantShopSceneCore();
    void DrawCatalog();
    void UpdateDescription(u32 selection);
    void Run();

    i32 phase;
    bool has_purchased;
    // Native RAM capacity: 99 content bytes followed by the terminating NUL.
    FixedStr<99> description;
};

typedef char SpecialMerchantCorePhaseCheck[offsetof(SpecialMerchantShopSceneCore, phase) == 0x6A4 ? 1 : -1];
typedef char SpecialMerchantCorePurchasedCheck[offsetof(SpecialMerchantShopSceneCore, has_purchased) == 0x6A8 ? 1 : -1];
typedef char SpecialMerchantCoreDescriptionCheck[offsetof(SpecialMerchantShopSceneCore, description) == 0x6AC ? 1 : -1];
typedef char SpecialMerchantCoreSizeCheck[sizeof(SpecialMerchantShopSceneCore) == 0x710 ? 1 : -1];

// Member order releases the continuation before this owned core.
#pragma interface "scene_special_merchant_shop.hh"

#pragma interface "scene_special_merchant_shop.hh"

typedef char SpecialMerchantShopSceneSizeCheck[sizeof(SpecialMerchantShopScene) == 12 ? 1 : -1];
typedef char SpecialMerchantShopSceneCoreCheck[offsetof(SpecialMerchantShopScene, core) == 4 ? 1 : -1];
typedef char SpecialMerchantShopSceneContinuationCheck[offsetof(SpecialMerchantShopScene, continuation) == 8 ? 1 : -1];

EXTERN_C

// The real constructor's GCC 2.9 continuation-slot ABI, without a wrapper body.
SpecialMerchantShopScene * __24SpecialMerchantShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_special_merchant_shop.hh"


struct SpecialMerchantShopCatalogEntry
{
    u32 item_id;
    u32 price;
};

// The original entry at index 10 is handled as a Record Player rather than
// as an ArticleUi item.  Its first word is a catalog sentinel, not a tool ID.
enum
{
    SPECIAL_MERCHANT_RECORD_PLAYER_SENTINEL = 10,
};

extern SpecialMerchantShopCatalogEntry const gSpecialMerchantShopCatalog[];

extern char const gText_SpecialMerchantShop_RecordPlayerDescription[];
extern char const gText_SpecialMerchantShop_InsufficientGold[];
extern char const gText_SpecialMerchantShop_InventoryFull[];
extern char const gText_SpecialMerchantShop_BlankLinePair[];
extern char const gText_SpecialMerchantShop_PurchaseComplete[];
extern char const gText_SpecialMerchantShop_RecordPlayerDelivery[];
extern char const gText_SpecialMerchantShop_PurchaseCompleteShort[];
extern char const gText_SpecialMerchantShop_ArticleDelivery[];
extern char const gText_SpecialMerchantShop_PurchaseMorePrompt[];

#endif // SCENE_SPECIAL_MERCHANT_SHOP_HH
