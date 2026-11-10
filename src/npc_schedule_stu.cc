#include "npc_schedule_stu.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectStuSchedule\n"
    "SelectStuSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E598\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_0803E5BC\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr2, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    cmp\tr2, #2\n"
    "    bne .Ljp_0803E5A0\n"
    "    cmp\tr1, #30\n"
    "    bne .Ljp_0803E5A0\n"
    "    ldr r3, .Ljp_0803E59C\n"
    "    adds\tr0, r5, r3\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsrs\tr0, r0, #6\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803E5A0\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E598: .word 0x000021CA\n"
    ".Ljp_0803E59C: .word 0x000021A2\n"
    ".Ljp_0803E5A0:\n"
    "    adds\tr0, r2, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E5B0\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E5B0:\n"
    "    ldr r1, .Ljp_0803E5C0\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E5C4\n"
    ".Ljp_0803E5BC:\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E5C0: .word 0x0000215A\n"
    ".Ljp_0803E5C4:\n"
    "    cmp\tr4, #1\n"
    "    beq .Ljp_0803E5CC\n"
    "    cmp\tr4, #3\n"
    "    bne .Ljp_0803E5D0\n"
    ".Ljp_0803E5CC:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E5D0:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E5DA\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E5DC\n"
    ".Ljp_0803E5DA:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E5DC:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" NpcScheduleStorage_080F61FC const gUnk_080F61FC = {
    {
        SelectStuSchedule,
        6,
        gUnk_080F61FC.table_choices,
    },
    {
        nullptr,
        &gUnk_080F61FC.table_storage[0],
        &gUnk_080F61FC.table_storage[1],
        &gUnk_080F61FC.table_storage[2],
        &gUnk_080F61FC.table_storage[3],
        &gUnk_080F61FC.table_storage[4],
    },
    {
        { 5, &gUnk_080F61FC.entry_storage[0] },
        { 1, &gUnk_080F61FC.entry_storage[5] },
        { 1, &gUnk_080F61FC.entry_storage[6] },
        { 1, &gUnk_080F61FC.entry_storage[7] },
        { 5, &gUnk_080F61FC.entry_storage[8] },
    },
    {
        { 0x00000000, &gUnk_080F61FC.payload_storage[0] },
        { 0x000001A4, &gUnk_080F61FC.payload_storage[1] },
        { 0x000001C7, &gUnk_080F61FC.payload_storage[2] },
        { 0x00000258, &gUnk_080F61FC.payload_storage[3] },
        { 0x0000027B, &gUnk_080F61FC.payload_storage[0] },
        { 0x00000000, &gUnk_080F61FC.payload_storage[0] },
        { 0x00000000, &gUnk_080F61FC.payload_storage[0] },
        { 0x00000000, &gUnk_080F61FC.payload_storage[0] },
        { 0x00000000, &gUnk_080F61FC.payload_storage[0] },
        { 0x00000078, &gUnk_080F61FC.payload_storage[6] },
        { 0x00000082, &gUnk_080F61FC.payload_storage[4] },
        { 0x000000B4, &gUnk_080F61FC.payload_storage[5] },
        { 0x000000BE, &gUnk_080F61FC.payload_storage[0] },
    },
    {
        { &gUnk_080F61FC.detail_storage[0], 2, 176, 160, 14, 0, true },
        { &gUnk_080F61FC.detail_storage[2], 3, 400, 160, 5, 0, false },
        { nullptr, 0, 1200, 200, 5, 0, false },
        { &gUnk_080F61FC.detail_storage[5], 3, 1200, 200, 5, 0, false },
        { nullptr, 0, 228, 145, 2, 1, false },
        { &gUnk_080F61FC.detail_storage[8], 2, 228, 145, 2, 0, false },
        { &gUnk_080F61FC.detail_storage[10], 2, 340, 0, 2, 0, false },
    },
    {
        { 0x0060, 0x0002, 0x0078, 0x0005 },
        { 0x00A0, 0x0002, 0x0078, 0x0004 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0022, 0x04B0, 0x0000, 0x0000 },
        { 0x0023, 0x00C8, 0x0001, 0x0000 },
        { 0x0001, 0x00D8, 0x0001, 0x0000 },
        { 0x0021, 0x0190, 0x0000, 0x0000 },
        { 0x0023, 0x00A0, 0x0001, 0x0000 },
        { 0x0004, 0x0154, 0x0000, 0x0000 },
        { 0x000A, 0x0000, 0x0001, 0x0000 },
        { 0x0006, 0x0091, 0x0001, 0x0000 },
        { 0x000A, 0x00E4, 0x0000, 0x0000 },
    },
};
