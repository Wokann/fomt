#include "poultry_shop_text.hh"

#include "item.hh"

#if defined(REGION_JP)
#include "data/text/jp/poultry_shop_menu.cc"
#else
#include "data/text/us/poultry_shop_menu.cc"
#endif

PoultryShopCatalogEntry const gPoultryShopCatalog[] = {
    { ARTICLE_CHICKEN_FEED, gText_PoultryShop_Empty, 10, gText_PoultryShop_Empty, 0 },
    { TOOL_ANIMAL_MEDICINE, gText_PoultryShop_Empty, 1000, gText_PoultryShop_Empty, 1 },
    { 2, gText_PoultryShop_BuyChicken, 1500, gText_PoultryShop_BuyChicken, 2 },
    { 3, gText_PoultryShop_SellChicken, 0, gText_PoultryShop_SellChicken, 3 },
    { 4, gText_PoultryShop_Empty, 0, gText_PoultryShop_Empty, 4 },
};

#if defined(REGION_JP)
#include "data/text/jp/poultry_shop_status.cc"
#else
#include "data/text/us/poultry_shop_status.cc"
#endif
