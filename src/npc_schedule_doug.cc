#include "npc_schedule_doug.hh"
#include "game_state.hh"
#include "npc_collection.hh"
extern "C" u32 SelectDougSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    GameDayDate date;
    u8 season;
    u8 day;
    u32 spouse;

    if (save.event_state.ann_and_cliff_rival_wedding_routing_state)
        return 0;
    DecodeGameDayDate(&date, &save.clock.calendar);
    season = date.season;
    day = date.day;
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 2;
    spouse = save.npcs.GetSpouseCharacterId();
    if (season == 2 && day == 5 && spouse != 25)
        return 3;
    return 1;
}

// The following selector descriptors were recovered from the contiguous
// script-adjacent UI resource block.  Their nested C++ objects preserve every
// original internal pointer as a relocation rather than a ROM address.

extern "C" DougScheduleData const gDougScheduleData = {
    // descriptor
    {
        SelectDougSchedule,
        ARRAY_COUNT(gDougScheduleData.table_choices),
        gDougScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gDougScheduleData.table_storage[0],
        &gDougScheduleData.table_storage[1],
        &gDougScheduleData.table_storage[2],
    },
    // table_storage
    {
        { ARRAY_COUNT(gDougScheduleData.entries_0), gDougScheduleData.entries_0 },
        { ARRAY_COUNT(gDougScheduleData.entries_1), gDougScheduleData.entries_1 },
        { ARRAY_COUNT(gDougScheduleData.entries_2), gDougScheduleData.entries_2 },
    },
    // entries_0
    {
        { 0x00000000, &gDougScheduleData.payload_storage[0] },
        { 0x00000078, &gDougScheduleData.payload_storage[1] },
        { 0x000001A4, &gDougScheduleData.payload_storage[2] },
        { 0x0000021C, &gDougScheduleData.payload_storage[1] },
        { 0x0000030C, &gDougScheduleData.payload_storage[2] },
        { 0x00000384, &gDougScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gDougScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gDougScheduleData.payload_storage[3] },
        { 0x00000294, &gDougScheduleData.payload_storage[4] },
        { 0x0000029F, &gDougScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gDougScheduleData.points_0, ARRAY_COUNT(gDougScheduleData.points_0), 304, 88, 22, 0, true },
        { nullptr, 0, 315, 80, 21, 0, false },
        { nullptr, 0, 48, 80, 22, 1, false },
        { nullptr, 0, 200, 280, 8, 1, false },
        { gDougScheduleData.points_4, ARRAY_COUNT(gDougScheduleData.points_4), 200, 280, 8, 0, false },
    },
    // points_0
    {
        { 170, 2, 120, 0, true },
        { 88, 2, 120, 1, true },
    },
    // points_4
    {
        { 2, 240, false },
        { 11, 512, true },
    },
};
