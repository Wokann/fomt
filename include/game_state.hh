#ifndef GAME_STATE_HH
#define GAME_STATE_HH

#include "prelude.h"

// func_08010F54 scans the first 25 bytes, decoding the low two bits as a
// season value and bits 2-6 as a day value. The final zero remains part of
// the original table layout but is not scanned by that loop. The following
// runtime string is physically contiguous in the original ROM, so one packed
// C++ object preserves the native layout without explicit zero padding.
struct PACKED Unk_080F0566Data
{
    u8 values[26];
    char cpp_runtime_bad_alloc[sizeof("bad_alloc")];
};

extern Unk_080F0566Data const gUnk_080F0566;

#endif // GAME_STATE_HH
