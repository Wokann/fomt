#include "npc_schedule_basil.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectBasilSchedule\n"
    "SelectBasilSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803E0D4\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803E0D8\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803E10C\n"
    "    .align 2, 0\n"
    ".Ljp_0803E0D4: .word 0x000021CA\n"
    ".Ljp_0803E0D8:\n"
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
    "    beq .Ljp_0803E0F8\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803E10C\n"
    ".Ljp_0803E0F8:\n"
    "    cmp\tr4, #1\n"
    "    bne .Ljp_0803E10A\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803E106\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803E10C\n"
    ".Ljp_0803E106:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803E10C\n"
    ".Ljp_0803E10A:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803E10C:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" NpcScheduleStorage_080F49C0 const gUnk_080F49C0 = {
    {
        SelectBasilSchedule,
        5,
        gUnk_080F49C0.table_choices,
    },
    {
        nullptr,
        &gUnk_080F49C0.table_storage[0],
        &gUnk_080F49C0.table_storage[1],
        &gUnk_080F49C0.table_storage[2],
        &gUnk_080F49C0.table_storage[3],
    },
    {
        { 8, &gUnk_080F49C0.entry_storage[0] },
        { 13, &gUnk_080F49C0.entry_storage[8] },
        { 8, &gUnk_080F49C0.entry_storage[21] },
        { 1, &gUnk_080F49C0.entry_storage[29] },
    },
    {
        { 0x00000000, &gUnk_080F49C0.payload_storage[1] },
        { 0x000000F0, &gUnk_080F49C0.payload_storage[0] },
        { 0x000001A4, &gUnk_080F49C0.payload_storage[1] },
        { 0x00000258, &gUnk_080F49C0.payload_storage[0] },
        { 0x0000030C, &gUnk_080F49C0.payload_storage[2] },
        { 0x00000336, &gUnk_080F49C0.payload_storage[3] },
        { 0x000003C6, &gUnk_080F49C0.payload_storage[4] },
        { 0x000003F0, &gUnk_080F49C0.payload_storage[1] },
        { 0x00000000, &gUnk_080F49C0.payload_storage[1] },
        { 0x0000003C, &gUnk_080F49C0.payload_storage[8] },
        { 0x00000057, &gUnk_080F49C0.payload_storage[5] },
        { 0x00000092, &gUnk_080F49C0.payload_storage[6] },
        { 0x000000F1, &gUnk_080F49C0.payload_storage[7] },
        { 0x0000012C, &gUnk_080F49C0.payload_storage[9] },
        { 0x00000146, &gUnk_080F49C0.payload_storage[0] },
        { 0x000001A4, &gUnk_080F49C0.payload_storage[1] },
        { 0x00000258, &gUnk_080F49C0.payload_storage[0] },
        { 0x0000030C, &gUnk_080F49C0.payload_storage[2] },
        { 0x00000336, &gUnk_080F49C0.payload_storage[3] },
        { 0x000003C6, &gUnk_080F49C0.payload_storage[4] },
        { 0x000003F0, &gUnk_080F49C0.payload_storage[1] },
        { 0x00000000, &gUnk_080F49C0.payload_storage[1] },
        { 0x000000F0, &gUnk_080F49C0.payload_storage[0] },
        { 0x000001A4, &gUnk_080F49C0.payload_storage[1] },
        { 0x00000258, &gUnk_080F49C0.payload_storage[0] },
        { 0x0000030C, &gUnk_080F49C0.payload_storage[2] },
        { 0x00000336, &gUnk_080F49C0.payload_storage[3] },
        { 0x000003C6, &gUnk_080F49C0.payload_storage[4] },
        { 0x000003F0, &gUnk_080F49C0.payload_storage[1] },
        { 0x00000000, &gUnk_080F49C0.payload_storage[1] },
    },
    {
        { &gUnk_080F49C0.detail_storage[0], 2, 24, 168, 26, 0, true },
        { nullptr, 0, 32, 88, 27, 1, false },
        { &gUnk_080F49C0.detail_storage[2], 7, 200, 160, 5, 0, false },
        { nullptr, 0, 127, 223, 21, 0, false },
        { &gUnk_080F49C0.detail_storage[9], 7, 632, 488, 5, 0, false },
        { &gUnk_080F49C0.detail_storage[16], 19, 1200, 752, 0, 0, false },
        { nullptr, 0, 280, 168, 0, 0, false },
        { &gUnk_080F49C0.detail_storage[35], 19, 280, 168, 0, 0, false },
        { &gUnk_080F49C0.detail_storage[54], 5, 200, 160, 5, 0, false },
        { &gUnk_080F49C0.detail_storage[59], 5, 104, 704, 5, 0, false },
    },
    {
        { 0x0050, 0x0002, 0x0078, 0x0003 },
        { 0x0018, 0x0002, 0x0078, 0x0002 },
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0004, 0x0090, 0x0000, 0x0000 },
        { 0x0005, 0x00F0, 0x0001, 0x0000 },
        { 0x0007, 0x0068, 0x0000, 0x0000 },
        { 0x0013, 0x0218, 0x0001, 0x0000 },
        { 0x0028, 0x0278, 0x0000, 0x0000 },
        { 0x002A, 0x01E8, 0x0001, 0x0000 },
        { 0x0002, 0x0218, 0x0001, 0x0000 },
        { 0x0017, 0x0068, 0x0000, 0x0000 },
        { 0x0023, 0x00F0, 0x0001, 0x0000 },
        { 0x0025, 0x0090, 0x0000, 0x0000 },
        { 0x0026, 0x00D8, 0x0001, 0x0000 },
        { 0x0028, 0x00C8, 0x0000, 0x0000 },
        { 0x002A, 0x00A0, 0x0001, 0x0000 },
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
        { 0x003B, 0x0118, 0x0000, 0x0000 },
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
        { 0x0002, 0x00D8, 0x0001, 0x0000 },
        { 0x0004, 0x0090, 0x0000, 0x0000 },
        { 0x0005, 0x00F0, 0x0001, 0x0000 },
        { 0x0007, 0x0068, 0x0000, 0x0000 },
        { 0x001B, 0x02DE, 0x0001, 0x0000 },
        { 0x0013, 0x00F0, 0x0001, 0x0000 },
        { 0x0015, 0x0090, 0x0000, 0x0000 },
        { 0x0016, 0x00D8, 0x0001, 0x0000 },
        { 0x0018, 0x00C8, 0x0000, 0x0000 },
        { 0x001A, 0x00A0, 0x0001, 0x0000 },
    },
};
