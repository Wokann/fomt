#include "npc_schedule_thomas.hh"
#include "game_state.hh"

extern "C" u32 SelectThomasSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    GameDayDate date;
    u8 season;
    u8 day;
    u8 weekday;
    DecodeGameDayDate(&date, &save.clock.calendar);
    season = date.season;
    day = date.day;
    weekday = date.weekday;
    if (season == 3 && day == 2
        && save.event_state.thomas_random_item_request_event_state == 2
        && (u32)save.event_state.thomas_random_item_request_choice == 0)
    {
        if (save.event_state.thomas_random_item_request_delivery_state != 2)
            return 7;
        return 0;
    }
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 6;
    if (weekday == 6)
    {
        if (save.clock.weather_today == 0)
            return 2;
        else
            return 3;
    }
    if (weekday == 0)
    {
        if (save.clock.weather_today == 0)
            return 4;
        else
            return 5;
    }
    return 1;
}

extern "C" ThomasScheduleData const gThomasScheduleData = {
    // descriptor
    {
        SelectThomasSchedule,
        ARRAY_COUNT(gThomasScheduleData.table_choices),
        gThomasScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gThomasScheduleData.table_storage[0],
        &gThomasScheduleData.table_storage[1],
        &gThomasScheduleData.table_storage[2],
        &gThomasScheduleData.table_storage[3],
        &gThomasScheduleData.table_storage[4],
        &gThomasScheduleData.table_storage[5],
        &gThomasScheduleData.table_storage[6],
    },
    // table_storage
    {
        { ARRAY_COUNT(gThomasScheduleData.entries_0), gThomasScheduleData.entries_0 },
        { ARRAY_COUNT(gThomasScheduleData.entries_1), gThomasScheduleData.entries_1 },
        { ARRAY_COUNT(gThomasScheduleData.entries_2), gThomasScheduleData.entries_2 },
        { ARRAY_COUNT(gThomasScheduleData.entries_3), gThomasScheduleData.entries_3 },
        { ARRAY_COUNT(gThomasScheduleData.entries_4), gThomasScheduleData.entries_4 },
        { ARRAY_COUNT(gThomasScheduleData.entries_5), gThomasScheduleData.entries_5 },
        { ARRAY_COUNT(gThomasScheduleData.entries_6), gThomasScheduleData.entries_6 },
    },
    // entries_0
    {
        { 0x00000000, &gThomasScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gThomasScheduleData.payload_storage[0] },
        { 0x0000003F, &gThomasScheduleData.payload_storage[1] },
        { 0x0000004C, &gThomasScheduleData.payload_storage[2] },
        { 0x000000F6, &gThomasScheduleData.payload_storage[3] },
        { 0x00000106, &gThomasScheduleData.payload_storage[4] },
        { 0x000001A9, &gThomasScheduleData.payload_storage[5] },
        { 0x000001E3, &gThomasScheduleData.payload_storage[6] },
        { 0x000001E9, &gThomasScheduleData.payload_storage[7] },
        { 0x00000260, &gThomasScheduleData.payload_storage[8] },
        { 0x00000266, &gThomasScheduleData.payload_storage[9] },
        { 0x0000029C, &gThomasScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gThomasScheduleData.payload_storage[0] },
        { 0x0000003F, &gThomasScheduleData.payload_storage[1] },
        { 0x0000004C, &gThomasScheduleData.payload_storage[2] },
        { 0x000000F4, &gThomasScheduleData.payload_storage[3] },
        { 0x00000104, &gThomasScheduleData.payload_storage[4] },
        { 0x000001A4, &gThomasScheduleData.payload_storage[10] },
        { 0x000001CC, &gThomasScheduleData.payload_storage[11] },
        { 0x0000025D, &gThomasScheduleData.payload_storage[12] },
        { 0x00000282, &gThomasScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gThomasScheduleData.payload_storage[0] },
        { 0x000000F0, &gThomasScheduleData.payload_storage[13] },
        { 0x000000F7, &gThomasScheduleData.payload_storage[4] },
        { 0x000001A6, &gThomasScheduleData.payload_storage[5] },
        { 0x000001E0, &gThomasScheduleData.payload_storage[6] },
        { 0x000001E6, &gThomasScheduleData.payload_storage[7] },
        { 0x00000260, &gThomasScheduleData.payload_storage[8] },
        { 0x00000266, &gThomasScheduleData.payload_storage[9] },
        { 0x0000029C, &gThomasScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gThomasScheduleData.payload_storage[0] },
        { 0x000000F0, &gThomasScheduleData.payload_storage[13] },
        { 0x000000F7, &gThomasScheduleData.payload_storage[4] },
        { 0x000001A4, &gThomasScheduleData.payload_storage[10] },
        { 0x000001CC, &gThomasScheduleData.payload_storage[11] },
        { 0x0000025A, &gThomasScheduleData.payload_storage[12] },
        { 0x0000027F, &gThomasScheduleData.payload_storage[0] },
    },
    // entries_5
    {
        { 0x00000000, &gThomasScheduleData.payload_storage[0] },
    },
    // entries_6
    {
        { 0x00000000, &gThomasScheduleData.payload_storage[17] },
        { 0x0000030C, &gThomasScheduleData.payload_storage[14] },
        { 0x00000316, &gThomasScheduleData.payload_storage[15] },
        { 0x00000348, &gThomasScheduleData.payload_storage[16] },
        { 0x00000352, &gThomasScheduleData.payload_storage[17] },
    },
    // payload_storage
    {
        { nullptr, 0, 120, 104, 30, 0, false },
        { gThomasScheduleData.points_1, ARRAY_COUNT(gThomasScheduleData.points_1), 480, 160, 5, 0, false },
        { nullptr, 0, 88, 216, 15, 0, false },
        { gThomasScheduleData.points_3, ARRAY_COUNT(gThomasScheduleData.points_3), 688, 160, 5, 0, false },
        { nullptr, 0, 128, 136, 14, 1, false },
        { gThomasScheduleData.points_5, ARRAY_COUNT(gThomasScheduleData.points_5), 400, 160, 5, 0, false },
        { gThomasScheduleData.points_6, ARRAY_COUNT(gThomasScheduleData.points_6), 220, 0, 6, 0, false },
        { nullptr, 0, 148, 80, 6, 1, false },
        { gThomasScheduleData.points_8, ARRAY_COUNT(gThomasScheduleData.points_8), 148, 80, 6, 0, false },
        { gThomasScheduleData.points_9, ARRAY_COUNT(gThomasScheduleData.points_9), 1260, 704, 5, 0, false },
        { gThomasScheduleData.points_10, ARRAY_COUNT(gThomasScheduleData.points_10), 400, 160, 5, 0, false },
        { nullptr, 0, 81, 235, 21, 3, false },
        { gThomasScheduleData.points_12, ARRAY_COUNT(gThomasScheduleData.points_12), 632, 488, 5, 0, false },
        { gThomasScheduleData.points_13, ARRAY_COUNT(gThomasScheduleData.points_13), 480, 160, 5, 0, false },
        { gThomasScheduleData.points_14, ARRAY_COUNT(gThomasScheduleData.points_14), 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gThomasScheduleData.points_16, ARRAY_COUNT(gThomasScheduleData.points_16), 228, 145, 2, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
    },
    // points_1
    {
        { 2, 216, true },
        { 11, 688, false },
        { 13, 160, true },
    },
    // points_3
    {
        { 2, 216, true },
        { 14, 400, false },
        { 16, 160, true },
    },
    // points_5
    {
        { 2, 216, true },
        { 36, 1248, false },
        { 37, 240, true },
        { 38, 1260, false },
        { 58, 736, true },
    },
    // points_6
    {
        { 3, 80, true },
        { 6, 148, false },
    },
    // points_8
    {
        { 3, 220, false },
        { 6, 0, true },
    },
    // points_9
    {
        { 19, 240, true },
        { 20, 1248, false },
        { 21, 216, true },
        { 52, 480, false },
        { 54, 160, true },
    },
    // points_10
    {
        { 2, 216, true },
        { 18, 808, false },
        { 31, 536, true },
        { 38, 632, false },
        { 40, 488, true },
    },
    // points_12
    {
        { 2, 536, true },
        { 9, 808, false },
        { 22, 216, true },
        { 35, 480, false },
        { 37, 160, true },
    },
    // points_13
    {
        { 2, 216, true },
        { 5, 400, false },
        { 7, 160, true },
    },
    // points_14
    {
        { 6, 145, true },
        { 10, 228, false },
    },
    // points_16
    {
        { 4, 340, false },
        { 10, 0, true },
    },
};
