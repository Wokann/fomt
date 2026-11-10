#include "npc_schedule_van.hh"
#include "game_state.hh"

extern "C" u32 IsVanWednesdayScheduleActive(void const * context)
{
    GameStateSaveImage const & state = *static_cast<GameStateSaveImage const *>(context);
    GameDayDate date;
    DecodeGameDayDate(&date, &state.clock.calendar);
    u8 const weekday = date.weekday;
    u32 const introduction = state.event_state.van_introduction_event_state;
    if (introduction == 2 && weekday == DAY_OF_WEEK_WEDNESDAY)
        return 1;
    return 0;
}

extern "C" VanScheduleData const gVanScheduleData = {
    // descriptor
    {
        IsVanWednesdayScheduleActive,
        ARRAY_COUNT(gVanScheduleData.table_choices),
        gVanScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gVanScheduleData.table_storage[0],
    },
    // table_storage
    {
        { ARRAY_COUNT(gVanScheduleData.entries_0), gVanScheduleData.entries_0 },
    },
    // entries_0
    {
        { 0x00000000, &gVanScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 352, 248, 23, 2, false },
    },
};
