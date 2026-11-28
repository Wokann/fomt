#include "npc_schedule_mary.hh"
#include "game_state.hh"

extern "C" u32 SelectMarySchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    if (save.event_state.mary_and_gray_rival_wedding_routing_state)
        return 0;

    GameDayDate date;
    DecodeGameDayDate(&date, &save.clock.calendar);
    u8 season = date.season;
    u8 day = date.day;
    u8 weekday = date.weekday;
    NpcCollection const & characters = save.npcs;
    u32 spouse = characters.GetSpouseCharacterId();
    if (spouse == CHARACTER_MARY) {
        if (season == SEASON_FALL) {
            if (day == DAY_09)
                return 16;
            if (day == DAY_13)
                return 17;
        }
        if (save.event_state.mary_spouse_collapse_event_state == 1)
            return 18;
        bool has_child = save.npcs.GetChild() != nullptr;
        if (static_cast<u8>(IsNpcScheduleDateListed(season, day))
            || save.clock.weather_today == WEATHER_TYPHOON
            || save.clock.weather_today == WEATHER_SNOWSTORM) {
            if (has_child)
                return 14;
            return 15;
        }
        if (weekday == DAY_OF_WEEK_MONDAY) {
            if (has_child)
                return 11;
            return 13;
        }
        if (has_child)
            return 10;
        return 12;
    }
    if (save.npcs.mary.GetRivalEventCount() > 4) {
        if (static_cast<u8>(IsNpcScheduleDateListed(season, day)))
            return 9;
        if (weekday == DAY_OF_WEEK_THURSDAY) {
            if (save.clock.weather_today == WEATHER_SUNNY)
                return 5;
            return 6;
        }
        return 4;
    }
    Bachelorette const * mary = characters.GetBachelorette(CHARACTER_MARY);
    if (season == SEASON_WINTER && day == DAY_14 && spouse == 0
        && mary != nullptr && mary->GetLove() >= LOVE_HEART_PURPLE_MIN
        && save.event_state.winter_thanksgiving_mary_visit_event_state != 2)
        return 7;
    if (static_cast<u8>(IsNpcScheduleDateListed(season, day)))
        return 8;
    if (weekday == DAY_OF_WEEK_MONDAY) {
        if (save.clock.weather_today == WEATHER_SUNNY)
            return 2;
        return 3;
    }
    return 1;
}


extern "C" MaryScheduleData const gMaryScheduleData = {
    // descriptor
    {
        SelectMarySchedule,
        ARRAY_COUNT(gMaryScheduleData.table_choices),
        gMaryScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gMaryScheduleData.table_storage[0],
        &gMaryScheduleData.table_storage[1],
        &gMaryScheduleData.table_storage[2],
        &gMaryScheduleData.table_storage[3],
        &gMaryScheduleData.table_storage[4],
        &gMaryScheduleData.table_storage[5],
        &gMaryScheduleData.table_storage[6],
        &gMaryScheduleData.table_storage[7],
        &gMaryScheduleData.table_storage[8],
        &gMaryScheduleData.table_storage[9],
        &gMaryScheduleData.table_storage[10],
        &gMaryScheduleData.table_storage[11],
        &gMaryScheduleData.table_storage[12],
        &gMaryScheduleData.table_storage[13],
        &gMaryScheduleData.table_storage[14],
        &gMaryScheduleData.table_storage[15],
        &gMaryScheduleData.table_storage[16],
        &gMaryScheduleData.table_storage[17],
    },
    // table_storage
    {
        { ARRAY_COUNT(gMaryScheduleData.entries_0), gMaryScheduleData.entries_0 },
        { ARRAY_COUNT(gMaryScheduleData.entries_1), gMaryScheduleData.entries_1 },
        { ARRAY_COUNT(gMaryScheduleData.entries_2), gMaryScheduleData.entries_2 },
        { ARRAY_COUNT(gMaryScheduleData.entries_3), gMaryScheduleData.entries_3 },
        { ARRAY_COUNT(gMaryScheduleData.entries_4), gMaryScheduleData.entries_4 },
        { ARRAY_COUNT(gMaryScheduleData.entries_5), gMaryScheduleData.entries_5 },
        { ARRAY_COUNT(gMaryScheduleData.entries_6), gMaryScheduleData.entries_6 },
        { ARRAY_COUNT(gMaryScheduleData.entries_7), gMaryScheduleData.entries_7 },
        { ARRAY_COUNT(gMaryScheduleData.entries_8), gMaryScheduleData.entries_8 },
        { ARRAY_COUNT(gMaryScheduleData.entries_9), gMaryScheduleData.entries_9 },
        { ARRAY_COUNT(gMaryScheduleData.entries_10), gMaryScheduleData.entries_10 },
        { ARRAY_COUNT(gMaryScheduleData.entries_11), gMaryScheduleData.entries_11 },
        { ARRAY_COUNT(gMaryScheduleData.entries_12), gMaryScheduleData.entries_12 },
        { ARRAY_COUNT(gMaryScheduleData.entries_13), gMaryScheduleData.entries_13 },
        { ARRAY_COUNT(gMaryScheduleData.entries_14), gMaryScheduleData.entries_14 },
        { ARRAY_COUNT(gMaryScheduleData.entries_15), gMaryScheduleData.entries_15 },
        { ARRAY_COUNT(gMaryScheduleData.entries_16), gMaryScheduleData.entries_16 },
        { ARRAY_COUNT(gMaryScheduleData.entries_17), gMaryScheduleData.entries_17 },
    },
    // entries_0
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000000F0, &gMaryScheduleData.payload_storage[2] },
        { 0x000000F7, &gMaryScheduleData.payload_storage[3] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[4] },
        { 0x000002D7, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003F, &gMaryScheduleData.payload_storage[5] },
        { 0x0000005A, &gMaryScheduleData.payload_storage[6] },
        { 0x00000094, &gMaryScheduleData.payload_storage[7] },
        { 0x000000F0, &gMaryScheduleData.payload_storage[8] },
        { 0x0000012A, &gMaryScheduleData.payload_storage[9] },
        { 0x00000144, &gMaryScheduleData.payload_storage[1] },
        { 0x000001A4, &gMaryScheduleData.payload_storage[10] },
        { 0x000001BC, &gMaryScheduleData.payload_storage[11] },
        { 0x0000025B, &gMaryScheduleData.payload_storage[12] },
        { 0x00000273, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000001A4, &gMaryScheduleData.payload_storage[10] },
        { 0x000001BC, &gMaryScheduleData.payload_storage[11] },
        { 0x0000025B, &gMaryScheduleData.payload_storage[12] },
        { 0x00000273, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000000F0, &gMaryScheduleData.payload_storage[2] },
        { 0x000000F7, &gMaryScheduleData.payload_storage[3] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[4] },
        { 0x000002D7, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000001AA, &gMaryScheduleData.payload_storage[5] },
        { 0x000001C5, &gMaryScheduleData.payload_storage[23] },
        { 0x000001CE, &gMaryScheduleData.payload_storage[24] },
        { 0x00000258, &gMaryScheduleData.payload_storage[25] },
        { 0x00000262, &gMaryScheduleData.payload_storage[9] },
        { 0x0000027C, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_5
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000001A4, &gMaryScheduleData.payload_storage[5] },
        { 0x000001BF, &gMaryScheduleData.payload_storage[19] },
        { 0x000001CF, &gMaryScheduleData.payload_storage[20] },
        { 0x00000258, &gMaryScheduleData.payload_storage[21] },
        { 0x00000268, &gMaryScheduleData.payload_storage[9] },
        { 0x00000282, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_6
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[1] },
        { 0x000001E0, &gMaryScheduleData.payload_storage[16] },
        { 0x000001EA, &gMaryScheduleData.payload_storage[17] },
        { 0x0000021C, &gMaryScheduleData.payload_storage[18] },
        { 0x00000226, &gMaryScheduleData.payload_storage[1] },
    },
    // entries_7
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[1] },
    },
    // entries_8
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[1] },
    },
    // entries_9
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x000000B4, &gMaryScheduleData.payload_storage[3] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_10
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_11
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x000000B4, &gMaryScheduleData.payload_storage[3] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_12
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_13
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_14
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_15
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x000000F0, &gMaryScheduleData.payload_storage[22] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_16
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[22] },
    },
    // entries_17
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[14] },
    },
    // payload_storage
    {
        { gMaryScheduleData.points_0, ARRAY_COUNT(gMaryScheduleData.points_0), 176, 120, 27, 0, true },
        { gMaryScheduleData.points_1, ARRAY_COUNT(gMaryScheduleData.points_1), 176, 160, 26, 0, true },
        { gMaryScheduleData.points_2, ARRAY_COUNT(gMaryScheduleData.points_2), 200, 160, 5, 0, false },
        { nullptr, 0, 172, 115, 24, 0, false },
        { gMaryScheduleData.points_4, ARRAY_COUNT(gMaryScheduleData.points_4), 276, 168, 5, 0, false },
        { gMaryScheduleData.points_5, ARRAY_COUNT(gMaryScheduleData.points_5), 200, 160, 5, 0, false },
        { gMaryScheduleData.points_6, ARRAY_COUNT(gMaryScheduleData.points_6), 1200, 752, 0, 0, false },
        { gMaryScheduleData.points_7, ARRAY_COUNT(gMaryScheduleData.points_7), 344, 208, 0, 0, true },
        { gMaryScheduleData.points_8, ARRAY_COUNT(gMaryScheduleData.points_8), 344, 208, 0, 0, false },
        { gMaryScheduleData.points_9, ARRAY_COUNT(gMaryScheduleData.points_9), 104, 704, 5, 0, false },
        { gMaryScheduleData.points_10, ARRAY_COUNT(gMaryScheduleData.points_10), 200, 160, 5, 0, false },
        { nullptr, 0, 120, 138, 15, 0, false },
        { gMaryScheduleData.points_12, ARRAY_COUNT(gMaryScheduleData.points_12), 688, 160, 5, 0, false },
        { gMaryScheduleData.points_13, ARRAY_COUNT(gMaryScheduleData.points_13), 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { gMaryScheduleData.points_15, ARRAY_COUNT(gMaryScheduleData.points_15), 256, 152, 29, 0, true },
        { gMaryScheduleData.points_16, ARRAY_COUNT(gMaryScheduleData.points_16), 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gMaryScheduleData.points_18, ARRAY_COUNT(gMaryScheduleData.points_18), 228, 145, 2, 0, false },
        { gMaryScheduleData.points_19, ARRAY_COUNT(gMaryScheduleData.points_19), 104, 0, 7, 0, false },
        { nullptr, 0, 48, 88, 38, 0, false },
        { gMaryScheduleData.points_21, ARRAY_COUNT(gMaryScheduleData.points_21), 296, 116, 7, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
        { gMaryScheduleData.points_23, ARRAY_COUNT(gMaryScheduleData.points_23), 240, 480, 8, 0, false },
        { nullptr, 0, 256, 272, 8, 1, false },
        { gMaryScheduleData.points_25, ARRAY_COUNT(gMaryScheduleData.points_25), 256, 272, 8, 0, false },
    },
    // points_0
    {
        { 72, 2, 120, 2, false },
        { 176, 2, 120, 3, false },
    },
    // points_1
    {
        { 88, 2, 120, 1, true },
        { 160, 2, 120, 0, true },
    },
    // points_2
    {
        { 2, 216, true },
        { 5, 276, false },
        { 7, 168, true },
    },
    // points_4
    {
        { 2, 216, true },
        { 5, 200, false },
        { 7, 160, true },
    },
    // points_5
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 7, 104, false },
        { 27, 734, true },
    },
    // points_6
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
        { 56, 344, false },
        { 58, 208, true },
    },
    // points_7
    {
        { 392, 2, 120, 3, false },
        { 344, 2, 120, 2, false },
    },
    // points_8
    {
        { 2, 168, true },
        { 14, 656, false },
        { 20, 328, true },
        { 21, 692, false },
        { 31, 568, true },
        { 32, 720, false },
        { 33, 592, true },
        { 34, 752, false },
        { 35, 624, true },
        { 36, 776, false },
        { 37, 656, true },
        { 38, 808, false },
        { 39, 680, true },
        { 40, 832, false },
        { 41, 704, true },
        { 42, 856, false },
        { 43, 728, true },
        { 45, 912, false },
        { 46, 752, true },
        { 58, 1216, false },
    },
    // points_9
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 24, 200, false },
        { 26, 160, true },
    },
    // points_10
    {
        { 2, 216, true },
        { 22, 688, false },
        { 24, 160, true },
    },
    // points_12
    {
        { 2, 216, true },
        { 22, 200, false },
        { 24, 160, true },
    },
    // points_13
    {
        { 108, 2, 120, 2, true },
        { 128, 2, 120, 3, false },
        { 76, 2, 120, 3, true },
        { 112, 2, 120, 2, false },
    },
    // points_15
    {
        { 96, 2, 0, 0, true },
        { 328, 2, 120, 3, false },
        { 256, 2, 0, 0, false },
        { 152, 2, 120, 0, true },
    },
    // points_16
    {
        { 6, 145, true },
        { 10, 228, false },
    },
    // points_18
    {
        { 4, 340, false },
        { 10, 0, true },
    },
    // points_19
    {
        { 6, 152, true },
        { 14, 296, false },
        { 16, 116, true },
    },
    // points_21
    {
        { 2, 152, true },
        { 10, 104, false },
        { 16, 0, true },
    },
    // points_23
    {
        { 8, 272, true },
        { 9, 256, false },
    },
    // points_25
    {
        { 1, 240, false },
        { 10, 512, true },
    },
};
