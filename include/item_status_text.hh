#ifndef ITEM_STATUS_TEXT_HH
#define ITEM_STATUS_TEXT_HH

#include "prelude.h"

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

#endif // ITEM_STATUS_TEXT_HH
