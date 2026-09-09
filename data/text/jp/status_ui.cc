#include "status_ui_text.hh"

#if defined(FOMT_TEXT_STATUS_UI_SHOP_COMMON)

char const gText_ShopCommon_GoldUnit[] =
    "Ｇ";

char const gText_ShopCommon_QuantitySuffix[] =
    "コ";

char const * const gShopCommonQuantitySuffixTextRef =
    gText_ShopCommon_QuantitySuffix;

char const gText_ShopCommon_OwnedQuantityLabel[] =
    "持っている数";

char const * const gShopCommonOwnedQuantityLabelTextRef =
    gText_ShopCommon_OwnedQuantityLabel;

#else

char const gText_ToolStatus_GemOfTruth[] =
    "真実の秘宝\r\n";

char const gText_ToolStatus_EnergyLabel[] =
    "体力　";

char const gText_ToolStatus_ValueSeparator[] =
    "／";

char const gText_ToolStatus_EnergyFatigueLineBreak[] =
    "\r\n";

char const gText_ToolStatus_FatigueLabel[] =
    "疲労　";

char const gText_ToolStatus_FatigueMaximum[] =
    "／１００";

char const gText_ToolStatus_PedometerLabel[] =
    "万歩計\r\n\n";

char const gText_ToolStatus_PedometerStepsSuffix[] =
    "歩";

char const gText_ToolStatus_DescriptionQuoteOpen[] =
    "『";

char const gText_ToolStatus_DescriptionQuoteClose[] =
    "』";

char const gText_ToolStatus_RemainingSquaresPrefix[] =
    "のこり";

char const gText_ToolStatus_RemainingSquaresSuffix[] =
    "マス分。";

char const gText_AnimalStatus_Dog[] =
    "犬\r\n";

char const gText_AnimalStatus_Puppy[] =
    "子犬\r\n";

char const gText_AnimalStatus_Chicken[] =
    "鶏\r\n";

char const gText_AnimalStatus_Chick[] =
    "ひよこ\r\n";

char const gText_AnimalStatus_Sick[] =
    "\r\n"
    "病気";

char const gText_AnimalStatus_Unhappy[] =
    "\r\n"
    "不機嫌";

char const gText_AnimalStatus_Healthy[] =
    "\r\n"
    "健康";

char const gText_ItemStatus_BasketName[] =
    "かご\r\n";

char const gText_ItemStatus_BasketDescription[] =
    "出荷物をためておける。\r\n";

char const gText_ItemStatus_BasketHoldingSuffix[] =
    "個入ってる。";

char const gText_ItemStatus_WrappedAsPresent[] =
    "を\r\n"
    "プレゼント用に包んでもらった\r\n"
    "もの。";

char const * const gItemStatusWrappedAsPresentTextRef =
    gText_ItemStatus_WrappedAsPresent;

char const gText_ItemDiscard_Confirm[] =
    "これを捨ててもいい？";

char const * const gItemDiscardConfirmTextRef =
    gText_ItemDiscard_Confirm;

char const gText_ItemDiscard_CannotDiscard[] =
    "これは捨てられない。{Press}";

char const * const gItemDiscardCannotDiscardTextRef =
    gText_ItemDiscard_CannotDiscard;

char const gText_ItemDiscard_Cursed[] =
    "呪われているのではずせない！{Press}";

char const * const gItemDiscardCursedTextRef =
    gText_ItemDiscard_Cursed;

#endif // FOMT_TEXT_STATUS_UI_SHOP_COMMON
