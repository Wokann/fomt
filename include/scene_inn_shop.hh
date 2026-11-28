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

// The transfer retains the erased owner slot and its cached typed order.
struct InnShopOrderTransfer {
    void * & source;
    InnShopOrder * value;
    InnShopOrderTransfer(void * & input, InnShopOrder * order)
        : source(input), value(order) {}
    InnShopOrder * release() const { source = nullptr; return value; }
};

struct InnShopOrderOwner {
    void * value;
    InnShopOrder * release()
    {
        InnShopOrder * result = static_cast<InnShopOrder *>(value);
        value = nullptr;
        return result;
    }
    explicit InnShopOrderOwner(InnShopOrder * input = nullptr) : value(input) {}
    InnShopOrderOwner(InnShopOrderOwner & other) : value(other.release()) {}
    InnShopOrderOwner(InnShopOrderTransfer transfer) : value(transfer.release()) {}
    ~InnShopOrderOwner() { delete static_cast<InnShopOrder *>(value); }
    operator InnShopOrderTransfer()
    {
        return InnShopOrderTransfer(value, static_cast<InnShopOrder *>(value));
    }
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


#pragma interface "scene_inn_shop.hh"

#pragma interface "scene_inn_shop.hh"


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
