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

extern "C" MaryScheduleData const gMaryScheduleData = {
    // descriptor
    {
        SelectMarySchedule,
        ARRAY_COUNT(gMaryScheduleData.table_choices),
        gMaryScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gMaryScheduleData.table_storage[0],
        &gMaryScheduleData.table_storage[1],
        &gMaryScheduleData.table_storage[2],
        &gMaryScheduleData.table_storage[3],
        &gMaryScheduleData.table_storage[4],
        &gMaryScheduleData.table_storage[5],
        &gMaryScheduleData.table_storage[6],
        &gMaryScheduleData.table_storage[7],
        &gMaryScheduleData.table_storage[8],
        &gMaryScheduleData.table_storage[9],
        &gMaryScheduleData.table_storage[10],
        &gMaryScheduleData.table_storage[11],
        &gMaryScheduleData.table_storage[12],
        &gMaryScheduleData.table_storage[13],
        &gMaryScheduleData.table_storage[14],
        &gMaryScheduleData.table_storage[15],
        &gMaryScheduleData.table_storage[16],
        &gMaryScheduleData.table_storage[17],
    },
    // table_storage
    {
        { ARRAY_COUNT(gMaryScheduleData.entries_0), gMaryScheduleData.entries_0 },
        { ARRAY_COUNT(gMaryScheduleData.entries_1), gMaryScheduleData.entries_1 },
        { ARRAY_COUNT(gMaryScheduleData.entries_2), gMaryScheduleData.entries_2 },
        { ARRAY_COUNT(gMaryScheduleData.entries_3), gMaryScheduleData.entries_3 },
        { ARRAY_COUNT(gMaryScheduleData.entries_4), gMaryScheduleData.entries_4 },
        { ARRAY_COUNT(gMaryScheduleData.entries_5), gMaryScheduleData.entries_5 },
        { ARRAY_COUNT(gMaryScheduleData.entries_6), gMaryScheduleData.entries_6 },
        { ARRAY_COUNT(gMaryScheduleData.entries_7), gMaryScheduleData.entries_7 },
        { ARRAY_COUNT(gMaryScheduleData.entries_8), gMaryScheduleData.entries_8 },
        { ARRAY_COUNT(gMaryScheduleData.entries_9), gMaryScheduleData.entries_9 },
        { ARRAY_COUNT(gMaryScheduleData.entries_10), gMaryScheduleData.entries_10 },
        { ARRAY_COUNT(gMaryScheduleData.entries_11), gMaryScheduleData.entries_11 },
        { ARRAY_COUNT(gMaryScheduleData.entries_12), gMaryScheduleData.entries_12 },
        { ARRAY_COUNT(gMaryScheduleData.entries_13), gMaryScheduleData.entries_13 },
        { ARRAY_COUNT(gMaryScheduleData.entries_14), gMaryScheduleData.entries_14 },
        { ARRAY_COUNT(gMaryScheduleData.entries_15), gMaryScheduleData.entries_15 },
        { ARRAY_COUNT(gMaryScheduleData.entries_16), gMaryScheduleData.entries_16 },
        { ARRAY_COUNT(gMaryScheduleData.entries_17), gMaryScheduleData.entries_17 },
    },
    // entries_0
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000000F0, &gMaryScheduleData.payload_storage[2] },
        { 0x000000F7, &gMaryScheduleData.payload_storage[3] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[4] },
        { 0x000002D7, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003F, &gMaryScheduleData.payload_storage[5] },
        { 0x0000005A, &gMaryScheduleData.payload_storage[6] },
        { 0x00000094, &gMaryScheduleData.payload_storage[7] },
        { 0x000000F0, &gMaryScheduleData.payload_storage[8] },
        { 0x0000012A, &gMaryScheduleData.payload_storage[9] },
        { 0x00000144, &gMaryScheduleData.payload_storage[1] },
        { 0x000001A4, &gMaryScheduleData.payload_storage[10] },
        { 0x000001BC, &gMaryScheduleData.payload_storage[11] },
        { 0x0000025B, &gMaryScheduleData.payload_storage[12] },
        { 0x00000273, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000001A4, &gMaryScheduleData.payload_storage[10] },
        { 0x000001BC, &gMaryScheduleData.payload_storage[11] },
        { 0x0000025B, &gMaryScheduleData.payload_storage[12] },
        { 0x00000273, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000000F0, &gMaryScheduleData.payload_storage[2] },
        { 0x000000F7, &gMaryScheduleData.payload_storage[3] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[4] },
        { 0x000002D7, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000001AA, &gMaryScheduleData.payload_storage[5] },
        { 0x000001C5, &gMaryScheduleData.payload_storage[23] },
        { 0x000001CE, &gMaryScheduleData.payload_storage[24] },
        { 0x00000258, &gMaryScheduleData.payload_storage[25] },
        { 0x00000262, &gMaryScheduleData.payload_storage[9] },
        { 0x0000027C, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_5
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[0] },
        { 0x0000003C, &gMaryScheduleData.payload_storage[1] },
        { 0x000001A4, &gMaryScheduleData.payload_storage[5] },
        { 0x000001BF, &gMaryScheduleData.payload_storage[19] },
        { 0x000001CF, &gMaryScheduleData.payload_storage[20] },
        { 0x00000258, &gMaryScheduleData.payload_storage[21] },
        { 0x00000268, &gMaryScheduleData.payload_storage[9] },
        { 0x00000282, &gMaryScheduleData.payload_storage[1] },
        { 0x000003C0, &gMaryScheduleData.payload_storage[0] },
    },
    // entries_6
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[1] },
        { 0x000001E0, &gMaryScheduleData.payload_storage[16] },
        { 0x000001EA, &gMaryScheduleData.payload_storage[17] },
        { 0x0000021C, &gMaryScheduleData.payload_storage[18] },
        { 0x00000226, &gMaryScheduleData.payload_storage[1] },
    },
    // entries_7
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[1] },
    },
    // entries_8
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[1] },
    },
    // entries_9
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x000000B4, &gMaryScheduleData.payload_storage[3] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_10
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_11
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x000000B4, &gMaryScheduleData.payload_storage[3] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_12
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_13
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_14
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_15
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x000000F0, &gMaryScheduleData.payload_storage[22] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[15] },
        { 0x00000348, &gMaryScheduleData.payload_storage[14] },
    },
    // entries_16
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[15] },
        { 0x0000012C, &gMaryScheduleData.payload_storage[13] },
        { 0x000002D0, &gMaryScheduleData.payload_storage[22] },
    },
    // entries_17
    {
        { 0x00000000, &gMaryScheduleData.payload_storage[14] },
    },
    // payload_storage
    {
        { gMaryScheduleData.points_0, ARRAY_COUNT(gMaryScheduleData.points_0), 176, 120, 27, 0, true },
        { gMaryScheduleData.points_1, ARRAY_COUNT(gMaryScheduleData.points_1), 176, 160, 26, 0, true },
        { gMaryScheduleData.points_2, ARRAY_COUNT(gMaryScheduleData.points_2), 200, 160, 5, 0, false },
        { nullptr, 0, 172, 115, 24, 0, false },
        { gMaryScheduleData.points_4, ARRAY_COUNT(gMaryScheduleData.points_4), 276, 168, 5, 0, false },
        { gMaryScheduleData.points_5, ARRAY_COUNT(gMaryScheduleData.points_5), 200, 160, 5, 0, false },
        { gMaryScheduleData.points_6, ARRAY_COUNT(gMaryScheduleData.points_6), 1200, 752, 0, 0, false },
        { gMaryScheduleData.points_7, ARRAY_COUNT(gMaryScheduleData.points_7), 344, 208, 0, 0, true },
        { gMaryScheduleData.points_8, ARRAY_COUNT(gMaryScheduleData.points_8), 344, 208, 0, 0, false },
        { gMaryScheduleData.points_9, ARRAY_COUNT(gMaryScheduleData.points_9), 104, 704, 5, 0, false },
        { gMaryScheduleData.points_10, ARRAY_COUNT(gMaryScheduleData.points_10), 200, 160, 5, 0, false },
        { nullptr, 0, 120, 138, 15, 0, false },
        { gMaryScheduleData.points_12, ARRAY_COUNT(gMaryScheduleData.points_12), 688, 160, 5, 0, false },
        { gMaryScheduleData.points_13, ARRAY_COUNT(gMaryScheduleData.points_13), 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { gMaryScheduleData.points_15, ARRAY_COUNT(gMaryScheduleData.points_15), 256, 152, 29, 0, true },
        { gMaryScheduleData.points_16, ARRAY_COUNT(gMaryScheduleData.points_16), 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gMaryScheduleData.points_18, ARRAY_COUNT(gMaryScheduleData.points_18), 228, 145, 2, 0, false },
        { gMaryScheduleData.points_19, ARRAY_COUNT(gMaryScheduleData.points_19), 104, 0, 7, 0, false },
        { nullptr, 0, 48, 88, 38, 0, false },
        { gMaryScheduleData.points_21, ARRAY_COUNT(gMaryScheduleData.points_21), 296, 116, 7, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
        { gMaryScheduleData.points_23, ARRAY_COUNT(gMaryScheduleData.points_23), 240, 480, 8, 0, false },
        { nullptr, 0, 256, 272, 8, 1, false },
        { gMaryScheduleData.points_25, ARRAY_COUNT(gMaryScheduleData.points_25), 256, 272, 8, 0, false },
    },
    // points_0
    {
        { 72, 2, 120, 2, false },
        { 176, 2, 120, 3, false },
    },
    // points_1
    {
        { 88, 2, 120, 1, true },
        { 160, 2, 120, 0, true },
    },
    // points_2
    {
        { 2, 216, true },
        { 5, 276, false },
        { 7, 168, true },
    },
    // points_4
    {
        { 2, 216, true },
        { 5, 200, false },
        { 7, 160, true },
    },
    // points_5
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 7, 104, false },
        { 27, 734, true },
    },
    // points_6
    {
        { 12, 912, false },
        { 13, 728, true },
        { 15, 856, false },
        { 16, 704, true },
        { 17, 832, false },
        { 18, 680, true },
        { 19, 808, false },
        { 20, 656, true },
        { 21, 776, false },
        { 22, 624, true },
        { 23, 752, false },
        { 24, 592, true },
        { 25, 720, false },
        { 26, 568, true },
        { 27, 692, false },
        { 37, 328, true },
        { 38, 656, false },
        { 44, 168, true },
        { 56, 344, false },
        { 58, 208, true },
    },
    // points_7
    {
        { 392, 2, 120, 3, false },
        { 344, 2, 120, 2, false },
    },
    // points_8
    {
        { 2, 168, true },
        { 14, 656, false },
        { 20, 328, true },
        { 21, 692, false },
        { 31, 568, true },
        { 32, 720, false },
        { 33, 592, true },
        { 34, 752, false },
        { 35, 624, true },
        { 36, 776, false },
        { 37, 656, true },
        { 38, 808, false },
        { 39, 680, true },
        { 40, 832, false },
        { 41, 704, true },
        { 42, 856, false },
        { 43, 728, true },
        { 45, 912, false },
        { 46, 752, true },
        { 58, 1216, false },
    },
    // points_9
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 24, 200, false },
        { 26, 160, true },
    },
    // points_10
    {
        { 2, 216, true },
        { 22, 688, false },
        { 24, 160, true },
    },
    // points_12
    {
        { 2, 216, true },
        { 22, 200, false },
        { 24, 160, true },
    },
    // points_13
    {
        { 108, 2, 120, 2, true },
        { 128, 2, 120, 3, false },
        { 76, 2, 120, 3, true },
        { 112, 2, 120, 2, false },
    },
    // points_15
    {
        { 96, 2, 0, 0, true },
        { 328, 2, 120, 3, false },
        { 256, 2, 0, 0, false },
        { 152, 2, 120, 0, true },
    },
    // points_16
    {
        { 6, 145, true },
        { 10, 228, false },
    },
    // points_18
    {
        { 4, 340, false },
        { 10, 0, true },
    },
    // points_19
    {
        { 6, 152, true },
        { 14, 296, false },
        { 16, 116, true },
    },
    // points_21
    {
        { 2, 152, true },
        { 10, 104, false },
        { 16, 0, true },
    },
    // points_23
    {
        { 8, 272, true },
        { 9, 256, false },
    },
    // points_25
    {
        { 1, 240, false },
        { 10, 512, true },
    },
};
