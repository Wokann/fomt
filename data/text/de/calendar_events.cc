#include "calendar_events.hh"

#include "unknown_types.hh"

// This is the separate fixed-width season-name copy expanded by the calendar
// dynamic-field handler, followed by the native calendar date storage.  Its
// final NUL is the first logical season byte; every following pair stores a
// day and the next logical season byte.

CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames
    ALIGN(1) = {
    {
        "Frühling",
        "Sommer",
        "Herbst",
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
    "1. Frühlingstag\r\n"
    "Neujahrsfeier Rosenplatz\r\n"
    "18 Uhr bis Mitternacht.{Press}";

char const gText_Calendar_Festival_SpringThanksgiving[] ALIGN(4) =
    "\p"
    "14. Frühlingstag\r\n"
    "Frühlings-Erntedankfest{Press}";

char const gText_Calendar_Festival_SpringHorseRace[] ALIGN(4) =
    "\p"
    "18. Frühlingstag\r\n"
    "Frühlings-Pferderennen auf\r\n"
    "dem Rosenplatz (10 - 18Uhr){Press}";

char const gText_Calendar_Festival_CookingFestival[] ALIGN(4) =
    "\p"
    "22. Frühlingstag\r\n"
    "Kochfestival auf dem\r\n"
    "Rosenplatz (10 -18Uhr){Press}";

char const gText_Calendar_Festival_BeachDay[] ALIGN(4) =
    "\p"
    "1. Sommertag\r\n"
    "Strandtag am Mineralstrand\r\n"
    "(10 -18Uhr) {Press}";

char const gText_Calendar_Festival_ChickenFestival[] ALIGN(4) =
    "\p"
    "7. Sommertag\r\n"
    "Hühnerfestival auf dem\r\n"
    "Rosenplatz (10 -18Uhr){Press}";

char const gText_Calendar_Festival_CowFestival[] ALIGN(4) =
    "\p"
    "20. Sommertag\r\n"
    "Kuhfestival auf dem \r\n"
    "Rosenplatz (10 - 18Uhr){Press}";

char const gText_Calendar_Festival_FireworksFestival[] ALIGN(4) =
    "\p"
    "24. Sommertag\r\n"
    "Feuerwerkfestival am\r\n"
    "Mineralstrand (18 - 21Uhr){Press}";

char const gText_Calendar_Festival_MusicFestival[] ALIGN(4) =
    "\p"
    "3. Herbsttag\r\n"
    "Musikfestival in der Kirche\r\n"
    "(18 Uhr - Mitternacht) {Press}";

char const gText_Calendar_Festival_HarvestFestival[] ALIGN(4) =
    "\p"
    "9. Herbsttag\r\n"
    "Erntefest auf dem \r\n"
    "Rosenplatz (10 - 18Uhr){Press}";

char const gText_Calendar_Festival_FullMoonFestival[] ALIGN(4) =
    "\p"
    "13. Herbsttag \r\n"
    "Vollmondfest\r\n"
    "(18 Uhr - Mitternacht) {Press}";

char const gText_Calendar_Festival_FallHorseRace[] ALIGN(4) =
    "\p"
    "18. Herbsttag\r\n"
    "Herbst-Pferderennen auf\r\n"
    "dem Rosenplatz (10 - 18Uhr){Press}";

char const gText_Calendar_Festival_SheepFestival[] ALIGN(4) =
    "\p"
    "21. Herbsttag \r\n"
    "Schaffestival auf dem \r\n"
    "Rosenplatz (10 - 18 Uhr){Press}";

char const gText_Calendar_Festival_PumpkinFestival[] ALIGN(4) =
    "\p"
    "30. Herbsttag\r\n"
    "Kürbisfestival {Press}";

char const gText_Calendar_Festival_WinterThanksgiving[] ALIGN(4) =
    "\p"
    "14. Wintertag\r\n"
    "Erntedankfest{Press}";

char const gText_Calendar_Festival_StarryNightFestival[] ALIGN(4) =
    "\p"
    "24. Wintertag\r\n"
    "Sternennachtfest {Press}";

char const gText_Calendar_Festival_YearEndGathering[] ALIGN(4) =
    "\p"
    "30. Wintertag\r\n"
    "Jahresendversammlung\r\n"
    "Jahresendfeier {Press}";

char const gText_Calendar_Festival_Marriage[] =
    "\p"
    "\xF1. Tag von \xF0\r\n"
    "Ehe mit \xF2{Press}";

char const gText_Calendar_Festival_WeddingAnniversary[] ALIGN(4) =
    "\p"
    "Hochzeitstag{Press}";

char const gText_Calendar_Festival_NoPlans[] ALIGN(4) =
    "\p"
    "Keine Pläne...{Press}";

char const gCppRuntimeBadAlloc_CalendarNoPlansFirst[] ALIGN(4) =
    "bad_alloc";

char const gText_Calendar_FallbackNone[] ALIGN(4) =
    "N/A ";

char const gCppRuntimeBadAlloc_CalendarNoPlansSecond[] ALIGN(4) =
    "bad_alloc";
