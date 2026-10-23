#ifndef MAP_CLOCK_STATUS_HH
#define MAP_CLOCK_STATUS_HH

#include "prelude.h"

// Only the prefix consumed by the recovered setters is modeled. This is not
// the size or construction contract of the complete native HUD allocation.
struct MapClockStatusHudDataPrefix {
    u8 unk_000[0x2CC];
    u8 unk_selector;
    u8 unk_2CD[0x23];
    u8 unk_selector_dirty;
    u8 unk_value_active;
    u16 unk_value;
    u8 unk_2F4[0x40];
    u8 unk_value_dirty;
};

struct MapClockStatusHudContent {
    MapClockStatusHudDataPrefix * state;
};

typedef char MapClockStatusSelectorOffset[offsetof(MapClockStatusHudDataPrefix, unk_selector) == 0x2CC ? 1 : -1];
typedef char MapClockStatusSelectorDirtyOffset[offsetof(MapClockStatusHudDataPrefix, unk_selector_dirty) == 0x2F0 ? 1 : -1];
typedef char MapClockStatusValueActiveOffset[offsetof(MapClockStatusHudDataPrefix, unk_value_active) == 0x2F1 ? 1 : -1];
typedef char MapClockStatusValueOffset[offsetof(MapClockStatusHudDataPrefix, unk_value) == 0x2F2 ? 1 : -1];
typedef char MapClockStatusValueDirtyOffset[offsetof(MapClockStatusHudDataPrefix, unk_value_dirty) == 0x334 ? 1 : -1];
typedef char MapClockStatusContentSize[sizeof(MapClockStatusHudContent) == 4 ? 1 : -1];

// Values above 4 leave the selector unchanged. The visual meaning of
// these five native states is not established; do not infer weather.
EXTERN_C
void SetMapClockStatusHudUnkSelector(MapClockStatusHudContent const * hud, u32 value);
// Compare the full input word before storing its low 16 bits.
void SetMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud, u32 value);
void ClearMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud);
EXTERN_C_END

#endif // MAP_CLOCK_STATUS_HH
