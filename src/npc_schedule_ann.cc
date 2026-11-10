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

extern "C" AnnScheduleData const gAnnScheduleData = {
    // descriptor
    {
        SelectAnnSchedule,
        ARRAY_COUNT(gAnnScheduleData.table_choices),
        gAnnScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gAnnScheduleData.table_storage[0],
        &gAnnScheduleData.table_storage[1],
        &gAnnScheduleData.table_storage[2],
        &gAnnScheduleData.table_storage[3],
        &gAnnScheduleData.table_storage[4],
        &gAnnScheduleData.table_storage[5],
        &gAnnScheduleData.table_storage[6],
        &gAnnScheduleData.table_storage[7],
        &gAnnScheduleData.table_storage[8],
        &gAnnScheduleData.table_storage[9],
        &gAnnScheduleData.table_storage[10],
        &gAnnScheduleData.table_storage[11],
        &gAnnScheduleData.table_storage[12],
        &gAnnScheduleData.table_storage[13],
        &gAnnScheduleData.table_storage[14],
        &gAnnScheduleData.table_storage[15],
        &gAnnScheduleData.table_storage[16],
        &gAnnScheduleData.table_storage[17],
    },
    // table_storage
    {
        { ARRAY_COUNT(gAnnScheduleData.entries_0), gAnnScheduleData.entries_0 },
        { ARRAY_COUNT(gAnnScheduleData.entries_1), gAnnScheduleData.entries_1 },
        { ARRAY_COUNT(gAnnScheduleData.entries_2), gAnnScheduleData.entries_2 },
        { ARRAY_COUNT(gAnnScheduleData.entries_3), gAnnScheduleData.entries_3 },
        { ARRAY_COUNT(gAnnScheduleData.entries_4), gAnnScheduleData.entries_4 },
        { ARRAY_COUNT(gAnnScheduleData.entries_5), gAnnScheduleData.entries_5 },
        { ARRAY_COUNT(gAnnScheduleData.entries_6), gAnnScheduleData.entries_6 },
        { ARRAY_COUNT(gAnnScheduleData.entries_7), gAnnScheduleData.entries_7 },
        { ARRAY_COUNT(gAnnScheduleData.entries_8), gAnnScheduleData.entries_8 },
        { ARRAY_COUNT(gAnnScheduleData.entries_9), gAnnScheduleData.entries_9 },
        { ARRAY_COUNT(gAnnScheduleData.entries_10), gAnnScheduleData.entries_10 },
        { ARRAY_COUNT(gAnnScheduleData.entries_11), gAnnScheduleData.entries_11 },
        { ARRAY_COUNT(gAnnScheduleData.entries_12), gAnnScheduleData.entries_12 },
        { ARRAY_COUNT(gAnnScheduleData.entries_13), gAnnScheduleData.entries_13 },
        { ARRAY_COUNT(gAnnScheduleData.entries_14), gAnnScheduleData.entries_14 },
        { ARRAY_COUNT(gAnnScheduleData.entries_15), gAnnScheduleData.entries_15 },
        { ARRAY_COUNT(gAnnScheduleData.entries_16), gAnnScheduleData.entries_16 },
        { ARRAY_COUNT(gAnnScheduleData.entries_17), gAnnScheduleData.entries_17 },
    },
    // entries_0
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x0000003C, &gAnnScheduleData.payload_storage[3] },
        { 0x0000005F, &gAnnScheduleData.payload_storage[4] },
        { 0x0000006B, &gAnnScheduleData.payload_storage[5] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[6] },
        { 0x000000FD, &gAnnScheduleData.payload_storage[7] },
        { 0x0000011F, &gAnnScheduleData.payload_storage[2] },
        { 0x000001A4, &gAnnScheduleData.payload_storage[0] },
        { 0x00000258, &gAnnScheduleData.payload_storage[2] },
        { 0x0000030C, &gAnnScheduleData.payload_storage[0] },
        { 0x000003C0, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[2] },
        { 0x000001A4, &gAnnScheduleData.payload_storage[0] },
        { 0x00000258, &gAnnScheduleData.payload_storage[2] },
        { 0x0000030C, &gAnnScheduleData.payload_storage[0] },
        { 0x000003C0, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x0000003C, &gAnnScheduleData.payload_storage[3] },
        { 0x0000005F, &gAnnScheduleData.payload_storage[4] },
        { 0x0000006B, &gAnnScheduleData.payload_storage[5] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[6] },
        { 0x000000FD, &gAnnScheduleData.payload_storage[7] },
        { 0x0000011F, &gAnnScheduleData.payload_storage[2] },
        { 0x000001A4, &gAnnScheduleData.payload_storage[0] },
        { 0x00000258, &gAnnScheduleData.payload_storage[2] },
        { 0x0000030C, &gAnnScheduleData.payload_storage[0] },
        { 0x000003C0, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[2] },
        { 0x000001A4, &gAnnScheduleData.payload_storage[0] },
        { 0x00000258, &gAnnScheduleData.payload_storage[2] },
        { 0x0000030C, &gAnnScheduleData.payload_storage[0] },
        { 0x000003C0, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_4
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[0] },
        { 0x00000294, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_5
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_6
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[1] },
        { 0x00000078, &gAnnScheduleData.payload_storage[8] },
        { 0x00000082, &gAnnScheduleData.payload_storage[9] },
        { 0x000000B4, &gAnnScheduleData.payload_storage[13] },
        { 0x000000BE, &gAnnScheduleData.payload_storage[1] },
    },
    // entries_7
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_8
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x000000B4, &gAnnScheduleData.payload_storage[0] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_9
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_10
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x000000B4, &gAnnScheduleData.payload_storage[0] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_11
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_12
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_13
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_14
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_15
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x000000F0, &gAnnScheduleData.payload_storage[14] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[12] },
        { 0x00000348, &gAnnScheduleData.payload_storage[11] },
    },
    // entries_16
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[12] },
        { 0x0000012C, &gAnnScheduleData.payload_storage[10] },
        { 0x000002D0, &gAnnScheduleData.payload_storage[14] },
    },
    // entries_17
    {
        { 0x00000000, &gAnnScheduleData.payload_storage[11] },
    },
    // payload_storage
    {
        { gAnnScheduleData.points_0, ARRAY_COUNT(gAnnScheduleData.points_0), 200, 83, 21, 0, true },
        { gAnnScheduleData.points_1, ARRAY_COUNT(gAnnScheduleData.points_1), 135, 96, 22, 0, true },
        { gAnnScheduleData.points_2, ARRAY_COUNT(gAnnScheduleData.points_2), 80, 88, 23, 0, true },
        { gAnnScheduleData.points_3, ARRAY_COUNT(gAnnScheduleData.points_3), 632, 488, 5, 0, false },
        { gAnnScheduleData.points_4, ARRAY_COUNT(gAnnScheduleData.points_4), 1200, 528, 0, 0, false },
        { nullptr, 0, 1032, 432, 0, 1, false },
        { gAnnScheduleData.points_6, ARRAY_COUNT(gAnnScheduleData.points_6), 1032, 432, 0, 0, false },
        { gAnnScheduleData.points_7, ARRAY_COUNT(gAnnScheduleData.points_7), 1260, 704, 5, 0, false },
        { gAnnScheduleData.points_8, ARRAY_COUNT(gAnnScheduleData.points_8), 340, 0, 2, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { gAnnScheduleData.points_10, ARRAY_COUNT(gAnnScheduleData.points_10), 112, 76, 29, 0, true },
        { nullptr, 0, 440, -48, 29, 0, false },
        { gAnnScheduleData.points_12, ARRAY_COUNT(gAnnScheduleData.points_12), 256, 152, 29, 0, true },
        { gAnnScheduleData.points_13, ARRAY_COUNT(gAnnScheduleData.points_13), 228, 145, 2, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
    },
    // points_0
    {
        { 128, 2, 120, 2, false },
        { 160, 2, 120, 0, true },
        { 96, 2, 120, 2, false },
        { 83, 2, 120, 1, true },
        { 200, 2, 120, 3, false },
    },
    // points_1
    {
        { 200, 2, 120, 3, false },
        { 135, 2, 120, 2, false },
    },
    // points_2
    {
        { 176, 2, 120, 0, true },
        { 88, 2, 120, 1, true },
    },
    // points_3
    {
        { 2, 536, true },
        { 27, 1260, false },
        { 35, 736, true },
    },
    // points_4
    {
        { 1, 1176, false },
        { 2, 512, true },
        { 3, 1160, false },
        { 4, 496, true },
        { 5, 1144, false },
        { 6, 480, true },
        { 10, 1032, false },
        { 12, 432, true },
    },
    // points_6
    {
        { 2, 480, true },
        { 6, 1144, false },
        { 7, 496, true },
        { 8, 1160, false },
        { 9, 512, true },
        { 10, 1176, false },
        { 11, 528, true },
        { 13, 1216, false },
    },
    // points_7
    {
        { 7, 536, true },
        { 32, 632, false },
        { 34, 488, true },
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
