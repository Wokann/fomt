#ifndef CALENDAR_HH
#define CALENDAR_HH

#include "unknown_types.hh"

struct GameCalendar;

#if defined(REGION_JP)
extern char const gText_Calendar_SeasonNames[4][3];
extern char const gText_Calendar_WeekdayNames[7][3];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_Calendar_SeasonNames[4][7];
extern char const gText_Calendar_WeekdayNames[7][5];
#endif
extern char const gText_Calendar_None[];

// Borrowed ROM label, returned as one word and consumed through its C-string view.
struct CalendarSeasonLabel
{
    char const * value;
    explicit CalendarSeasonLabel(char const * text) : value(text) {}
    operator char const *() const { return value; }
};
typedef char CalendarSeasonLabelSizeCheck[sizeof(CalendarSeasonLabel) == 4 ? 1 : -1];

CalendarSeasonLabel GetCalendarSeasonLabel(Season season);
// Returns a borrowed weekday label, or the calendar fallback for an invalid index.
extern "C" char const * GetCalendarWeekdayLabel(unsigned int week_day);
// The first day before 06:00 still uses the preceding season.
// Keep the original word-sized return ABI for its native callers.
extern "C" u32 GetCalendarEffectiveSeason(GameCalendar const & calendar);
#endif // CALENDAR_HH
