#ifndef ITEM_DISCARD_TEXT_HH
#define ITEM_DISCARD_TEXT_HH

#include "prelude.h"

#define ITEM_DISCARD_CONFIRM_TEXT SECTION(".rodata.item_discard_confirm")
#define ITEM_DISCARD_CONFIRM_TEXT_REF SECTION(".rodata.item_discard_confirm_text_ref")
#define ITEM_DISCARD_CANNOT_DISCARD_TEXT SECTION(".rodata.item_discard_cannot_discard")
#define ITEM_DISCARD_CANNOT_DISCARD_TEXT_REF SECTION(".rodata.item_discard_cannot_discard_text_ref")
#define ITEM_DISCARD_CURSED_TEXT SECTION(".rodata.item_discard_cursed")
#define ITEM_DISCARD_CURSED_TEXT_REF SECTION(".rodata.item_discard_cursed_text_ref")

extern char const gText_ItemDiscard_Confirm[];
extern char const * const gItemDiscardConfirmTextRef;
extern char const gText_ItemDiscard_CannotDiscard[];
extern char const * const gItemDiscardCannotDiscardTextRef;
extern char const gText_ItemDiscard_Cursed[];
extern char const * const gItemDiscardCursedTextRef;

#endif // ITEM_DISCARD_TEXT_HH
