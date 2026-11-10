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

extern "C" NpcScheduleStorage_080F7B40 const gUnk_080F7B40 = {
    {
        SelectGotzSchedule,
        15,
        gUnk_080F7B40.table_choices,
    },
    {
        nullptr,
        &gUnk_080F7B40.table_storage[0],
        &gUnk_080F7B40.table_storage[1],
        &gUnk_080F7B40.table_storage[2],
        &gUnk_080F7B40.table_storage[3],
        &gUnk_080F7B40.table_storage[4],
        &gUnk_080F7B40.table_storage[5],
        &gUnk_080F7B40.table_storage[6],
        &gUnk_080F7B40.table_storage[7],
        &gUnk_080F7B40.table_storage[8],
        &gUnk_080F7B40.table_storage[9],
        &gUnk_080F7B40.table_storage[10],
        &gUnk_080F7B40.table_storage[11],
        &gUnk_080F7B40.table_storage[12],
        &gUnk_080F7B40.table_storage[13],
    },
    {
        { 7, &gUnk_080F7B40.entry_storage[0] },
        { 11, &gUnk_080F7B40.entry_storage[7] },
        { 12, &gUnk_080F7B40.entry_storage[18] },
        { 7, &gUnk_080F7B40.entry_storage[30] },
        { 1, &gUnk_080F7B40.entry_storage[37] },
        { 1, &gUnk_080F7B40.entry_storage[38] },
        { 1, &gUnk_080F7B40.entry_storage[39] },
        { 1, &gUnk_080F7B40.entry_storage[40] },
        { 1, &gUnk_080F7B40.entry_storage[41] },
        { 1, &gUnk_080F7B40.entry_storage[42] },
        { 1, &gUnk_080F7B40.entry_storage[43] },
        { 1, &gUnk_080F7B40.entry_storage[44] },
        { 1, &gUnk_080F7B40.entry_storage[45] },
        { 1, &gUnk_080F7B40.entry_storage[46] },
    },
    {
        { 0x00000000, &gUnk_080F7B40.payload_storage[0] },
        { 0x0000003C, &gUnk_080F7B40.payload_storage[1] },
        { 0x0000005E, &gUnk_080F7B40.payload_storage[2] },
        { 0x00000087, &gUnk_080F7B40.payload_storage[3] },
        { 0x000000F0, &gUnk_080F7B40.payload_storage[4] },
        { 0x0000011A, &gUnk_080F7B40.payload_storage[5] },
        { 0x0000013B, &gUnk_080F7B40.payload_storage[0] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[0] },
        { 0x0000003C, &gUnk_080F7B40.payload_storage[1] },
        { 0x0000005E, &gUnk_080F7B40.payload_storage[2] },
        { 0x00000087, &gUnk_080F7B40.payload_storage[3] },
        { 0x000000F0, &gUnk_080F7B40.payload_storage[4] },
        { 0x0000011A, &gUnk_080F7B40.payload_storage[5] },
        { 0x0000013B, &gUnk_080F7B40.payload_storage[0] },
        { 0x000001AA, &gUnk_080F7B40.payload_storage[6] },
        { 0x000001B5, &gUnk_080F7B40.payload_storage[7] },
        { 0x00000258, &gUnk_080F7B40.payload_storage[8] },
        { 0x00000263, &gUnk_080F7B40.payload_storage[0] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[0] },
        { 0x0000003C, &gUnk_080F7B40.payload_storage[1] },
        { 0x0000005E, &gUnk_080F7B40.payload_storage[2] },
        { 0x00000087, &gUnk_080F7B40.payload_storage[3] },
        { 0x000000F0, &gUnk_080F7B40.payload_storage[4] },
        { 0x0000011A, &gUnk_080F7B40.payload_storage[9] },
        { 0x0000013F, &gUnk_080F7B40.payload_storage[10] },
        { 0x000001A4, &gUnk_080F7B40.payload_storage[11] },
        { 0x000001B0, &gUnk_080F7B40.payload_storage[12] },
        { 0x0000025E, &gUnk_080F7B40.payload_storage[13] },
        { 0x0000028C, &gUnk_080F7B40.payload_storage[14] },
        { 0x000002A3, &gUnk_080F7B40.payload_storage[0] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[0] },
        { 0x000001A4, &gUnk_080F7B40.payload_storage[1] },
        { 0x000001C6, &gUnk_080F7B40.payload_storage[15] },
        { 0x000001CD, &gUnk_080F7B40.payload_storage[16] },
        { 0x00000258, &gUnk_080F7B40.payload_storage[17] },
        { 0x00000260, &gUnk_080F7B40.payload_storage[5] },
        { 0x00000281, &gUnk_080F7B40.payload_storage[0] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[0] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[18] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[19] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[21] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[22] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[20] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[20] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[20] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[20] },
        { 0x00000000, &gUnk_080F7B40.payload_storage[23] },
    },
    {
        { nullptr, 0, 200, 91, 40, 0, false },
        { &gUnk_080F7B40.detail_storage[0], 8, 614, 244, 3, 0, false },
        { &gUnk_080F7B40.detail_storage[8], 16, 1200, 752, 0, 0, false },
        { &gUnk_080F7B40.detail_storage[24], 2, 384, 608, 0, 0, true },
        { &gUnk_080F7B40.detail_storage[26], 16, 384, 608, 0, 0, false },
        { &gUnk_080F7B40.detail_storage[42], 8, 0, 448, 3, 0, false },
        { &gUnk_080F7B40.detail_storage[50], 3, 614, 244, 3, 0, false },
        { &gUnk_080F7B40.detail_storage[53], 2, 512, 170, 3, 0, true },
        { &gUnk_080F7B40.detail_storage[55], 3, 512, 170, 3, 0, false },
        { &gUnk_080F7B40.detail_storage[58], 5, 104, 704, 5, 0, false },
        { &gUnk_080F7B40.detail_storage[63], 2, 80, 88, 30, 0, true },
        { &gUnk_080F7B40.detail_storage[65], 3, 480, 160, 5, 0, false },
        { nullptr, 0, 56, 136, 15, 3, false },
        { &gUnk_080F7B40.detail_storage[68], 5, 688, 160, 5, 0, false },
        { &gUnk_080F7B40.detail_storage[73], 3, 832, 0, 3, 0, false },
        { &gUnk_080F7B40.detail_storage[76], 2, 240, 480, 8, 0, false },
        { nullptr, 0, 352, 400, 8, 3, false },
        { &gUnk_080F7B40.detail_storage[78], 2, 352, 400, 8, 0, false },
        { &gUnk_080F7B40.detail_storage[80], 3, 32, 83, 29, 0, true },
        { &gUnk_080F7B40.detail_storage[83], 3, 32, 124, 29, 0, true },
        { &gUnk_080F7B40.detail_storage[86], 3, 32, 98, 29, 0, true },
        { &gUnk_080F7B40.detail_storage[89], 3, 208, 160, 17, 0, true },
        { &gUnk_080F7B40.detail_storage[92], 3, 328, 196, 37, 0, true },
        { &gUnk_080F7B40.detail_storage[95], 5, 539, 95, 7, 0, true },
    },
    {
        { 0x0002, 0x0128, 0x0001, 0x0000 },
        { 0x0014, 0x00A8, 0x0000, 0x0000 },
        { 0x0016, 0x0158, 0x0001, 0x0000 },
        { 0x0018, 0x0078, 0x0000, 0x0000 },
        { 0x001A, 0x0188, 0x0001, 0x0000 },
        { 0x001D, 0x003C, 0x0000, 0x0000 },
        { 0x001F, 0x01C0, 0x0001, 0x0000 },
        { 0x0022, 0xFFF0, 0x0000, 0x0000 },
        { 0x000C, 0x0390, 0x0000, 0x0000 },
        { 0x000D, 0x02D8, 0x0001, 0x0000 },
        { 0x000F, 0x0358, 0x0000, 0x0000 },
        { 0x0010, 0x02C0, 0x0001, 0x0000 },
        { 0x0011, 0x0340, 0x0000, 0x0000 },
        { 0x0012, 0x02A8, 0x0001, 0x0000 },
        { 0x0013, 0x0328, 0x0000, 0x0000 },
        { 0x0014, 0x0290, 0x0001, 0x0000 },
        { 0x0015, 0x0308, 0x0000, 0x0000 },
        { 0x0016, 0x0270, 0x0001, 0x0000 },
        { 0x0017, 0x02F0, 0x0000, 0x0000 },
        { 0x0018, 0x0250, 0x0001, 0x0000 },
        { 0x0019, 0x02D0, 0x0000, 0x0000 },
        { 0x001A, 0x0238, 0x0001, 0x0000 },
        { 0x0027, 0x0180, 0x0000, 0x0000 },
        { 0x0029, 0x0260, 0x0001, 0x0000 },
        { 0x0140, 0x0002, 0x0078, 0x0000 },
        { 0x0180, 0x0002, 0x0078, 0x0000 },
        { 0x0002, 0x0238, 0x0001, 0x0000 },
        { 0x000F, 0x02D0, 0x0000, 0x0000 },
        { 0x0010, 0x0250, 0x0001, 0x0000 },
        { 0x0011, 0x02F0, 0x0000, 0x0000 },
        { 0x0012, 0x0270, 0x0001, 0x0000 },
        { 0x0013, 0x0307, 0x0000, 0x0000 },
        { 0x0014, 0x0290, 0x0001, 0x0000 },
        { 0x0015, 0x0328, 0x0000, 0x0000 },
        { 0x0016, 0x02A8, 0x0001, 0x0000 },
        { 0x0017, 0x0340, 0x0000, 0x0000 },
        { 0x0018, 0x02C0, 0x0001, 0x0000 },
        { 0x0019, 0x0358, 0x0000, 0x0000 },
        { 0x001A, 0x02D8, 0x0001, 0x0000 },
        { 0x001C, 0x0390, 0x0000, 0x0000 },
        { 0x001D, 0x02F0, 0x0001, 0x0000 },
        { 0x002A, 0x04C0, 0x0000, 0x0000 },
        { 0x0002, 0x0038, 0x0000, 0x0000 },
        { 0x0004, 0x0188, 0x0001, 0x0000 },
        { 0x0007, 0x0078, 0x0000, 0x0000 },
        { 0x0009, 0x0158, 0x0001, 0x0000 },
        { 0x000B, 0x00A8, 0x0000, 0x0000 },
        { 0x000D, 0x0128, 0x0001, 0x0000 },
        { 0x001F, 0x0266, 0x0000, 0x0000 },
        { 0x0021, 0x00F4, 0x0001, 0x0000 },
        { 0x0002, 0x0128, 0x0001, 0x0000 },
        { 0x0006, 0x0200, 0x0000, 0x0000 },
        { 0x000B, 0x00AA, 0x0001, 0x0000 },
        { 0x01B0, 0x0002, 0x0078, 0x0001 },
        { 0x0200, 0x0002, 0x0078, 0x0001 },
        { 0x0005, 0x0128, 0x0001, 0x0000 },
        { 0x0009, 0x0266, 0x0000, 0x0000 },
        { 0x000B, 0x00F4, 0x0001, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0015, 0x0090, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x0023, 0x01E0, 0x0000, 0x0000 },
        { 0x0025, 0x00A0, 0x0001, 0x0000 },
        { 0x0018, 0x0002, 0x0078, 0x0002 },
        { 0x0050, 0x0002, 0x0078, 0x0003 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x000A, 0x02B0, 0x0000, 0x0000 },
        { 0x000C, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0007, 0x0328, 0x0000, 0x0000 },
        { 0x0014, 0x0218, 0x0001, 0x0000 },
        { 0x0026, 0x04EC, 0x0000, 0x0000 },
        { 0x002E, 0x02E0, 0x0001, 0x0000 },
        { 0x000C, 0x0128, 0x0001, 0x0000 },
        { 0x0015, 0x0266, 0x0000, 0x0000 },
        { 0x0017, 0x00F4, 0x0001, 0x0000 },
        { 0x0003, 0x0190, 0x0001, 0x0000 },
        { 0x0007, 0x0160, 0x0000, 0x0000 },
        { 0x0004, 0x00F0, 0x0000, 0x0000 },
        { 0x0008, 0x0200, 0x0001, 0x0000 },
        { 0x0053, 0x0002, 0x012C, 0x0006 },
        { 0x0085, 0x0002, 0x012C, 0x0006 },
        { 0x0053, 0x0002, 0x012C, 0x0006 },
        { 0x007C, 0x0002, 0x012C, 0x0006 },
        { 0x00A2, 0x0002, 0x012C, 0x0006 },
        { 0x007C, 0x0002, 0x012C, 0x0006 },
        { 0x0062, 0x0002, 0x012C, 0x0006 },
        { 0x0094, 0x0002, 0x012C, 0x0006 },
        { 0x0062, 0x0002, 0x012C, 0x0006 },
        { 0x00A0, 0x0002, 0x012C, 0x0007 },
        { 0x006E, 0x0002, 0x012C, 0x0007 },
        { 0x00A0, 0x0002, 0x012C, 0x0007 },
        { 0x00C4, 0x0002, 0x012C, 0x0007 },
        { 0x00E0, 0x0002, 0x012C, 0x0007 },
        { 0x00C4, 0x0002, 0x012C, 0x0007 },
        { 0x005F, 0x0002, 0x012C, 0x0006 },
        { 0x0023, 0x0002, 0x012C, 0x0006 },
        { 0x005F, 0x0002, 0x012C, 0x0007 },
        { 0x0023, 0x0002, 0x012C, 0x0007 },
        { 0x005F, 0x0002, 0x012C, 0x0006 },
    },
};
