#include "beach_cafe_shop_text.hh"

#if defined(FOMT_TEXT_BEACH_CAFE_SHOP_DESCRIPTIONS)

char const gText_BeachCafeShop_WaterDescription[] =
    "Wasser. Gutes altes Wasser.";

char const gText_BeachCafeShop_EmptyDescription[] =
    "";

char const gText_BeachCafeShop_SpaghettiDescription[] =
    "Lecker aussehende\r\n"
    "Spaghetti.";

char const gText_BeachCafeShop_SnowConeDescription[] =
    "Schneekegel. Splittereis\r\n"
    "mit Sirup.";

#elif defined(FOMT_TEXT_BEACH_CAFE_SHOP_DIALOGUE)

char const gText_BeachCafeShop_InsufficientGold[] =
    "Hey, du hast \r\n"
    "nicht genug Geld!{Press}";

char const gText_BeachCafeShop_NoOrder[] =
    "Wenn du wieder Hunger\r\n"
    "kriegst, komm einfach\r\n"
    "wieder, OK?!{Press}";

char const gText_BeachCafeShop_OrderComplete[] =
    "Warte eine Sekunde....\r\n"
    "Hier bitte. Genieß es!{Press}";

char const gCppRuntimeBadAlloc_BeachCafeShopTrailer[] =
    "bad_alloc";

#else
#error "Select one beach_cafe_shop text fragment before including this file."
#endif
