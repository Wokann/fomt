#include "npc_schedule_carter.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectCarterSchedule(void const * context)
{
    u8 date[4];
    u8 const * raw;
    u8 const * ctx = (u8 const *)context;
    u8 season;
    u8 day;
    u8 weekday;
    if (ctx[0x21CA] & 0x7C)
        return 0;
    raw = date;
    DecodeGameDayDate((GameDayDate *)date, (GameCalendar const *)(ctx + 16));
    season = raw[1];
    day = raw[2];
    weekday = raw[3];
    if (season == 2 && day == 3)
        return 9;
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 8;
    if (weekday == 1 || weekday == 3)
        return 1;
    if (*(u32 const *)(ctx + 8) == 0)
        return 2;
    return 1;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" CarterScheduleData const gCarterScheduleData = {
    // descriptor
    {
        SelectCarterSchedule,
        ARRAY_COUNT(gCarterScheduleData.table_choices),
        gCarterScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gCarterScheduleData.table_storage[0],
        &gCarterScheduleData.table_storage[1],
        &gCarterScheduleData.table_storage[2],
        &gCarterScheduleData.table_storage[3],
        &gCarterScheduleData.table_storage[4],
        &gCarterScheduleData.table_storage[5],
        &gCarterScheduleData.table_storage[6],
        &gCarterScheduleData.table_storage[7],
        &gCarterScheduleData.table_storage[8],
    },
    // table_storage
    {
        { ARRAY_COUNT(gCarterScheduleData.entries_0), gCarterScheduleData.entries_0 },
        { ARRAY_COUNT(gCarterScheduleData.entries_1), gCarterScheduleData.entries_1 },
        { ARRAY_COUNT(gCarterScheduleData.entries_2), gCarterScheduleData.entries_2 },
        { ARRAY_COUNT(gCarterScheduleData.entries_3), gCarterScheduleData.entries_3 },
        { ARRAY_COUNT(gCarterScheduleData.entries_4), gCarterScheduleData.entries_4 },
        { ARRAY_COUNT(gCarterScheduleData.entries_5), gCarterScheduleData.entries_5 },
        { ARRAY_COUNT(gCarterScheduleData.entries_6), gCarterScheduleData.entries_6 },
        { ARRAY_COUNT(gCarterScheduleData.entries_7), gCarterScheduleData.entries_7 },
        { ARRAY_COUNT(gCarterScheduleData.entries_8), gCarterScheduleData.entries_8 },
    },
    // entries_0
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[0] },
        { 0x000000B4, &gCarterScheduleData.payload_storage[1] },
        { 0x000000B9, &gCarterScheduleData.payload_storage[2] },
        { 0x000001A4, &gCarterScheduleData.payload_storage[3] },
        { 0x00000258, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_1
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[0] },
        { 0x000000B4, &gCarterScheduleData.payload_storage[1] },
        { 0x000000B9, &gCarterScheduleData.payload_storage[2] },
        { 0x000001A4, &gCarterScheduleData.payload_storage[4] },
        { 0x000001A7, &gCarterScheduleData.payload_storage[5] },
        { 0x00000258, &gCarterScheduleData.payload_storage[6] },
        { 0x0000025B, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_2
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_3
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_4
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_5
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_6
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_7
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_8
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
        { 0x000002D0, &gCarterScheduleData.payload_storage[7] },
        { 0x000002D1, &gCarterScheduleData.payload_storage[8] },
        { 0x0000041A, &gCarterScheduleData.payload_storage[9] },
        { 0x0000041B, &gCarterScheduleData.payload_storage[2] },
    },
    // payload_storage
    {
        { gCarterScheduleData.points_0, ARRAY_COUNT(gCarterScheduleData.points_0), 1160, 152, 5, 0, true },
        { gCarterScheduleData.points_1, ARRAY_COUNT(gCarterScheduleData.points_1), 1160, 152, 5, 0, false },
        { nullptr, 0, 184, 67, 12, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
        { gCarterScheduleData.points_4, ARRAY_COUNT(gCarterScheduleData.points_4), 1232, 156, 5, 0, false },
        { nullptr, 0, 1224, 208, 5, 2, false },
        { gCarterScheduleData.points_6, ARRAY_COUNT(gCarterScheduleData.points_6), 1224, 208, 5, 0, false },
        { gCarterScheduleData.points_7, ARRAY_COUNT(gCarterScheduleData.points_7), 1232, 156, 5, 0, false },
        { nullptr, 0, 1232, 181, 5, 0, false },
        { gCarterScheduleData.points_9, ARRAY_COUNT(gCarterScheduleData.points_9), 1232, 181, 5, 0, false },
    },
    // points_0
    {
        { 1088, 2, 120, 1, false },
        { 1160, 2, 120, 1, false },
    },
    // points_1
    {
        { 1, 160, true },
        { 4, 1232, false },
        { 5, 156, true },
    },
    // points_4
    {
        { 2, 208, true },
        { 3, 1224, false },
    },
    // points_6
    {
        { 1, 1232, false },
        { 3, 156, true },
    },
    // points_7
    {
        { 1, 181, true },
    },
    // points_9
    {
        { 1, 156, true },
    },
};
