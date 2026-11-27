#include "npc_schedule_ellen.hh"
#include "game_state.hh"

extern "C" u32 SelectEllenSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    if (save.event_state.elli_and_doctor_rival_wedding_routing_state)
        return 0;
    GameDayDate date;
    DecodeGameDayDate(&date, &save.clock.calendar);
    if ((u8)IsNpcScheduleDateListed(date.season, date.day))
        return 2;
    return 1;
}

// The physical order below is descriptor, table-choice array, two tables,
// two entries, the shared payload, and the C++ runtime string immediately
// following it.  Keeping it as one aggregate preserves the real internal
// relocations rather than embedding raw ROM addresses.
extern "C" EllenScheduleData const gEllenScheduleData = {
    { SelectEllenSchedule, ARRAY_COUNT(gEllenScheduleData.table_choices), gEllenScheduleData.table_choices },
    {
            nullptr,
            &gEllenScheduleData.table_storage[0],
            &gEllenScheduleData.table_storage[1],
        },
    {
        { ARRAY_COUNT(gEllenScheduleData.entries_0), gEllenScheduleData.entries_0 },
        { ARRAY_COUNT(gEllenScheduleData.entries_1), gEllenScheduleData.entries_1 },
    },
    { { 0, &gEllenScheduleData.payload } },
    { { 0, &gEllenScheduleData.payload } },
    { nullptr, 0, 128, 96, 14, 0, false },
};
