#include "special_merchant_shop_text.hh"

#include "item.hh"

SpecialMerchantShopCatalogEntry const gSpecialMerchantShopCatalog[] = {
    { ARTICLE_ALBUM_1, 500 },
    { ARTICLE_ALBUM_2, 600 },
    { ARTICLE_ALBUM_3, 700 },
    { ARTICLE_ALBUM_4, 800 },
    { ARTICLE_ALBUM_5, 900 },
    { ARTICLE_ALBUM_6, 1000 },
    { ARTICLE_ALBUM_7, 1100 },
    { ARTICLE_ALBUM_8, 1200 },
    { ARTICLE_ALBUM_9, 1300 },
    { ARTICLE_ALBUM_10, 1400 },
    { SPECIAL_MERCHANT_RECORD_PLAYER_SENTINEL, 2000 },
    { ARTICLE_COPPER, 150 },
    { ARTICLE_SILVER, 200 },
    { ARTICLE_GOLD, 250 },
    { ARTICLE_MYSTRILE, 400 },
};

#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(special_merchant_shop.cc)
#else
#include FOMT_TEXT_INCLUDE(special_merchant_shop.cc)
#endif
