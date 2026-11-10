#include "npc_schedule_gotz.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectGotzSchedule\n"
    "SelectGotzSchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr6, [r4, #3]\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E95A\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803E95A:\n"
    "    ldr\tr7, [r5, #8]\n"
    "    ldr r0, .Ljp_0803E99C\n"
    "    adds\tr4, r5, r0\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetConstruction__C4Gotz\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803EA18\n"
    "    adds\tr0, r4, #0\n"
    "    bl IsConstructionComplete__C4Gotz\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803EA18\n"
    "    adds\tr0, r4, #0\n"
    "    bl IsConstructionOrderedToday__C4Gotz\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803EA18\n"
    "    subs\tr0, r7, #3\n"
    "    cmp\tr0, #1\n"
    "    bls .Ljp_0803EA18\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetConstruction__C4Gotz\n"
    "    cmp\tr0, #13\n"
    "    bhi .Ljp_0803EA18\n"
    "    lsls\tr0, r0, #2\n"
    "    ldr r1, .Ljp_0803E9A0\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    mov\tpc, r0\n"
    ".Ljp_0803E99C: .word 0x00001F64\n"
    ".Ljp_0803E9A0: .word .Ljp_0803E9A4\n"
    ".Ljp_0803E9A4: .word .Ljp_0803EA18\n"
    "    .word .Ljp_0803E9DC\n"
    "    .word .Ljp_0803EA00\n"
    "    .word .Ljp_0803EA04\n"
    "    .word .Ljp_0803EA08\n"
    "    .word .Ljp_0803EA0C\n"
    "    .word .Ljp_0803EA0C\n"
    "    .word .Ljp_0803EA0C\n"
    "    .word .Ljp_0803EA10\n"
    "    .word .Ljp_0803EA10\n"
    "    .word .Ljp_0803EA10\n"
    "    .word .Ljp_0803EA14\n"
    "    .word .Ljp_0803EA14\n"
    "    .word .Ljp_0803EA14\n"
    ".Ljp_0803E9DC:\n"
    "    movs\tr1, #250\t@ 0xfa\n"
    "    lsls\tr1, r1, #1\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetUpgradeLevel__C9FarmHouse\n"
    "    cmp\tr0, #1\n"
    "    beq .Ljp_0803E9F8\n"
    "    cmp\tr0, #1\n"
    "    bcc .Ljp_0803E9F4\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803E9FC\n"
    "    b .Ljp_0803EA18\n"
    ".Ljp_0803E9F4:\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803E9F8:\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803E9FC:\n"
    "    movs\tr0, #13\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA00:\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA04:\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA08:\n"
    "    movs\tr0, #14\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA0C:\n"
    "    movs\tr0, #10\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA10:\n"
    "    movs\tr0, #11\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA14:\n"
    "    movs\tr0, #12\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA18:\n"
    "    cmp\tr6, #5\n"
    "    bgt .Ljp_0803EA26\n"
    "    cmp\tr6, #4\n"
    "    bge .Ljp_0803EA2E\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803EA36\n"
    "    b .Ljp_0803EA2A\n"
    ".Ljp_0803EA26:\n"
    "    cmp\tr6, #6\n"
    "    beq .Ljp_0803EA32\n"
    ".Ljp_0803EA2A:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA2E:\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA32:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803EA38\n"
    ".Ljp_0803EA36:\n"
    "    movs\tr0, #4\n"
    ".Ljp_0803EA38:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" GotzScheduleData const gGotzScheduleData = {
    // descriptor
    {
        SelectGotzSchedule,
        ARRAY_COUNT(gGotzScheduleData.table_choices),
        gGotzScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gGotzScheduleData.table_storage[0],
        &gGotzScheduleData.table_storage[1],
        &gGotzScheduleData.table_storage[2],
        &gGotzScheduleData.table_storage[3],
        &gGotzScheduleData.table_storage[4],
        &gGotzScheduleData.table_storage[5],
        &gGotzScheduleData.table_storage[6],
        &gGotzScheduleData.table_storage[7],
        &gGotzScheduleData.table_storage[8],
        &gGotzScheduleData.table_storage[9],
        &gGotzScheduleData.table_storage[10],
        &gGotzScheduleData.table_storage[11],
        &gGotzScheduleData.table_storage[12],
        &gGotzScheduleData.table_storage[13],
    },
    // table_storage
    {
        { ARRAY_COUNT(gGotzScheduleData.entries_0), gGotzScheduleData.entries_0 },
        { ARRAY_COUNT(gGotzScheduleData.entries_1), gGotzScheduleData.entries_1 },
        { ARRAY_COUNT(gGotzScheduleData.entries_2), gGotzScheduleData.entries_2 },
        { ARRAY_COUNT(gGotzScheduleData.entries_3), gGotzScheduleData.entries_3 },
        { ARRAY_COUNT(gGotzScheduleData.entries_4), gGotzScheduleData.entries_4 },
        { ARRAY_COUNT(gGotzScheduleData.entries_5), gGotzScheduleData.entries_5 },
        { ARRAY_COUNT(gGotzScheduleData.entries_6), gGotzScheduleData.entries_6 },
        { ARRAY_COUNT(gGotzScheduleData.entries_7), gGotzScheduleData.entries_7 },
        { ARRAY_COUNT(gGotzScheduleData.entries_8), gGotzScheduleData.entries_8 },
        { ARRAY_COUNT(gGotzScheduleData.entries_9), gGotzScheduleData.entries_9 },
        { ARRAY_COUNT(gGotzScheduleData.entries_10), gGotzScheduleData.entries_10 },
        { ARRAY_COUNT(gGotzScheduleData.entries_11), gGotzScheduleData.entries_11 },
        { ARRAY_COUNT(gGotzScheduleData.entries_12), gGotzScheduleData.entries_12 },
        { ARRAY_COUNT(gGotzScheduleData.entries_13), gGotzScheduleData.entries_13 },
    },
    // entries_0
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
        { 0x0000003C, &gGotzScheduleData.payload_storage[1] },
        { 0x0000005E, &gGotzScheduleData.payload_storage[2] },
        { 0x00000087, &gGotzScheduleData.payload_storage[3] },
        { 0x000000F0, &gGotzScheduleData.payload_storage[4] },
        { 0x0000011A, &gGotzScheduleData.payload_storage[5] },
        { 0x0000013B, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
        { 0x0000003C, &gGotzScheduleData.payload_storage[1] },
        { 0x0000005E, &gGotzScheduleData.payload_storage[2] },
        { 0x00000087, &gGotzScheduleData.payload_storage[3] },
        { 0x000000F0, &gGotzScheduleData.payload_storage[4] },
        { 0x0000011A, &gGotzScheduleData.payload_storage[5] },
        { 0x0000013B, &gGotzScheduleData.payload_storage[0] },
        { 0x000001AA, &gGotzScheduleData.payload_storage[6] },
        { 0x000001B5, &gGotzScheduleData.payload_storage[7] },
        { 0x00000258, &gGotzScheduleData.payload_storage[8] },
        { 0x00000263, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
        { 0x0000003C, &gGotzScheduleData.payload_storage[1] },
        { 0x0000005E, &gGotzScheduleData.payload_storage[2] },
        { 0x00000087, &gGotzScheduleData.payload_storage[3] },
        { 0x000000F0, &gGotzScheduleData.payload_storage[4] },
        { 0x0000011A, &gGotzScheduleData.payload_storage[9] },
        { 0x0000013F, &gGotzScheduleData.payload_storage[10] },
        { 0x000001A4, &gGotzScheduleData.payload_storage[11] },
        { 0x000001B0, &gGotzScheduleData.payload_storage[12] },
        { 0x0000025E, &gGotzScheduleData.payload_storage[13] },
        { 0x0000028C, &gGotzScheduleData.payload_storage[14] },
        { 0x000002A3, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
        { 0x000001A4, &gGotzScheduleData.payload_storage[1] },
        { 0x000001C6, &gGotzScheduleData.payload_storage[15] },
        { 0x000001CD, &gGotzScheduleData.payload_storage[16] },
        { 0x00000258, &gGotzScheduleData.payload_storage[17] },
        { 0x00000260, &gGotzScheduleData.payload_storage[5] },
        { 0x00000281, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[0] },
    },
    // entries_5
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[18] },
    },
    // entries_6
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[19] },
    },
    // entries_7
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[21] },
    },
    // entries_8
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[22] },
    },
    // entries_9
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[20] },
    },
    // entries_10
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[20] },
    },
    // entries_11
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[20] },
    },
    // entries_12
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[20] },
    },
    // entries_13
    {
        { 0x00000000, &gGotzScheduleData.payload_storage[23] },
    },
    // payload_storage
    {
        { nullptr, 0, 200, 91, 40, 0, false },
        { gGotzScheduleData.points_1, ARRAY_COUNT(gGotzScheduleData.points_1), 614, 244, 3, 0, false },
        { gGotzScheduleData.points_2, ARRAY_COUNT(gGotzScheduleData.points_2), 1200, 752, 0, 0, false },
        { gGotzScheduleData.points_3, ARRAY_COUNT(gGotzScheduleData.points_3), 384, 608, 0, 0, true },
        { gGotzScheduleData.points_4, ARRAY_COUNT(gGotzScheduleData.points_4), 384, 608, 0, 0, false },
        { gGotzScheduleData.points_5, ARRAY_COUNT(gGotzScheduleData.points_5), 0, 448, 3, 0, false },
        { gGotzScheduleData.points_6, ARRAY_COUNT(gGotzScheduleData.points_6), 614, 244, 3, 0, false },
        { gGotzScheduleData.points_7, ARRAY_COUNT(gGotzScheduleData.points_7), 512, 170, 3, 0, true },
        { gGotzScheduleData.points_8, ARRAY_COUNT(gGotzScheduleData.points_8), 512, 170, 3, 0, false },
        { gGotzScheduleData.points_9, ARRAY_COUNT(gGotzScheduleData.points_9), 104, 704, 5, 0, false },
        { gGotzScheduleData.points_10, ARRAY_COUNT(gGotzScheduleData.points_10), 80, 88, 30, 0, true },
        { gGotzScheduleData.points_11, ARRAY_COUNT(gGotzScheduleData.points_11), 480, 160, 5, 0, false },
        { nullptr, 0, 56, 136, 15, 3, false },
        { gGotzScheduleData.points_13, ARRAY_COUNT(gGotzScheduleData.points_13), 688, 160, 5, 0, false },
        { gGotzScheduleData.points_14, ARRAY_COUNT(gGotzScheduleData.points_14), 832, 0, 3, 0, false },
        { gGotzScheduleData.points_15, ARRAY_COUNT(gGotzScheduleData.points_15), 240, 480, 8, 0, false },
        { nullptr, 0, 352, 400, 8, 3, false },
        { gGotzScheduleData.points_17, ARRAY_COUNT(gGotzScheduleData.points_17), 352, 400, 8, 0, false },
        { gGotzScheduleData.points_18, ARRAY_COUNT(gGotzScheduleData.points_18), 32, 83, 29, 0, true },
        { gGotzScheduleData.points_19, ARRAY_COUNT(gGotzScheduleData.points_19), 32, 124, 29, 0, true },
        { gGotzScheduleData.points_20, ARRAY_COUNT(gGotzScheduleData.points_20), 32, 98, 29, 0, true },
        { gGotzScheduleData.points_21, ARRAY_COUNT(gGotzScheduleData.points_21), 208, 160, 17, 0, true },
        { gGotzScheduleData.points_22, ARRAY_COUNT(gGotzScheduleData.points_22), 328, 196, 37, 0, true },
        { gGotzScheduleData.points_23, ARRAY_COUNT(gGotzScheduleData.points_23), 539, 95, 7, 0, true },
    },
    // points_1
    {
        { 2, 296, true },
        { 20, 168, false },
        { 22, 344, true },
        { 24, 120, false },
        { 26, 392, true },
        { 29, 60, false },
        { 31, 448, true },
        { 34, -16, false },
    },
    // points_2
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
        { 39, 384, false },
        { 41, 608, true },
    },
    // points_3
    {
        { 320, 2, 120, 0, false },
        { 384, 2, 120, 0, false },
    },
    // points_4
    {
        { 2, 568, true },
        { 15, 720, false },
        { 16, 592, true },
        { 17, 752, false },
        { 18, 624, true },
        { 19, 775, false },
        { 20, 656, true },
        { 21, 808, false },
        { 22, 680, true },
        { 23, 832, false },
        { 24, 704, true },
        { 25, 856, false },
        { 26, 728, true },
        { 28, 912, false },
        { 29, 752, true },
        { 42, 1216, false },
    },
    // points_5
    {
        { 2, 56, false },
        { 4, 392, true },
        { 7, 120, false },
        { 9, 344, true },
        { 11, 168, false },
        { 13, 296, true },
        { 31, 614, false },
        { 33, 244, true },
    },
    // points_6
    {
        { 2, 296, true },
        { 6, 512, false },
        { 11, 170, true },
    },
    // points_7
    {
        { 432, 2, 120, 1, false },
        { 512, 2, 120, 1, false },
    },
    // points_8
    {
        { 5, 296, true },
        { 9, 614, false },
        { 11, 244, true },
    },
    // points_9
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 35, 480, false },
        { 37, 160, true },
    },
    // points_10
    {
        { 24, 2, 120, 2, false },
        { 80, 2, 120, 3, false },
    },
    // points_11
    {
        { 2, 216, true },
        { 10, 688, false },
        { 12, 160, true },
    },
    // points_13
    {
        { 2, 216, true },
        { 7, 808, false },
        { 20, 536, true },
        { 38, 1260, false },
        { 46, 736, true },
    },
    // points_14
    {
        { 12, 296, true },
        { 21, 614, false },
        { 23, 244, true },
    },
    // points_15
    {
        { 3, 400, true },
        { 7, 352, false },
    },
    // points_17
    {
        { 4, 240, false },
        { 8, 512, true },
    },
    // points_18
    {
        { 83, 2, 300, 2, true },
        { 133, 2, 300, 2, true },
        { 83, 2, 300, 2, true },
    },
    // points_19
    {
        { 124, 2, 300, 2, true },
        { 162, 2, 300, 2, true },
        { 124, 2, 300, 2, true },
    },
    // points_20
    {
        { 98, 2, 300, 2, true },
        { 148, 2, 300, 2, true },
        { 98, 2, 300, 2, true },
    },
    // points_21
    {
        { 160, 2, 300, 3, true },
        { 110, 2, 300, 3, true },
        { 160, 2, 300, 3, true },
    },
    // points_22
    {
        { 196, 2, 300, 3, true },
        { 224, 2, 300, 3, true },
        { 196, 2, 300, 3, true },
    },
    // points_23
    {
        { 95, 2, 300, 2, true },
        { 35, 2, 300, 2, true },
        { 95, 2, 300, 3, true },
        { 35, 2, 300, 3, true },
        { 95, 2, 300, 2, true },
    },
};
