#include "npc_schedule_saibara.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectSaibaraSchedule\n"
    "SelectSaibaraSchedule:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E8D0\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E8D4\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E92C\n"
    "    .align 2, 0\n"
    ".Ljp_0803E8D0: .word 0x000021CA\n"
    ".Ljp_0803E8D4:\n"
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
    "    beq .Ljp_0803E8F4\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E92C\n"
    ".Ljp_0803E8F4:\n"
    "    ldr r0, .Ljp_0803E914\n"
    "    adds\tr4, r5, r0\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetOrder__C7Saibara\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E918\n"
    "    adds\tr0, r4, #0\n"
    "    bl IsOrderComplete__C7Saibara\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E918\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E92C\n"
    "    .align 2, 0\n"
    ".Ljp_0803E914: .word 0x00001DAC\n"
    ".Ljp_0803E918:\n"
    "    cmp\tr6, #4\n"
    "    bne .Ljp_0803E92A\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E926\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E92C\n"
    ".Ljp_0803E926:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E92C\n"
    ".Ljp_0803E92A:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E92C:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" SaibaraScheduleData const gSaibaraScheduleData = {
    // descriptor
    {
        SelectSaibaraSchedule,
        ARRAY_COUNT(gSaibaraScheduleData.table_choices),
        gSaibaraScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gSaibaraScheduleData.table_storage[0],
        &gSaibaraScheduleData.table_storage[1],
        &gSaibaraScheduleData.table_storage[2],
        &gSaibaraScheduleData.table_storage[3],
        &gSaibaraScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gSaibaraScheduleData.entries_0), gSaibaraScheduleData.entries_0 },
        { ARRAY_COUNT(gSaibaraScheduleData.entries_1), gSaibaraScheduleData.entries_1 },
        { ARRAY_COUNT(gSaibaraScheduleData.entries_2), gSaibaraScheduleData.entries_2 },
        { ARRAY_COUNT(gSaibaraScheduleData.entries_3), gSaibaraScheduleData.entries_3 },
        { ARRAY_COUNT(gSaibaraScheduleData.entries_4), gSaibaraScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[0] },
        { 0x00000078, &gSaibaraScheduleData.payload_storage[1] },
        { 0x0000030F, &gSaibaraScheduleData.payload_storage[2] },
        { 0x0000031F, &gSaibaraScheduleData.payload_storage[6] },
        { 0x0000033E, &gSaibaraScheduleData.payload_storage[7] },
        { 0x000003C0, &gSaibaraScheduleData.payload_storage[8] },
        { 0x000003DF, &gSaibaraScheduleData.payload_storage[9] },
        { 0x000003EF, &gSaibaraScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[0] },
        { 0x0000003F, &gSaibaraScheduleData.payload_storage[10] },
        { 0x00000065, &gSaibaraScheduleData.payload_storage[11] },
        { 0x0000006E, &gSaibaraScheduleData.payload_storage[12] },
        { 0x000000F0, &gSaibaraScheduleData.payload_storage[13] },
        { 0x000000FA, &gSaibaraScheduleData.payload_storage[14] },
        { 0x0000011F, &gSaibaraScheduleData.payload_storage[1] },
        { 0x000001A7, &gSaibaraScheduleData.payload_storage[2] },
        { 0x000001B7, &gSaibaraScheduleData.payload_storage[3] },
        { 0x000001E5, &gSaibaraScheduleData.payload_storage[4] },
        { 0x00000258, &gSaibaraScheduleData.payload_storage[5] },
        { 0x00000287, &gSaibaraScheduleData.payload_storage[9] },
        { 0x00000297, &gSaibaraScheduleData.payload_storage[1] },
        { 0x0000030C, &gSaibaraScheduleData.payload_storage[2] },
        { 0x0000031C, &gSaibaraScheduleData.payload_storage[6] },
        { 0x0000033B, &gSaibaraScheduleData.payload_storage[1] },
        { 0x000003C0, &gSaibaraScheduleData.payload_storage[8] },
        { 0x000003DF, &gSaibaraScheduleData.payload_storage[9] },
        { 0x000003EF, &gSaibaraScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[0] },
        { 0x00000078, &gSaibaraScheduleData.payload_storage[1] },
        { 0x0000030C, &gSaibaraScheduleData.payload_storage[2] },
        { 0x0000031C, &gSaibaraScheduleData.payload_storage[6] },
        { 0x0000033B, &gSaibaraScheduleData.payload_storage[7] },
        { 0x000003C0, &gSaibaraScheduleData.payload_storage[8] },
        { 0x000003DF, &gSaibaraScheduleData.payload_storage[9] },
        { 0x000003EF, &gSaibaraScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gSaibaraScheduleData.payload_storage[1] },
    },
    // payload_storage
    {
        { gSaibaraScheduleData.points_0, ARRAY_COUNT(gSaibaraScheduleData.points_0), 152, 80, 38, 0, true },
        { nullptr, 0, 118, 115, 38, 0, false },
        { gSaibaraScheduleData.points_2, ARRAY_COUNT(gSaibaraScheduleData.points_2), 296, 116, 7, 0, false },
        { gSaibaraScheduleData.points_3, ARRAY_COUNT(gSaibaraScheduleData.points_3), 104, 704, 5, 0, false },
        { nullptr, 0, 152, 136, 15, 0, false },
        { gSaibaraScheduleData.points_5, ARRAY_COUNT(gSaibaraScheduleData.points_5), 688, 160, 5, 0, false },
        { gSaibaraScheduleData.points_6, ARRAY_COUNT(gSaibaraScheduleData.points_6), 104, 704, 5, 0, false },
        { nullptr, 0, 287, 235, 21, 2, false },
        { gSaibaraScheduleData.points_8, ARRAY_COUNT(gSaibaraScheduleData.points_8), 632, 488, 5, 0, false },
        { gSaibaraScheduleData.points_9, ARRAY_COUNT(gSaibaraScheduleData.points_9), 104, 0, 7, 0, false },
        { gSaibaraScheduleData.points_10, ARRAY_COUNT(gSaibaraScheduleData.points_10), 296, 116, 7, 0, false },
        { gSaibaraScheduleData.points_11, ARRAY_COUNT(gSaibaraScheduleData.points_11), 240, 480, 8, 0, false },
        { nullptr, 0, 256, 272, 8, 1, false },
        { gSaibaraScheduleData.points_13, ARRAY_COUNT(gSaibaraScheduleData.points_13), 256, 272, 8, 0, false },
        { gSaibaraScheduleData.points_14, ARRAY_COUNT(gSaibaraScheduleData.points_14), 812, 512, 7, 0, false },
    },
    // points_0
    {
        { 192, 2, 120, 3, false },
        { 152, 2, 120, 2, false },
    },
    // points_2
    {
        { 2, 152, true },
        { 10, 104, false },
        { 16, 0, true },
    },
    // points_3
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 44, 688, false },
        { 46, 160, true },
    },
    // points_5
    {
        { 2, 216, true },
        { 24, 144, false },
        { 25, 240, true },
        { 27, 104, false },
        { 47, 736, true },
    },
    // points_6
    {
        { 7, 536, true },
        { 28, 632, false },
        { 31, 488, true },
    },
    // points_8
    {
        { 2, 536, true },
        { 23, 104, false },
        { 31, 736, true },
    },
    // points_9
    {
        { 6, 152, true },
        { 14, 296, false },
        { 16, 116, true },
    },
    // points_10
    {
        { 2, 152, true },
        { 23, 812, false },
        { 38, 544, true },
    },
    // points_11
    {
        { 8, 272, true },
        { 9, 256, false },
    },
    // points_13
    {
        { 1, 240, false },
        { 10, 512, true },
    },
    // points_14
    {
        { 14, 152, true },
        { 35, 296, false },
        { 37, 116, true },
    },
};
