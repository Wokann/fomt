#include "livestock_shop.hh"

#if defined(FOMT_LIVESTOCK_SHOP_TEXT_MENU)

char const gText_LivestockShop_Empty[] =
    "";

char const gText_LivestockShop_BuyCowPrimary[] =
    "Kuh kaufen.";

char const gText_LivestockShop_BuyCow[] =
    "Kuh kaufen";

char const gText_LivestockShop_BuySheep[] =
    "Schaf kaufen";

char const gText_LivestockShop_SellCow[] =
    "Kuh verkaufen";

char const gText_LivestockShop_SellSheep[] =
    "Schaf verkaufen";

#elif defined(FOMT_LIVESTOCK_SHOP_TEXT_STATUS)

char const gText_LivestockShop_PageBreak[] =
    "\p";

char const gText_LivestockShop_StatusSick[] =
    "　　　Krank   ";

char const gText_LivestockShop_StatusUnhappy[] =
    " Unglücklich";

char const gText_LivestockShop_StatusHealthy[] =
    "　　　Gesund  ";

char const gText_LivestockShop_StatusSpacer[] =
    " ";

char const gText_LivestockShop_Age[] =
    "Jahre alt\r\n　　　　　";

char const gText_LivestockShop_Spring[] =
    "Frühling";

char const gText_LivestockShop_Summer[] =
    "Sommer";

char const gText_LivestockShop_Autumn[] =
    "Herbst";

char const gText_LivestockShop_Winter[] =
    "Winter";

char const gText_LivestockShop_DailySellingPrice[] =
    "D\r\nVerkaufspreis   ";

char const gText_LivestockShop_Currency[] =
    "G";

char const gText_LivestockShop_SecondaryStatusSick[] =
    "　　　Krank 　";

char const gText_LivestockShop_SecondaryAge[] =
    "Jahre alt \r\n　　　　  ";

char const gText_LivestockShop_SecondaryDailySellingPrice[] =
    "D \r\nVerkaufspreis　　 ";

#elif defined(FOMT_LIVESTOCK_SHOP_TEXT_DIALOGUE)

char const gText_LivestockShop_InsufficientGold[] =
    "Du hast nicht genug Gold!{Press}";

char const gText_LivestockShop_FeedBinFull[] =
    "Der Futtereimer ist\r\n"
    "schon voll, siehst du nicht?{Press}";

char const gText_LivestockShop_BlankLinePair[] =
    "\r\n"
    "\r\n";

char const gText_LivestockShop_InventoryFull[] =
    "Du kannst nichts \r\n"
    "anderes mehr tragen! {Press}";

char const gText_LivestockShop_BarnFull[] =
    "Die Scheune ist voll...!{Press}";

char const gText_LivestockShop_NameAnimalPrompt[] =
    "Benennst du sie\r\n"
    "für mich?{Press}";

char const gText_LivestockShop_NoCowsToSell[] =
    "Ich habe überhaupt\r\n"
    "keine Kühe zu verkaufen...{Press}";

char const gText_LivestockShop_NoSheepToSell[] =
    "Ich habe überhaupt keine\r\n"
    "Schafe zu verkaufen...{Press}";

char const gText_LivestockShop_ComeAgain[] =
    "Sag mir einfach, wenn du\r\n"
    "etwas kaufen willst.{Press}";

char const gText_LivestockShop_PurchaseConfirmation[] =
    "Bist du sicher?{Press}";

char const gText_LivestockShop_PricePromptPrefix[] =
    "Wie wären";

char const gText_LivestockShop_PricePromptSuffix[] =
    " G?";

char const gText_LivestockShop_Yes[] =
    "Ja";

char const gText_LivestockShop_No[] =
    "Nein";

char const gText_LivestockShop_FeedPurchaseComplete[] =
    "Ich tue das Hühnerfutter\r\n"
    "jetzt in den Eimer.{Press}";

char const gText_LivestockShop_PurchaseDeliveryPartial[] =
    "Komm jederzeit.{Press}\p"
    "Da du das nicht alles\r\n"
    "tragen kannst, liefere\r\n"
    "ich es dir, Ok?{Press}";

char const gText_LivestockShop_PurchaseDeliveryAll[] =
    "Komm jederzeit.{Press}\p"
    "Da du nichts mehr tragen\r\n"
    "kannst, liefere ich es\r\n"
    "dir, Ok?{Press}";

char const gText_LivestockShop_PurchaseComplete[] =
    "Komm jederzeit.{Press}";

char const gText_LivestockShop_AnimalPurchaseComplete[] =
    "Ich bringe sie für \r\n"
    "dich in die Scheune. Danke!{Press}";

char const gText_LivestockShop_PurchaseMorePrompt[] =
    "An nichts anderem\r\n"
    "interessiert?{Press}";

char const gText_LivestockShop_PurchaseDeclinedPrefix[] =
    "Na gut...{Press}\p"
    "Dann, ";

char const gText_LivestockShop_AnimalDeliveryLineBreak[] =
    "\r\n";

char const gText_LivestockShop_AnimalDelivery[] =
    "Ich hole es von der Scheune\r\n"
    "des Priesters.{Press}";

#else
#error "Include this file through src/livestock_shop.cc with a text partition."
#endif
