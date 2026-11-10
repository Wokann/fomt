#ifndef SHOP_UI_HH
#define SHOP_UI_HH

#include "shop_common.hh"

EXTERN_C
// These two paths set/clear all six low UI flags and select text speed 0x100/0.
void SetShopMessageText(ShopScreenCore * core, char const * text);
void SetShopDescriptionText(ShopScreenCore * core, char const * text);
// Native byte-state accessors; the meanings of the two flags remain unknown.
u8 func_080CAC3C(ShopScreenCore const * core);
u8 func_080CAC48(ShopScreenCore const * core);
// The native receiver is unused; the comparison line is passed in r1.
void SetVCountCompareRegister(void * receiver, u16 line);
EXTERN_C_END

#endif // SHOP_UI_HH
