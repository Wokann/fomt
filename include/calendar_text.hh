#ifndef CALENDAR_TEXT_HH
#define CALENDAR_TEXT_HH

#include "prelude.h"

#define CALENDAR_FESTIVAL_TEXT SECTION(".rodata.calendar.festival_text")
#define CALENDAR_NO_PLANS_TEXT SECTION(".rodata.calendar.no_plans_text")

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

extern char const gText_Calendar_Festival_NewYearFestival[];
extern char const gText_Calendar_Festival_SpringThanksgiving[];
extern char const gText_Calendar_Festival_SpringHorseRace[];
extern char const gText_Calendar_Festival_CookingFestival[];
extern char const gText_Calendar_Festival_BeachDay[];
extern char const gText_Calendar_Festival_ChickenFestival[];
extern char const gText_Calendar_Festival_CowFestival[];
extern char const gText_Calendar_Festival_FireworksFestival[];
extern char const gText_Calendar_Festival_MusicFestival[];
extern char const gText_Calendar_Festival_HarvestFestival[];
extern char const gText_Calendar_Festival_FullMoonFestival[];
extern char const gText_Calendar_Festival_FallHorseRace[];
extern char const gText_Calendar_Festival_SheepFestival[];
extern char const gText_Calendar_Festival_PumpkinFestival[];
extern char const gText_Calendar_Festival_WinterThanksgiving[];
extern char const gText_Calendar_Festival_StarryNightFestival[];
extern char const gText_Calendar_Festival_YearEndGathering[];
extern char const gText_Calendar_Festival_NoPlans[];

#endif // CALENDAR_TEXT_HH
