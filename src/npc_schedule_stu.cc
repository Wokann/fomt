#include "npc_schedule_stu.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectStuSchedule\n"
    "SelectStuSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E598\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_0803E5BC\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr2, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    cmp\tr2, #2\n"
    "    bne .Ljp_0803E5A0\n"
    "    cmp\tr1, #30\n"
    "    bne .Ljp_0803E5A0\n"
    "    ldr r3, .Ljp_0803E59C\n"
    "    adds\tr0, r5, r3\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsrs\tr0, r0, #6\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803E5A0\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E598: .word 0x000021CA\n"
    ".Ljp_0803E59C: .word 0x000021A2\n"
    ".Ljp_0803E5A0:\n"
    "    adds\tr0, r2, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E5B0\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E5B0:\n"
    "    ldr r1, .Ljp_0803E5C0\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E5C4\n"
    ".Ljp_0803E5BC:\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E5C0: .word 0x0000215A\n"
    ".Ljp_0803E5C4:\n"
    "    cmp\tr4, #1\n"
    "    beq .Ljp_0803E5CC\n"
    "    cmp\tr4, #3\n"
    "    bne .Ljp_0803E5D0\n"
    ".Ljp_0803E5CC:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E5D0:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E5DA\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E5DA:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E5DC:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" StuScheduleData const gStuScheduleData = {
    // descriptor
    {
        SelectStuSchedule,
        ARRAY_COUNT(gStuScheduleData.table_choices),
        gStuScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gStuScheduleData.table_storage[0],
        &gStuScheduleData.table_storage[1],
        &gStuScheduleData.table_storage[2],
        &gStuScheduleData.table_storage[3],
        &gStuScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gStuScheduleData.entries_0), gStuScheduleData.entries_0 },
        { ARRAY_COUNT(gStuScheduleData.entries_1), gStuScheduleData.entries_1 },
        { ARRAY_COUNT(gStuScheduleData.entries_2), gStuScheduleData.entries_2 },
        { ARRAY_COUNT(gStuScheduleData.entries_3), gStuScheduleData.entries_3 },
        { ARRAY_COUNT(gStuScheduleData.entries_4), gStuScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
        { 0x000001A4, &gStuScheduleData.payload_storage[1] },
        { 0x000001C7, &gStuScheduleData.payload_storage[2] },
        { 0x00000258, &gStuScheduleData.payload_storage[3] },
        { 0x0000027B, &gStuScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gStuScheduleData.payload_storage[0] },
        { 0x00000078, &gStuScheduleData.payload_storage[6] },
        { 0x00000082, &gStuScheduleData.payload_storage[4] },
        { 0x000000B4, &gStuScheduleData.payload_storage[5] },
        { 0x000000BE, &gStuScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gStuScheduleData.points_0, ARRAY_COUNT(gStuScheduleData.points_0), 176, 160, 14, 0, true },
        { gStuScheduleData.points_1, ARRAY_COUNT(gStuScheduleData.points_1), 400, 160, 5, 0, false },
        { nullptr, 0, 1200, 200, 5, 0, false },
        { gStuScheduleData.points_3, ARRAY_COUNT(gStuScheduleData.points_3), 1200, 200, 5, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gStuScheduleData.points_5, ARRAY_COUNT(gStuScheduleData.points_5), 228, 145, 2, 0, false },
        { gStuScheduleData.points_6, ARRAY_COUNT(gStuScheduleData.points_6), 340, 0, 2, 0, false },
    },
    // points_0
    {
        { 96, 2, 120, 1, true },
        { 160, 2, 120, 0, true },
    },
    // points_1
    {
        { 2, 216, true },
        { 34, 1200, false },
        { 35, 200, true },
    },
    // points_3
    {
        { 1, 216, true },
        { 33, 400, false },
        { 35, 160, true },
    },
    // points_5
    {
        { 4, 340, false },
        { 10, 0, true },
    },
    // points_6
    {
        { 6, 145, true },
        { 10, 228, false },
    },
};
