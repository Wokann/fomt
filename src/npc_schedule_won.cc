#include "npc_schedule_won.hh"
#include "game_state.hh"
#include <algorithm>

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectWonSchedule(void const * context)
{
    GameStateSaveImage const & save = *(GameStateSaveImage const *)context;
    GameDayDate date;
    u8 season;
    u8 day;

    DecodeGameDayDate(&date, &save.clock.calendar);

    season = date.season;
    day = date.day;

    if (IsNpcScheduleDateListed(season, day) << 0x18)
        return 2;

    if (std::min<u32>(200, save.clock.calendar.GetYear()) > 1)
        return 1;

    if (season != 0)
        return 1;

    if (day > 2)
        return 1;

    return 0;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" WonScheduleData const gWonScheduleData = {
    // descriptor
    {
        SelectWonSchedule,
        ARRAY_COUNT(gWonScheduleData.table_choices),
        gWonScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gWonScheduleData.table_storage[0],
        &gWonScheduleData.table_storage[1],
    },
    // table_storage
    {
        { ARRAY_COUNT(gWonScheduleData.entries_0), gWonScheduleData.entries_0 },
        { ARRAY_COUNT(gWonScheduleData.entries_1), gWonScheduleData.entries_1 },
    },
    // entries_0
    {
        { 0x00000000, &gWonScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gWonScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 191, 141, 13, 2, false },
    },
};
