#ifndef ITEM_STATUS_TEXT_HH
#define ITEM_STATUS_TEXT_HH

#include "prelude.h"

#define ITEM_STATUS_WRAPPED_AS_PRESENT_TEXT SECTION(".rodata.item_status_wrapped_as_present")
#define ITEM_STATUS_WRAPPED_AS_PRESENT_TEXT_REF SECTION(".rodata.item_status_wrapped_as_present_text_ref")

extern char const gText_ItemStatus_WrappedAsPresent[];
extern char const * const gItemStatusWrappedAsPresentTextRef;

#endif // ITEM_STATUS_TEXT_HH
