#include "inn_shop_text.hh"

#if defined(FOMT_TEXT_INN_SHOP_DESCRIPTIONS)

char const gText_InnShop_WaterDescription[] =
    "水\r\n"
    "何の変哲もないただの水。";

char const gText_InnShop_BoxLunchDescription[] =
    "定食\r\n"
    "宿屋さんでお昼の間だけ\r\n"
    "売っている。";

char const gText_InnShop_Empty[] =
    "";

char const gText_InnShop_MilkDescription[] =
    "牛乳\r\n"
    "牛の乳をしぼった飲み物。";

#elif defined(FOMT_TEXT_INN_SHOP_DIALOGUE)

char const gText_InnShop_InsufficientGold[] =
    "金が足りねぇぞ。\r\n"
    "出直して来い。{Press}";

char const gText_InnShop_NoOrder[] =
    "なんだ、いいのか？\r\n"
    "注文なら、\r\n"
    "いつでも聞くからな。{Press}";

char const gText_InnShop_OrderComplete[] =
    "まいど！\r\n"
    "ちょっと待ってくれよ…\r\n"
    "ほら、お待ちどうっ！{Press}";

extern char const gCppRuntimeBadAlloc_InnShopTrailer[] =
    "bad_alloc";

#else
#error "Select one inn_shop text fragment before including this file."
#endif
