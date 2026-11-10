#include "npc_schedule_popuri.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectPopuriSchedule\n"
    "SelectPopuriSchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r9\n"
    "    mov\tr6, r8\n"
    "    push\t{r6, r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803D73C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803D70A\n"
    "    b .Ljp_0803D896\n"
    ".Ljp_0803D70A:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr7, [r4, #1]\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    mov\tr8, r0\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    mov\tr9, r4\n"
    "    ldr r1, .Ljp_0803D740\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetSpouseCharacterId__C13NpcCollection\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #3\n"
    "    bne .Ljp_0803D7DE\n"
    "    cmp\tr7, #2\n"
    "    bne .Ljp_0803D744\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #13\n"
    "    bne .Ljp_0803D744\n"
    "    movs\tr0, #22\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D73C: .word 0x000021CA\n"
    ".Ljp_0803D740: .word 0x00001CD4\n"
    ".Ljp_0803D744:\n"
    "    ldr r1, .Ljp_0803D758\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803D75C\n"
    "    movs\tr0, #23\n"
    "    b .Ljp_0803D8C8\n"
    "    .align 2, 0\n"
    ".Ljp_0803D758: .word 0x0000216B\n"
    ".Ljp_0803D75C:\n"
    "    ldr r1, .Ljp_0803D794\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr6, [r0, #0]\n"
    "    ldr r1, .Ljp_0803D798\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetChild__C13NpcCollection\n"
    "    negs\tr1, r0\n"
    "    orrs\tr1, r0\n"
    "    lsrs\tr4, r1, #31\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D788\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803D788\n"
    "    cmp\tr0, #4\n"
    "    bne .Ljp_0803D7AC\n"
    ".Ljp_0803D788:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803D7A0\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D79C\n"
    "    movs\tr0, #13\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D794: .word 0x00002148\n"
    ".Ljp_0803D798: .word 0x00001CD4\n"
    ".Ljp_0803D79C:\n"
    "    movs\tr0, #12\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7A0:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D7A8\n"
    "    movs\tr0, #15\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7A8:\n"
    "    movs\tr0, #14\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7AC:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D7C2\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D7C2\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803D7BE\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7BE:\n"
    "    movs\tr0, #11\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7C2:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803D7D2\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D7CE\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7CE:\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7D2:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D7DA\n"
    "    movs\tr0, #10\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7DA:\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7DE:\n"
    "    ldr r1, .Ljp_0803D800\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetRivalEventCount__C12Bachelorette\n"
    "    cmp\tr0, #4\n"
    "    bls .Ljp_0803D812\n"
    "    cmp\tr7, #1\n"
    "    bne .Ljp_0803D896\n"
    "    movs\tr0, #1\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D804\n"
    "    movs\tr0, #19\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D800: .word 0x00001D6C\n"
    ".Ljp_0803D804:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D80E\n"
    "    movs\tr0, #20\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D80E:\n"
    "    movs\tr0, #21\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D812:\n"
    "    cmp\tr7, #2\n"
    "    bne .Ljp_0803D834\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #30\n"
    "    bne .Ljp_0803D834\n"
    "    ldr r1, .Ljp_0803D830\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803D834\n"
    "    movs\tr0, #17\n"
    "    b .Ljp_0803D8C8\n"
    "    .align 2, 0\n"
    ".Ljp_0803D830: .word 0x000021A3\n"
    ".Ljp_0803D834:\n"
    "    ldr r1, .Ljp_0803D86C\n"
    "    adds\tr0, r5, r1\n"
    "    movs\tr1, #3\n"
    "    bl GetBachelorette__C13NpcCollectionUi\n"
    "    cmp\tr7, #3\n"
    "    bne .Ljp_0803D878\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #14\n"
    "    bne .Ljp_0803D878\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_0803D878\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D878\n"
    "    bl GetLove__C12Bachelorette\n"
    "    ldr r1, .Ljp_0803D870\n"
    "    cmp\tr0, r1\n"
    "    bls .Ljp_0803D878\n"
    "    ldr r1, .Ljp_0803D874\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803D878\n"
    "    movs\tr0, #18\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D86C: .word 0x00001CD4\n"
    ".Ljp_0803D870: .word 0x0000270F\n"
    ".Ljp_0803D874: .word 0x000021A3\n"
    ".Ljp_0803D878:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D88A\n"
    "    movs\tr0, #16\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D88A:\n"
    "    ldr r1, .Ljp_0803D89C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803D8A0\n"
    ".Ljp_0803D896:\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803D8C8\n"
    "    .align 2, 0\n"
    ".Ljp_0803D89C: .word 0x0000215A\n"
    ".Ljp_0803D8A0:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D8BC\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D8B8\n"
    "    cmp\tr7, #1\n"
    "    bne .Ljp_0803D8B4\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D8B4:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D8B8:\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D8BC:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D8C6\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D8C6:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803D8C8:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3, r4}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

// Recovered schedule data at US ROM 0x080F1FC0 (JP 0x080F181C).
// The two regional payloads differ only in relocated function/data pointers.

extern "C" PopuriScheduleData const gPopuriScheduleData = {
    // descriptor
    { SelectPopuriSchedule, ARRAY_COUNT(gPopuriScheduleData.table_choices), gPopuriScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gPopuriScheduleData.table_storage[0], &gPopuriScheduleData.table_storage[1], &gPopuriScheduleData.table_storage[2],
        &gPopuriScheduleData.table_storage[3], &gPopuriScheduleData.table_storage[4], &gPopuriScheduleData.table_storage[5], &gPopuriScheduleData.table_storage[6],
        &gPopuriScheduleData.table_storage[7], &gPopuriScheduleData.table_storage[8], &gPopuriScheduleData.table_storage[9], &gPopuriScheduleData.table_storage[10],
        &gPopuriScheduleData.table_storage[11], &gPopuriScheduleData.table_storage[12], &gPopuriScheduleData.table_storage[13], &gPopuriScheduleData.table_storage[14],
        &gPopuriScheduleData.table_storage[15], &gPopuriScheduleData.table_storage[16], &gPopuriScheduleData.table_storage[17], &gPopuriScheduleData.table_storage[18],
        &gPopuriScheduleData.table_storage[19], &gPopuriScheduleData.table_storage[20], &gPopuriScheduleData.table_storage[21], &gPopuriScheduleData.table_storage[22],
    },
    // table_storage
    {
        { ARRAY_COUNT(gPopuriScheduleData.entries_0), gPopuriScheduleData.entries_0 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_1), gPopuriScheduleData.entries_1 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_2), gPopuriScheduleData.entries_2 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_3), gPopuriScheduleData.entries_3 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_4), gPopuriScheduleData.entries_4 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_5), gPopuriScheduleData.entries_5 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_6), gPopuriScheduleData.entries_6 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_7), gPopuriScheduleData.entries_7 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_8), gPopuriScheduleData.entries_8 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_9), gPopuriScheduleData.entries_9 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_10), gPopuriScheduleData.entries_10 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_11), gPopuriScheduleData.entries_11 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_12), gPopuriScheduleData.entries_12 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_13), gPopuriScheduleData.entries_13 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_14), gPopuriScheduleData.entries_14 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_15), gPopuriScheduleData.entries_15 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_16), gPopuriScheduleData.entries_16 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_17), gPopuriScheduleData.entries_17 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_18), gPopuriScheduleData.entries_18 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_19), gPopuriScheduleData.entries_19 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_20), gPopuriScheduleData.entries_20 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_21), gPopuriScheduleData.entries_21 },
        { ARRAY_COUNT(gPopuriScheduleData.entries_22), gPopuriScheduleData.entries_22 },
    },
    // entries_0
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 60, &gPopuriScheduleData.payload_storage[1] },
        { 98, &gPopuriScheduleData.payload_storage[2] },
        { 113, &gPopuriScheduleData.payload_storage[3] },
        { 240, &gPopuriScheduleData.payload_storage[4] },
        { 256, &gPopuriScheduleData.payload_storage[5] },
        { 293, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_1
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_2
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 180, &gPopuriScheduleData.payload_storage[7] },
        { 227, &gPopuriScheduleData.payload_storage[8] },
        { 251, &gPopuriScheduleData.payload_storage[9] },
        { 421, &gPopuriScheduleData.payload_storage[10] },
        { 446, &gPopuriScheduleData.payload_storage[11] },
        { 462, &gPopuriScheduleData.payload_storage[12] },
        { 600, &gPopuriScheduleData.payload_storage[13] },
        { 608, &gPopuriScheduleData.payload_storage[14] },
        { 655, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_3
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 180, &gPopuriScheduleData.payload_storage[7] },
        { 227, &gPopuriScheduleData.payload_storage[8] },
        { 251, &gPopuriScheduleData.payload_storage[9] },
        { 600, &gPopuriScheduleData.payload_storage[10] },
        { 625, &gPopuriScheduleData.payload_storage[14] },
        { 672, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_4
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 420, &gPopuriScheduleData.payload_storage[7] },
        { 467, &gPopuriScheduleData.payload_storage[15] },
        { 486, &gPopuriScheduleData.payload_storage[16] },
        { 600, &gPopuriScheduleData.payload_storage[17] },
        { 620, &gPopuriScheduleData.payload_storage[14] },
        { 667, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_5
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_6
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 180, &gPopuriScheduleData.payload_storage[0] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_7
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_8
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_9
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 180, &gPopuriScheduleData.payload_storage[0] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_10
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_11
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_12
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_13
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_14
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[18] },
        { 840, &gPopuriScheduleData.payload_storage[20] },
    },
    // entries_15
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
    },
    // entries_16
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 240, &gPopuriScheduleData.payload_storage[23] },
        { 250, &gPopuriScheduleData.payload_storage[21] },
        { 300, &gPopuriScheduleData.payload_storage[22] },
        { 310, &gPopuriScheduleData.payload_storage[0] },
    },
    // entries_17
    {
        { 0, &gPopuriScheduleData.payload_storage[23] },
        { 10, &gPopuriScheduleData.payload_storage[21] },
        { 60, &gPopuriScheduleData.payload_storage[22] },
        { 70, &gPopuriScheduleData.payload_storage[0] },
    },
    // entries_18
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
    },
    // entries_19
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 120, &gPopuriScheduleData.payload_storage[7] },
        { 167, &gPopuriScheduleData.payload_storage[15] },
        { 186, &gPopuriScheduleData.payload_storage[16] },
        { 240, &gPopuriScheduleData.payload_storage[17] },
        { 260, &gPopuriScheduleData.payload_storage[14] },
        { 307, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_20
    {
        { 0, &gPopuriScheduleData.payload_storage[0] },
        { 780, &gPopuriScheduleData.payload_storage[6] },
    },
    // entries_21
    {
        { 0, &gPopuriScheduleData.payload_storage[18] },
        { 300, &gPopuriScheduleData.payload_storage[19] },
        { 720, &gPopuriScheduleData.payload_storage[24] },
    },
    // entries_22
    {
        { 0, &gPopuriScheduleData.payload_storage[20] },
    },
    // payload_storage
    {
        { gPopuriScheduleData.points_0, ARRAY_COUNT(gPopuriScheduleData.points_0), 168, 104, 10, 0, 1 },
        { gPopuriScheduleData.points_1, ARRAY_COUNT(gPopuriScheduleData.points_1), 572, 227, 7, 0, 0 },
        { gPopuriScheduleData.points_2, ARRAY_COUNT(gPopuriScheduleData.points_2), 1200, 528, 0, 0, 0 },
        { gPopuriScheduleData.points_3, ARRAY_COUNT(gPopuriScheduleData.points_3), 984, 416, 0, 0, 1 },
        { gPopuriScheduleData.points_4, ARRAY_COUNT(gPopuriScheduleData.points_4), 984, 416, 0, 0, 0 },
        { gPopuriScheduleData.points_5, ARRAY_COUNT(gPopuriScheduleData.points_5), 812, 512, 7, 0, 0 },
        { gPopuriScheduleData.points_6, ARRAY_COUNT(gPopuriScheduleData.points_6), 168, 72, 11, 0, 1 },
        { gPopuriScheduleData.points_7, ARRAY_COUNT(gPopuriScheduleData.points_7), 572, 227, 7, 0, 0 },
        { gPopuriScheduleData.points_8, ARRAY_COUNT(gPopuriScheduleData.points_8), 1260, 704, 5, 0, 0 },
        { gPopuriScheduleData.points_9, ARRAY_COUNT(gPopuriScheduleData.points_9), 248, 88, 12, 0, 1 },
        { gPopuriScheduleData.points_10, ARRAY_COUNT(gPopuriScheduleData.points_10), 1232, 156, 5, 0, 0 },
        { gPopuriScheduleData.points_11, ARRAY_COUNT(gPopuriScheduleData.points_11), 220, 0, 6, 0, 0 },
        { gPopuriScheduleData.points_12, ARRAY_COUNT(gPopuriScheduleData.points_12), 280, 352, 6, 0, 1 },
        { gPopuriScheduleData.points_13, ARRAY_COUNT(gPopuriScheduleData.points_13), 280, 352, 6, 0, 0 },
        { gPopuriScheduleData.points_14, ARRAY_COUNT(gPopuriScheduleData.points_14), 1272, 0, 7, 0, 0 },
        { gPopuriScheduleData.points_15, ARRAY_COUNT(gPopuriScheduleData.points_15), 0, 280, 1, 0, 0 },
        { nullptr, 0, 256, 232, 1, 3, 0 },
        { gPopuriScheduleData.points_17, ARRAY_COUNT(gPopuriScheduleData.points_17), 256, 232, 1, 0, 0 },
        { gPopuriScheduleData.points_18, ARRAY_COUNT(gPopuriScheduleData.points_18), 256, 152, 29, 0, 1 },
        { gPopuriScheduleData.points_19, ARRAY_COUNT(gPopuriScheduleData.points_19), 112, 76, 29, 0, 1 },
        { nullptr, 0, 440, -48, 29, 0, 0 },
        { nullptr, 0, 228, 145, 2, 1, 0 },
        { gPopuriScheduleData.points_22, ARRAY_COUNT(gPopuriScheduleData.points_22), 228, 145, 2, 0, 0 },
        { gPopuriScheduleData.points_23, ARRAY_COUNT(gPopuriScheduleData.points_23), 340, 0, 2, 0, 0 },
        { nullptr, 0, 0, 0, 564, 1, 0 },
    },
    // points_0
    {
        { 224, 2, 120, 3, 0 },
        { 168, 2, 120, 2, 0 },
    },
    // points_1
    {
        { 1, 248, 1 },
        { 5, 472, 0 },
        { 9, 152, 1 },
        { 23, 812, 0 },
        { 38, 544, 1 },
    },
    // points_2
    {
        { 1, 1176, 0 },
        { 2, 512, 1 },
        { 3, 1160, 0 },
        { 4, 496, 1 },
        { 5, 1144, 0 },
        { 6, 480, 1 },
        { 12, 984, 0 },
        { 15, 416, 1 },
    },
    // points_3
    {
        { 944, 2, 0, 0, 0 },
        { 374, 2, 120, 3, 1 },
        { 416, 2, 0, 0, 1 },
        { 984, 2, 120, 1, 0 },
    },
    // points_4
    {
        { 3, 480, 1 },
        { 9, 1144, 0 },
        { 10, 496, 1 },
        { 11, 1160, 0 },
        { 12, 512, 1 },
        { 13, 1176, 0 },
        { 14, 528, 1 },
        { 16, 1216, 0 },
    },
    // points_5
    {
        { 14, 152, 1 },
        { 28, 472, 0 },
        { 32, 248, 1 },
        { 36, 572, 0 },
        { 37, 227, 1 },
    },
    // points_6
    {
        { 138, 2, 120, 1, 1 },
        { 72, 2, 120, 0, 1 },
    },
    // points_7
    {
        { 1, 248, 1 },
        { 5, 472, 0 },
        { 9, 152, 1 },
        { 40, 1248, 0 },
        { 41, 128, 1 },
        { 42, 1272, 0 },
        { 47, 0, 1 },
    },
    // points_8
    {
        { 19, 240, 1 },
        { 20, 1248, 0 },
        { 21, 216, 1 },
        { 22, 1232, 0 },
        { 24, 156, 1 },
    },
    // points_9
    {
        { 280, 2, 120, 3, 0 },
        { 248, 2, 120, 2, 0 },
    },
    // points_10
    {
        { 2, 216, 1 },
        { 3, 1248, 0 },
        { 4, 240, 1 },
        { 5, 1260, 0 },
        { 25, 736, 1 },
    },
    // points_11
    {
        { 14, 352, 1 },
        { 16, 280, 0 },
    },
    // points_12
    {
        { 344, 2, 120, 3, 0 },
        { 280, 2, 120, 2, 0 },
    },
    // points_13
    {
        { 3, 220, 0 },
        { 8, 480, 1 },
    },
    // points_14
    {
        { 5, 128, 1 },
        { 6, 1248, 0 },
        { 7, 152, 1 },
        { 38, 472, 0 },
        { 42, 248, 1 },
        { 46, 572, 0 },
        { 47, 227, 1 },
    },
    // points_15
    {
        { 3, 64, 0 },
        { 6, 360, 1 },
        { 8, 104, 0 },
        { 13, 232, 1 },
        { 19, 256, 0 },
    },
    // points_17
    {
        { 6, 104, 0 },
        { 11, 360, 1 },
        { 13, 64, 0 },
        { 16, 280, 1 },
        { 20, -16, 0 },
    },
    // points_18
    {
        { 96, 2, 0, 0, 1 },
        { 328, 2, 120, 3, 0 },
        { 256, 2, 0, 0, 0 },
        { 152, 2, 120, 0, 1 },
    },
    // points_19
    {
        { 108, 2, 120, 2, 1 },
        { 128, 2, 120, 3, 0 },
        { 76, 2, 120, 3, 1 },
        { 112, 2, 120, 2, 0 },
    },
    // points_22
    {
        { 4, 340, 0 },
        { 10, 0, 1 },
    },
    // points_23
    {
        { 6, 145, 1 },
        { 10, 228, 0 },
    },
};
