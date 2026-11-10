#include "npc_schedule_doctor.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectDoctorSchedule\n"
    "SelectDoctorSchedule:\n"
    "    push\t{r4, r5, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803DB84\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803DB88\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803DBBC\n"
    "    .align 2, 0\n"
    ".Ljp_0803DB84: .word 0x000021CA\n"
    ".Ljp_0803DB88:\n"
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
    "    beq .Ljp_0803DBA8\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803DBBC\n"
    ".Ljp_0803DBA8:\n"
    "    cmp\tr4, #3\n"
    "    bne .Ljp_0803DBBA\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DBB6\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803DBBC\n"
    ".Ljp_0803DBB6:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803DBBC\n"
    ".Ljp_0803DBBA:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803DBBC:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

// Recovered schedule data at US ROM 0x080F3010 (JP 0x080F286C).
// The two regional payloads differ only in relocated function/data pointers.

extern "C" DoctorScheduleData const gDoctorScheduleData = {
    // descriptor
    { SelectDoctorSchedule, ARRAY_COUNT(gDoctorScheduleData.table_choices), gDoctorScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gDoctorScheduleData.table_storage[0], &gDoctorScheduleData.table_storage[1], &gDoctorScheduleData.table_storage[2],
        &gDoctorScheduleData.table_storage[3],
    },
    // table_storage
    {
        { ARRAY_COUNT(gDoctorScheduleData.entries_0), gDoctorScheduleData.entries_0 },
        { ARRAY_COUNT(gDoctorScheduleData.entries_1), gDoctorScheduleData.entries_1 },
        { ARRAY_COUNT(gDoctorScheduleData.entries_2), gDoctorScheduleData.entries_2 },
        { ARRAY_COUNT(gDoctorScheduleData.entries_3), gDoctorScheduleData.entries_3 },
    },
    // entries_0
    {
        { 0, &gDoctorScheduleData.payload_storage[0] },
        { 180, &gDoctorScheduleData.payload_storage[1] },
        { 780, &gDoctorScheduleData.payload_storage[0] },
    },
    // entries_1
    {
        { 0, &gDoctorScheduleData.payload_storage[0] },
        { 60, &gDoctorScheduleData.payload_storage[2] },
        { 100, &gDoctorScheduleData.payload_storage[3] },
        { 147, &gDoctorScheduleData.payload_storage[4] },
        { 240, &gDoctorScheduleData.payload_storage[5] },
        { 288, &gDoctorScheduleData.payload_storage[6] },
        { 327, &gDoctorScheduleData.payload_storage[1] },
        { 420, &gDoctorScheduleData.payload_storage[7] },
        { 447, &gDoctorScheduleData.payload_storage[8] },
        // JP stores these two schedule times one minute earlier.
#if defined(REGION_JP)
        { 600, &gDoctorScheduleData.payload_storage[9] },
        { 627, &gDoctorScheduleData.payload_storage[1] },
#else
        { 601, &gDoctorScheduleData.payload_storage[9] },
        { 628, &gDoctorScheduleData.payload_storage[1] },
#endif
        { 960, &gDoctorScheduleData.payload_storage[0] },
    },
    // entries_2
    {
        { 0, &gDoctorScheduleData.payload_storage[0] },
        { 60, &gDoctorScheduleData.payload_storage[10] },
        { 79, &gDoctorScheduleData.payload_storage[11] },
        { 240, &gDoctorScheduleData.payload_storage[12] },
        { 259, &gDoctorScheduleData.payload_storage[1] },
        { 420, &gDoctorScheduleData.payload_storage[7] },
        { 447, &gDoctorScheduleData.payload_storage[8] },
        // JP stores these two schedule times one minute earlier.
#if defined(REGION_JP)
        { 600, &gDoctorScheduleData.payload_storage[9] },
        { 627, &gDoctorScheduleData.payload_storage[1] },
#else
        { 601, &gDoctorScheduleData.payload_storage[9] },
        { 628, &gDoctorScheduleData.payload_storage[1] },
#endif
        { 960, &gDoctorScheduleData.payload_storage[0] },
    },
    // entries_3
    {
        { 0, &gDoctorScheduleData.payload_storage[0] },
    },
    // payload_storage
    {
        { gDoctorScheduleData.points_0, ARRAY_COUNT(gDoctorScheduleData.points_0), 192, 208, 20, 0, 1 },
        { nullptr, 0, 248, 91, 19, 0, 0 },
        { gDoctorScheduleData.points_2, ARRAY_COUNT(gDoctorScheduleData.points_2), 856, 164, 5, 0, 0 },
        { gDoctorScheduleData.points_3, ARRAY_COUNT(gDoctorScheduleData.points_3), 1200, 752, 0, 0, 0 },
        { gDoctorScheduleData.points_4, ARRAY_COUNT(gDoctorScheduleData.points_4), 256, 488, 0, 0, 1 },
        { gDoctorScheduleData.points_5, ARRAY_COUNT(gDoctorScheduleData.points_5), 256, 488, 0, 0, 0 },
        { gDoctorScheduleData.points_6, ARRAY_COUNT(gDoctorScheduleData.points_6), 1260, 704, 5, 0, 0 },
        { gDoctorScheduleData.points_7, ARRAY_COUNT(gDoctorScheduleData.points_7), 856, 164, 5, 0, 0 },
        { nullptr, 0, 144, 144, 25, 1, 0 },
        { gDoctorScheduleData.points_9, ARRAY_COUNT(gDoctorScheduleData.points_9), 276, 168, 5, 0, 0 },
        { gDoctorScheduleData.points_10, ARRAY_COUNT(gDoctorScheduleData.points_10), 856, 164, 5, 0, 0 },
        { nullptr, 0, 296, 155, 12, 1, 0 },
        { gDoctorScheduleData.points_12, ARRAY_COUNT(gDoctorScheduleData.points_12), 1232, 156, 5, 0, 0 },
    },
    // points_0
    {
        { 72, 2, 120, 2, 0 },
        { 227, 2, 120, 0, 1 },
        { 192, 2, 120, 3, 0 },
        { 208, 2, 120, 2, 1 },
    },
    // points_2
    {
        { 2, 216, 1 },
        { 18, 1248, 0 },
        { 19, 240, 1 },
        { 20, 1260, 0 },
        { 40, 736, 1 },
    },
    // points_3
    {
        { 12, 912, 0 },
        { 13, 728, 1 },
        { 15, 856, 0 },
        { 16, 704, 1 },
        { 17, 832, 0 },
        { 18, 680, 1 },
        { 19, 808, 0 },
        { 20, 656, 1 },
        { 21, 776, 0 },
        { 22, 624, 1 },
        { 23, 752, 0 },
        { 24, 592, 1 },
        { 25, 720, 0 },
        { 26, 568, 1 },
        { 44, 256, 0 },
        { 47, 488, 1 },
    },
    // points_4
    {
        { 216, 2, 0, 0, 0 },
        { 552, 2, 120, 0, 1 },
        { 488, 2, 0, 0, 1 },
        { 256, 2, 120, 3, 0 },
    },
    // points_5
    {
        { 3, 568, 1 },
        { 21, 720, 0 },
        { 22, 592, 1 },
        { 23, 752, 0 },
        { 24, 624, 1 },
        { 25, 775, 0 },
        { 26, 656, 1 },
        { 27, 808, 0 },
        { 28, 680, 1 },
        { 29, 832, 0 },
        { 30, 704, 1 },
        { 31, 856, 0 },
        { 32, 728, 1 },
        { 34, 912, 0 },
        { 35, 752, 1 },
        { 48, 1216, 0 },
    },
    // points_6
    {
        { 19, 240, 1 },
        { 20, 1248, 0 },
        { 21, 216, 1 },
        { 37, 856, 0 },
        { 39, 164, 1 },
    },
    // points_7
    {
        { 2, 216, 1 },
        { 25, 276, 0 },
        { 27, 168, 1 },
    },
    // points_9
    {
        { 2, 216, 1 },
        { 25, 856, 0 },
        { 27, 164, 1 },
    },
    // points_10
    {
        { 2, 216, 1 },
        { 17, 1232, 0 },
        { 19, 156, 1 },
    },
    // points_12
    {
        { 2, 216, 1 },
        { 17, 856, 0 },
        { 19, 164, 1 },
    },
};
