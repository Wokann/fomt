#include "npc_schedule_manna.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectMannaSchedule\n"
    "SelectMannaSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr2, [r4, #3]\n"
    "    adds\tr4, r2, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E680\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E6C6\n"
    ".Ljp_0803E680:\n"
    "    ldr r1, .Ljp_0803E690\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E694\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E6C6\n"
    ".Ljp_0803E690: .word 0x000021CA\n"
    ".Ljp_0803E694:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E6C4\n"
    "    cmp\tr4, #6\n"
    "    bne .Ljp_0803E6C0\n"
    "    ldr r1, .Ljp_0803E6B8\n"
    "    adds\tr0, r5, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    movs\tr1, #194\t@ 0xc2\n"
    "    lsls\tr1, r1, #11\n"
    "    ands\tr0, r1\n"
    "    movs\tr1, #130\t@ 0x82\n"
    "    lsls\tr1, r1, #11\n"
    "    cmp\tr0, r1\n"
    "    bne .Ljp_0803E6BC\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E6C6\n"
    "    .align 2, 0\n"
    ".Ljp_0803E6B8: .word 0x00002174\n"
    ".Ljp_0803E6BC:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E6C6\n"
    ".Ljp_0803E6C0:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E6C6\n"
    ".Ljp_0803E6C4:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803E6C6:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    "    .align 2, 0\n"
);

extern "C" NpcScheduleStorage_080F66C4 const gUnk_080F66C4 = {
    {
        SelectMannaSchedule,
        6,
        gUnk_080F66C4.table_choices,
    },
    {
        nullptr,
        &gUnk_080F66C4.table_storage[0],
        &gUnk_080F66C4.table_storage[1],
        &gUnk_080F66C4.table_storage[2],
        &gUnk_080F66C4.table_storage[3],
        &gUnk_080F66C4.table_storage[4],
    },
    {
        { 9, &gUnk_080F66C4.entry_storage[0] },
        { 7, &gUnk_080F66C4.entry_storage[9] },
        { 11, &gUnk_080F66C4.entry_storage[16] },
        { 11, &gUnk_080F66C4.entry_storage[27] },
        { 1, &gUnk_080F66C4.entry_storage[38] },
    },
    {
        { 0x00000000, &gUnk_080F66C4.payload_storage[0] },
        { 0x0000003C, &gUnk_080F66C4.payload_storage[1] },
        { 0x000001A4, &gUnk_080F66C4.payload_storage[2] },
        { 0x000001D7, &gUnk_080F66C4.payload_storage[3] },
        { 0x000001E0, &gUnk_080F66C4.payload_storage[4] },
        { 0x00000258, &gUnk_080F66C4.payload_storage[5] },
        { 0x00000261, &gUnk_080F66C4.payload_storage[6] },
        { 0x00000293, &gUnk_080F66C4.payload_storage[18] },
        { 0x000003C0, &gUnk_080F66C4.payload_storage[0] },
        { 0x00000000, &gUnk_080F66C4.payload_storage[0] },
        { 0x0000003C, &gUnk_080F66C4.payload_storage[1] },
        { 0x000001A7, &gUnk_080F66C4.payload_storage[7] },
        { 0x000001D4, &gUnk_080F66C4.payload_storage[8] },
        { 0x0000025B, &gUnk_080F66C4.payload_storage[9] },
        { 0x00000289, &gUnk_080F66C4.payload_storage[18] },
        { 0x000003C0, &gUnk_080F66C4.payload_storage[0] },
        { 0x00000000, &gUnk_080F66C4.payload_storage[0] },
        { 0x0000003C, &gUnk_080F66C4.payload_storage[18] },
        { 0x000000F0, &gUnk_080F66C4.payload_storage[10] },
        { 0x0000010A, &gUnk_080F66C4.payload_storage[11] },
        { 0x000001A7, &gUnk_080F66C4.payload_storage[12] },
        { 0x000001E8, &gUnk_080F66C4.payload_storage[3] },
        { 0x000001F1, &gUnk_080F66C4.payload_storage[4] },
        { 0x00000258, &gUnk_080F66C4.payload_storage[5] },
        { 0x00000261, &gUnk_080F66C4.payload_storage[6] },
        { 0x00000293, &gUnk_080F66C4.payload_storage[18] },
        { 0x000003C0, &gUnk_080F66C4.payload_storage[0] },
        { 0x00000000, &gUnk_080F66C4.payload_storage[0] },
        { 0x0000003C, &gUnk_080F66C4.payload_storage[18] },
        { 0x000000F0, &gUnk_080F66C4.payload_storage[10] },
        { 0x0000010A, &gUnk_080F66C4.payload_storage[11] },
        { 0x000001A7, &gUnk_080F66C4.payload_storage[13] },
        { 0x000001D1, &gUnk_080F66C4.payload_storage[14] },
        { 0x00000266, &gUnk_080F66C4.payload_storage[15] },
        { 0x00000292, &gUnk_080F66C4.payload_storage[16] },
        { 0x0000030F, &gUnk_080F66C4.payload_storage[17] },
        { 0x0000034B, &gUnk_080F66C4.payload_storage[18] },
        { 0x000003C0, &gUnk_080F66C4.payload_storage[0] },
        { 0x00000000, &gUnk_080F66C4.payload_storage[0] },
    },
    {
        { &gUnk_080F66C4.detail_storage[0], 2, 32, 80, 32, 0, true },
        { nullptr, 0, 59, 91, 31, 0, false },
        { &gUnk_080F66C4.detail_storage[2], 3, 232, 484, 5, 0, false },
        { &gUnk_080F66C4.detail_storage[5], 2, 220, 0, 6, 0, false },
        { nullptr, 0, 328, 125, 6, 1, false },
        { &gUnk_080F66C4.detail_storage[7], 2, 328, 125, 6, 0, false },
        { &gUnk_080F66C4.detail_storage[9], 3, 1260, 704, 5, 0, false },
        { &gUnk_080F66C4.detail_storage[12], 5, 232, 484, 5, 0, false },
        { nullptr, 0, 232, 264, 15, 2, false },
        { &gUnk_080F66C4.detail_storage[17], 7, 688, 160, 5, 0, false },
        { &gUnk_080F66C4.detail_storage[24], 7, 232, 484, 5, 0, false },
        { nullptr, 0, 144, 168, 26, 2, false },
        { &gUnk_080F66C4.detail_storage[31], 5, 200, 160, 5, 0, false },
        { &gUnk_080F66C4.detail_storage[36], 7, 200, 160, 5, 0, false },
        { nullptr, 0, 79, 147, 21, 2, false },
        { &gUnk_080F66C4.detail_storage[43], 7, 632, 488, 5, 0, false },
        { nullptr, 0, 72, 195, 12, 1, false },
        { &gUnk_080F66C4.detail_storage[50], 7, 1232, 160, 5, 0, false },
        { &gUnk_080F66C4.detail_storage[57], 2, 96, 80, 31, 0, true },
    },
    {
        { 0x0050, 0x0002, 0x0078, 0x0003 },
        { 0x0020, 0x0002, 0x0078, 0x0002 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x002B, 0x04EC, 0x0000, 0x0000 },
        { 0x0033, 0x02E0, 0x0001, 0x0000 },
        { 0x0005, 0x007D, 0x0001, 0x0000 },
        { 0x0009, 0x0148, 0x0000, 0x0000 },
        { 0x0004, 0x00DC, 0x0000, 0x0000 },
        { 0x0009, 0x0000, 0x0001, 0x0000 },
        { 0x0007, 0x0218, 0x0001, 0x0000 },
        { 0x0030, 0x00E8, 0x0000, 0x0000 },
        { 0x0032, 0x01E0, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x0019, 0x0328, 0x0000, 0x0000 },
        { 0x0026, 0x00D8, 0x0001, 0x0000 },
        { 0x002B, 0x02B0, 0x0000, 0x0000 },
        { 0x002D, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0018, 0x0090, 0x0000, 0x0000 },
        { 0x0019, 0x00F0, 0x0001, 0x0000 },
        { 0x001B, 0x0068, 0x0000, 0x0000 },
        { 0x0027, 0x0218, 0x0001, 0x0000 },
        { 0x002C, 0x00E8, 0x0000, 0x0000 },
        { 0x002E, 0x01E4, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x0007, 0x0068, 0x0000, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0015, 0x0090, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x0018, 0x00C8, 0x0000, 0x0000 },
        { 0x001A, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x002B, 0x04E0, 0x0000, 0x0000 },
        { 0x002C, 0x00F0, 0x0001, 0x0000 },
        { 0x002D, 0x04EC, 0x0000, 0x0000 },
        { 0x0041, 0x02E0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0004, 0x0090, 0x0000, 0x0000 },
        { 0x0005, 0x00F0, 0x0001, 0x0000 },
        { 0x0007, 0x0068, 0x0000, 0x0000 },
        { 0x0013, 0x0218, 0x0001, 0x0000 },
        { 0x0028, 0x0278, 0x0000, 0x0000 },
        { 0x002A, 0x01E8, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x001B, 0x04EC, 0x0000, 0x0000 },
        { 0x0027, 0x00F0, 0x0001, 0x0000 },
        { 0x0028, 0x04E0, 0x0000, 0x0000 },
        { 0x0029, 0x00D8, 0x0001, 0x0000 },
        { 0x002A, 0x04D0, 0x0000, 0x0000 },
        { 0x002C, 0x009C, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0003, 0x04E0, 0x0000, 0x0000 },
        { 0x0004, 0x00F0, 0x0001, 0x0000 },
        { 0x0005, 0x04EC, 0x0000, 0x0000 },
        { 0x0011, 0x0218, 0x0001, 0x0000 },
        { 0x003A, 0x00E8, 0x0000, 0x0000 },
        { 0x003C, 0x01E4, 0x0001, 0x0000 },
        { 0x0020, 0x0002, 0x0078, 0x0002 },
        { 0x0060, 0x0002, 0x0078, 0x0001 },
    },
};
