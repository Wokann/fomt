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

ScheduleInfo const ScheduleInfo_Unk_080F286C = {
    SelectDoctorSchedule,
    5,
    gUnk_080F301C,
};

Schedule const * const gUnk_080F301C[] = {
    nullptr, &gUnk_080F3030, &gUnk_080F3038, &gUnk_080F3040,
    &gUnk_080F3048,
};

Schedule const gUnk_080F3030 = { 3, gUnk_080F3050 };
Schedule const gUnk_080F3038 = { 12, gUnk_080F3068 };
Schedule const gUnk_080F3040 = { 10, gUnk_080F30C8 };
Schedule const gUnk_080F3048 = { 1, gUnk_080F3118 };

ScheduleEntry const gUnk_080F3050[] = {
    { 0, &gUnk_080F3120 },
    { 180, &gUnk_080F312C },
    { 780, &gUnk_080F3120 },
};

ScheduleEntry const gUnk_080F3068[] = {
    { 0, &gUnk_080F3120 },
    { 60, &gUnk_080F3138 },
    { 100, &gUnk_080F3144 },
    { 147, &gUnk_080F3150 },
    { 240, &gUnk_080F315C },
    { 288, &gUnk_080F3168 },
    { 327, &gUnk_080F312C },
    { 420, &gUnk_080F3174 },
    { 447, &gUnk_080F3180 },
    // JP stores these two schedule times one minute earlier.
#if defined(REGION_JP)
    { 600, &gUnk_080F318C },
    { 627, &gUnk_080F312C },
#else
    { 601, &gUnk_080F318C },
    { 628, &gUnk_080F312C },
#endif
    { 960, &gUnk_080F3120 },
};

ScheduleEntry const gUnk_080F30C8[] = {
    { 0, &gUnk_080F3120 },
    { 60, &gUnk_080F3198 },
    { 79, &gUnk_080F31A4 },
    { 240, &gUnk_080F31B0 },
    { 259, &gUnk_080F312C },
    { 420, &gUnk_080F3174 },
    { 447, &gUnk_080F3180 },
    // JP stores these two schedule times one minute earlier.
#if defined(REGION_JP)
    { 600, &gUnk_080F318C },
    { 627, &gUnk_080F312C },
#else
    { 601, &gUnk_080F318C },
    { 628, &gUnk_080F312C },
#endif
    { 960, &gUnk_080F3120 },
};

ScheduleEntry const gUnk_080F3118[] = {
    { 0, &gUnk_080F3120 },
};

PathInfo const gUnk_080F3120 = {
    (void const *)gUnk_080F31BC,
    4,
    192,
    208,
    20,
    0,
    1,
};

PathInfo const gUnk_080F312C = {
    nullptr,
    0,
    248,
    91,
    19,
    0,
    0,
};

PathInfo const gUnk_080F3138 = {
    (void const *)gUnk_080F31DC,
    5,
    856,
    164,
    5,
    0,
    0,
};

PathInfo const gUnk_080F3144 = {
    (void const *)gUnk_080F3204,
    16,
    1200,
    752,
    0,
    0,
    0,
};

PathInfo const gUnk_080F3150 = {
    (void const *)gUnk_080F3284,
    4,
    256,
    488,
    0,
    0,
    1,
};

PathInfo const gUnk_080F315C = {
    (void const *)gUnk_080F32A4,
    16,
    256,
    488,
    0,
    0,
    0,
};

PathInfo const gUnk_080F3168 = {
    (void const *)gUnk_080F3324,
    5,
    1260,
    704,
    5,
    0,
    0,
};

PathInfo const gUnk_080F3174 = {
    (void const *)gUnk_080F334C,
    3,
    856,
    164,
    5,
    0,
    0,
};

PathInfo const gUnk_080F3180 = {
    nullptr,
    0,
    144,
    144,
    25,
    1,
    0,
};

PathInfo const gUnk_080F318C = {
    (void const *)gUnk_080F3364,
    3,
    276,
    168,
    5,
    0,
    0,
};

PathInfo const gUnk_080F3198 = {
    (void const *)gUnk_080F337C,
    3,
    856,
    164,
    5,
    0,
    0,
};

PathInfo const gUnk_080F31A4 = {
    nullptr,
    0,
    296,
    155,
    12,
    1,
    0,
};

PathInfo const gUnk_080F31B0 = {
    (void const *)gUnk_080F3394,
    3,
    1232,
    156,
    5,
    0,
    0,
};

PathPointB const gUnk_080F31BC[] = {
    { 72, 2, 120, 2, 0 },
    { 227, 2, 120, 0, 1 },
    { 192, 2, 120, 3, 0 },
    { 208, 2, 120, 2, 1 },
};

PathPointA const gUnk_080F31DC[] = {
    { 2, 216, 1 },
    { 18, 1248, 0 },
    { 19, 240, 1 },
    { 20, 1260, 0 },
    { 40, 736, 1 },
};

PathPointA const gUnk_080F3204[] = {
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
};

PathPointB const gUnk_080F3284[] = {
    { 216, 2, 0, 0, 0 },
    { 552, 2, 120, 0, 1 },
    { 488, 2, 0, 0, 1 },
    { 256, 2, 120, 3, 0 },
};

PathPointA const gUnk_080F32A4[] = {
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
};

PathPointA const gUnk_080F3324[] = {
    { 19, 240, 1 },
    { 20, 1248, 0 },
    { 21, 216, 1 },
    { 37, 856, 0 },
    { 39, 164, 1 },
};

PathPointA const gUnk_080F334C[] = {
    { 2, 216, 1 },
    { 25, 276, 0 },
    { 27, 168, 1 },
};

PathPointA const gUnk_080F3364[] = {
    { 2, 216, 1 },
    { 25, 856, 0 },
    { 27, 164, 1 },
};

PathPointA const gUnk_080F337C[] = {
    { 2, 216, 1 },
    { 17, 1232, 0 },
    { 19, 156, 1 },
};

PathPointA const gUnk_080F3394[] = {
    { 2, 216, 1 },
    { 17, 856, 0 },
    { 19, 164, 1 },
};
