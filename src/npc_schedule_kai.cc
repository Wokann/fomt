#include "npc_schedule_kai.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectKaiSchedule\n"
    "SelectKaiSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E7EC\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_0803E806\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803E806\n"
    "    movs\tr0, #1\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E7F0\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E808\n"
    ".Ljp_0803E7EC: .word 0x000021CA\n"
    ".Ljp_0803E7F0:\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_0803E802\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E7FE\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E808\n"
    ".Ljp_0803E7FE:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E808\n"
    ".Ljp_0803E802:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E808\n"
    ".Ljp_0803E806:\n"
    "    movs\tr0, #0\n"
    ".Ljp_0803E808:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" KaiScheduleData const gKaiScheduleData = {
    // descriptor
    {
        SelectKaiSchedule,
        ARRAY_COUNT(gKaiScheduleData.table_choices),
        gKaiScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gKaiScheduleData.table_storage[0],
        &gKaiScheduleData.table_storage[1],
        &gKaiScheduleData.table_storage[2],
        &gKaiScheduleData.table_storage[3],
    },
    // table_storage
    {
        { ARRAY_COUNT(gKaiScheduleData.entries_0), gKaiScheduleData.entries_0 },
        { ARRAY_COUNT(gKaiScheduleData.entries_1), gKaiScheduleData.entries_1 },
        { ARRAY_COUNT(gKaiScheduleData.entries_2), gKaiScheduleData.entries_2 },
        { ARRAY_COUNT(gKaiScheduleData.entries_3), gKaiScheduleData.entries_3 },
    },
    // entries_0
    {
        { 0x00000000, &gKaiScheduleData.payload_storage[0] },
        { 0x00000079, &gKaiScheduleData.payload_storage[1] },
        { 0x0000009C, &gKaiScheduleData.payload_storage[2] },
        { 0x000000B0, &gKaiScheduleData.payload_storage[3] },
        { 0x0000012C, &gKaiScheduleData.payload_storage[4] },
        { 0x00000131, &gKaiScheduleData.payload_storage[5] },
        { 0x000001A4, &gKaiScheduleData.payload_storage[6] },
        { 0x000001A9, &gKaiScheduleData.payload_storage[3] },
        { 0x00000294, &gKaiScheduleData.payload_storage[4] },
        { 0x00000299, &gKaiScheduleData.payload_storage[5] },
        { 0x0000030C, &gKaiScheduleData.payload_storage[7] },
        { 0x00000320, &gKaiScheduleData.payload_storage[8] },
        { 0x00000342, &gKaiScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gKaiScheduleData.payload_storage[0] },
        { 0x000001A4, &gKaiScheduleData.payload_storage[1] },
        { 0x000001C7, &gKaiScheduleData.payload_storage[9] },
        { 0x000001D9, &gKaiScheduleData.payload_storage[10] },
        { 0x00000258, &gKaiScheduleData.payload_storage[11] },
        { 0x0000026B, &gKaiScheduleData.payload_storage[8] },
        { 0x0000028D, &gKaiScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gKaiScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gKaiScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 208, 80, 23, 0, false },
        { gKaiScheduleData.points_1, ARRAY_COUNT(gKaiScheduleData.points_1), 632, 488, 5, 0, false },
        { gKaiScheduleData.points_2, ARRAY_COUNT(gKaiScheduleData.points_2), 0, 280, 1, 0, false },
        { nullptr, 0, 160, 116, 1, 0, false },
        { gKaiScheduleData.points_4, ARRAY_COUNT(gKaiScheduleData.points_4), 160, 116, 1, 0, false },
        { nullptr, 0, 110, 91, 36, 0, false },
        { gKaiScheduleData.points_6, ARRAY_COUNT(gKaiScheduleData.points_6), 84, 116, 1, 0, false },
        { gKaiScheduleData.points_7, ARRAY_COUNT(gKaiScheduleData.points_7), 84, 116, 1, 0, false },
        { gKaiScheduleData.points_8, ARRAY_COUNT(gKaiScheduleData.points_8), 1260, 704, 5, 0, false },
        { gKaiScheduleData.points_9, ARRAY_COUNT(gKaiScheduleData.points_9), 0, 280, 1, 0, false },
        { nullptr, 0, 256, 264, 1, 3, false },
        { gKaiScheduleData.points_11, ARRAY_COUNT(gKaiScheduleData.points_11), 256, 264, 1, 0, false },
    },
    // points_1
    {
        { 2, 536, true },
        { 27, 1260, false },
        { 35, 736, true },
    },
    // points_2
    {
        { 3, 64, false },
        { 6, 360, true },
        { 8, 104, false },
        { 17, 136, true },
        { 19, 160, false },
        { 20, 116, true },
    },
    // points_4
    {
        { 1, 136, true },
        { 4, 80, false },
        { 5, 116, true },
    },
    // points_6
    {
        { 1, 136, true },
        { 4, 160, false },
        { 5, 116, true },
    },
    // points_7
    {
        { 1, 136, true },
        { 2, 104, false },
        { 11, 360, true },
        { 13, 64, false },
        { 16, 280, true },
        { 20, -16, false },
    },
    // points_8
    {
        { 7, 536, true },
        { 32, 632, false },
        { 34, 488, true },
    },
    // points_9
    {
        { 3, 64, false },
        { 6, 360, true },
        { 8, 104, false },
        { 12, 264, true },
        { 18, 256, false },
    },
    // points_11
    {
        { 6, 104, false },
        { 10, 360, true },
        { 12, 64, false },
        { 15, 280, true },
        { 19, -16, false },
    },
};
