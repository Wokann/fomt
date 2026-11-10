#ifndef SCENE_INN_SHOP_HH
#define SCENE_INN_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "shop_common.hh"

#pragma interface "scene_inn_shop.hh"

struct InnShopOrder {
    u32 icon_id;
    u32 unk_04;
    i32 stamina_change;
    i32 unk_0C;
};

// The native return conversion retains both the source slot and its value.
struct InnShopOrderTransfer {
    InnShopOrder * & source;
    InnShopOrder * value;
    InnShopOrderTransfer(InnShopOrder * & input) : source(input), value(input) {}
    InnShopOrder * release() const { source = nullptr; return value; }
};

struct InnShopOrderOwner {
    InnShopOrder * value;
    InnShopOrder * release() { InnShopOrder * result = value; value = nullptr; return result; }
    explicit InnShopOrderOwner(InnShopOrder * input = nullptr) : value(input) {}
    InnShopOrderOwner(InnShopOrderOwner & other) : value(other.release()) {}
    InnShopOrderOwner(InnShopOrderTransfer transfer) : value(transfer.release()) {}
    ~InnShopOrderOwner() { delete value; }
    operator InnShopOrderTransfer() { return InnShopOrderTransfer(value); }
};
#pragma interface "scene_inn_shop.hh"

struct InnShopSceneCore;

struct InnShopSceneCoreOwner {
    explicit InnShopSceneCoreOwner(InnShopSceneCore * input) : value(input) {}
    ~InnShopSceneCoreOwner();
    InnShopSceneCore * value;
};

#pragma interface "scene_inn_shop.hh"
struct InnShopScene : AScene {
    InnShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~InnShopScene();
    virtual SceneTransitionOwner Run();
    InnShopOrderOwner TakeOrder();

    InnShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct InnShopSceneCore : ShopScreenCore {
    InnShopSceneCore(GameStateSaveImage * image);
    virtual ~InnShopSceneCore();
    InnShopOrderOwner TakeOrder();
    void UpdateDescription(u32 selection);
    void Run();

    i32 phase;
    bool has_ordered;
    InnShopOrderOwner order;
};

typedef char InnOrderSizeCheck[sizeof(InnShopOrder) == 16 ? 1 : -1];
typedef char InnOrderOwnerSizeCheck[sizeof(InnShopOrderOwner) == 4 ? 1 : -1];
typedef char InnOrderTransferSizeCheck[sizeof(InnShopOrderTransfer) == 8 ? 1 : -1];
typedef char InnCorePhaseCheck[offsetof(InnShopSceneCore, phase) == 0x6A4 ? 1 : -1];
typedef char InnCoreOrderedCheck[offsetof(InnShopSceneCore, has_ordered) == 0x6A8 ? 1 : -1];
typedef char InnCoreOrderCheck[offsetof(InnShopSceneCore, order) == 0x6AC ? 1 : -1];
typedef char InnCoreSizeCheck[sizeof(InnShopSceneCore) == 0x6B0 ? 1 : -1];

#pragma interface "scene_inn_shop.hh"

#pragma interface "scene_inn_shop.hh"

typedef char InnShopSceneSizeCheck[sizeof(InnShopScene) == 12 ? 1 : -1];
typedef char InnShopSceneCoreCheck[offsetof(InnShopScene, core) == 4 ? 1 : -1];
typedef char InnShopSceneContinuationCheck[offsetof(InnShopScene, continuation) == 8 ? 1 : -1];

EXTERN_C

// The real constructor's GCC 2.9 continuation-slot ABI, without a wrapper body.
InnShopScene * __12InnShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_inn_shop.hh"


// Run applies stamina_change to the farmer and copies the final fields to
// InnShopOrder. The roles of the two remaining values are not yet established.
struct InnShopMenuEntry
{
    u32 food_ui_id;
    u32 price;
    char const * description_override;
    u32 uses_description_override;
    i32 stamina_change;
    i32 unk_14;
    u32 unk_18;
};

extern InnShopMenuEntry const gInnShopMenu[];

extern char const gText_InnShop_WaterDescription[];
extern char const gText_InnShop_BoxLunchDescription[];
extern char const gText_InnShop_Empty[];
extern char const gText_InnShop_MilkDescription[];
extern char const gText_InnShop_InsufficientGold[];
extern char const gText_InnShop_NoOrder[];
extern char const gText_InnShop_OrderComplete[];

#endif // SCENE_INN_SHOP_HH
