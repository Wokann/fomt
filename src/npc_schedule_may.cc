#include "npc_schedule_may.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectMaySchedule\n"
    "SelectMaySchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr6, [r4, #1]\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    adds\tr7, r0, #0\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803EA6C\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803EABC\n"
    ".Ljp_0803EA6C:\n"
    "    cmp\tr6, #2\n"
    "    bne .Ljp_0803EA8C\n"
    "    cmp\tr7, #30\n"
    "    bne .Ljp_0803EA8C\n"
    "    ldr r1, .Ljp_0803EA88\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803EA8C\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803EABC\n"
    "    .align 2, 0\n"
    ".Ljp_0803EA88: .word 0x000021A2\n"
    ".Ljp_0803EA8C:\n"
    "    ldr r1, .Ljp_0803EA9C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803EAA0\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803EABC\n"
    ".Ljp_0803EA9C: .word 0x0000215A\n"
    ".Ljp_0803EAA0:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803EABA\n"
    "    cmp\tr4, #1\n"
    "    bne .Ljp_0803EAAE\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803EABC\n"
    ".Ljp_0803EAAE:\n"
    "    cmp\tr4, #3\n"
    "    bne .Ljp_0803EAB6\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803EABC\n"
    ".Ljp_0803EAB6:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803EABC\n"
    ".Ljp_0803EABA:\n"
    "    movs\tr0, #4\n"
    ".Ljp_0803EABC:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" NpcScheduleStorage_080F81BC const gUnk_080F81BC = {
    {
        SelectMaySchedule,
        7,
        gUnk_080F81BC.table_choices,
    },
    {
        nullptr,
        &gUnk_080F81BC.table_storage[0],
        &gUnk_080F81BC.table_storage[1],
        &gUnk_080F81BC.table_storage[2],
        &gUnk_080F81BC.table_storage[3],
        &gUnk_080F81BC.table_storage[4],
        &gUnk_080F81BC.table_storage[5],
    },
    {
        { 12, &gUnk_080F81BC.entry_storage[0] },
        { 10, &gUnk_080F81BC.entry_storage[12] },
        { 12, &gUnk_080F81BC.entry_storage[22] },
        { 1, &gUnk_080F81BC.entry_storage[34] },
        { 1, &gUnk_080F81BC.entry_storage[35] },
        { 4, &gUnk_080F81BC.entry_storage[36] },
    },
    {
        { 0x00000000, &gUnk_080F81BC.payload_storage[0] },
        { 0x0000003C, &gUnk_080F81BC.payload_storage[2] },
        { 0x0000003F, &gUnk_080F81BC.payload_storage[3] },
        { 0x0000012C, &gUnk_080F81BC.payload_storage[4] },
        { 0x0000012F, &gUnk_080F81BC.payload_storage[0] },
        { 0x000001A4, &gUnk_080F81BC.payload_storage[5] },
        { 0x000001C6, &gUnk_080F81BC.payload_storage[6] },
        { 0x000001DA, &gUnk_080F81BC.payload_storage[7] },
        { 0x00000258, &gUnk_080F81BC.payload_storage[8] },
        { 0x0000026D, &gUnk_080F81BC.payload_storage[9] },
        { 0x0000028F, &gUnk_080F81BC.payload_storage[0] },
        { 0x0000030C, &gUnk_080F81BC.payload_storage[1] },
        { 0x00000000, &gUnk_080F81BC.payload_storage[0] },
        { 0x0000003C, &gUnk_080F81BC.payload_storage[2] },
        { 0x0000003F, &gUnk_080F81BC.payload_storage[3] },
        { 0x0000012C, &gUnk_080F81BC.payload_storage[4] },
        { 0x0000012F, &gUnk_080F81BC.payload_storage[0] },
        { 0x000001A4, &gUnk_080F81BC.payload_storage[2] },
        { 0x000001A7, &gUnk_080F81BC.payload_storage[3] },
        { 0x00000258, &gUnk_080F81BC.payload_storage[4] },
        { 0x0000025B, &gUnk_080F81BC.payload_storage[0] },
        { 0x0000030C, &gUnk_080F81BC.payload_storage[1] },
        { 0x00000000, &gUnk_080F81BC.payload_storage[0] },
        { 0x0000003C, &gUnk_080F81BC.payload_storage[2] },
        { 0x0000003F, &gUnk_080F81BC.payload_storage[3] },
        { 0x0000012C, &gUnk_080F81BC.payload_storage[4] },
        { 0x0000012F, &gUnk_080F81BC.payload_storage[0] },
        { 0x000001A4, &gUnk_080F81BC.payload_storage[10] },
        { 0x000001BD, &gUnk_080F81BC.payload_storage[11] },
        { 0x000001D6, &gUnk_080F81BC.payload_storage[12] },
        { 0x00000258, &gUnk_080F81BC.payload_storage[13] },
        { 0x00000272, &gUnk_080F81BC.payload_storage[14] },
        { 0x0000028B, &gUnk_080F81BC.payload_storage[0] },
        { 0x0000030C, &gUnk_080F81BC.payload_storage[1] },
        { 0x00000000, &gUnk_080F81BC.payload_storage[0] },
        { 0x00000000, &gUnk_080F81BC.payload_storage[0] },
        { 0x00000000, &gUnk_080F81BC.payload_storage[17] },
        { 0x0000000A, &gUnk_080F81BC.payload_storage[15] },
        { 0x0000003C, &gUnk_080F81BC.payload_storage[16] },
        { 0x00000046, &gUnk_080F81BC.payload_storage[0] },
    },
    {
        { &gUnk_080F81BC.detail_storage[0], 2, 16, 96, 41, 0, true },
        { &gUnk_080F81BC.detail_storage[2], 2, 96, 80, 42, 0, true },
        { &gUnk_080F81BC.detail_storage[4], 3, 944, 228, 7, 0, false },
        { &gUnk_080F81BC.detail_storage[7], 2, 912, 216, 7, 0, true },
        { &gUnk_080F81BC.detail_storage[9], 3, 912, 216, 7, 0, false },
        { &gUnk_080F81BC.detail_storage[12], 5, 992, 232, 7, 0, false },
        { &gUnk_080F81BC.detail_storage[17], 11, 1200, 528, 0, 0, false },
        { nullptr, 0, 912, 575, 0, 1, false },
        { &gUnk_080F81BC.detail_storage[28], 11, 912, 576, 0, 0, false },
        { &gUnk_080F81BC.detail_storage[39], 5, 812, 512, 7, 0, false },
        { &gUnk_080F81BC.detail_storage[44], 7, 992, 232, 7, 0, false },
        { &gUnk_080F81BC.detail_storage[51], 5, 1260, 704, 5, 0, false },
        { nullptr, 0, 1176, 200, 5, 0, false },
        { &gUnk_080F81BC.detail_storage[56], 5, 1176, 200, 5, 0, false },
        { &gUnk_080F81BC.detail_storage[61], 7, 1272, 0, 7, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { &gUnk_080F81BC.detail_storage[68], 2, 228, 145, 2, 0, false },
        { &gUnk_080F81BC.detail_storage[70], 2, 340, 0, 2, 0, false },
    },
    {
        { 0x0058, 0x0002, 0x0078, 0x0000 },
        { 0x0010, 0x0002, 0x0078, 0x0000 },
        { 0x0090, 0x0002, 0x0078, 0x0003 },
        { 0x0060, 0x0002, 0x0078, 0x0002 },
        { 0x0001, 0x00EB, 0x0001, 0x0000 },
        { 0x0002, 0x0390, 0x0000, 0x0000 },
        { 0x0003, 0x00D8, 0x0001, 0x0000 },
        { 0x0368, 0x0002, 0x0078, 0x0002 },
        { 0x0390, 0x0002, 0x0078, 0x0003 },
        { 0x0001, 0x00EB, 0x0001, 0x0000 },
        { 0x0002, 0x03B0, 0x0000, 0x0000 },
        { 0x0003, 0x00E4, 0x0001, 0x0000 },
        { 0x0002, 0x0118, 0x0001, 0x0000 },
        { 0x0005, 0x0424, 0x0000, 0x0000 },
        { 0x000A, 0x0098, 0x0001, 0x0000 },
        { 0x0014, 0x032C, 0x0000, 0x0000 },
        { 0x0022, 0x0220, 0x0001, 0x0000 },
        { 0x0001, 0x0498, 0x0000, 0x0000 },
        { 0x0002, 0x0200, 0x0001, 0x0000 },
        { 0x0003, 0x0488, 0x0000, 0x0000 },
        { 0x0004, 0x01F0, 0x0001, 0x0000 },
        { 0x0005, 0x0478, 0x0000, 0x0000 },
        { 0x0006, 0x01E0, 0x0001, 0x0000 },
        { 0x000C, 0x03E8, 0x0000, 0x0000 },
        { 0x000E, 0x0218, 0x0001, 0x0000 },
        { 0x000F, 0x03D0, 0x0000, 0x0000 },
        { 0x0011, 0x023F, 0x0001, 0x0000 },
        { 0x0014, 0x0390, 0x0000, 0x0000 },
        { 0x0003, 0x03D0, 0x0000, 0x0000 },
        { 0x0005, 0x0218, 0x0001, 0x0000 },
        { 0x0006, 0x03E8, 0x0000, 0x0000 },
        { 0x0008, 0x01E0, 0x0001, 0x0000 },
        { 0x000E, 0x0478, 0x0000, 0x0000 },
        { 0x000F, 0x01F0, 0x0001, 0x0000 },
        { 0x0010, 0x0488, 0x0000, 0x0000 },
        { 0x0011, 0x0200, 0x0001, 0x0000 },
        { 0x0012, 0x0498, 0x0000, 0x0000 },
        { 0x0013, 0x0210, 0x0001, 0x0000 },
        { 0x0015, 0x04C0, 0x0000, 0x0000 },
        { 0x000E, 0x0098, 0x0001, 0x0000 },
        { 0x0018, 0x0424, 0x0000, 0x0000 },
        { 0x001D, 0x0118, 0x0001, 0x0000 },
        { 0x0020, 0x03E0, 0x0000, 0x0000 },
        { 0x0022, 0x00E8, 0x0001, 0x0000 },
        { 0x0002, 0x0118, 0x0001, 0x0000 },
        { 0x0005, 0x0424, 0x0000, 0x0000 },
        { 0x000A, 0x0098, 0x0001, 0x0000 },
        { 0x0012, 0x04E0, 0x0000, 0x0000 },
        { 0x0013, 0x0080, 0x0001, 0x0000 },
        { 0x0014, 0x04F8, 0x0000, 0x0000 },
        { 0x0019, 0x0000, 0x0001, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0014, 0x04E0, 0x0000, 0x0000 },
        { 0x0015, 0x00D8, 0x0001, 0x0000 },
        { 0x0018, 0x0498, 0x0000, 0x0000 },
        { 0x0019, 0x00C8, 0x0001, 0x0000 },
        { 0x0001, 0x00D8, 0x0001, 0x0000 },
        { 0x0004, 0x04E0, 0x0000, 0x0000 },
        { 0x0005, 0x00F0, 0x0001, 0x0000 },
        { 0x0006, 0x04EC, 0x0000, 0x0000 },
        { 0x001A, 0x02E0, 0x0001, 0x0000 },
        { 0x0005, 0x0080, 0x0001, 0x0000 },
        { 0x0006, 0x04E0, 0x0000, 0x0000 },
        { 0x0007, 0x0098, 0x0001, 0x0000 },
        { 0x000F, 0x0424, 0x0000, 0x0000 },
        { 0x0014, 0x0118, 0x0001, 0x0000 },
        { 0x0017, 0x03E0, 0x0000, 0x0000 },
        { 0x0019, 0x00E8, 0x0001, 0x0000 },
        { 0x0004, 0x0154, 0x0000, 0x0000 },
        { 0x000A, 0x0000, 0x0001, 0x0000 },
        { 0x0006, 0x0091, 0x0001, 0x0000 },
        { 0x000A, 0x00E4, 0x0000, 0x0000 },
    },
};
