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

u32 const gUnk_08117838 = 0x00001010;

u32 const gUnk_0811783C[8] = {
    0x00003010, 0x00003028, 0x00003040, 0x00003058,
    0x00005010, 0x00005028, 0x00005040, 0x00005058,
};

u32 const gUnk_0811785C = 0x00000102;

u32 const gUnk_08117860[8] = {
    0x00000502, 0x00000505, 0x00000508, 0x0000050B,
    0x00000902, 0x00000905, 0x00000908, 0x0000090B,
};

#include FOMT_TEXT_INCLUDE(shop_common_5.cc)

u32 const gUnk_0811788C[18][4] = {
    { 0x00000005, 0x00000001, 0x00000009, 0x00000009 },
    { 0x00000000, 0x00000005, 0x0000000D, 0x00000002 },
    { 0x00000000, 0x00000006, 0x00000001, 0x00000003 },
    { 0x00000000, 0x00000007, 0x00000002, 0x00000004 },
    { 0x00000000, 0x00000008, 0x00000003, 0x0000000A },
    { 0x00000001, 0x00000000, 0x00000011, 0x00000006 },
    { 0x00000002, 0x00000000, 0x00000005, 0x00000007 },
    { 0x00000003, 0x00000000, 0x00000006, 0x00000008 },
    { 0x00000004, 0x00000000, 0x00000007, 0x0000000E },
    { 0x0000000E, 0x0000000A, 0x00000000, 0x00000000 },
    { 0x00000009, 0x0000000E, 0x00000004, 0x0000000B },
    { 0x00000009, 0x0000000F, 0x0000000A, 0x0000000C },
    { 0x00000009, 0x00000010, 0x0000000B, 0x0000000D },
    { 0x00000009, 0x00000011, 0x0000000C, 0x00000001 },
    { 0x0000000A, 0x00000009, 0x00000008, 0x0000000F },
    { 0x0000000B, 0x00000009, 0x0000000E, 0x00000010 },
    { 0x0000000C, 0x00000009, 0x0000000F, 0x00000011 },
    { 0x0000000D, 0x00000009, 0x00000010, 0x00000005 },
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
