#include "poultry_shop_data.hh"

#include "item.hh"

#include FOMT_TEXT_INCLUDE(poultry_shop_data.cc)

PoultryShopCatalogEntry const gPoultryShopCatalog[] = {
    { ITEM_ARTICLE_CHICKEN_FEED, gText_PoultryShop_Empty, 10, gText_PoultryShop_Empty, 0 },
    { ITEM_TOOL_ANIMAL_MEDICINE, gText_PoultryShop_Empty, 1000, gText_PoultryShop_Empty, 1 },
    { 2, gText_PoultryShop_BuyChicken, 1500, gText_PoultryShop_BuyChicken, 2 },
    { 3, gText_PoultryShop_SellChicken, 0, gText_PoultryShop_SellChicken, 3 },
    { 4, gText_PoultryShop_Empty, 0, gText_PoultryShop_Empty, 4 },
};

#include FOMT_TEXT_INCLUDE(poultry_shop_data_1.cc)
#include "data/text/common/poultry_shop_data_1.cc"
