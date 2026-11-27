#include "npc_schedule_anna.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectAnnaSchedule(void const * context)
{
    u8 date[4];
    u8 const * raw;
    u8 flags;
    u8 season;
    u8 day;
    u8 weekday;
    flags = ((u8 const *)context)[0x21CA];
    if ((i32)(flags << 27) < 0)
        return 0;
    raw = date;
    DecodeGameDayDate((GameDayDate *)date,
        (GameCalendar const *)((u8 const *)context + 16));
    season = raw[1];
    day = raw[2];
    weekday = raw[3];
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 5;
    if (weekday == 1)
    {
        if (*(u32 const *)((u8 const *)context + 8) == 0)
            return 3;
        else
            return 4;
    }
    if (*(u32 const *)((u8 const *)context + 8) == 0)
        return 1;
    return 2;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" AnnaScheduleData const gAnnaScheduleData = {
    // descriptor
    {
        SelectAnnaSchedule,
        ARRAY_COUNT(gAnnaScheduleData.table_choices),
        gAnnaScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gAnnaScheduleData.table_storage[0],
        &gAnnaScheduleData.table_storage[1],
        &gAnnaScheduleData.table_storage[2],
        &gAnnaScheduleData.table_storage[3],
        &gAnnaScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gAnnaScheduleData.entries_0), gAnnaScheduleData.entries_0 },
        { ARRAY_COUNT(gAnnaScheduleData.entries_1), gAnnaScheduleData.entries_1 },
        { ARRAY_COUNT(gAnnaScheduleData.entries_2), gAnnaScheduleData.entries_2 },
        { ARRAY_COUNT(gAnnaScheduleData.entries_3), gAnnaScheduleData.entries_3 },
        { ARRAY_COUNT(gAnnaScheduleData.entries_4), gAnnaScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
        { 0x0000003C, &gAnnaScheduleData.payload_storage[1] },
        { 0x000001A4, &gAnnaScheduleData.payload_storage[2] },
        { 0x000001E5, &gAnnaScheduleData.payload_storage[3] },
        { 0x000001EF, &gAnnaScheduleData.payload_storage[4] },
        { 0x0000025A, &gAnnaScheduleData.payload_storage[5] },
        { 0x00000264, &gAnnaScheduleData.payload_storage[6] },
        { 0x000002A4, &gAnnaScheduleData.payload_storage[1] },
        { 0x000003C0, &gAnnaScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
        { 0x0000003C, &gAnnaScheduleData.payload_storage[1] },
        { 0x000003C0, &gAnnaScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
        { 0x00000042, &gAnnaScheduleData.payload_storage[7] },
        { 0x0000005D, &gAnnaScheduleData.payload_storage[8] },
        { 0x00000098, &gAnnaScheduleData.payload_storage[9] },
        { 0x000000F3, &gAnnaScheduleData.payload_storage[10] },
        { 0x0000012E, &gAnnaScheduleData.payload_storage[11] },
        { 0x00000148, &gAnnaScheduleData.payload_storage[1] },
        { 0x000001AA, &gAnnaScheduleData.payload_storage[12] },
        { 0x000001C2, &gAnnaScheduleData.payload_storage[13] },
        { 0x00000258, &gAnnaScheduleData.payload_storage[14] },
        { 0x00000270, &gAnnaScheduleData.payload_storage[1] },
        { 0x000003C0, &gAnnaScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
        { 0x0000003C, &gAnnaScheduleData.payload_storage[1] },
        { 0x000001A7, &gAnnaScheduleData.payload_storage[12] },
        { 0x000001BF, &gAnnaScheduleData.payload_storage[13] },
        { 0x00000258, &gAnnaScheduleData.payload_storage[14] },
        { 0x00000270, &gAnnaScheduleData.payload_storage[1] },
        { 0x000003C0, &gAnnaScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 50, 88, 27, 0, false },
        { nullptr, 0, 24, 88, 26, 0, false },
        { gAnnaScheduleData.points_2, ARRAY_COUNT(gAnnaScheduleData.points_2), 200, 160, 5, 0, false },
        { gAnnaScheduleData.points_3, ARRAY_COUNT(gAnnaScheduleData.points_3), 220, 0, 6, 0, false },
        { nullptr, 0, 360, 96, 6, 2, false },
        { gAnnaScheduleData.points_5, ARRAY_COUNT(gAnnaScheduleData.points_5), 360, 96, 6, 0, false },
        { gAnnaScheduleData.points_6, ARRAY_COUNT(gAnnaScheduleData.points_6), 1260, 704, 5, 0, false },
        { gAnnaScheduleData.points_7, ARRAY_COUNT(gAnnaScheduleData.points_7), 200, 160, 5, 0, false },
        { gAnnaScheduleData.points_8, ARRAY_COUNT(gAnnaScheduleData.points_8), 1200, 752, 0, 0, false },
        { nullptr, 0, 296, 200, 0, 3, false },
        { gAnnaScheduleData.points_10, ARRAY_COUNT(gAnnaScheduleData.points_10), 296, 200, 0, 0, false },
        { gAnnaScheduleData.points_11, ARRAY_COUNT(gAnnaScheduleData.points_11), 104, 704, 5, 0, false },
        { gAnnaScheduleData.points_12, ARRAY_COUNT(gAnnaScheduleData.points_12), 200, 160, 5, 0, false },
        { nullptr, 0, 152, 138, 15, 0, false },
        { gAnnaScheduleData.points_14, ARRAY_COUNT(gAnnaScheduleData.points_14), 688, 160, 5, 0, false },
    },
    // points_2
    {
        { 2, 216, true },
        { 26, 808, false },
        { 39, 536, true },
        { 57, 1260, false },
        { 65, 736, true },
    },
    // points_3
    {
        { 4, 96, true },
        { 10, 360, false },
    },
    // points_5
    {
        { 6, 220, false },
        { 10, 0, true },
    },
    // points_6
    {
        { 7, 536, true },
        { 25, 808, false },
        { 38, 216, true },
        { 62, 200, false },
        { 64, 160, true },
    },
    // points_7
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 7, 104, false },
        { 27, 734, true },
    },
    // points_8
    {
        { 12, 912, false },
        { 13, 728, true },
        { 15, 856, false },
        { 16, 704, true },
        { 17, 832, false },
        { 18, 680, true },
        { 19, 808, false },
        { 20, 656, true },
        { 21, 776, false },
        { 22, 624, true },
        { 23, 752, false },
        { 24, 592, true },
        { 25, 720, false },
        { 26, 568, true },
        { 27, 692, false },
        { 37, 328, true },
        { 38, 656, false },
        { 44, 168, true },
        { 58, 296, false },
        { 59, 200, true },
    },
    // points_10
    {
        { 1, 168, true },
        { 15, 656, false },
        { 21, 328, true },
        { 22, 692, false },
        { 32, 568, true },
        { 33, 720, false },
        { 34, 592, true },
        { 35, 752, false },
        { 36, 624, true },
        { 37, 776, false },
        { 38, 656, true },
        { 39, 808, false },
        { 40, 680, true },
        { 41, 832, false },
        { 42, 704, true },
        { 43, 856, false },
        { 44, 728, true },
        { 46, 912, false },
        { 47, 752, true },
        { 59, 1216, false },
    },
    // points_11
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 24, 200, false },
        { 26, 160, true },
    },
    // points_12
    {
        { 2, 216, true },
        { 22, 688, false },
        { 24, 160, true },
    },
    // points_14
    {
        { 2, 216, true },
        { 22, 200, false },
        { 24, 160, true },
    },
};
