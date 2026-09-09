#include "calendar_text.hh"
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
