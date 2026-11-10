#include "npc_schedule_carter.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectCarterSchedule\n"
    "SelectCarterSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E768\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    movs\tr0, #124\t@ 0x7c\n"
    "    ands\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E76C\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E7AC\n"
    ".Ljp_0803E768: .word 0x000021CA\n"
    ".Ljp_0803E76C:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    cmp\tr0, #2\n"
    "    bne .Ljp_0803E78A\n"
    "    cmp\tr1, #3\n"
    "    bne .Ljp_0803E78A\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803E7AC\n"
    ".Ljp_0803E78A:\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E798\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803E7AC\n"
    ".Ljp_0803E798:\n"
    "    cmp\tr4, #1\n"
    "    beq .Ljp_0803E7A6\n"
    "    cmp\tr4, #3\n"
    "    beq .Ljp_0803E7A6\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E7AA\n"
    ".Ljp_0803E7A6:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E7AC\n"
    ".Ljp_0803E7AA:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803E7AC:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" NpcScheduleStorage_080F6DE8 const gUnk_080F6DE8 = {
    {
        SelectCarterSchedule,
        10,
        gUnk_080F6DE8.table_choices,
    },
    {
        nullptr,
        &gUnk_080F6DE8.table_storage[0],
        &gUnk_080F6DE8.table_storage[1],
        &gUnk_080F6DE8.table_storage[2],
        &gUnk_080F6DE8.table_storage[3],
        &gUnk_080F6DE8.table_storage[4],
        &gUnk_080F6DE8.table_storage[5],
        &gUnk_080F6DE8.table_storage[6],
        &gUnk_080F6DE8.table_storage[7],
        &gUnk_080F6DE8.table_storage[8],
    },
    {
        { 5, &gUnk_080F6DE8.entry_storage[0] },
        { 7, &gUnk_080F6DE8.entry_storage[5] },
        { 1, &gUnk_080F6DE8.entry_storage[12] },
        { 1, &gUnk_080F6DE8.entry_storage[13] },
        { 1, &gUnk_080F6DE8.entry_storage[14] },
        { 1, &gUnk_080F6DE8.entry_storage[15] },
        { 1, &gUnk_080F6DE8.entry_storage[16] },
        { 1, &gUnk_080F6DE8.entry_storage[17] },
        { 5, &gUnk_080F6DE8.entry_storage[18] },
    },
    {
        { 0x00000000, &gUnk_080F6DE8.payload_storage[0] },
        { 0x000000B4, &gUnk_080F6DE8.payload_storage[1] },
        { 0x000000B9, &gUnk_080F6DE8.payload_storage[2] },
        { 0x000001A4, &gUnk_080F6DE8.payload_storage[3] },
        { 0x00000258, &gUnk_080F6DE8.payload_storage[2] },
        { 0x00000000, &gUnk_080F6DE8.payload_storage[0] },
        { 0x000000B4, &gUnk_080F6DE8.payload_storage[1] },
        { 0x000000B9, &gUnk_080F6DE8.payload_storage[2] },
        { 0x000001A4, &gUnk_080F6DE8.payload_storage[4] },
        { 0x000001A7, &gUnk_080F6DE8.payload_storage[5] },
        { 0x00000258, &gUnk_080F6DE8.payload_storage[6] },
        { 0x0000025B, &gUnk_080F6DE8.payload_storage[2] },
        { 0x00000000, &gUnk_080F6DE8.payload_storage[2] },
        { 0x00000000, &gUnk_080F6DE8.payload_storage[2] },
        { 0x00000000, &gUnk_080F6DE8.payload_storage[2] },
        { 0x00000000, &gUnk_080F6DE8.payload_storage[2] },
        { 0x00000000, &gUnk_080F6DE8.payload_storage[2] },
        { 0x00000000, &gUnk_080F6DE8.payload_storage[2] },
        { 0x00000000, &gUnk_080F6DE8.payload_storage[2] },
        { 0x000002D0, &gUnk_080F6DE8.payload_storage[7] },
        { 0x000002D1, &gUnk_080F6DE8.payload_storage[8] },
        { 0x0000041A, &gUnk_080F6DE8.payload_storage[9] },
        { 0x0000041B, &gUnk_080F6DE8.payload_storage[2] },
    },
    {
        { &gUnk_080F6DE8.detail_storage[0], 2, 1160, 152, 5, 0, true },
        { &gUnk_080F6DE8.detail_storage[2], 3, 1160, 152, 5, 0, false },
        { nullptr, 0, 184, 67, 12, 0, false },
        { nullptr, 0, 0, 0, 564, 1, false },
        { &gUnk_080F6DE8.detail_storage[5], 2, 1232, 156, 5, 0, false },
        { nullptr, 0, 1224, 208, 5, 2, false },
        { &gUnk_080F6DE8.detail_storage[7], 2, 1224, 208, 5, 0, false },
        { &gUnk_080F6DE8.detail_storage[9], 1, 1232, 156, 5, 0, false },
        { nullptr, 0, 1232, 181, 5, 0, false },
        { &gUnk_080F6DE8.detail_storage[10], 1, 1232, 181, 5, 0, false },
    },
    {
        { 0x0440, 0x0002, 0x0078, 0x0001 },
        { 0x0488, 0x0002, 0x0078, 0x0001 },
        { 0x0001, 0x00A0, 0x0001, 0x0000 },
        { 0x0004, 0x04D0, 0x0000, 0x0000 },
        { 0x0005, 0x009C, 0x0001, 0x0000 },
        { 0x0002, 0x00D0, 0x0001, 0x0000 },
        { 0x0003, 0x04C8, 0x0000, 0x0000 },
        { 0x0001, 0x04D0, 0x0000, 0x0000 },
        { 0x0003, 0x009C, 0x0001, 0x0000 },
        { 0x0001, 0x00B5, 0x0001, 0x0000 },
        { 0x0001, 0x009C, 0x0001, 0x0000 },
    },
};
