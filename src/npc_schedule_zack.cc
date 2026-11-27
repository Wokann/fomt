#include "npc_schedule_zack.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

extern "C" u32 SelectZackSchedule(void const * context)
{
    u8 date[4];
    u8 const * raw;
    raw = date;
    DecodeGameDayDate((GameDayDate *)date,
        (GameCalendar const *)((u8 const *)context + 16));
    if ((u8)IsNpcScheduleDateListed(raw[1], raw[2]))
        return 2;
    return 1;
}

asm_unified(
    "    .align 2, 0\n"
);

// Recovered schedule data at US ROM 0x080F2DC0 (JP 0x080F261C).
// The two regional payloads differ only in relocated function/data pointers.

extern "C" ZackScheduleData const gZackScheduleData = {
    // descriptor
    { SelectZackSchedule, ARRAY_COUNT(gZackScheduleData.table_choices), gZackScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gZackScheduleData.table_storage[0], &gZackScheduleData.table_storage[1],
    },
    // table_storage
    {
        { ARRAY_COUNT(gZackScheduleData.entries_0), gZackScheduleData.entries_0 },
        { ARRAY_COUNT(gZackScheduleData.entries_1), gZackScheduleData.entries_1 },
    },
    // entries_0
    {
        { 0, &gZackScheduleData.payload_storage[0] },
        { 60, &gZackScheduleData.payload_storage[1] },
        { 82, &gZackScheduleData.payload_storage[2] },
        { 127, &gZackScheduleData.payload_storage[3] },
        { 240, &gZackScheduleData.payload_storage[4] },
        { 286, &gZackScheduleData.payload_storage[5] },
        { 308, &gZackScheduleData.payload_storage[0] },
        { 630, &gZackScheduleData.payload_storage[1] },
        { 652, &gZackScheduleData.payload_storage[6] },
        { 663, &gZackScheduleData.payload_storage[7] },
        { 720, &gZackScheduleData.payload_storage[8] },
        { 731, &gZackScheduleData.payload_storage[9] },
        { 786, &gZackScheduleData.payload_storage[10] },
        { 833, &gZackScheduleData.payload_storage[5] },
        { 855, &gZackScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0, &gZackScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gZackScheduleData.points_0, ARRAY_COUNT(gZackScheduleData.points_0), 176, 88, 13, 0, 1 },
        { gZackScheduleData.points_1, ARRAY_COUNT(gZackScheduleData.points_1), 212, 108, 1, 0, 0 },
        { gZackScheduleData.points_2, ARRAY_COUNT(gZackScheduleData.points_2), 1260, 704, 5, 0, 0 },
        { nullptr, 0, 232, 264, 15, 2, 0 },
        { gZackScheduleData.points_4, ARRAY_COUNT(gZackScheduleData.points_4), 688, 160, 5, 0, 0 },
        { gZackScheduleData.points_5, ARRAY_COUNT(gZackScheduleData.points_5), 0, 280, 1, 0, 0 },
        { gZackScheduleData.points_6, ARRAY_COUNT(gZackScheduleData.points_6), 340, 0, 2, 0, 0 },
        { nullptr, 0, 244, 171, 2, 0, 0 },
        { gZackScheduleData.points_8, ARRAY_COUNT(gZackScheduleData.points_8), 244, 171, 2, 0, 0 },
        { nullptr, 0, 88, 88, 38, 0, 0 },
        { gZackScheduleData.points_10, ARRAY_COUNT(gZackScheduleData.points_10), 296, 116, 7, 0, 0 },
    },
    // points_0
    {
        { 128, 2, 120, 0, 0 },
        { 176, 2, 120, 0, 0 },
    },
    // points_1
    {
        { 1, 136, 1 },
        { 5, 104, 0 },
        { 14, 360, 1 },
        { 16, 64, 0 },
        { 19, 280, 1 },
        { 22, 0, 0 },
    },
    // points_2
    {
        { 19, 240, 1 },
        { 20, 1248, 0 },
        { 21, 216, 1 },
        { 43, 688, 0 },
        { 45, 160, 1 },
    },
    // points_4
    {
        { 2, 216, 1 },
        { 24, 1248, 0 },
        { 25, 240, 1 },
        { 26, 1260, 0 },
        { 46, 736, 1 },
    },
    // points_5
    {
        { 3, 64, 0 },
        { 6, 360, 1 },
        { 8, 104, 0 },
        { 17, 136, 1 },
        { 21, 212, 0 },
        { 22, 108, 1 },
    },
    // points_6
    {
        { 6, 145, 1 },
        { 10, 244, 0 },
        { 11, 171, 1 },
    },
    // points_8
    {
        { 1, 145, 1 },
        { 5, 340, 0 },
        { 11, 0, 1 },
    },
    // points_10
    {
        { 2, 152, 1 },
        { 40, 1248, 0 },
        { 41, 128, 1 },
        { 42, 1272, 0 },
        { 47, 0, 1 },
    },
};
