#ifndef SCENE_BEACH_CAFE_SHOP_HH
#define SCENE_BEACH_CAFE_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "shop_common.hh"

#pragma interface "scene_beach_cafe_shop.hh"

struct BeachCafeShopOrder {
    u32 icon_id;
    u32 unk_04;
    i32 stamina_change;
    i32 unk_0C;
};

// The transfer retains the erased owner slot and its cached typed order.
struct BeachCafeShopOrderTransfer {
    void * & source;
    BeachCafeShopOrder * value;
    BeachCafeShopOrderTransfer(void * & input, BeachCafeShopOrder * order)
        : source(input), value(order) {}
    BeachCafeShopOrder * release() const { source = nullptr; return value; }
};

struct BeachCafeShopOrderOwner {
    void * value;
    BeachCafeShopOrder * release()
    {
        BeachCafeShopOrder * result = static_cast<BeachCafeShopOrder *>(value);
        value = nullptr;
        return result;
    }
    explicit BeachCafeShopOrderOwner(BeachCafeShopOrder * input = nullptr) : value(input) {}
    BeachCafeShopOrderOwner(BeachCafeShopOrderOwner & other) : value(other.release()) {}
    BeachCafeShopOrderOwner(BeachCafeShopOrderTransfer transfer) : value(transfer.release()) {}
    ~BeachCafeShopOrderOwner() { delete static_cast<BeachCafeShopOrder *>(value); }
    operator BeachCafeShopOrderTransfer()
    {
        return BeachCafeShopOrderTransfer(value, static_cast<BeachCafeShopOrder *>(value));
    }
};
#pragma interface "scene_beach_cafe_shop.hh"

struct BeachCafeShopSceneCore;

struct BeachCafeShopSceneCoreOwner {
    explicit BeachCafeShopSceneCoreOwner(BeachCafeShopSceneCore * input) : value(input) {}
    ~BeachCafeShopSceneCoreOwner();
    BeachCafeShopSceneCore * value;
};

#pragma interface "scene_beach_cafe_shop.hh"
struct BeachCafeShopScene : AScene {
    BeachCafeShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~BeachCafeShopScene();
    virtual SceneTransitionOwner Run();
    BeachCafeShopOrderOwner TakeOrder();

    BeachCafeShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct BeachCafeShopSceneCore : ShopScreenCore {
    BeachCafeShopSceneCore(GameStateSaveImage * image);
    virtual ~BeachCafeShopSceneCore();
    BeachCafeShopOrderOwner TakeOrder();
    void UpdateDescription(u32 selection);
    void Run();

    i32 phase;
    bool has_ordered;
    BeachCafeShopOrderOwner order;
};


#pragma interface "scene_beach_cafe_shop.hh"

#pragma interface "scene_beach_cafe_shop.hh"


EXTERN_C

// The real constructor's GCC 2.9 continuation-slot ABI, without a wrapper body.
BeachCafeShopScene * __18BeachCafeShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_beach_cafe_shop.hh"


// Run applies stamina_change to the farmer and copies the final fields to
// BeachCafeShopOrder. The roles of the two remaining values are not yet established.
struct BeachCafeShopMenuEntry
{
    u32 food_ui_id;
    u32 price;
    char const * description_override;
    u32 uses_description_override;
    i32 stamina_change;
    i32 unk_14;
    u32 unk_18;
};

extern BeachCafeShopMenuEntry const gBeachCafeShopMenu[];

extern char const gText_BeachCafeShop_WaterDescription[];
extern char const gText_BeachCafeShop_EmptyDescription[];
extern char const gText_BeachCafeShop_SpaghettiDescription[];
extern char const gText_BeachCafeShop_SnowConeDescription[];
extern char const gText_BeachCafeShop_InsufficientGold[];
extern char const gText_BeachCafeShop_NoOrder[];
extern char const gText_BeachCafeShop_OrderComplete[];

#endif // SCENE_BEACH_CAFE_SHOP_HH
