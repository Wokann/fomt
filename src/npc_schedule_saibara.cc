#include "npc_schedule_saibara.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

#include "saibara.hh"
#include "game_state_types.hh"
extern "C" u32 SelectSaibaraSchedule(void const * context)
{
    GameStateSaveImage const * save = (GameStateSaveImage const *)context;
    u8 date[4];
    u8 const * raw;
    u8 season;
    u8 day;
    u8 weekday;
    Saibara const * saibara;
    if ((i32)(((u8 const *)context)[0x21CA] << 27) < 0)
        return 0;
    raw = date;
    DecodeGameDayDate((GameDayDate *)date, &save->clock.calendar);
    season = raw[1];
    day = raw[2];
    weekday = raw[3];
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 4;
    saibara = &save->npcs.saibara;
    if (saibara->GetOrder() != 0 && !saibara->IsOrderComplete())
        return 5;
    if (weekday == 4)
    {
        if (*(u32 const *)&save->clock == 0)
            return 2;
        else
            return 3;
    }
    return 1;
}

asm_unified(
    "    .align 2, 0\n"
);

extern "C" SaibaraScheduleData const gSaibaraScheduleData = {
    // descriptor
    {
        SelectSaibaraSchedule,
        ARRAY_COUNT(gSaibaraScheduleData.table_choices),
        gSaibaraScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gSaibaraScheduleData.table_storage[0],
        &gSaibaraScheduleData.table_storage[1],
        &gSaibaraScheduleData.table_storage[2],
        &gSaibaraScheduleData.table_storage[3],
        &gSaibaraScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gSaibaraScheduleData.entries_0), gSaibaraScheduleData.entries_0 },
        { ARRAY_COUNT(gSaibaraScheduleData.entries_1), gSaibaraScheduleData.entries_1 },
        { ARRAY_COUNT(gSaibaraScheduleData.entries_2), gSaibaraScheduleData.entries_2 },
        { ARRAY_COUNT(gSaibaraScheduleData.entries_3), gSaibaraScheduleData.entries_3 },
        { ARRAY_COUNT(gSaibaraScheduleData.entries_4), gSaibaraScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[0] },
        { 0x00000078, &gSaibaraScheduleData.payload_storage[1] },
        { 0x0000030F, &gSaibaraScheduleData.payload_storage[2] },
        { 0x0000031F, &gSaibaraScheduleData.payload_storage[6] },
        { 0x0000033E, &gSaibaraScheduleData.payload_storage[7] },
        { 0x000003C0, &gSaibaraScheduleData.payload_storage[8] },
        { 0x000003DF, &gSaibaraScheduleData.payload_storage[9] },
        { 0x000003EF, &gSaibaraScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[0] },
        { 0x0000003F, &gSaibaraScheduleData.payload_storage[10] },
        { 0x00000065, &gSaibaraScheduleData.payload_storage[11] },
        { 0x0000006E, &gSaibaraScheduleData.payload_storage[12] },
        { 0x000000F0, &gSaibaraScheduleData.payload_storage[13] },
        { 0x000000FA, &gSaibaraScheduleData.payload_storage[14] },
        { 0x0000011F, &gSaibaraScheduleData.payload_storage[1] },
        { 0x000001A7, &gSaibaraScheduleData.payload_storage[2] },
        { 0x000001B7, &gSaibaraScheduleData.payload_storage[3] },
        { 0x000001E5, &gSaibaraScheduleData.payload_storage[4] },
        { 0x00000258, &gSaibaraScheduleData.payload_storage[5] },
        { 0x00000287, &gSaibaraScheduleData.payload_storage[9] },
        { 0x00000297, &gSaibaraScheduleData.payload_storage[1] },
        { 0x0000030C, &gSaibaraScheduleData.payload_storage[2] },
        { 0x0000031C, &gSaibaraScheduleData.payload_storage[6] },
        { 0x0000033B, &gSaibaraScheduleData.payload_storage[1] },
        { 0x000003C0, &gSaibaraScheduleData.payload_storage[8] },
        { 0x000003DF, &gSaibaraScheduleData.payload_storage[9] },
        { 0x000003EF, &gSaibaraScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[0] },
        { 0x00000078, &gSaibaraScheduleData.payload_storage[1] },
        { 0x0000030C, &gSaibaraScheduleData.payload_storage[2] },
        { 0x0000031C, &gSaibaraScheduleData.payload_storage[6] },
        { 0x0000033B, &gSaibaraScheduleData.payload_storage[7] },
        { 0x000003C0, &gSaibaraScheduleData.payload_storage[8] },
        { 0x000003DF, &gSaibaraScheduleData.payload_storage[9] },
        { 0x000003EF, &gSaibaraScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[1] },
    },
    // payload_storage
    {
        { gSaibaraScheduleData.points_0, ARRAY_COUNT(gSaibaraScheduleData.points_0), 152, 80, 38, 0, true },
        { nullptr, 0, 118, 115, 38, 0, false },
        { gSaibaraScheduleData.points_2, ARRAY_COUNT(gSaibaraScheduleData.points_2), 296, 116, 7, 0, false },
        { gSaibaraScheduleData.points_3, ARRAY_COUNT(gSaibaraScheduleData.points_3), 104, 704, 5, 0, false },
        { nullptr, 0, 152, 136, 15, 0, false },
        { gSaibaraScheduleData.points_5, ARRAY_COUNT(gSaibaraScheduleData.points_5), 688, 160, 5, 0, false },
        { gSaibaraScheduleData.points_6, ARRAY_COUNT(gSaibaraScheduleData.points_6), 104, 704, 5, 0, false },
        { nullptr, 0, 287, 235, 21, 2, false },
        { gSaibaraScheduleData.points_8, ARRAY_COUNT(gSaibaraScheduleData.points_8), 632, 488, 5, 0, false },
        { gSaibaraScheduleData.points_9, ARRAY_COUNT(gSaibaraScheduleData.points_9), 104, 0, 7, 0, false },
        { gSaibaraScheduleData.points_10, ARRAY_COUNT(gSaibaraScheduleData.points_10), 296, 116, 7, 0, false },
        { gSaibaraScheduleData.points_11, ARRAY_COUNT(gSaibaraScheduleData.points_11), 240, 480, 8, 0, false },
        { nullptr, 0, 256, 272, 8, 1, false },
        { gSaibaraScheduleData.points_13, ARRAY_COUNT(gSaibaraScheduleData.points_13), 256, 272, 8, 0, false },
        { gSaibaraScheduleData.points_14, ARRAY_COUNT(gSaibaraScheduleData.points_14), 812, 512, 7, 0, false },
    },
    // points_0
    {
        { 192, 2, 120, 3, false },
        { 152, 2, 120, 2, false },
    },
    // points_2
    {
        { 2, 152, true },
        { 10, 104, false },
        { 16, 0, true },
    },
    // points_3
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 44, 688, false },
        { 46, 160, true },
    },
    // points_5
    {
        { 2, 216, true },
        { 24, 144, false },
        { 25, 240, true },
        { 27, 104, false },
        { 47, 736, true },
    },
    // points_6
    {
        { 7, 536, true },
        { 28, 632, false },
        { 31, 488, true },
    },
    // points_8
    {
        { 2, 536, true },
        { 23, 104, false },
        { 31, 736, true },
    },
    // points_9
    {
        { 6, 152, true },
        { 14, 296, false },
        { 16, 116, true },
    },
    // points_10
    {
        { 2, 152, true },
        { 23, 812, false },
        { 38, 544, true },
    },
    // points_11
    {
        { 8, 272, true },
        { 9, 256, false },
    },
    // points_13
    {
        { 1, 240, false },
        { 10, 512, true },
    },
    // points_14
    {
        { 14, 152, true },
        { 35, 296, false },
        { 37, 116, true },
    },
};
