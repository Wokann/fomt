#ifndef UI_TEXT_LAYOUT_HH
#define UI_TEXT_LAYOUT_HH

#include "prelude.h"

enum
{
    UI_TEXT_LAYOUT_VARIANT_COUNT = 8,
    UI_TEXT_LAYOUT_SLOT_COUNT = 6,
};

// The native helper indexes this object as
// base + layout * UI_TEXT_LAYOUT_SLOT_COUNT + one_based_slot.  Byte zero is
// also deliberately used as an empty-string fallback by the same code.
// The 4-byte type alignment supplies the three trailing ROM padding bytes.
struct UiTextLayoutPositionTable
{
    u8 empty_string;
    u8 position_codes[UI_TEXT_LAYOUT_VARIANT_COUNT][UI_TEXT_LAYOUT_SLOT_COUNT];
} ALIGN(4);

extern UiTextLayoutPositionTable const gUiTextLayoutPositionTable;

#endif // UI_TEXT_LAYOUT_HH
