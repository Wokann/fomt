#include "npc_schedule_doug.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

#include "npc_collection.hh"
extern "C" u32 SelectDougSchedule(void const * context)
{
    u8 date[4];
    u8 const * raw;
    u8 season;
    u8 day;
    u32 spouse;
    if ((i32)(((u8 const *)context)[0x21CA] << 25) < 0)
        return 0;
    raw = date;
    DecodeGameDayDate((GameDayDate *)date,
        (GameCalendar const *)((u8 const *)context + 16));
    season = raw[1];
    day = raw[2];
    if ((u8)IsNpcScheduleDateListed(season, day))
        return 2;
    /* Offset form kept on purpose: +0x1CD4 is GameStateSaveImage::npcs
       (confirmed by the offsetof check in game_state_types.hh). Writing
       it as &save->npcs changes register allocation (r5 -> r1) and stops
       matching; see PROGRESS round 180. Tracked as a pending struct fix. */
    spouse = ((NpcCollection const *)((u8 const *)context + 0x1CD4))->GetSpouseCharacterId();
    if (season == 2 && day == 5 && spouse != 25)
        return 3;
    return 1;
}

asm_unified(
    "    .align 2, 0\n"
);

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
