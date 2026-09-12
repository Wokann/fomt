#include "status_ui_text.hh"

#if defined(FOMT_TEXT_STATUS_UI_SHOP_COMMON)

char const gText_ShopCommon_GoldUnit[] =
    "G ";

char const gText_ShopCommon_QuantitySuffix[] =
    "  ";

char const * const gShopCommonQuantitySuffixTextRef =
    gText_ShopCommon_QuantitySuffix;

char const gText_ShopCommon_OwnedQuantityLabel[] =
    "Du hast     ";

char const * const gShopCommonOwnedQuantityLabelTextRef =
    gText_ShopCommon_OwnedQuantityLabel;

#else

char const gText_ToolStatus_GemOfTruth[] =
    "Juwel der Wahrheit\r\n";

char const gText_ToolStatus_EnergyLabel[] =
    "Energie ";

char const gText_ToolStatus_ValueSeparator[] =
    "/";

char const gText_ToolStatus_EnergyFatigueLineBreak[] =
    "\r\n";

char const gText_ToolStatus_FatigueLabel[] =
    "Energieverlust ";

char const gText_ToolStatus_FatigueMaximum[] =
    "/100";

char const gText_ToolStatus_PedometerLabel[] =
    "Schrittmesser\r\n\n";

char const gText_ToolStatus_PedometerStepsSuffix[] =
    " Schritte";

char const gText_ToolStatus_DescriptionQuotePrefix[] =
    " \"";

char const gText_ToolStatus_RemainingSquaresSuffix[] =
    " übrige Quadrate";

char const gText_AnimalStatus_Dog[] =
    "Hund\r\n";

char const gText_AnimalStatus_Puppy[] =
    "Welpe\r\n";

char const gText_AnimalStatus_Chicken[] =
    "Huhn\r\n";

char const gText_AnimalStatus_Chick[] =
    "Küken\r\n";

char const gText_AnimalStatus_Sick[] =
    "\r\n"
    "Krank";

char const gText_AnimalStatus_Unhappy[] =
    "\r\n"
    "Unglücklich";

char const gText_AnimalStatus_Healthy[] =
    "\r\n"
    "Gesund";

char const gText_ItemStatus_BasketName[] =
    "Korb\r\n";

char const gText_ItemStatus_BasketDescription[] =
    "Dinge zum Versand lagern.\r\n";

char const gText_ItemStatus_BasketHoldingPrefix[] =
    "Hält ";

char const gText_ItemStatus_BasketHoldingSuffix[] =
    " Dinge.";

char const gText_ItemStatus_WrappedAsPresent[] =
    "\r\nals Geschenk verpackt.";

char const * const gItemStatusWrappedAsPresentTextRef =
    gText_ItemStatus_WrappedAsPresent;

char const gText_ItemDiscard_Confirm[] =
    "Wegwerfen?";

char const * const gItemDiscardConfirmTextRef =
    gText_ItemDiscard_Confirm;

char const gText_ItemDiscard_CannotDiscard[] =
    "Du kannst das nicht\r\n"
    "wegwerfen.{Press}";

char const * const gItemDiscardCannotDiscardTextRef =
    gText_ItemDiscard_CannotDiscard;

char const gText_ItemDiscard_Cursed[] =
    "Du kannst nicht loslassen,\r\n"
    "weil es verwünscht ist!{Press}";

char const * const gItemDiscardCursedTextRef =
    gText_ItemDiscard_Cursed;

#endif // FOMT_TEXT_STATUS_UI_SHOP_COMMON
