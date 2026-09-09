#include "winery_shop_text.hh"

#include "item.hh"

WineryShopCatalogEntry const gWineryShopCatalog[] = {
    { FOOD_WINE, 300 },
    { FOOD_GRAPE_JUICE, 200 },
};

#if defined(REGION_JP)
#include "data/text/jp/winery_shop.cc"
#else
#include "data/text/us/winery_shop.cc"
#endif
