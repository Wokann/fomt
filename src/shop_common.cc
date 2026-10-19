#include "shop_common.hh"

#include FOMT_TEXT_INCLUDE(shop_common_1.cc)

#if defined(REGION_JP)
u16 const gUnk_080C85A0DigitGlyphs[10] = {
        0x824F, 0x8250, 0x8251, 0x8252, 0x8253,
        0x8254, 0x8255, 0x8256, 0x8257, 0x8258,
    };
#else
u16 const gUnk_080C85A0DigitGlyphs[10] = {
        0x0030, 0x0031, 0x0032, 0x0033, 0x0034,
        0x0035, 0x0036, 0x0037, 0x0038, 0x0039,
    };
#endif

#include FOMT_TEXT_INCLUDE(shop_common_2.cc)

char const * const gShopCommonQuantitySuffixTextRef =
    gText_ShopCommon_QuantitySuffix;

#include FOMT_TEXT_INCLUDE(shop_common_3.cc)

char const * const gShopCommonOwnedQuantityLabelTextRef =
    gText_ShopCommon_OwnedQuantityLabel;

#include FOMT_TEXT_INCLUDE(shop_common_4.cc)

MenuGridPosition const gMenuGridHeaderPosition = { 16, 16 };

MenuGridPosition const gMenuGridCellPositions[8] = {
    { 16, 48 }, { 40, 48 }, { 64, 48 }, { 88, 48 },
    { 16, 80 }, { 40, 80 }, { 64, 80 }, { 88, 80 },
};

u32 const gUnk_0811785C = 0x00000102;

u32 const gUnk_08117860[8] = {
    0x00000502, 0x00000505, 0x00000508, 0x0000050B,
    0x00000902, 0x00000905, 0x00000908, 0x0000090B,
};

#include FOMT_TEXT_INCLUDE(shop_common_5.cc)

// Selection targets in up, down, left, right order.
MenuGridNavigation const gMenuGridNavigation[18] = {
    { 5, 1, 9, 9 },
    { 0, 5, 13, 2 },
    { 0, 6, 1, 3 },
    { 0, 7, 2, 4 },
    { 0, 8, 3, 10 },
    { 1, 0, 17, 6 },
    { 2, 0, 5, 7 },
    { 3, 0, 6, 8 },
    { 4, 0, 7, 14 },
    { 14, 10, 0, 0 },
    { 9, 14, 4, 11 },
    { 9, 15, 10, 12 },
    { 9, 16, 11, 13 },
    { 9, 17, 12, 1 },
    { 10, 9, 8, 15 },
    { 11, 9, 14, 16 },
    { 12, 9, 15, 17 },
    { 13, 9, 16, 5 },
};

#include FOMT_TEXT_INCLUDE(shop_common_6.cc)

char const * const gItemStatusWrappedAsPresentTextRef =
    gText_ItemStatus_WrappedAsPresent;

#include FOMT_TEXT_INCLUDE(shop_common_7.cc)

char const * const gItemDiscardConfirmTextRef =
    gText_ItemDiscard_Confirm;

#include FOMT_TEXT_INCLUDE(shop_common_8.cc)

char const * const gItemDiscardCannotDiscardTextRef =
    gText_ItemDiscard_CannotDiscard;

#include FOMT_TEXT_INCLUDE(shop_common_9.cc)

char const * const gItemDiscardCursedTextRef =
    gText_ItemDiscard_Cursed;
