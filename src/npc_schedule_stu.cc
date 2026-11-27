#include "npc_schedule_stu.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectStuSchedule(void const * context)
{
    u8 date[4];
    u8 const * raw;
    u8 season;
    u8 day;
    u8 weekday;
    if ((i32)(((u8 const *)context)[0x21CA] << 26) < 0)
        return 0;
    raw = date;
    DecodeGameDayDate((GameDayDate *)date,
        (GameCalendar const *)((u8 const *)context + 16));
    season = raw[1];
    day = raw[2];
    weekday = raw[3];
    if (season == 2 && day == 30
        && (((u8 const *)context)[0x21A2] >> 6) != 2)
        return 5;
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 4;
    if ((i32)(((u8 const *)context)[0x215A] << 28) < 0)
        return 0;
    if (weekday == 1 || weekday == 3)
        return 3;
    if (*(u32 const *)((u8 const *)context + 8) == 0)
        return 1;
    return 2;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" StuScheduleData const gStuScheduleData = {
    // descriptor
    {
        SelectStuSchedule,
        ARRAY_COUNT(gStuScheduleData.table_choices),
        gStuScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gStuScheduleData.table_storage[0],
        &gStuScheduleData.table_storage[1],
        &gStuScheduleData.table_storage[2],
        &gStuScheduleData.table_storage[3],
        &gStuScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gStuScheduleData.entries_0), gStuScheduleData.entries_0 },
        { ARRAY_COUNT(gStuScheduleData.entries_1), gStuScheduleData.entries_1 },
        { ARRAY_COUNT(gStuScheduleData.entries_2), gStuScheduleData.entries_2 },
        { ARRAY_COUNT(gStuScheduleData.entries_3), gStuScheduleData.entries_3 },
        { ARRAY_COUNT(gStuScheduleData.entries_4), gStuScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
        { 0x000001A4, &gStuScheduleData.payload_storage[1] },
        { 0x000001C7, &gStuScheduleData.payload_storage[2] },
        { 0x00000258, &gStuScheduleData.payload_storage[3] },
        { 0x0000027B, &gStuScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
        { 0x00000078, &gStuScheduleData.payload_storage[6] },
        { 0x00000082, &gStuScheduleData.payload_storage[4] },
        { 0x000000B4, &gStuScheduleData.payload_storage[5] },
        { 0x000000BE, &gStuScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gStuScheduleData.points_0, ARRAY_COUNT(gStuScheduleData.points_0), 176, 160, 14, 0, true },
        { gStuScheduleData.points_1, ARRAY_COUNT(gStuScheduleData.points_1), 400, 160, 5, 0, false },
        { nullptr, 0, 1200, 200, 5, 0, false },
        { gStuScheduleData.points_3, ARRAY_COUNT(gStuScheduleData.points_3), 1200, 200, 5, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gStuScheduleData.points_5, ARRAY_COUNT(gStuScheduleData.points_5), 228, 145, 2, 0, false },
        { gStuScheduleData.points_6, ARRAY_COUNT(gStuScheduleData.points_6), 340, 0, 2, 0, false },
    },
    // points_0
    {
        { 96, 2, 120, 1, true },
        { 160, 2, 120, 0, true },
    },
    // points_1
    {
        { 2, 216, true },
        { 34, 1200, false },
        { 35, 200, true },
    },
    // points_3
    {
        { 1, 216, true },
        { 33, 400, false },
        { 35, 160, true },
    },
    // points_5
    {
        { 4, 340, false },
        { 10, 0, true },
    },
    // points_6
    {
        { 6, 145, true },
        { 10, 228, false },
    },
};
