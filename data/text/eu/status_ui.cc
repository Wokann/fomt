#include "status_ui_text.hh"

#if defined(FOMT_TEXT_STATUS_UI_SHOP_COMMON)

char const gText_ShopCommon_GoldUnit[] =
    "G ";

char const gText_ShopCommon_QuantitySuffix[] =
    "  ";

char const * const gShopCommonQuantitySuffixTextRef =
    gText_ShopCommon_QuantitySuffix;

char const gText_ShopCommon_OwnedQuantityLabel[] =
    "You have    ";

char const * const gShopCommonOwnedQuantityLabelTextRef =
    gText_ShopCommon_OwnedQuantityLabel;

#else

char const gText_ToolStatus_GemOfTruth[] =
    "Gem of Truth\r\n";

char const gText_ToolStatus_EnergyLabel[] =
    "Energy ";

char const gText_ToolStatus_ValueSeparator[] =
    "/";

char const gText_ToolStatus_EnergyFatigueLineBreak[] =
    "\r\n";

char const gText_ToolStatus_FatigueLabel[] =
    "Fatigue ";

char const gText_ToolStatus_FatigueMaximum[] =
    "/100";

char const gText_ToolStatus_PedometerLabel[] =
    "Pedometer\r\n\n";

char const gText_ToolStatus_PedometerStepsSuffix[] =
    " steps";

char const gText_ToolStatus_DescriptionQuotePrefix[] =
    " \"";

char const gText_ToolStatus_RemainingSquaresSuffix[] =
    " squares left";

char const gText_AnimalStatus_Dog[] =
    "Dog\r\n";

char const gText_AnimalStatus_Puppy[] =
    "Puppy\r\n";

char const gText_AnimalStatus_Chicken[] =
    "Chicken\r\n";

char const gText_AnimalStatus_Chick[] =
    "Chick\r\n";

char const gText_AnimalStatus_Sick[] =
    "\r\n"
    "Sick";

char const gText_AnimalStatus_Unhappy[] =
    "\r\n"
    "Unhappy";

char const gText_AnimalStatus_Healthy[] =
    "\r\n"
    "Healthy";

char const gText_ItemStatus_BasketName[] =
    "Basket\r\n";

char const gText_ItemStatus_BasketDescription[] =
    "Can store goods to ship.\r\n";

char const gText_ItemStatus_BasketHoldingPrefix[] =
    "Holding ";

char const gText_ItemStatus_BasketHoldingSuffix[] =
    " items.";

char const gText_ItemStatus_WrappedAsPresent[] =
    "\r\nwrapped as a present.";

char const * const gItemStatusWrappedAsPresentTextRef =
    gText_ItemStatus_WrappedAsPresent;

char const gText_ItemDiscard_Confirm[] =
    "Throw this away?";

char const * const gItemDiscardConfirmTextRef =
    gText_ItemDiscard_Confirm;

char const gText_ItemDiscard_CannotDiscard[] =
    "You can't throw this away.{Press}";

char const * const gItemDiscardCannotDiscardTextRef =
    gText_ItemDiscard_CannotDiscard;

char const gText_ItemDiscard_Cursed[] =
    "You can't let go of it\r\n"
    "because it's cursed!{Press}";

char const * const gItemDiscardCursedTextRef =
    gText_ItemDiscard_Cursed;

#endif // FOMT_TEXT_STATUS_UI_SHOP_COMMON
