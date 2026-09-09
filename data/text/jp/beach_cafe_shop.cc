#include "beach_cafe_shop_text.hh"

#if defined(FOMT_TEXT_BEACH_CAFE_SHOP_DESCRIPTIONS)

char const gText_BeachCafeShop_WaterDescription[] =
    "水\r\n"
    "何の変哲もないただの水。";

char const gText_BeachCafeShop_EmptyDescription[] =
    "";

char const gText_BeachCafeShop_SpaghettiDescription[] =
    "スパゲッティ\r\n"
    "イタリアのめん料理。";

char const gText_BeachCafeShop_SnowConeDescription[] =
    "かき氷\r\n"
    "氷をこまかく砕いて作った\r\n"
    "お菓子。";

#elif defined(FOMT_TEXT_BEACH_CAFE_SHOP_DIALOGUE)

char const gText_BeachCafeShop_InsufficientGold[] =
    "おい、金が足りねぇよ。{Press}";

char const gText_BeachCafeShop_NoOrder[] =
    "それじゃ。\r\n"
    "あ、なんか食うんだったら、\r\n"
    "また声かけてよ。{Press}";

char const gText_BeachCafeShop_OrderComplete[] =
    "ＯＫ、ちょっと待って…………\r\n"
    "おまたせ、味わって食えよ。{Press}";

char const gCppRuntimeBadAlloc_BeachCafeShopTrailer[] =
    "bad_alloc";

#else
#error "Select one beach_cafe_shop text fragment before including this file."
#endif
