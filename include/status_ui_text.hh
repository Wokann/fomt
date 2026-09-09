#ifndef STATUS_UI_TEXT_HH
#define STATUS_UI_TEXT_HH

#include "prelude.h"

extern char const gText_ShopCommon_GoldUnit[];
extern char const gText_ShopCommon_QuantitySuffix[];
extern char const gText_ShopCommon_OwnedQuantityLabel[];
extern char const * const gShopCommonQuantitySuffixTextRef;
extern char const * const gShopCommonOwnedQuantityLabelTextRef;

extern char const gText_ToolStatus_GemOfTruth[];
extern char const gText_ToolStatus_EnergyLabel[];
extern char const gText_ToolStatus_ValueSeparator[];
extern char const gText_ToolStatus_EnergyFatigueLineBreak[];
extern char const gText_ToolStatus_FatigueLabel[];
extern char const gText_ToolStatus_FatigueMaximum[];
extern char const gText_ToolStatus_PedometerLabel[];
extern char const gText_ToolStatus_PedometerStepsSuffix[];

#if defined(REGION_JP)
extern char const gText_ToolStatus_DescriptionQuoteOpen[];
extern char const gText_ToolStatus_DescriptionQuoteClose[];
extern char const gText_ToolStatus_RemainingSquaresPrefix[];
extern char const gText_ToolStatus_RemainingSquaresSuffix[];
#else
extern char const gText_ToolStatus_DescriptionQuotePrefix[];
extern char const gText_ToolStatus_RemainingSquaresSuffix[];
#endif

extern char const gText_AnimalStatus_Dog[];
extern char const gText_AnimalStatus_Puppy[];
extern char const gText_AnimalStatus_Chicken[];
extern char const gText_AnimalStatus_Chick[];
extern char const gText_AnimalStatus_Sick[];
extern char const gText_AnimalStatus_Unhappy[];
extern char const gText_AnimalStatus_Healthy[];

extern char const gText_ItemStatus_BasketName[];
extern char const gText_ItemStatus_BasketDescription[];
#if defined(REGION_JP)
extern char const gText_ItemStatus_BasketHoldingSuffix[];
#else
extern char const gText_ItemStatus_BasketHoldingPrefix[];
extern char const gText_ItemStatus_BasketHoldingSuffix[];
#endif
extern char const gText_ItemStatus_WrappedAsPresent[];
extern char const * const gItemStatusWrappedAsPresentTextRef;

extern char const gText_ItemDiscard_Confirm[];
extern char const * const gItemDiscardConfirmTextRef;
extern char const gText_ItemDiscard_CannotDiscard[];
extern char const * const gItemDiscardCannotDiscardTextRef;
extern char const gText_ItemDiscard_Cursed[];
extern char const * const gItemDiscardCursedTextRef;

#endif // STATUS_UI_TEXT_HH
