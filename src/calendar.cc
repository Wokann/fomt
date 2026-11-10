#include "calendar.hh"

#include "game_state.hh"
#include "time_of_day_types.hh"

#include FOMT_TEXT_INCLUDE(calendar.cc)

CalendarSeasonLabel GetCalendarSeasonLabel(Season season)
{
    if (season < NUM_SEASONS)
    {
        return CalendarSeasonLabel(gText_Calendar_SeasonNames[season]);
    }

    return CalendarSeasonLabel(gText_Calendar_None);
}

extern "C" char const * GetCalendarWeekdayLabel(unsigned int week_day)
{
    if (week_day < 7)
    {
        return gText_Calendar_WeekdayNames[week_day];
    }

    return gText_Calendar_None;
}

extern "C" u32 GetCalendarEffectiveSeason(GameCalendar const & calendar)
{
    GameDate const & date = calendar.date;
    GameTime const & time = calendar.time;

    if (date.GetDay() == 0 && time.GetHour() < 6)
        return (date.GetSeason() % NUM_SEASONS - 1u) % NUM_SEASONS;

    return date.GetSeason();
}
