#include "npc_schedule_gotz.hh"
#include "game_state.hh"

extern "C" u32 SelectGotzSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    GameDayDate date;
    DecodeGameDayDate(&date, &save.clock.calendar);
    u8 season = date.season;
    u8 day = date.day;
    u8 weekday = date.weekday;
    if (static_cast<u8>(IsNpcScheduleDateListed(season, day)))
        return 5;

    u32 weather = save.clock.weather_today;
    Gotz const & carpenter = save.npcs.gotz;
    if (carpenter.GetConstruction() != 0 && !carpenter.IsConstructionComplete()
        && !carpenter.IsConstructionOrderedToday()
        && (weather < WEATHER_TYPHOON || weather > WEATHER_SNOWSTORM)) {
        switch (carpenter.GetConstruction()) {
        case 0: break;
        case 1:
            switch (save.farm.farm_house.GetUpgradeLevel()) {
            case FARMHOUSE_UPGRADE_ORIGINAL: return 6;
            case FARMHOUSE_UPGRADE_FIRST_EXTENSION: return 7;
            case FARMHOUSE_UPGRADE_SECOND_EXTENSION: return 13;
            }
            break;
        case 2: return 8;
        case 3: return 9;
        case 4: return 14;
        case 5:
        case 6:
        case 7: return 10;
        case 8:
        case 9:
        case 10: return 11;
        case 11:
        case 12:
        case 13: return 12;
        }
    }
    switch (weekday) {
    default: return 1;
    case DAY_OF_WEEK_THURSDAY:
    case DAY_OF_WEEK_FRIDAY: return 2;
    case DAY_OF_WEEK_SATURDAY: return 3;
    case DAY_OF_WEEK_SUNDAY: return 4;
    }
}

extern "C" GotzScheduleData const gGotzScheduleData = {
    // descriptor
    {
        SelectGotzSchedule,
        ARRAY_COUNT(gGotzScheduleData.table_choices),
        gGotzScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gGotzScheduleData.table_storage[0],
        &gGotzScheduleData.table_storage[1],
        &gGotzScheduleData.table_storage[2],
        &gGotzScheduleData.table_storage[3],
        &gGotzScheduleData.table_storage[4],
        &gGotzScheduleData.table_storage[5],
        &gGotzScheduleData.table_storage[6],
        &gGotzScheduleData.table_storage[7],
        &gGotzScheduleData.table_storage[8],
        &gGotzScheduleData.table_storage[9],
        &gGotzScheduleData.table_storage[10],
        &gGotzScheduleData.table_storage[11],
        &gGotzScheduleData.table_storage[12],
        &gGotzScheduleData.table_storage[13],
    },
    // table_storage
    {
        { ARRAY_COUNT(gGotzScheduleData.entries_0), gGotzScheduleData.entries_0 },
        { ARRAY_COUNT(gGotzScheduleData.entries_1), gGotzScheduleData.entries_1 },
        { ARRAY_COUNT(gGotzScheduleData.entries_2), gGotzScheduleData.entries_2 },
        { ARRAY_COUNT(gGotzScheduleData.entries_3), gGotzScheduleData.entries_3 },
        { ARRAY_COUNT(gGotzScheduleData.entries_4), gGotzScheduleData.entries_4 },
        { ARRAY_COUNT(gGotzScheduleData.entries_5), gGotzScheduleData.entries_5 },
        { ARRAY_COUNT(gGotzScheduleData.entries_6), gGotzScheduleData.entries_6 },
        { ARRAY_COUNT(gGotzScheduleData.entries_7), gGotzScheduleData.entries_7 },
        { ARRAY_COUNT(gGotzScheduleData.entries_8), gGotzScheduleData.entries_8 },
        { ARRAY_COUNT(gGotzScheduleData.entries_9), gGotzScheduleData.entries_9 },
        { ARRAY_COUNT(gGotzScheduleData.entries_10), gGotzScheduleData.entries_10 },
        { ARRAY_COUNT(gGotzScheduleData.entries_11), gGotzScheduleData.entries_11 },
        { ARRAY_COUNT(gGotzScheduleData.entries_12), gGotzScheduleData.entries_12 },
        { ARRAY_COUNT(gGotzScheduleData.entries_13), gGotzScheduleData.entries_13 },
    },
    // entries_0
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
        { 0x0000003C, &gGotzScheduleData.payload_storage[1] },
        { 0x0000005E, &gGotzScheduleData.payload_storage[2] },
        { 0x00000087, &gGotzScheduleData.payload_storage[3] },
        { 0x000000F0, &gGotzScheduleData.payload_storage[4] },
        { 0x0000011A, &gGotzScheduleData.payload_storage[5] },
        { 0x0000013B, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
        { 0x0000003C, &gGotzScheduleData.payload_storage[1] },
        { 0x0000005E, &gGotzScheduleData.payload_storage[2] },
        { 0x00000087, &gGotzScheduleData.payload_storage[3] },
        { 0x000000F0, &gGotzScheduleData.payload_storage[4] },
        { 0x0000011A, &gGotzScheduleData.payload_storage[5] },
        { 0x0000013B, &gGotzScheduleData.payload_storage[0] },
        { 0x000001AA, &gGotzScheduleData.payload_storage[6] },
        { 0x000001B5, &gGotzScheduleData.payload_storage[7] },
        { 0x00000258, &gGotzScheduleData.payload_storage[8] },
        { 0x00000263, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
        { 0x0000003C, &gGotzScheduleData.payload_storage[1] },
        { 0x0000005E, &gGotzScheduleData.payload_storage[2] },
        { 0x00000087, &gGotzScheduleData.payload_storage[3] },
        { 0x000000F0, &gGotzScheduleData.payload_storage[4] },
        { 0x0000011A, &gGotzScheduleData.payload_storage[9] },
        { 0x0000013F, &gGotzScheduleData.payload_storage[10] },
        { 0x000001A4, &gGotzScheduleData.payload_storage[11] },
        { 0x000001B0, &gGotzScheduleData.payload_storage[12] },
        { 0x0000025E, &gGotzScheduleData.payload_storage[13] },
        { 0x0000028C, &gGotzScheduleData.payload_storage[14] },
        { 0x000002A3, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
        { 0x000001A4, &gGotzScheduleData.payload_storage[1] },
        { 0x000001C6, &gGotzScheduleData.payload_storage[15] },
        { 0x000001CD, &gGotzScheduleData.payload_storage[16] },
        { 0x00000258, &gGotzScheduleData.payload_storage[17] },
        { 0x00000260, &gGotzScheduleData.payload_storage[5] },
        { 0x00000281, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_5
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[18] },
    },
    // entries_6
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[19] },
    },
    // entries_7
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[21] },
    },
    // entries_8
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[22] },
    },
    // entries_9
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[20] },
    },
    // entries_10
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[20] },
    },
    // entries_11
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[20] },
    },
    // entries_12
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[20] },
    },
    // entries_13
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[23] },
    },
    // payload_storage
    {
        { nullptr, 0, 200, 91, 40, 0, false },
        { gGotzScheduleData.points_1, ARRAY_COUNT(gGotzScheduleData.points_1), 614, 244, 3, 0, false },
        { gGotzScheduleData.points_2, ARRAY_COUNT(gGotzScheduleData.points_2), 1200, 752, 0, 0, false },
        { gGotzScheduleData.points_3, ARRAY_COUNT(gGotzScheduleData.points_3), 384, 608, 0, 0, true },
        { gGotzScheduleData.points_4, ARRAY_COUNT(gGotzScheduleData.points_4), 384, 608, 0, 0, false },
        { gGotzScheduleData.points_5, ARRAY_COUNT(gGotzScheduleData.points_5), 0, 448, 3, 0, false },
        { gGotzScheduleData.points_6, ARRAY_COUNT(gGotzScheduleData.points_6), 614, 244, 3, 0, false },
        { gGotzScheduleData.points_7, ARRAY_COUNT(gGotzScheduleData.points_7), 512, 170, 3, 0, true },
        { gGotzScheduleData.points_8, ARRAY_COUNT(gGotzScheduleData.points_8), 512, 170, 3, 0, false },
        { gGotzScheduleData.points_9, ARRAY_COUNT(gGotzScheduleData.points_9), 104, 704, 5, 0, false },
        { gGotzScheduleData.points_10, ARRAY_COUNT(gGotzScheduleData.points_10), 80, 88, 30, 0, true },
        { gGotzScheduleData.points_11, ARRAY_COUNT(gGotzScheduleData.points_11), 480, 160, 5, 0, false },
        { nullptr, 0, 56, 136, 15, 3, false },
        { gGotzScheduleData.points_13, ARRAY_COUNT(gGotzScheduleData.points_13), 688, 160, 5, 0, false },
        { gGotzScheduleData.points_14, ARRAY_COUNT(gGotzScheduleData.points_14), 832, 0, 3, 0, false },
        { gGotzScheduleData.points_15, ARRAY_COUNT(gGotzScheduleData.points_15), 240, 480, 8, 0, false },
        { nullptr, 0, 352, 400, 8, 3, false },
        { gGotzScheduleData.points_17, ARRAY_COUNT(gGotzScheduleData.points_17), 352, 400, 8, 0, false },
        { gGotzScheduleData.points_18, ARRAY_COUNT(gGotzScheduleData.points_18), 32, 83, 29, 0, true },
        { gGotzScheduleData.points_19, ARRAY_COUNT(gGotzScheduleData.points_19), 32, 124, 29, 0, true },
        { gGotzScheduleData.points_20, ARRAY_COUNT(gGotzScheduleData.points_20), 32, 98, 29, 0, true },
        { gGotzScheduleData.points_21, ARRAY_COUNT(gGotzScheduleData.points_21), 208, 160, 17, 0, true },
        { gGotzScheduleData.points_22, ARRAY_COUNT(gGotzScheduleData.points_22), 328, 196, 37, 0, true },
        { gGotzScheduleData.points_23, ARRAY_COUNT(gGotzScheduleData.points_23), 539, 95, 7, 0, true },
    },
    // points_1
    {
        { 2, 296, true },
        { 20, 168, false },
        { 22, 344, true },
        { 24, 120, false },
        { 26, 392, true },
        { 29, 60, false },
        { 31, 448, true },
        { 34, -16, false },
    },
    // points_2
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
        { 39, 384, false },
        { 41, 608, true },
    },
    // points_3
    {
        { 320, 2, 120, 0, false },
        { 384, 2, 120, 0, false },
    },
    // points_4
    {
        { 2, 568, true },
        { 15, 720, false },
        { 16, 592, true },
        { 17, 752, false },
        { 18, 624, true },
        { 19, 775, false },
        { 20, 656, true },
        { 21, 808, false },
        { 22, 680, true },
        { 23, 832, false },
        { 24, 704, true },
        { 25, 856, false },
        { 26, 728, true },
        { 28, 912, false },
        { 29, 752, true },
        { 42, 1216, false },
    },
    // points_5
    {
        { 2, 56, false },
        { 4, 392, true },
        { 7, 120, false },
        { 9, 344, true },
        { 11, 168, false },
        { 13, 296, true },
        { 31, 614, false },
        { 33, 244, true },
    },
    // points_6
    {
        { 2, 296, true },
        { 6, 512, false },
        { 11, 170, true },
    },
    // points_7
    {
        { 432, 2, 120, 1, false },
        { 512, 2, 120, 1, false },
    },
    // points_8
    {
        { 5, 296, true },
        { 9, 614, false },
        { 11, 244, true },
    },
    // points_9
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 35, 480, false },
        { 37, 160, true },
    },
    // points_10
    {
        { 24, 2, 120, 2, false },
        { 80, 2, 120, 3, false },
    },
    // points_11
    {
        { 2, 216, true },
        { 10, 688, false },
        { 12, 160, true },
    },
    // points_13
    {
        { 2, 216, true },
        { 7, 808, false },
        { 20, 536, true },
        { 38, 1260, false },
        { 46, 736, true },
    },
    // points_14
    {
        { 12, 296, true },
        { 21, 614, false },
        { 23, 244, true },
    },
    // points_15
    {
        { 3, 400, true },
        { 7, 352, false },
    },
    // points_17
    {
        { 4, 240, false },
        { 8, 512, true },
    },
    // points_18
    {
        { 83, 2, 300, 2, true },
        { 133, 2, 300, 2, true },
        { 83, 2, 300, 2, true },
    },
    // points_19
    {
        { 124, 2, 300, 2, true },
        { 162, 2, 300, 2, true },
        { 124, 2, 300, 2, true },
    },
    // points_20
    {
        { 98, 2, 300, 2, true },
        { 148, 2, 300, 2, true },
        { 98, 2, 300, 2, true },
    },
    // points_21
    {
        { 160, 2, 300, 3, true },
        { 110, 2, 300, 3, true },
        { 160, 2, 300, 3, true },
    },
    // points_22
    {
        { 196, 2, 300, 3, true },
        { 224, 2, 300, 3, true },
        { 196, 2, 300, 3, true },
    },
    // points_23
    {
        { 95, 2, 300, 2, true },
        { 35, 2, 300, 2, true },
        { 95, 2, 300, 3, true },
        { 35, 2, 300, 3, true },
        { 95, 2, 300, 2, true },
    },
};
