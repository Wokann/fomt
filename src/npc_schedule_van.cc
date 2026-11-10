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

extern "C" NpcScheduleStorage_080F6B10 const gUnk_080F6B10 = {
    {
        IsVanWednesdayScheduleActive,
        2,
        gUnk_080F6B10.table_choices,
    },
    {
        nullptr,
        &gUnk_080F6B10.table_storage[0],
    },
    {
        { 1, &gUnk_080F6B10.entry_storage[0] },
    },
    {
        { 0x00000000, &gUnk_080F6B10.payload_storage[0] },
    },
    {
        { nullptr, 0, 352, 248, 23, 2, false },
    },
};
