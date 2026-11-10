#include "npc_schedule_cliff.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectCliffSchedule\n"
    "SelectCliffSchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r8\n"
    "    push\t{r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803DABC\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_0803DAB6\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    mov\tr0, sp\n"
    "    ldrb\tr6, [r0, #0]\n"
    "    ldrb\tr7, [r4, #1]\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    mov\tr8, r0\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    ldr r1, .Ljp_0803DAC0\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803DAB6\n"
    "    subs\tr1, #12\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_0803DAC4\n"
    "    cmp\tr6, #1\n"
    "    bhi .Ljp_0803DAB6\n"
    "    cmp\tr6, #1\n"
    "    bne .Ljp_0803DAC4\n"
    "    cmp\tr7, #3\n"
    "    bne .Ljp_0803DAC4\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #28\n"
    "    bls .Ljp_0803DAC4\n"
    ".Ljp_0803DAB6:\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803DB32\n"
    "    .align 2, 0\n"
    ".Ljp_0803DABC: .word 0x000021CA\n"
    ".Ljp_0803DAC0: .word 0x00002181\n"
    ".Ljp_0803DAC4:\n"
    "    ldr r1, .Ljp_0803DAD8\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803DADC\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803DB32\n"
    "    .align 2, 0\n"
    ".Ljp_0803DAD8: .word 0x00002181\n"
    ".Ljp_0803DADC:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DAEE\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803DB32\n"
    ".Ljp_0803DAEE:\n"
    "    cmp\tr6, #1\n"
    "    bne .Ljp_0803DB10\n"
    "    cmp\tr7, #2\n"
    "    bne .Ljp_0803DB10\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #15\n"
    "    bne .Ljp_0803DB10\n"
    "    ldr r1, .Ljp_0803DB0C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803DB10\n"
    ".Ljp_0803DB08:\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803DB32\n"
    ".Ljp_0803DB0C: .word 0x00002175\n"
    ".Ljp_0803DB10:\n"
    "    ldr r1, .Ljp_0803DB2C\n"
    "    adds\tr0, r5, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    movs\tr1, #194\t@ 0xc2\n"
    "    lsls\tr1, r1, #11\n"
    "    ands\tr0, r1\n"
    "    movs\tr1, #130\t@ 0x82\n"
    "    lsls\tr1, r1, #11\n"
    "    cmp\tr0, r1\n"
    "    bne .Ljp_0803DB30\n"
    "    cmp\tr4, #6\n"
    "    bne .Ljp_0803DB08\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803DB32\n"
    ".Ljp_0803DB2C: .word 0x00002174\n"
    ".Ljp_0803DB30:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803DB32:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

// Recovered schedule data at US ROM 0x080F2AF8 (JP 0x080F2354).
// The two regional payloads differ only in relocated function/data pointers.

ScheduleInfo const ScheduleInfo_Unk_080F2354 = {
    SelectCliffSchedule,
    6,
    gUnk_080F2B04,
};

Schedule const * const gUnk_080F2B04[] = {
    nullptr, &gUnk_080F2B1C, &gUnk_080F2B24, &gUnk_080F2B2C,
    &gUnk_080F2B34, &gUnk_080F2B3C,
};

Schedule const gUnk_080F2B1C = { 5, gUnk_080F2B44 };
Schedule const gUnk_080F2B24 = { 9, gUnk_080F2B6C };
Schedule const gUnk_080F2B2C = { 6, gUnk_080F2BB4 };
Schedule const gUnk_080F2B34 = { 1, gUnk_080F2BE4 };
Schedule const gUnk_080F2B3C = { 1, gUnk_080F2BEC };

ScheduleEntry const gUnk_080F2B44[] = {
    { 0, &gUnk_080F2BF4 },
    { 180, &gUnk_080F2C00 },
    { 224, &gUnk_080F2C0C },
    { 605, &gUnk_080F2C18 },
    { 646, &gUnk_080F2BF4 },
};

ScheduleEntry const gUnk_080F2B6C[] = {
    { 0, &gUnk_080F2BF4 },
    { 240, &gUnk_080F2C24 },
    { 265, &gUnk_080F2C30 },
    { 420, &gUnk_080F2C3C },
    { 427, &gUnk_080F2C48 },
    { 600, &gUnk_080F2C54 },
    { 667, &gUnk_080F2C0C },
    { 783, &gUnk_080F2C18 },
    { 824, &gUnk_080F2BF4 },
};

ScheduleEntry const gUnk_080F2BB4[] = {
    { 0, &gUnk_080F2BF4 },
    { 420, &gUnk_080F2C60 },
    { 611, &gUnk_080F2C00 },
    { 655, &gUnk_080F2C0C },
    { 780, &gUnk_080F2C6C },
    { 824, &gUnk_080F2BF4 },
};

ScheduleEntry const gUnk_080F2BE4[] = {
    { 0, &gUnk_080F2BF4 },
};

ScheduleEntry const gUnk_080F2BEC[] = {
    { 0, &gUnk_080F2C78 },
};

PathInfo const gUnk_080F2BF4 = {
    nullptr,
    0,
    272,
    72,
    23,
    0,
    0,
};

PathInfo const gUnk_080F2C00 = {
    (void const *)gUnk_080F2C84,
    7,
    632,
    488,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C0C = {
    nullptr,
    0,
    104,
    155,
    12,
    1,
    0,
};

PathInfo const gUnk_080F2C18 = {
    (void const *)gUnk_080F2CBC,
    5,
    1232,
    156,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C24 = {
    (void const *)gUnk_080F2CE4,
    7,
    632,
    488,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C30 = {
    (void const *)gUnk_080F2D1C,
    2,
    176,
    88,
    34,
    0,
    1,
};

PathInfo const gUnk_080F2C3C = {
    (void const *)gUnk_080F2D2C,
    2,
    314,
    456,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C48 = {
    nullptr,
    0,
    456,
    476,
    5,
    1,
    0,
};

PathInfo const gUnk_080F2C54 = {
    (void const *)gUnk_080F2D3C,
    8,
    456,
    476,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C60 = {
    nullptr,
    0,
    64,
    136,
    21,
    0,
    0,
};

PathInfo const gUnk_080F2C6C = {
    (void const *)gUnk_080F2D7C,
    7,
    1232,
    160,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C78 = {
    nullptr,
    0,
    432,
    232,
    19,
    0,
    0,
};

PathPointA const gUnk_080F2C84[] = {
    { 2, 536, 1 },
    { 27, 1260, 0 },
    { 39, 240, 1 },
    { 40, 1248, 0 },
    { 41, 216, 1 },
    { 42, 1232, 0 },
    { 44, 156, 1 },
};

PathPointA const gUnk_080F2CBC[] = {
    { 2, 216, 1 },
    { 19, 808, 0 },
    { 32, 536, 1 },
    { 39, 632, 0 },
    { 41, 488, 1 },
};

PathPointA const gUnk_080F2CE4[] = {
    { 2, 536, 1 },
    { 18, 232, 0 },
    { 20, 480, 1 },
    { 21, 265, 0 },
    { 22, 476, 1 },
    { 24, 316, 0 },
    { 25, 460, 1 },
};

PathPointB const gUnk_080F2D1C[] = {
    { 208, 2, 120, 1, 0 },
    { 176, 2, 120, 1, 0 },
};

PathPointA const gUnk_080F2D2C[] = {
    { 1, 476, 1 },
    { 7, 456, 0 },
};

PathPointA const gUnk_080F2D3C[] = {
    { 8, 265, 0 },
    { 9, 496, 1 },
    { 10, 232, 0 },
    { 12, 536, 1 },
    { 35, 808, 0 },
    { 48, 216, 1 },
    { 65, 1232, 0 },
    { 67, 156, 1 },
};

PathPointA const gUnk_080F2D7C[] = {
    { 2, 216, 1 },
    { 3, 1248, 0 },
    { 4, 240, 1 },
    { 5, 1260, 0 },
    { 17, 536, 1 },
    { 42, 632, 0 },
    { 44, 488, 1 },
};
