#ifndef CALENDAR_TEXT_HH
#define CALENDAR_TEXT_HH

#include "prelude.h"

// The fixed row widths are part of the original menu ABI: callers index these
// arrays directly rather than through a pointer table.
#if defined(REGION_JP)
extern char const gText_Calendar_SeasonNames[4][3];
extern char const gText_Calendar_None[];
extern char const gText_Calendar_WeekdayNames[7][3];
#else
extern char const gText_Calendar_SeasonNames[4][7];
extern char const gText_Calendar_None[];
extern char const gText_Calendar_WeekdayNames[7][5];
#endif

#endif // CALENDAR_TEXT_HH
