#include "npc_schedule_gray.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

#include "npc_schedule_gray.hh"
#include "bachelorette.hh"
extern "C" u32 SelectGraySchedule(void const * context)
{
    u8 date[4];
    u8 const * raw;
    u8 season;
    u8 day;
    u8 weekday;
    u32 count;
    if ((i32)(((u8 const *)context)[0x21CA] << 27) < 0)
        return 0;
    raw = date;
    DecodeGameDayDate((GameDayDate *)date,
        (GameCalendar const *)((u8 const *)context + 16));
    season = raw[1];
    day = raw[2];
    weekday = raw[3];
    /* Offset form kept on purpose: +0x1E28 is GameStateSaveImage::npcs.mary
       (NpcCollection offset 0x154, confirmed by the member table in
       npc_collection.hh). The struct form changes register allocation and
       no longer matches; see PROGRESS round 181. Tracked as a pending fix. */
    count = ((Bachelorette const *)((u8 const *)context + 0x1E28))->GetRivalEventCount();
    if (count > 4)
    {
        if ((u8)IsNpcScheduleDateListed(season, day))
            return 9;
        if (weekday == 4)
        {
            if (*(u32 const *)((u8 const *)context + 8) == 0)
                return 6;
            else
                return 7;
        }
        return 5;
    }
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 8;
    if (count != 0)
    {
        if (weekday == 1)
            return 3;
        if (weekday == 4)
            return 4;
        return 2;
    }
    return 1;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" GrayScheduleData const gGrayScheduleData = {
    // descriptor
    {
        SelectGraySchedule,
        ARRAY_COUNT(gGrayScheduleData.table_choices),
        gGrayScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gGrayScheduleData.table_storage[0],
        &gGrayScheduleData.table_storage[1],
        &gGrayScheduleData.table_storage[2],
        &gGrayScheduleData.table_storage[3],
        &gGrayScheduleData.table_storage[4],
        &gGrayScheduleData.table_storage[5],
        &gGrayScheduleData.table_storage[6],
        &gGrayScheduleData.table_storage[7],
        &gGrayScheduleData.table_storage[8],
    },
    // table_storage
    {
        { ARRAY_COUNT(gGrayScheduleData.entries_0), gGrayScheduleData.entries_0 },
        { ARRAY_COUNT(gGrayScheduleData.entries_1), gGrayScheduleData.entries_1 },
        { ARRAY_COUNT(gGrayScheduleData.entries_2), gGrayScheduleData.entries_2 },
        { ARRAY_COUNT(gGrayScheduleData.entries_3), gGrayScheduleData.entries_3 },
        { ARRAY_COUNT(gGrayScheduleData.entries_4), gGrayScheduleData.entries_4 },
        { ARRAY_COUNT(gGrayScheduleData.entries_5), gGrayScheduleData.entries_5 },
        { ARRAY_COUNT(gGrayScheduleData.entries_6), gGrayScheduleData.entries_6 },
        { ARRAY_COUNT(gGrayScheduleData.entries_7), gGrayScheduleData.entries_7 },
        { ARRAY_COUNT(gGrayScheduleData.entries_8), gGrayScheduleData.entries_8 },
    },
    // entries_0
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
        { 0x0000003F, &gGrayScheduleData.payload_storage[1] },
        { 0x00000062, &gGrayScheduleData.payload_storage[2] },
        { 0x00000068, &gGrayScheduleData.payload_storage[12] },
        { 0x000000B4, &gGrayScheduleData.payload_storage[3] },
        { 0x000000C8, &gGrayScheduleData.payload_storage[4] },
        { 0x000000F7, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[7] },
        { 0x000001D2, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
        { 0x0000003F, &gGrayScheduleData.payload_storage[1] },
        { 0x00000062, &gGrayScheduleData.payload_storage[4] },
        { 0x00000091, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[9] },
        { 0x000001D1, &gGrayScheduleData.payload_storage[10] },
        { 0x00000258, &gGrayScheduleData.payload_storage[11] },
        { 0x00000285, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
        { 0x0000003F, &gGrayScheduleData.payload_storage[1] },
        { 0x00000062, &gGrayScheduleData.payload_storage[4] },
        { 0x00000091, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[7] },
        { 0x000001D2, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
        { 0x0000003F, &gGrayScheduleData.payload_storage[1] },
        { 0x00000062, &gGrayScheduleData.payload_storage[13] },
        { 0x0000006C, &gGrayScheduleData.payload_storage[14] },
        { 0x000000F1, &gGrayScheduleData.payload_storage[15] },
        { 0x000000FC, &gGrayScheduleData.payload_storage[16] },
        { 0x00000121, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[9] },
        { 0x000001D1, &gGrayScheduleData.payload_storage[10] },
        { 0x00000258, &gGrayScheduleData.payload_storage[11] },
        { 0x00000285, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[17] },
        { 0x0000003C, &gGrayScheduleData.payload_storage[19] },
        { 0x00000056, &gGrayScheduleData.payload_storage[20] },
        { 0x00000066, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[9] },
        { 0x000001D1, &gGrayScheduleData.payload_storage[10] },
        { 0x00000258, &gGrayScheduleData.payload_storage[21] },
        { 0x00000261, &gGrayScheduleData.payload_storage[17] },
        { 0x000003C0, &gGrayScheduleData.payload_storage[18] },
    },
    // entries_5
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[18] },
        { 0x0000003C, &gGrayScheduleData.payload_storage[17] },
        { 0x000001A7, &gGrayScheduleData.payload_storage[19] },
        { 0x000001C1, &gGrayScheduleData.payload_storage[13] },
        { 0x000001CB, &gGrayScheduleData.payload_storage[14] },
        { 0x0000025A, &gGrayScheduleData.payload_storage[15] },
        { 0x00000265, &gGrayScheduleData.payload_storage[8] },
        { 0x0000027F, &gGrayScheduleData.payload_storage[17] },
        { 0x000003C0, &gGrayScheduleData.payload_storage[18] },
    },
    // entries_6
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[18] },
        { 0x0000003C, &gGrayScheduleData.payload_storage[17] },
        { 0x000001A7, &gGrayScheduleData.payload_storage[19] },
        { 0x000001C1, &gGrayScheduleData.payload_storage[20] },
        { 0x000001D1, &gGrayScheduleData.payload_storage[5] },
        { 0x0000025B, &gGrayScheduleData.payload_storage[6] },
        { 0x0000026B, &gGrayScheduleData.payload_storage[8] },
        { 0x00000285, &gGrayScheduleData.payload_storage[17] },
        { 0x000003C0, &gGrayScheduleData.payload_storage[18] },
    },
    // entries_7
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_8
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[17] },
    },
    // payload_storage
    {
        { nullptr, 0, 208, 176, 23, 3, false },
        { gGrayScheduleData.points_1, ARRAY_COUNT(gGrayScheduleData.points_1), 632, 488, 5, 0, false },
        { gGrayScheduleData.points_2, ARRAY_COUNT(gGrayScheduleData.points_2), 220, 0, 6, 0, false },
        { gGrayScheduleData.points_3, ARRAY_COUNT(gGrayScheduleData.points_3), 148, 80, 6, 0, false },
        { gGrayScheduleData.points_4, ARRAY_COUNT(gGrayScheduleData.points_4), 1272, 0, 7, 0, false },
        { gGrayScheduleData.points_5, ARRAY_COUNT(gGrayScheduleData.points_5), 72, 144, 38, 0, true },
        { gGrayScheduleData.points_6, ARRAY_COUNT(gGrayScheduleData.points_6), 296, 116, 7, 0, false },
        { gGrayScheduleData.points_7, ARRAY_COUNT(gGrayScheduleData.points_7), 104, 704, 5, 0, false },
        { gGrayScheduleData.points_8, ARRAY_COUNT(gGrayScheduleData.points_8), 104, 704, 5, 0, false },
        { gGrayScheduleData.points_9, ARRAY_COUNT(gGrayScheduleData.points_9), 104, 704, 5, 0, false },
        { nullptr, 0, 58, 136, 24, 2, false },
        { gGrayScheduleData.points_11, ARRAY_COUNT(gGrayScheduleData.points_11), 276, 168, 5, 0, false },
        { nullptr, 0, 148, 80, 6, 1, false },
        { gGrayScheduleData.points_13, ARRAY_COUNT(gGrayScheduleData.points_13), 240, 480, 8, 0, false },
        { nullptr, 0, 232, 256, 8, 1, false },
        { gGrayScheduleData.points_15, ARRAY_COUNT(gGrayScheduleData.points_15), 232, 256, 8, 0, false },
        { gGrayScheduleData.points_16, ARRAY_COUNT(gGrayScheduleData.points_16), 812, 512, 7, 0, false },
        { nullptr, 0, 128, 80, 26, 0, false },
        { nullptr, 0, 120, 72, 27, 2, false },
        { gGrayScheduleData.points_19, ARRAY_COUNT(gGrayScheduleData.points_19), 200, 160, 5, 0, false },
        { gGrayScheduleData.points_20, ARRAY_COUNT(gGrayScheduleData.points_20), 104, 0, 7, 0, false },
        { gGrayScheduleData.points_21, ARRAY_COUNT(gGrayScheduleData.points_21), 276, 168, 5, 0, false },
    },
    // points_1
    {
        { 2, 536, true },
        { 27, 1260, false },
        { 35, 736, true },
    },
    // points_2
    {
        { 3, 80, true },
        { 6, 148, false },
    },
    // points_3
    {
        { 3, 224, false },
        { 20, 480, true },
    },
    // points_4
    {
        { 5, 128, true },
        { 6, 1248, false },
        { 7, 152, true },
        { 45, 296, false },
        { 47, 116, true },
    },
    // points_5
    {
        { 24, 2, 0, 0, false },
        { 80, 2, 120, 3, true },
        { 144, 2, 0, 0, true },
        { 72, 2, 120, 1, false },
    },
    // points_6
    {
        { 2, 152, true },
        { 10, 104, false },
        { 16, 0, true },
    },
    // points_7
    {
        { 7, 536, true },
        { 28, 632, false },
        { 30, 488, true },
    },
    // points_8
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 24, 200, false },
        { 26, 160, true },
    },
    // points_9
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 27, 276, false },
        { 29, 168, true },
    },
    // points_11
    {
        { 2, 216, true },
        { 23, 808, false },
        { 36, 536, true },
        { 43, 632, false },
        { 45, 488, true },
    },
    // points_13
    {
        { 9, 256, true },
        { 10, 232, false },
    },
    // points_15
    {
        { 1, 240, false },
        { 11, 512, true },
    },
    // points_16
    {
        { 14, 152, true },
        { 35, 296, false },
        { 37, 116, true },
    },
    // points_19
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 6, 104, false },
        { 26, 736, true },
    },
    // points_20
    {
        { 6, 152, true },
        { 14, 296, false },
        { 16, 116, true },
    },
    // points_21
    {
        { 2, 216, true },
        { 7, 200, false },
        { 9, 160, true },
    },
};
