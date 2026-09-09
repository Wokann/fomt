#ifndef WON_SHOP_TEXT_HH
#define WON_SHOP_TEXT_HH

#include "prelude.h"

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
extern char const gCppRuntimeBadAlloc_WonShopTrailer[];

#endif // WON_SHOP_TEXT_HH
