#include "world_lighting.hh"
#include "game_world.hh"
#include "map_data.hh"

EC void RefreshWorldMapTimeOfDayPalette(GameSceneWorldPrefix & world)
{
    world.data.map.value->RefreshAppearance(world.time_of_day_period,
        world.time_palette_blend, 30 - world.time_palette_blend);
    if (GetMapData(world.data.map.value->map_data_id)->flags == 0) {
        GameCalendar const & calendar = *world.calendar;
        UpdateWorldTimeOfDayPalettes(world, calendar.time.clock_hour,
            calendar.time.clock_minute, 1);
    }
}

EC TimeOfDayPeriod GetWorldTimeOfDayPeriod(GameSceneWorldPrefix &, u32 hour)
{
    if (hour <= 5)
        return TIME_OF_DAY_PERIOD_NIGHT;
    else if (hour <= 11)
        return TIME_OF_DAY_PERIOD_MORNING;
    else if (hour > 17)
        return TIME_OF_DAY_PERIOD_EVENING;
    else
        return TIME_OF_DAY_PERIOD_AFTERNOON;
}
