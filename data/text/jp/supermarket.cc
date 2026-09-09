#include "supermarket_text.hh"

#if defined(FOMT_TEXT_SUPERMARKET_PRIMARY)

char const gText_Supermarket_EquipmentCapacityFull[] =
    "これ以上、\r\n"
    "装備を持つ事が出来ない…{Press}";

char const gText_Supermarket_BlankLinePair[] =
    "\r\n"
    "\r\n";

char const gText_Supermarket_InsufficientGold[] =
    "あ…あのぅ…、\r\n"
    "お金足りないんだけど…{Press}";

char const gText_Supermarket_ThankYou[] =
    "ありがとうございました。{Press}";

char const gText_Supermarket_PurchaseConfirmation[] =
    "あれ？\r\n"
    "いいの？{Press}";

char const gText_Supermarket_PurchaseMorePrompt[] =
    "他にも何か買う？{Press}";

char const gText_Supermarket_EquipmentDelivery[] =
    "ありがとうございました。{Press}\p"
    "あれ？\r\n"
    "装備がいっぱいだね。\r\n"
    "後で届けておくよ。{Press}";

char const gText_Supermarket_EquipmentDeliveryPartial[] =
    "ありがとうございました。{Press}\p"
    "あれ？\r\n"
    "装備が何個か入らないみたいだ\r\n"
    "ね。後で届けておくよ。{Press}";

#elif defined(FOMT_TEXT_SUPERMARKET_SECONDARY)

char const gText_Supermarket_SeedDelivery[] =
    "ありがとうございました。{Press}\p"
    "あれ？\r\n"
    "持ち物がいっぱいだね。\r\n"
    "後で届けておくよ。{Press}";

char const gText_Supermarket_SeedDeliveryPartial[] =
    "ありがとうございました。{Press}\p"
    "あれ？\r\n"
    "持ち物が何個か入らないみたい\r\n"
    "だね。後で届けておくよ。{Press}";

char const gText_Supermarket_SeedPurchaseConfirmation[] =
    "あれ…いいの？{Press}";

extern char const gCppRuntimeBadAlloc_SupermarketTrailer[] =
    "bad_alloc";

#else
#error "Select one supermarket text fragment before including this file."
#endif
