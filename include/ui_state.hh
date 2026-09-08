#ifndef UI_STATE_HH
#define UI_STATE_HH

#include "prelude.h"

// Multiple UI constructors copy unk_00 for unk_04 bytes into VRAM and copy
// unk_08 into palette RAM.  The encoded resource payload formats remain raw.
struct UiSharedResourceData
{
    u8 const * unk_00;
    u32 unk_04;
    u8 const * unk_08;
};

extern u8 const gUnk_UiSharedResourceData_000[];
extern u8 const gUnk_UiSharedResourceData_001[];
extern UiSharedResourceData const gUiSharedResourceData;

#endif // UI_STATE_HH
