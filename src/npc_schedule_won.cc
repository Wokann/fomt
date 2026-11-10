#include "npc_schedule_won.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectWonSchedule\n"
    "SelectWonSchedule:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #12\n"
    "    adds\tr5, r0, #0\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    adds\tr6, r0, #0\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    adds\tr4, r0, #0\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r4, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E324\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E356\n"
    ".Ljp_0803E324:\n"
    "    movs\tr3, #200\t@ 0xc8\n"
    "    str\tr3, [sp, #4]\n"
    "    ldrb\tr0, [r5, #16]\n"
    "    lsrs\tr2, r0, #3\n"
    "    lsls\tr1, r2, #3\n"
    "    subs\tr1, r1, r2\n"
    "    lsls\tr0, r0, #29\n"
    "    lsrs\tr0, r0, #29\n"
    "    adds\tr1, r1, r0\n"
    "    str\tr1, [sp, #8]\n"
    "    add\tr2, sp, #8\n"
    "    add\tr0, sp, #4\n"
    "    cmp\tr3, r1\n"
    "    bls .Ljp_0803E342\n"
    "    adds\tr0, r2, #0\n"
    ".Ljp_0803E342:\n"
    "    ldr\tr0, [r0, #0]\n"
    "    cmp\tr0, #1\n"
    "    bhi .Ljp_0803E354\n"
    "    cmp\tr6, #0\n"
    "    bne .Ljp_0803E354\n"
    "    cmp\tr4, #2\n"
    "    bhi .Ljp_0803E354\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E356\n"
    ".Ljp_0803E354:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E356:\n"
    "    add\tsp, #12\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

extern "C" NpcScheduleStorage_080F597C const gUnk_080F597C = {
    {
        SelectWonSchedule,
        3,
        gUnk_080F597C.table_choices,
    },
    {
        nullptr,
        &gUnk_080F597C.table_storage[0],
        &gUnk_080F597C.table_storage[1],
    },
    {
        { 1, &gUnk_080F597C.entry_storage[0] },
        { 1, &gUnk_080F597C.entry_storage[1] },
    },
    {
        { 0x00000000, &gUnk_080F597C.payload_storage[0] },
        { 0x00000000, &gUnk_080F597C.payload_storage[0] },
    },
    {
        { nullptr, 0, 191, 141, 13, 2, false },
    },
};
