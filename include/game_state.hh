#ifndef GAME_STATE_HH
#define GAME_STATE_HH

#include "prelude.h"

struct SramAccess;

EXTERN_C

// Writes the original save image and its checksum at the selected SRAM
// offset. Zero denotes success; nonzero values carry the SRAM error flags.
u32 func_080115B0(void const * snapshot, struct SramAccess * access, u32 offset);

// Initializes and reads a save image into the supplied allocation. The
// status output is zero on success; the complete image layout is unresolved.
void * func_08011650(void * object, struct SramAccess * access, u32 offset,
    u32 * status);
// Copy-construction into existing storage and the original destructor ABI.
// Destructor flag bit zero requests deallocation after member cleanup.
void * func_080D4178(void * object, void const * source);
void func_080D4480(void * object, u32 flags);

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
