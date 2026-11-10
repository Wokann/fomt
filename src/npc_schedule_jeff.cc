#include "npc_schedule_jeff.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectJeffSchedule\n"
    "SelectJeffSchedule:\n"
    "    push\t{r4, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr1, r0, #0\n"
    "    ldr r2, .Ljp_0803DC20\n"
    "    adds\tr0, r1, r2\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #29\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803DC24\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803DC54\n"
    "    .align 2, 0\n"
    ".Ljp_0803DC20: .word 0x000021CA\n"
    ".Ljp_0803DC24:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DC42\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803DC54\n"
    ".Ljp_0803DC42:\n"
    "    cmp\tr4, #2\n"
    "    bne .Ljp_0803DC4A\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803DC54\n"
    ".Ljp_0803DC4A:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803DC52\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803DC54\n"
    ".Ljp_0803DC52:\n"
    "    movs\tr0, #3\n"
    ".Ljp_0803DC54:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

// This is the immediately following, larger instance of the same selector
// family. The repeated entries intentionally retain their original pointers:
// native readers distinguish table placement even when a payload is shared.
extern "C" NpcScheduleExtendedStorage const gUnk_080F3408 = {
        {
            SelectJeffSchedule,
            5,
            gUnk_080F3408.table_choices,
        },
        {
            nullptr,
            &gUnk_080F3408.table_storage[0],
            &gUnk_080F3408.table_storage[1],
            &gUnk_080F3408.table_storage[2],
            &gUnk_080F3408.table_storage[3],
        },
        {
            { 3, gUnk_080F3408.entry_storage_0 },
            { 7, gUnk_080F3408.entry_storage_1 },
            { 5, gUnk_080F3408.entry_storage_2 },
            { 1, gUnk_080F3408.entry_storage_3 },
        },
        {
            { 0x0000, &gUnk_080F3408.payload_storage[0] },
            { 0x0078, &gUnk_080F3408.payload_storage[1] },
            { 0x02D0, &gUnk_080F3408.payload_storage[0] },
        },
        {
            { 0x0000, &gUnk_080F3408.payload_storage[0] },
            { 0x00F3, &gUnk_080F3408.payload_storage[2] },
            { 0x010E, &gUnk_080F3408.payload_storage[3] },
            { 0x01A7, &gUnk_080F3408.payload_storage[4] },
            { 0x01BB, &gUnk_080F3408.payload_storage[5] },
            { 0x0258, &gUnk_080F3408.payload_storage[6] },
            { 0x0263, &gUnk_080F3408.payload_storage[0] },
        },
        {
            { 0x0000, &gUnk_080F3408.payload_storage[0] },
            { 0x01A7, &gUnk_080F3408.payload_storage[7] },
            { 0x01C4, &gUnk_080F3408.payload_storage[8] },
            { 0x025B, &gUnk_080F3408.payload_storage[9] },
            { 0x0278, &gUnk_080F3408.payload_storage[0] },
        },
        {
            { 0x0000, &gUnk_080F3408.payload_storage[0] },
        },
        {
            { nullptr, 0, 40, 88, 16, 1, false },
            { nullptr, 0, 227, 115, 15, 0, false },
            { gUnk_080F3408.detail_storage_0, 3, 688, 160, 5, 0, false },
            { nullptr, 0, 264, 155, 12, 1, false },
            { gUnk_080F3408.detail_storage_1, 3, 1232, 156, 5, 0, false },
            { nullptr, 0, 40, 192, 19, 3, false },
            { gUnk_080F3408.detail_storage_2, 3, 856, 164, 5, 0, false },
            { gUnk_080F3408.detail_storage_3, 5, 688, 160, 5, 0, false },
            { nullptr, 0, 224, 235, 21, 3, false },
            { gUnk_080F3408.detail_storage_4, 5, 632, 488, 5, 0, false },
        },
        {
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0018, 0x04D0, 0x0000, 0x0000 },
            { 0x001B, 0x009C, 0x0001, 0x0000 },
        },
        {
            { 0x0003, 0x00D8, 0x0001, 0x0000 },
            { 0x0012, 0x0358, 0x0000, 0x0000 },
            { 0x0014, 0x00A4, 0x0001, 0x0000 },
        },
        {
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0009, 0x02B0, 0x0000, 0x0000 },
            { 0x000B, 0x00A0, 0x0001, 0x0000 },
        },
        {
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0007, 0x0328, 0x0000, 0x0000 },
            { 0x0014, 0x0218, 0x0001, 0x0000 },
            { 0x001B, 0x0278, 0x0000, 0x0000 },
            { 0x001D, 0x01E8, 0x0001, 0x0000 },
        },
        {
            { 0x0002, 0x0218, 0x0001, 0x0000 },
            { 0x0009, 0x0328, 0x0000, 0x0000 },
            { 0x0016, 0x00D8, 0x0001, 0x0000 },
            { 0x001B, 0x02B0, 0x0000, 0x0000 },
            { 0x001D, 0x00A0, 0x0001, 0x0000 },
        },
    };
