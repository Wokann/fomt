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

extern "C" NpcScheduleStorage_080F7294 const gUnk_080F7294 = {
    {
        SelectGraySchedule,
        10,
        gUnk_080F7294.table_choices,
    },
    {
        nullptr,
        &gUnk_080F7294.table_storage[0],
        &gUnk_080F7294.table_storage[1],
        &gUnk_080F7294.table_storage[2],
        &gUnk_080F7294.table_storage[3],
        &gUnk_080F7294.table_storage[4],
        &gUnk_080F7294.table_storage[5],
        &gUnk_080F7294.table_storage[6],
        &gUnk_080F7294.table_storage[7],
        &gUnk_080F7294.table_storage[8],
    },
    {
        { 10, &gUnk_080F7294.entry_storage[0] },
        { 9, &gUnk_080F7294.entry_storage[10] },
        { 7, &gUnk_080F7294.entry_storage[19] },
        { 12, &gUnk_080F7294.entry_storage[26] },
        { 10, &gUnk_080F7294.entry_storage[38] },
        { 9, &gUnk_080F7294.entry_storage[48] },
        { 9, &gUnk_080F7294.entry_storage[57] },
        { 1, &gUnk_080F7294.entry_storage[66] },
        { 1, &gUnk_080F7294.entry_storage[67] },
    },
    {
        { 0x00000000, &gUnk_080F7294.payload_storage[0] },
        { 0x0000003F, &gUnk_080F7294.payload_storage[1] },
        { 0x00000062, &gUnk_080F7294.payload_storage[2] },
        { 0x00000068, &gUnk_080F7294.payload_storage[12] },
        { 0x000000B4, &gUnk_080F7294.payload_storage[3] },
        { 0x000000C8, &gUnk_080F7294.payload_storage[4] },
        { 0x000000F7, &gUnk_080F7294.payload_storage[5] },
        { 0x000001A4, &gUnk_080F7294.payload_storage[6] },
        { 0x000001B4, &gUnk_080F7294.payload_storage[7] },
        { 0x000001D2, &gUnk_080F7294.payload_storage[0] },
        { 0x00000000, &gUnk_080F7294.payload_storage[0] },
        { 0x0000003F, &gUnk_080F7294.payload_storage[1] },
        { 0x00000062, &gUnk_080F7294.payload_storage[4] },
        { 0x00000091, &gUnk_080F7294.payload_storage[5] },
        { 0x000001A4, &gUnk_080F7294.payload_storage[6] },
        { 0x000001B4, &gUnk_080F7294.payload_storage[9] },
        { 0x000001D1, &gUnk_080F7294.payload_storage[10] },
        { 0x00000258, &gUnk_080F7294.payload_storage[11] },
        { 0x00000285, &gUnk_080F7294.payload_storage[0] },
        { 0x00000000, &gUnk_080F7294.payload_storage[0] },
        { 0x0000003F, &gUnk_080F7294.payload_storage[1] },
        { 0x00000062, &gUnk_080F7294.payload_storage[4] },
        { 0x00000091, &gUnk_080F7294.payload_storage[5] },
        { 0x000001A4, &gUnk_080F7294.payload_storage[6] },
        { 0x000001B4, &gUnk_080F7294.payload_storage[7] },
        { 0x000001D2, &gUnk_080F7294.payload_storage[0] },
        { 0x00000000, &gUnk_080F7294.payload_storage[0] },
        { 0x0000003F, &gUnk_080F7294.payload_storage[1] },
        { 0x00000062, &gUnk_080F7294.payload_storage[13] },
        { 0x0000006C, &gUnk_080F7294.payload_storage[14] },
        { 0x000000F1, &gUnk_080F7294.payload_storage[15] },
        { 0x000000FC, &gUnk_080F7294.payload_storage[16] },
        { 0x00000121, &gUnk_080F7294.payload_storage[5] },
        { 0x000001A4, &gUnk_080F7294.payload_storage[6] },
        { 0x000001B4, &gUnk_080F7294.payload_storage[9] },
        { 0x000001D1, &gUnk_080F7294.payload_storage[10] },
        { 0x00000258, &gUnk_080F7294.payload_storage[11] },
        { 0x00000285, &gUnk_080F7294.payload_storage[0] },
        { 0x00000000, &gUnk_080F7294.payload_storage[17] },
        { 0x0000003C, &gUnk_080F7294.payload_storage[19] },
        { 0x00000056, &gUnk_080F7294.payload_storage[20] },
        { 0x00000066, &gUnk_080F7294.payload_storage[5] },
        { 0x000001A4, &gUnk_080F7294.payload_storage[6] },
        { 0x000001B4, &gUnk_080F7294.payload_storage[9] },
        { 0x000001D1, &gUnk_080F7294.payload_storage[10] },
        { 0x00000258, &gUnk_080F7294.payload_storage[21] },
        { 0x00000261, &gUnk_080F7294.payload_storage[17] },
        { 0x000003C0, &gUnk_080F7294.payload_storage[18] },
        { 0x00000000, &gUnk_080F7294.payload_storage[18] },
        { 0x0000003C, &gUnk_080F7294.payload_storage[17] },
        { 0x000001A7, &gUnk_080F7294.payload_storage[19] },
        { 0x000001C1, &gUnk_080F7294.payload_storage[13] },
        { 0x000001CB, &gUnk_080F7294.payload_storage[14] },
        { 0x0000025A, &gUnk_080F7294.payload_storage[15] },
        { 0x00000265, &gUnk_080F7294.payload_storage[8] },
        { 0x0000027F, &gUnk_080F7294.payload_storage[17] },
        { 0x000003C0, &gUnk_080F7294.payload_storage[18] },
        { 0x00000000, &gUnk_080F7294.payload_storage[18] },
        { 0x0000003C, &gUnk_080F7294.payload_storage[17] },
        { 0x000001A7, &gUnk_080F7294.payload_storage[19] },
        { 0x000001C1, &gUnk_080F7294.payload_storage[20] },
        { 0x000001D1, &gUnk_080F7294.payload_storage[5] },
        { 0x0000025B, &gUnk_080F7294.payload_storage[6] },
        { 0x0000026B, &gUnk_080F7294.payload_storage[8] },
        { 0x00000285, &gUnk_080F7294.payload_storage[17] },
        { 0x000003C0, &gUnk_080F7294.payload_storage[18] },
        { 0x00000000, &gUnk_080F7294.payload_storage[0] },
        { 0x00000000, &gUnk_080F7294.payload_storage[17] },
    },
    {
        { nullptr, 0, 208, 176, 23, 3, false },
        { &gUnk_080F7294.detail_storage[0], 3, 632, 488, 5, 0, false },
        { &gUnk_080F7294.detail_storage[3], 2, 220, 0, 6, 0, false },
        { &gUnk_080F7294.detail_storage[5], 2, 148, 80, 6, 0, false },
        { &gUnk_080F7294.detail_storage[7], 5, 1272, 0, 7, 0, false },
        { &gUnk_080F7294.detail_storage[12], 4, 72, 144, 38, 0, true },
        { &gUnk_080F7294.detail_storage[16], 3, 296, 116, 7, 0, false },
        { &gUnk_080F7294.detail_storage[19], 3, 104, 704, 5, 0, false },
        { &gUnk_080F7294.detail_storage[22], 5, 104, 704, 5, 0, false },
        { &gUnk_080F7294.detail_storage[27], 5, 104, 704, 5, 0, false },
        { nullptr, 0, 58, 136, 24, 2, false },
        { &gUnk_080F7294.detail_storage[32], 5, 276, 168, 5, 0, false },
        { nullptr, 0, 148, 80, 6, 1, false },
        { &gUnk_080F7294.detail_storage[37], 2, 240, 480, 8, 0, false },
        { nullptr, 0, 232, 256, 8, 1, false },
        { &gUnk_080F7294.detail_storage[39], 2, 232, 256, 8, 0, false },
        { &gUnk_080F7294.detail_storage[41], 3, 812, 512, 7, 0, false },
        { nullptr, 0, 128, 80, 26, 0, false },
        { nullptr, 0, 120, 72, 27, 2, false },
        { &gUnk_080F7294.detail_storage[44], 5, 200, 160, 5, 0, false },
        { &gUnk_080F7294.detail_storage[49], 3, 104, 0, 7, 0, false },
        { &gUnk_080F7294.detail_storage[52], 3, 276, 168, 5, 0, false },
    },
    {
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x001B, 0x04EC, 0x0000, 0x0000 },
        { 0x0023, 0x02E0, 0x0001, 0x0000 },
        { 0x0003, 0x0050, 0x0001, 0x0000 },
        { 0x0006, 0x0094, 0x0000, 0x0000 },
        { 0x0003, 0x00E0, 0x0000, 0x0000 },
        { 0x0014, 0x01E0, 0x0001, 0x0000 },
        { 0x0005, 0x0080, 0x0001, 0x0000 },
        { 0x0006, 0x04E0, 0x0000, 0x0000 },
        { 0x0007, 0x0098, 0x0001, 0x0000 },
        { 0x002D, 0x0128, 0x0000, 0x0000 },
        { 0x002F, 0x0074, 0x0001, 0x0000 },
        { 0x0018, 0x0002, 0x0000, 0x0000 },
        { 0x0050, 0x0002, 0x0078, 0x0007 },
        { 0x0090, 0x0002, 0x0000, 0x0004 },
        { 0x0048, 0x0002, 0x0078, 0x0001 },
        { 0x0002, 0x0098, 0x0001, 0x0000 },
        { 0x000A, 0x0068, 0x0000, 0x0000 },
        { 0x0010, 0x0000, 0x0001, 0x0000 },
        { 0x0007, 0x0218, 0x0001, 0x0000 },
        { 0x001C, 0x0278, 0x0000, 0x0000 },
        { 0x001E, 0x01E8, 0x0001, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0015, 0x0090, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x0018, 0x00C8, 0x0000, 0x0000 },
        { 0x001A, 0x00A0, 0x0001, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0015, 0x0090, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x001B, 0x0114, 0x0000, 0x0000 },
        { 0x001D, 0x00A8, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0017, 0x0328, 0x0000, 0x0000 },
        { 0x0024, 0x0218, 0x0001, 0x0000 },
        { 0x002B, 0x0278, 0x0000, 0x0000 },
        { 0x002D, 0x01E8, 0x0001, 0x0000 },
        { 0x0009, 0x0100, 0x0001, 0x0000 },
        { 0x000A, 0x00E8, 0x0000, 0x0000 },
        { 0x0001, 0x00F0, 0x0000, 0x0000 },
        { 0x000B, 0x0200, 0x0001, 0x0000 },
        { 0x000E, 0x0098, 0x0001, 0x0000 },
        { 0x0023, 0x0128, 0x0000, 0x0000 },
        { 0x0025, 0x0074, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0004, 0x0090, 0x0000, 0x0000 },
        { 0x0005, 0x00F0, 0x0001, 0x0000 },
        { 0x0006, 0x0068, 0x0000, 0x0000 },
        { 0x001A, 0x02E0, 0x0001, 0x0000 },
        { 0x0006, 0x0098, 0x0001, 0x0000 },
        { 0x000E, 0x0128, 0x0000, 0x0000 },
        { 0x0010, 0x0074, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0007, 0x00C8, 0x0000, 0x0000 },
        { 0x0009, 0x00A0, 0x0001, 0x0000 },
    },
};
