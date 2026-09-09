#include "poultry_shop_text.hh"

#if defined(FOMT_TEXT_POULTRY_SHOP_MENU)

char const gText_PoultryShop_Empty[] =
    "";

char const gText_PoultryShop_BuyChicken[] =
    "鶏を買う";

char const gText_PoultryShop_SellChicken[] =
    "鶏を売る";

#elif defined(FOMT_TEXT_POULTRY_SHOP_STATUS)

char const gText_PoultryShop_PageBreak[] =
    "\p";

char const gText_PoultryShop_StatusSick[] =
    "　　　　　　　　病気　";

char const gText_PoultryShop_StatusUnhappy[] =
    "　　　　　　　不機嫌　";

char const gText_PoultryShop_StatusHealthy[] =
    "　　　　　　　　健康　";

char const gText_PoultryShop_StatusSpacer[] =
    "　";

char const gText_PoultryShop_Age[] =
    "才\r\n"
    "　　　　　　　　　";

char const gText_PoultryShop_Spring[] =
    "春";

char const gText_PoultryShop_Summer[] =
    "夏";

char const gText_PoultryShop_Autumn[] =
    "秋";

char const gText_PoultryShop_Winter[] =
    "冬";

char const gText_PoultryShop_DailySellingPrice[] =
    "日\r\n"
    "買取額　　　　　　";

char const gText_PoultryShop_Currency[] =
    "Ｇ";

char const gText_PoultryShop_InsufficientGold[] =
    "あら～、\r\n"
    "お金が足りないみたいねぇ。{Press}";

char const gText_PoultryShop_FeedBinFull[] =
    "こんなにたくさんエサ置き場に\r\n"
    "入らない。{Press}";

char const gText_PoultryShop_BlankLinePair[] =
    "\r\n"
    "\r\n";

char const gText_PoultryShop_InventoryFull[] =
    "あらぁ、\r\n"
    "もう持てないみたいよぉ。{Press}";

char const gText_PoultryShop_CoopFull[] =
    "牧場の鶏小屋は、\r\n"
    "すでにいっぱいだ…{Press}";

char const gText_PoultryShop_NameChickenPrompt[] =
    "鶏を飼うのなら、名前をつけて\r\n"
    "あげて～。{Press}";

char const gText_PoultryShop_NoChickensToSell[] =
    "売ることのできる鶏を飼ってい\r\n"
    "ない…{Press}";

char const gText_PoultryShop_NotInterested[] =
    "もういらないの～？{Press}";

char const gText_PoultryShop_PurchaseDeclined[] =
    "え～買わないのぉ？{Press}";

char const gText_PoultryShop_PricePrompt[] =
    "Ｇで買うわよ～。";

char const gText_PoultryShop_Yes[] =
    "はい";

char const gText_PoultryShop_No[] =
    "いいえ";

char const gText_PoultryShop_FeedPurchaseComplete[] =
    "ありがと～、また来てねぇ。\r\n"
    "買ってくれたエサは、牧場のエ\r\n"
    "サ置き場に置いておくように、{Press}\p"
    "リックに言っておくから～。{Press}";

char const gText_PoultryShop_PurchaseDeliveryPartial[] =
    "ありがと～、また来てねぇ。\r\n"
    "あらぁ？\r\n"
    "何個か持てないみたいねぇ。{Press}\p"
    "後で届けておくように、\r\n"
    "リックに言っておくから～。{Press}";

char const gText_PoultryShop_MedicinePurchaseComplete[] =
    "ありがと～、また来てねぇ。\r\n"
    "買ってくれた薬は、\r\n"
    "後で届けておくように、{Press}\p"
    "リックに言っておくから～。{Press}";

char const gText_PoultryShop_PurchaseComplete[] =
    "ありがと～、また来てねぇ。{Press}";

char const gText_PoultryShop_ChickenPurchaseComplete[] =
    "買ってくれた鶏は、牧場の鶏小\r\n"
    "屋に入れておくように、\r\n"
    "リックに言っておくから～。{Press}";

char const gText_PoultryShop_PurchaseMorePrompt[] =
    "他にも何か買う～？{Press}";

char const gText_PoultryShop_ChickenSold[] =
    "売ってくれた鶏は、牧場の鶏小\r\n"
    "屋から連れてくるようにリック\r\n"
    "に言っておくから～。{Press}";

extern char const gCppRuntimeBadAlloc_PoultryShopTrailer[] =
    "bad_alloc";

#else
#error "Select one poultry-shop text fragment before including this file."
#endif