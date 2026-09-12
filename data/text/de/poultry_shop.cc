#include "poultry_shop_text.hh"

#if defined(FOMT_TEXT_POULTRY_SHOP_MENU)

char const gText_PoultryShop_Empty[] =
    "";

char const gText_PoultryShop_BuyChicken[] =
    "Huhn kaufen";

char const gText_PoultryShop_SellChicken[] =
    "Huhn verkaufen";

#elif defined(FOMT_TEXT_POULTRY_SHOP_STATUS)

char const gText_PoultryShop_PageBreak[] =
    "\p";

char const gText_PoultryShop_StatusSick[] =
    "　　　Krank";

char const gText_PoultryShop_StatusUnhappy[] =
    "　　　Ungesund  ";

char const gText_PoultryShop_StatusHealthy[] =
    "　　　Gesund  ";

char const gText_PoultryShop_StatusSpacer[] =
    " ";

char const gText_PoultryShop_Age[] =
    "Jahre alt\r\n"
    "          ";

char const gText_PoultryShop_Spring[] =
    "Frühling";

char const gText_PoultryShop_Summer[] =
    "Sommer";

char const gText_PoultryShop_Autumn[] =
    "Herbst";

char const gText_PoultryShop_Winter[] =
    "Winter";

char const gText_PoultryShop_DailySellingPrice[] =
    "D\r\n"
    "Verkaufspreis　   ";

char const gText_PoultryShop_Currency[] =
    "G";

char const gText_PoultryShop_InsufficientGold[] =
    "Tut mir leid...\r\n"
    "Du hast nicht genug Gold.{Press}";

char const gText_PoultryShop_FeedBinFull[] =
    "So viel Futter passt nicht\r\n"
    "in deinen Eimer!{Press}";

char const gText_PoultryShop_BlankLinePair[] =
    "\r\n"
    "\r\n";

char const gText_PoultryShop_InventoryFull[] =
    "Sieht aus, also könntest\r\n"
    "du nicht mehr halten.{Press}";

char const gText_PoultryShop_CoopFull[] =
    "Dein Hühnerstall\r\n"
    "ist schon voll!{Press}";

char const gText_PoultryShop_NameChickenPrompt[] =
    "Die Hühner mögen es,\r\n"
    "wenn du ihnen Namen gibst.{Press}";

char const gText_PoultryShop_NoChickensToSell[] =
    "Du hast keine Hühner, die\r\n"
    "du verkaufen könntest...!{Press}";

char const gText_PoultryShop_NotInterested[] =
    "Sicher, dass du nicht\r\n"
    "interessiert bist?{Press}";

char const gText_PoultryShop_PurchaseDeclined[] =
    "Also kaufst du kein...?{Press}";

char const gText_PoultryShop_PricePromptPrefix[] =
    "Ich kaufe es für";

char const gText_PoultryShop_PricePromptSuffix[] =
    "G.";

char const gText_PoultryShop_Yes[] =
    "Ja";

char const gText_PoultryShop_No[] =
    "Nein";

char const gText_PoultryShop_FeedPurchaseComplete[] =
    "Danke! Komm bald wieder.{Press}\p"
    "Ich sage Rick, er soll das\r\n"
    "Futter das du gekauft hast\r\n"
    "in deinen Futtereimer tun.{Press}";

char const gText_PoultryShop_PurchaseDeliveryPartial[] =
    "Danke! Komm bald wieder.{Press}\p"
    "Oh...scheint, als könntest\r\n"
    "du nicht so viele tragen.\r\n"
    "Ich werde Rick bitten,{Press}\r\n"
    "sie zu liefern.{Press}";

char const gText_PoultryShop_MedicinePurchaseComplete[] =
    "Danke! Komm bald wieder.\r\n"
    "Rick wird dir die gekaufte\r\n"
    "Medizin liefern.{Press}";

char const gText_PoultryShop_PurchaseComplete[] =
    "Danke! Komm bald wieder.{Press}";

char const gText_PoultryShop_ChickenPurchaseComplete[] =
    "Ich sage Rick, er soll die\r\n"
    "Hühner, die du gekauft hast,\r\n"
    "in deinen Stall bringen.{Press}";

char const gText_PoultryShop_PurchaseMorePrompt[] =
    "Brauchst du noch etwas?{Press}";

char const gText_PoultryShop_ChickenSold[] =
    "Ich bitte Rick, die Hühner,\r\n"
    "die du verkauft hast, aus\r\n"
    "deinem Stall zu holen.{Press}";

extern char const gCppRuntimeBadAlloc_PoultryShopTrailer[] =
    "bad_alloc";

#else
#error "Select one poultry-shop text fragment before including this file."
#endif
