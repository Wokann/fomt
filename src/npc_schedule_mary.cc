#include "npc_schedule_mary.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectMarySchedule\n"
    "SelectMarySchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r9\n"
    "    mov\tr6, r8\n"
    "    push\t{r6, r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E130\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E134\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E130: .word 0x000021CA\n"
    ".Ljp_0803E134:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr7, [r4, #1]\n"
    "    ldrb\tr6, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    mov\tr9, r4\n"
    "    ldr r0, .Ljp_0803E164\n"
    "    adds\tr4, r5, r0\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetSpouseCharacterId__C13NpcCollection\n"
    "    mov\tr8, r0\n"
    "    cmp\tr0, #12\n"
    "    bne .Ljp_0803E1E2\n"
    "    cmp\tr7, #2\n"
    "    bne .Ljp_0803E170\n"
    "    cmp\tr6, #9\n"
    "    bne .Ljp_0803E168\n"
    "    movs\tr0, #16\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E164: .word 0x00001CD4\n"
    ".Ljp_0803E168:\n"
    "    cmp\tr6, #13\n"
    "    bne .Ljp_0803E170\n"
    "    movs\tr0, #17\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E170:\n"
    "    ldr r1, .Ljp_0803E184\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803E188\n"
    "    movs\tr0, #18\n"
    "    b .Ljp_0803E284\n"
    "    .align 2, 0\n"
    ".Ljp_0803E184: .word 0x0000216C\n"
    ".Ljp_0803E188:\n"
    "    ldr r1, .Ljp_0803E1BC\n"
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
    "    bne .Ljp_0803E1B0\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803E1B0\n"
    "    cmp\tr0, #4\n"
    "    bne .Ljp_0803E1C4\n"
    ".Ljp_0803E1B0:\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E1C0\n"
    "    movs\tr0, #14\n"
    "    b .Ljp_0803E284\n"
    "    .align 2, 0\n"
    ".Ljp_0803E1BC: .word 0x00001CD4\n"
    ".Ljp_0803E1C0:\n"
    "    movs\tr0, #15\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E1C4:\n"
    "    mov\tr1, r9\n"
    "    cmp\tr1, #1\n"
    "    bne .Ljp_0803E1D6\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803E1D2\n"
    "    movs\tr0, #11\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E1D2:\n"
    "    movs\tr0, #13\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E1D6:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803E1DE\n"
    "    movs\tr0, #10\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E1DE:\n"
    "    movs\tr0, #12\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E1E2:\n"
    "    ldr r1, .Ljp_0803E200\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetRivalEventCount__C12Bachelorette\n"
    "    cmp\tr0, #4\n"
    "    bls .Ljp_0803E21C\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r6, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E204\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E200: .word 0x00001E28\n"
    ".Ljp_0803E204:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #4\n"
    "    bne .Ljp_0803E218\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E214\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E214:\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E218:\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E21C:\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #12\n"
    "    bl GetBachelorette__C13NpcCollectionUi\n"
    "    cmp\tr7, #3\n"
    "    bne .Ljp_0803E25C\n"
    "    cmp\tr6, #14\n"
    "    bne .Ljp_0803E25C\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #0\n"
    "    bne .Ljp_0803E25C\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E25C\n"
    "    bl GetLove__C12Bachelorette\n"
    "    ldr r1, .Ljp_0803E254\n"
    "    cmp\tr0, r1\n"
    "    bls .Ljp_0803E25C\n"
    "    ldr r1, .Ljp_0803E258\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803E25C\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803E284\n"
    "    .align 2, 0\n"
    ".Ljp_0803E254: .word 0x0000270F\n"
    ".Ljp_0803E258: .word 0x000021A5\n"
    ".Ljp_0803E25C:\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r6, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E26E\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E26E:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803E282\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E27E\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E27E:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E284\n"
    ".Ljp_0803E282:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E284:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3, r4}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

extern "C" NpcScheduleStorage_080F4D74 const gUnk_080F4D74 = {
    {
        SelectMarySchedule,
        19,
        gUnk_080F4D74.table_choices,
    },
    {
        nullptr,
        &gUnk_080F4D74.table_storage[0],
        &gUnk_080F4D74.table_storage[1],
        &gUnk_080F4D74.table_storage[2],
        &gUnk_080F4D74.table_storage[3],
        &gUnk_080F4D74.table_storage[4],
        &gUnk_080F4D74.table_storage[5],
        &gUnk_080F4D74.table_storage[6],
        &gUnk_080F4D74.table_storage[7],
        &gUnk_080F4D74.table_storage[8],
        &gUnk_080F4D74.table_storage[9],
        &gUnk_080F4D74.table_storage[10],
        &gUnk_080F4D74.table_storage[11],
        &gUnk_080F4D74.table_storage[12],
        &gUnk_080F4D74.table_storage[13],
        &gUnk_080F4D74.table_storage[14],
        &gUnk_080F4D74.table_storage[15],
        &gUnk_080F4D74.table_storage[16],
        &gUnk_080F4D74.table_storage[17],
    },
    {
        { 7, &gUnk_080F4D74.entry_storage[0] },
        { 12, &gUnk_080F4D74.entry_storage[7] },
        { 7, &gUnk_080F4D74.entry_storage[19] },
        { 7, &gUnk_080F4D74.entry_storage[26] },
        { 9, &gUnk_080F4D74.entry_storage[33] },
        { 9, &gUnk_080F4D74.entry_storage[42] },
        { 5, &gUnk_080F4D74.entry_storage[51] },
        { 1, &gUnk_080F4D74.entry_storage[56] },
        { 1, &gUnk_080F4D74.entry_storage[57] },
        { 4, &gUnk_080F4D74.entry_storage[58] },
        { 4, &gUnk_080F4D74.entry_storage[62] },
        { 4, &gUnk_080F4D74.entry_storage[66] },
        { 4, &gUnk_080F4D74.entry_storage[70] },
        { 4, &gUnk_080F4D74.entry_storage[74] },
        { 4, &gUnk_080F4D74.entry_storage[78] },
        { 4, &gUnk_080F4D74.entry_storage[82] },
        { 3, &gUnk_080F4D74.entry_storage[86] },
        { 1, &gUnk_080F4D74.entry_storage[89] },
    },
    {
        { 0x00000000, &gUnk_080F4D74.payload_storage[0] },
        { 0x0000003C, &gUnk_080F4D74.payload_storage[1] },
        { 0x000000F0, &gUnk_080F4D74.payload_storage[2] },
        { 0x000000F7, &gUnk_080F4D74.payload_storage[3] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[4] },
        { 0x000002D7, &gUnk_080F4D74.payload_storage[1] },
        { 0x000003C0, &gUnk_080F4D74.payload_storage[0] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[0] },
        { 0x0000003F, &gUnk_080F4D74.payload_storage[5] },
        { 0x0000005A, &gUnk_080F4D74.payload_storage[6] },
        { 0x00000094, &gUnk_080F4D74.payload_storage[7] },
        { 0x000000F0, &gUnk_080F4D74.payload_storage[8] },
        { 0x0000012A, &gUnk_080F4D74.payload_storage[9] },
        { 0x00000144, &gUnk_080F4D74.payload_storage[1] },
        { 0x000001A4, &gUnk_080F4D74.payload_storage[10] },
        { 0x000001BC, &gUnk_080F4D74.payload_storage[11] },
        { 0x0000025B, &gUnk_080F4D74.payload_storage[12] },
        { 0x00000273, &gUnk_080F4D74.payload_storage[1] },
        { 0x000003C0, &gUnk_080F4D74.payload_storage[0] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[0] },
        { 0x0000003C, &gUnk_080F4D74.payload_storage[1] },
        { 0x000001A4, &gUnk_080F4D74.payload_storage[10] },
        { 0x000001BC, &gUnk_080F4D74.payload_storage[11] },
        { 0x0000025B, &gUnk_080F4D74.payload_storage[12] },
        { 0x00000273, &gUnk_080F4D74.payload_storage[1] },
        { 0x000003C0, &gUnk_080F4D74.payload_storage[0] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[0] },
        { 0x0000003C, &gUnk_080F4D74.payload_storage[1] },
        { 0x000000F0, &gUnk_080F4D74.payload_storage[2] },
        { 0x000000F7, &gUnk_080F4D74.payload_storage[3] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[4] },
        { 0x000002D7, &gUnk_080F4D74.payload_storage[1] },
        { 0x000003C0, &gUnk_080F4D74.payload_storage[0] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[0] },
        { 0x0000003C, &gUnk_080F4D74.payload_storage[1] },
        { 0x000001AA, &gUnk_080F4D74.payload_storage[5] },
        { 0x000001C5, &gUnk_080F4D74.payload_storage[23] },
        { 0x000001CE, &gUnk_080F4D74.payload_storage[24] },
        { 0x00000258, &gUnk_080F4D74.payload_storage[25] },
        { 0x00000262, &gUnk_080F4D74.payload_storage[9] },
        { 0x0000027C, &gUnk_080F4D74.payload_storage[1] },
        { 0x000003C0, &gUnk_080F4D74.payload_storage[0] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[0] },
        { 0x0000003C, &gUnk_080F4D74.payload_storage[1] },
        { 0x000001A4, &gUnk_080F4D74.payload_storage[5] },
        { 0x000001BF, &gUnk_080F4D74.payload_storage[19] },
        { 0x000001CF, &gUnk_080F4D74.payload_storage[20] },
        { 0x00000258, &gUnk_080F4D74.payload_storage[21] },
        { 0x00000268, &gUnk_080F4D74.payload_storage[9] },
        { 0x00000282, &gUnk_080F4D74.payload_storage[1] },
        { 0x000003C0, &gUnk_080F4D74.payload_storage[0] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[1] },
        { 0x000001E0, &gUnk_080F4D74.payload_storage[16] },
        { 0x000001EA, &gUnk_080F4D74.payload_storage[17] },
        { 0x0000021C, &gUnk_080F4D74.payload_storage[18] },
        { 0x00000226, &gUnk_080F4D74.payload_storage[1] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[1] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[1] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[15] },
        { 0x000000B4, &gUnk_080F4D74.payload_storage[3] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[15] },
        { 0x00000348, &gUnk_080F4D74.payload_storage[14] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[15] },
        { 0x0000012C, &gUnk_080F4D74.payload_storage[13] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[15] },
        { 0x00000348, &gUnk_080F4D74.payload_storage[14] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[15] },
        { 0x000000B4, &gUnk_080F4D74.payload_storage[3] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[15] },
        { 0x00000348, &gUnk_080F4D74.payload_storage[14] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[15] },
        { 0x0000012C, &gUnk_080F4D74.payload_storage[13] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[15] },
        { 0x00000348, &gUnk_080F4D74.payload_storage[14] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[15] },
        { 0x0000012C, &gUnk_080F4D74.payload_storage[13] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[15] },
        { 0x00000348, &gUnk_080F4D74.payload_storage[14] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[15] },
        { 0x0000012C, &gUnk_080F4D74.payload_storage[13] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[15] },
        { 0x00000348, &gUnk_080F4D74.payload_storage[14] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[15] },
        { 0x000000F0, &gUnk_080F4D74.payload_storage[22] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[15] },
        { 0x00000348, &gUnk_080F4D74.payload_storage[14] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[15] },
        { 0x0000012C, &gUnk_080F4D74.payload_storage[13] },
        { 0x000002D0, &gUnk_080F4D74.payload_storage[22] },
        { 0x00000000, &gUnk_080F4D74.payload_storage[14] },
    },
    {
        { &gUnk_080F4D74.detail_storage[0], 2, 176, 120, 27, 0, true },
        { &gUnk_080F4D74.detail_storage[2], 2, 176, 160, 26, 0, true },
        { &gUnk_080F4D74.detail_storage[4], 3, 200, 160, 5, 0, false },
        { nullptr, 0, 172, 115, 24, 0, false },
        { &gUnk_080F4D74.detail_storage[7], 3, 276, 168, 5, 0, false },
        { &gUnk_080F4D74.detail_storage[10], 5, 200, 160, 5, 0, false },
        { &gUnk_080F4D74.detail_storage[15], 20, 1200, 752, 0, 0, false },
        { &gUnk_080F4D74.detail_storage[35], 2, 344, 208, 0, 0, true },
        { &gUnk_080F4D74.detail_storage[37], 20, 344, 208, 0, 0, false },
        { &gUnk_080F4D74.detail_storage[57], 5, 104, 704, 5, 0, false },
        { &gUnk_080F4D74.detail_storage[62], 3, 200, 160, 5, 0, false },
        { nullptr, 0, 120, 138, 15, 0, false },
        { &gUnk_080F4D74.detail_storage[65], 3, 688, 160, 5, 0, false },
        { &gUnk_080F4D74.detail_storage[68], 4, 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { &gUnk_080F4D74.detail_storage[72], 4, 256, 152, 29, 0, true },
        { &gUnk_080F4D74.detail_storage[76], 2, 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { &gUnk_080F4D74.detail_storage[78], 2, 228, 145, 2, 0, false },
        { &gUnk_080F4D74.detail_storage[80], 3, 104, 0, 7, 0, false },
        { nullptr, 0, 48, 88, 38, 0, false },
        { &gUnk_080F4D74.detail_storage[83], 3, 296, 116, 7, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
        { &gUnk_080F4D74.detail_storage[86], 2, 240, 480, 8, 0, false },
        { nullptr, 0, 256, 272, 8, 1, false },
        { &gUnk_080F4D74.detail_storage[88], 2, 256, 272, 8, 0, false },
    },
    {
        { 0x0048, 0x0002, 0x0078, 0x0002 },
        { 0x00B0, 0x0002, 0x0078, 0x0003 },
        { 0x0058, 0x0002, 0x0078, 0x0005 },
        { 0x00A0, 0x0002, 0x0078, 0x0004 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0005, 0x0114, 0x0000, 0x0000 },
        { 0x0007, 0x00A8, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0005, 0x00C8, 0x0000, 0x0000 },
        { 0x0007, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0004, 0x0090, 0x0000, 0x0000 },
        { 0x0005, 0x00F0, 0x0001, 0x0000 },
        { 0x0007, 0x0068, 0x0000, 0x0000 },
        { 0x001B, 0x02DE, 0x0001, 0x0000 },
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
        { 0x001B, 0x02B4, 0x0000, 0x0000 },
        { 0x0025, 0x0148, 0x0001, 0x0000 },
        { 0x0026, 0x0290, 0x0000, 0x0000 },
        { 0x002C, 0x00A8, 0x0001, 0x0000 },
        { 0x0038, 0x0158, 0x0000, 0x0000 },
        { 0x003A, 0x00D0, 0x0001, 0x0000 },
        { 0x0188, 0x0002, 0x0078, 0x0003 },
        { 0x0158, 0x0002, 0x0078, 0x0002 },
        { 0x0002, 0x00A8, 0x0001, 0x0000 },
        { 0x000E, 0x0290, 0x0000, 0x0000 },
        { 0x0014, 0x0148, 0x0001, 0x0000 },
        { 0x0015, 0x02B4, 0x0000, 0x0000 },
        { 0x001F, 0x0238, 0x0001, 0x0000 },
        { 0x0020, 0x02D0, 0x0000, 0x0000 },
        { 0x0021, 0x0250, 0x0001, 0x0000 },
        { 0x0022, 0x02F0, 0x0000, 0x0000 },
        { 0x0023, 0x0270, 0x0001, 0x0000 },
        { 0x0024, 0x0308, 0x0000, 0x0000 },
        { 0x0025, 0x0290, 0x0001, 0x0000 },
        { 0x0026, 0x0328, 0x0000, 0x0000 },
        { 0x0027, 0x02A8, 0x0001, 0x0000 },
        { 0x0028, 0x0340, 0x0000, 0x0000 },
        { 0x0029, 0x02C0, 0x0001, 0x0000 },
        { 0x002A, 0x0358, 0x0000, 0x0000 },
        { 0x002B, 0x02D8, 0x0001, 0x0000 },
        { 0x002D, 0x0390, 0x0000, 0x0000 },
        { 0x002E, 0x02F0, 0x0001, 0x0000 },
        { 0x003A, 0x04C0, 0x0000, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0015, 0x0090, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x0018, 0x00C8, 0x0000, 0x0000 },
        { 0x001A, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0016, 0x02B0, 0x0000, 0x0000 },
        { 0x0018, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0016, 0x00C8, 0x0000, 0x0000 },
        { 0x0018, 0x00A0, 0x0001, 0x0000 },
        { 0x006C, 0x0002, 0x0078, 0x0006 },
        { 0x0080, 0x0002, 0x0078, 0x0003 },
        { 0x004C, 0x0002, 0x0078, 0x0007 },
        { 0x0070, 0x0002, 0x0078, 0x0002 },
        { 0x0060, 0x0002, 0x0000, 0x0004 },
        { 0x0148, 0x0002, 0x0078, 0x0003 },
        { 0x0100, 0x0002, 0x0000, 0x0000 },
        { 0x0098, 0x0002, 0x0078, 0x0004 },
        { 0x0006, 0x0091, 0x0001, 0x0000 },
        { 0x000A, 0x00E4, 0x0000, 0x0000 },
        { 0x0004, 0x0154, 0x0000, 0x0000 },
        { 0x000A, 0x0000, 0x0001, 0x0000 },
        { 0x0006, 0x0098, 0x0001, 0x0000 },
        { 0x000E, 0x0128, 0x0000, 0x0000 },
        { 0x0010, 0x0074, 0x0001, 0x0000 },
        { 0x0002, 0x0098, 0x0001, 0x0000 },
        { 0x000A, 0x0068, 0x0000, 0x0000 },
        { 0x0010, 0x0000, 0x0001, 0x0000 },
        { 0x0008, 0x0110, 0x0001, 0x0000 },
        { 0x0009, 0x0100, 0x0000, 0x0000 },
        { 0x0001, 0x00F0, 0x0000, 0x0000 },
        { 0x000A, 0x0200, 0x0001, 0x0000 },
    },
};
