#ifndef GAME_STATE_HH
#define GAME_STATE_HH

#include "prelude.h"

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
