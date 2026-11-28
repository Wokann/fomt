#include "npc_schedule_popuri.hh"
#include "game_state.hh"

extern "C" u32 SelectPopuriSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    if (save.event_state.popuri_and_kai_rival_wedding_routing_state)
        return 0;

    GameDayDate date;
    DecodeGameDayDate(&date, &save.clock.calendar);
    u8 season = date.season;
    u8 day = date.day;
    u8 weekday = date.weekday;
    u32 spouse = save.npcs.GetSpouseCharacterId();
    if (spouse == CHARACTER_POPURI) {
        if (season == SEASON_FALL && day == DAY_13)
            return 22;
        if (save.event_state.popuri_spouse_collapse_event_state == 1)
            return 23;
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
        if (family_state != 0 && weekday == DAY_OF_WEEK_SUNDAY) {
            if (has_child)
                return 8;
            return 11;
        }
        if (has_child) {
            if (family_state != 0)
                return 7;
            return 6;
        }
        if (family_state != 0)
            return 10;
        return 9;
    }

    if (save.npcs.popuri.GetRivalEventCount() > 4) {
        if (season != SEASON_SUMMER)
            return 0;
        if (static_cast<u8>(IsNpcScheduleDateListed(SEASON_SUMMER, day)))
            return 19;
        if (save.clock.weather_today == WEATHER_SUNNY)
            return 20;
        return 21;
    }
    if (season == SEASON_FALL && day == DAY_30
        && save.event_state.pumpkin_festival_popuri_treat_visit_state != 2)
        return 17;
    Bachelorette const * popuri = save.npcs.GetBachelorette(CHARACTER_POPURI);
    if (season == SEASON_WINTER && day == DAY_14 && spouse == 0
        && popuri != nullptr && popuri->GetLove() >= LOVE_HEART_PURPLE_MIN
        && save.event_state.winter_thanksgiving_popuri_visit_event_state != 2)
        return 18;
    if (static_cast<u8>(IsNpcScheduleDateListed(season, day)))
        return 16;
    if (save.event_state.popuri_blue_heart_event_choice)
        return 0;
    if (weekday == DAY_OF_WEEK_SUNDAY) {
        if (save.clock.weather_today == WEATHER_SUNNY) {
            if (season == SEASON_SUMMER)
                return 5;
            return 3;
        }
        return 4;
    }
    if (save.clock.weather_today == WEATHER_SUNNY)
        return 1;
    else
        return 2;
}

// Recovered schedule data at US ROM 0x080F1FC0 (JP 0x080F181C).
// The two regional payloads differ only in relocated function/data pointers.

extern "C" PopuriScheduleData const gPopuriScheduleData = {
    // descriptor
    { SelectPopuriSchedule, ARRAY_COUNT(gPopuriScheduleData.table_choices), gPopuriScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gPopuriScheduleData.table_storage[0], &gPopuriScheduleData.table_storage[1], &gPopuriScheduleData.table_storage[2],
        &gPopuriScheduleData.table_storage[3], &gPopuriScheduleData.table_storage[4], &gPopuriScheduleData.table_storage[5], &gPopuriScheduleData.table_storage[6],
        &gPopuriScheduleData.table_storage[7], &gPopuriScheduleData.table_storage[8], &gPopuriScheduleData.table_storage[9], &gPopuriScheduleData.table_storage[10],
        &gPopuriScheduleData.table_storage[11], &gPopuriScheduleData.table_storage[12], &gPopuriScheduleData.table_storage[13], &gPopuriScheduleData.table_storage[14],
        &gPopuriScheduleData.table_storage[15], &gPopuriScheduleData.table_storage[16], &gPopuriScheduleData.table_storage[17], &gPopuriScheduleData.table_storage[18],
        &gPopuriScheduleData.table_storage[19], &gPopuriScheduleData.table_storage[20], &gPopuriScheduleData.table_storage[21], &gPopuriScheduleData.table_storage[22],
    },
    // table_storage
    {
        { ARRAY_COUNT(gPopuriScheduleData.entries_0), gPopuriScheduleData.entries_0 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_1), gPopuriScheduleData.entries_1 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_2), gPopuriScheduleData.entries_2 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_3), gPopuriScheduleData.entries_3 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_4), gPopuriScheduleData.entries_4 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_5), gPopuriScheduleData.entries_5 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_6), gPopuriScheduleData.entries_6 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_7), gPopuriScheduleData.entries_7 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_8), gPopuriScheduleData.entries_8 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_9), gPopuriScheduleData.entries_9 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_10), gPopuriScheduleData.entries_10 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_11), gPopuriScheduleData.entries_11 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_12), gPopuriScheduleData.entries_12 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_13), gPopuriScheduleData.entries_13 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_14), gPopuriScheduleData.entries_14 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_15), gPopuriScheduleData.entries_15 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_16), gPopuriScheduleData.entries_16 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_17), gPopuriScheduleData.entries_17 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_18), gPopuriScheduleData.entries_18 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_19), gPopuriScheduleData.entries_19 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_20), gPopuriScheduleData.entries_20 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_21), gPopuriScheduleData.entries_21 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_22), gPopuriScheduleData.entries_22 },
    },
    // entries_0
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 60, &gPopuriScheduleData.payload_storage[1] },
        { 98, &gPopuriScheduleData.payload_storage[2] },
        { 113, &gPopuriScheduleData.payload_storage[3] },
        { 240, &gPopuriScheduleData.payload_storage[4] },
        { 256, &gPopuriScheduleData.payload_storage[5] },
        { 293, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_1
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_2
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 180, &gPopuriScheduleData.payload_storage[7] },
        { 227, &gPopuriScheduleData.payload_storage[8] },
        { 251, &gPopuriScheduleData.payload_storage[9] },
        { 421, &gPopuriScheduleData.payload_storage[10] },
        { 446, &gPopuriScheduleData.payload_storage[11] },
        { 462, &gPopuriScheduleData.payload_storage[12] },
        { 600, &gPopuriScheduleData.payload_storage[13] },
        { 608, &gPopuriScheduleData.payload_storage[14] },
        { 655, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_3
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 180, &gPopuriScheduleData.payload_storage[7] },
        { 227, &gPopuriScheduleData.payload_storage[8] },
        { 251, &gPopuriScheduleData.payload_storage[9] },
        { 600, &gPopuriScheduleData.payload_storage[10] },
        { 625, &gPopuriScheduleData.payload_storage[14] },
        { 672, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_4
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 420, &gPopuriScheduleData.payload_storage[7] },
        { 467, &gPopuriScheduleData.payload_storage[15] },
        { 486, &gPopuriScheduleData.payload_storage[16] },
        { 600, &gPopuriScheduleData.payload_storage[17] },
        { 620, &gPopuriScheduleData.payload_storage[14] },
        { 667, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_5
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_6
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 180, &gPopuriScheduleData.payload_storage[0] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_7
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_8
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_9
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 180, &gPopuriScheduleData.payload_storage[0] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_10
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_11
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_12
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_13
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_14
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_15
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
    },
    // entries_16
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 240, &gPopuriScheduleData.payload_storage[23] },
        { 250, &gPopuriScheduleData.payload_storage[21] },
        { 300, &gPopuriScheduleData.payload_storage[22] },
        { 310, &gPopuriScheduleData.payload_storage[0] },
    },
    // entries_17
    {
        { 0, &gPopuriScheduleData.payload_storage[23] },
        { 10, &gPopuriScheduleData.payload_storage[21] },
        { 60, &gPopuriScheduleData.payload_storage[22] },
        { 70, &gPopuriScheduleData.payload_storage[0] },
    },
    // entries_18
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
    },
    // entries_19
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 120, &gPopuriScheduleData.payload_storage[7] },
        { 167, &gPopuriScheduleData.payload_storage[15] },
        { 186, &gPopuriScheduleData.payload_storage[16] },
        { 240, &gPopuriScheduleData.payload_storage[17] },
        { 260, &gPopuriScheduleData.payload_storage[14] },
        { 307, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_20
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_21
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[24] },
    },
    // entries_22
    {
        { 0, &gPopuriScheduleData.payload_storage[20] },
    },
    // payload_storage
    {
        { gPopuriScheduleData.points_0, ARRAY_COUNT(gPopuriScheduleData.points_0), 168, 104, 10, 0, 1 },
        { gPopuriScheduleData.points_1, ARRAY_COUNT(gPopuriScheduleData.points_1), 572, 227, 7, 0, 0 },
        { gPopuriScheduleData.points_2, ARRAY_COUNT(gPopuriScheduleData.points_2), 1200, 528, 0, 0, 0 },
        { gPopuriScheduleData.points_3, ARRAY_COUNT(gPopuriScheduleData.points_3), 984, 416, 0, 0, 1 },
        { gPopuriScheduleData.points_4, ARRAY_COUNT(gPopuriScheduleData.points_4), 984, 416, 0, 0, 0 },
        { gPopuriScheduleData.points_5, ARRAY_COUNT(gPopuriScheduleData.points_5), 812, 512, 7, 0, 0 },
        { gPopuriScheduleData.points_6, ARRAY_COUNT(gPopuriScheduleData.points_6), 168, 72, 11, 0, 1 },
        { gPopuriScheduleData.points_7, ARRAY_COUNT(gPopuriScheduleData.points_7), 572, 227, 7, 0, 0 },
        { gPopuriScheduleData.points_8, ARRAY_COUNT(gPopuriScheduleData.points_8), 1260, 704, 5, 0, 0 },
        { gPopuriScheduleData.points_9, ARRAY_COUNT(gPopuriScheduleData.points_9), 248, 88, 12, 0, 1 },
        { gPopuriScheduleData.points_10, ARRAY_COUNT(gPopuriScheduleData.points_10), 1232, 156, 5, 0, 0 },
        { gPopuriScheduleData.points_11, ARRAY_COUNT(gPopuriScheduleData.points_11), 220, 0, 6, 0, 0 },
        { gPopuriScheduleData.points_12, ARRAY_COUNT(gPopuriScheduleData.points_12), 280, 352, 6, 0, 1 },
        { gPopuriScheduleData.points_13, ARRAY_COUNT(gPopuriScheduleData.points_13), 280, 352, 6, 0, 0 },
        { gPopuriScheduleData.points_14, ARRAY_COUNT(gPopuriScheduleData.points_14), 1272, 0, 7, 0, 0 },
        { gPopuriScheduleData.points_15, ARRAY_COUNT(gPopuriScheduleData.points_15), 0, 280, 1, 0, 0 },
        { nullptr, 0, 256, 232, 1, 3, 0 },
        { gPopuriScheduleData.points_17, ARRAY_COUNT(gPopuriScheduleData.points_17), 256, 232, 1, 0, 0 },
        { gPopuriScheduleData.points_18, ARRAY_COUNT(gPopuriScheduleData.points_18), 256, 152, 29, 0, 1 },
        { gPopuriScheduleData.points_19, ARRAY_COUNT(gPopuriScheduleData.points_19), 112, 76, 29, 0, 1 },
        { nullptr, 0, 440, -48, 29, 0, 0 },
        { nullptr, 0, 228, 145, 2, 1, 0 },
        { gPopuriScheduleData.points_22, ARRAY_COUNT(gPopuriScheduleData.points_22), 228, 145, 2, 0, 0 },
        { gPopuriScheduleData.points_23, ARRAY_COUNT(gPopuriScheduleData.points_23), 340, 0, 2, 0, 0 },
        { nullptr, 0, 0, 0, 564, 1, 0 },
    },
    // points_0
    {
        { 224, 2, 120, 3, 0 },
        { 168, 2, 120, 2, 0 },
    },
    // points_1
    {
        { 1, 248, 1 },
        { 5, 472, 0 },
        { 9, 152, 1 },
        { 23, 812, 0 },
        { 38, 544, 1 },
    },
    // points_2
    {
        { 1, 1176, 0 },
        { 2, 512, 1 },
        { 3, 1160, 0 },
        { 4, 496, 1 },
        { 5, 1144, 0 },
        { 6, 480, 1 },
        { 12, 984, 0 },
        { 15, 416, 1 },
    },
    // points_3
    {
        { 944, 2, 0, 0, 0 },
        { 374, 2, 120, 3, 1 },
        { 416, 2, 0, 0, 1 },
        { 984, 2, 120, 1, 0 },
    },
    // points_4
    {
        { 3, 480, 1 },
        { 9, 1144, 0 },
        { 10, 496, 1 },
        { 11, 1160, 0 },
        { 12, 512, 1 },
        { 13, 1176, 0 },
        { 14, 528, 1 },
        { 16, 1216, 0 },
    },
    // points_5
    {
        { 14, 152, 1 },
        { 28, 472, 0 },
        { 32, 248, 1 },
        { 36, 572, 0 },
        { 37, 227, 1 },
    },
    // points_6
    {
        { 138, 2, 120, 1, 1 },
        { 72, 2, 120, 0, 1 },
    },
    // points_7
    {
        { 1, 248, 1 },
        { 5, 472, 0 },
        { 9, 152, 1 },
        { 40, 1248, 0 },
        { 41, 128, 1 },
        { 42, 1272, 0 },
        { 47, 0, 1 },
    },
    // points_8
    {
        { 19, 240, 1 },
        { 20, 1248, 0 },
        { 21, 216, 1 },
        { 22, 1232, 0 },
        { 24, 156, 1 },
    },
    // points_9
    {
        { 280, 2, 120, 3, 0 },
        { 248, 2, 120, 2, 0 },
    },
    // points_10
    {
        { 2, 216, 1 },
        { 3, 1248, 0 },
        { 4, 240, 1 },
        { 5, 1260, 0 },
        { 25, 736, 1 },
    },
    // points_11
    {
        { 14, 352, 1 },
        { 16, 280, 0 },
    },
    // points_12
    {
        { 344, 2, 120, 3, 0 },
        { 280, 2, 120, 2, 0 },
    },
    // points_13
    {
        { 3, 220, 0 },
        { 8, 480, 1 },
    },
    // points_14
    {
        { 5, 128, 1 },
        { 6, 1248, 0 },
        { 7, 152, 1 },
        { 38, 472, 0 },
        { 42, 248, 1 },
        { 46, 572, 0 },
        { 47, 227, 1 },
    },
    // points_15
    {
        { 3, 64, 0 },
        { 6, 360, 1 },
        { 8, 104, 0 },
        { 13, 232, 1 },
        { 19, 256, 0 },
    },
    // points_17
    {
        { 6, 104, 0 },
        { 11, 360, 1 },
        { 13, 64, 0 },
        { 16, 280, 1 },
        { 20, -16, 0 },
    },
    // points_18
    {
        { 96, 2, 0, 0, 1 },
        { 328, 2, 120, 3, 0 },
        { 256, 2, 0, 0, 0 },
        { 152, 2, 120, 0, 1 },
    },
    // points_19
    {
        { 108, 2, 120, 2, 1 },
        { 128, 2, 120, 3, 0 },
        { 76, 2, 120, 3, 1 },
        { 112, 2, 120, 2, 0 },
    },
    // points_22
    {
        { 4, 340, 0 },
        { 10, 0, 1 },
    },
    // points_23
    {
        { 6, 145, 1 },
        { 10, 228, 0 },
    },
};
