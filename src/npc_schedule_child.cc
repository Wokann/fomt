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

ScheduleInfo const gUnk_080F221C = {
    SelectChildSchedule,
    6,
    gUnk_080F29CC,
};

Schedule const * const gUnk_080F29CC[] = {
    nullptr, &gUnk_080F29E4, &gUnk_080F29EC, &gUnk_080F29F4,
    &gUnk_080F29FC, &gUnk_080F2A04,
};

Schedule const gUnk_080F29E4 = { 4, gUnk_080F2A0C };
Schedule const gUnk_080F29EC = { 4, gUnk_080F2A2C };
Schedule const gUnk_080F29F4 = { 1, gUnk_080F2A4C };
Schedule const gUnk_080F29FC = { 3, gUnk_080F2A54 };
Schedule const gUnk_080F2A04 = { 2, gUnk_080F2A6C };

ScheduleEntry const gUnk_080F2A0C[] = {
    { 0, &gUnk_080F2A7C },
    { 180, &gUnk_080F2A88 },
    { 720, &gUnk_080F2A7C },
    { 840, &gUnk_080F2A88 },
};

ScheduleEntry const gUnk_080F2A2C[] = {
    { 0, &gUnk_080F2A7C },
    { 300, &gUnk_080F2A88 },
    { 720, &gUnk_080F2A7C },
    { 840, &gUnk_080F2A88 },
};

ScheduleEntry const gUnk_080F2A4C[] = {
    { 0, &gUnk_080F2A88 },
};

ScheduleEntry const gUnk_080F2A54[] = {
    { 0, &gUnk_080F2A94 },
    { 300, &gUnk_080F2AA0 },
    { 720, &gUnk_080F2A88 },
};

ScheduleEntry const gUnk_080F2A6C[] = {
    { 0, &gUnk_080F2A7C },
    { 180, &gUnk_080F2A88 },
};

PathInfo const gUnk_080F2A7C = {
    nullptr,
    0,
    0,
    0,
    564,
    1,
    0,
};

PathInfo const gUnk_080F2A88 = {
    nullptr,
    0,
    416,
    -48,
    29,
    0,
    0,
};

PathInfo const gUnk_080F2A94 = {
    (void const *)gUnk_080F2AAC,
    4,
    352,
    128,
    29,
    0,
    1,
};

PathInfo const gUnk_080F2AA0 = {
    (void const *)gUnk_080F2ACC,
    4,
    56,
    128,
    29,
    0,
    1,
};

PathPointB const gUnk_080F2AAC[] = {
    { 408, 2, 120, 3, 0 },
    { 160, 2, 120, 0, 1 },
    { 352, 2, 120, 2, 0 },
    { 128, 2, 120, 1, 1 },
};

PathPointB const gUnk_080F2ACC[] = {
    { 160, 2, 120, 0, 1 },
    { 104, 2, 120, 3, 0 },
    { 128, 2, 120, 1, 1 },
    { 56, 2, 120, 2, 0 },
};
