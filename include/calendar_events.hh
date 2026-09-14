#ifndef CALENDAR_EVENTS_HH
#define CALENDAR_EVENTS_HH

#include "prelude.h"
#include "game_state.hh"

// The native calendar scan begins with the last NUL in season_names, then
// reads a day and the following entry's season byte.  Keep this physical
// storage adjacent to the names rather than inventing an overlapping object.
struct __attribute__((packed)) CalendarFestivalDateStorage
{
    u8 day;
    u8 following_season;
};

#if defined(REGION_JP)
struct __attribute__((packed)) CalendarDynamicSeasonData
{
    char season_names[4][4];
    CalendarFestivalDateStorage festival_dates[17];
};

extern CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames;
#elif defined(REGION_DE)
// The German executable indexes these four native fields at 0x00, 0x0C,
// 0x14, and 0x1C.  German "Frühling" needs the larger first storage field.
struct __attribute__((packed)) CalendarDynamicSeasonData
{
    struct __attribute__((packed))
    {
        char spring[12];
        char summer[8];
        char autumn[8];
        char winter[8];
    } season_names;
    CalendarFestivalDateStorage festival_dates[17];
};

extern CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames;
#else
struct __attribute__((packed)) CalendarDynamicSeasonData
{
    char season_names[4][8];
    CalendarFestivalDateStorage festival_dates[17];
};

extern CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames;
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
extern char const gText_Calendar_Festival_Marriage[];
extern char const gText_Calendar_Festival_WeddingAnniversary[];
extern char const gText_Calendar_Festival_NoPlans[];
extern char const gCppRuntimeBadAlloc_CalendarNoPlansFirst[];
extern char const gText_Calendar_FallbackNone[];
extern char const gCppRuntimeBadAlloc_CalendarNoPlansSecond[];

#endif // CALENDAR_EVENTS_HH
