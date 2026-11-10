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

extern "C" NpcScheduleStorage_080F4974 const gUnk_080F4974 = {
    {
        IsLouSundayScheduleActive,
        2,
        gUnk_080F4974.table_choices,
    },
    {
        nullptr,
        &gUnk_080F4974.table_storage[0],
    },
    {
        { 1, &gUnk_080F4974.entry_storage[0] },
    },
    {
        { 0x00000000, &gUnk_080F4974.payload_storage[0] },
    },
    {
        { &gUnk_080F4974.detail_storage[0], 2, 160, 160, 23, 0, true },
    },
    {
        { 0x0070, 0x0002, 0x0078, 0x0002 },
        { 0x00A0, 0x0002, 0x0078, 0x0003 },
    },
};
