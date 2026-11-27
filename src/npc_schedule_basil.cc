#include "npc_schedule_basil.hh"
#include "game_state.hh"

extern "C" u32 SelectBasilSchedule(void const * context)
{
    GameStateSaveImage const & save = *(GameStateSaveImage const *)context;
    GameDayDate date;
    u8 season;
    u8 day;
    u8 weekday;
    u32 rival_wedding;

    rival_wedding = save.event_state.mary_and_gray_rival_wedding_routing_state;

    if (rival_wedding != 0)
        return 0;

    DecodeGameDayDate(&date, &save.clock.calendar);

    season = date.season;
    day = date.day;
    weekday = date.weekday;

    if (IsNpcScheduleDateListed(season, day) << 0x18)
        return 4;

    if (weekday == 1)
    {
        if (save.clock.weather_today == 0)
            return 2;

        return 3;
    }

    return 1;
}

extern "C" BasilScheduleData const gBasilScheduleData = {
    // descriptor
    {
        SelectBasilSchedule,
        ARRAY_COUNT(gBasilScheduleData.table_choices),
        gBasilScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gBasilScheduleData.table_storage[0],
        &gBasilScheduleData.table_storage[1],
        &gBasilScheduleData.table_storage[2],
        &gBasilScheduleData.table_storage[3],
    },
    // table_storage
    {
        { ARRAY_COUNT(gBasilScheduleData.entries_0), gBasilScheduleData.entries_0 },
        { ARRAY_COUNT(gBasilScheduleData.entries_1), gBasilScheduleData.entries_1 },
        { ARRAY_COUNT(gBasilScheduleData.entries_2), gBasilScheduleData.entries_2 },
        { ARRAY_COUNT(gBasilScheduleData.entries_3), gBasilScheduleData.entries_3 },
    },
    // entries_0
    {
        { 0x00000000, &gBasilScheduleData.payload_storage[1] },
        { 0x000000F0, &gBasilScheduleData.payload_storage[0] },
        { 0x000001A4, &gBasilScheduleData.payload_storage[1] },
        { 0x00000258, &gBasilScheduleData.payload_storage[0] },
        { 0x0000030C, &gBasilScheduleData.payload_storage[2] },
        { 0x00000336, &gBasilScheduleData.payload_storage[3] },
        { 0x000003C6, &gBasilScheduleData.payload_storage[4] },
        { 0x000003F0, &gBasilScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gBasilScheduleData.payload_storage[1] },
        { 0x0000003C, &gBasilScheduleData.payload_storage[8] },
        { 0x00000057, &gBasilScheduleData.payload_storage[5] },
        { 0x00000092, &gBasilScheduleData.payload_storage[6] },
        { 0x000000F1, &gBasilScheduleData.payload_storage[7] },
        { 0x0000012C, &gBasilScheduleData.payload_storage[9] },
        { 0x00000146, &gBasilScheduleData.payload_storage[0] },
        { 0x000001A4, &gBasilScheduleData.payload_storage[1] },
        { 0x00000258, &gBasilScheduleData.payload_storage[0] },
        { 0x0000030C, &gBasilScheduleData.payload_storage[2] },
        { 0x00000336, &gBasilScheduleData.payload_storage[3] },
        { 0x000003C6, &gBasilScheduleData.payload_storage[4] },
        { 0x000003F0, &gBasilScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0x00000000, &gBasilScheduleData.payload_storage[1] },
        { 0x000000F0, &gBasilScheduleData.payload_storage[0] },
        { 0x000001A4, &gBasilScheduleData.payload_storage[1] },
        { 0x00000258, &gBasilScheduleData.payload_storage[0] },
        { 0x0000030C, &gBasilScheduleData.payload_storage[2] },
        { 0x00000336, &gBasilScheduleData.payload_storage[3] },
        { 0x000003C6, &gBasilScheduleData.payload_storage[4] },
        { 0x000003F0, &gBasilScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0x00000000, &gBasilScheduleData.payload_storage[1] },
    },
    // payload_storage
    {
        { gBasilScheduleData.points_0, ARRAY_COUNT(gBasilScheduleData.points_0), 24, 168, 26, 0, true },
        { nullptr, 0, 32, 88, 27, 1, false },
        { gBasilScheduleData.points_2, ARRAY_COUNT(gBasilScheduleData.points_2), 200, 160, 5, 0, false },
        { nullptr, 0, 127, 223, 21, 0, false },
        { gBasilScheduleData.points_4, ARRAY_COUNT(gBasilScheduleData.points_4), 632, 488, 5, 0, false },
        { gBasilScheduleData.points_5, ARRAY_COUNT(gBasilScheduleData.points_5), 1200, 752, 0, 0, false },
        { nullptr, 0, 280, 168, 0, 0, false },
        { gBasilScheduleData.points_7, ARRAY_COUNT(gBasilScheduleData.points_7), 280, 168, 0, 0, false },
        { gBasilScheduleData.points_8, ARRAY_COUNT(gBasilScheduleData.points_8), 200, 160, 5, 0, false },
        { gBasilScheduleData.points_9, ARRAY_COUNT(gBasilScheduleData.points_9), 104, 704, 5, 0, false },
    },
    // points_0
    {
        { 80, 2, 120, 3, false },
        { 24, 2, 120, 2, false },
    },
    // points_2
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 7, 104, false },
        { 19, 536, true },
        { 40, 632, false },
        { 42, 488, true },
    },
    // points_4
    {
        { 2, 536, true },
        { 23, 104, false },
        { 35, 240, true },
        { 37, 144, false },
        { 38, 216, true },
        { 40, 200, false },
        { 42, 160, true },
    },
    // points_5
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
        { 59, 280, false },
    },
    // points_7
    {
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
    // points_8
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 7, 104, false },
        { 27, 734, true },
    },
    // points_9
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 24, 200, false },
        { 26, 160, true },
    },
};
