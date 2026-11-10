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

extern "C" ElliScheduleData const gElliScheduleData = {
    // descriptor
    {
        SelectElliSchedule,
        ARRAY_COUNT(gElliScheduleData.table_choices),
        gElliScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gElliScheduleData.table_storage[0],
        &gElliScheduleData.table_storage[1],
        &gElliScheduleData.table_storage[2],
        &gElliScheduleData.table_storage[3],
        &gElliScheduleData.table_storage[4],
        &gElliScheduleData.table_storage[5],
        &gElliScheduleData.table_storage[6],
        &gElliScheduleData.table_storage[7],
        &gElliScheduleData.table_storage[8],
        &gElliScheduleData.table_storage[9],
        &gElliScheduleData.table_storage[10],
        &gElliScheduleData.table_storage[11],
        &gElliScheduleData.table_storage[12],
        &gElliScheduleData.table_storage[13],
        &gElliScheduleData.table_storage[14],
        &gElliScheduleData.table_storage[15],
    },
    // table_storage
    {
        { ARRAY_COUNT(gElliScheduleData.entries_0), gElliScheduleData.entries_0 },
        { ARRAY_COUNT(gElliScheduleData.entries_1), gElliScheduleData.entries_1 },
        { ARRAY_COUNT(gElliScheduleData.entries_2), gElliScheduleData.entries_2 },
        { ARRAY_COUNT(gElliScheduleData.entries_3), gElliScheduleData.entries_3 },
        { ARRAY_COUNT(gElliScheduleData.entries_4), gElliScheduleData.entries_4 },
        { ARRAY_COUNT(gElliScheduleData.entries_5), gElliScheduleData.entries_5 },
        { ARRAY_COUNT(gElliScheduleData.entries_6), gElliScheduleData.entries_6 },
        { ARRAY_COUNT(gElliScheduleData.entries_7), gElliScheduleData.entries_7 },
        { ARRAY_COUNT(gElliScheduleData.entries_8), gElliScheduleData.entries_8 },
        { ARRAY_COUNT(gElliScheduleData.entries_9), gElliScheduleData.entries_9 },
        { ARRAY_COUNT(gElliScheduleData.entries_10), gElliScheduleData.entries_10 },
        { ARRAY_COUNT(gElliScheduleData.entries_11), gElliScheduleData.entries_11 },
        { ARRAY_COUNT(gElliScheduleData.entries_12), gElliScheduleData.entries_12 },
        { ARRAY_COUNT(gElliScheduleData.entries_13), gElliScheduleData.entries_13 },
        { ARRAY_COUNT(gElliScheduleData.entries_14), gElliScheduleData.entries_14 },
        { ARRAY_COUNT(gElliScheduleData.entries_15), gElliScheduleData.entries_15 },
    },
    // entries_0
    {
        { 0x00000000, &gElliScheduleData.payload_storage[0] },
        { 0x000000B4, &gElliScheduleData.payload_storage[1] },
        { 0x0000030C, &gElliScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gElliScheduleData.payload_storage[0] },
        { 0x000000B4, &gElliScheduleData.payload_storage[2] },
        { 0x000000CA, &gElliScheduleData.payload_storage[3] },
        { 0x000001A4, &gElliScheduleData.payload_storage[4] },
        { 0x000001B4, &gElliScheduleData.payload_storage[5] },
        { 0x00000258, &gElliScheduleData.payload_storage[6] },
        { 0x00000268, &gElliScheduleData.payload_storage[3] },
        { 0x0000030C, &gElliScheduleData.payload_storage[7] },
        { 0x00000322, &gElliScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gElliScheduleData.payload_storage[0] },
        { 0x000000B4, &gElliScheduleData.payload_storage[1] },
        { 0x0000030C, &gElliScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gElliScheduleData.payload_storage[0] },
        { 0x000000B4, &gElliScheduleData.payload_storage[2] },
        { 0x000000CA, &gElliScheduleData.payload_storage[3] },
        { 0x000001A4, &gElliScheduleData.payload_storage[4] },
        { 0x000001B4, &gElliScheduleData.payload_storage[5] },
        { 0x00000258, &gElliScheduleData.payload_storage[6] },
        { 0x00000268, &gElliScheduleData.payload_storage[3] },
        { 0x0000030C, &gElliScheduleData.payload_storage[7] },
        { 0x00000322, &gElliScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gElliScheduleData.payload_storage[0] },
    },
    // entries_5
    {
        { 0x00000000, &gElliScheduleData.payload_storage[1] },
        { 0x000000F0, &gElliScheduleData.payload_storage[8] },
        { 0x000000FA, &gElliScheduleData.payload_storage[9] },
        { 0x0000012C, &gElliScheduleData.payload_storage[13] },
        { 0x00000136, &gElliScheduleData.payload_storage[1] },
    },
    // entries_6
    {
        { 0x00000000, &gElliScheduleData.payload_storage[0] },
    },
    // entries_7
    {
        { 0x00000000, &gElliScheduleData.payload_storage[12] },
        { 0x000000B4, &gElliScheduleData.payload_storage[1] },
        { 0x000002D0, &gElliScheduleData.payload_storage[12] },
        { 0x00000348, &gElliScheduleData.payload_storage[11] },
    },
    // entries_8
    {
        { 0x00000000, &gElliScheduleData.payload_storage[12] },
        { 0x0000012C, &gElliScheduleData.payload_storage[10] },
        { 0x000002D0, &gElliScheduleData.payload_storage[12] },
        { 0x00000348, &gElliScheduleData.payload_storage[11] },
    },
    // entries_9
    {
        { 0x00000000, &gElliScheduleData.payload_storage[12] },
        { 0x000000B4, &gElliScheduleData.payload_storage[1] },
        { 0x000002D0, &gElliScheduleData.payload_storage[12] },
        { 0x00000348, &gElliScheduleData.payload_storage[11] },
    },
    // entries_10
    {
        { 0x00000000, &gElliScheduleData.payload_storage[12] },
        { 0x0000012C, &gElliScheduleData.payload_storage[10] },
        { 0x000002D0, &gElliScheduleData.payload_storage[12] },
        { 0x00000348, &gElliScheduleData.payload_storage[11] },
    },
    // entries_11
    {
        { 0x00000000, &gElliScheduleData.payload_storage[12] },
        { 0x0000012C, &gElliScheduleData.payload_storage[10] },
        { 0x000002D0, &gElliScheduleData.payload_storage[12] },
        { 0x00000348, &gElliScheduleData.payload_storage[11] },
    },
    // entries_12
    {
        { 0x00000000, &gElliScheduleData.payload_storage[12] },
        { 0x0000012C, &gElliScheduleData.payload_storage[10] },
        { 0x000002D0, &gElliScheduleData.payload_storage[12] },
        { 0x00000348, &gElliScheduleData.payload_storage[11] },
    },
    // entries_13
    {
        { 0x00000000, &gElliScheduleData.payload_storage[12] },
        { 0x000000F0, &gElliScheduleData.payload_storage[14] },
        { 0x000002D0, &gElliScheduleData.payload_storage[12] },
        { 0x00000348, &gElliScheduleData.payload_storage[11] },
    },
    // entries_14
    {
        { 0x00000000, &gElliScheduleData.payload_storage[12] },
        { 0x0000012C, &gElliScheduleData.payload_storage[10] },
        { 0x000002D0, &gElliScheduleData.payload_storage[14] },
    },
    // entries_15
    {
        { 0x00000000, &gElliScheduleData.payload_storage[11] },
    },
    // payload_storage
    {
        { gElliScheduleData.points_0, ARRAY_COUNT(gElliScheduleData.points_0), 344, 240, 20, 0, true },
        { nullptr, 0, 136, 107, 19, 0, false },
        { gElliScheduleData.points_2, ARRAY_COUNT(gElliScheduleData.points_2), 856, 164, 5, 0, false },
        { gElliScheduleData.points_3, ARRAY_COUNT(gElliScheduleData.points_3), 80, 88, 14, 0, true },
        { gElliScheduleData.points_4, ARRAY_COUNT(gElliScheduleData.points_4), 400, 160, 5, 0, false },
        { nullptr, 0, 56, 136, 15, 3, false },
        { gElliScheduleData.points_6, ARRAY_COUNT(gElliScheduleData.points_6), 688, 160, 5, 0, false },
        { gElliScheduleData.points_7, ARRAY_COUNT(gElliScheduleData.points_7), 400, 160, 5, 0, false },
        { gElliScheduleData.points_8, ARRAY_COUNT(gElliScheduleData.points_8), 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gElliScheduleData.points_10, ARRAY_COUNT(gElliScheduleData.points_10), 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { gElliScheduleData.points_12, ARRAY_COUNT(gElliScheduleData.points_12), 256, 152, 29, 0, true },
        { gElliScheduleData.points_13, ARRAY_COUNT(gElliScheduleData.points_13), 228, 145, 2, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
    },
    // points_0
    {
        { 296, 2, 120, 2, false },
        { 344, 2, 120, 3, false },
    },
    // points_2
    {
        { 2, 216, true },
        { 20, 400, false },
        { 22, 160, true },
    },
    // points_3
    {
        { 24, 2, 120, 1, false },
        { 80, 2, 120, 1, false },
    },
    // points_4
    {
        { 2, 216, true },
        { 14, 688, false },
        { 16, 160, true },
    },
    // points_6
    {
        { 2, 216, true },
        { 14, 400, false },
        { 16, 160, true },
    },
    // points_7
    {
        { 2, 216, true },
        { 20, 856, false },
        { 22, 164, true },
    },
    // points_8
    {
        { 6, 145, true },
        { 10, 228, false },
    },
    // points_10
    {
        { 108, 2, 120, 2, true },
        { 128, 2, 120, 3, false },
        { 76, 2, 120, 3, true },
        { 112, 2, 120, 2, false },
    },
    // points_12
    {
        { 96, 2, 0, 0, true },
        { 328, 2, 120, 3, false },
        { 256, 2, 0, 0, false },
        { 152, 2, 120, 0, true },
    },
    // points_13
    {
        { 4, 340, false },
        { 10, 0, true },
    },
};
