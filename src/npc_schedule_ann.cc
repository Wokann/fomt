#include "npc_schedule_ann.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectAnnSchedule\n"
    "SelectAnnSchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r9\n"
    "    mov\tr6, r8\n"
    "    push\t{r6, r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803DEF4\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803DEF8\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DEF4: .word 0x000021CA\n"
    ".Ljp_0803DEF8:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    mov\tr8, r0\n"
    "    ldrb\tr6, [r4, #2]\n"
    "    ldr r1, .Ljp_0803DF28\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetSpouseCharacterId__C13NpcCollection\n"
    "    adds\tr4, r0, #0\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #2\n"
    "    bne .Ljp_0803DF2C\n"
    "    cmp\tr6, #5\n"
    "    bne .Ljp_0803DF2C\n"
    "    cmp\tr4, #25\n"
    "    beq .Ljp_0803DF30\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E072\n"
    "    .align 2, 0\n"
    ".Ljp_0803DF28: .word 0x00001CD4\n"
    ".Ljp_0803DF2C:\n"
    "    cmp\tr4, #25\n"
    "    bne .Ljp_0803DFD8\n"
    ".Ljp_0803DF30:\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #2\n"
    "    bne .Ljp_0803DF46\n"
    "    cmp\tr6, #9\n"
    "    bne .Ljp_0803DF3E\n"
    "    movs\tr0, #16\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DF3E:\n"
    "    cmp\tr6, #13\n"
    "    bne .Ljp_0803DF46\n"
    "    movs\tr0, #17\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DF46:\n"
    "    ldr r1, .Ljp_0803DF64\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    lsrs\tr2, r2, #7\n"
    "    adds\tr1, #1\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    movs\tr1, #1\n"
    "    ands\tr0, r1\n"
    "    lsls\tr0, r0, #1\n"
    "    orrs\tr0, r2\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803DF68\n"
    "    movs\tr0, #18\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DF64: .word 0x0000216B\n"
    ".Ljp_0803DF68:\n"
    "    ldr r1, .Ljp_0803DFA4\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr4, [r0, #0]\n"
    "    ldr r1, .Ljp_0803DFA8\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetChild__C13NpcCollection\n"
    "    negs\tr1, r0\n"
    "    orrs\tr1, r0\n"
    "    lsrs\tr7, r1, #31\n"
    "    mov\tr9, r7\n"
    "    mov\tr0, r8\n"
    "    adds\tr1, r6, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DF96\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803DF96\n"
    "    cmp\tr0, #4\n"
    "    bne .Ljp_0803DFBC\n"
    ".Ljp_0803DF96:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DFB0\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803DFAC\n"
    "    movs\tr0, #13\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFA4: .word 0x00002148\n"
    ".Ljp_0803DFA8: .word 0x00001CD4\n"
    ".Ljp_0803DFAC:\n"
    "    movs\tr0, #12\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFB0:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803DFB8\n"
    "    movs\tr0, #15\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFB8:\n"
    "    movs\tr0, #14\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFBC:\n"
    "    cmp\tr7, #0\n"
    "    beq .Ljp_0803DFCC\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803DFC8\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFC8:\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFCC:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803DFD4\n"
    "    movs\tr0, #11\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFD4:\n"
    "    movs\tr0, #10\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFD8:\n"
    "    ldr r1, .Ljp_0803DFFC\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetRivalEventCount__C12Bachelorette\n"
    "    cmp\tr0, #4\n"
    "    bls .Ljp_0803E004\n"
    "    mov\tr0, r8\n"
    "    adds\tr1, r6, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E062\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E000\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803DFFC: .word 0x00001F38\n"
    ".Ljp_0803E000:\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803E004:\n"
    "    ldr r1, .Ljp_0803E048\n"
    "    adds\tr0, r5, r1\n"
    "    movs\tr1, #25\n"
    "    bl GetBachelorette__C13NpcCollectionUi\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #3\n"
    "    bne .Ljp_0803E054\n"
    "    cmp\tr6, #14\n"
    "    bne .Ljp_0803E054\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_0803E054\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E054\n"
    "    bl GetLove__C12Bachelorette\n"
    "    ldr r1, .Ljp_0803E04C\n"
    "    cmp\tr0, r1\n"
    "    bls .Ljp_0803E054\n"
    "    ldr r1, .Ljp_0803E050\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    lsrs\tr2, r2, #7\n"
    "    adds\tr1, #1\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    movs\tr1, #1\n"
    "    ands\tr0, r1\n"
    "    lsls\tr0, r0, #1\n"
    "    orrs\tr0, r2\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803E054\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803E048: .word 0x00001CD4\n"
    ".Ljp_0803E04C: .word 0x0000270F\n"
    ".Ljp_0803E050: .word 0x000021A3\n"
    ".Ljp_0803E054:\n"
    "    mov\tr0, r8\n"
    "    adds\tr1, r6, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E066\n"
    ".Ljp_0803E062:\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803E066:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E070\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E072\n"
    ".Ljp_0803E070:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E072:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3, r4}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    "\n"
);

extern "C" NpcScheduleStorage_080F43DC const gUnk_080F43DC = {
    {
        SelectAnnSchedule,
        19,
        gUnk_080F43DC.table_choices,
    },
    {
        nullptr,
        &gUnk_080F43DC.table_storage[0],
        &gUnk_080F43DC.table_storage[1],
        &gUnk_080F43DC.table_storage[2],
        &gUnk_080F43DC.table_storage[3],
        &gUnk_080F43DC.table_storage[4],
        &gUnk_080F43DC.table_storage[5],
        &gUnk_080F43DC.table_storage[6],
        &gUnk_080F43DC.table_storage[7],
        &gUnk_080F43DC.table_storage[8],
        &gUnk_080F43DC.table_storage[9],
        &gUnk_080F43DC.table_storage[10],
        &gUnk_080F43DC.table_storage[11],
        &gUnk_080F43DC.table_storage[12],
        &gUnk_080F43DC.table_storage[13],
        &gUnk_080F43DC.table_storage[14],
        &gUnk_080F43DC.table_storage[15],
        &gUnk_080F43DC.table_storage[16],
        &gUnk_080F43DC.table_storage[17],
    },
    {
        { 11, &gUnk_080F43DC.entry_storage[0] },
        { 6, &gUnk_080F43DC.entry_storage[11] },
        { 11, &gUnk_080F43DC.entry_storage[17] },
        { 6, &gUnk_080F43DC.entry_storage[28] },
        { 3, &gUnk_080F43DC.entry_storage[34] },
        { 1, &gUnk_080F43DC.entry_storage[37] },
        { 5, &gUnk_080F43DC.entry_storage[38] },
        { 4, &gUnk_080F43DC.entry_storage[43] },
        { 4, &gUnk_080F43DC.entry_storage[47] },
        { 4, &gUnk_080F43DC.entry_storage[51] },
        { 4, &gUnk_080F43DC.entry_storage[55] },
        { 4, &gUnk_080F43DC.entry_storage[59] },
        { 4, &gUnk_080F43DC.entry_storage[63] },
        { 4, &gUnk_080F43DC.entry_storage[67] },
        { 4, &gUnk_080F43DC.entry_storage[71] },
        { 4, &gUnk_080F43DC.entry_storage[75] },
        { 3, &gUnk_080F43DC.entry_storage[79] },
        { 1, &gUnk_080F43DC.entry_storage[82] },
    },
    {
        { 0x00000000, &gUnk_080F43DC.payload_storage[1] },
        { 0x0000003C, &gUnk_080F43DC.payload_storage[3] },
        { 0x0000005F, &gUnk_080F43DC.payload_storage[4] },
        { 0x0000006B, &gUnk_080F43DC.payload_storage[5] },
        { 0x000000F0, &gUnk_080F43DC.payload_storage[6] },
        { 0x000000FD, &gUnk_080F43DC.payload_storage[7] },
        { 0x0000011F, &gUnk_080F43DC.payload_storage[2] },
        { 0x000001A4, &gUnk_080F43DC.payload_storage[0] },
        { 0x00000258, &gUnk_080F43DC.payload_storage[2] },
        { 0x0000030C, &gUnk_080F43DC.payload_storage[0] },
        { 0x000003C0, &gUnk_080F43DC.payload_storage[1] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[1] },
        { 0x000000F0, &gUnk_080F43DC.payload_storage[2] },
        { 0x000001A4, &gUnk_080F43DC.payload_storage[0] },
        { 0x00000258, &gUnk_080F43DC.payload_storage[2] },
        { 0x0000030C, &gUnk_080F43DC.payload_storage[0] },
        { 0x000003C0, &gUnk_080F43DC.payload_storage[1] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[1] },
        { 0x0000003C, &gUnk_080F43DC.payload_storage[3] },
        { 0x0000005F, &gUnk_080F43DC.payload_storage[4] },
        { 0x0000006B, &gUnk_080F43DC.payload_storage[5] },
        { 0x000000F0, &gUnk_080F43DC.payload_storage[6] },
        { 0x000000FD, &gUnk_080F43DC.payload_storage[7] },
        { 0x0000011F, &gUnk_080F43DC.payload_storage[2] },
        { 0x000001A4, &gUnk_080F43DC.payload_storage[0] },
        { 0x00000258, &gUnk_080F43DC.payload_storage[2] },
        { 0x0000030C, &gUnk_080F43DC.payload_storage[0] },
        { 0x000003C0, &gUnk_080F43DC.payload_storage[1] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[1] },
        { 0x000000F0, &gUnk_080F43DC.payload_storage[2] },
        { 0x000001A4, &gUnk_080F43DC.payload_storage[0] },
        { 0x00000258, &gUnk_080F43DC.payload_storage[2] },
        { 0x0000030C, &gUnk_080F43DC.payload_storage[0] },
        { 0x000003C0, &gUnk_080F43DC.payload_storage[1] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[1] },
        { 0x000000F0, &gUnk_080F43DC.payload_storage[0] },
        { 0x00000294, &gUnk_080F43DC.payload_storage[1] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[1] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[1] },
        { 0x00000078, &gUnk_080F43DC.payload_storage[8] },
        { 0x00000082, &gUnk_080F43DC.payload_storage[9] },
        { 0x000000B4, &gUnk_080F43DC.payload_storage[13] },
        { 0x000000BE, &gUnk_080F43DC.payload_storage[1] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x0000012C, &gUnk_080F43DC.payload_storage[10] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x000000B4, &gUnk_080F43DC.payload_storage[0] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x0000012C, &gUnk_080F43DC.payload_storage[10] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x000000B4, &gUnk_080F43DC.payload_storage[0] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x0000012C, &gUnk_080F43DC.payload_storage[10] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x0000012C, &gUnk_080F43DC.payload_storage[10] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x0000012C, &gUnk_080F43DC.payload_storage[10] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x0000012C, &gUnk_080F43DC.payload_storage[10] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x000000F0, &gUnk_080F43DC.payload_storage[14] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[12] },
        { 0x00000348, &gUnk_080F43DC.payload_storage[11] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[12] },
        { 0x0000012C, &gUnk_080F43DC.payload_storage[10] },
        { 0x000002D0, &gUnk_080F43DC.payload_storage[14] },
        { 0x00000000, &gUnk_080F43DC.payload_storage[11] },
    },
    {
        { &gUnk_080F43DC.detail_storage[0], 5, 200, 83, 21, 0, true },
        { &gUnk_080F43DC.detail_storage[5], 2, 135, 96, 22, 0, true },
        { &gUnk_080F43DC.detail_storage[7], 2, 80, 88, 23, 0, true },
        { &gUnk_080F43DC.detail_storage[9], 3, 632, 488, 5, 0, false },
        { &gUnk_080F43DC.detail_storage[12], 8, 1200, 528, 0, 0, false },
        { nullptr, 0, 1032, 432, 0, 1, false },
        { &gUnk_080F43DC.detail_storage[20], 8, 1032, 432, 0, 0, false },
        { &gUnk_080F43DC.detail_storage[28], 3, 1260, 704, 5, 0, false },
        { &gUnk_080F43DC.detail_storage[31], 2, 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { &gUnk_080F43DC.detail_storage[33], 4, 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { &gUnk_080F43DC.detail_storage[37], 4, 256, 152, 29, 0, true },
        { &gUnk_080F43DC.detail_storage[41], 2, 228, 145, 2, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
    },
    {
        { 0x0080, 0x0002, 0x0078, 0x0002 },
        { 0x00A0, 0x0002, 0x0078, 0x0004 },
        { 0x0060, 0x0002, 0x0078, 0x0002 },
        { 0x0053, 0x0002, 0x0078, 0x0005 },
        { 0x00C8, 0x0002, 0x0078, 0x0003 },
        { 0x00C8, 0x0002, 0x0078, 0x0003 },
        { 0x0087, 0x0002, 0x0078, 0x0002 },
        { 0x00B0, 0x0002, 0x0078, 0x0004 },
        { 0x0058, 0x0002, 0x0078, 0x0005 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x001B, 0x04EC, 0x0000, 0x0000 },
        { 0x0023, 0x02E0, 0x0001, 0x0000 },
        { 0x0001, 0x0498, 0x0000, 0x0000 },
        { 0x0002, 0x0200, 0x0001, 0x0000 },
        { 0x0003, 0x0488, 0x0000, 0x0000 },
        { 0x0004, 0x01F0, 0x0001, 0x0000 },
        { 0x0005, 0x0478, 0x0000, 0x0000 },
        { 0x0006, 0x01E0, 0x0001, 0x0000 },
        { 0x000A, 0x0408, 0x0000, 0x0000 },
        { 0x000C, 0x01B0, 0x0001, 0x0000 },
        { 0x0002, 0x01E0, 0x0001, 0x0000 },
        { 0x0006, 0x0478, 0x0000, 0x0000 },
        { 0x0007, 0x01F0, 0x0001, 0x0000 },
        { 0x0008, 0x0488, 0x0000, 0x0000 },
        { 0x0009, 0x0200, 0x0001, 0x0000 },
        { 0x000A, 0x0498, 0x0000, 0x0000 },
        { 0x000B, 0x0210, 0x0001, 0x0000 },
        { 0x000D, 0x04C0, 0x0000, 0x0000 },
        { 0x0007, 0x0218, 0x0001, 0x0000 },
        { 0x0020, 0x0278, 0x0000, 0x0000 },
        { 0x0022, 0x01E8, 0x0001, 0x0000 },
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
