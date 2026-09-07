#include "livestock_shop.hh"

#if defined(FOMT_LIVESTOCK_SHOP_TEXT_MENU)

char const gText_LivestockShop_Empty[] =
    "";

char const gText_LivestockShop_BuyCow[] =
    "牛を買う";

char const gText_LivestockShop_BuySheep[] =
    "羊を買う";

char const gText_LivestockShop_SellCow[] =
    "牛を売る";

char const gText_LivestockShop_SellSheep[] =
    "羊を売る";

#elif defined(FOMT_LIVESTOCK_SHOP_TEXT_STATUS)

char const gText_LivestockShop_PageBreak[] =
    "\p";

char const gText_LivestockShop_StatusSick[] =
    "　　　　　　　　病気　";

char const gText_LivestockShop_StatusUnhappy[] =
    "　　　　　　　不機嫌　";

char const gText_LivestockShop_StatusHealthy[] =
    "　　　　　　　　健康　";

char const gText_LivestockShop_StatusSpacer[] =
    "　";

char const gText_LivestockShop_Age[] =
    "才\r\n　　　　　　　　　";

char const gText_LivestockShop_Spring[] =
    "春";

char const gText_LivestockShop_Summer[] =
    "夏";

char const gText_LivestockShop_Autumn[] =
    "秋";

char const gText_LivestockShop_Winter[] =
    "冬";

char const gText_LivestockShop_DailySellingPrice[] =
    "日\r\n買取額　　　　　";

char const gText_LivestockShop_Currency[] =
    "Ｇ";

char const gText_LivestockShop_SecondaryDailySellingPrice[] =
    "日\r\n買取額　　　　　　";

#elif defined(FOMT_LIVESTOCK_SHOP_TEXT_DIALOGUE)

char const gText_LivestockShop_InsufficientGold[] =
    "お金が足りないみたいじゃの。{Press}";

char const gText_LivestockShop_FeedBinFull[] =
    "すでにサイロが飼い葉でいっぱ\r\n"
    "いだ…{Press}";

char const gText_LivestockShop_BlankLinePair[] =
    "\r\n"
    "\r\n";

char const gText_LivestockShop_InventoryFull[] =
    "なんじゃ、\r\n"
    "装備が入らないみたいじゃの。{Press}";

char const gText_LivestockShop_BarnFull[] =
    "動物小屋はいっぱいだ…{Press}";

char const gText_LivestockShop_NameAnimalPrompt[] =
    "それじゃあ、名前をつけてやっ\r\n"
    "てくれんかの？{Press}";

char const gText_LivestockShop_NoCowsToSell[] =
    "売れる牛が１頭もいない…{Press}";

char const gText_LivestockShop_NoSheepToSell[] =
    "売れる羊が１頭もいない…{Press}";

char const gText_LivestockShop_ComeAgain[] =
    "何か買いたいもんがあったら、\r\n"
    "また声をかけてくれるとええ。{Press}";

char const gText_LivestockShop_PurchaseConfirmation[] =
    "おや、いいのかの？{Press}";

char const gText_LivestockShop_PricePrompt[] =
    "Ｇでどうかの？";

char const gText_LivestockShop_Yes[] =
    "はい";

char const gText_LivestockShop_No[] =
    "いいえ";

char const gText_LivestockShop_FeedPurchaseComplete[] =
    "それじゃあ飼い葉は、\r\n"
    "サイロに入れておくからの。\r\n"
    "まいどあり。{Press}";

char const gText_LivestockShop_PurchaseDeliveryPartial[] =
    "まいどあり。\r\n"
    "何個か装備が入らないみたいじ\r\n"
    "ゃの。{Press}\p"
    "後で家に届けておくよ。{Press}";

char const gText_LivestockShop_PurchaseDeliveryAll[] =
    "まいどあり。\r\n"
    "装備がいっぱいみたいじゃの。\r\n"
    "後で家に届けておくよ。{Press}";

char const gText_LivestockShop_PurchaseComplete[] =
    "まいどあり。{Press}";

char const gText_LivestockShop_AnimalPurchaseComplete[] =
    "じゃあ、小屋の中に入れておく\r\n"
    "からの。まいどあり。{Press}";

char const gText_LivestockShop_PurchaseMorePrompt[] =
    "他に買うもんはないのかの？{Press}";

char const gText_LivestockShop_PurchaseDeclinedPrefix[] =
    "そうか…{Press}\p"
    "じゃあ、";

char const gText_LivestockShop_AnimalDelivery[] =
    "牧場さん\r\n"
    "の動物小屋から連れて行くから\r\n"
    "の。{Press}";

#else
#error "Include this file through src/livestock_shop.cc with a text partition."
#endif
