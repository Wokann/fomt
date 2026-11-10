#include "npc_schedule_duke.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectDukeSchedule\n"
    "SelectDukeSchedule:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    adds\tr6, r4, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E60C\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E60C:\n"
    "    ldr r1, .Ljp_0803E61C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E620\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E61C: .word 0x000021CA\n"
    ".Ljp_0803E620:\n"
    "    ldr r1, .Ljp_0803E63C\n"
    "    adds\tr0, r5, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    movs\tr1, #194\t@ 0xc2\n"
    "    lsls\tr1, r1, #11\n"
    "    ands\tr0, r1\n"
    "    movs\tr1, #130\t@ 0x82\n"
    "    lsls\tr1, r1, #11\n"
    "    cmp\tr0, r1\n"
    "    bne .Ljp_0803E644\n"
    "    cmp\tr4, #6\n"
    "    bne .Ljp_0803E640\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E63C: .word 0x00002174\n"
    ".Ljp_0803E640:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E644:\n"
    "    cmp\tr6, #6\n"
    "    beq .Ljp_0803E64C\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E64C:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803E64E:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

extern "C" DukeScheduleData const gDukeScheduleData = {
    // descriptor
    {
        SelectDukeSchedule,
        ARRAY_COUNT(gDukeScheduleData.table_choices),
        gDukeScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gDukeScheduleData.table_storage[0],
        &gDukeScheduleData.table_storage[1],
        &gDukeScheduleData.table_storage[2],
        &gDukeScheduleData.table_storage[3],
        &gDukeScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gDukeScheduleData.entries_0), gDukeScheduleData.entries_0 },
        { ARRAY_COUNT(gDukeScheduleData.entries_1), gDukeScheduleData.entries_1 },
        { ARRAY_COUNT(gDukeScheduleData.entries_2), gDukeScheduleData.entries_2 },
        { ARRAY_COUNT(gDukeScheduleData.entries_3), gDukeScheduleData.entries_3 },
        { ARRAY_COUNT(gDukeScheduleData.entries_4), gDukeScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
        { 0x0000003C, &gDukeScheduleData.payload_storage[0] },
        { 0x000000F0, &gDukeScheduleData.payload_storage[5] },
        { 0x000000F6, &gDukeScheduleData.payload_storage[2] },
        { 0x000001E0, &gDukeScheduleData.payload_storage[3] },
        { 0x000001E5, &gDukeScheduleData.payload_storage[4] },
        { 0x00000294, &gDukeScheduleData.payload_storage[6] },
        { 0x0000029D, &gDukeScheduleData.payload_storage[0] },
        { 0x0000030C, &gDukeScheduleData.payload_storage[7] },
        { 0x00000320, &gDukeScheduleData.payload_storage[8] },
        { 0x000003C3, &gDukeScheduleData.payload_storage[9] },
        { 0x000003D7, &gDukeScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
        { 0x0000003C, &gDukeScheduleData.payload_storage[0] },
        { 0x000001A4, &gDukeScheduleData.payload_storage[7] },
        { 0x000001B8, &gDukeScheduleData.payload_storage[8] },
        { 0x0000025B, &gDukeScheduleData.payload_storage[9] },
        { 0x0000026F, &gDukeScheduleData.payload_storage[0] },
        { 0x000003C0, &gDukeScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
        { 0x0000003C, &gDukeScheduleData.payload_storage[0] },
        { 0x000001A7, &gDukeScheduleData.payload_storage[5] },
        { 0x000001AD, &gDukeScheduleData.payload_storage[2] },
        { 0x0000021C, &gDukeScheduleData.payload_storage[3] },
        { 0x00000221, &gDukeScheduleData.payload_storage[4] },
        { 0x00000294, &gDukeScheduleData.payload_storage[6] },
        { 0x0000029D, &gDukeScheduleData.payload_storage[0] },
        { 0x0000030C, &gDukeScheduleData.payload_storage[7] },
        { 0x00000320, &gDukeScheduleData.payload_storage[8] },
        { 0x000003C3, &gDukeScheduleData.payload_storage[9] },
        { 0x000003D7, &gDukeScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
        { 0x0000003C, &gDukeScheduleData.payload_storage[0] },
        { 0x000001A4, &gDukeScheduleData.payload_storage[7] },
        { 0x000001B8, &gDukeScheduleData.payload_storage[8] },
        { 0x00000260, &gDukeScheduleData.payload_storage[10] },
        { 0x0000028C, &gDukeScheduleData.payload_storage[11] },
        { 0x00000312, &gDukeScheduleData.payload_storage[12] },
        { 0x0000034E, &gDukeScheduleData.payload_storage[0] },
        { 0x000003DD, &gDukeScheduleData.payload_storage[1] },
    },
    // entries_4
    {
        { 0x00000000, &gDukeScheduleData.payload_storage[1] },
    },
    // payload_storage
    {
        { gDukeScheduleData.points_0, ARRAY_COUNT(gDukeScheduleData.points_0), 40, 168, 31, 0, true },
        { nullptr, 0, 32, 152, 32, 0, false },
        { gDukeScheduleData.points_2, ARRAY_COUNT(gDukeScheduleData.points_2), 24, 80, 34, 0, true },
        { gDukeScheduleData.points_3, ARRAY_COUNT(gDukeScheduleData.points_3), 314, 456, 5, 0, false },
        { nullptr, 0, 408, 476, 5, 1, false },
        { gDukeScheduleData.points_5, ARRAY_COUNT(gDukeScheduleData.points_5), 232, 484, 5, 0, false },
        { gDukeScheduleData.points_6, ARRAY_COUNT(gDukeScheduleData.points_6), 408, 476, 5, 0, false },
        { gDukeScheduleData.points_7, ARRAY_COUNT(gDukeScheduleData.points_7), 232, 476, 5, 0, false },
        { nullptr, 0, 16, 147, 21, 3, false },
        { gDukeScheduleData.points_9, ARRAY_COUNT(gDukeScheduleData.points_9), 632, 488, 5, 0, false },
        { gDukeScheduleData.points_10, ARRAY_COUNT(gDukeScheduleData.points_10), 632, 488, 5, 0, false },
        { nullptr, 0, 104, 195, 12, 1, false },
        { gDukeScheduleData.points_12, ARRAY_COUNT(gDukeScheduleData.points_12), 1232, 160, 5, 0, false },
    },
    // points_0
    {
        { 88, 2, 120, 3, false },
        { 40, 2, 120, 2, false },
    },
    // points_2
    {
        { 56, 2, 240, 1, false },
        { 24, 2, 240, 1, false },
    },
    // points_3
    {
        { 1, 476, true },
        { 5, 408, false },
    },
    // points_5
    {
        { 1, 496, true },
        { 2, 265, false },
        { 3, 476, true },
        { 5, 316, false },
        { 6, 460, true },
    },
    // points_6
    {
        { 6, 265, false },
        { 7, 496, true },
        { 8, 232, false },
        { 9, 484, true },
    },
    // points_7
    {
        { 2, 536, true },
        { 18, 632, false },
        { 20, 484, true },
    },
    // points_9
    {
        { 2, 536, true },
        { 18, 232, false },
        { 20, 476, true },
    },
    // points_10
    {
        { 2, 536, true },
        { 27, 1260, false },
        { 39, 240, true },
        { 40, 1248, false },
        { 41, 216, true },
        { 42, 1232, false },
        { 44, 156, true },
    },
    // points_12
    {
        { 2, 216, true },
        { 3, 1248, false },
        { 4, 240, true },
        { 5, 1260, false },
        { 17, 536, true },
        { 58, 232, false },
        { 60, 476, true },
    },
};
