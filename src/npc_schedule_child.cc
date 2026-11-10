#include "npc_schedule_child.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectChildSchedule\n"
    "SelectChildSchedule:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r0, .Ljp_0803D958\n"
    "    adds\tr4, r5, r0\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetChild__C13NpcCollection\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D93E\n"
    "    b .Ljp_0803DA52\n"
    ".Ljp_0803D93E:\n"
    "    bl GetAgeDays__C5Child\n"
    "    cmp\tr0, #59\t@ 0x3b\n"
    "    bls .Ljp_0803D948\n"
    "    b .Ljp_0803DA4E\n"
    ".Ljp_0803D948:\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetSpouseCharacterId__C13NpcCollection\n"
    "    adds\tr6, r0, #0\n"
    "    cmp\tr6, #31\n"
    "    bne .Ljp_0803D95C\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803DA54\n"
    ".Ljp_0803D958: .word 0x00001CD4\n"
    ".Ljp_0803D95C:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    cmp\tr0, #2\n"
    "    bne .Ljp_0803D97A\n"
    "    cmp\tr1, #13\n"
    "    bne .Ljp_0803D97A\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803DA54\n"
    ".Ljp_0803D97A:\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DA24\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803DA24\n"
    "    cmp\tr0, #4\n"
    "    beq .Ljp_0803DA24\n"
    "    ldr r1, .Ljp_0803D9A4\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    subs\tr0, r6, #3\n"
    "    cmp\tr0, #28\n"
    "    bhi .Ljp_0803DA4A\n"
    "    lsls\tr0, r0, #2\n"
    "    ldr r1, .Ljp_0803D9A8\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    mov\tpc, r0\n"
    ".Ljp_0803D9A4: .word 0x00002148\n"
    ".Ljp_0803D9A8: .word .Ljp_0803D9AC\n"
    ".Ljp_0803D9AC: .word .Ljp_0803DA28\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA20\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA32\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA40\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA46\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    "    .word .Ljp_0803DA4A\n"
    ".Ljp_0803DA20:\n"
    "    cmp\tr4, #1\n"
    "    bne .Ljp_0803DA4A\n"
    ".Ljp_0803DA24:\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803DA54\n"
    ".Ljp_0803DA28:\n"
    "    cmp\tr2, #0\n"
    "    beq .Ljp_0803DA24\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_0803DA4A\n"
    "    b .Ljp_0803DA24\n"
    ".Ljp_0803DA32:\n"
    "    cmp\tr2, #0\n"
    "    beq .Ljp_0803DA24\n"
    "    cmp\tr4, #2\n"
    "    beq .Ljp_0803DA24\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_0803DA4A\n"
    "    b .Ljp_0803DA24\n"
    ".Ljp_0803DA40:\n"
    "    cmp\tr4, #3\n"
    "    bne .Ljp_0803DA4A\n"
    "    b .Ljp_0803DA24\n"
    ".Ljp_0803DA46:\n"
    "    cmp\tr2, #0\n"
    "    beq .Ljp_0803DA24\n"
    ".Ljp_0803DA4A:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803DA54\n"
    ".Ljp_0803DA4E:\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803DA54\n"
    ".Ljp_0803DA52:\n"
    "    movs\tr0, #0\n"
    ".Ljp_0803DA54:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

// Recovered schedule data at US ROM 0x080F29C0 (JP 0x080F221C).
// The two regional payloads differ only in relocated function/data pointers.

extern "C" ChildScheduleData const gChildScheduleData = {
    // descriptor
    { SelectChildSchedule, ARRAY_COUNT(gChildScheduleData.table_choices), gChildScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gChildScheduleData.table_storage[0], &gChildScheduleData.table_storage[1], &gChildScheduleData.table_storage[2],
        &gChildScheduleData.table_storage[3], &gChildScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gChildScheduleData.entries_0), gChildScheduleData.entries_0 },
        { ARRAY_COUNT(gChildScheduleData.entries_1), gChildScheduleData.entries_1 },
        { ARRAY_COUNT(gChildScheduleData.entries_2), gChildScheduleData.entries_2 },
        { ARRAY_COUNT(gChildScheduleData.entries_3), gChildScheduleData.entries_3 },
        { ARRAY_COUNT(gChildScheduleData.entries_4), gChildScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0, &gChildScheduleData.payload_storage[0] },
        { 180, &gChildScheduleData.payload_storage[1] },
        { 720, &gChildScheduleData.payload_storage[0] },
        { 840, &gChildScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0, &gChildScheduleData.payload_storage[0] },
        { 300, &gChildScheduleData.payload_storage[1] },
        { 720, &gChildScheduleData.payload_storage[0] },
        { 840, &gChildScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0, &gChildScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0, &gChildScheduleData.payload_storage[2] },
        { 300, &gChildScheduleData.payload_storage[3] },
        { 720, &gChildScheduleData.payload_storage[1] },
    },
    // entries_4
    {
        { 0, &gChildScheduleData.payload_storage[0] },
        { 180, &gChildScheduleData.payload_storage[1] },
    },
    // payload_storage
    {
        { nullptr, 0, 0, 0, 564, 1, 0 },
        { nullptr, 0, 416, -48, 29, 0, 0 },
        { gChildScheduleData.points_2, ARRAY_COUNT(gChildScheduleData.points_2), 352, 128, 29, 0, 1 },
        { gChildScheduleData.points_3, ARRAY_COUNT(gChildScheduleData.points_3), 56, 128, 29, 0, 1 },
    },
    // points_2
    {
        { 408, 2, 120, 3, 0 },
        { 160, 2, 120, 0, 1 },
        { 352, 2, 120, 2, 0 },
        { 128, 2, 120, 1, 1 },
    },
    // points_3
    {
        { 160, 2, 120, 0, 1 },
        { 104, 2, 120, 3, 0 },
        { 128, 2, 120, 1, 1 },
        { 56, 2, 120, 2, 0 },
    },
};
