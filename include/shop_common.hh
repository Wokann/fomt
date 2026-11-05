#ifndef SHOP_COMMON_HH
#define SHOP_COMMON_HH

#include "prelude.h"

extern char const gCppRuntimeBadAlloc_ShopCommonDigitGlyphs[];
extern u16 const gShopDigitGlyphs[10];
extern char const gCppRuntimeBadAlloc_ShopCommonPostText[];
// Pixel-byte pairs retain the native four-byte record alignment.
struct ALIGN(4) MenuGridPosition {
    u8 x;
    u8 y;
};
typedef char MenuGridPositionSizeCheck[sizeof(MenuGridPosition) == 4 ? 1 : -1];
typedef char MenuGridPositionYCheck[offsetof(MenuGridPosition, y) == 1 ? 1 : -1];
extern MenuGridPosition const gMenuGridHeaderPosition;
extern MenuGridPosition const gMenuGridCellPositions[8];
extern u32 const gUnk_0811785C;
extern u32 const gUnk_08117860[8];
extern char const gCppRuntimeBadAlloc_ShopCommonTable[];
// Target selection indices: left header 0, left cells 1..8,
// right header 9 and right cells 10..17.
struct MenuGridNavigation {
    i32 up;
    i32 down;
    i32 left;
    i32 right;
};
typedef char MenuGridNavigationSizeCheck[sizeof(MenuGridNavigation) == 16 ? 1 : -1];
typedef char MenuGridNavigationDownCheck[offsetof(MenuGridNavigation, down) == 4 ? 1 : -1];
typedef char MenuGridNavigationLeftCheck[offsetof(MenuGridNavigation, left) == 8 ? 1 : -1];
typedef char MenuGridNavigationRightCheck[offsetof(MenuGridNavigation, right) == 12 ? 1 : -1];
extern MenuGridNavigation const gMenuGridNavigation[18];

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

#endif // SHOP_COMMON_HH
