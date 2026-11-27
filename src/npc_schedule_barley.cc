#include "npc_schedule_barley.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectBarleySchedule(void const * context)
{
    GameStateSaveImage const & save = *(GameStateSaveImage const *)context;
    GameDayDate date;
    u8 season;
    u8 day;
    u8 weekday;

    DecodeGameDayDate(&date, &save.clock.calendar);

    season = date.season;
    day = date.day;
    weekday = date.weekday;

    if (IsNpcScheduleDateListed(season, day) << 0x18)
        return 4;

    if (weekday == 1)
    {
        if (save.clock.weather_today == 0)
            return 2;

        return 3;
    }

    return 1;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" BarleyScheduleData const gBarleyScheduleData = {
    // descriptor
    {
        SelectBarleySchedule,
        ARRAY_COUNT(gBarleyScheduleData.table_choices),
        gBarleyScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gBarleyScheduleData.table_storage[0],
        &gBarleyScheduleData.table_storage[1],
        &gBarleyScheduleData.table_storage[2],
        &gBarleyScheduleData.table_storage[3],
    },
    // table_storage
    {
        { ARRAY_COUNT(gBarleyScheduleData.entries_0), gBarleyScheduleData.entries_0 },
        { ARRAY_COUNT(gBarleyScheduleData.entries_1), gBarleyScheduleData.entries_1 },
        { ARRAY_COUNT(gBarleyScheduleData.entries_2), gBarleyScheduleData.entries_2 },
        { ARRAY_COUNT(gBarleyScheduleData.entries_3), gBarleyScheduleData.entries_3 },
    },
    // entries_0
    {
        { 0x00000000, &gBarleyScheduleData.payload_storage[2] },
        { 0x00000078, &gBarleyScheduleData.payload_storage[12] },
        { 0x00000080, &gBarleyScheduleData.payload_storage[0] },
        { 0x0000030C, &gBarleyScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gBarleyScheduleData.payload_storage[2] },
        { 0x00000078, &gBarleyScheduleData.payload_storage[4] },
        { 0x0000008E, &gBarleyScheduleData.payload_storage[3] },
        { 0x000000C3, &gBarleyScheduleData.payload_storage[5] },
        { 0x000001A4, &gBarleyScheduleData.payload_storage[6] },
        { 0x000001DA, &gBarleyScheduleData.payload_storage[7] },
        { 0x000001EA, &gBarleyScheduleData.payload_storage[8] },
        { 0x00000258, &gBarleyScheduleData.payload_storage[9] },
        { 0x00000269, &gBarleyScheduleData.payload_storage[10] },
        { 0x0000028B, &gBarleyScheduleData.payload_storage[0] },
        { 0x0000030C, &gBarleyScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0x00000000, &gBarleyScheduleData.payload_storage[2] },
        { 0x00000078, &gBarleyScheduleData.payload_storage[4] },
        { 0x0000008E, &gBarleyScheduleData.payload_storage[3] },
        { 0x000000C3, &gBarleyScheduleData.payload_storage[5] },
        { 0x000001A4, &gBarleyScheduleData.payload_storage[6] },
        { 0x000001DA, &gBarleyScheduleData.payload_storage[11] },
        { 0x000001F3, &gBarleyScheduleData.payload_storage[0] },
        { 0x00000258, &gBarleyScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0x00000000, &gBarleyScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 81, 160, 41, 3, false },
        { gBarleyScheduleData.points_1, ARRAY_COUNT(gBarleyScheduleData.points_1), 64, 80, 42, 0, true },
        { gBarleyScheduleData.points_2, ARRAY_COUNT(gBarleyScheduleData.points_2), 1112, 272, 7, 0, true },
        { gBarleyScheduleData.points_3, ARRAY_COUNT(gBarleyScheduleData.points_3), 1260, 704, 5, 0, false },
        { gBarleyScheduleData.points_4, ARRAY_COUNT(gBarleyScheduleData.points_4), 1112, 272, 7, 0, false },
        { nullptr, 0, 120, 144, 30, 1, false },
        { gBarleyScheduleData.points_6, ARRAY_COUNT(gBarleyScheduleData.points_6), 480, 160, 5, 0, false },
        { gBarleyScheduleData.points_7, ARRAY_COUNT(gBarleyScheduleData.points_7), 1200, 528, 0, 0, false },
        { gBarleyScheduleData.points_8, ARRAY_COUNT(gBarleyScheduleData.points_8), 944, 536, 0, 0, true },
        { gBarleyScheduleData.points_9, ARRAY_COUNT(gBarleyScheduleData.points_9), 944, 536, 0, 0, false },
        { gBarleyScheduleData.points_10, ARRAY_COUNT(gBarleyScheduleData.points_10), 812, 512, 7, 0, false },
        { gBarleyScheduleData.points_11, ARRAY_COUNT(gBarleyScheduleData.points_11), 1272, 0, 7, 0, false },
        { gBarleyScheduleData.points_12, ARRAY_COUNT(gBarleyScheduleData.points_12), 1112, 272, 7, 0, false },
    },
    // points_1
    {
        { 168, 2, 120, 3, true },
        { 80, 2, 120, 3, true },
    },
    // points_2
    {
        { 1176, 2, 120, 3, false },
        { 1112, 2, 120, 2, false },
    },
    // points_3
    {
        { 7, 536, true },
        { 25, 808, false },
        { 38, 216, true },
        { 51, 480, false },
        { 53, 160, true },
    },
    // points_4
    {
        { 2, 1060, false },
        { 7, 152, true },
        { 15, 1248, false },
        { 16, 128, true },
        { 17, 1272, false },
        { 22, 0, true },
    },
    // points_6
    {
        { 2, 216, true },
        { 15, 808, false },
        { 28, 536, true },
        { 46, 1260, false },
        { 54, 734, true },
    },
    // points_7
    {
        { 1, 1176, false },
        { 2, 512, true },
        { 3, 1160, false },
        { 4, 496, true },
        { 5, 1144, false },
        { 6, 480, true },
        { 12, 1000, false },
        { 14, 536, true },
        { 16, 944, false },
    },
    // points_8
    {
        { 880, 2, 120, 2, false },
        { 944, 2, 120, 3, false },
    },
    // points_9
    {
        { 2, 1000, false },
        { 4, 480, true },
        { 10, 1144, false },
        { 11, 496, true },
        { 12, 1160, false },
        { 13, 512, true },
        { 14, 1176, false },
        { 15, 528, true },
        { 17, 1216, false },
    },
    // points_10
    {
        { 14, 152, true },
        { 24, 1060, false },
        { 29, 280, true },
        { 32, 992, false },
        { 34, 232, true },
    },
    // points_11
    {
        { 5, 128, true },
        { 6, 1248, false },
        { 7, 152, true },
        { 15, 1060, false },
        { 20, 280, true },
        { 23, 992, false },
        { 25, 232, true },
    },
    // points_12
    {
        { 2, 1060, false },
        { 3, 280, true },
        { 6, 992, false },
        { 8, 232, true },
    },
};
