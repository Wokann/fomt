#include "npc_schedule_lillia.hh"
#include "game_state.hh"

extern "C" u32 SelectLilliaSchedule(void const * context)
{
    GameStateSaveImage const & save = *(GameStateSaveImage const *)context;
    GameDayDate date;
    u8 season;
    u8 day;
    u8 weekday;
    u32 rival_wedding;

    rival_wedding =
        (u32)save.event_state.rick_and_karen_rival_wedding_routing_state
        | (u32)save.event_state.popuri_and_kai_rival_wedding_routing_state;

    if (rival_wedding != 0)
        return 0;

    DecodeGameDayDate(&date, &save.clock.calendar);

    season = date.season;
    day = date.day;
    weekday = date.weekday;

    if (IsNpcScheduleDateListed(season, day) << 0x18)
        return 3;

    if (weekday == 0)
        return 2;

    return 1;
}

// Recovered schedule data at US ROM 0x080F280C (JP 0x080F2068).
// The two regional payloads differ only in relocated function/data pointers.

extern "C" LilliaScheduleData const gLilliaScheduleData = {
    // descriptor
    { SelectLilliaSchedule, ARRAY_COUNT(gLilliaScheduleData.table_choices), gLilliaScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gLilliaScheduleData.table_storage[0], &gLilliaScheduleData.table_storage[1], &gLilliaScheduleData.table_storage[2],
    },
    // table_storage
    {
        { ARRAY_COUNT(gLilliaScheduleData.entries_0), gLilliaScheduleData.entries_0 },
        { ARRAY_COUNT(gLilliaScheduleData.entries_1), gLilliaScheduleData.entries_1 },
        { ARRAY_COUNT(gLilliaScheduleData.entries_2), gLilliaScheduleData.entries_2 },
    },
    // entries_0
    {
        { 0, &gLilliaScheduleData.payload_storage[0] },
        { 300, &gLilliaScheduleData.payload_storage[1] },
        { 780, &gLilliaScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0, &gLilliaScheduleData.payload_storage[0] },
        { 300, &gLilliaScheduleData.payload_storage[1] },
        { 421, &gLilliaScheduleData.payload_storage[2] },
        { 468, &gLilliaScheduleData.payload_storage[3] },
        { 507, &gLilliaScheduleData.payload_storage[4] },
        { 600, &gLilliaScheduleData.payload_storage[5] },
        { 640, &gLilliaScheduleData.payload_storage[6] },
        { 687, &gLilliaScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0, &gLilliaScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 112, 130, 11, 3, 0 },
        { nullptr, 0, 215, 160, 10, 2, 0 },
        { gLilliaScheduleData.points_2, ARRAY_COUNT(gLilliaScheduleData.points_2), 572, 227, 7, 0, 0 },
        { gLilliaScheduleData.points_3, ARRAY_COUNT(gLilliaScheduleData.points_3), 1260, 704, 5, 0, 0 },
        { nullptr, 0, 40, 246, 19, 3, 0 },
        { gLilliaScheduleData.points_5, ARRAY_COUNT(gLilliaScheduleData.points_5), 856, 164, 5, 0, 0 },
        { gLilliaScheduleData.points_6, ARRAY_COUNT(gLilliaScheduleData.points_6), 1272, 0, 7, 0, 0 },
    },
    // points_2
    {
        { 1, 248, 1 },
        { 5, 472, 0 },
        { 9, 152, 1 },
        { 40, 1248, 0 },
        { 41, 128, 1 },
        { 42, 1272, 0 },
        { 47, 0, 1 },
    },
    // points_3
    {
        { 19, 240, 1 },
        { 20, 1248, 0 },
        { 21, 216, 1 },
        { 37, 856, 0 },
        { 39, 164, 1 },
    },
    // points_5
    {
        { 2, 216, 1 },
        { 18, 1248, 0 },
        { 19, 240, 1 },
        { 20, 1260, 0 },
        { 40, 736, 1 },
    },
    // points_6
    {
        { 5, 128, 1 },
        { 6, 1248, 0 },
        { 7, 152, 1 },
        { 38, 472, 0 },
        { 42, 248, 1 },
        { 46, 572, 0 },
        { 47, 227, 1 },
    },
};
