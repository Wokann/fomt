#include "npc_schedule_sasha.hh"
#include "game_state.hh"

extern "C" u32 SelectSashaSchedule(void const * context)
{
    GameStateSaveImage const & save = *(GameStateSaveImage const *)context;
    GameDayDate date;
    u8 season;
    u8 day;
    u8 weekday;
    u32 rival_wedding;

    rival_wedding = save.event_state.rick_and_karen_rival_wedding_routing_state;

    if (rival_wedding != 0)
        return 0;

    DecodeGameDayDate(&date, &save.clock.calendar);

    season = date.season;
    day = date.day;
    weekday = date.weekday;

    if (IsNpcScheduleDateListed(season, day) << 0x18)
        return 4;

    if (save.clock.weather_today == 0)
    {
        if (weekday == 2)
            return 3;

        return 1;
    }

    return 2;
}

// The next ROM object has five choices, of which the first is null. Keep its
// tables, entry records, payloads, and detail records contiguous and ordered.
extern "C" SashaScheduleData const gSashaScheduleData = {
    // descriptor
    {
        SelectSashaSchedule,
        ARRAY_COUNT(gSashaScheduleData.table_choices),
        gSashaScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gSashaScheduleData.table_storage[0],
        &gSashaScheduleData.table_storage[1],
        &gSashaScheduleData.table_storage[2],
        &gSashaScheduleData.table_storage[3],
    },
    // table_storage
    {
        { ARRAY_COUNT(gSashaScheduleData.entries_0), gSashaScheduleData.entries_0 },
        { ARRAY_COUNT(gSashaScheduleData.entries_1), gSashaScheduleData.entries_1 },
        { ARRAY_COUNT(gSashaScheduleData.entries_2), gSashaScheduleData.entries_2 },
        { ARRAY_COUNT(gSashaScheduleData.entries_3), gSashaScheduleData.entries_3 },
    },
    // entries_0
    {
        { 0x0000, &gSashaScheduleData.payload_storage[0] },
        { 0x01A4, &gSashaScheduleData.payload_storage[1] },
        { 0x01D2, &gSashaScheduleData.payload_storage[2] },
        { 0x01D9, &gSashaScheduleData.payload_storage[3] },
        { 0x0258, &gSashaScheduleData.payload_storage[4] },
        { 0x025F, &gSashaScheduleData.payload_storage[5] },
        { 0x028C, &gSashaScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x0000, &gSashaScheduleData.payload_storage[0] },
        { 0x01A4, &gSashaScheduleData.payload_storage[12] },
        { 0x0258, &gSashaScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x0000, &gSashaScheduleData.payload_storage[0] },
        { 0x003C, &gSashaScheduleData.payload_storage[1] },
        { 0x006A, &gSashaScheduleData.payload_storage[6] },
        { 0x0083, &gSashaScheduleData.payload_storage[7] },
        { 0x00F3, &gSashaScheduleData.payload_storage[8] },
        { 0x011E, &gSashaScheduleData.payload_storage[9] },
        { 0x01A7, &gSashaScheduleData.payload_storage[10] },
        { 0x01C5, &gSashaScheduleData.payload_storage[11] },
        { 0x01E7, &gSashaScheduleData.payload_storage[13] },
        { 0x0258, &gSashaScheduleData.payload_storage[14] },
        { 0x0268, &gSashaScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x0000, &gSashaScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gSashaScheduleData.points_0, ARRAY_COUNT(gSashaScheduleData.points_0), 136, 80, 16, 0, true },
        { gSashaScheduleData.points_1, ARRAY_COUNT(gSashaScheduleData.points_1), 688, 160, 5, 0, false },
        { gSashaScheduleData.points_2, ARRAY_COUNT(gSashaScheduleData.points_2), 220, 0, 6, 0, false },
        { nullptr, 0, 328, 80, 6, 0, false },
        { gSashaScheduleData.points_4, ARRAY_COUNT(gSashaScheduleData.points_4), 328, 80, 6, 0, false },
        { gSashaScheduleData.points_5, ARRAY_COUNT(gSashaScheduleData.points_5), 1260, 704, 5, 0, false },
        { gSashaScheduleData.points_6, ARRAY_COUNT(gSashaScheduleData.points_6), 1272, 0, 7, 0, false },
        { nullptr, 0, 120, 120, 41, 0, false },
        { gSashaScheduleData.points_8, ARRAY_COUNT(gSashaScheduleData.points_8), 992, 234, 7, 0, false },
        { nullptr, 0, 192, 138, 10, 0, false },
        { gSashaScheduleData.points_10, ARRAY_COUNT(gSashaScheduleData.points_10), 572, 227, 7, 0, false },
        { gSashaScheduleData.points_11, ARRAY_COUNT(gSashaScheduleData.points_11), 104, 704, 5, 0, false },
        { gSashaScheduleData.points_12, ARRAY_COUNT(gSashaScheduleData.points_12), 256, 80, 15, 0, true },
        { nullptr, 0, 112, 136, 14, 1, false },
        { gSashaScheduleData.points_14, ARRAY_COUNT(gSashaScheduleData.points_14), 400, 160, 5, 0, false },
    },
    // points_0
    {
        { 272, 2, 120, 3, false },
        { 136, 2, 120, 2, false },
    },
    // points_1
    {
        { 2, 216, true },
        { 24, 1248, false },
        { 25, 240, true },
        { 26, 1260, false },
        { 46, 736, true },
    },
    // points_2
    {
        { 3, 80, true },
        { 7, 328, false },
    },
    // points_4
    {
        { 4, 220, false },
        { 7, 0, true },
    },
    // points_5
    {
        { 19, 240, true },
        { 20, 1248, false },
        { 21, 216, true },
        { 43, 688, false },
        { 45, 160, true },
    },
    // points_6
    {
        { 5, 128, true },
        { 6, 1248, false },
        { 7, 152, true },
        { 15, 1060, false },
        { 20, 280, true },
        { 23, 992, false },
        { 25, 232, true },
    },
    // points_8
    {
        { 2, 280, true },
        { 5, 1060, false },
        { 10, 152, true },
        { 34, 472, false },
        { 38, 248, true },
        { 42, 572, false },
        { 43, 227, true },
    },
    // points_10
    {
        { 1, 248, true },
        { 5, 472, false },
        { 9, 152, true },
        { 24, 104, false },
        { 30, 0, true },
    },
    // points_11
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 32, 400, false },
        { 34, 160, true },
    },
    // points_12
    {
        { 200, 2, 120, 2, false },
        { 256, 2, 120, 3, false },
    },
    // points_14
    {
        { 2, 216, true },
        { 14, 688, false },
        { 16, 160, true },
    },
};
