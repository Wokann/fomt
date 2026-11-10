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

extern "C" BarleyScheduleData const gBarleyScheduleData = {
    // descriptor
    {
        SelectBarleySchedule,
        ARRAY_COUNT(gBarleyScheduleData.table_choices),
        gBarleyScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gBarleyScheduleData.table_storage[0],
        &gBarleyScheduleData.table_storage[1],
        &gBarleyScheduleData.table_storage[2],
        &gBarleyScheduleData.table_storage[3],
    },
    // table_storage
    {
        { ARRAY_COUNT(gBarleyScheduleData.entries_0), gBarleyScheduleData.entries_0 },
        { ARRAY_COUNT(gBarleyScheduleData.entries_1), gBarleyScheduleData.entries_1 },
        { ARRAY_COUNT(gBarleyScheduleData.entries_2), gBarleyScheduleData.entries_2 },
        { ARRAY_COUNT(gBarleyScheduleData.entries_3), gBarleyScheduleData.entries_3 },
    },
    // entries_0
    {
        { 0x00000000, &gBarleyScheduleData.payload_storage[2] },
        { 0x00000078, &gBarleyScheduleData.payload_storage[12] },
        { 0x00000080, &gBarleyScheduleData.payload_storage[0] },
        { 0x0000030C, &gBarleyScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0x00000000, &gBarleyScheduleData.payload_storage[2] },
        { 0x00000078, &gBarleyScheduleData.payload_storage[4] },
        { 0x0000008E, &gBarleyScheduleData.payload_storage[3] },
        { 0x000000C3, &gBarleyScheduleData.payload_storage[5] },
        { 0x000001A4, &gBarleyScheduleData.payload_storage[6] },
        { 0x000001DA, &gBarleyScheduleData.payload_storage[7] },
        { 0x000001EA, &gBarleyScheduleData.payload_storage[8] },
        { 0x00000258, &gBarleyScheduleData.payload_storage[9] },
        { 0x00000269, &gBarleyScheduleData.payload_storage[10] },
        { 0x0000028B, &gBarleyScheduleData.payload_storage[0] },
        { 0x0000030C, &gBarleyScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0x00000000, &gBarleyScheduleData.payload_storage[2] },
        { 0x00000078, &gBarleyScheduleData.payload_storage[4] },
        { 0x0000008E, &gBarleyScheduleData.payload_storage[3] },
        { 0x000000C3, &gBarleyScheduleData.payload_storage[5] },
        { 0x000001A4, &gBarleyScheduleData.payload_storage[6] },
        { 0x000001DA, &gBarleyScheduleData.payload_storage[11] },
        { 0x000001F3, &gBarleyScheduleData.payload_storage[0] },
        { 0x00000258, &gBarleyScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0x00000000, &gBarleyScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 81, 160, 41, 3, false },
        { gBarleyScheduleData.points_1, ARRAY_COUNT(gBarleyScheduleData.points_1), 64, 80, 42, 0, true },
        { gBarleyScheduleData.points_2, ARRAY_COUNT(gBarleyScheduleData.points_2), 1112, 272, 7, 0, true },
        { gBarleyScheduleData.points_3, ARRAY_COUNT(gBarleyScheduleData.points_3), 1260, 704, 5, 0, false },
        { gBarleyScheduleData.points_4, ARRAY_COUNT(gBarleyScheduleData.points_4), 1112, 272, 7, 0, false },
        { nullptr, 0, 120, 144, 30, 1, false },
        { gBarleyScheduleData.points_6, ARRAY_COUNT(gBarleyScheduleData.points_6), 480, 160, 5, 0, false },
        { gBarleyScheduleData.points_7, ARRAY_COUNT(gBarleyScheduleData.points_7), 1200, 528, 0, 0, false },
        { gBarleyScheduleData.points_8, ARRAY_COUNT(gBarleyScheduleData.points_8), 944, 536, 0, 0, true },
        { gBarleyScheduleData.points_9, ARRAY_COUNT(gBarleyScheduleData.points_9), 944, 536, 0, 0, false },
        { gBarleyScheduleData.points_10, ARRAY_COUNT(gBarleyScheduleData.points_10), 812, 512, 7, 0, false },
        { gBarleyScheduleData.points_11, ARRAY_COUNT(gBarleyScheduleData.points_11), 1272, 0, 7, 0, false },
        { gBarleyScheduleData.points_12, ARRAY_COUNT(gBarleyScheduleData.points_12), 1112, 272, 7, 0, false },
    },
    // points_1
    {
        { 168, 2, 120, 3, true },
        { 80, 2, 120, 3, true },
    },
    // points_2
    {
        { 1176, 2, 120, 3, false },
        { 1112, 2, 120, 2, false },
    },
    // points_3
    {
        { 7, 536, true },
        { 25, 808, false },
        { 38, 216, true },
        { 51, 480, false },
        { 53, 160, true },
    },
    // points_4
    {
        { 2, 1060, false },
        { 7, 152, true },
        { 15, 1248, false },
        { 16, 128, true },
        { 17, 1272, false },
        { 22, 0, true },
    },
    // points_6
    {
        { 2, 216, true },
        { 15, 808, false },
        { 28, 536, true },
        { 46, 1260, false },
        { 54, 734, true },
    },
    // points_7
    {
        { 1, 1176, false },
        { 2, 512, true },
        { 3, 1160, false },
        { 4, 496, true },
        { 5, 1144, false },
        { 6, 480, true },
        { 12, 1000, false },
        { 14, 536, true },
        { 16, 944, false },
    },
    // points_8
    {
        { 880, 2, 120, 2, false },
        { 944, 2, 120, 3, false },
    },
    // points_9
    {
        { 2, 1000, false },
        { 4, 480, true },
        { 10, 1144, false },
        { 11, 496, true },
        { 12, 1160, false },
        { 13, 512, true },
        { 14, 1176, false },
        { 15, 528, true },
        { 17, 1216, false },
    },
    // points_10
    {
        { 14, 152, true },
        { 24, 1060, false },
        { 29, 280, true },
        { 32, 992, false },
        { 34, 232, true },
    },
    // points_11
    {
        { 5, 128, true },
        { 6, 1248, false },
        { 7, 152, true },
        { 15, 1060, false },
        { 20, 280, true },
        { 23, 992, false },
        { 25, 232, true },
    },
    // points_12
    {
        { 2, 1060, false },
        { 3, 280, true },
        { 6, 992, false },
        { 8, 232, true },
    },
};
