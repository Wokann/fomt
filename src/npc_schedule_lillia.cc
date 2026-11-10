#include "npc_schedule_lillia.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectLilliaSchedule\n"
    "SelectLilliaSchedule:\n"
    "    push\t{r4, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr2, r0, #0\n"
    "    ldr r1, .Ljp_0803D8F0\n"
    "    adds\tr0, r2, r1\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    movs\tr0, #12\n"
    "    ands\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D8F4\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803D91E\n"
    ".Ljp_0803D8F0: .word 0x000021CA\n"
    ".Ljp_0803D8F4:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r2, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D914\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803D91E\n"
    ".Ljp_0803D914:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803D91C\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803D91E\n"
    ".Ljp_0803D91C:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803D91E:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

// Recovered schedule data at US ROM 0x080F280C (JP 0x080F2068).
// The two regional payloads differ only in relocated function/data pointers.

ScheduleInfo const gUnk_080F2068 = {
    SelectLilliaSchedule,
    4,
    gUnk_080F2818,
};

Schedule const * const gUnk_080F2818[] = {
    nullptr, &gUnk_080F2828, &gUnk_080F2830, &gUnk_080F2838,
};

Schedule const gUnk_080F2828 = { 3, gUnk_080F2840 };
Schedule const gUnk_080F2830 = { 8, gUnk_080F2858 };
Schedule const gUnk_080F2838 = { 1, gUnk_080F2898 };

ScheduleEntry const gUnk_080F2840[] = {
    { 0, &gUnk_080F28A0 },
    { 300, &gUnk_080F28AC },
    { 780, &gUnk_080F28A0 },
};

ScheduleEntry const gUnk_080F2858[] = {
    { 0, &gUnk_080F28A0 },
    { 300, &gUnk_080F28AC },
    { 421, &gUnk_080F28B8 },
    { 468, &gUnk_080F28C4 },
    { 507, &gUnk_080F28D0 },
    { 600, &gUnk_080F28DC },
    { 640, &gUnk_080F28E8 },
    { 687, &gUnk_080F28A0 },
};

ScheduleEntry const gUnk_080F2898[] = {
    { 0, &gUnk_080F28A0 },
};

PathInfo const gUnk_080F28A0 = {
    nullptr,
    0,
    112,
    130,
    11,
    3,
    0,
};

PathInfo const gUnk_080F28AC = {
    nullptr,
    0,
    215,
    160,
    10,
    2,
    0,
};

PathInfo const gUnk_080F28B8 = {
    (void const *)gUnk_080F28F4,
    7,
    572,
    227,
    7,
    0,
    0,
};

PathInfo const gUnk_080F28C4 = {
    (void const *)gUnk_080F292C,
    5,
    1260,
    704,
    5,
    0,
    0,
};

PathInfo const gUnk_080F28D0 = {
    nullptr,
    0,
    40,
    246,
    19,
    3,
    0,
};

PathInfo const gUnk_080F28DC = {
    (void const *)gUnk_080F2954,
    5,
    856,
    164,
    5,
    0,
    0,
};

PathInfo const gUnk_080F28E8 = {
    (void const *)gUnk_080F297C,
    7,
    1272,
    0,
    7,
    0,
    0,
};

PathPointA const gUnk_080F28F4[] = {
    { 1, 248, 1 },
    { 5, 472, 0 },
    { 9, 152, 1 },
    { 40, 1248, 0 },
    { 41, 128, 1 },
    { 42, 1272, 0 },
    { 47, 0, 1 },
};

PathPointA const gUnk_080F292C[] = {
    { 19, 240, 1 },
    { 20, 1248, 0 },
    { 21, 216, 1 },
    { 37, 856, 0 },
    { 39, 164, 1 },
};

PathPointA const gUnk_080F2954[] = {
    { 2, 216, 1 },
    { 18, 1248, 0 },
    { 19, 240, 1 },
    { 20, 1260, 0 },
    { 40, 736, 1 },
};

PathPointA const gUnk_080F297C[] = {
    { 5, 128, 1 },
    { 6, 1248, 0 },
    { 7, 152, 1 },
    { 38, 472, 0 },
    { 42, 248, 1 },
    { 46, 572, 0 },
    { 47, 227, 1 },
};
