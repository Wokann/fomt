#include "npc_schedule_gray.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectGraySchedule\n"
    "SelectGraySchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r8\n"
    "    push\t{r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E82C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E830\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E8AA\n"
    "    .align 2, 0\n"
    ".Ljp_0803E82C: .word 0x000021CA\n"
    ".Ljp_0803E830:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr6, [r4, #1]\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    mov\tr8, r0\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    ldr r1, .Ljp_0803E864\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetRivalEventCount__C12Bachelorette\n"
    "    adds\tr7, r0, #0\n"
    "    cmp\tr7, #4\n"
    "    bls .Ljp_0803E87E\n"
    "    adds\tr0, r6, #0\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E868\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803E8AA\n"
    ".Ljp_0803E864: .word 0x00001E28\n"
    ".Ljp_0803E868:\n"
    "    cmp\tr4, #4\n"
    "    bne .Ljp_0803E87A\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E876\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803E8AA\n"
    ".Ljp_0803E876:\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803E8AA\n"
    ".Ljp_0803E87A:\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E8AA\n"
    ".Ljp_0803E87E:\n"
    "    adds\tr0, r6, #0\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E890\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803E8AA\n"
    ".Ljp_0803E890:\n"
    "    cmp\tr7, #0\n"
    "    beq .Ljp_0803E8A8\n"
    "    cmp\tr4, #1\n"
    "    bne .Ljp_0803E89C\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E8AA\n"
    ".Ljp_0803E89C:\n"
    "    cmp\tr4, #4\n"
    "    bne .Ljp_0803E8A4\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E8AA\n"
    ".Ljp_0803E8A4:\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E8AA\n"
    ".Ljp_0803E8A8:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E8AA:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

extern "C" GrayScheduleData const gGrayScheduleData = {
    // descriptor
    {
        SelectGraySchedule,
        ARRAY_COUNT(gGrayScheduleData.table_choices),
        gGrayScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gGrayScheduleData.table_storage[0],
        &gGrayScheduleData.table_storage[1],
        &gGrayScheduleData.table_storage[2],
        &gGrayScheduleData.table_storage[3],
        &gGrayScheduleData.table_storage[4],
        &gGrayScheduleData.table_storage[5],
        &gGrayScheduleData.table_storage[6],
        &gGrayScheduleData.table_storage[7],
        &gGrayScheduleData.table_storage[8],
    },
    // table_storage
    {
        { ARRAY_COUNT(gGrayScheduleData.entries_0), gGrayScheduleData.entries_0 },
        { ARRAY_COUNT(gGrayScheduleData.entries_1), gGrayScheduleData.entries_1 },
        { ARRAY_COUNT(gGrayScheduleData.entries_2), gGrayScheduleData.entries_2 },
        { ARRAY_COUNT(gGrayScheduleData.entries_3), gGrayScheduleData.entries_3 },
        { ARRAY_COUNT(gGrayScheduleData.entries_4), gGrayScheduleData.entries_4 },
        { ARRAY_COUNT(gGrayScheduleData.entries_5), gGrayScheduleData.entries_5 },
        { ARRAY_COUNT(gGrayScheduleData.entries_6), gGrayScheduleData.entries_6 },
        { ARRAY_COUNT(gGrayScheduleData.entries_7), gGrayScheduleData.entries_7 },
        { ARRAY_COUNT(gGrayScheduleData.entries_8), gGrayScheduleData.entries_8 },
    },
    // entries_0
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
        { 0x0000003F, &gGrayScheduleData.payload_storage[1] },
        { 0x00000062, &gGrayScheduleData.payload_storage[2] },
        { 0x00000068, &gGrayScheduleData.payload_storage[12] },
        { 0x000000B4, &gGrayScheduleData.payload_storage[3] },
        { 0x000000C8, &gGrayScheduleData.payload_storage[4] },
        { 0x000000F7, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[7] },
        { 0x000001D2, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
        { 0x0000003F, &gGrayScheduleData.payload_storage[1] },
        { 0x00000062, &gGrayScheduleData.payload_storage[4] },
        { 0x00000091, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[9] },
        { 0x000001D1, &gGrayScheduleData.payload_storage[10] },
        { 0x00000258, &gGrayScheduleData.payload_storage[11] },
        { 0x00000285, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
        { 0x0000003F, &gGrayScheduleData.payload_storage[1] },
        { 0x00000062, &gGrayScheduleData.payload_storage[4] },
        { 0x00000091, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[7] },
        { 0x000001D2, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
        { 0x0000003F, &gGrayScheduleData.payload_storage[1] },
        { 0x00000062, &gGrayScheduleData.payload_storage[13] },
        { 0x0000006C, &gGrayScheduleData.payload_storage[14] },
        { 0x000000F1, &gGrayScheduleData.payload_storage[15] },
        { 0x000000FC, &gGrayScheduleData.payload_storage[16] },
        { 0x00000121, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[9] },
        { 0x000001D1, &gGrayScheduleData.payload_storage[10] },
        { 0x00000258, &gGrayScheduleData.payload_storage[11] },
        { 0x00000285, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[17] },
        { 0x0000003C, &gGrayScheduleData.payload_storage[19] },
        { 0x00000056, &gGrayScheduleData.payload_storage[20] },
        { 0x00000066, &gGrayScheduleData.payload_storage[5] },
        { 0x000001A4, &gGrayScheduleData.payload_storage[6] },
        { 0x000001B4, &gGrayScheduleData.payload_storage[9] },
        { 0x000001D1, &gGrayScheduleData.payload_storage[10] },
        { 0x00000258, &gGrayScheduleData.payload_storage[21] },
        { 0x00000261, &gGrayScheduleData.payload_storage[17] },
        { 0x000003C0, &gGrayScheduleData.payload_storage[18] },
    },
    // entries_5
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[18] },
        { 0x0000003C, &gGrayScheduleData.payload_storage[17] },
        { 0x000001A7, &gGrayScheduleData.payload_storage[19] },
        { 0x000001C1, &gGrayScheduleData.payload_storage[13] },
        { 0x000001CB, &gGrayScheduleData.payload_storage[14] },
        { 0x0000025A, &gGrayScheduleData.payload_storage[15] },
        { 0x00000265, &gGrayScheduleData.payload_storage[8] },
        { 0x0000027F, &gGrayScheduleData.payload_storage[17] },
        { 0x000003C0, &gGrayScheduleData.payload_storage[18] },
    },
    // entries_6
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[18] },
        { 0x0000003C, &gGrayScheduleData.payload_storage[17] },
        { 0x000001A7, &gGrayScheduleData.payload_storage[19] },
        { 0x000001C1, &gGrayScheduleData.payload_storage[20] },
        { 0x000001D1, &gGrayScheduleData.payload_storage[5] },
        { 0x0000025B, &gGrayScheduleData.payload_storage[6] },
        { 0x0000026B, &gGrayScheduleData.payload_storage[8] },
        { 0x00000285, &gGrayScheduleData.payload_storage[17] },
        { 0x000003C0, &gGrayScheduleData.payload_storage[18] },
    },
    // entries_7
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[0] },
    },
    // entries_8
    {
        { 0x00000000, &gGrayScheduleData.payload_storage[17] },
    },
    // payload_storage
    {
        { nullptr, 0, 208, 176, 23, 3, false },
        { gGrayScheduleData.points_1, ARRAY_COUNT(gGrayScheduleData.points_1), 632, 488, 5, 0, false },
        { gGrayScheduleData.points_2, ARRAY_COUNT(gGrayScheduleData.points_2), 220, 0, 6, 0, false },
        { gGrayScheduleData.points_3, ARRAY_COUNT(gGrayScheduleData.points_3), 148, 80, 6, 0, false },
        { gGrayScheduleData.points_4, ARRAY_COUNT(gGrayScheduleData.points_4), 1272, 0, 7, 0, false },
        { gGrayScheduleData.points_5, ARRAY_COUNT(gGrayScheduleData.points_5), 72, 144, 38, 0, true },
        { gGrayScheduleData.points_6, ARRAY_COUNT(gGrayScheduleData.points_6), 296, 116, 7, 0, false },
        { gGrayScheduleData.points_7, ARRAY_COUNT(gGrayScheduleData.points_7), 104, 704, 5, 0, false },
        { gGrayScheduleData.points_8, ARRAY_COUNT(gGrayScheduleData.points_8), 104, 704, 5, 0, false },
        { gGrayScheduleData.points_9, ARRAY_COUNT(gGrayScheduleData.points_9), 104, 704, 5, 0, false },
        { nullptr, 0, 58, 136, 24, 2, false },
        { gGrayScheduleData.points_11, ARRAY_COUNT(gGrayScheduleData.points_11), 276, 168, 5, 0, false },
        { nullptr, 0, 148, 80, 6, 1, false },
        { gGrayScheduleData.points_13, ARRAY_COUNT(gGrayScheduleData.points_13), 240, 480, 8, 0, false },
        { nullptr, 0, 232, 256, 8, 1, false },
        { gGrayScheduleData.points_15, ARRAY_COUNT(gGrayScheduleData.points_15), 232, 256, 8, 0, false },
        { gGrayScheduleData.points_16, ARRAY_COUNT(gGrayScheduleData.points_16), 812, 512, 7, 0, false },
        { nullptr, 0, 128, 80, 26, 0, false },
        { nullptr, 0, 120, 72, 27, 2, false },
        { gGrayScheduleData.points_19, ARRAY_COUNT(gGrayScheduleData.points_19), 200, 160, 5, 0, false },
        { gGrayScheduleData.points_20, ARRAY_COUNT(gGrayScheduleData.points_20), 104, 0, 7, 0, false },
        { gGrayScheduleData.points_21, ARRAY_COUNT(gGrayScheduleData.points_21), 276, 168, 5, 0, false },
    },
    // points_1
    {
        { 2, 536, true },
        { 27, 1260, false },
        { 35, 736, true },
    },
    // points_2
    {
        { 3, 80, true },
        { 6, 148, false },
    },
    // points_3
    {
        { 3, 224, false },
        { 20, 480, true },
    },
    // points_4
    {
        { 5, 128, true },
        { 6, 1248, false },
        { 7, 152, true },
        { 45, 296, false },
        { 47, 116, true },
    },
    // points_5
    {
        { 24, 2, 0, 0, false },
        { 80, 2, 120, 3, true },
        { 144, 2, 0, 0, true },
        { 72, 2, 120, 1, false },
    },
    // points_6
    {
        { 2, 152, true },
        { 10, 104, false },
        { 16, 0, true },
    },
    // points_7
    {
        { 7, 536, true },
        { 28, 632, false },
        { 30, 488, true },
    },
    // points_8
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 24, 200, false },
        { 26, 160, true },
    },
    // points_9
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 27, 276, false },
        { 29, 168, true },
    },
    // points_11
    {
        { 2, 216, true },
        { 23, 808, false },
        { 36, 536, true },
        { 43, 632, false },
        { 45, 488, true },
    },
    // points_13
    {
        { 9, 256, true },
        { 10, 232, false },
    },
    // points_15
    {
        { 1, 240, false },
        { 11, 512, true },
    },
    // points_16
    {
        { 14, 152, true },
        { 35, 296, false },
        { 37, 116, true },
    },
    // points_19
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 6, 104, false },
        { 26, 736, true },
    },
    // points_20
    {
        { 6, 152, true },
        { 14, 296, false },
        { 16, 116, true },
    },
    // points_21
    {
        { 2, 216, true },
        { 7, 200, false },
        { 9, 160, true },
    },
};
