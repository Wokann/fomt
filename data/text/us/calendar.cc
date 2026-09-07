#include "calendar_text.hh"

#include "unknown_types.hh"

// The section boundaries preserve the original two-byte alignment gaps without
// embedding padding bytes in the authored text.
char const gText_Calendar_SeasonNames[4][7] SECTION(".rodata.calendar.season") ALIGN(1) = {
    "Spring",
    "Summer",
    "Fall  ",
    "Winter"
};

// This is the separate fixed-width season-name copy expanded by the calendar
// dynamic-field handler, followed by the native calendar date storage.  Its
// final NUL is the first logical season byte; every following pair stores a
// day and the next logical season byte.
CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames
    CALENDAR_DYNAMIC_SEASON_TEXT ALIGN(1) = {
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

char const gText_Calendar_None[] SECTION(".rodata.calendar.none") =
    "無";

char const gText_Calendar_WeekdayNames[7][5] SECTION(".rodata.calendar.weekday") ALIGN(1) = {
    "Sun.",
    "Mon.",
    "Tue.",
    "Wed.",
    "Thu.",
    "Fri.",
    "Sat."
};

char const gText_Calendar_Festival_NewYearFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "1st day of Spring\r\n"
    "New Year Festival in Rose\r\n"
    "Square. 6PM - Midnight{Press}";

char const gText_Calendar_Festival_SpringThanksgiving[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "14th day of Spring\r\n"
    "Spring Thanksgiving Festival{Press}";

char const gText_Calendar_Festival_SpringHorseRace[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "18th day of Spring\r\n"
    "Spring Horse Racing\r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_CookingFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "22nd day of Spring\r\n"
    "Cooking Festival\r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_BeachDay[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "1st day of Summer\r\n"
    "Beach Day at Mineral Beach\r\n"
    "(10AM - 6PM) {Press}";

char const gText_Calendar_Festival_ChickenFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "7th day of Summer\r\n"
    "Chicken Festival in \r\n"
    "Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_CowFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "20th day of Summer\r\n"
    "Cow Festival \r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_FireworksFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "24th day of Summer\r\n"
    "Fireworks Festival \r\n"
    "at Mineral Beach (6-9PM) {Press}";

char const gText_Calendar_Festival_MusicFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "3rd day of Fall\r\n"
    "Music Festival in Church \r\n"
    "(6PM - Midnight) {Press}";

char const gText_Calendar_Festival_HarvestFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "9th day of Fall\r\n"
    "Harvest Festival \r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_FullMoonFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "13th day of Fall \r\n"
    "Full Moon Festival\r\n"
    "(6PM - Midnight) {Press}";

char const gText_Calendar_Festival_FallHorseRace[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "18th day of Fall\r\n"
    "Fall Horse Racing in\r\n"
    "Rose Square (10AM - 6PM) {Press}";

char const gText_Calendar_Festival_SheepFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "21st day of Fall \r\n"
    "Sheep Festival \r\n"
    "in Rose Square (10AM - 6PM){Press}";

char const gText_Calendar_Festival_PumpkinFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "30th day of Fall\r\n"
    "Pumpkin Festival {Press}";

char const gText_Calendar_Festival_WinterThanksgiving[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "14th day of Winter\r\n"
    "Thanksgiving{Press}";

char const gText_Calendar_Festival_StarryNightFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "24th day of Winter\r\n"
    "Starry Night Festival {Press}";

char const gText_Calendar_Festival_YearEndGathering[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "30th day of Winter\r\n"
    "Year End Gathering \r\n"
    "Year End Festival {Press}";

char const gText_Calendar_Festival_Marriage[] CALENDAR_FESTIVAL_DYNAMIC_TEXT =
    "\p"
    "\xF1st day of \xF0\r\n"
    "Marriage to \xF2{Press}";

char const gText_Calendar_Festival_WeddingAnniversary[] CALENDAR_FESTIVAL_DYNAMIC_TEXT =
    "\p"
    "\xF1st day of \xF0\r\n"
    "Wedding Anniversary{Press}";

char const gText_Calendar_Festival_NoPlans[] CALENDAR_NO_PLANS_TEXT =
    "\p"
    "No plans...{Press}";
