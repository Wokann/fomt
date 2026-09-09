#include "beach_cafe_shop_text.hh"

#if defined(REGION_JP)
#include "data/text/jp/beach_cafe_shop_descriptions.cc"
#else
#include "data/text/us/beach_cafe_shop_descriptions.cc"
#endif

BeachCafeShopMenuEntry const gBeachCafeShopMenu[] = {
    { 0x1CD, 0, gText_BeachCafeShop_WaterDescription, 1, 1, 0, 1 },
    { 0x63, 250, gText_BeachCafeShop_EmptyDescription, 0, 20, -3, 0 },
    { 0x1A6, 300, gText_BeachCafeShop_SpaghettiDescription, 1, 40, -5, 0 },
    { 0x82, 200, gText_BeachCafeShop_EmptyDescription, 0, 30, -3, 0 },
    { 0xF7, 300, gText_BeachCafeShop_SnowConeDescription, 1, 1, -20, 0 },
};

#if defined(REGION_JP)
#include "data/text/jp/beach_cafe_shop_dialogue.cc"
#else
#include "data/text/us/beach_cafe_shop_dialogue.cc"
#endif
