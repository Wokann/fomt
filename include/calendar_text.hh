#ifndef CALENDAR_TEXT_HH
#define CALENDAR_TEXT_HH

#include "prelude.h"


// The native calendar scan begins with the last NUL in season_names, then
// reads a day and the following entry's season byte.  Keep this physical
// storage adjacent to the names rather than inventing an overlapping object.
struct PACKED CalendarFestivalDateStorage
{
    u8 day;
    u8 following_season;
};

#if defined(REGION_JP)
struct PACKED CalendarDynamicSeasonData
{
    char season_names[4][4];
    CalendarFestivalDateStorage festival_dates[17];
};

extern CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames;

// The fixed row widths are part of the original menu ABI: callers index these
// arrays directly rather than through a pointer table.
extern char const gText_Calendar_SeasonNames[4][3];
extern char const gText_Calendar_None[];
extern char const gText_Calendar_WeekdayNames[7][3];
#else
struct PACKED CalendarDynamicSeasonData
{
    char season_names[4][8];
    CalendarFestivalDateStorage festival_dates[17];
};

extern CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames;

// The fixed row widths are part of the original menu ABI: callers index these
// arrays directly rather than through a pointer table.
extern char const gText_Calendar_SeasonNames[4][7];
extern char const gText_Calendar_None[];
extern char const gText_Calendar_WeekdayNames[7][5];
#endif

extern char const gCppRuntimeBadAlloc_CalendarTrailer00[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer01[];
extern char const gCppRuntimeError_CalendarTrailer[];
extern char const gText_CalendarTrailerFallbackNone[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer02[];

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
extern char const gText_Calendar_Festival_Marriage[];
extern char const gText_Calendar_Festival_WeddingAnniversary[];
extern char const gText_Calendar_Festival_NoPlans[];
extern char const gCppRuntimeBadAlloc_CalendarNoPlansFirst[];
extern char const gText_Calendar_FallbackNone[];
extern char const gCppRuntimeBadAlloc_CalendarNoPlansSecond[];

#endif // CALENDAR_TEXT_HH
