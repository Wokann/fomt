#include "npc_schedule_zack.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectZackSchedule\n"
    "SelectZackSchedule:\n"
    "    push\t{r4, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr1, r0, #0\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DB62\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803DB64\n"
    ".Ljp_0803DB62:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803DB64:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
);

// Recovered schedule data at US ROM 0x080F2DC0 (JP 0x080F261C).
// The two regional payloads differ only in relocated function/data pointers.

ScheduleInfo const ScheduleInfo_Unk_080F261C = {
    SelectZackSchedule,
    3,
    gUnk_080F2DCC,
};

Schedule const * const gUnk_080F2DCC[] = {
    nullptr, &gUnk_080F2DD8, &gUnk_080F2DE0,
};

Schedule const gUnk_080F2DD8 = { 15, gUnk_080F2DE8 };
Schedule const gUnk_080F2DE0 = { 1, gUnk_080F2E60 };

// The original JP gUnk_080F3010 label starts at entry 6 of this table.
ScheduleEntry const gUnk_080F2DE8[] = {
    { 0, &gUnk_080F2E68 },
    { 60, &gUnk_080F2E74 },
    { 82, &gUnk_080F2E80 },
    { 127, &gUnk_080F2E8C },
    { 240, &gUnk_080F2E98 },
};

ScheduleEntry const gUnk_080F3010[] = {
    { 286, &gUnk_080F2EA4 },
    { 308, &gUnk_080F2E68 },
    { 630, &gUnk_080F2E74 },
    { 652, &gUnk_080F2EB0 },
    { 663, &gUnk_080F2EBC },
    { 720, &gUnk_080F2EC8 },
    { 731, &gUnk_080F2ED4 },
    { 786, &gUnk_080F2EE0 },
    { 833, &gUnk_080F2EA4 },
    { 855, &gUnk_080F2E68 },
};

ScheduleEntry const gUnk_080F2E60[] = {
    { 0, &gUnk_080F2E68 },
};

PathInfo const gUnk_080F2E68 = {
    (void const *)gUnk_080F2EEC,
    2,
    176,
    88,
    13,
    0,
    1,
};

PathInfo const gUnk_080F2E74 = {
    (void const *)gUnk_080F2EFC,
    6,
    212,
    108,
    1,
    0,
    0,
};

PathInfo const gUnk_080F2E80 = {
    (void const *)gUnk_080F2F2C,
    5,
    1260,
    704,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2E8C = {
    nullptr,
    0,
    232,
    264,
    15,
    2,
    0,
};

PathInfo const gUnk_080F2E98 = {
    (void const *)gUnk_080F2F54,
    5,
    688,
    160,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2EA4 = {
    (void const *)gUnk_080F2F7C,
    6,
    0,
    280,
    1,
    0,
    0,
};

PathInfo const gUnk_080F2EB0 = {
    (void const *)gUnk_080F2FAC,
    3,
    340,
    0,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2EBC = {
    nullptr,
    0,
    244,
    171,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2EC8 = {
    (void const *)gUnk_080F2FC4,
    3,
    244,
    171,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2ED4 = {
    nullptr,
    0,
    88,
    88,
    38,
    0,
    0,
};

PathInfo const gUnk_080F2EE0 = {
    (void const *)gUnk_080F2FDC,
    5,
    296,
    116,
    7,
    0,
    0,
};

PathPointB const gUnk_080F2EEC[] = {
    { 128, 2, 120, 0, 0 },
    { 176, 2, 120, 0, 0 },
};

PathPointA const gUnk_080F2EFC[] = {
    { 1, 136, 1 },
    { 5, 104, 0 },
    { 14, 360, 1 },
    { 16, 64, 0 },
    { 19, 280, 1 },
    { 22, 0, 0 },
};

PathPointA const gUnk_080F2F2C[] = {
    { 19, 240, 1 },
    { 20, 1248, 0 },
    { 21, 216, 1 },
    { 43, 688, 0 },
    { 45, 160, 1 },
};

PathPointA const gUnk_080F2F54[] = {
    { 2, 216, 1 },
    { 24, 1248, 0 },
    { 25, 240, 1 },
    { 26, 1260, 0 },
    { 46, 736, 1 },
};

PathPointA const gUnk_080F2F7C[] = {
    { 3, 64, 0 },
    { 6, 360, 1 },
    { 8, 104, 0 },
    { 17, 136, 1 },
    { 21, 212, 0 },
    { 22, 108, 1 },
};

PathPointA const gUnk_080F2FAC[] = {
    { 6, 145, 1 },
    { 10, 244, 0 },
    { 11, 171, 1 },
};

PathPointA const gUnk_080F2FC4[] = {
    { 1, 145, 1 },
    { 5, 340, 0 },
    { 11, 0, 1 },
};

PathPointA const gUnk_080F2FDC[] = {
    { 2, 152, 1 },
    { 40, 1248, 0 },
    { 41, 128, 1 },
    { 42, 1272, 0 },
    { 47, 0, 1 },
};
