#include "npc_schedule_jeff.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectJeffSchedule(void const * context)
{
    GameStateSaveImage const & save = *(GameStateSaveImage const *)context;
    GameDayDate date;
    u8 season;
    u8 day;
    u8 weekday;

    if (save.event_state.rick_and_karen_rival_wedding_routing_state)
        return 0;

    DecodeGameDayDate(&date, &save.clock.calendar);

    season = date.season;
    day = date.day;
    weekday = date.weekday;

    if (IsNpcScheduleDateListed(season, day) << 0x18)
        return 4;

    if (weekday == 2)
        return 2;

    if (weekday == 0)
        return 3;

    return 1;
}

asm_unified(
    "    .align 2, 0\n"
);

// This is the immediately following, larger instance of the same selector
// family. The repeated entries intentionally retain their original pointers:
// native readers distinguish table placement even when a payload is shared.
extern "C" JeffScheduleData const gJeffScheduleData = {
    // descriptor
    {
        SelectJeffSchedule,
        ARRAY_COUNT(gJeffScheduleData.table_choices),
        gJeffScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gJeffScheduleData.table_storage[0],
        &gJeffScheduleData.table_storage[1],
        &gJeffScheduleData.table_storage[2],
        &gJeffScheduleData.table_storage[3],
    },
    // table_storage
    {
        { ARRAY_COUNT(gJeffScheduleData.entries_0), gJeffScheduleData.entries_0 },
        { ARRAY_COUNT(gJeffScheduleData.entries_1), gJeffScheduleData.entries_1 },
        { ARRAY_COUNT(gJeffScheduleData.entries_2), gJeffScheduleData.entries_2 },
        { ARRAY_COUNT(gJeffScheduleData.entries_3), gJeffScheduleData.entries_3 },
    },
    // entries_0
    {
        { 0x0000, &gJeffScheduleData.payload_storage[0] },
        { 0x0078, &gJeffScheduleData.payload_storage[1] },
        { 0x02D0, &gJeffScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x0000, &gJeffScheduleData.payload_storage[0] },
        { 0x00F3, &gJeffScheduleData.payload_storage[2] },
        { 0x010E, &gJeffScheduleData.payload_storage[3] },
        { 0x01A7, &gJeffScheduleData.payload_storage[4] },
        { 0x01BB, &gJeffScheduleData.payload_storage[5] },
        { 0x0258, &gJeffScheduleData.payload_storage[6] },
        { 0x0263, &gJeffScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x0000, &gJeffScheduleData.payload_storage[0] },
        { 0x01A7, &gJeffScheduleData.payload_storage[7] },
        { 0x01C4, &gJeffScheduleData.payload_storage[8] },
        { 0x025B, &gJeffScheduleData.payload_storage[9] },
        { 0x0278, &gJeffScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x0000, &gJeffScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 40, 88, 16, 1, false },
        { nullptr, 0, 227, 115, 15, 0, false },
        { gJeffScheduleData.points_2, ARRAY_COUNT(gJeffScheduleData.points_2), 688, 160, 5, 0, false },
        { nullptr, 0, 264, 155, 12, 1, false },
        { gJeffScheduleData.points_4, ARRAY_COUNT(gJeffScheduleData.points_4), 1232, 156, 5, 0, false },
        { nullptr, 0, 40, 192, 19, 3, false },
        { gJeffScheduleData.points_6, ARRAY_COUNT(gJeffScheduleData.points_6), 856, 164, 5, 0, false },
        { gJeffScheduleData.points_7, ARRAY_COUNT(gJeffScheduleData.points_7), 688, 160, 5, 0, false },
        { nullptr, 0, 224, 235, 21, 3, false },
        { gJeffScheduleData.points_9, ARRAY_COUNT(gJeffScheduleData.points_9), 632, 488, 5, 0, false },
    },
    // points_2
    {
        { 2, 216, true },
        { 24, 1232, false },
        { 27, 156, true },
    },
    // points_4
    {
        { 3, 216, true },
        { 18, 856, false },
        { 20, 164, true },
    },
    // points_6
    {
        { 2, 216, true },
        { 9, 688, false },
        { 11, 160, true },
    },
    // points_7
    {
        { 2, 216, true },
        { 7, 808, false },
        { 20, 536, true },
        { 27, 632, false },
        { 29, 488, true },
    },
    // points_9
    {
        { 2, 536, true },
        { 9, 808, false },
        { 22, 216, true },
        { 27, 688, false },
        { 29, 160, true },
    },
};
