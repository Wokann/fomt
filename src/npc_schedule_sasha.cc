#include "npc_schedule_sasha.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectSashaSchedule\n"
    "SelectSashaSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803DE30\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #29\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803DE34\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803DE68\n"
    "    .align 2, 0\n"
    ".Ljp_0803DE30: .word 0x000021CA\n"
    ".Ljp_0803DE34:\n"
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
    "    beq .Ljp_0803DE54\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803DE68\n"
    ".Ljp_0803DE54:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DE66\n"
    "    cmp\tr4, #2\n"
    "    bne .Ljp_0803DE62\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803DE68\n"
    ".Ljp_0803DE62:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803DE68\n"
    ".Ljp_0803DE66:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803DE68:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

// The next ROM object has five choices, of which the first is null. Keep its
// tables, entry records, payloads, and detail records contiguous and ordered.
extern "C" NpcScheduleFiveChoiceStorage const gUnk_080F3FD8 = {
        {
            SelectSashaSchedule,
            5,
            gUnk_080F3FD8.table_choices,
        },
        {
            nullptr,
            &gUnk_080F3FD8.table_storage[0],
            &gUnk_080F3FD8.table_storage[1],
            &gUnk_080F3FD8.table_storage[2],
            &gUnk_080F3FD8.table_storage[3],
        },
        {
            { 7, &gUnk_080F3FD8.entry_storage[0] },  // Choice 01.
            { 3, &gUnk_080F3FD8.entry_storage[7] },  // Choice 02.
            { 11, &gUnk_080F3FD8.entry_storage[10] }, // Choice 03.
            { 1, &gUnk_080F3FD8.entry_storage[21] }, // Choice 04.
        },
        {
            // Table 01.
            { 0x0000, &gUnk_080F3FD8.payload_storage[0] },
            { 0x01A4, &gUnk_080F3FD8.payload_storage[1] },
            { 0x01D2, &gUnk_080F3FD8.payload_storage[2] },
            { 0x01D9, &gUnk_080F3FD8.payload_storage[3] },
            { 0x0258, &gUnk_080F3FD8.payload_storage[4] },
            { 0x025F, &gUnk_080F3FD8.payload_storage[5] },
            { 0x028C, &gUnk_080F3FD8.payload_storage[0] },
            // Table 02.
            { 0x0000, &gUnk_080F3FD8.payload_storage[0] },
            { 0x01A4, &gUnk_080F3FD8.payload_storage[12] },
            { 0x0258, &gUnk_080F3FD8.payload_storage[0] },
            // Table 03.
            { 0x0000, &gUnk_080F3FD8.payload_storage[0] },
            { 0x003C, &gUnk_080F3FD8.payload_storage[1] },
            { 0x006A, &gUnk_080F3FD8.payload_storage[6] },
            { 0x0083, &gUnk_080F3FD8.payload_storage[7] },
            { 0x00F3, &gUnk_080F3FD8.payload_storage[8] },
            { 0x011E, &gUnk_080F3FD8.payload_storage[9] },
            { 0x01A7, &gUnk_080F3FD8.payload_storage[10] },
            { 0x01C5, &gUnk_080F3FD8.payload_storage[11] },
            { 0x01E7, &gUnk_080F3FD8.payload_storage[13] },
            { 0x0258, &gUnk_080F3FD8.payload_storage[14] },
            { 0x0268, &gUnk_080F3FD8.payload_storage[0] },
            // Table 04.
            { 0x0000, &gUnk_080F3FD8.payload_storage[0] },
        },
        {
            { &gUnk_080F3FD8.detail_storage[0], 2, 136, 80, 16, 0, true },
            { &gUnk_080F3FD8.detail_storage[2], 5, 688, 160, 5, 0, false },
            { &gUnk_080F3FD8.detail_storage[7], 2, 220, 0, 6, 0, false },
            { nullptr, 0, 328, 80, 6, 0, false },
            { &gUnk_080F3FD8.detail_storage[9], 2, 328, 80, 6, 0, false },
            { &gUnk_080F3FD8.detail_storage[11], 5, 1260, 704, 5, 0, false },
            { &gUnk_080F3FD8.detail_storage[16], 7, 1272, 0, 7, 0, false },
            { nullptr, 0, 120, 120, 41, 0, false },
            { &gUnk_080F3FD8.detail_storage[23], 7, 992, 234, 7, 0, false },
            { nullptr, 0, 192, 138, 10, 0, false },
            { &gUnk_080F3FD8.detail_storage[30], 5, 572, 227, 7, 0, false },
            { &gUnk_080F3FD8.detail_storage[35], 5, 104, 704, 5, 0, false },
            { &gUnk_080F3FD8.detail_storage[40], 2, 256, 80, 15, 0, true },
            { nullptr, 0, 112, 136, 14, 1, false },
            { &gUnk_080F3FD8.detail_storage[42], 3, 400, 160, 5, 0, false },
        },
        {
            { 0x0110, 0x0002, 0x0078, 0x0003 },
            { 0x0088, 0x0002, 0x0078, 0x0002 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0018, 0x04E0, 0x0000, 0x0000 },
            { 0x0019, 0x00F0, 0x0001, 0x0000 },
            { 0x001A, 0x04EC, 0x0000, 0x0000 },
            { 0x002E, 0x02E0, 0x0001, 0x0000 },
            { 0x0003, 0x0050, 0x0001, 0x0000 },
            { 0x0007, 0x0148, 0x0000, 0x0000 },
            { 0x0004, 0x00DC, 0x0000, 0x0000 },
            { 0x0007, 0x0000, 0x0001, 0x0000 },
            { 0x0013, 0x00F0, 0x0001, 0x0000 },
            { 0x0014, 0x04E0, 0x0000, 0x0000 },
            { 0x0015, 0x00D8, 0x0001, 0x0000 },
            { 0x002B, 0x02B0, 0x0000, 0x0000 },
            { 0x002D, 0x00A0, 0x0001, 0x0000 },
            { 0x0005, 0x0080, 0x0001, 0x0000 },
            { 0x0006, 0x04E0, 0x0000, 0x0000 },
            { 0x0007, 0x0098, 0x0001, 0x0000 },
            { 0x000F, 0x0424, 0x0000, 0x0000 },
            { 0x0014, 0x0118, 0x0001, 0x0000 },
            { 0x0017, 0x03E0, 0x0000, 0x0000 },
            { 0x0019, 0x00E8, 0x0001, 0x0000 },
            { 0x0002, 0x0118, 0x0001, 0x0000 },
            { 0x0005, 0x0424, 0x0000, 0x0000 },
            { 0x000A, 0x0098, 0x0001, 0x0000 },
            { 0x0022, 0x01D8, 0x0000, 0x0000 },
            { 0x0026, 0x00F8, 0x0001, 0x0000 },
            { 0x002A, 0x023C, 0x0000, 0x0000 },
            { 0x002B, 0x00E3, 0x0001, 0x0000 },
            { 0x0001, 0x00F8, 0x0001, 0x0000 },
            { 0x0005, 0x01D8, 0x0000, 0x0000 },
            { 0x0009, 0x0098, 0x0001, 0x0000 },
            { 0x0018, 0x0068, 0x0000, 0x0000 },
            { 0x001E, 0x0000, 0x0001, 0x0000 },
            { 0x0013, 0x00F0, 0x0001, 0x0000 },
            { 0x0015, 0x0090, 0x0000, 0x0000 },
            { 0x0016, 0x00D8, 0x0001, 0x0000 },
            { 0x0020, 0x0190, 0x0000, 0x0000 },
            { 0x0022, 0x00A0, 0x0001, 0x0000 },
            { 0x00C8, 0x0002, 0x0078, 0x0002 },
            { 0x0100, 0x0002, 0x0078, 0x0003 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x000E, 0x02B0, 0x0000, 0x0000 },
            { 0x0010, 0x00A0, 0x0001, 0x0000 },
        },
    };
