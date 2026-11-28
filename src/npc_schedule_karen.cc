#include "npc_schedule_karen.hh"
#include "game_state.hh"

extern "C" u32 SelectKarenSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    u32 rival_wedding = static_cast<u32>(save.event_state.rick_and_karen_rival_wedding_routing_state)
        | static_cast<u32>(save.event_state.popuri_and_kai_rival_wedding_routing_state);
    if (rival_wedding != 0)
        return 0;

    GameDayDate date;
    DecodeGameDayDate(&date, &save.clock.calendar);
    u8 season = date.season;
    u8 day = date.day;
    u8 weekday = date.weekday;
    NpcCollection const & characters = save.npcs;
    u32 spouse = characters.GetSpouseCharacterId();
    if (spouse == CHARACTER_KAREN) {
        if (season == SEASON_FALL) {
            if (day == DAY_09)
                return 21;
            if (day == DAY_13)
                return 22;
        }
        if (save.event_state.karen_spouse_collapse_event_state == 1)
            return 23;
        u8 family_state = save.npcs.unk_474;
        bool has_child = save.npcs.GetChild() != nullptr;
        if (static_cast<u8>(IsNpcScheduleDateListed(season, day))
            || save.clock.weather_today == WEATHER_TYPHOON
            || save.clock.weather_today == WEATHER_SNOWSTORM) {
            if (has_child) {
                if (family_state != 0)
                    return 18;
                return 17;
            }
            if (family_state != 0)
                return 20;
            return 19;
        }
        if (family_state != 0 && (weekday == DAY_OF_WEEK_SUNDAY || weekday == DAY_OF_WEEK_TUESDAY)) {
            if (has_child)
                return 13;
            return 16;
        }
        if (has_child) {
            if (family_state != 0)
                return 12;
            return 11;
        }
        if (family_state != 0)
            return 15;
        return 14;
    }
    if (save.npcs.karen.GetRivalEventCount() > 4) {
        if (static_cast<u8>(IsNpcScheduleDateListed(season, day)))
            return 10;
        if (weekday == DAY_OF_WEEK_SUNDAY)
            return 7;
        return 6;
    }
    Bachelorette const * karen = characters.GetBachelorette(CHARACTER_KAREN);
    if (season == SEASON_WINTER && day == DAY_14 && spouse == 0
        && karen != nullptr && karen->GetLove() >= LOVE_HEART_PURPLE_MIN
        && save.event_state.winter_thanksgiving_karen_visit_event_state != 2)
        return 9;
    if (static_cast<u8>(IsNpcScheduleDateListed(season, day)))
        return 8;
    if (weekday == DAY_OF_WEEK_SUNDAY)
        return 3;
    if (weekday == DAY_OF_WEEK_TUESDAY) {
        if (save.clock.weather_today == WEATHER_SUNNY)
            return 4;
        return 5;
    }
    if (save.clock.weather_today == WEATHER_SUNNY)
        return 1;
    else
        return 2;
}


// This 24-choice selector follows immediately in ROM. The aggregate keeps
// its table pointers, entries, payloads, and pointed detail records in their
// original physical order while giving every actual pointer a C++ relocation.
extern "C" KarenScheduleData const gKarenScheduleData = {
    // descriptor
    {
        SelectKarenSchedule,
        ARRAY_COUNT(gKarenScheduleData.table_choices),
        gKarenScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gKarenScheduleData.table_storage[0],
        &gKarenScheduleData.table_storage[1],
        &gKarenScheduleData.table_storage[2],
        &gKarenScheduleData.table_storage[3],
        &gKarenScheduleData.table_storage[4],
        &gKarenScheduleData.table_storage[5],
        &gKarenScheduleData.table_storage[6],
        &gKarenScheduleData.table_storage[7],
        &gKarenScheduleData.table_storage[8],
        &gKarenScheduleData.table_storage[9],
        &gKarenScheduleData.table_storage[10],
        &gKarenScheduleData.table_storage[11],
        &gKarenScheduleData.table_storage[12],
        &gKarenScheduleData.table_storage[13],
        &gKarenScheduleData.table_storage[14],
        &gKarenScheduleData.table_storage[15],
        &gKarenScheduleData.table_storage[16],
        &gKarenScheduleData.table_storage[17],
        &gKarenScheduleData.table_storage[18],
        &gKarenScheduleData.table_storage[19],
        &gKarenScheduleData.table_storage[20],
        &gKarenScheduleData.table_storage[21],
        &gKarenScheduleData.table_storage[22],
    },
    // table_storage
    {
        { ARRAY_COUNT(gKarenScheduleData.entries_0), gKarenScheduleData.entries_0 },
        { ARRAY_COUNT(gKarenScheduleData.entries_1), gKarenScheduleData.entries_1 },
        { ARRAY_COUNT(gKarenScheduleData.entries_2), gKarenScheduleData.entries_2 },
        { ARRAY_COUNT(gKarenScheduleData.entries_3), gKarenScheduleData.entries_3 },
        { ARRAY_COUNT(gKarenScheduleData.entries_4), gKarenScheduleData.entries_4 },
        { ARRAY_COUNT(gKarenScheduleData.entries_5), gKarenScheduleData.entries_5 },
        { ARRAY_COUNT(gKarenScheduleData.entries_6), gKarenScheduleData.entries_6 },
        { ARRAY_COUNT(gKarenScheduleData.entries_7), gKarenScheduleData.entries_7 },
        { ARRAY_COUNT(gKarenScheduleData.entries_8), gKarenScheduleData.entries_8 },
        { ARRAY_COUNT(gKarenScheduleData.entries_9), gKarenScheduleData.entries_9 },
        { ARRAY_COUNT(gKarenScheduleData.entries_10), gKarenScheduleData.entries_10 },
        { ARRAY_COUNT(gKarenScheduleData.entries_11), gKarenScheduleData.entries_11 },
        { ARRAY_COUNT(gKarenScheduleData.entries_12), gKarenScheduleData.entries_12 },
        { ARRAY_COUNT(gKarenScheduleData.entries_13), gKarenScheduleData.entries_13 },
        { ARRAY_COUNT(gKarenScheduleData.entries_14), gKarenScheduleData.entries_14 },
        { ARRAY_COUNT(gKarenScheduleData.entries_15), gKarenScheduleData.entries_15 },
        { ARRAY_COUNT(gKarenScheduleData.entries_16), gKarenScheduleData.entries_16 },
        { ARRAY_COUNT(gKarenScheduleData.entries_17), gKarenScheduleData.entries_17 },
        { ARRAY_COUNT(gKarenScheduleData.entries_18), gKarenScheduleData.entries_18 },
        { ARRAY_COUNT(gKarenScheduleData.entries_19), gKarenScheduleData.entries_19 },
        { ARRAY_COUNT(gKarenScheduleData.entries_20), gKarenScheduleData.entries_20 },
        { ARRAY_COUNT(gKarenScheduleData.entries_21), gKarenScheduleData.entries_21 },
        { ARRAY_COUNT(gKarenScheduleData.entries_22), gKarenScheduleData.entries_22 },
    },
    // entries_0
    {
        { 0x0000, &gKarenScheduleData.payload_storage[0] },
        { 0x0078, &gKarenScheduleData.payload_storage[1] },
        { 0x007E, &gKarenScheduleData.payload_storage[2] },
        { 0x00F0, &gKarenScheduleData.payload_storage[3] },
        { 0x00F6, &gKarenScheduleData.payload_storage[0] },
        { 0x01A4, &gKarenScheduleData.payload_storage[4] },
        { 0x0258, &gKarenScheduleData.payload_storage[0] },
        { 0x030C, &gKarenScheduleData.payload_storage[5] },
        { 0x033A, &gKarenScheduleData.payload_storage[6] },
        { 0x034B, &gKarenScheduleData.payload_storage[7] },
        { 0x03C0, &gKarenScheduleData.payload_storage[8] },
        { 0x03D2, &gKarenScheduleData.payload_storage[9] },
        { 0x03FF, &gKarenScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x0000, &gKarenScheduleData.payload_storage[0] },
        { 0x0078, &gKarenScheduleData.payload_storage[4] },
        { 0x00F0, &gKarenScheduleData.payload_storage[0] },
        { 0x01A4, &gKarenScheduleData.payload_storage[4] },
        { 0x0258, &gKarenScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x0000, &gKarenScheduleData.payload_storage[0] },
        { 0x0078, &gKarenScheduleData.payload_storage[4] },
        { 0x030C, &gKarenScheduleData.payload_storage[11] },
        { 0x0329, &gKarenScheduleData.payload_storage[10] },
        { 0x03C9, &gKarenScheduleData.payload_storage[12] },
        { 0x03E6, &gKarenScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x0000, &gKarenScheduleData.payload_storage[0] },
        { 0x0078, &gKarenScheduleData.payload_storage[1] },
        { 0x007E, &gKarenScheduleData.payload_storage[2] },
        { 0x00F0, &gKarenScheduleData.payload_storage[3] },
        { 0x00F6, &gKarenScheduleData.payload_storage[0] },
        { 0x01A4, &gKarenScheduleData.payload_storage[5] },
        { 0x01D2, &gKarenScheduleData.payload_storage[13] },
        { 0x01E0, &gKarenScheduleData.payload_storage[14] },
        { 0x0258, &gKarenScheduleData.payload_storage[15] },
        { 0x0267, &gKarenScheduleData.payload_storage[9] },
        { 0x0294, &gKarenScheduleData.payload_storage[0] },
        { 0x030C, &gKarenScheduleData.payload_storage[11] },
        { 0x0329, &gKarenScheduleData.payload_storage[10] },
        { 0x03C9, &gKarenScheduleData.payload_storage[12] },
        { 0x03E6, &gKarenScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x0000, &gKarenScheduleData.payload_storage[0] },
        { 0x0078, &gKarenScheduleData.payload_storage[4] },
        { 0x00F0, &gKarenScheduleData.payload_storage[0] },
        { 0x01A4, &gKarenScheduleData.payload_storage[5] },
        { 0x01D2, &gKarenScheduleData.payload_storage[16] },
        { 0x01E9, &gKarenScheduleData.payload_storage[17] },
        { 0x0258, &gKarenScheduleData.payload_storage[18] },
        { 0x026F, &gKarenScheduleData.payload_storage[9] },
        { 0x029C, &gKarenScheduleData.payload_storage[0] },
        { 0x030C, &gKarenScheduleData.payload_storage[11] },
        { 0x0329, &gKarenScheduleData.payload_storage[10] },
        { 0x03C9, &gKarenScheduleData.payload_storage[12] },
        { 0x03E6, &gKarenScheduleData.payload_storage[0] },
    },
    // entries_5
    {
        { 0x0000, &gKarenScheduleData.payload_storage[20] },
        { 0x0078, &gKarenScheduleData.payload_storage[21] },
        { 0x007D, &gKarenScheduleData.payload_storage[22] },
        { 0x00F0, &gKarenScheduleData.payload_storage[23] },
        { 0x00F5, &gKarenScheduleData.payload_storage[19] },
        { 0x030C, &gKarenScheduleData.payload_storage[20] },
    },
    // entries_6
    {
        { 0x0000, &gKarenScheduleData.payload_storage[20] },
        { 0x0041, &gKarenScheduleData.payload_storage[24] },
        { 0x005F, &gKarenScheduleData.payload_storage[25] },
        { 0x008C, &gKarenScheduleData.payload_storage[4] },
        { 0x030C, &gKarenScheduleData.payload_storage[32] },
        { 0x033A, &gKarenScheduleData.payload_storage[33] },
        { 0x0358, &gKarenScheduleData.payload_storage[20] },
    },
    // entries_7
    {
        { 0x0000, &gKarenScheduleData.payload_storage[0] },
    },
    // entries_8
    {
        { 0x0000, &gKarenScheduleData.payload_storage[0] },
        { 0x0168, &gKarenScheduleData.payload_storage[26] },
        { 0x0172, &gKarenScheduleData.payload_storage[27] },
        { 0x01A4, &gKarenScheduleData.payload_storage[31] },
        { 0x01AE, &gKarenScheduleData.payload_storage[0] },
    },
    // entries_9
    {
        { 0x0000, &gKarenScheduleData.payload_storage[19] },
    },
    // entries_10
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_11
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x00B4, &gKarenScheduleData.payload_storage[4] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_12
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_13
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_14
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x00B4, &gKarenScheduleData.payload_storage[4] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_15
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_16
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_17
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_18
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_19
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_20
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x00F0, &gKarenScheduleData.payload_storage[34] },
        { 0x02D0, &gKarenScheduleData.payload_storage[30] },
        { 0x0348, &gKarenScheduleData.payload_storage[29] },
    },
    // entries_21
    {
        { 0x0000, &gKarenScheduleData.payload_storage[30] },
        { 0x012C, &gKarenScheduleData.payload_storage[28] },
        { 0x02D0, &gKarenScheduleData.payload_storage[34] },
    },
    // entries_22
    {
        { 0x0000, &gKarenScheduleData.payload_storage[29] },
    },
    // payload_storage
    {
        { gKarenScheduleData.points_0, ARRAY_COUNT(gKarenScheduleData.points_0), 104, 104, 16, 0, true },
        { gKarenScheduleData.points_1, ARRAY_COUNT(gKarenScheduleData.points_1), 688, 160, 5, 0, false },
        { nullptr, 0, 752, 184, 5, 0, false },
        { gKarenScheduleData.points_3, ARRAY_COUNT(gKarenScheduleData.points_3), 752, 184, 5, 0, false },
        { gKarenScheduleData.points_4, ARRAY_COUNT(gKarenScheduleData.points_4), 128, 80, 15, 0, true },
        { gKarenScheduleData.points_5, ARRAY_COUNT(gKarenScheduleData.points_5), 688, 160, 5, 0, false },
        { gKarenScheduleData.points_6, ARRAY_COUNT(gKarenScheduleData.points_6), 0, 280, 1, 0, false },
        { gKarenScheduleData.points_7, ARRAY_COUNT(gKarenScheduleData.points_7), 256, 296, 1, 0, true },
        { gKarenScheduleData.points_8, ARRAY_COUNT(gKarenScheduleData.points_8), 256, 296, 1, 0, false },
        { gKarenScheduleData.points_9, ARRAY_COUNT(gKarenScheduleData.points_9), 1260, 704, 5, 0, false },
        { nullptr, 0, 208, 120, 21, 1, false },
        { gKarenScheduleData.points_11, ARRAY_COUNT(gKarenScheduleData.points_11), 688, 160, 5, 0, false },
        { gKarenScheduleData.points_12, ARRAY_COUNT(gKarenScheduleData.points_12), 632, 488, 5, 0, false },
        { gKarenScheduleData.points_13, ARRAY_COUNT(gKarenScheduleData.points_13), 1200, 528, 0, 0, false },
        { nullptr, 0, 1008, 424, 0, 1, false },
        { gKarenScheduleData.points_15, ARRAY_COUNT(gKarenScheduleData.points_15), 1008, 424, 0, 0, false },
        { gKarenScheduleData.points_16, ARRAY_COUNT(gKarenScheduleData.points_16), 832, 0, 3, 0, false },
        { gKarenScheduleData.points_17, ARRAY_COUNT(gKarenScheduleData.points_17), 160, 160, 40, 0, true },
        { gKarenScheduleData.points_18, ARRAY_COUNT(gKarenScheduleData.points_18), 612, 244, 3, 0, false },
        { nullptr, 0, 88, 104, 10, 1, false },
        { nullptr, 0, 90, 80, 11, 0, false },
        { gKarenScheduleData.points_21, ARRAY_COUNT(gKarenScheduleData.points_21), 572, 227, 7, 0, false },
        { gKarenScheduleData.points_22, ARRAY_COUNT(gKarenScheduleData.points_22), 544, 312, 7, 0, true },
        { gKarenScheduleData.points_23, ARRAY_COUNT(gKarenScheduleData.points_23), 544, 312, 7, 0, false },
        { gKarenScheduleData.points_24, ARRAY_COUNT(gKarenScheduleData.points_24), 572, 227, 7, 0, false },
        { gKarenScheduleData.points_25, ARRAY_COUNT(gKarenScheduleData.points_25), 104, 704, 5, 0, false },
        { gKarenScheduleData.points_26, ARRAY_COUNT(gKarenScheduleData.points_26), 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gKarenScheduleData.points_28, ARRAY_COUNT(gKarenScheduleData.points_28), 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { gKarenScheduleData.points_30, ARRAY_COUNT(gKarenScheduleData.points_30), 256, 152, 29, 0, true },
        { gKarenScheduleData.points_31, ARRAY_COUNT(gKarenScheduleData.points_31), 228, 145, 2, 0, false },
        { gKarenScheduleData.points_32, ARRAY_COUNT(gKarenScheduleData.points_32), 688, 160, 5, 0, false },
        { gKarenScheduleData.points_33, ARRAY_COUNT(gKarenScheduleData.points_33), 104, 0, 7, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
    },
    // points_0
    {
        { 64, 2, 0, 0, false },
        { 224, 2, 120, 0, true },
        { 104, 2, 0, 0, true },
        { 104, 2, 120, 3, false },
    },
    // points_1
    {
        { 2, 216, true },
        { 5, 752, false },
        { 6, 184, true },
    },
    // points_3
    {
        { 1, 216, true },
        { 4, 688, false },
        { 6, 160, true },
    },
    // points_4
    {
        { 56, 2, 120, 2, false },
        { 128, 2, 120, 3, false },
    },
    // points_5
    {
        { 2, 216, true },
        { 24, 1248, false },
        { 25, 240, true },
        { 26, 1260, false },
        { 46, 736, true },
    },
    // points_6
    {
        { 3, 64, false },
        { 6, 360, true },
        { 8, 104, false },
        { 11, 296, true },
        { 17, 256, false },
    },
    // points_7
    {
        { 336, 2, 120, 3, true },
        { 296, 2, 120, 3, true },
    },
    // points_8
    {
        { 6, 104, false },
        { 9, 360, true },
        { 11, 64, false },
        { 14, 280, true },
        { 18, -16, false },
    },
    // points_9
    {
        { 19, 240, true },
        { 20, 1248, false },
        { 21, 216, true },
        { 43, 688, false },
        { 45, 160, true },
    },
    // points_11
    {
        { 2, 216, true },
        { 7, 808, false },
        { 20, 536, true },
        { 27, 632, false },
        { 29, 488, true },
    },
    // points_12
    {
        { 2, 536, true },
        { 9, 808, false },
        { 22, 216, true },
        { 27, 688, false },
        { 29, 160, true },
    },
    // points_13
    {
        { 1, 1176, false },
        { 2, 512, true },
        { 3, 1160, false },
        { 4, 496, true },
        { 5, 1144, false },
        { 6, 480, true },
        { 11, 1008, false },
        { 14, 424, true },
    },
    // points_15
    {
        { 3, 480, true },
        { 8, 1144, false },
        { 9, 496, true },
        { 10, 1160, false },
        { 11, 512, true },
        { 12, 1176, false },
        { 13, 528, true },
        { 15, 1216, false },
    },
    // points_16
    {
        { 12, 296, true },
        { 21, 614, false },
        { 23, 244, true },
    },
    // points_17
    {
        { 216, 2, 120, 3, false },
        { 160, 2, 120, 2, false },
    },
    // points_18
    {
        { 2, 296, true },
        { 11, 832, false },
        { 23, 0, true },
    },
    // points_21
    {
        { 1, 248, true },
        { 2, 544, false },
        { 5, 312, true },
    },
    // points_22
    {
        { 600, 2, 120, 3, false },
        { 544, 2, 120, 2, false },
    },
    // points_23
    {
        { 3, 248, true },
        { 4, 572, false },
        { 5, 227, true },
    },
    // points_24
    {
        { 1, 248, true },
        { 5, 472, false },
        { 9, 152, true },
        { 24, 104, false },
        { 30, 0, true },
    },
    // points_25
    {
        { 19, 240, true },
        { 20, 144, false },
        { 21, 216, true },
        { 43, 688, false },
        { 45, 160, true },
    },
    // points_26
    {
        { 6, 145, true },
        { 10, 228, false },
    },
    // points_28
    {
        { 108, 2, 120, 2, true },
        { 128, 2, 120, 3, false },
        { 76, 2, 120, 3, true },
        { 112, 2, 120, 2, false },
    },
    // points_30
    {
        { 96, 2, 0, 0, true },
        { 328, 2, 120, 3, false },
        { 256, 2, 0, 0, false },
        { 152, 2, 120, 0, true },
    },
    // points_31
    {
        { 4, 340, false },
        { 10, 0, true },
    },
    // points_32
    {
        { 2, 216, true },
        { 24, 144, false },
        { 25, 240, true },
        { 26, 104, false },
        { 46, 736, true },
    },
    // points_33
    {
        { 6, 152, true },
        { 21, 472, false },
        { 25, 248, true },
        { 29, 572, false },
        { 30, 227, true },
    },
};
