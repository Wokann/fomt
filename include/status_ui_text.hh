#ifndef STATUS_UI_TEXT_HH
#define STATUS_UI_TEXT_HH

#include "prelude.h"

struct AnimalStatusScreenPrefixText
{
    char unavailable[6];
#if defined(REGION_JP)
    char digits[21];
    char digit_trailer[1];
#else
    char digits[10][2];
    char padding[2];
#endif
};

#if defined(REGION_JP)
struct AnimalStatusScreenText
{
    char healthy[8];
    char unhappy[8];
    char sick[8];
    char spring[4];
    char summer[4];
    char autumn[4];
    char winter[4];
    char age[4];
    char day[4];
};
#else
struct AnimalStatusScreenText
{
    char healthy[12];
    char unhappy[12];
    char sick[12];
    char spring[8];
    char summer[8];
    char autumn[8];
    char winter[8];
    char age[4];
    char day[4];
};
#endif

extern AnimalStatusScreenPrefixText const gAnimalStatusScreenPrefixText;
extern AnimalStatusScreenText const gAnimalStatusScreenText;

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
