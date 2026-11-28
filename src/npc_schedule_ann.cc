#include "npc_schedule_ann.hh"
#include "game_state.hh"

extern "C" u32 SelectAnnSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    if (save.event_state.ann_and_cliff_rival_wedding_routing_state)
        return 0;

    GameDayDate date;
    DecodeGameDayDate(&date, &save.clock.calendar);
    u8 season = date.season;
    u8 day = date.day;
    u32 spouse = save.npcs.GetSpouseCharacterId();
    if (season == SEASON_FALL && day == DAY_05 && spouse != CHARACTER_ANN)
        return 5;
    if (spouse == CHARACTER_ANN) {
        if (season == SEASON_FALL) {
            if (day == DAY_09)
                return 16;
            if (day == DAY_13)
                return 17;
        }
        if (save.event_state.ann_spouse_collapse_event_state == 1)
            return 18;
        u8 family_state = save.npcs.unk_474;
        bool has_child = save.npcs.GetChild() != nullptr;
        if (static_cast<u8>(IsNpcScheduleDateListed(season, day))
            || save.clock.weather_today == WEATHER_TYPHOON
            || save.clock.weather_today == WEATHER_SNOWSTORM) {
            if (has_child) {
                if (family_state != 0)
                    return 13;
                return 12;
            }
            if (family_state != 0)
                return 15;
            return 14;
        }
        if (has_child) {
            if (family_state != 0)
                return 9;
            return 8;
        }
        if (family_state != 0)
            return 11;
        return 10;
    }
    if (save.npcs.ann.GetRivalEventCount() > 4) {
        if (static_cast<u8>(IsNpcScheduleDateListed(season, day)))
            return 6;
        if (save.clock.weather_today == WEATHER_SUNNY)
            return 3;
        return 4;
    }
    Bachelorette const * ann = save.npcs.GetBachelorette(CHARACTER_ANN);
    if (season == SEASON_WINTER && day == DAY_14 && spouse == 0
        && ann != nullptr && ann->GetLove() >= LOVE_HEART_PURPLE_MIN
        && save.event_state.winter_thanksgiving_ann_visit_event_state != 2)
        return 7;
    if (static_cast<u8>(IsNpcScheduleDateListed(season, day)))
        return 6;
    if (save.clock.weather_today == WEATHER_SUNNY)
        return 1;
    else
        return 2;
}


extern "C" AnnScheduleData const gAnnScheduleData = {
    // descriptor
    {
        SelectAnnSchedule,
        ARRAY_COUNT(gAnnScheduleData.table_choices),
        gAnnScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gAnnScheduleData.table_storage[0],
        &gAnnScheduleData.table_storage[1],
        &gAnnScheduleData.table_storage[2],
        &gAnnScheduleData.table_storage[3],
        &gAnnScheduleData.table_storage[4],
        &gAnnScheduleData.table_storage[5],
        &gAnnScheduleData.table_storage[6],
        &gAnnScheduleData.table_storage[7],
        &gAnnScheduleData.table_storage[8],
        &gAnnScheduleData.table_storage[9],
        &gAnnScheduleData.table_storage[10],
        &gAnnScheduleData.table_storage[11],
        &gAnnScheduleData.table_storage[12],
        &gAnnScheduleData.table_storage[13],
        &gAnnScheduleData.table_storage[14],
        &gAnnScheduleData.table_storage[15],
        &gAnnScheduleData.table_storage[16],
        &gAnnScheduleData.table_storage[17],
    },
    // table_storage
    {
        { ARRAY_COUNT(gAnnScheduleData.entries_0), gAnnScheduleData.entries_0 },
        { ARRAY_COUNT(gAnnScheduleData.entries_1), gAnnScheduleData.entries_1 },
        { ARRAY_COUNT(gAnnScheduleData.entries_2), gAnnScheduleData.entries_2 },
        { ARRAY_COUNT(gAnnScheduleData.entries_3), gAnnScheduleData.entries_3 },
        { ARRAY_COUNT(gAnnScheduleData.entries_4), gAnnScheduleData.entries_4 },
        { ARRAY_COUNT(gAnnScheduleData.entries_5), gAnnScheduleData.entries_5 },
        { ARRAY_COUNT(gAnnScheduleData.entries_6), gAnnScheduleData.entries_6 },
        { ARRAY_COUNT(gAnnScheduleData.entries_7), gAnnScheduleData.entries_7 },
        { ARRAY_COUNT(gAnnScheduleData.entries_8), gAnnScheduleData.entries_8 },
        { ARRAY_COUNT(gAnnScheduleData.entries_9), gAnnScheduleData.entries_9 },
        { ARRAY_COUNT(gAnnScheduleData.entries_10), gAnnScheduleData.entries_10 },
        { ARRAY_COUNT(gAnnScheduleData.entries_11), gAnnScheduleData.entries_11 },
        { ARRAY_COUNT(gAnnScheduleData.entries_12), gAnnScheduleData.entries_12 },
        { ARRAY_COUNT(gAnnScheduleData.entries_13), gAnnScheduleData.entries_13 },
        { ARRAY_COUNT(gAnnScheduleData.entries_14), gAnnScheduleData.entries_14 },
        { ARRAY_COUNT(gAnnScheduleData.entries_15), gAnnScheduleData.entries_15 },
        { ARRAY_COUNT(gAnnScheduleData.entries_16), gAnnScheduleData.entries_16 },
        { ARRAY_COUNT(gAnnScheduleData.entries_17), gAnnScheduleData.entries_17 },
    },
    // entries_0
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x0000003C, &gAnnScheduleData.payload_storage[3] },
        { 0x0000005F, &gAnnScheduleData.payload_storage[4] },
        { 0x0000006B, &gAnnScheduleData.payload_storage[5] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[6] },
        { 0x000000FD, &gAnnScheduleData.payload_storage[7] },
        { 0x0000011F, &gAnnScheduleData.payload_storage[2] },
        { 0x000001A4, &gAnnScheduleData.payload_storage[0] },
        { 0x00000258, &gAnnScheduleData.payload_storage[2] },
        { 0x0000030C, &gAnnScheduleData.payload_storage[0] },
        { 0x000003C0, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[2] },
        { 0x000001A4, &gAnnScheduleData.payload_storage[0] },
        { 0x00000258, &gAnnScheduleData.payload_storage[2] },
        { 0x0000030C, &gAnnScheduleData.payload_storage[0] },
        { 0x000003C0, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x0000003C, &gAnnScheduleData.payload_storage[3] },
        { 0x0000005F, &gAnnScheduleData.payload_storage[4] },
        { 0x0000006B, &gAnnScheduleData.payload_storage[5] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[6] },
        { 0x000000FD, &gAnnScheduleData.payload_storage[7] },
        { 0x0000011F, &gAnnScheduleData.payload_storage[2] },
        { 0x000001A4, &gAnnScheduleData.payload_storage[0] },
        { 0x00000258, &gAnnScheduleData.payload_storage[2] },
        { 0x0000030C, &gAnnScheduleData.payload_storage[0] },
        { 0x000003C0, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[2] },
        { 0x000001A4, &gAnnScheduleData.payload_storage[0] },
        { 0x00000258, &gAnnScheduleData.payload_storage[2] },
        { 0x0000030C, &gAnnScheduleData.payload_storage[0] },
        { 0x000003C0, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_4
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[0] },
        { 0x00000294, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_5
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_6
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x00000078, &gAnnScheduleData.payload_storage[8] },
        { 0x00000082, &gAnnScheduleData.payload_storage[9] },
        { 0x000000B4, &gAnnScheduleData.payload_storage[13] },
        { 0x000000BE, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_7
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_8
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x000000B4, &gAnnScheduleData.payload_storage[0] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_9
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_10
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x000000B4, &gAnnScheduleData.payload_storage[0] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_11
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_12
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_13
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_14
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_15
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[14] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_16
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[14] },
    },
    // entries_17
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[11] },
    },
    // payload_storage
    {
        { gAnnScheduleData.points_0, ARRAY_COUNT(gAnnScheduleData.points_0), 200, 83, 21, 0, true },
        { gAnnScheduleData.points_1, ARRAY_COUNT(gAnnScheduleData.points_1), 135, 96, 22, 0, true },
        { gAnnScheduleData.points_2, ARRAY_COUNT(gAnnScheduleData.points_2), 80, 88, 23, 0, true },
        { gAnnScheduleData.points_3, ARRAY_COUNT(gAnnScheduleData.points_3), 632, 488, 5, 0, false },
        { gAnnScheduleData.points_4, ARRAY_COUNT(gAnnScheduleData.points_4), 1200, 528, 0, 0, false },
        { nullptr, 0, 1032, 432, 0, 1, false },
        { gAnnScheduleData.points_6, ARRAY_COUNT(gAnnScheduleData.points_6), 1032, 432, 0, 0, false },
        { gAnnScheduleData.points_7, ARRAY_COUNT(gAnnScheduleData.points_7), 1260, 704, 5, 0, false },
        { gAnnScheduleData.points_8, ARRAY_COUNT(gAnnScheduleData.points_8), 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gAnnScheduleData.points_10, ARRAY_COUNT(gAnnScheduleData.points_10), 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { gAnnScheduleData.points_12, ARRAY_COUNT(gAnnScheduleData.points_12), 256, 152, 29, 0, true },
        { gAnnScheduleData.points_13, ARRAY_COUNT(gAnnScheduleData.points_13), 228, 145, 2, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
    },
    // points_0
    {
        { 128, 2, 120, 2, false },
        { 160, 2, 120, 0, true },
        { 96, 2, 120, 2, false },
        { 83, 2, 120, 1, true },
        { 200, 2, 120, 3, false },
    },
    // points_1
    {
        { 200, 2, 120, 3, false },
        { 135, 2, 120, 2, false },
    },
    // points_2
    {
        { 176, 2, 120, 0, true },
        { 88, 2, 120, 1, true },
    },
    // points_3
    {
        { 2, 536, true },
        { 27, 1260, false },
        { 35, 736, true },
    },
    // points_4
    {
        { 1, 1176, false },
        { 2, 512, true },
        { 3, 1160, false },
        { 4, 496, true },
        { 5, 1144, false },
        { 6, 480, true },
        { 10, 1032, false },
        { 12, 432, true },
    },
    // points_6
    {
        { 2, 480, true },
        { 6, 1144, false },
        { 7, 496, true },
        { 8, 1160, false },
        { 9, 512, true },
        { 10, 1176, false },
        { 11, 528, true },
        { 13, 1216, false },
    },
    // points_7
    {
        { 7, 536, true },
        { 32, 632, false },
        { 34, 488, true },
    },
    // points_8
    {
        { 6, 145, true },
        { 10, 228, false },
    },
    // points_10
    {
        { 108, 2, 120, 2, true },
        { 128, 2, 120, 3, false },
        { 76, 2, 120, 3, true },
        { 112, 2, 120, 2, false },
    },
    // points_12
    {
        { 96, 2, 0, 0, true },
        { 328, 2, 120, 3, false },
        { 256, 2, 0, 0, false },
        { 152, 2, 120, 0, true },
    },
    // points_13
    {
        { 4, 340, false },
        { 10, 0, true },
    },
};
