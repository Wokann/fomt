#include "npc_schedule_harris.hh"
#include "game_state.hh"

extern "C" u32 SelectHarrisSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    if (save.event_state.elli_and_doctor_rival_wedding_routing_state)
        return 0;
    GameDayDate date;
    DecodeGameDayDate(&date, &save.clock.calendar);
    if ((u8)IsNpcScheduleDateListed(date.season, date.day))
        return 2;
    return 1;
}

extern "C" HarrisScheduleData const gHarrisScheduleData = {
    // descriptor
    {
        SelectHarrisSchedule,
        ARRAY_COUNT(gHarrisScheduleData.table_choices),
        gHarrisScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gHarrisScheduleData.table_storage[0],
        &gHarrisScheduleData.table_storage[1],
    },
    // table_storage
    {
        { ARRAY_COUNT(gHarrisScheduleData.entries_0), gHarrisScheduleData.entries_0 },
        { ARRAY_COUNT(gHarrisScheduleData.entries_1), gHarrisScheduleData.entries_1 },
    },
    // entries_0
    {
        { 0x00000000, &gHarrisScheduleData.payload_storage[0] },
        { 0x0000003C, &gHarrisScheduleData.payload_storage[1] },
        { 0x00000078, &gHarrisScheduleData.payload_storage[2] },
        { 0x00000091, &gHarrisScheduleData.payload_storage[4] },
        { 0x000000F0, &gHarrisScheduleData.payload_storage[3] },
        { 0x00000113, &gHarrisScheduleData.payload_storage[5] },
        { 0x0000012A, &gHarrisScheduleData.payload_storage[6] },
        { 0x000001A7, &gHarrisScheduleData.payload_storage[7] },
        { 0x000001BE, &gHarrisScheduleData.payload_storage[8] },
        { 0x000001E0, &gHarrisScheduleData.payload_storage[9] },
        { 0x00000258, &gHarrisScheduleData.payload_storage[10] },
        { 0x0000027D, &gHarrisScheduleData.payload_storage[0] },
        { 0x0000030C, &gHarrisScheduleData.payload_storage[11] },
        { 0x00000311, &gHarrisScheduleData.payload_storage[12] },
        { 0x000003C0, &gHarrisScheduleData.payload_storage[13] },
        { 0x000003C5, &gHarrisScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gHarrisScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gHarrisScheduleData.points_0, ARRAY_COUNT(gHarrisScheduleData.points_0), 152, 104, 30, 0, true },
        { gHarrisScheduleData.points_1, ARRAY_COUNT(gHarrisScheduleData.points_1), 480, 160, 5, 0, false },
        { gHarrisScheduleData.points_2, ARRAY_COUNT(gHarrisScheduleData.points_2), 1272, 0, 7, 0, false },
        { gHarrisScheduleData.points_3, ARRAY_COUNT(gHarrisScheduleData.points_3), 992, 232, 7, 0, false },
        { nullptr, 0, 160, 152, 41, 2, false },
        { gHarrisScheduleData.points_5, ARRAY_COUNT(gHarrisScheduleData.points_5), 832, 0, 3, 0, false },
        { nullptr, 0, 80, 160, 40, 3, false },
        { gHarrisScheduleData.points_7, ARRAY_COUNT(gHarrisScheduleData.points_7), 612, 244, 3, 0, false },
        { gHarrisScheduleData.points_8, ARRAY_COUNT(gHarrisScheduleData.points_8), 1260, 704, 5, 0, false },
        { nullptr, 0, 16, 224, 21, 3, false },
        { gHarrisScheduleData.points_10, ARRAY_COUNT(gHarrisScheduleData.points_10), 632, 488, 5, 0, false },
        { gHarrisScheduleData.points_11, ARRAY_COUNT(gHarrisScheduleData.points_11), 480, 160, 5, 0, false },
        { nullptr, 0, 440, 200, 5, 0, false },
        { gHarrisScheduleData.points_13, ARRAY_COUNT(gHarrisScheduleData.points_13), 440, 200, 5, 0, false },
    },
    // points_0
    {
        { 216, 2, 120, 3, false },
        { 152, 2, 120, 2, false },
    },
    // points_1
    {
        { 2, 216, true },
        { 38, 1248, false },
        { 39, 240, true },
        { 40, 1260, false },
        { 60, 736, true },
    },
    // points_2
    {
        { 5, 128, true },
        { 6, 1248, false },
        { 7, 152, true },
        { 15, 1060, false },
        { 20, 280, true },
        { 23, 992, false },
        { 25, 232, true },
    },
    // points_3
    {
        { 2, 280, true },
        { 5, 1060, false },
        { 10, 152, true },
        { 20, 812, false },
        { 35, 544, true },
    },
    // points_5
    {
        { 12, 296, true },
        { 21, 614, false },
        { 23, 244, true },
    },
    // points_7
    {
        { 2, 296, true },
        { 11, 832, false },
        { 23, 0, true },
    },
    // points_8
    {
        { 7, 536, true },
        { 32, 632, false },
        { 34, 488, true },
    },
    // points_10
    {
        { 2, 536, true },
        { 9, 808, false },
        { 22, 216, true },
        { 35, 480, false },
        { 37, 160, true },
    },
    // points_11
    {
        { 2, 216, true },
        { 4, 440, false },
        { 5, 200, true },
    },
    // points_13
    {
        { 1, 216, true },
        { 3, 480, false },
        { 5, 160, true },
    },
};
