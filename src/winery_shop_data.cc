#include "winery_shop_text.hh"

#include "item.hh"

WineryShopCatalogEntry const gWineryShopCatalog[] = {
    { ITEM_FOOD_WINE, 300 },
    { ITEM_FOOD_GRAPE_JUICE, 200 },
};

#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(winery_shop.cc)
#else
#include FOMT_TEXT_INCLUDE(winery_shop.cc)
#endif
