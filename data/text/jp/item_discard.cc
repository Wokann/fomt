#include "item_discard_text.hh"

char const gText_ItemDiscard_Confirm[] =
    "これを捨ててもいい？\x00\x00\x00";

char const * const gItemDiscardConfirmTextRef =
    gText_ItemDiscard_Confirm;

char const gText_ItemDiscard_CannotDiscard[] =
    "これは捨てられない。{Press}\x00\x00";

char const * const gItemDiscardCannotDiscardTextRef =
    gText_ItemDiscard_CannotDiscard;

char const gText_ItemDiscard_Cursed[] =
    "呪われているのではずせない！{Press}\x00\x00";

char const * const gItemDiscardCursedTextRef =
    gText_ItemDiscard_Cursed;
