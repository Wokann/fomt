#include "npc_schedule_may.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectMaySchedule(void const * context)
{
    u8 date[4];
    u8 const * raw;
    u8 season;
    u8 day;
    u8 weekday;
    raw = date;
    DecodeGameDayDate((GameDayDate *)date,
        (GameCalendar const *)((u8 const *)context + 16));
    season = raw[1];
    day = raw[2];
    weekday = raw[3];
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 5;
    if (season == 2 && day == 30
        && (((u32)((u8 const *)context)[0x21A2] << 26) >> 30) != 2)
        return 6;
    if ((i32)(((u8 const *)context)[0x215A] << 28) < 0)
        return 0;
    if (*(u32 const *)((u8 const *)context + 8) == 0)
    {
        if (weekday == 1)
            return 1;
        if (weekday == 3)
            return 2;
        return 3;
    }
    return 4;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" MayScheduleData const gMayScheduleData = {
    // descriptor
    {
        SelectMaySchedule,
        ARRAY_COUNT(gMayScheduleData.table_choices),
        gMayScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gMayScheduleData.table_storage[0],
        &gMayScheduleData.table_storage[1],
        &gMayScheduleData.table_storage[2],
        &gMayScheduleData.table_storage[3],
        &gMayScheduleData.table_storage[4],
        &gMayScheduleData.table_storage[5],
    },
    // table_storage
    {
        { ARRAY_COUNT(gMayScheduleData.entries_0), gMayScheduleData.entries_0 },
        { ARRAY_COUNT(gMayScheduleData.entries_1), gMayScheduleData.entries_1 },
        { ARRAY_COUNT(gMayScheduleData.entries_2), gMayScheduleData.entries_2 },
        { ARRAY_COUNT(gMayScheduleData.entries_3), gMayScheduleData.entries_3 },
        { ARRAY_COUNT(gMayScheduleData.entries_4), gMayScheduleData.entries_4 },
        { ARRAY_COUNT(gMayScheduleData.entries_5), gMayScheduleData.entries_5 },
    },
    // entries_0
    {
        { 0x00000000, &gMayScheduleData.payload_storage[0] },
        { 0x0000003C, &gMayScheduleData.payload_storage[2] },
        { 0x0000003F, &gMayScheduleData.payload_storage[3] },
        { 0x0000012C, &gMayScheduleData.payload_storage[4] },
        { 0x0000012F, &gMayScheduleData.payload_storage[0] },
        { 0x000001A4, &gMayScheduleData.payload_storage[5] },
        { 0x000001C6, &gMayScheduleData.payload_storage[6] },
        { 0x000001DA, &gMayScheduleData.payload_storage[7] },
        { 0x00000258, &gMayScheduleData.payload_storage[8] },
        { 0x0000026D, &gMayScheduleData.payload_storage[9] },
        { 0x0000028F, &gMayScheduleData.payload_storage[0] },
        { 0x0000030C, &gMayScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gMayScheduleData.payload_storage[0] },
        { 0x0000003C, &gMayScheduleData.payload_storage[2] },
        { 0x0000003F, &gMayScheduleData.payload_storage[3] },
        { 0x0000012C, &gMayScheduleData.payload_storage[4] },
        { 0x0000012F, &gMayScheduleData.payload_storage[0] },
        { 0x000001A4, &gMayScheduleData.payload_storage[2] },
        { 0x000001A7, &gMayScheduleData.payload_storage[3] },
        { 0x00000258, &gMayScheduleData.payload_storage[4] },
        { 0x0000025B, &gMayScheduleData.payload_storage[0] },
        { 0x0000030C, &gMayScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0x00000000, &gMayScheduleData.payload_storage[0] },
        { 0x0000003C, &gMayScheduleData.payload_storage[2] },
        { 0x0000003F, &gMayScheduleData.payload_storage[3] },
        { 0x0000012C, &gMayScheduleData.payload_storage[4] },
        { 0x0000012F, &gMayScheduleData.payload_storage[0] },
        { 0x000001A4, &gMayScheduleData.payload_storage[10] },
        { 0x000001BD, &gMayScheduleData.payload_storage[11] },
        { 0x000001D6, &gMayScheduleData.payload_storage[12] },
        { 0x00000258, &gMayScheduleData.payload_storage[13] },
        { 0x00000272, &gMayScheduleData.payload_storage[14] },
        { 0x0000028B, &gMayScheduleData.payload_storage[0] },
        { 0x0000030C, &gMayScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0x00000000, &gMayScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gMayScheduleData.payload_storage[0] },
    },
    // entries_5
    {
        { 0x00000000, &gMayScheduleData.payload_storage[17] },
        { 0x0000000A, &gMayScheduleData.payload_storage[15] },
        { 0x0000003C, &gMayScheduleData.payload_storage[16] },
        { 0x00000046, &gMayScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gMayScheduleData.points_0, ARRAY_COUNT(gMayScheduleData.points_0), 16, 96, 41, 0, true },
        { gMayScheduleData.points_1, ARRAY_COUNT(gMayScheduleData.points_1), 96, 80, 42, 0, true },
        { gMayScheduleData.points_2, ARRAY_COUNT(gMayScheduleData.points_2), 944, 228, 7, 0, false },
        { gMayScheduleData.points_3, ARRAY_COUNT(gMayScheduleData.points_3), 912, 216, 7, 0, true },
        { gMayScheduleData.points_4, ARRAY_COUNT(gMayScheduleData.points_4), 912, 216, 7, 0, false },
        { gMayScheduleData.points_5, ARRAY_COUNT(gMayScheduleData.points_5), 992, 232, 7, 0, false },
        { gMayScheduleData.points_6, ARRAY_COUNT(gMayScheduleData.points_6), 1200, 528, 0, 0, false },
        { nullptr, 0, 912, 575, 0, 1, false },
        { gMayScheduleData.points_8, ARRAY_COUNT(gMayScheduleData.points_8), 912, 576, 0, 0, false },
        { gMayScheduleData.points_9, ARRAY_COUNT(gMayScheduleData.points_9), 812, 512, 7, 0, false },
        { gMayScheduleData.points_10, ARRAY_COUNT(gMayScheduleData.points_10), 992, 232, 7, 0, false },
        { gMayScheduleData.points_11, ARRAY_COUNT(gMayScheduleData.points_11), 1260, 704, 5, 0, false },
        { nullptr, 0, 1176, 200, 5, 0, false },
        { gMayScheduleData.points_13, ARRAY_COUNT(gMayScheduleData.points_13), 1176, 200, 5, 0, false },
        { gMayScheduleData.points_14, ARRAY_COUNT(gMayScheduleData.points_14), 1272, 0, 7, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gMayScheduleData.points_16, ARRAY_COUNT(gMayScheduleData.points_16), 228, 145, 2, 0, false },
        { gMayScheduleData.points_17, ARRAY_COUNT(gMayScheduleData.points_17), 340, 0, 2, 0, false },
    },
    // points_0
    {
        { 88, 2, 120, 0, false },
        { 16, 2, 120, 0, false },
    },
    // points_1
    {
        { 144, 2, 120, 3, false },
        { 96, 2, 120, 2, false },
    },
    // points_2
    {
        { 1, 235, true },
        { 2, 912, false },
        { 3, 216, true },
    },
    // points_3
    {
        { 872, 2, 120, 2, false },
        { 912, 2, 120, 3, false },
    },
    // points_4
    {
        { 1, 235, true },
        { 2, 944, false },
        { 3, 228, true },
    },
    // points_5
    {
        { 2, 280, true },
        { 5, 1060, false },
        { 10, 152, true },
        { 20, 812, false },
        { 34, 544, true },
    },
    // points_6
    {
        { 1, 1176, false },
        { 2, 512, true },
        { 3, 1160, false },
        { 4, 496, true },
        { 5, 1144, false },
        { 6, 480, true },
        { 12, 1000, false },
        { 14, 536, true },
        { 15, 976, false },
        { 17, 575, true },
        { 20, 912, false },
    },
    // points_8
    {
        { 3, 976, false },
        { 5, 536, true },
        { 6, 1000, false },
        { 8, 480, true },
        { 14, 1144, false },
        { 15, 496, true },
        { 16, 1160, false },
        { 17, 512, true },
        { 18, 1176, false },
        { 19, 528, true },
        { 21, 1216, false },
    },
    // points_9
    {
        { 14, 152, true },
        { 24, 1060, false },
        { 29, 280, true },
        { 32, 992, false },
        { 34, 232, true },
    },
    // points_10
    {
        { 2, 280, true },
        { 5, 1060, false },
        { 10, 152, true },
        { 18, 1248, false },
        { 19, 128, true },
        { 20, 1272, false },
        { 25, 0, true },
    },
    // points_11
    {
        { 19, 240, true },
        { 20, 1248, false },
        { 21, 216, true },
        { 24, 1176, false },
        { 25, 200, true },
    },
    // points_13
    {
        { 1, 216, true },
        { 4, 1248, false },
        { 5, 240, true },
        { 6, 1260, false },
        { 26, 736, true },
    },
    // points_14
    {
        { 5, 128, true },
        { 6, 1248, false },
        { 7, 152, true },
        { 15, 1060, false },
        { 20, 280, true },
        { 23, 992, false },
        { 25, 232, true },
    },
    // points_16
    {
        { 4, 340, false },
        { 10, 0, true },
    },
    // points_17
    {
        { 6, 145, true },
        { 10, 228, false },
    },
};
