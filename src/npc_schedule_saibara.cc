#include "npc_schedule_saibara.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectSaibaraSchedule\n"
    "SelectSaibaraSchedule:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E8D0\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E8D4\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E92C\n"
    "    .align 2, 0\n"
    ".Ljp_0803E8D0: .word 0x000021CA\n"
    ".Ljp_0803E8D4:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr6, [r4, #3]\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E8F4\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E92C\n"
    ".Ljp_0803E8F4:\n"
    "    ldr r0, .Ljp_0803E914\n"
    "    adds\tr4, r5, r0\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetOrder__C7Saibara\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803E918\n"
    "    adds\tr0, r4, #0\n"
    "    bl IsOrderComplete__C7Saibara\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E918\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803E92C\n"
    "    .align 2, 0\n"
    ".Ljp_0803E914: .word 0x00001DAC\n"
    ".Ljp_0803E918:\n"
    "    cmp\tr6, #4\n"
    "    bne .Ljp_0803E92A\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E926\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E92C\n"
    ".Ljp_0803E926:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E92C\n"
    ".Ljp_0803E92A:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E92C:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" NpcScheduleStorage_080F77FC const gUnk_080F77FC = {
    {
        SelectSaibaraSchedule,
        6,
        gUnk_080F77FC.table_choices,
    },
    {
        nullptr,
        &gUnk_080F77FC.table_storage[0],
        &gUnk_080F77FC.table_storage[1],
        &gUnk_080F77FC.table_storage[2],
        &gUnk_080F77FC.table_storage[3],
        &gUnk_080F77FC.table_storage[4],
    },
    {
        { 8, &gUnk_080F77FC.entry_storage[0] },
        { 19, &gUnk_080F77FC.entry_storage[8] },
        { 8, &gUnk_080F77FC.entry_storage[27] },
        { 1, &gUnk_080F77FC.entry_storage[35] },
        { 1, &gUnk_080F77FC.entry_storage[36] },
    },
    {
        { 0x00000000, &gUnk_080F77FC.payload_storage[0] },
        { 0x00000078, &gUnk_080F77FC.payload_storage[1] },
        { 0x0000030F, &gUnk_080F77FC.payload_storage[2] },
        { 0x0000031F, &gUnk_080F77FC.payload_storage[6] },
        { 0x0000033E, &gUnk_080F77FC.payload_storage[7] },
        { 0x000003C0, &gUnk_080F77FC.payload_storage[8] },
        { 0x000003DF, &gUnk_080F77FC.payload_storage[9] },
        { 0x000003EF, &gUnk_080F77FC.payload_storage[0] },
        { 0x00000000, &gUnk_080F77FC.payload_storage[0] },
        { 0x0000003F, &gUnk_080F77FC.payload_storage[10] },
        { 0x00000065, &gUnk_080F77FC.payload_storage[11] },
        { 0x0000006E, &gUnk_080F77FC.payload_storage[12] },
        { 0x000000F0, &gUnk_080F77FC.payload_storage[13] },
        { 0x000000FA, &gUnk_080F77FC.payload_storage[14] },
        { 0x0000011F, &gUnk_080F77FC.payload_storage[1] },
        { 0x000001A7, &gUnk_080F77FC.payload_storage[2] },
        { 0x000001B7, &gUnk_080F77FC.payload_storage[3] },
        { 0x000001E5, &gUnk_080F77FC.payload_storage[4] },
        { 0x00000258, &gUnk_080F77FC.payload_storage[5] },
        { 0x00000287, &gUnk_080F77FC.payload_storage[9] },
        { 0x00000297, &gUnk_080F77FC.payload_storage[1] },
        { 0x0000030C, &gUnk_080F77FC.payload_storage[2] },
        { 0x0000031C, &gUnk_080F77FC.payload_storage[6] },
        { 0x0000033B, &gUnk_080F77FC.payload_storage[1] },
        { 0x000003C0, &gUnk_080F77FC.payload_storage[8] },
        { 0x000003DF, &gUnk_080F77FC.payload_storage[9] },
        { 0x000003EF, &gUnk_080F77FC.payload_storage[0] },
        { 0x00000000, &gUnk_080F77FC.payload_storage[0] },
        { 0x00000078, &gUnk_080F77FC.payload_storage[1] },
        { 0x0000030C, &gUnk_080F77FC.payload_storage[2] },
        { 0x0000031C, &gUnk_080F77FC.payload_storage[6] },
        { 0x0000033B, &gUnk_080F77FC.payload_storage[7] },
        { 0x000003C0, &gUnk_080F77FC.payload_storage[8] },
        { 0x000003DF, &gUnk_080F77FC.payload_storage[9] },
        { 0x000003EF, &gUnk_080F77FC.payload_storage[0] },
        { 0x00000000, &gUnk_080F77FC.payload_storage[0] },
        { 0x00000000, &gUnk_080F77FC.payload_storage[1] },
    },
    {
        { &gUnk_080F77FC.detail_storage[0], 2, 152, 80, 38, 0, true },
        { nullptr, 0, 118, 115, 38, 0, false },
        { &gUnk_080F77FC.detail_storage[2], 3, 296, 116, 7, 0, false },
        { &gUnk_080F77FC.detail_storage[5], 5, 104, 704, 5, 0, false },
        { nullptr, 0, 152, 136, 15, 0, false },
        { &gUnk_080F77FC.detail_storage[10], 5, 688, 160, 5, 0, false },
        { &gUnk_080F77FC.detail_storage[15], 3, 104, 704, 5, 0, false },
        { nullptr, 0, 287, 235, 21, 2, false },
        { &gUnk_080F77FC.detail_storage[18], 3, 632, 488, 5, 0, false },
        { &gUnk_080F77FC.detail_storage[21], 3, 104, 0, 7, 0, false },
        { &gUnk_080F77FC.detail_storage[24], 3, 296, 116, 7, 0, false },
        { &gUnk_080F77FC.detail_storage[27], 2, 240, 480, 8, 0, false },
        { nullptr, 0, 256, 272, 8, 1, false },
        { &gUnk_080F77FC.detail_storage[29], 2, 256, 272, 8, 0, false },
        { &gUnk_080F77FC.detail_storage[31], 3, 812, 512, 7, 0, false },
    },
    {
        { 0x00C0, 0x0002, 0x0078, 0x0003 },
        { 0x0098, 0x0002, 0x0078, 0x0002 },
        { 0x0002, 0x0098, 0x0001, 0x0000 },
        { 0x000A, 0x0068, 0x0000, 0x0000 },
        { 0x0010, 0x0000, 0x0001, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0015, 0x0090, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x002C, 0x02B0, 0x0000, 0x0000 },
        { 0x002E, 0x00A0, 0x0001, 0x0000 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0018, 0x0090, 0x0000, 0x0000 },
        { 0x0019, 0x00F0, 0x0001, 0x0000 },
        { 0x001B, 0x0068, 0x0000, 0x0000 },
        { 0x002F, 0x02E0, 0x0001, 0x0000 },
        { 0x0007, 0x0218, 0x0001, 0x0000 },
        { 0x001C, 0x0278, 0x0000, 0x0000 },
        { 0x001F, 0x01E8, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x0017, 0x0068, 0x0000, 0x0000 },
        { 0x001F, 0x02E0, 0x0001, 0x0000 },
        { 0x0006, 0x0098, 0x0001, 0x0000 },
        { 0x000E, 0x0128, 0x0000, 0x0000 },
        { 0x0010, 0x0074, 0x0001, 0x0000 },
        { 0x0002, 0x0098, 0x0001, 0x0000 },
        { 0x0017, 0x032C, 0x0000, 0x0000 },
        { 0x0026, 0x0220, 0x0001, 0x0000 },
        { 0x0008, 0x0110, 0x0001, 0x0000 },
        { 0x0009, 0x0100, 0x0000, 0x0000 },
        { 0x0001, 0x00F0, 0x0000, 0x0000 },
        { 0x000A, 0x0200, 0x0001, 0x0000 },
        { 0x000E, 0x0098, 0x0001, 0x0000 },
        { 0x0023, 0x0128, 0x0000, 0x0000 },
        { 0x0025, 0x0074, 0x0001, 0x0000 },
    },
};
