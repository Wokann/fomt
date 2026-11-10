#include "npc_schedule_thomas.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectThomasSchedule\n"
    "SelectThomasSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr2, [r4, #1]\n"
    "    ldrb\tr3, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    cmp\tr2, #3\n"
    "    bne .Ljp_0803E3B4\n"
    "    cmp\tr3, #2\n"
    "    bne .Ljp_0803E3B4\n"
    "    ldr r1, .Ljp_0803E3A8\n"
    "    adds\tr0, r5, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    movs\tr1, #134\t@ 0x86\n"
    "    lsls\tr1, r1, #11\n"
    "    ands\tr0, r1\n"
    "    movs\tr1, #128\t@ 0x80\n"
    "    lsls\tr1, r1, #6\n"
    "    cmp\tr0, r1\n"
    "    bne .Ljp_0803E3B4\n"
    "    ldr r1, .Ljp_0803E3AC\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803E3B0\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803E3EC\n"
    "    .align 2, 0\n"
    ".Ljp_0803E3A8: .word 0x00002178\n"
    ".Ljp_0803E3AC: .word 0x0000217A\n"
    ".Ljp_0803E3B0:\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E3EC\n"
    ".Ljp_0803E3B4:\n"
    "    adds\tr0, r2, #0\n"
    "    adds\tr1, r3, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E3C6\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803E3EC\n"
    ".Ljp_0803E3C6:\n"
    "    cmp\tr4, #6\n"
    "    bne .Ljp_0803E3D8\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E3D4\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E3EC\n"
    ".Ljp_0803E3D4:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E3EC\n"
    ".Ljp_0803E3D8:\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_0803E3EA\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E3E6\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E3EC\n"
    ".Ljp_0803E3E6:\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E3EC\n"
    ".Ljp_0803E3EA:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E3EC:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" NpcScheduleStorage_080F59CC const gUnk_080F59CC = {
    {
        SelectThomasSchedule,
        8,
        gUnk_080F59CC.table_choices,
    },
    {
        nullptr,
        &gUnk_080F59CC.table_storage[0],
        &gUnk_080F59CC.table_storage[1],
        &gUnk_080F59CC.table_storage[2],
        &gUnk_080F59CC.table_storage[3],
        &gUnk_080F59CC.table_storage[4],
        &gUnk_080F59CC.table_storage[5],
        &gUnk_080F59CC.table_storage[6],
    },
    {
        { 1, &gUnk_080F59CC.entry_storage[0] },
        { 11, &gUnk_080F59CC.entry_storage[1] },
        { 9, &gUnk_080F59CC.entry_storage[12] },
        { 9, &gUnk_080F59CC.entry_storage[21] },
        { 7, &gUnk_080F59CC.entry_storage[30] },
        { 1, &gUnk_080F59CC.entry_storage[37] },
        { 5, &gUnk_080F59CC.entry_storage[38] },
    },
    {
        { 0x00000000, &gUnk_080F59CC.payload_storage[0] },
        { 0x00000000, &gUnk_080F59CC.payload_storage[0] },
        { 0x0000003F, &gUnk_080F59CC.payload_storage[1] },
        { 0x0000004C, &gUnk_080F59CC.payload_storage[2] },
        { 0x000000F6, &gUnk_080F59CC.payload_storage[3] },
        { 0x00000106, &gUnk_080F59CC.payload_storage[4] },
        { 0x000001A9, &gUnk_080F59CC.payload_storage[5] },
        { 0x000001E3, &gUnk_080F59CC.payload_storage[6] },
        { 0x000001E9, &gUnk_080F59CC.payload_storage[7] },
        { 0x00000260, &gUnk_080F59CC.payload_storage[8] },
        { 0x00000266, &gUnk_080F59CC.payload_storage[9] },
        { 0x0000029C, &gUnk_080F59CC.payload_storage[0] },
        { 0x00000000, &gUnk_080F59CC.payload_storage[0] },
        { 0x0000003F, &gUnk_080F59CC.payload_storage[1] },
        { 0x0000004C, &gUnk_080F59CC.payload_storage[2] },
        { 0x000000F4, &gUnk_080F59CC.payload_storage[3] },
        { 0x00000104, &gUnk_080F59CC.payload_storage[4] },
        { 0x000001A4, &gUnk_080F59CC.payload_storage[10] },
        { 0x000001CC, &gUnk_080F59CC.payload_storage[11] },
        { 0x0000025D, &gUnk_080F59CC.payload_storage[12] },
        { 0x00000282, &gUnk_080F59CC.payload_storage[0] },
        { 0x00000000, &gUnk_080F59CC.payload_storage[0] },
        { 0x000000F0, &gUnk_080F59CC.payload_storage[13] },
        { 0x000000F7, &gUnk_080F59CC.payload_storage[4] },
        { 0x000001A6, &gUnk_080F59CC.payload_storage[5] },
        { 0x000001E0, &gUnk_080F59CC.payload_storage[6] },
        { 0x000001E6, &gUnk_080F59CC.payload_storage[7] },
        { 0x00000260, &gUnk_080F59CC.payload_storage[8] },
        { 0x00000266, &gUnk_080F59CC.payload_storage[9] },
        { 0x0000029C, &gUnk_080F59CC.payload_storage[0] },
        { 0x00000000, &gUnk_080F59CC.payload_storage[0] },
        { 0x000000F0, &gUnk_080F59CC.payload_storage[13] },
        { 0x000000F7, &gUnk_080F59CC.payload_storage[4] },
        { 0x000001A4, &gUnk_080F59CC.payload_storage[10] },
        { 0x000001CC, &gUnk_080F59CC.payload_storage[11] },
        { 0x0000025A, &gUnk_080F59CC.payload_storage[12] },
        { 0x0000027F, &gUnk_080F59CC.payload_storage[0] },
        { 0x00000000, &gUnk_080F59CC.payload_storage[0] },
        { 0x00000000, &gUnk_080F59CC.payload_storage[17] },
        { 0x0000030C, &gUnk_080F59CC.payload_storage[14] },
        { 0x00000316, &gUnk_080F59CC.payload_storage[15] },
        { 0x00000348, &gUnk_080F59CC.payload_storage[16] },
        { 0x00000352, &gUnk_080F59CC.payload_storage[17] },
    },
    {
        { nullptr, 0, 120, 104, 30, 0, false },
        { &gUnk_080F59CC.detail_storage[0], 3, 480, 160, 5, 0, false },
        { nullptr, 0, 88, 216, 15, 0, false },
        { &gUnk_080F59CC.detail_storage[3], 3, 688, 160, 5, 0, false },
        { nullptr, 0, 128, 136, 14, 1, false },
        { &gUnk_080F59CC.detail_storage[6], 5, 400, 160, 5, 0, false },
        { &gUnk_080F59CC.detail_storage[11], 2, 220, 0, 6, 0, false },
        { nullptr, 0, 148, 80, 6, 1, false },
        { &gUnk_080F59CC.detail_storage[13], 2, 148, 80, 6, 0, false },
        { &gUnk_080F59CC.detail_storage[15], 5, 1260, 704, 5, 0, false },
        { &gUnk_080F59CC.detail_storage[20], 5, 400, 160, 5, 0, false },
        { nullptr, 0, 81, 235, 21, 3, false },
        { &gUnk_080F59CC.detail_storage[25], 5, 632, 488, 5, 0, false },
        { &gUnk_080F59CC.detail_storage[30], 3, 480, 160, 5, 0, false },
        { &gUnk_080F59CC.detail_storage[33], 2, 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { &gUnk_080F59CC.detail_storage[35], 2, 228, 145, 2, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
    },
    {
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x000B, 0x02B0, 0x0000, 0x0000 },
        { 0x000D, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x000E, 0x0190, 0x0000, 0x0000 },
        { 0x0010, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0024, 0x04E0, 0x0000, 0x0000 },
        { 0x0025, 0x00F0, 0x0001, 0x0000 },
        { 0x0026, 0x04EC, 0x0000, 0x0000 },
        { 0x003A, 0x02E0, 0x0001, 0x0000 },
        { 0x0003, 0x0050, 0x0001, 0x0000 },
        { 0x0006, 0x0094, 0x0000, 0x0000 },
        { 0x0003, 0x00DC, 0x0000, 0x0000 },
        { 0x0006, 0x0000, 0x0001, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0014, 0x04E0, 0x0000, 0x0000 },
        { 0x0015, 0x00D8, 0x0001, 0x0000 },
        { 0x0034, 0x01E0, 0x0000, 0x0000 },
        { 0x0036, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0012, 0x0328, 0x0000, 0x0000 },
        { 0x001F, 0x0218, 0x0001, 0x0000 },
        { 0x0026, 0x0278, 0x0000, 0x0000 },
        { 0x0028, 0x01E8, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x0009, 0x0328, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x0023, 0x01E0, 0x0000, 0x0000 },
        { 0x0025, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0005, 0x0190, 0x0000, 0x0000 },
        { 0x0007, 0x00A0, 0x0001, 0x0000 },
        { 0x0006, 0x0091, 0x0001, 0x0000 },
        { 0x000A, 0x00E4, 0x0000, 0x0000 },
        { 0x0004, 0x0154, 0x0000, 0x0000 },
        { 0x000A, 0x0000, 0x0001, 0x0000 },
    },
};
