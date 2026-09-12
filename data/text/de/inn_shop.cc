#include "inn_shop_text.hh"

#if defined(FOMT_TEXT_INN_SHOP_DESCRIPTIONS)

char const gText_InnShop_WaterDescription[] =
    "Wasser. Gutes altes Wasser.";

char const gText_InnShop_BoxLunchDescription[] =
    "Lunch in der Box.\r\n"
    "Wird nur nachmittags\r\n"
    "im Hotel verkauft.";

char const gText_InnShop_Empty[] =
    "";

char const gText_InnShop_MilkDescription[] =
    "Milch. Frisch gemolken.";

#elif defined(FOMT_TEXT_INN_SHOP_DIALOGUE)

char const gText_InnShop_InsufficientGold[] =
    "Du hast nicht genug\r\n"
    "Gold. Komm später wieder.{Press}";

char const gText_InnShop_NoOrder[] =
    "Du möchtest also\r\n"
    "nichts? Sicher?\r\n"
    "Komm jederzeit wieder!{Press}";

char const gText_InnShop_OrderComplete[] =
    "Danke!\r\n"
    "Warte einen Moment...\r\n"
    "OK, hier bitte!{Press}";

extern char const gCppRuntimeBadAlloc_InnShopTrailer[] =
    "bad_alloc";

#else
#error "Select one inn_shop text fragment before including this file."
#endif
