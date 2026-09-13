#include "winery_shop_data.hh"

#include "item.hh"

WineryShopCatalogEntry const gWineryShopCatalog[] = {
    { ITEM_FOOD_WINE, 300 },
    { ITEM_FOOD_GRAPE_JUICE, 200 },
};

#include FOMT_TEXT_INCLUDE(winery_shop_data.cc)
