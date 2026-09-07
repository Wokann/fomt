#include "item_discard_text.hh"

char const gText_ItemDiscard_Confirm[] =
    "Throw this away?\x00\x00\x00";

char const * const gItemDiscardConfirmTextRef =
    gText_ItemDiscard_Confirm;

char const gText_ItemDiscard_CannotDiscard[] =
    "You can't throw this away.{Press}";

char const * const gItemDiscardCannotDiscardTextRef =
    gText_ItemDiscard_CannotDiscard;

char const gText_ItemDiscard_Cursed[] =
    "You can't let go of it\r\n"
    "because it's cursed!{Press}\x00\x00";

char const * const gItemDiscardCursedTextRef =
    gText_ItemDiscard_Cursed;
