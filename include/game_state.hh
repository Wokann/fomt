#ifndef GAME_STATE_HH
#define GAME_STATE_HH

#include "prelude.h"

struct SramAccess;

EXTERN_C

// Writes the original save image and its checksum at the selected SRAM
// offset. Zero denotes success; nonzero values carry the SRAM error flags.
u32 func_080115B0(void const * snapshot, struct SramAccess * access, u32 offset);

EXTERN_C_END

#if defined(REGION_JP)
extern char const gText_Calendar_SeasonNames[4][3];
extern char const gText_Calendar_WeekdayNames[7][3];
#else
extern char const gText_Calendar_SeasonNames[4][7];
extern char const gText_Calendar_WeekdayNames[7][5];
#endif

extern char const gText_Calendar_None[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer00[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer01[];
extern char const gCppRuntimeError_CalendarTrailer[];
extern char const gText_CalendarTrailerFallbackNone[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer02[];

// func_08010F54 scans the first 25 entries as packed season/day values.
extern u8 const gUnk_080F0566[];
extern char const gCppRuntimeBadAlloc_GameState[];

#endif // GAME_STATE_HH
