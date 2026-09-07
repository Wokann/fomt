#include "livestock_shop.hh"

#if defined(FOMT_LIVESTOCK_SHOP_TEXT_MENU)

char const gText_LivestockShop_Empty[] =
    "";

char const gText_LivestockShop_BuyCow[] =
    "Buy Cow";

char const gText_LivestockShop_BuySheep[] =
    "Buy Sheep";

char const gText_LivestockShop_SellCow[] =
    "Sell Cow";

char const gText_LivestockShop_SellSheep[] =
    "Sell Sheep";

#elif defined(FOMT_LIVESTOCK_SHOP_TEXT_STATUS)

char const gText_LivestockShop_PageBreak[] =
    "\p";

char const gText_LivestockShop_StatusSick[] =
    "　　　Sick　  ";

char const gText_LivestockShop_StatusUnhappy[] =
    "　　　Unhappy ";

char const gText_LivestockShop_StatusHealthy[] =
    "　　　Healthy ";

char const gText_LivestockShop_StatusSpacer[] =
    " ";

char const gText_LivestockShop_Age[] =
    "years old\r\n　　　　　    ";

char const gText_LivestockShop_Spring[] =
    "Spring";

char const gText_LivestockShop_Summer[] =
    "Summer";

char const gText_LivestockShop_Autumn[] =
    "Fall";

char const gText_LivestockShop_Winter[] =
    "Winter";

char const gText_LivestockShop_DailySellingPrice[] =
    "D\r\nSelling Price　 ";

char const gText_LivestockShop_Currency[] =
    "G";

char const gText_LivestockShop_SecondaryStatusSick[] =
    "　　　Sick  　";

char const gText_LivestockShop_SecondaryAge[] =
    "years old \r\n　　　　　    ";

char const gText_LivestockShop_SecondaryDailySellingPrice[] =
    "D \r\nSelling Price　　 ";

#elif defined(FOMT_LIVESTOCK_SHOP_TEXT_DIALOGUE)

char const gText_LivestockShop_InsufficientGold[] =
    "You don't have enough gold!{Press}";

char const gText_LivestockShop_FeedBinFull[] =
    "The Feed Bin is already\r\n"
    "full, don't you know...{Press}";

char const gText_LivestockShop_BlankLinePair[] =
    "\r\n"
    "\r\n";

char const gText_LivestockShop_InventoryFull[] =
    "You can't hold \r\n"
    "anything else! {Press}";

char const gText_LivestockShop_BarnFull[] =
    "The Barn is full...!{Press}";

char const gText_LivestockShop_NameAnimalPrompt[] =
    "Will you do the naming\r\n"
    "for me?{Press}";

char const gText_LivestockShop_NoCowsToSell[] =
    "I don't have any cows\r\n"
    "to sell at all...{Press}";

char const gText_LivestockShop_NoSheepToSell[] =
    "I don't have any sheep\r\n"
    "to sell at all...{Press}";

char const gText_LivestockShop_ComeAgain[] =
    "Just let me know if you\r\n"
    "want to buy anything, now.{Press}";

char const gText_LivestockShop_PurchaseConfirmation[] =
    "You're sure now?{Press}";

char const gText_LivestockShop_PricePromptPrefix[] =
    "How about ";

char const gText_LivestockShop_PricePromptSuffix[] =
    " G?";

char const gText_LivestockShop_Yes[] =
    "Yes";

char const gText_LivestockShop_No[] =
    "No";

char const gText_LivestockShop_FeedPurchaseComplete[] =
    "I'll put this here Chicken\r\n"
    "Feed in the Feed Bin, now.{Press}";

char const gText_LivestockShop_PurchaseDeliveryPartial[] =
    "Come any time.{Press}\p"
    "Since you can't hold\r\n"
    "all of this, I'll deliver\r\n"
    "it, OK?{Press}";

char const gText_LivestockShop_PurchaseDeliveryAll[] =
    "Come any time.{Press}\p"
    "Since you can't hold\r\n"
    "anything else, I'll deliver\r\n"
    "it, OK?{Press}";

char const gText_LivestockShop_PurchaseComplete[] =
    "Come any time.{Press}";

char const gText_LivestockShop_AnimalPurchaseComplete[] =
    "I'll put 'er in the barn \r\n"
    "for you. Thanks!{Press}";

char const gText_LivestockShop_PurchaseMorePrompt[] =
    "Not interested in anything\r\n"
    "else?{Press}";

char const gText_LivestockShop_PurchaseDeclinedPrefix[] =
    "Alright...{Press}\p"
    "Then, ";

char const gText_LivestockShop_AnimalDelivery[] =
    " I'll take\r\n"
    "it from the pastor's barn.{Press}";

#else
#error "Include this file through src/livestock_shop.cc with a text partition."
#endif
