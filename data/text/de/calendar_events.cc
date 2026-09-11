#include "calendar_events.hh"

#include "unknown_types.hh"

// This is the separate fixed-width season-name copy expanded by the calendar
// dynamic-field handler, followed by the native calendar date storage.  Its
// final NUL is the first logical season byte; every following pair stores a
// day and the next logical season byte.

CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames
    ALIGN(1) = {
    {
        "Spring",
        "Summer",
        "Fall",
        "Winter",
    },
    {
        {  1, SEASON_SPRING },
        { 14, SEASON_SPRING },
        { 18, SEASON_SPRING },
        { 22, SEASON_SUMMER },
        {  1, SEASON_SUMMER },
        {  7, SEASON_SUMMER },
        { 20, SEASON_SUMMER },
        { 24, SEASON_AUTUMN },
        {  3, SEASON_AUTUMN },
        {  9, SEASON_AUTUMN },
        { 13, SEASON_AUTUMN },
        { 18, SEASON_AUTUMN },
        { 21, SEASON_AUTUMN },
        { 30, SEASON_WINTER },
        { 14, SEASON_WINTER },
        { 24, SEASON_WINTER },
        { 30, SEASON_SPRING },
    },
};

char const gText_Calendar_Festival_NewYearFestival[] =
    "\p"
    "1st day of Spring\r\n"
    "New Year Festival in Rose\r\n"
    "Square. 6PM - Midnight{Press}";

char const gText_Calendar_Festival_SpringThanksgiving[] ALIGN(4) =
    "\p"
    "14th day of Spring\r\n"
    "Spring Thanksgiving Festival{Press}";

char const gText_Calendar_Festival_SpringHorseRace[] ALIGN(4) =
    "\p"
    "18th day of Spring\r\n"
    "Spring Horse Racing\r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_CookingFestival[] ALIGN(4) =
    "\p"
    "22nd day of Spring\r\n"
    "Cooking Festival\r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_BeachDay[] ALIGN(4) =
    "\p"
    "1st day of Summer\r\n"
    "Beach Day at Mineral Beach\r\n"
    "(10AM - 6PM) {Press}";

char const gText_Calendar_Festival_ChickenFestival[] ALIGN(4) =
    "\p"
    "7th day of Summer\r\n"
    "Chicken Festival in \r\n"
    "Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_CowFestival[] ALIGN(4) =
    "\p"
    "20th day of Summer\r\n"
    "Cow Festival \r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_FireworksFestival[] ALIGN(4) =
    "\p"
    "24th day of Summer\r\n"
    "Fireworks Festival \r\n"
    "at Mineral Beach (6-9PM) {Press}";

char const gText_Calendar_Festival_MusicFestival[] ALIGN(4) =
    "\p"
    "3rd day of Fall\r\n"
    "Music Festival in Church \r\n"
    "(6PM - Midnight) {Press}";

char const gText_Calendar_Festival_HarvestFestival[] ALIGN(4) =
    "\p"
    "9th day of Fall\r\n"
    "Harvest Festival \r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_FullMoonFestival[] ALIGN(4) =
    "\p"
    "13th day of Fall \r\n"
    "Full Moon Festival\r\n"
    "(6PM - Midnight) {Press}";

char const gText_Calendar_Festival_FallHorseRace[] ALIGN(4) =
    "\p"
    "18th day of Fall\r\n"
    "Fall Horse Racing in\r\n"
    "Rose Square (10AM - 6PM) {Press}";

char const gText_Calendar_Festival_SheepFestival[] ALIGN(4) =
    "\p"
    "21st day of Fall \r\n"
    "Sheep Festival \r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_PumpkinFestival[] ALIGN(4) =
    "\p"
    "30th day of Fall\r\n"
    "Pumpkin Festival {Press}";

char const gText_Calendar_Festival_WinterThanksgiving[] ALIGN(4) =
    "\p"
    "14th day of Winter\r\n"
    "Thanksgiving{Press}";

char const gText_Calendar_Festival_StarryNightFestival[] ALIGN(4) =
    "\p"
    "24th day of Winter\r\n"
    "Starry Night Festival {Press}";

char const gText_Calendar_Festival_YearEndGathering[] ALIGN(4) =
    "\p"
    "30th day of Winter\r\n"
    "Year End Gathering \r\n"
    "Year End Festival {Press}";

char const gText_Calendar_Festival_Marriage[] =
    "\p"
    "\xF1st day of \xF0\r\n"
    "Marriage to \xF2{Press}";

char const gText_Calendar_Festival_WeddingAnniversary[] ALIGN(4) =
    "\p"
    "\xF1st day of \xF0\r\n"
    "Wedding Anniversary{Press}";

char const gText_Calendar_Festival_NoPlans[] ALIGN(4) =
    "\p"
    "No plans...{Press}";

char const gCppRuntimeBadAlloc_CalendarNoPlansFirst[] ALIGN(4) =
    "bad_alloc";

char const gText_Calendar_FallbackNone[] ALIGN(4) =
    "N/A ";

char const gCppRuntimeBadAlloc_CalendarNoPlansSecond[] ALIGN(4) =
    "bad_alloc";
