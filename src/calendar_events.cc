#include "calendar_events.hh"

#include "unknown_types.hh"

// This fixed-width season-name storage is immediately followed by the native
// calendar date bytes.  Its final NUL is the first logical season byte; every
// following pair stores a day and the next logical season byte.
CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames = {
#if defined(REGION_JP)
    {
        "春",
        "夏",
        "秋",
        "冬",
    },
#elif defined(REGION_DE)
    {
        "Frühling",
        "Sommer",
        "Herbst",
        "Winter",
    },
#else
    {
        "Spring",
        "Summer",
        "Fall",
        "Winter",
    },
#endif
    {
        {  1, SEASON_SPRING },
        { 14, SEASON_SPRING },
        { 18, SEASON_SPRING },
        { 22, SEASON_SUMMER },
        {  1, SEASON_SUMMER },
        {  7, SEASON_SUMMER },
        { 20, SEASON_SUMMER },
        { 24, SEASON_FALL },
        {  3, SEASON_FALL },
        {  9, SEASON_FALL },
        { 13, SEASON_FALL },
        { 18, SEASON_FALL },
        { 21, SEASON_FALL },
        { 30, SEASON_WINTER },
        { 14, SEASON_WINTER },
        { 24, SEASON_WINTER },
        { 30, SEASON_SPRING },
    },
};

#include FOMT_TEXT_INCLUDE(calendar_events.cc)
