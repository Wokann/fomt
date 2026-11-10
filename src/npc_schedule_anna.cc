#include "npc_schedule_anna.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectAnnaSchedule\n"
    "SelectAnnaSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E2AC\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E2B0\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E2EE\n"
    "    .align 2, 0\n"
    ".Ljp_0803E2AC: .word 0x000021CA\n"
    ".Ljp_0803E2B0:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E2D0\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E2EE\n"
    ".Ljp_0803E2D0:\n"
    "    cmp\tr4, #1\n"
    "    bne .Ljp_0803E2E2\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E2DE\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E2EE\n"
    ".Ljp_0803E2DE:\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E2EE\n"
    ".Ljp_0803E2E2:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E2EC\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E2EE\n"
    ".Ljp_0803E2EC:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E2EE:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

extern "C" NpcScheduleStorage_080F5540 const gUnk_080F5540 = {
    {
        SelectAnnaSchedule,
        6,
        gUnk_080F5540.table_choices,
    },
    {
        nullptr,
        &gUnk_080F5540.table_storage[0],
        &gUnk_080F5540.table_storage[1],
        &gUnk_080F5540.table_storage[2],
        &gUnk_080F5540.table_storage[3],
        &gUnk_080F5540.table_storage[4],
    },
    {
        { 9, &gUnk_080F5540.entry_storage[0] },
        { 3, &gUnk_080F5540.entry_storage[9] },
        { 12, &gUnk_080F5540.entry_storage[12] },
        { 7, &gUnk_080F5540.entry_storage[24] },
        { 1, &gUnk_080F5540.entry_storage[31] },
    },
    {
        { 0x00000000, &gUnk_080F5540.payload_storage[0] },
        { 0x0000003C, &gUnk_080F5540.payload_storage[1] },
        { 0x000001A4, &gUnk_080F5540.payload_storage[2] },
        { 0x000001E5, &gUnk_080F5540.payload_storage[3] },
        { 0x000001EF, &gUnk_080F5540.payload_storage[4] },
        { 0x0000025A, &gUnk_080F5540.payload_storage[5] },
        { 0x00000264, &gUnk_080F5540.payload_storage[6] },
        { 0x000002A4, &gUnk_080F5540.payload_storage[1] },
        { 0x000003C0, &gUnk_080F5540.payload_storage[0] },
        { 0x00000000, &gUnk_080F5540.payload_storage[0] },
        { 0x0000003C, &gUnk_080F5540.payload_storage[1] },
        { 0x000003C0, &gUnk_080F5540.payload_storage[0] },
        { 0x00000000, &gUnk_080F5540.payload_storage[0] },
        { 0x00000042, &gUnk_080F5540.payload_storage[7] },
        { 0x0000005D, &gUnk_080F5540.payload_storage[8] },
        { 0x00000098, &gUnk_080F5540.payload_storage[9] },
        { 0x000000F3, &gUnk_080F5540.payload_storage[10] },
        { 0x0000012E, &gUnk_080F5540.payload_storage[11] },
        { 0x00000148, &gUnk_080F5540.payload_storage[1] },
        { 0x000001AA, &gUnk_080F5540.payload_storage[12] },
        { 0x000001C2, &gUnk_080F5540.payload_storage[13] },
        { 0x00000258, &gUnk_080F5540.payload_storage[14] },
        { 0x00000270, &gUnk_080F5540.payload_storage[1] },
        { 0x000003C0, &gUnk_080F5540.payload_storage[0] },
        { 0x00000000, &gUnk_080F5540.payload_storage[0] },
        { 0x0000003C, &gUnk_080F5540.payload_storage[1] },
        { 0x000001A7, &gUnk_080F5540.payload_storage[12] },
        { 0x000001BF, &gUnk_080F5540.payload_storage[13] },
        { 0x00000258, &gUnk_080F5540.payload_storage[14] },
        { 0x00000270, &gUnk_080F5540.payload_storage[1] },
        { 0x000003C0, &gUnk_080F5540.payload_storage[0] },
        { 0x00000000, &gUnk_080F5540.payload_storage[0] },
    },
    {
        { nullptr, 0, 50, 88, 27, 0, false },
        { nullptr, 0, 24, 88, 26, 0, false },
        { &gUnk_080F5540.detail_storage[0], 5, 200, 160, 5, 0, false },
        { &gUnk_080F5540.detail_storage[5], 2, 220, 0, 6, 0, false },
        { nullptr, 0, 360, 96, 6, 2, false },
        { &gUnk_080F5540.detail_storage[7], 2, 360, 96, 6, 0, false },
        { &gUnk_080F5540.detail_storage[9], 5, 1260, 704, 5, 0, false },
        { &gUnk_080F5540.detail_storage[14], 5, 200, 160, 5, 0, false },
        { &gUnk_080F5540.detail_storage[19], 20, 1200, 752, 0, 0, false },
        { nullptr, 0, 296, 200, 0, 3, false },
        { &gUnk_080F5540.detail_storage[39], 20, 296, 200, 0, 0, false },
        { &gUnk_080F5540.detail_storage[59], 5, 104, 704, 5, 0, false },
        { &gUnk_080F5540.detail_storage[64], 3, 200, 160, 5, 0, false },
        { nullptr, 0, 152, 138, 15, 0, false },
        { &gUnk_080F5540.detail_storage[67], 3, 688, 160, 5, 0, false },
    },
    {
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x001A, 0x0328, 0x0000, 0x0000 },
        { 0x0027, 0x0218, 0x0001, 0x0000 },
        { 0x0039, 0x04EC, 0x0000, 0x0000 },
        { 0x0041, 0x02E0, 0x0001, 0x0000 },
        { 0x0004, 0x0060, 0x0001, 0x0000 },
        { 0x000A, 0x0168, 0x0000, 0x0000 },
        { 0x0006, 0x00DC, 0x0000, 0x0000 },
        { 0x000A, 0x0000, 0x0001, 0x0000 },
        { 0x0007, 0x0218, 0x0001, 0x0000 },
        { 0x0019, 0x0328, 0x0000, 0x0000 },
        { 0x0026, 0x00D8, 0x0001, 0x0000 },
        { 0x003E, 0x00C8, 0x0000, 0x0000 },
        { 0x0040, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0004, 0x0090, 0x0000, 0x0000 },
        { 0x0005, 0x00F0, 0x0001, 0x0000 },
        { 0x0007, 0x0068, 0x0000, 0x0000 },
        { 0x001B, 0x02DE, 0x0001, 0x0000 },
        { 0x000C, 0x0390, 0x0000, 0x0000 },
        { 0x000D, 0x02D8, 0x0001, 0x0000 },
        { 0x000F, 0x0358, 0x0000, 0x0000 },
        { 0x0010, 0x02C0, 0x0001, 0x0000 },
        { 0x0011, 0x0340, 0x0000, 0x0000 },
        { 0x0012, 0x02A8, 0x0001, 0x0000 },
        { 0x0013, 0x0328, 0x0000, 0x0000 },
        { 0x0014, 0x0290, 0x0001, 0x0000 },
        { 0x0015, 0x0308, 0x0000, 0x0000 },
        { 0x0016, 0x0270, 0x0001, 0x0000 },
        { 0x0017, 0x02F0, 0x0000, 0x0000 },
        { 0x0018, 0x0250, 0x0001, 0x0000 },
        { 0x0019, 0x02D0, 0x0000, 0x0000 },
        { 0x001A, 0x0238, 0x0001, 0x0000 },
        { 0x001B, 0x02B4, 0x0000, 0x0000 },
        { 0x0025, 0x0148, 0x0001, 0x0000 },
        { 0x0026, 0x0290, 0x0000, 0x0000 },
        { 0x002C, 0x00A8, 0x0001, 0x0000 },
        { 0x003A, 0x0128, 0x0000, 0x0000 },
        { 0x003B, 0x00C8, 0x0001, 0x0000 },
        { 0x0001, 0x00A8, 0x0001, 0x0000 },
        { 0x000F, 0x0290, 0x0000, 0x0000 },
        { 0x0015, 0x0148, 0x0001, 0x0000 },
        { 0x0016, 0x02B4, 0x0000, 0x0000 },
        { 0x0020, 0x0238, 0x0001, 0x0000 },
        { 0x0021, 0x02D0, 0x0000, 0x0000 },
        { 0x0022, 0x0250, 0x0001, 0x0000 },
        { 0x0023, 0x02F0, 0x0000, 0x0000 },
        { 0x0024, 0x0270, 0x0001, 0x0000 },
        { 0x0025, 0x0308, 0x0000, 0x0000 },
        { 0x0026, 0x0290, 0x0001, 0x0000 },
        { 0x0027, 0x0328, 0x0000, 0x0000 },
        { 0x0028, 0x02A8, 0x0001, 0x0000 },
        { 0x0029, 0x0340, 0x0000, 0x0000 },
        { 0x002A, 0x02C0, 0x0001, 0x0000 },
        { 0x002B, 0x0358, 0x0000, 0x0000 },
        { 0x002C, 0x02D8, 0x0001, 0x0000 },
        { 0x002E, 0x0390, 0x0000, 0x0000 },
        { 0x002F, 0x02F0, 0x0001, 0x0000 },
        { 0x003B, 0x04C0, 0x0000, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0015, 0x0090, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x0018, 0x00C8, 0x0000, 0x0000 },
        { 0x001A, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0016, 0x02B0, 0x0000, 0x0000 },
        { 0x0018, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0016, 0x00C8, 0x0000, 0x0000 },
        { 0x0018, 0x00A0, 0x0001, 0x0000 },
    },
};
