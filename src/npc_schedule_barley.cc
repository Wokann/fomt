#include "npc_schedule_barley.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectBarleySchedule\n"
    "SelectBarleySchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
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
    "    beq .Ljp_0803EAEA\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803EAFE\n"
    ".Ljp_0803EAEA:\n"
    "    cmp\tr4, #1\n"
    "    bne .Ljp_0803EAFC\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803EAF8\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803EAFE\n"
    ".Ljp_0803EAF8:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803EAFE\n"
    ".Ljp_0803EAFC:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803EAFE:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

extern "C" NpcScheduleStorage_080F8678 const gUnk_080F8678 = {
    {
        SelectBarleySchedule,
        5,
        gUnk_080F8678.table_choices,
    },
    {
        nullptr,
        &gUnk_080F8678.table_storage[0],
        &gUnk_080F8678.table_storage[1],
        &gUnk_080F8678.table_storage[2],
        &gUnk_080F8678.table_storage[3],
    },
    {
        { 4, &gUnk_080F8678.entry_storage[0] },
        { 11, &gUnk_080F8678.entry_storage[4] },
        { 8, &gUnk_080F8678.entry_storage[15] },
        { 1, &gUnk_080F8678.entry_storage[23] },
    },
    {
        { 0x00000000, &gUnk_080F8678.payload_storage[2] },
        { 0x00000078, &gUnk_080F8678.payload_storage[12] },
        { 0x00000080, &gUnk_080F8678.payload_storage[0] },
        { 0x0000030C, &gUnk_080F8678.payload_storage[1] },
        { 0x00000000, &gUnk_080F8678.payload_storage[2] },
        { 0x00000078, &gUnk_080F8678.payload_storage[4] },
        { 0x0000008E, &gUnk_080F8678.payload_storage[3] },
        { 0x000000C3, &gUnk_080F8678.payload_storage[5] },
        { 0x000001A4, &gUnk_080F8678.payload_storage[6] },
        { 0x000001DA, &gUnk_080F8678.payload_storage[7] },
        { 0x000001EA, &gUnk_080F8678.payload_storage[8] },
        { 0x00000258, &gUnk_080F8678.payload_storage[9] },
        { 0x00000269, &gUnk_080F8678.payload_storage[10] },
        { 0x0000028B, &gUnk_080F8678.payload_storage[0] },
        { 0x0000030C, &gUnk_080F8678.payload_storage[1] },
        { 0x00000000, &gUnk_080F8678.payload_storage[2] },
        { 0x00000078, &gUnk_080F8678.payload_storage[4] },
        { 0x0000008E, &gUnk_080F8678.payload_storage[3] },
        { 0x000000C3, &gUnk_080F8678.payload_storage[5] },
        { 0x000001A4, &gUnk_080F8678.payload_storage[6] },
        { 0x000001DA, &gUnk_080F8678.payload_storage[11] },
        { 0x000001F3, &gUnk_080F8678.payload_storage[0] },
        { 0x00000258, &gUnk_080F8678.payload_storage[1] },
        { 0x00000000, &gUnk_080F8678.payload_storage[0] },
    },
    {
        { nullptr, 0, 81, 160, 41, 3, false },
        { &gUnk_080F8678.detail_storage[0], 2, 64, 80, 42, 0, true },
        { &gUnk_080F8678.detail_storage[2], 2, 1112, 272, 7, 0, true },
        { &gUnk_080F8678.detail_storage[4], 5, 1260, 704, 5, 0, false },
        { &gUnk_080F8678.detail_storage[9], 6, 1112, 272, 7, 0, false },
        { nullptr, 0, 120, 144, 30, 1, false },
        { &gUnk_080F8678.detail_storage[15], 5, 480, 160, 5, 0, false },
        { &gUnk_080F8678.detail_storage[20], 9, 1200, 528, 0, 0, false },
        { &gUnk_080F8678.detail_storage[29], 2, 944, 536, 0, 0, true },
        { &gUnk_080F8678.detail_storage[31], 9, 944, 536, 0, 0, false },
        { &gUnk_080F8678.detail_storage[40], 5, 812, 512, 7, 0, false },
        { &gUnk_080F8678.detail_storage[45], 7, 1272, 0, 7, 0, false },
        { &gUnk_080F8678.detail_storage[52], 4, 1112, 272, 7, 0, false },
    },
    {
        { 0x00A8, 0x0002, 0x0078, 0x0007 },
        { 0x0050, 0x0002, 0x0078, 0x0007 },
        { 0x0498, 0x0002, 0x0078, 0x0003 },
        { 0x0458, 0x0002, 0x0078, 0x0002 },
        { 0x0007, 0x0218, 0x0001, 0x0000 },
        { 0x0019, 0x0328, 0x0000, 0x0000 },
        { 0x0026, 0x00D8, 0x0001, 0x0000 },
        { 0x0033, 0x01E0, 0x0000, 0x0000 },
        { 0x0035, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x0424, 0x0000, 0x0000 },
        { 0x0007, 0x0098, 0x0001, 0x0000 },
        { 0x000F, 0x04E0, 0x0000, 0x0000 },
        { 0x0010, 0x0080, 0x0001, 0x0000 },
        { 0x0011, 0x04F8, 0x0000, 0x0000 },
        { 0x0016, 0x0000, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x000F, 0x0328, 0x0000, 0x0000 },
        { 0x001C, 0x0218, 0x0001, 0x0000 },
        { 0x002E, 0x04EC, 0x0000, 0x0000 },
        { 0x0036, 0x02DE, 0x0001, 0x0000 },
        { 0x0001, 0x0498, 0x0000, 0x0000 },
        { 0x0002, 0x0200, 0x0001, 0x0000 },
        { 0x0003, 0x0488, 0x0000, 0x0000 },
        { 0x0004, 0x01F0, 0x0001, 0x0000 },
        { 0x0005, 0x0478, 0x0000, 0x0000 },
        { 0x0006, 0x01E0, 0x0001, 0x0000 },
        { 0x000C, 0x03E8, 0x0000, 0x0000 },
        { 0x000E, 0x0218, 0x0001, 0x0000 },
        { 0x0010, 0x03B0, 0x0000, 0x0000 },
        { 0x0370, 0x0002, 0x0078, 0x0002 },
        { 0x03B0, 0x0002, 0x0078, 0x0003 },
        { 0x0002, 0x03E8, 0x0000, 0x0000 },
        { 0x0004, 0x01E0, 0x0001, 0x0000 },
        { 0x000A, 0x0478, 0x0000, 0x0000 },
        { 0x000B, 0x01F0, 0x0001, 0x0000 },
        { 0x000C, 0x0488, 0x0000, 0x0000 },
        { 0x000D, 0x0200, 0x0001, 0x0000 },
        { 0x000E, 0x0498, 0x0000, 0x0000 },
        { 0x000F, 0x0210, 0x0001, 0x0000 },
        { 0x0011, 0x04C0, 0x0000, 0x0000 },
        { 0x000E, 0x0098, 0x0001, 0x0000 },
        { 0x0018, 0x0424, 0x0000, 0x0000 },
        { 0x001D, 0x0118, 0x0001, 0x0000 },
        { 0x0020, 0x03E0, 0x0000, 0x0000 },
        { 0x0022, 0x00E8, 0x0001, 0x0000 },
        { 0x0005, 0x0080, 0x0001, 0x0000 },
        { 0x0006, 0x04E0, 0x0000, 0x0000 },
        { 0x0007, 0x0098, 0x0001, 0x0000 },
        { 0x000F, 0x0424, 0x0000, 0x0000 },
        { 0x0014, 0x0118, 0x0001, 0x0000 },
        { 0x0017, 0x03E0, 0x0000, 0x0000 },
        { 0x0019, 0x00E8, 0x0001, 0x0000 },
        { 0x0002, 0x0424, 0x0000, 0x0000 },
        { 0x0003, 0x0118, 0x0001, 0x0000 },
        { 0x0006, 0x03E0, 0x0000, 0x0000 },
        { 0x0008, 0x00E8, 0x0001, 0x0000 },
    },
};
