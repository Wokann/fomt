#include "npc_schedule_ellen.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectEllenSchedule(void const * context)
{
    if ((i32)(((u8 const *)context)[0x21CA] << 26) < 0)
        return 0;
    u8 date[4];
    u8 const * raw = date;
    DecodeGameDayDate((GameDayDate *)date,
        (GameCalendar const *)((u8 const *)context + 16));
    if ((u8)IsNpcScheduleDateListed(raw[1], raw[2]))
        return 2;
    return 1;
}

asm_unified(
    "    .align 2, 0\n"
);

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
