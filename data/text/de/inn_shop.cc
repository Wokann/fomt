#include "inn_shop_text.hh"

#if defined(FOMT_TEXT_INN_SHOP_DESCRIPTIONS)

char const gText_InnShop_WaterDescription[] =
    "Water. Just plain old water.";

char const gText_InnShop_BoxLunchDescription[] =
    "Box Lunch.\r\n"
    "Sold only at the Hotel\r\n"
    "in the afternoon.";

char const gText_InnShop_Empty[] =
    "";

char const gText_InnShop_MilkDescription[] =
    "Milk. Freshly squeezed.";

#elif defined(FOMT_TEXT_INN_SHOP_DIALOGUE)

char const gText_InnShop_InsufficientGold[] =
    "You don't have enough\r\n"
    "Gold. Come back later.{Press}";

char const gText_InnShop_NoOrder[] =
    "So you don't want\r\n"
    "anything? You sure?\r\n"
    "Come back any time now!{Press}";

char const gText_InnShop_OrderComplete[] =
    "Thanks!\r\n"
    "Wait one moment...\r\n"
    "OK, here you are!{Press}";

extern char const gCppRuntimeBadAlloc_InnShopTrailer[] =
    "bad_alloc";

#else
#error "Select one inn_shop text fragment before including this file."
#endif
