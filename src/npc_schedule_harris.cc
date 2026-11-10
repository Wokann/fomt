#include "npc_schedule_harris.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectHarrisSchedule\n"
    "SelectHarrisSchedule:\n"
    "    push\t{r4, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr1, r0, #0\n"
    "    ldr r2, .Ljp_0803E724\n"
    "    adds\tr0, r1, r2\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E728\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E746\n"
    "    .align 2, 0\n"
    ".Ljp_0803E724: .word 0x000021CA\n"
    ".Ljp_0803E728:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E744\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E746\n"
    ".Ljp_0803E744:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803E746:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

extern "C" NpcScheduleStorage_080F6B4C const gUnk_080F6B4C = {
    {
        SelectHarrisSchedule,
        3,
        gUnk_080F6B4C.table_choices,
    },
    {
        nullptr,
        &gUnk_080F6B4C.table_storage[0],
        &gUnk_080F6B4C.table_storage[1],
    },
    {
        { 16, &gUnk_080F6B4C.entry_storage[0] },
        { 1, &gUnk_080F6B4C.entry_storage[16] },
    },
    {
        { 0x00000000, &gUnk_080F6B4C.payload_storage[0] },
        { 0x0000003C, &gUnk_080F6B4C.payload_storage[1] },
        { 0x00000078, &gUnk_080F6B4C.payload_storage[2] },
        { 0x00000091, &gUnk_080F6B4C.payload_storage[4] },
        { 0x000000F0, &gUnk_080F6B4C.payload_storage[3] },
        { 0x00000113, &gUnk_080F6B4C.payload_storage[5] },
        { 0x0000012A, &gUnk_080F6B4C.payload_storage[6] },
        { 0x000001A7, &gUnk_080F6B4C.payload_storage[7] },
        { 0x000001BE, &gUnk_080F6B4C.payload_storage[8] },
        { 0x000001E0, &gUnk_080F6B4C.payload_storage[9] },
        { 0x00000258, &gUnk_080F6B4C.payload_storage[10] },
        { 0x0000027D, &gUnk_080F6B4C.payload_storage[0] },
        { 0x0000030C, &gUnk_080F6B4C.payload_storage[11] },
        { 0x00000311, &gUnk_080F6B4C.payload_storage[12] },
        { 0x000003C0, &gUnk_080F6B4C.payload_storage[13] },
        { 0x000003C5, &gUnk_080F6B4C.payload_storage[0] },
        { 0x00000000, &gUnk_080F6B4C.payload_storage[0] },
    },
    {
        { &gUnk_080F6B4C.detail_storage[0], 2, 152, 104, 30, 0, true },
        { &gUnk_080F6B4C.detail_storage[2], 5, 480, 160, 5, 0, false },
        { &gUnk_080F6B4C.detail_storage[7], 7, 1272, 0, 7, 0, false },
        { &gUnk_080F6B4C.detail_storage[14], 5, 992, 232, 7, 0, false },
        { nullptr, 0, 160, 152, 41, 2, false },
        { &gUnk_080F6B4C.detail_storage[19], 3, 832, 0, 3, 0, false },
        { nullptr, 0, 80, 160, 40, 3, false },
        { &gUnk_080F6B4C.detail_storage[22], 3, 612, 244, 3, 0, false },
        { &gUnk_080F6B4C.detail_storage[25], 3, 1260, 704, 5, 0, false },
        { nullptr, 0, 16, 224, 21, 3, false },
        { &gUnk_080F6B4C.detail_storage[28], 5, 632, 488, 5, 0, false },
        { &gUnk_080F6B4C.detail_storage[33], 3, 480, 160, 5, 0, false },
        { nullptr, 0, 440, 200, 5, 0, false },
        { &gUnk_080F6B4C.detail_storage[36], 3, 440, 200, 5, 0, false },
    },
    {
        { 0x00D8, 0x0002, 0x0078, 0x0003 },
        { 0x0098, 0x0002, 0x0078, 0x0002 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0026, 0x04E0, 0x0000, 0x0000 },
        { 0x0027, 0x00F0, 0x0001, 0x0000 },
        { 0x0028, 0x04EC, 0x0000, 0x0000 },
        { 0x003C, 0x02E0, 0x0001, 0x0000 },
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
        { 0x0014, 0x032C, 0x0000, 0x0000 },
        { 0x0023, 0x0220, 0x0001, 0x0000 },
        { 0x000C, 0x0128, 0x0001, 0x0000 },
        { 0x0015, 0x0266, 0x0000, 0x0000 },
        { 0x0017, 0x00F4, 0x0001, 0x0000 },
        { 0x0002, 0x0128, 0x0001, 0x0000 },
        { 0x000B, 0x0340, 0x0000, 0x0000 },
        { 0x0017, 0x0000, 0x0001, 0x0000 },
        { 0x0007, 0x0218, 0x0001, 0x0000 },
        { 0x0020, 0x0278, 0x0000, 0x0000 },
        { 0x0022, 0x01E8, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x0009, 0x0328, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x0023, 0x01E0, 0x0000, 0x0000 },
        { 0x0025, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0004, 0x01B8, 0x0000, 0x0000 },
        { 0x0005, 0x00C8, 0x0001, 0x0000 },
        { 0x0001, 0x00D8, 0x0001, 0x0000 },
        { 0x0003, 0x01E0, 0x0000, 0x0000 },
        { 0x0005, 0x00A0, 0x0001, 0x0000 },
    },
};
