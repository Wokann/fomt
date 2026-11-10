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

extern "C" AnnaScheduleData const gAnnaScheduleData = {
    // descriptor
    {
        SelectAnnaSchedule,
        ARRAY_COUNT(gAnnaScheduleData.table_choices),
        gAnnaScheduleData.table_choices,
    },
    // table_choices
    {
        nullptr,
        &gAnnaScheduleData.table_storage[0],
        &gAnnaScheduleData.table_storage[1],
        &gAnnaScheduleData.table_storage[2],
        &gAnnaScheduleData.table_storage[3],
        &gAnnaScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gAnnaScheduleData.entries_0), gAnnaScheduleData.entries_0 },
        { ARRAY_COUNT(gAnnaScheduleData.entries_1), gAnnaScheduleData.entries_1 },
        { ARRAY_COUNT(gAnnaScheduleData.entries_2), gAnnaScheduleData.entries_2 },
        { ARRAY_COUNT(gAnnaScheduleData.entries_3), gAnnaScheduleData.entries_3 },
        { ARRAY_COUNT(gAnnaScheduleData.entries_4), gAnnaScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
        { 0x0000003C, &gAnnaScheduleData.payload_storage[1] },
        { 0x000001A4, &gAnnaScheduleData.payload_storage[2] },
        { 0x000001E5, &gAnnaScheduleData.payload_storage[3] },
        { 0x000001EF, &gAnnaScheduleData.payload_storage[4] },
        { 0x0000025A, &gAnnaScheduleData.payload_storage[5] },
        { 0x00000264, &gAnnaScheduleData.payload_storage[6] },
        { 0x000002A4, &gAnnaScheduleData.payload_storage[1] },
        { 0x000003C0, &gAnnaScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
        { 0x0000003C, &gAnnaScheduleData.payload_storage[1] },
        { 0x000003C0, &gAnnaScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
        { 0x00000042, &gAnnaScheduleData.payload_storage[7] },
        { 0x0000005D, &gAnnaScheduleData.payload_storage[8] },
        { 0x00000098, &gAnnaScheduleData.payload_storage[9] },
        { 0x000000F3, &gAnnaScheduleData.payload_storage[10] },
        { 0x0000012E, &gAnnaScheduleData.payload_storage[11] },
        { 0x00000148, &gAnnaScheduleData.payload_storage[1] },
        { 0x000001AA, &gAnnaScheduleData.payload_storage[12] },
        { 0x000001C2, &gAnnaScheduleData.payload_storage[13] },
        { 0x00000258, &gAnnaScheduleData.payload_storage[14] },
        { 0x00000270, &gAnnaScheduleData.payload_storage[1] },
        { 0x000003C0, &gAnnaScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
        { 0x0000003C, &gAnnaScheduleData.payload_storage[1] },
        { 0x000001A7, &gAnnaScheduleData.payload_storage[12] },
        { 0x000001BF, &gAnnaScheduleData.payload_storage[13] },
        { 0x00000258, &gAnnaScheduleData.payload_storage[14] },
        { 0x00000270, &gAnnaScheduleData.payload_storage[1] },
        { 0x000003C0, &gAnnaScheduleData.payload_storage[0] },
    },
    // entries_4
    {
        { 0x00000000, &gAnnaScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { nullptr, 0, 50, 88, 27, 0, false },
        { nullptr, 0, 24, 88, 26, 0, false },
        { gAnnaScheduleData.points_2, ARRAY_COUNT(gAnnaScheduleData.points_2), 200, 160, 5, 0, false },
        { gAnnaScheduleData.points_3, ARRAY_COUNT(gAnnaScheduleData.points_3), 220, 0, 6, 0, false },
        { nullptr, 0, 360, 96, 6, 2, false },
        { gAnnaScheduleData.points_5, ARRAY_COUNT(gAnnaScheduleData.points_5), 360, 96, 6, 0, false },
        { gAnnaScheduleData.points_6, ARRAY_COUNT(gAnnaScheduleData.points_6), 1260, 704, 5, 0, false },
        { gAnnaScheduleData.points_7, ARRAY_COUNT(gAnnaScheduleData.points_7), 200, 160, 5, 0, false },
        { gAnnaScheduleData.points_8, ARRAY_COUNT(gAnnaScheduleData.points_8), 1200, 752, 0, 0, false },
        { nullptr, 0, 296, 200, 0, 3, false },
        { gAnnaScheduleData.points_10, ARRAY_COUNT(gAnnaScheduleData.points_10), 296, 200, 0, 0, false },
        { gAnnaScheduleData.points_11, ARRAY_COUNT(gAnnaScheduleData.points_11), 104, 704, 5, 0, false },
        { gAnnaScheduleData.points_12, ARRAY_COUNT(gAnnaScheduleData.points_12), 200, 160, 5, 0, false },
        { nullptr, 0, 152, 138, 15, 0, false },
        { gAnnaScheduleData.points_14, ARRAY_COUNT(gAnnaScheduleData.points_14), 688, 160, 5, 0, false },
    },
    // points_2
    {
        { 2, 216, true },
        { 26, 808, false },
        { 39, 536, true },
        { 57, 1260, false },
        { 65, 736, true },
    },
    // points_3
    {
        { 4, 96, true },
        { 10, 360, false },
    },
    // points_5
    {
        { 6, 220, false },
        { 10, 0, true },
    },
    // points_6
    {
        { 7, 536, true },
        { 25, 808, false },
        { 38, 216, true },
        { 62, 200, false },
        { 64, 160, true },
    },
    // points_7
    {
        { 2, 216, true },
        { 4, 144, false },
        { 5, 240, true },
        { 7, 104, false },
        { 27, 734, true },
    },
    // points_8
    {
        { 12, 912, false },
        { 13, 728, true },
        { 15, 856, false },
        { 16, 704, true },
        { 17, 832, false },
        { 18, 680, true },
        { 19, 808, false },
        { 20, 656, true },
        { 21, 776, false },
        { 22, 624, true },
        { 23, 752, false },
        { 24, 592, true },
        { 25, 720, false },
        { 26, 568, true },
        { 27, 692, false },
        { 37, 328, true },
        { 38, 656, false },
        { 44, 168, true },
        { 58, 296, false },
        { 59, 200, true },
    },
    // points_10
    {
        { 1, 168, true },
        { 15, 656, false },
        { 21, 328, true },
        { 22, 692, false },
        { 32, 568, true },
        { 33, 720, false },
        { 34, 592, true },
        { 35, 752, false },
        { 36, 624, true },
        { 37, 776, false },
        { 38, 656, true },
        { 39, 808, false },
        { 40, 680, true },
        { 41, 832, false },
        { 42, 704, true },
        { 43, 856, false },
        { 44, 728, true },
        { 46, 912, false },
        { 47, 752, true },
        { 59, 1216, false },
    },
    // points_11
    {
        { 19, 240, true },
        { 21, 144, false },
        { 22, 216, true },
        { 24, 200, false },
        { 26, 160, true },
    },
    // points_12
    {
        { 2, 216, true },
        { 22, 688, false },
        { 24, 160, true },
    },
    // points_14
    {
        { 2, 216, true },
        { 22, 200, false },
        { 24, 160, true },
    },
};
