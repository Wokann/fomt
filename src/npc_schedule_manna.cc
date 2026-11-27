#include "npc_schedule_manna.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

#include "npc_schedule_manna.hh"
#include "game_state.hh"
extern "C" u32 SelectMannaSchedule(void const * context)
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
    if ((i32)(((u8 const *)context)[0x21CA] << 25) < 0)
        return 0;
    if (*(u32 const *)((u8 const *)context + 8) == 0)
    {
        if (weekday == 6)
        {
            /* +0x2174 is GameStateSaveImage::event_state (offset 0x214C)
               + 0x28, a 32-bit cell in the GameEventState bitfield region;
               mask selects bits 12-18. Exact named bitfield not resolved
               yet (H3 exception). */
            if ((*(u32 const *)((u8 const *)context + 0x2174) & (0xC2u << 11))
                == (0x82u << 11))
                return 4;
            return 3;
        }
        return 1;
    }
    return 2;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" MannaScheduleData const gMannaScheduleData = {
    // descriptor
    {
        SelectMannaSchedule,
        ARRAY_COUNT(gMannaScheduleData.table_choices),
        gMannaScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gMannaScheduleData.table_storage[0],
        &gMannaScheduleData.table_storage[1],
        &gMannaScheduleData.table_storage[2],
        &gMannaScheduleData.table_storage[3],
        &gMannaScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gMannaScheduleData.entries_0), gMannaScheduleData.entries_0 },
        { ARRAY_COUNT(gMannaScheduleData.entries_1), gMannaScheduleData.entries_1 },
        { ARRAY_COUNT(gMannaScheduleData.entries_2), gMannaScheduleData.entries_2 },
        { ARRAY_COUNT(gMannaScheduleData.entries_3), gMannaScheduleData.entries_3 },
        { ARRAY_COUNT(gMannaScheduleData.entries_4), gMannaScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gMannaScheduleData.payload_storage[0] },
        { 0x0000003C, &gMannaScheduleData.payload_storage[1] },
        { 0x000001A4, &gMannaScheduleData.payload_storage[2] },
        { 0x000001D7, &gMannaScheduleData.payload_storage[3] },
        { 0x000001E0, &gMannaScheduleData.payload_storage[4] },
        { 0x00000258, &gMannaScheduleData.payload_storage[5] },
        { 0x00000261, &gMannaScheduleData.payload_storage[6] },
        { 0x00000293, &gMannaScheduleData.payload_storage[18] },
        { 0x000003C0, &gMannaScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gMannaScheduleData.payload_storage[0] },
        { 0x0000003C, &gMannaScheduleData.payload_storage[1] },
        { 0x000001A7, &gMannaScheduleData.payload_storage[7] },
        { 0x000001D4, &gMannaScheduleData.payload_storage[8] },
        { 0x0000025B, &gMannaScheduleData.payload_storage[9] },
        { 0x00000289, &gMannaScheduleData.payload_storage[18] },
        { 0x000003C0, &gMannaScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gMannaScheduleData.payload_storage[0] },
        { 0x0000003C, &gMannaScheduleData.payload_storage[18] },
        { 0x000000F0, &gMannaScheduleData.payload_storage[10] },
        { 0x0000010A, &gMannaScheduleData.payload_storage[11] },
        { 0x000001A7, &gMannaScheduleData.payload_storage[12] },
        { 0x000001E8, &gMannaScheduleData.payload_storage[3] },
        { 0x000001F1, &gMannaScheduleData.payload_storage[4] },
        { 0x00000258, &gMannaScheduleData.payload_storage[5] },
        { 0x00000261, &gMannaScheduleData.payload_storage[6] },
        { 0x00000293, &gMannaScheduleData.payload_storage[18] },
        { 0x000003C0, &gMannaScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gMannaScheduleData.payload_storage[0] },
        { 0x0000003C, &gMannaScheduleData.payload_storage[18] },
        { 0x000000F0, &gMannaScheduleData.payload_storage[10] },
        { 0x0000010A, &gMannaScheduleData.payload_storage[11] },
        { 0x000001A7, &gMannaScheduleData.payload_storage[13] },
        { 0x000001D1, &gMannaScheduleData.payload_storage[14] },
        { 0x00000266, &gMannaScheduleData.payload_storage[15] },
        { 0x00000292, &gMannaScheduleData.payload_storage[16] },
        { 0x0000030F, &gMannaScheduleData.payload_storage[17] },
        { 0x0000034B, &gMannaScheduleData.payload_storage[18] },
        { 0x000003C0, &gMannaScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gMannaScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gMannaScheduleData.points_0, ARRAY_COUNT(gMannaScheduleData.points_0), 32, 80, 32, 0, true },
        { nullptr, 0, 59, 91, 31, 0, false },
        { gMannaScheduleData.points_2, ARRAY_COUNT(gMannaScheduleData.points_2), 232, 484, 5, 0, false },
        { gMannaScheduleData.points_3, ARRAY_COUNT(gMannaScheduleData.points_3), 220, 0, 6, 0, false },
        { nullptr, 0, 328, 125, 6, 1, false },
        { gMannaScheduleData.points_5, ARRAY_COUNT(gMannaScheduleData.points_5), 328, 125, 6, 0, false },
        { gMannaScheduleData.points_6, ARRAY_COUNT(gMannaScheduleData.points_6), 1260, 704, 5, 0, false },
        { gMannaScheduleData.points_7, ARRAY_COUNT(gMannaScheduleData.points_7), 232, 484, 5, 0, false },
        { nullptr, 0, 232, 264, 15, 2, false },
        { gMannaScheduleData.points_9, ARRAY_COUNT(gMannaScheduleData.points_9), 688, 160, 5, 0, false },
        { gMannaScheduleData.points_10, ARRAY_COUNT(gMannaScheduleData.points_10), 232, 484, 5, 0, false },
        { nullptr, 0, 144, 168, 26, 2, false },
        { gMannaScheduleData.points_12, ARRAY_COUNT(gMannaScheduleData.points_12), 200, 160, 5, 0, false },
        { gMannaScheduleData.points_13, ARRAY_COUNT(gMannaScheduleData.points_13), 200, 160, 5, 0, false },
        { nullptr, 0, 79, 147, 21, 2, false },
        { gMannaScheduleData.points_15, ARRAY_COUNT(gMannaScheduleData.points_15), 632, 488, 5, 0, false },
        { nullptr, 0, 72, 195, 12, 1, false },
        { gMannaScheduleData.points_17, ARRAY_COUNT(gMannaScheduleData.points_17), 1232, 160, 5, 0, false },
        { gMannaScheduleData.points_18, ARRAY_COUNT(gMannaScheduleData.points_18), 96, 80, 31, 0, true },
    },
    // points_0
    {
        { 80, 2, 120, 3, false },
        { 32, 2, 120, 2, false },
    },
    // points_2
    {
        { 2, 536, true },
        { 43, 1260, false },
        { 51, 736, true },
    },
    // points_3
    {
        { 5, 125, true },
        { 9, 328, false },
    },
    // points_5
    {
        { 4, 220, false },
        { 9, 0, true },
    },
    // points_6
    {
        { 7, 536, true },
        { 48, 232, false },
        { 50, 480, true },
    },
    // points_7
    {
        { 2, 536, true },
        { 25, 808, false },
        { 38, 216, true },
        { 43, 688, false },
        { 45, 160, true },
    },
    // points_9
    {
        { 2, 216, true },
        { 24, 144, false },
        { 25, 240, true },
        { 27, 104, false },
        { 39, 536, true },
        { 44, 232, false },
        { 46, 484, true },
    },
    // points_10
    {
        { 2, 536, true },
        { 7, 104, false },
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 24, 200, false },
        { 26, 160, true },
    },
    // points_12
    {
        { 2, 216, true },
        { 43, 1248, false },
        { 44, 240, true },
        { 45, 1260, false },
        { 65, 736, true },
    },
    // points_13
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 7, 104, false },
        { 19, 536, true },
        { 40, 632, false },
        { 42, 488, true },
    },
    // points_15
    {
        { 2, 536, true },
        { 27, 1260, false },
        { 39, 240, true },
        { 40, 1248, false },
        { 41, 216, true },
        { 42, 1232, false },
        { 44, 156, true },
    },
    // points_17
    {
        { 2, 216, true },
        { 3, 1248, false },
        { 4, 240, true },
        { 5, 1260, false },
        { 17, 536, true },
        { 58, 232, false },
        { 60, 484, true },
    },
    // points_18
    {
        { 32, 2, 120, 2, false },
        { 96, 2, 120, 1, false },
    },
};
