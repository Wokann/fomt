#include "shop_common.hh"

char const gCppRuntimeBadAlloc_ShopCommonDigitGlyphs[]
    SECTION(".rodata.shop_common_digit_glyphs") =
        "bad_alloc";

#if defined(REGION_JP)
u16 const gUnk_080C85A0DigitGlyphs[10]
    SECTION(".rodata.shop_common_digit_glyphs") = {
        0x824F, 0x8250, 0x8251, 0x8252, 0x8253,
        0x8254, 0x8255, 0x8256, 0x8257, 0x8258,
    };
#else
u16 const gUnk_080C85A0DigitGlyphs[10]
    SECTION(".rodata.shop_common_digit_glyphs") = {
        0x0030, 0x0031, 0x0032, 0x0033, 0x0034,
        0x0035, 0x0036, 0x0037, 0x0038, 0x0039,
    };
#endif
