#include "npc_schedule_duke.hh"
#include "game_state.hh"

extern "C" u32 SelectDukeSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    GameDayDate date;
    u8 season;
    u8 day;
    u8 weekday;
    u8 saved;
    DecodeGameDayDate(&date, &save.clock.calendar);
    season = date.season;
    day = date.day;
    weekday = date.weekday;
    saved = weekday;
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 5;
    if (save.event_state.ann_and_cliff_rival_wedding_routing_state)
        return 0;
    if ((u32)save.event_state.told_cliff_about_grape_harvest_job == 1
        && save.event_state.cliff_permanent_winery_job_event_state == 2)
    {
        if (weekday == 6)
            return 4;
        return 3;
    }
    if (saved == 6)
        return 2;
    return 1;
}

extern "C" DukeScheduleData const gDukeScheduleData = {
    // descriptor
    {
        SelectDukeSchedule,
        ARRAY_COUNT(gDukeScheduleData.table_choices),
        gDukeScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gDukeScheduleData.table_storage[0],
        &gDukeScheduleData.table_storage[1],
        &gDukeScheduleData.table_storage[2],
        &gDukeScheduleData.table_storage[3],
        &gDukeScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gDukeScheduleData.entries_0), gDukeScheduleData.entries_0 },
        { ARRAY_COUNT(gDukeScheduleData.entries_1), gDukeScheduleData.entries_1 },
        { ARRAY_COUNT(gDukeScheduleData.entries_2), gDukeScheduleData.entries_2 },
        { ARRAY_COUNT(gDukeScheduleData.entries_3), gDukeScheduleData.entries_3 },
        { ARRAY_COUNT(gDukeScheduleData.entries_4), gDukeScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
        { 0x0000003C, &gDukeScheduleData.payload_storage[0] },
        { 0x000000F0, &gDukeScheduleData.payload_storage[5] },
        { 0x000000F6, &gDukeScheduleData.payload_storage[2] },
        { 0x000001E0, &gDukeScheduleData.payload_storage[3] },
        { 0x000001E5, &gDukeScheduleData.payload_storage[4] },
        { 0x00000294, &gDukeScheduleData.payload_storage[6] },
        { 0x0000029D, &gDukeScheduleData.payload_storage[0] },
        { 0x0000030C, &gDukeScheduleData.payload_storage[7] },
        { 0x00000320, &gDukeScheduleData.payload_storage[8] },
        { 0x000003C3, &gDukeScheduleData.payload_storage[9] },
        { 0x000003D7, &gDukeScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
        { 0x0000003C, &gDukeScheduleData.payload_storage[0] },
        { 0x000001A4, &gDukeScheduleData.payload_storage[7] },
        { 0x000001B8, &gDukeScheduleData.payload_storage[8] },
        { 0x0000025B, &gDukeScheduleData.payload_storage[9] },
        { 0x0000026F, &gDukeScheduleData.payload_storage[0] },
        { 0x000003C0, &gDukeScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
        { 0x0000003C, &gDukeScheduleData.payload_storage[0] },
        { 0x000001A7, &gDukeScheduleData.payload_storage[5] },
        { 0x000001AD, &gDukeScheduleData.payload_storage[2] },
        { 0x0000021C, &gDukeScheduleData.payload_storage[3] },
        { 0x00000221, &gDukeScheduleData.payload_storage[4] },
        { 0x00000294, &gDukeScheduleData.payload_storage[6] },
        { 0x0000029D, &gDukeScheduleData.payload_storage[0] },
        { 0x0000030C, &gDukeScheduleData.payload_storage[7] },
        { 0x00000320, &gDukeScheduleData.payload_storage[8] },
        { 0x000003C3, &gDukeScheduleData.payload_storage[9] },
        { 0x000003D7, &gDukeScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
        { 0x0000003C, &gDukeScheduleData.payload_storage[0] },
        { 0x000001A4, &gDukeScheduleData.payload_storage[7] },
        { 0x000001B8, &gDukeScheduleData.payload_storage[8] },
        { 0x00000260, &gDukeScheduleData.payload_storage[10] },
        { 0x0000028C, &gDukeScheduleData.payload_storage[11] },
        { 0x00000312, &gDukeScheduleData.payload_storage[12] },
        { 0x0000034E, &gDukeScheduleData.payload_storage[0] },
        { 0x000003DD, &gDukeScheduleData.payload_storage[1] },
    },
    // entries_4
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
    },
    // payload_storage
    {
        { gDukeScheduleData.points_0, ARRAY_COUNT(gDukeScheduleData.points_0), 40, 168, 31, 0, true },
        { nullptr, 0, 32, 152, 32, 0, false },
        { gDukeScheduleData.points_2, ARRAY_COUNT(gDukeScheduleData.points_2), 24, 80, 34, 0, true },
        { gDukeScheduleData.points_3, ARRAY_COUNT(gDukeScheduleData.points_3), 314, 456, 5, 0, false },
        { nullptr, 0, 408, 476, 5, 1, false },
        { gDukeScheduleData.points_5, ARRAY_COUNT(gDukeScheduleData.points_5), 232, 484, 5, 0, false },
        { gDukeScheduleData.points_6, ARRAY_COUNT(gDukeScheduleData.points_6), 408, 476, 5, 0, false },
        { gDukeScheduleData.points_7, ARRAY_COUNT(gDukeScheduleData.points_7), 232, 476, 5, 0, false },
        { nullptr, 0, 16, 147, 21, 3, false },
        { gDukeScheduleData.points_9, ARRAY_COUNT(gDukeScheduleData.points_9), 632, 488, 5, 0, false },
        { gDukeScheduleData.points_10, ARRAY_COUNT(gDukeScheduleData.points_10), 632, 488, 5, 0, false },
        { nullptr, 0, 104, 195, 12, 1, false },
        { gDukeScheduleData.points_12, ARRAY_COUNT(gDukeScheduleData.points_12), 1232, 160, 5, 0, false },
    },
    // points_0
    {
        { 88, 2, 120, 3, false },
        { 40, 2, 120, 2, false },
    },
    // points_2
    {
        { 56, 2, 240, 1, false },
        { 24, 2, 240, 1, false },
    },
    // points_3
    {
        { 1, 476, true },
        { 5, 408, false },
    },
    // points_5
    {
        { 1, 496, true },
        { 2, 265, false },
        { 3, 476, true },
        { 5, 316, false },
        { 6, 460, true },
    },
    // points_6
    {
        { 6, 265, false },
        { 7, 496, true },
        { 8, 232, false },
        { 9, 484, true },
    },
    // points_7
    {
        { 2, 536, true },
        { 18, 632, false },
        { 20, 484, true },
    },
    // points_9
    {
        { 2, 536, true },
        { 18, 232, false },
        { 20, 476, true },
    },
    // points_10
    {
        { 2, 536, true },
        { 27, 1260, false },
        { 39, 240, true },
        { 40, 1248, false },
        { 41, 216, true },
        { 42, 1232, false },
        { 44, 156, true },
    },
    // points_12
    {
        { 2, 216, true },
        { 3, 1248, false },
        { 4, 240, true },
        { 5, 1260, false },
        { 17, 536, true },
        { 58, 232, false },
        { 60, 476, true },
    },
};
