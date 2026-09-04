#include "prelude.h"

#include "calendar_text.hh"
#include "unknown_types.hh" // for GameDate and Time

EC char const * func_0800E2E4(Season season)
{
    if (season < NUM_SEASONS)
    {
        return gText_Calendar_SeasonNames[season];
    }

    return gText_Calendar_None;
}

EC char const * func_0800E304(unsigned int week_day)
{
    if (week_day < 7)
    {
        return gText_Calendar_WeekdayNames[week_day];
    }

    return gText_Calendar_None;
}

struct Unk_0800E324
{
    u8 unk_00; /* year? */
    GameDate date;
    GameTime time;
};

EC u32 func_0800E324(Unk_0800E324 const & arg_0)
{
    GameDate const & date = arg_0.date;
    GameTime const & time = arg_0.time;

    if (date.GetDay() == 0 && time.GetHour() < 6)
    {
        /* get previous season
         * TODO: inline GetPreviousSeason(season)? */
        return (date.GetSeason() % NUM_SEASONS - 1u) % NUM_SEASONS;
    }

    return date.GetSeason();
}
