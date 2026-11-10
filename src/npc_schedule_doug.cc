#include "npc_schedule_doug.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectDougSchedule\n"
    "SelectDougSchedule:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803DE88\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803DE8C\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803DECE\n"
    "    .align 2, 0\n"
    ".Ljp_0803DE88: .word 0x000021CA\n"
    ".Ljp_0803DE8C:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr6, [r4, #1]\n"
    "    ldrb\tr4, [r4, #2]\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r4, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DEAE\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803DECE\n"
    ".Ljp_0803DEAE:\n"
    "    ldr r1, .Ljp_0803DEC8\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetSpouseCharacterId__C13NpcCollection\n"
    "    cmp\tr6, #2\n"
    "    bne .Ljp_0803DECC\n"
    "    cmp\tr4, #5\n"
    "    bne .Ljp_0803DECC\n"
    "    cmp\tr0, #25\n"
    "    beq .Ljp_0803DECC\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803DECE\n"
    "    .align 2, 0\n"
    ".Ljp_0803DEC8: .word 0x00001CD4\n"
    ".Ljp_0803DECC:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803DECE:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

// The following selector descriptors were recovered from the contiguous
// script-adjacent UI resource block.  Their nested C++ objects preserve every
// original internal pointer as a relocation rather than a ROM address.

extern "C" DougScheduleData const gDougScheduleData = {
    // descriptor
    {
        SelectDougSchedule,
        ARRAY_COUNT(gDougScheduleData.table_choices),
        gDougScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gDougScheduleData.table_storage[0],
        &gDougScheduleData.table_storage[1],
        &gDougScheduleData.table_storage[2],
    },
    // table_storage
    {
        { ARRAY_COUNT(gDougScheduleData.entries_0), gDougScheduleData.entries_0 },
        { ARRAY_COUNT(gDougScheduleData.entries_1), gDougScheduleData.entries_1 },
        { ARRAY_COUNT(gDougScheduleData.entries_2), gDougScheduleData.entries_2 },
    },
    // entries_0
    {
        { 0x00000000, &gDougScheduleData.payload_storage[0] },
        { 0x00000078, &gDougScheduleData.payload_storage[1] },
        { 0x000001A4, &gDougScheduleData.payload_storage[2] },
        { 0x0000021C, &gDougScheduleData.payload_storage[1] },
        { 0x0000030C, &gDougScheduleData.payload_storage[2] },
        { 0x00000384, &gDougScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gDougScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gDougScheduleData.payload_storage[3] },
        { 0x00000294, &gDougScheduleData.payload_storage[4] },
        { 0x0000029F, &gDougScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gDougScheduleData.points_0, ARRAY_COUNT(gDougScheduleData.points_0), 304, 88, 22, 0, true },
        { nullptr, 0, 315, 80, 21, 0, false },
        { nullptr, 0, 48, 80, 22, 1, false },
        { nullptr, 0, 200, 280, 8, 1, false },
        { gDougScheduleData.points_4, ARRAY_COUNT(gDougScheduleData.points_4), 200, 280, 8, 0, false },
    },
    // points_0
    {
        { 170, 2, 120, 0, true },
        { 88, 2, 120, 1, true },
    },
    // points_4
    {
        { 2, 240, false },
        { 11, 512, true },
    },
};
