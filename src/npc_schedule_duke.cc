#include "npc_schedule_duke.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectDukeSchedule\n"
    "SelectDukeSchedule:\n"
    "    push\t{r4, r5, r6, lr}\n"
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
    "    adds\tr6, r4, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E60C\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E60C:\n"
    "    ldr r1, .Ljp_0803E61C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E620\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E61C: .word 0x000021CA\n"
    ".Ljp_0803E620:\n"
    "    ldr r1, .Ljp_0803E63C\n"
    "    adds\tr0, r5, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    movs\tr1, #194\t@ 0xc2\n"
    "    lsls\tr1, r1, #11\n"
    "    ands\tr0, r1\n"
    "    movs\tr1, #130\t@ 0x82\n"
    "    lsls\tr1, r1, #11\n"
    "    cmp\tr0, r1\n"
    "    bne .Ljp_0803E644\n"
    "    cmp\tr4, #6\n"
    "    bne .Ljp_0803E640\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E63C: .word 0x00002174\n"
    ".Ljp_0803E640:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E644:\n"
    "    cmp\tr6, #6\n"
    "    beq .Ljp_0803E64C\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803E64E\n"
    ".Ljp_0803E64C:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803E64E:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

extern "C" NpcScheduleStorage_080F6370 const gUnk_080F6370 = {
    {
        SelectDukeSchedule,
        6,
        gUnk_080F6370.table_choices,
    },
    {
        nullptr,
        &gUnk_080F6370.table_storage[0],
        &gUnk_080F6370.table_storage[1],
        &gUnk_080F6370.table_storage[2],
        &gUnk_080F6370.table_storage[3],
        &gUnk_080F6370.table_storage[4],
    },
    {
        { 12, &gUnk_080F6370.entry_storage[0] },
        { 7, &gUnk_080F6370.entry_storage[12] },
        { 12, &gUnk_080F6370.entry_storage[19] },
        { 9, &gUnk_080F6370.entry_storage[31] },
        { 1, &gUnk_080F6370.entry_storage[40] },
    },
    {
        { 0x00000000, &gUnk_080F6370.payload_storage[1] },
        { 0x0000003C, &gUnk_080F6370.payload_storage[0] },
        { 0x000000F0, &gUnk_080F6370.payload_storage[5] },
        { 0x000000F6, &gUnk_080F6370.payload_storage[2] },
        { 0x000001E0, &gUnk_080F6370.payload_storage[3] },
        { 0x000001E5, &gUnk_080F6370.payload_storage[4] },
        { 0x00000294, &gUnk_080F6370.payload_storage[6] },
        { 0x0000029D, &gUnk_080F6370.payload_storage[0] },
        { 0x0000030C, &gUnk_080F6370.payload_storage[7] },
        { 0x00000320, &gUnk_080F6370.payload_storage[8] },
        { 0x000003C3, &gUnk_080F6370.payload_storage[9] },
        { 0x000003D7, &gUnk_080F6370.payload_storage[1] },
        { 0x00000000, &gUnk_080F6370.payload_storage[1] },
        { 0x0000003C, &gUnk_080F6370.payload_storage[0] },
        { 0x000001A4, &gUnk_080F6370.payload_storage[7] },
        { 0x000001B8, &gUnk_080F6370.payload_storage[8] },
        { 0x0000025B, &gUnk_080F6370.payload_storage[9] },
        { 0x0000026F, &gUnk_080F6370.payload_storage[0] },
        { 0x000003C0, &gUnk_080F6370.payload_storage[1] },
        { 0x00000000, &gUnk_080F6370.payload_storage[1] },
        { 0x0000003C, &gUnk_080F6370.payload_storage[0] },
        { 0x000001A7, &gUnk_080F6370.payload_storage[5] },
        { 0x000001AD, &gUnk_080F6370.payload_storage[2] },
        { 0x0000021C, &gUnk_080F6370.payload_storage[3] },
        { 0x00000221, &gUnk_080F6370.payload_storage[4] },
        { 0x00000294, &gUnk_080F6370.payload_storage[6] },
        { 0x0000029D, &gUnk_080F6370.payload_storage[0] },
        { 0x0000030C, &gUnk_080F6370.payload_storage[7] },
        { 0x00000320, &gUnk_080F6370.payload_storage[8] },
        { 0x000003C3, &gUnk_080F6370.payload_storage[9] },
        { 0x000003D7, &gUnk_080F6370.payload_storage[1] },
        { 0x00000000, &gUnk_080F6370.payload_storage[1] },
        { 0x0000003C, &gUnk_080F6370.payload_storage[0] },
        { 0x000001A4, &gUnk_080F6370.payload_storage[7] },
        { 0x000001B8, &gUnk_080F6370.payload_storage[8] },
        { 0x00000260, &gUnk_080F6370.payload_storage[10] },
        { 0x0000028C, &gUnk_080F6370.payload_storage[11] },
        { 0x00000312, &gUnk_080F6370.payload_storage[12] },
        { 0x0000034E, &gUnk_080F6370.payload_storage[0] },
        { 0x000003DD, &gUnk_080F6370.payload_storage[1] },
        { 0x00000000, &gUnk_080F6370.payload_storage[1] },
    },
    {
        { &gUnk_080F6370.detail_storage[0], 2, 40, 168, 31, 0, true },
        { nullptr, 0, 32, 152, 32, 0, false },
        { &gUnk_080F6370.detail_storage[2], 2, 24, 80, 34, 0, true },
        { &gUnk_080F6370.detail_storage[4], 2, 314, 456, 5, 0, false },
        { nullptr, 0, 408, 476, 5, 1, false },
        { &gUnk_080F6370.detail_storage[6], 5, 232, 484, 5, 0, false },
        { &gUnk_080F6370.detail_storage[11], 4, 408, 476, 5, 0, false },
        { &gUnk_080F6370.detail_storage[15], 3, 232, 476, 5, 0, false },
        { nullptr, 0, 16, 147, 21, 3, false },
        { &gUnk_080F6370.detail_storage[18], 3, 632, 488, 5, 0, false },
        { &gUnk_080F6370.detail_storage[21], 7, 632, 488, 5, 0, false },
        { nullptr, 0, 104, 195, 12, 1, false },
        { &gUnk_080F6370.detail_storage[28], 7, 1232, 160, 5, 0, false },
    },
    {
        { 0x0058, 0x0002, 0x0078, 0x0003 },
        { 0x0028, 0x0002, 0x0078, 0x0002 },
        { 0x0038, 0x0002, 0x00F0, 0x0001 },
        { 0x0018, 0x0002, 0x00F0, 0x0001 },
        { 0x0001, 0x01DC, 0x0001, 0x0000 },
        { 0x0005, 0x0198, 0x0000, 0x0000 },
        { 0x0001, 0x01F0, 0x0001, 0x0000 },
        { 0x0002, 0x0109, 0x0000, 0x0000 },
        { 0x0003, 0x01DC, 0x0001, 0x0000 },
        { 0x0005, 0x013C, 0x0000, 0x0000 },
        { 0x0006, 0x01CC, 0x0001, 0x0000 },
        { 0x0006, 0x0109, 0x0000, 0x0000 },
        { 0x0007, 0x01F0, 0x0001, 0x0000 },
        { 0x0008, 0x00E8, 0x0000, 0x0000 },
        { 0x0009, 0x01E4, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x0012, 0x0278, 0x0000, 0x0000 },
        { 0x0014, 0x01E4, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x0012, 0x00E8, 0x0000, 0x0000 },
        { 0x0014, 0x01DC, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x001B, 0x04EC, 0x0000, 0x0000 },
        { 0x0027, 0x00F0, 0x0001, 0x0000 },
        { 0x0028, 0x04E0, 0x0000, 0x0000 },
        { 0x0029, 0x00D8, 0x0001, 0x0000 },
        { 0x002A, 0x04D0, 0x0000, 0x0000 },
        { 0x002C, 0x009C, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0003, 0x04E0, 0x0000, 0x0000 },
        { 0x0004, 0x00F0, 0x0001, 0x0000 },
        { 0x0005, 0x04EC, 0x0000, 0x0000 },
        { 0x0011, 0x0218, 0x0001, 0x0000 },
        { 0x003A, 0x00E8, 0x0000, 0x0000 },
        { 0x003C, 0x01DC, 0x0001, 0x0000 },
    },
};
