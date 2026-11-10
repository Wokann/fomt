#include "npc_schedule_cliff.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectCliffSchedule\n"
    "SelectCliffSchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r8\n"
    "    push\t{r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803DABC\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_0803DAB6\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    mov\tr0, sp\n"
    "    ldrb\tr6, [r0, #0]\n"
    "    ldrb\tr7, [r4, #1]\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    mov\tr8, r0\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    ldr r1, .Ljp_0803DAC0\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803DAB6\n"
    "    subs\tr1, #12\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_0803DAC4\n"
    "    cmp\tr6, #1\n"
    "    bhi .Ljp_0803DAB6\n"
    "    cmp\tr6, #1\n"
    "    bne .Ljp_0803DAC4\n"
    "    cmp\tr7, #3\n"
    "    bne .Ljp_0803DAC4\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #28\n"
    "    bls .Ljp_0803DAC4\n"
    ".Ljp_0803DAB6:\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803DB32\n"
    "    .align 2, 0\n"
    ".Ljp_0803DABC: .word 0x000021CA\n"
    ".Ljp_0803DAC0: .word 0x00002181\n"
    ".Ljp_0803DAC4:\n"
    "    ldr r1, .Ljp_0803DAD8\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803DADC\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803DB32\n"
    "    .align 2, 0\n"
    ".Ljp_0803DAD8: .word 0x00002181\n"
    ".Ljp_0803DADC:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DAEE\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803DB32\n"
    ".Ljp_0803DAEE:\n"
    "    cmp\tr6, #1\n"
    "    bne .Ljp_0803DB10\n"
    "    cmp\tr7, #2\n"
    "    bne .Ljp_0803DB10\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #15\n"
    "    bne .Ljp_0803DB10\n"
    "    ldr r1, .Ljp_0803DB0C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803DB10\n"
    ".Ljp_0803DB08:\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803DB32\n"
    ".Ljp_0803DB0C: .word 0x00002175\n"
    ".Ljp_0803DB10:\n"
    "    ldr r1, .Ljp_0803DB2C\n"
    "    adds\tr0, r5, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    movs\tr1, #194\t@ 0xc2\n"
    "    lsls\tr1, r1, #11\n"
    "    ands\tr0, r1\n"
    "    movs\tr1, #130\t@ 0x82\n"
    "    lsls\tr1, r1, #11\n"
    "    cmp\tr0, r1\n"
    "    bne .Ljp_0803DB30\n"
    "    cmp\tr4, #6\n"
    "    bne .Ljp_0803DB08\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803DB32\n"
    ".Ljp_0803DB2C: .word 0x00002174\n"
    ".Ljp_0803DB30:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803DB32:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

// Recovered schedule data at US ROM 0x080F2AF8 (JP 0x080F2354).
// The two regional payloads differ only in relocated function/data pointers.

extern "C" CliffScheduleData const gCliffScheduleData = {
    // descriptor
    { SelectCliffSchedule, ARRAY_COUNT(gCliffScheduleData.table_choices), gCliffScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gCliffScheduleData.table_storage[0], &gCliffScheduleData.table_storage[1], &gCliffScheduleData.table_storage[2],
        &gCliffScheduleData.table_storage[3], &gCliffScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gCliffScheduleData.entries_0), gCliffScheduleData.entries_0 },
        { ARRAY_COUNT(gCliffScheduleData.entries_1), gCliffScheduleData.entries_1 },
        { ARRAY_COUNT(gCliffScheduleData.entries_2), gCliffScheduleData.entries_2 },
        { ARRAY_COUNT(gCliffScheduleData.entries_3), gCliffScheduleData.entries_3 },
        { ARRAY_COUNT(gCliffScheduleData.entries_4), gCliffScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0, &gCliffScheduleData.payload_storage[0] },
        { 180, &gCliffScheduleData.payload_storage[1] },
        { 224, &gCliffScheduleData.payload_storage[2] },
        { 605, &gCliffScheduleData.payload_storage[3] },
        { 646, &gCliffScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0, &gCliffScheduleData.payload_storage[0] },
        { 240, &gCliffScheduleData.payload_storage[4] },
        { 265, &gCliffScheduleData.payload_storage[5] },
        { 420, &gCliffScheduleData.payload_storage[6] },
        { 427, &gCliffScheduleData.payload_storage[7] },
        { 600, &gCliffScheduleData.payload_storage[8] },
        { 667, &gCliffScheduleData.payload_storage[2] },
        { 783, &gCliffScheduleData.payload_storage[3] },
        { 824, &gCliffScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0, &gCliffScheduleData.payload_storage[0] },
        { 420, &gCliffScheduleData.payload_storage[9] },
        { 611, &gCliffScheduleData.payload_storage[1] },
        { 655, &gCliffScheduleData.payload_storage[2] },
        { 780, &gCliffScheduleData.payload_storage[10] },
        { 824, &gCliffScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0, &gCliffScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0, &gCliffScheduleData.payload_storage[11] },
    },
    // payload_storage
    {
        { nullptr, 0, 272, 72, 23, 0, 0 },
        { gCliffScheduleData.points_1, ARRAY_COUNT(gCliffScheduleData.points_1), 632, 488, 5, 0, 0 },
        { nullptr, 0, 104, 155, 12, 1, 0 },
        { gCliffScheduleData.points_3, ARRAY_COUNT(gCliffScheduleData.points_3), 1232, 156, 5, 0, 0 },
        { gCliffScheduleData.points_4, ARRAY_COUNT(gCliffScheduleData.points_4), 632, 488, 5, 0, 0 },
        { gCliffScheduleData.points_5, ARRAY_COUNT(gCliffScheduleData.points_5), 176, 88, 34, 0, 1 },
        { gCliffScheduleData.points_6, ARRAY_COUNT(gCliffScheduleData.points_6), 314, 456, 5, 0, 0 },
        { nullptr, 0, 456, 476, 5, 1, 0 },
        { gCliffScheduleData.points_8, ARRAY_COUNT(gCliffScheduleData.points_8), 456, 476, 5, 0, 0 },
        { nullptr, 0, 64, 136, 21, 0, 0 },
        { gCliffScheduleData.points_10, ARRAY_COUNT(gCliffScheduleData.points_10), 1232, 160, 5, 0, 0 },
        { nullptr, 0, 432, 232, 19, 0, 0 },
    },
    // points_1
    {
        { 2, 536, 1 },
        { 27, 1260, 0 },
        { 39, 240, 1 },
        { 40, 1248, 0 },
        { 41, 216, 1 },
        { 42, 1232, 0 },
        { 44, 156, 1 },
    },
    // points_3
    {
        { 2, 216, 1 },
        { 19, 808, 0 },
        { 32, 536, 1 },
        { 39, 632, 0 },
        { 41, 488, 1 },
    },
    // points_4
    {
        { 2, 536, 1 },
        { 18, 232, 0 },
        { 20, 480, 1 },
        { 21, 265, 0 },
        { 22, 476, 1 },
        { 24, 316, 0 },
        { 25, 460, 1 },
    },
    // points_5
    {
        { 208, 2, 120, 1, 0 },
        { 176, 2, 120, 1, 0 },
    },
    // points_6
    {
        { 1, 476, 1 },
        { 7, 456, 0 },
    },
    // points_8
    {
        { 8, 265, 0 },
        { 9, 496, 1 },
        { 10, 232, 0 },
        { 12, 536, 1 },
        { 35, 808, 0 },
        { 48, 216, 1 },
        { 65, 1232, 0 },
        { 67, 156, 1 },
    },
    // points_10
    {
        { 2, 216, 1 },
        { 3, 1248, 0 },
        { 4, 240, 1 },
        { 5, 1260, 0 },
        { 17, 536, 1 },
        { 42, 632, 0 },
        { 44, 488, 1 },
    },
};
