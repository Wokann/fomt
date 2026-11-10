#include "npc_schedule_elli.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectElliSchedule\n"
    "SelectElliSchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r9\n"
    "    mov\tr6, r8\n"
    "    push\t{r6, r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E410\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E414\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E410: .word 0x000021CA\n"
    ".Ljp_0803E414:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr7, [r4, #1]\n"
    "    ldrb\tr6, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    mov\tr9, r4\n"
    "    ldr r0, .Ljp_0803E444\n"
    "    adds\tr4, r5, r0\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetSpouseCharacterId__C13NpcCollection\n"
    "    mov\tr8, r0\n"
    "    cmp\tr0, #21\n"
    "    bne .Ljp_0803E4C2\n"
    "    cmp\tr7, #2\n"
    "    bne .Ljp_0803E450\n"
    "    cmp\tr6, #9\n"
    "    bne .Ljp_0803E448\n"
    "    movs\tr0, #14\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E444: .word 0x00001CD4\n"
    ".Ljp_0803E448:\n"
    "    cmp\tr6, #13\n"
    "    bne .Ljp_0803E450\n"
    "    movs\tr0, #15\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E450:\n"
    "    ldr r1, .Ljp_0803E464\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #29\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803E468\n"
    "    movs\tr0, #16\n"
    "    b .Ljp_0803E54E\n"
    "    .align 2, 0\n"
    ".Ljp_0803E464: .word 0x0000216C\n"
    ".Ljp_0803E468:\n"
    "    ldr r1, .Ljp_0803E49C\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetChild__C13NpcCollection\n"
    "    negs\tr1, r0\n"
    "    orrs\tr1, r0\n"
    "    lsrs\tr4, r1, #31\n"
    "    mov\tr8, r4\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r6, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E490\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803E490\n"
    "    cmp\tr0, #4\n"
    "    bne .Ljp_0803E4A4\n"
    ".Ljp_0803E490:\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E4A0\n"
    "    movs\tr0, #12\n"
    "    b .Ljp_0803E54E\n"
    "    .align 2, 0\n"
    ".Ljp_0803E49C: .word 0x00001CD4\n"
    ".Ljp_0803E4A0:\n"
    "    movs\tr0, #13\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E4A4:\n"
    "    mov\tr1, r9\n"
    "    cmp\tr1, #3\n"
    "    bne .Ljp_0803E4B6\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803E4B2\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E4B2:\n"
    "    movs\tr0, #11\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E4B6:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803E4BE\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E4BE:\n"
    "    movs\tr0, #10\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E4C2:\n"
    "    ldr r1, .Ljp_0803E4E0\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetRivalEventCount__C12Bachelorette\n"
    "    cmp\tr0, #4\n"
    "    bls .Ljp_0803E4F2\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r6, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E4E4\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E4E0: .word 0x00001EE4\n"
    ".Ljp_0803E4E4:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #3\n"
    "    bne .Ljp_0803E4EE\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E4EE:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E4F2:\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #21\n"
    "    bl GetBachelorette__C13NpcCollectionUi\n"
    "    cmp\tr7, #3\n"
    "    bne .Ljp_0803E530\n"
    "    cmp\tr6, #14\n"
    "    bne .Ljp_0803E530\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #0\n"
    "    bne .Ljp_0803E530\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E530\n"
    "    bl GetLove__C12Bachelorette\n"
    "    ldr r1, .Ljp_0803E528\n"
    "    cmp\tr0, r1\n"
    "    bls .Ljp_0803E530\n"
    "    ldr r1, .Ljp_0803E52C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803E530\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E528: .word 0x0000270F\n"
    ".Ljp_0803E52C: .word 0x000021A4\n"
    ".Ljp_0803E530:\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r6, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E542\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E542:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803E54C\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E54E\n"
    ".Ljp_0803E54C:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803E54E:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3, r4}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" NpcScheduleStorage_080F5D94 const gUnk_080F5D94 = {
    {
        SelectElliSchedule,
        17,
        gUnk_080F5D94.table_choices,
    },
    {
        nullptr,
        &gUnk_080F5D94.table_storage[0],
        &gUnk_080F5D94.table_storage[1],
        &gUnk_080F5D94.table_storage[2],
        &gUnk_080F5D94.table_storage[3],
        &gUnk_080F5D94.table_storage[4],
        &gUnk_080F5D94.table_storage[5],
        &gUnk_080F5D94.table_storage[6],
        &gUnk_080F5D94.table_storage[7],
        &gUnk_080F5D94.table_storage[8],
        &gUnk_080F5D94.table_storage[9],
        &gUnk_080F5D94.table_storage[10],
        &gUnk_080F5D94.table_storage[11],
        &gUnk_080F5D94.table_storage[12],
        &gUnk_080F5D94.table_storage[13],
        &gUnk_080F5D94.table_storage[14],
        &gUnk_080F5D94.table_storage[15],
    },
    {
        { 3, &gUnk_080F5D94.entry_storage[0] },
        { 9, &gUnk_080F5D94.entry_storage[3] },
        { 3, &gUnk_080F5D94.entry_storage[12] },
        { 9, &gUnk_080F5D94.entry_storage[15] },
        { 1, &gUnk_080F5D94.entry_storage[24] },
        { 5, &gUnk_080F5D94.entry_storage[25] },
        { 1, &gUnk_080F5D94.entry_storage[30] },
        { 4, &gUnk_080F5D94.entry_storage[31] },
        { 4, &gUnk_080F5D94.entry_storage[35] },
        { 4, &gUnk_080F5D94.entry_storage[39] },
        { 4, &gUnk_080F5D94.entry_storage[43] },
        { 4, &gUnk_080F5D94.entry_storage[47] },
        { 4, &gUnk_080F5D94.entry_storage[51] },
        { 4, &gUnk_080F5D94.entry_storage[55] },
        { 3, &gUnk_080F5D94.entry_storage[59] },
        { 1, &gUnk_080F5D94.entry_storage[62] },
    },
    {
        { 0x00000000, &gUnk_080F5D94.payload_storage[0] },
        { 0x000000B4, &gUnk_080F5D94.payload_storage[1] },
        { 0x0000030C, &gUnk_080F5D94.payload_storage[0] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[0] },
        { 0x000000B4, &gUnk_080F5D94.payload_storage[2] },
        { 0x000000CA, &gUnk_080F5D94.payload_storage[3] },
        { 0x000001A4, &gUnk_080F5D94.payload_storage[4] },
        { 0x000001B4, &gUnk_080F5D94.payload_storage[5] },
        { 0x00000258, &gUnk_080F5D94.payload_storage[6] },
        { 0x00000268, &gUnk_080F5D94.payload_storage[3] },
        { 0x0000030C, &gUnk_080F5D94.payload_storage[7] },
        { 0x00000322, &gUnk_080F5D94.payload_storage[0] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[0] },
        { 0x000000B4, &gUnk_080F5D94.payload_storage[1] },
        { 0x0000030C, &gUnk_080F5D94.payload_storage[0] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[0] },
        { 0x000000B4, &gUnk_080F5D94.payload_storage[2] },
        { 0x000000CA, &gUnk_080F5D94.payload_storage[3] },
        { 0x000001A4, &gUnk_080F5D94.payload_storage[4] },
        { 0x000001B4, &gUnk_080F5D94.payload_storage[5] },
        { 0x00000258, &gUnk_080F5D94.payload_storage[6] },
        { 0x00000268, &gUnk_080F5D94.payload_storage[3] },
        { 0x0000030C, &gUnk_080F5D94.payload_storage[7] },
        { 0x00000322, &gUnk_080F5D94.payload_storage[0] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[0] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[1] },
        { 0x000000F0, &gUnk_080F5D94.payload_storage[8] },
        { 0x000000FA, &gUnk_080F5D94.payload_storage[9] },
        { 0x0000012C, &gUnk_080F5D94.payload_storage[13] },
        { 0x00000136, &gUnk_080F5D94.payload_storage[1] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[0] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[12] },
        { 0x000000B4, &gUnk_080F5D94.payload_storage[1] },
        { 0x000002D0, &gUnk_080F5D94.payload_storage[12] },
        { 0x00000348, &gUnk_080F5D94.payload_storage[11] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[12] },
        { 0x0000012C, &gUnk_080F5D94.payload_storage[10] },
        { 0x000002D0, &gUnk_080F5D94.payload_storage[12] },
        { 0x00000348, &gUnk_080F5D94.payload_storage[11] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[12] },
        { 0x000000B4, &gUnk_080F5D94.payload_storage[1] },
        { 0x000002D0, &gUnk_080F5D94.payload_storage[12] },
        { 0x00000348, &gUnk_080F5D94.payload_storage[11] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[12] },
        { 0x0000012C, &gUnk_080F5D94.payload_storage[10] },
        { 0x000002D0, &gUnk_080F5D94.payload_storage[12] },
        { 0x00000348, &gUnk_080F5D94.payload_storage[11] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[12] },
        { 0x0000012C, &gUnk_080F5D94.payload_storage[10] },
        { 0x000002D0, &gUnk_080F5D94.payload_storage[12] },
        { 0x00000348, &gUnk_080F5D94.payload_storage[11] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[12] },
        { 0x0000012C, &gUnk_080F5D94.payload_storage[10] },
        { 0x000002D0, &gUnk_080F5D94.payload_storage[12] },
        { 0x00000348, &gUnk_080F5D94.payload_storage[11] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[12] },
        { 0x000000F0, &gUnk_080F5D94.payload_storage[14] },
        { 0x000002D0, &gUnk_080F5D94.payload_storage[12] },
        { 0x00000348, &gUnk_080F5D94.payload_storage[11] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[12] },
        { 0x0000012C, &gUnk_080F5D94.payload_storage[10] },
        { 0x000002D0, &gUnk_080F5D94.payload_storage[14] },
        { 0x00000000, &gUnk_080F5D94.payload_storage[11] },
    },
    {
        { &gUnk_080F5D94.detail_storage[0], 2, 344, 240, 20, 0, true },
        { nullptr, 0, 136, 107, 19, 0, false },
        { &gUnk_080F5D94.detail_storage[2], 3, 856, 164, 5, 0, false },
        { &gUnk_080F5D94.detail_storage[5], 2, 80, 88, 14, 0, true },
        { &gUnk_080F5D94.detail_storage[7], 3, 400, 160, 5, 0, false },
        { nullptr, 0, 56, 136, 15, 3, false },
        { &gUnk_080F5D94.detail_storage[10], 3, 688, 160, 5, 0, false },
        { &gUnk_080F5D94.detail_storage[13], 3, 400, 160, 5, 0, false },
        { &gUnk_080F5D94.detail_storage[16], 2, 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { &gUnk_080F5D94.detail_storage[18], 4, 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { &gUnk_080F5D94.detail_storage[22], 4, 256, 152, 29, 0, true },
        { &gUnk_080F5D94.detail_storage[26], 2, 228, 145, 2, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
    },
    {
        { 0x0128, 0x0002, 0x0078, 0x0002 },
        { 0x0158, 0x0002, 0x0078, 0x0003 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0014, 0x0190, 0x0000, 0x0000 },
        { 0x0016, 0x00A0, 0x0001, 0x0000 },
        { 0x0018, 0x0002, 0x0078, 0x0001 },
        { 0x0050, 0x0002, 0x0078, 0x0001 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x000E, 0x02B0, 0x0000, 0x0000 },
        { 0x0010, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x000E, 0x0190, 0x0000, 0x0000 },
        { 0x0010, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0014, 0x0358, 0x0000, 0x0000 },
        { 0x0016, 0x00A4, 0x0001, 0x0000 },
        { 0x0006, 0x0091, 0x0001, 0x0000 },
        { 0x000A, 0x00E4, 0x0000, 0x0000 },
        { 0x006C, 0x0002, 0x0078, 0x0006 },
        { 0x0080, 0x0002, 0x0078, 0x0003 },
        { 0x004C, 0x0002, 0x0078, 0x0007 },
        { 0x0070, 0x0002, 0x0078, 0x0002 },
        { 0x0060, 0x0002, 0x0000, 0x0004 },
        { 0x0148, 0x0002, 0x0078, 0x0003 },
        { 0x0100, 0x0002, 0x0000, 0x0000 },
        { 0x0098, 0x0002, 0x0078, 0x0004 },
        { 0x0004, 0x0154, 0x0000, 0x0000 },
        { 0x000A, 0x0000, 0x0001, 0x0000 },
    },
};
