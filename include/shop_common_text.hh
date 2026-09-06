#ifndef SHOP_COMMON_TEXT_HH
#define SHOP_COMMON_TEXT_HH

#include "prelude.h"

#define SHOP_COMMON_PREFIX_TEXT SECTION(".rodata.shop_common_prefix")
#define SHOP_COMMON_OWNED_QUANTITY_LABEL_TEXT SECTION(".rodata.shop_common_owned_quantity_label")
#define SHOP_COMMON_QUANTITY_SUFFIX_TEXT_REF SECTION(".rodata.shop_common_quantity_suffix_text_ref")
#define SHOP_COMMON_OWNED_QUANTITY_LABEL_TEXT_REF SECTION(".rodata.shop_common_owned_quantity_label_text_ref")

extern char const gText_ShopCommon_GoldUnit[];
extern char const gText_ShopCommon_QuantitySuffix[];
extern char const gText_ShopCommon_OwnedQuantityLabel[];

extern char const * const gShopCommonQuantitySuffixTextRef;
extern char const * const gShopCommonOwnedQuantityLabelTextRef;

#endif // SHOP_COMMON_TEXT_HH
