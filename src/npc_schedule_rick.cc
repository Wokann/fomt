#include "npc_schedule_rick.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectRickSchedule\n"
    "SelectRickSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803D6B0\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    movs\tr0, #12\n"
    "    ands\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D6B4\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803D6E8\n"
    ".Ljp_0803D6B0: .word 0x000021CA\n"
    ".Ljp_0803D6B4:\n"
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
    "    beq .Ljp_0803D6D4\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803D6E8\n"
    ".Ljp_0803D6D4:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D6E6\n"
    "    cmp\tr4, #2\n"
    "    bne .Ljp_0803D6E2\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803D6E8\n"
    ".Ljp_0803D6E2:\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803D6E8\n"
    ".Ljp_0803D6E6:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803D6E8:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

extern "C" RickScheduleData const gRickScheduleData = {
    // descriptor
    { SelectRickSchedule, ARRAY_COUNT(gRickScheduleData.table_choices), gRickScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gRickScheduleData.table_storage[0], &gRickScheduleData.table_storage[1], &gRickScheduleData.table_storage[2], &gRickScheduleData.table_storage[3],
    },
    // table_storage
    {
        { ARRAY_COUNT(gRickScheduleData.entries_0), gRickScheduleData.entries_0 },
        { ARRAY_COUNT(gRickScheduleData.entries_1), gRickScheduleData.entries_1 },
        { ARRAY_COUNT(gRickScheduleData.entries_2), gRickScheduleData.entries_2 },
        { ARRAY_COUNT(gRickScheduleData.entries_3), gRickScheduleData.entries_3 },
    },
    // entries_0
    {
        { 0, &gRickScheduleData.payload_storage[19] },    /* 06:00 */
        { 60, &gRickScheduleData.payload_storage[21] },   /* 07:00 */
        { 91, &gRickScheduleData.payload_storage[2] },    /* 07:31 */
        { 139, &gRickScheduleData.payload_storage[3] },   /* 08:19 */
        { 242, &gRickScheduleData.payload_storage[4] },   /* 10:02 */
        { 291, &gRickScheduleData.payload_storage[5] },   /* 10:51 */
        { 321, &gRickScheduleData.payload_storage[1] },   /* 11:21 */
        { 423, &gRickScheduleData.payload_storage[18] },  /* 13:03 */
        { 430, &gRickScheduleData.payload_storage[19] },  /* 13:10 */
        { 600, &gRickScheduleData.payload_storage[20] },  /* 16:00 */
        { 607, &gRickScheduleData.payload_storage[1] },   /* 16:07 */
        { 780, &gRickScheduleData.payload_storage[6] },   /* 19:00 */
        { 827, &gRickScheduleData.payload_storage[7] },   /* 19:47 */
        { 861, &gRickScheduleData.payload_storage[8] },   /* 20:21 */
        { 972, &gRickScheduleData.payload_storage[9] },   /* 22:12 */
        { 1007, &gRickScheduleData.payload_storage[10] }, /* 22:47 */
        { 1054, &gRickScheduleData.payload_storage[0] },  /* 23:34 */
    },
    // entries_1
    {
        { 0, &gRickScheduleData.payload_storage[19] },    /* 06:00 */
        { 60, &gRickScheduleData.payload_storage[20] },   /* 07:00 */
        { 67, &gRickScheduleData.payload_storage[0] },    /* 07:07 */
        { 780, &gRickScheduleData.payload_storage[6] },   /* 19:00 */
        { 827, &gRickScheduleData.payload_storage[7] },   /* 19:47 */
        { 861, &gRickScheduleData.payload_storage[8] },   /* 20:21 */
        { 972, &gRickScheduleData.payload_storage[9] },   /* 22:12 */
        { 1007, &gRickScheduleData.payload_storage[10] }, /* 22:47 */
        { 1054, &gRickScheduleData.payload_storage[0] },  /* 23:34 */
    },
    // entries_2
    {
        { 0, &gRickScheduleData.payload_storage[19] },    /* 06:00 */
        { 60, &gRickScheduleData.payload_storage[22] },   /* 07:00 */
        { 108, &gRickScheduleData.payload_storage[11] },  /* 07:48 */
        { 117, &gRickScheduleData.payload_storage[12] },  /* 07:57 */
        { 240, &gRickScheduleData.payload_storage[13] },  /* 10:00 */
        { 250, &gRickScheduleData.payload_storage[14] },  /* 10:10 */
        { 297, &gRickScheduleData.payload_storage[1] },   /* 10:57 */
        { 420, &gRickScheduleData.payload_storage[15] },  /* 13:00 */
        { 438, &gRickScheduleData.payload_storage[16] },  /* 13:18 */
        { 600, &gRickScheduleData.payload_storage[17] },  /* 16:00 */
        { 618, &gRickScheduleData.payload_storage[1] },   /* 16:18 */
        { 780, &gRickScheduleData.payload_storage[6] },   /* 19:00 */
        { 827, &gRickScheduleData.payload_storage[7] },   /* 19:47 */
        { 861, &gRickScheduleData.payload_storage[8] },   /* 20:21 */
        { 972, &gRickScheduleData.payload_storage[9] },   /* 22:12 */
        { 1007, &gRickScheduleData.payload_storage[10] }, /* 22:47 */
        { 1054, &gRickScheduleData.payload_storage[0] },  /* 23:34 */
    },
    // entries_3
    {
        { 0, &gRickScheduleData.payload_storage[0] }, /* 06:00 */
    },
    // payload_storage
    {
        { nullptr, 0, 72, 80, 11, 0, 0 },
        { nullptr, 0, 64, 83, 10, 1, 0 },
        { gRickScheduleData.points_2, ARRAY_COUNT(gRickScheduleData.points_2), 104, 704, 5, 0, 0 },
        { nullptr, 0, 776, 184, 5, 0, 0 },
        { gRickScheduleData.points_4, ARRAY_COUNT(gRickScheduleData.points_4), 776, 184, 5, 0, 0 },
        { gRickScheduleData.points_5, ARRAY_COUNT(gRickScheduleData.points_5), 104, 0, 7, 0, 0 },
        { gRickScheduleData.points_6, ARRAY_COUNT(gRickScheduleData.points_6), 572, 227, 7, 0, 0 },
        { gRickScheduleData.points_7, ARRAY_COUNT(gRickScheduleData.points_7), 1260, 704, 5, 0, 0 },
        { nullptr, 0, 232, 120, 21, 1, 0 },
        { gRickScheduleData.points_9, ARRAY_COUNT(gRickScheduleData.points_9), 632, 488, 5, 0, 0 },
        { gRickScheduleData.points_10, ARRAY_COUNT(gRickScheduleData.points_10), 1272, 0, 7, 0, 0 },
        { gRickScheduleData.points_11, ARRAY_COUNT(gRickScheduleData.points_11), 220, 448, 6, 0, 0 },
        { gRickScheduleData.points_12, ARRAY_COUNT(gRickScheduleData.points_12), 376, 384, 6, 0, 1 },
        { gRickScheduleData.points_13, ARRAY_COUNT(gRickScheduleData.points_13), 376, 384, 6, 0, 0 },
        { gRickScheduleData.points_14, ARRAY_COUNT(gRickScheduleData.points_14), 1272, 0, 7, 0, 0 },
        { gRickScheduleData.points_15, ARRAY_COUNT(gRickScheduleData.points_15), 572, 227, 7, 0, 0 },
        { nullptr, 0, 88, 88, 38, 0, 0 },
        { gRickScheduleData.points_17, ARRAY_COUNT(gRickScheduleData.points_17), 296, 116, 7, 0, 0 },
        { gRickScheduleData.points_18, ARRAY_COUNT(gRickScheduleData.points_18), 572, 227, 7, 0, 0 },
        { gRickScheduleData.points_19, ARRAY_COUNT(gRickScheduleData.points_19), 520, 352, 7, 0, 1 },
        { gRickScheduleData.points_20, ARRAY_COUNT(gRickScheduleData.points_20), 520, 352, 7, 0, 0 },
        { gRickScheduleData.points_21, ARRAY_COUNT(gRickScheduleData.points_21), 520, 352, 7, 0, 0 },
        { gRickScheduleData.points_22, ARRAY_COUNT(gRickScheduleData.points_22), 520, 352, 7, 0, 0 },
    },
    // points_2
    {
        { 19, 240, 1 }, { 21, 144, 0 }, { 22, 216, 1 }, { 47, 776, 0 }, { 48, 184, 1 },
    },
    // points_4
    {
        { 1, 216, 1 }, { 26, 144, 0 }, { 27, 240, 1 }, { 29, 104, 0 }, { 49, 736, 1 },
    },
    // points_5
    {
        { 6, 152, 1 }, { 21, 472, 0 }, { 25, 248, 1 }, { 29, 572, 0 }, { 30, 227, 1 },
    },
    // points_6
    {
        { 1, 248, 1 }, { 5, 472, 0 }, { 9, 152, 1 }, { 40, 1248, 0 }, { 41, 128, 1 }, { 42, 1272, 0 }, { 47, 0, 1 },
    },
    // points_7
    {
        { 7, 536, 1 },
        { 32, 632, 0 },
        { 34, 488, 1 },
    },
    // points_9
    {
        { 2, 536, 1 },
        { 27, 1260, 0 },
        { 35, 736, 1 },
    },
    // points_10
    {
        { 5, 128, 1 }, { 6, 1248, 0 }, { 7, 152, 1 }, { 38, 472, 0 }, { 42, 248, 1 }, { 46, 572, 0 }, { 47, 227, 1 },
    },
    // points_11
    {
        { 3, 384, 1 },
        { 9, 376, 0 },
    },
    // points_12
    {
        { 304, 2, 120, 0, 1 },
        { 384, 2, 120, 1, 1 },
    },
    // points_13
    {
        { 6, 220, 0 },
        { 10, 480, 1 },
    },
    // points_14
    {
        { 5, 128, 1 }, { 6, 1248, 0 }, { 7, 152, 1 }, { 38, 472, 0 }, { 42, 248, 1 }, { 46, 572, 0 }, { 47, 227, 1 },
    },
    // points_15
    {
        { 1, 248, 1 }, { 5, 472, 0 }, { 9, 152, 1 }, { 16, 296, 0 }, { 18, 116, 1 },
    },
    // points_17
    {
        { 2, 152, 1 }, { 9, 472, 0 }, { 13, 248, 1 }, { 17, 572, 0 }, { 18, 227, 1 },
    },
    // points_18
    {
        { 1, 248, 1 },
        { 3, 520, 0 },
        { 7, 352, 1 },
    },
    // points_19
    {
        { 440, 2, 0, 0, 0 },
        { 256, 2, 120, 2, 1 },
        { 352, 2, 0, 0, 1 },
        { 520, 2, 120, 3, 0 },
    },
    // points_20
    {
        { 4, 248, 1 },
        { 6, 572, 0 },
        { 7, 227, 1 },
    },
    // points_21
    {
        { 4, 248, 1 }, { 6, 472, 0 }, { 10, 152, 1 }, { 25, 104, 0 }, { 31, 0, 1 },
    },
    // points_22
    {
        { 4, 248, 1 }, { 6, 472, 0 }, { 10, 152, 1 }, { 41, 1248, 0 }, { 42, 128, 1 }, { 43, 1272, 0 }, { 48, 0, 1 },
    },
};
