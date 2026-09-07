#ifndef WINERY_SHOP_TEXT_HH
#define WINERY_SHOP_TEXT_HH

#include "prelude.h"

struct WineryShopCatalogEntry
{
    u32 food_id;
    u32 price;
};

#define WINERY_SHOP_CATALOG SECTION(".rodata.winery_shop_catalog")
#define WINERY_SHOP_DIALOGUE SECTION(".rodata.winery_shop_dialogue")
#define WINERY_SHOP_TRAILER SECTION(".rodata.winery_shop_trailer")

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
extern char const gCppRuntimeBadAlloc_WineryShopTrailer[];

#endif // WINERY_SHOP_TEXT_HH
