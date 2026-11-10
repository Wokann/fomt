#include "npc_schedule_lou.hh"
#include "game_state.hh"

extern "C" u32 IsLouSundayScheduleActive(void const * context)
{
    GameStateSaveImage const & state = *static_cast<GameStateSaveImage const *>(context);
    GameDayDate date;
    DecodeGameDayDate(&date, &state.clock.calendar);
    u8 const weekday = date.weekday;
    u32 const introduction = state.event_state.lou_or_ruby_introduction_event_state;
    if (introduction == 2 && weekday == DAY_OF_WEEK_SUNDAY)
        return 1;
    return 0;
}

extern "C" LouScheduleData const gLouScheduleData = {
    // descriptor
    {
        IsLouSundayScheduleActive,
        ARRAY_COUNT(gLouScheduleData.table_choices),
        gLouScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gLouScheduleData.table_storage[0],
    },
    // table_storage
    {
        { ARRAY_COUNT(gLouScheduleData.entries_0), gLouScheduleData.entries_0 },
    },
    // entries_0
    {
        { 0x00000000, &gLouScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gLouScheduleData.points_0, ARRAY_COUNT(gLouScheduleData.points_0), 160, 160, 23, 0, true },
    },
    // points_0
    {
        { 112, 2, 120, 2, false },
        { 160, 2, 120, 3, false },
    },
};
