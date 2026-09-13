#include "special_merchant_shop_data.hh"

#include "item.hh"

SpecialMerchantShopCatalogEntry const gSpecialMerchantShopCatalog[] = {
    { ITEM_ARTICLE_ALBUM_1, 500 },
    { ITEM_ARTICLE_ALBUM_2, 600 },
    { ITEM_ARTICLE_ALBUM_3, 700 },
    { ITEM_ARTICLE_ALBUM_4, 800 },
    { ITEM_ARTICLE_ALBUM_5, 900 },
    { ITEM_ARTICLE_ALBUM_6, 1000 },
    { ITEM_ARTICLE_ALBUM_7, 1100 },
    { ITEM_ARTICLE_ALBUM_8, 1200 },
    { ITEM_ARTICLE_ALBUM_9, 1300 },
    { ITEM_ARTICLE_ALBUM_10, 1400 },
    { SPECIAL_MERCHANT_RECORD_PLAYER_SENTINEL, 2000 },
    { ITEM_ARTICLE_COPPER, 150 },
    { ITEM_ARTICLE_SILVER, 200 },
    { ITEM_ARTICLE_GOLD, 250 },
    { ITEM_ARTICLE_MYSTRILE, 400 },
};

#include FOMT_TEXT_INCLUDE(special_merchant_shop_data.cc)
