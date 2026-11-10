#ifndef SCENE_CARPENTER_SHOP_HH
#define SCENE_CARPENTER_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "scene.hh"
#include "shop_common.hh"
#include "utility/fixed_str.hh"

#pragma interface "scene_carpenter_shop.hh"

struct GameStateSaveImage;
// Fixed native storage for one 18 by 2 tile menu label.
struct CarpenterShopLabelTiles {
    u32 unk_00;
    u32 tiles[18 * 2 * 8];
};

struct CarpenterShopSceneCore;

struct CarpenterShopSceneCoreOwner {
    explicit CarpenterShopSceneCoreOwner(CarpenterShopSceneCore * input) : value(input) {}
    ~CarpenterShopSceneCoreOwner();
    CarpenterShopSceneCore * value;
};

#pragma interface "scene_carpenter_shop.hh"
struct CarpenterShopScene : AScene {
    CarpenterShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~CarpenterShopScene();
    virtual SceneTransitionOwner Run();

    CarpenterShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct CarpenterShopSceneCore : ShopScreenCore {
    CarpenterShopSceneCore(GameStateSaveImage * image);
    virtual ~CarpenterShopSceneCore();
    // The returned tile row becomes the scroll area's bottom limit.
    i32 DrawCatalog();
    i32 DrawRemodelChoices(i32 category);
    void UpdateDescription(u32 selection);
    void Run();

    FixedStr<99> quantity_description;
    i32 phase;
    bool has_purchased;
    u32 remodel_count;
    u32 remodel_catalog_indices[3];
    CarpenterShopLabelTiles label_tiles[20];
    FixedStr<127> remodel_description;
    bool lumber_bin_was_full;
};

typedef char CarpenterLabelTilesSizeCheck[sizeof(CarpenterShopLabelTiles) == 0x484 ? 1 : -1];
typedef char CarpenterCoreQuantityTextCheck[offsetof(CarpenterShopSceneCore, quantity_description) == 0x6A4 ? 1 : -1];
typedef char CarpenterCorePhaseCheck[offsetof(CarpenterShopSceneCore, phase) == 0x708 ? 1 : -1];
typedef char CarpenterCorePurchasedCheck[offsetof(CarpenterShopSceneCore, has_purchased) == 0x70C ? 1 : -1];
typedef char CarpenterCoreRemodelCountCheck[offsetof(CarpenterShopSceneCore, remodel_count) == 0x710 ? 1 : -1];
typedef char CarpenterCoreRemodelIndicesCheck[offsetof(CarpenterShopSceneCore, remodel_catalog_indices) == 0x714 ? 1 : -1];
typedef char CarpenterCoreTilesCheck[offsetof(CarpenterShopSceneCore, label_tiles) == 0x720 ? 1 : -1];
typedef char CarpenterCoreRemodelTextCheck[offsetof(CarpenterShopSceneCore, remodel_description) == 0x6170 ? 1 : -1];
typedef char CarpenterCoreLumberCheck[offsetof(CarpenterShopSceneCore, lumber_bin_was_full) == 0x61F0 ? 1 : -1];
typedef char CarpenterCoreSizeCheck[sizeof(CarpenterShopSceneCore) == 0x61F4 ? 1 : -1];

inline CarpenterShopSceneCoreOwner::~CarpenterShopSceneCoreOwner() { delete value; }
#pragma interface "scene_carpenter_shop.hh"

#pragma interface "scene_carpenter_shop.hh"

typedef char CarpenterShopSceneSizeCheck[sizeof(CarpenterShopScene) == 12 ? 1 : -1];
typedef char CarpenterShopSceneCoreCheck[offsetof(CarpenterShopScene, core) == 4 ? 1 : -1];
typedef char CarpenterShopSceneContinuationCheck[offsetof(CarpenterShopScene, continuation) == 8 ? 1 : -1];

EXTERN_C

// Direct GCC 2.9 constructor ABI: caller-made owner slot, returned this pointer.
// This names the sole C++ constructor body; it defines no additional function.
CarpenterShopScene * __18CarpenterShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** continuation, GameStateSaveImage * save);

EXTERN_C_END

#pragma interface "scene_carpenter_shop.hh"


// The original directory contains twenty fixed-width construction options.
// option_id values remain raw until the underlying construction enum is
// decompiled, while the pointer and cost fields reflect their ROM layout.
struct CarpenterCatalogEntry
{
    char const * menu_text;
    u32 gold_cost;
    u32 lumber_cost;
    u32 option_id;
    char const * detail_text;
};

extern char const gText_Carpenter_Lumber[];
extern char const gText_Carpenter_GoldenLumber[];
extern char const gText_Carpenter_HouseExtension[];
extern char const gText_Carpenter_HouseExtensionFirstCost[];
extern char const gText_Carpenter_HouseExtensionSecondCost[];
extern char const gText_Carpenter_AddBathtub[];
extern char const gText_Carpenter_BathtubCost[];
extern char const gText_Carpenter_ExpandChickenCoop[];
extern char const gText_Carpenter_ChickenCoopCost[];
extern char const gText_Carpenter_ExpandBarn[];
extern char const gText_Carpenter_BarnCost[];
extern char const gText_Carpenter_BuildVacationHouse[];
extern char const gText_Carpenter_VacationHouseCost[];
extern char const gText_Carpenter_RemodelWindow[];
extern char const gText_Carpenter_Rebuild[];
extern char const gText_Carpenter_RemodelDoghouse[];
extern char const gText_Carpenter_RemodelMailbox[];
extern char const gText_Carpenter_SquareWindowWithShutters[];
extern char const gText_Carpenter_WindowCost[];
extern char const gText_Carpenter_SquareWindowWithoutShutters[];
extern char const gText_Carpenter_RoundWindow[];
extern char const gText_Carpenter_RedDoghouse[];
extern char const gText_Carpenter_DoghouseCost[];
extern char const gText_Carpenter_BlueDoghouse[];
#if defined(REGION_DE)
extern char const gText_Carpenter_BlueDoghouseCost[];
#endif
extern char const gText_Carpenter_StrangeDoghouse[];
extern char const gText_Carpenter_RedMailbox[];
extern char const gText_Carpenter_MailboxCost[];
extern char const gText_Carpenter_BlueMailbox[];
extern char const gText_Carpenter_StrangeMailbox[];

extern char const gText_Carpenter_RebuildRequirements[];
extern char const gText_Carpenter_InsufficientGold[];
extern char const gText_Carpenter_LumberBinFull[];
extern char const gText_Carpenter_LumberHeader[];
extern char const gText_Carpenter_EquipmentFull[];
extern char const gText_Carpenter_GoldenLumberHeader[];
extern char const gText_Carpenter_CannotAcceptAnotherJob[];
extern char const gText_Carpenter_InsufficientLumber[];
extern char const gText_Carpenter_ThreeDayConfirmation[];
extern char const gText_Carpenter_NeedAnythingElse[];
extern char const gText_Carpenter_AreYouSureNow[];
extern char const gText_Carpenter_SameCurrentShape[];
extern char const gText_Carpenter_StoreLumber[];
extern char const gText_Carpenter_DeliveryAll[];
extern char const gText_Carpenter_DeliverySome[];
extern char const gText_Carpenter_PurchaseComplete[];
extern char const gText_Carpenter_Build[];
extern char const gText_Carpenter_DontBuild[];
extern char const gText_Carpenter_Upgrade[];
extern char const gText_Carpenter_DontUpgrade[];
extern char const gText_Carpenter_StartUpgradeTomorrow[];
#if defined(REGION_US) || defined(REGION_EU)
extern char const gText_Carpenter_ConfirmUpgrade[];
#endif
extern char const gText_Carpenter_NeedAnythingMore[];
extern char const gText_Carpenter_InitialPageBreak[];

extern CarpenterCatalogEntry const gCarpenterCatalog[];

#endif // SCENE_CARPENTER_SHOP_HH
