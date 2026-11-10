#include "npc_schedule_carter.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectCarterSchedule\n"
    "SelectCarterSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E768\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    movs\tr0, #124\t@ 0x7c\n"
    "    ands\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E76C\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E7AC\n"
    ".Ljp_0803E768: .word 0x000021CA\n"
    ".Ljp_0803E76C:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    cmp\tr0, #2\n"
    "    bne .Ljp_0803E78A\n"
    "    cmp\tr1, #3\n"
    "    bne .Ljp_0803E78A\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803E7AC\n"
    ".Ljp_0803E78A:\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E798\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803E7AC\n"
    ".Ljp_0803E798:\n"
    "    cmp\tr4, #1\n"
    "    beq .Ljp_0803E7A6\n"
    "    cmp\tr4, #3\n"
    "    beq .Ljp_0803E7A6\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E7AA\n"
    ".Ljp_0803E7A6:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E7AC\n"
    ".Ljp_0803E7AA:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803E7AC:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" CarterScheduleData const gCarterScheduleData = {
    // descriptor
    {
        SelectCarterSchedule,
        ARRAY_COUNT(gCarterScheduleData.table_choices),
        gCarterScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gCarterScheduleData.table_storage[0],
        &gCarterScheduleData.table_storage[1],
        &gCarterScheduleData.table_storage[2],
        &gCarterScheduleData.table_storage[3],
        &gCarterScheduleData.table_storage[4],
        &gCarterScheduleData.table_storage[5],
        &gCarterScheduleData.table_storage[6],
        &gCarterScheduleData.table_storage[7],
        &gCarterScheduleData.table_storage[8],
    },
    // table_storage
    {
        { ARRAY_COUNT(gCarterScheduleData.entries_0), gCarterScheduleData.entries_0 },
        { ARRAY_COUNT(gCarterScheduleData.entries_1), gCarterScheduleData.entries_1 },
        { ARRAY_COUNT(gCarterScheduleData.entries_2), gCarterScheduleData.entries_2 },
        { ARRAY_COUNT(gCarterScheduleData.entries_3), gCarterScheduleData.entries_3 },
        { ARRAY_COUNT(gCarterScheduleData.entries_4), gCarterScheduleData.entries_4 },
        { ARRAY_COUNT(gCarterScheduleData.entries_5), gCarterScheduleData.entries_5 },
        { ARRAY_COUNT(gCarterScheduleData.entries_6), gCarterScheduleData.entries_6 },
        { ARRAY_COUNT(gCarterScheduleData.entries_7), gCarterScheduleData.entries_7 },
        { ARRAY_COUNT(gCarterScheduleData.entries_8), gCarterScheduleData.entries_8 },
    },
    // entries_0
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[0] },
        { 0x000000B4, &gCarterScheduleData.payload_storage[1] },
        { 0x000000B9, &gCarterScheduleData.payload_storage[2] },
        { 0x000001A4, &gCarterScheduleData.payload_storage[3] },
        { 0x00000258, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_1
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[0] },
        { 0x000000B4, &gCarterScheduleData.payload_storage[1] },
        { 0x000000B9, &gCarterScheduleData.payload_storage[2] },
        { 0x000001A4, &gCarterScheduleData.payload_storage[4] },
        { 0x000001A7, &gCarterScheduleData.payload_storage[5] },
        { 0x00000258, &gCarterScheduleData.payload_storage[6] },
        { 0x0000025B, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_2
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_3
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_4
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_5
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_6
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_7
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
    },
    // entries_8
    {
        { 0x00000000, &gCarterScheduleData.payload_storage[2] },
        { 0x000002D0, &gCarterScheduleData.payload_storage[7] },
        { 0x000002D1, &gCarterScheduleData.payload_storage[8] },
        { 0x0000041A, &gCarterScheduleData.payload_storage[9] },
        { 0x0000041B, &gCarterScheduleData.payload_storage[2] },
    },
    // payload_storage
    {
        { gCarterScheduleData.points_0, ARRAY_COUNT(gCarterScheduleData.points_0), 1160, 152, 5, 0, true },
        { gCarterScheduleData.points_1, ARRAY_COUNT(gCarterScheduleData.points_1), 1160, 152, 5, 0, false },
        { nullptr, 0, 184, 67, 12, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
        { gCarterScheduleData.points_4, ARRAY_COUNT(gCarterScheduleData.points_4), 1232, 156, 5, 0, false },
        { nullptr, 0, 1224, 208, 5, 2, false },
        { gCarterScheduleData.points_6, ARRAY_COUNT(gCarterScheduleData.points_6), 1224, 208, 5, 0, false },
        { gCarterScheduleData.points_7, ARRAY_COUNT(gCarterScheduleData.points_7), 1232, 156, 5, 0, false },
        { nullptr, 0, 1232, 181, 5, 0, false },
        { gCarterScheduleData.points_9, ARRAY_COUNT(gCarterScheduleData.points_9), 1232, 181, 5, 0, false },
    },
    // points_0
    {
        { 1088, 2, 120, 1, false },
        { 1160, 2, 120, 1, false },
    },
    // points_1
    {
        { 1, 160, true },
        { 4, 1232, false },
        { 5, 156, true },
    },
    // points_4
    {
        { 2, 208, true },
        { 3, 1224, false },
    },
    // points_6
    {
        { 1, 1232, false },
        { 3, 156, true },
    },
    // points_7
    {
        { 1, 181, true },
    },
    // points_9
    {
        { 1, 156, true },
    },
};
