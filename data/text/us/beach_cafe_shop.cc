#include "beach_cafe_shop_text.hh"

#if defined(FOMT_TEXT_BEACH_CAFE_SHOP_DESCRIPTIONS)

char const gText_BeachCafeShop_WaterDescription[] =
    "Water. Just plain old water.";

char const gText_BeachCafeShop_EmptyDescription[] =
    "";

char const gText_BeachCafeShop_SpaghettiDescription[] =
    "Some delicious-looking\r\n"
    "spaghetti.";

char const gText_BeachCafeShop_SnowConeDescription[] =
    "Snow-cone. Crushed ice\r\n"
    "with syrup.";

#elif defined(FOMT_TEXT_BEACH_CAFE_SHOP_DIALOGUE)

char const gText_BeachCafeShop_InsufficientGold[] =
    "Hey, you don't have \r\n"
    "enough money!{Press}";

char const gText_BeachCafeShop_NoOrder[] =
    "If you get hungry again,\r\n"
    "just come back, OK?!{Press}";

char const gText_BeachCafeShop_OrderComplete[] =
    "Wait one second....\r\n"
    "There you are. Enjoy!{Press}";

char const gCppRuntimeBadAlloc_BeachCafeShopTrailer[] =
    "bad_alloc";

#else
#error "Select one beach_cafe_shop text fragment before including this file."
#endif
