#include "npc_schedule_kai.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectKaiSchedule\n"
    "SelectKaiSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E7EC\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_0803E806\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803E806\n"
    "    movs\tr0, #1\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E7F0\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E808\n"
    ".Ljp_0803E7EC: .word 0x000021CA\n"
    ".Ljp_0803E7F0:\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_0803E802\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E7FE\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E808\n"
    ".Ljp_0803E7FE:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E808\n"
    ".Ljp_0803E802:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E808\n"
    ".Ljp_0803E806:\n"
    "    movs\tr0, #0\n"
    ".Ljp_0803E808:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" NpcScheduleStorage_080F6FF8 const gUnk_080F6FF8 = {
    {
        SelectKaiSchedule,
        5,
        gUnk_080F6FF8.table_choices,
    },
    {
        nullptr,
        &gUnk_080F6FF8.table_storage[0],
        &gUnk_080F6FF8.table_storage[1],
        &gUnk_080F6FF8.table_storage[2],
        &gUnk_080F6FF8.table_storage[3],
    },
    {
        { 13, &gUnk_080F6FF8.entry_storage[0] },
        { 7, &gUnk_080F6FF8.entry_storage[13] },
        { 1, &gUnk_080F6FF8.entry_storage[20] },
        { 1, &gUnk_080F6FF8.entry_storage[21] },
    },
    {
        { 0x00000000, &gUnk_080F6FF8.payload_storage[0] },
        { 0x00000079, &gUnk_080F6FF8.payload_storage[1] },
        { 0x0000009C, &gUnk_080F6FF8.payload_storage[2] },
        { 0x000000B0, &gUnk_080F6FF8.payload_storage[3] },
        { 0x0000012C, &gUnk_080F6FF8.payload_storage[4] },
        { 0x00000131, &gUnk_080F6FF8.payload_storage[5] },
        { 0x000001A4, &gUnk_080F6FF8.payload_storage[6] },
        { 0x000001A9, &gUnk_080F6FF8.payload_storage[3] },
        { 0x00000294, &gUnk_080F6FF8.payload_storage[4] },
        { 0x00000299, &gUnk_080F6FF8.payload_storage[5] },
        { 0x0000030C, &gUnk_080F6FF8.payload_storage[7] },
        { 0x00000320, &gUnk_080F6FF8.payload_storage[8] },
        { 0x00000342, &gUnk_080F6FF8.payload_storage[0] },
        { 0x00000000, &gUnk_080F6FF8.payload_storage[0] },
        { 0x000001A4, &gUnk_080F6FF8.payload_storage[1] },
        { 0x000001C7, &gUnk_080F6FF8.payload_storage[9] },
        { 0x000001D9, &gUnk_080F6FF8.payload_storage[10] },
        { 0x00000258, &gUnk_080F6FF8.payload_storage[11] },
        { 0x0000026B, &gUnk_080F6FF8.payload_storage[8] },
        { 0x0000028D, &gUnk_080F6FF8.payload_storage[0] },
        { 0x00000000, &gUnk_080F6FF8.payload_storage[0] },
        { 0x00000000, &gUnk_080F6FF8.payload_storage[0] },
    },
    {
        { nullptr, 0, 208, 80, 23, 0, false },
        { &gUnk_080F6FF8.detail_storage[0], 3, 632, 488, 5, 0, false },
        { &gUnk_080F6FF8.detail_storage[3], 6, 0, 280, 1, 0, false },
        { nullptr, 0, 160, 116, 1, 0, false },
        { &gUnk_080F6FF8.detail_storage[9], 3, 160, 116, 1, 0, false },
        { nullptr, 0, 110, 91, 36, 0, false },
        { &gUnk_080F6FF8.detail_storage[12], 3, 84, 116, 1, 0, false },
        { &gUnk_080F6FF8.detail_storage[15], 6, 84, 116, 1, 0, false },
        { &gUnk_080F6FF8.detail_storage[21], 3, 1260, 704, 5, 0, false },
        { &gUnk_080F6FF8.detail_storage[24], 5, 0, 280, 1, 0, false },
        { nullptr, 0, 256, 264, 1, 3, false },
        { &gUnk_080F6FF8.detail_storage[29], 5, 256, 264, 1, 0, false },
    },
    {
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x001B, 0x04EC, 0x0000, 0x0000 },
        { 0x0023, 0x02E0, 0x0001, 0x0000 },
        { 0x0003, 0x0040, 0x0000, 0x0000 },
        { 0x0006, 0x0168, 0x0001, 0x0000 },
        { 0x0008, 0x0068, 0x0000, 0x0000 },
        { 0x0011, 0x0088, 0x0001, 0x0000 },
        { 0x0013, 0x00A0, 0x0000, 0x0000 },
        { 0x0014, 0x0074, 0x0001, 0x0000 },
        { 0x0001, 0x0088, 0x0001, 0x0000 },
        { 0x0004, 0x0050, 0x0000, 0x0000 },
        { 0x0005, 0x0074, 0x0001, 0x0000 },
        { 0x0001, 0x0088, 0x0001, 0x0000 },
        { 0x0004, 0x00A0, 0x0000, 0x0000 },
        { 0x0005, 0x0074, 0x0001, 0x0000 },
        { 0x0001, 0x0088, 0x0001, 0x0000 },
        { 0x0002, 0x0068, 0x0000, 0x0000 },
        { 0x000B, 0x0168, 0x0001, 0x0000 },
        { 0x000D, 0x0040, 0x0000, 0x0000 },
        { 0x0010, 0x0118, 0x0001, 0x0000 },
        { 0x0014, 0xFFF0, 0x0000, 0x0000 },
        { 0x0007, 0x0218, 0x0001, 0x0000 },
        { 0x0020, 0x0278, 0x0000, 0x0000 },
        { 0x0022, 0x01E8, 0x0001, 0x0000 },
        { 0x0003, 0x0040, 0x0000, 0x0000 },
        { 0x0006, 0x0168, 0x0001, 0x0000 },
        { 0x0008, 0x0068, 0x0000, 0x0000 },
        { 0x000C, 0x0108, 0x0001, 0x0000 },
        { 0x0012, 0x0100, 0x0000, 0x0000 },
        { 0x0006, 0x0068, 0x0000, 0x0000 },
        { 0x000A, 0x0168, 0x0001, 0x0000 },
        { 0x000C, 0x0040, 0x0000, 0x0000 },
        { 0x000F, 0x0118, 0x0001, 0x0000 },
        { 0x0013, 0xFFF0, 0x0000, 0x0000 },
    },
};
