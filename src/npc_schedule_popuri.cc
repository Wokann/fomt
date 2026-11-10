#include "npc_schedule_popuri.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectPopuriSchedule\n"
    "SelectPopuriSchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r9\n"
    "    mov\tr6, r8\n"
    "    push\t{r6, r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803D73C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803D70A\n"
    "    b .Ljp_0803D896\n"
    ".Ljp_0803D70A:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr7, [r4, #1]\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    mov\tr8, r0\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    mov\tr9, r4\n"
    "    ldr r1, .Ljp_0803D740\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetSpouseCharacterId__C13NpcCollection\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #3\n"
    "    bne .Ljp_0803D7DE\n"
    "    cmp\tr7, #2\n"
    "    bne .Ljp_0803D744\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #13\n"
    "    bne .Ljp_0803D744\n"
    "    movs\tr0, #22\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D73C: .word 0x000021CA\n"
    ".Ljp_0803D740: .word 0x00001CD4\n"
    ".Ljp_0803D744:\n"
    "    ldr r1, .Ljp_0803D758\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803D75C\n"
    "    movs\tr0, #23\n"
    "    b .Ljp_0803D8C8\n"
    "    .align 2, 0\n"
    ".Ljp_0803D758: .word 0x0000216B\n"
    ".Ljp_0803D75C:\n"
    "    ldr r1, .Ljp_0803D794\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr6, [r0, #0]\n"
    "    ldr r1, .Ljp_0803D798\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetChild__C13NpcCollection\n"
    "    negs\tr1, r0\n"
    "    orrs\tr1, r0\n"
    "    lsrs\tr4, r1, #31\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D788\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803D788\n"
    "    cmp\tr0, #4\n"
    "    bne .Ljp_0803D7AC\n"
    ".Ljp_0803D788:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803D7A0\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D79C\n"
    "    movs\tr0, #13\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D794: .word 0x00002148\n"
    ".Ljp_0803D798: .word 0x00001CD4\n"
    ".Ljp_0803D79C:\n"
    "    movs\tr0, #12\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7A0:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D7A8\n"
    "    movs\tr0, #15\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7A8:\n"
    "    movs\tr0, #14\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7AC:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D7C2\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D7C2\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803D7BE\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7BE:\n"
    "    movs\tr0, #11\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7C2:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803D7D2\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D7CE\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7CE:\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7D2:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803D7DA\n"
    "    movs\tr0, #10\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7DA:\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D7DE:\n"
    "    ldr r1, .Ljp_0803D800\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetRivalEventCount__C12Bachelorette\n"
    "    cmp\tr0, #4\n"
    "    bls .Ljp_0803D812\n"
    "    cmp\tr7, #1\n"
    "    bne .Ljp_0803D896\n"
    "    movs\tr0, #1\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D804\n"
    "    movs\tr0, #19\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D800: .word 0x00001D6C\n"
    ".Ljp_0803D804:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D80E\n"
    "    movs\tr0, #20\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D80E:\n"
    "    movs\tr0, #21\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D812:\n"
    "    cmp\tr7, #2\n"
    "    bne .Ljp_0803D834\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #30\n"
    "    bne .Ljp_0803D834\n"
    "    ldr r1, .Ljp_0803D830\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803D834\n"
    "    movs\tr0, #17\n"
    "    b .Ljp_0803D8C8\n"
    "    .align 2, 0\n"
    ".Ljp_0803D830: .word 0x000021A3\n"
    ".Ljp_0803D834:\n"
    "    ldr r1, .Ljp_0803D86C\n"
    "    adds\tr0, r5, r1\n"
    "    movs\tr1, #3\n"
    "    bl GetBachelorette__C13NpcCollectionUi\n"
    "    cmp\tr7, #3\n"
    "    bne .Ljp_0803D878\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #14\n"
    "    bne .Ljp_0803D878\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_0803D878\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D878\n"
    "    bl GetLove__C12Bachelorette\n"
    "    ldr r1, .Ljp_0803D870\n"
    "    cmp\tr0, r1\n"
    "    bls .Ljp_0803D878\n"
    "    ldr r1, .Ljp_0803D874\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803D878\n"
    "    movs\tr0, #18\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D86C: .word 0x00001CD4\n"
    ".Ljp_0803D870: .word 0x0000270F\n"
    ".Ljp_0803D874: .word 0x000021A3\n"
    ".Ljp_0803D878:\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r8\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D88A\n"
    "    movs\tr0, #16\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D88A:\n"
    "    ldr r1, .Ljp_0803D89C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #28\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803D8A0\n"
    ".Ljp_0803D896:\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803D8C8\n"
    "    .align 2, 0\n"
    ".Ljp_0803D89C: .word 0x0000215A\n"
    ".Ljp_0803D8A0:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D8BC\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803D8B8\n"
    "    cmp\tr7, #1\n"
    "    bne .Ljp_0803D8B4\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D8B4:\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D8B8:\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D8BC:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803D8C6\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803D8C8\n"
    ".Ljp_0803D8C6:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803D8C8:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3, r4}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

// Recovered schedule data at US ROM 0x080F1FC0 (JP 0x080F181C).
// The two regional payloads differ only in relocated function/data pointers.

ScheduleInfo const gUnk_080F1FC0 = {
    SelectPopuriSchedule,
    24,
    gUnk_080F1FCC,
};

Schedule const * const gUnk_080F1FCC[] = {
    nullptr, &gUnk_080F202C, &gUnk_080F2034, &gUnk_080F203C,
    &gUnk_080F2044, &gUnk_080F204C, &gUnk_080F2054, &gUnk_080F205C,
    &gUnk_080F2064, &gUnk_080F206C, &gUnk_080F2074, &gUnk_080F207C,
    &gUnk_080F2084, &gUnk_080F208C, &gUnk_080F2094, &gUnk_080F209C,
    &gUnk_080F20A4, &gUnk_080F20AC, &gUnk_080F20B4, &gUnk_080F20BC,
    &gUnk_080F20C4, &gUnk_080F20CC, &gUnk_080F20D4, &gUnk_080F20DC,
};

Schedule const gUnk_080F202C = { 8, gUnk_080F20E4 };
Schedule const gUnk_080F2034 = { 2, gUnk_080F2124 };
Schedule const gUnk_080F203C = { 11, gUnk_080F2134 };
Schedule const gUnk_080F2044 = { 8, gUnk_080F218C };
Schedule const gUnk_080F204C = { 8, gUnk_080F21CC };
Schedule const gUnk_080F2054 = { 4, gUnk_080F220C };
Schedule const gUnk_080F205C = { 4, gUnk_080F222C };
Schedule const gUnk_080F2064 = { 4, gUnk_080F224C };
Schedule const gUnk_080F206C = { 4, gUnk_080F226C };
Schedule const gUnk_080F2074 = { 4, gUnk_080F228C };
Schedule const gUnk_080F207C = { 4, gUnk_080F22AC };
Schedule const gUnk_080F2084 = { 4, gUnk_080F22CC };
Schedule const gUnk_080F208C = { 4, gUnk_080F22EC };
Schedule const gUnk_080F2094 = { 4, gUnk_080F230C };
Schedule const gUnk_080F209C = { 4, gUnk_080F232C };
Schedule const gUnk_080F20A4 = { 1, gUnk_080F234C };
Schedule const gUnk_080F20AC = { 5, gUnk_080F2354 };
Schedule const gUnk_080F20B4 = { 4, gUnk_080F237C };
Schedule const gUnk_080F20BC = { 1, gUnk_080F239C };
Schedule const gUnk_080F20C4 = { 8, gUnk_080F23A4 };
Schedule const gUnk_080F20CC = { 2, gUnk_080F23E4 };
Schedule const gUnk_080F20D4 = { 3, gUnk_080F23F4 };
Schedule const gUnk_080F20DC = { 1, gUnk_080F240C };

ScheduleEntry const gUnk_080F20E4[] = {
    { 0, &gUnk_080F2414 },
    { 60, &gUnk_080F2420 },
    { 98, &gUnk_080F242C },
    { 113, &gUnk_080F2438 },
    { 240, &gUnk_080F2444 },
    { 256, &gUnk_080F2450 },
    { 293, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F2124[] = {
    { 0, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F2134[] = {
    { 0, &gUnk_080F2414 },
    { 180, &gUnk_080F2468 },
    { 227, &gUnk_080F2474 },
    { 251, &gUnk_080F2480 },
    { 421, &gUnk_080F248C },
    { 446, &gUnk_080F2498 },
    { 462, &gUnk_080F24A4 },
    { 600, &gUnk_080F24B0 },
    { 608, &gUnk_080F24BC },
    { 655, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F218C[] = {
    { 0, &gUnk_080F2414 },
    { 180, &gUnk_080F2468 },
    { 227, &gUnk_080F2474 },
    { 251, &gUnk_080F2480 },
    { 600, &gUnk_080F248C },
    { 625, &gUnk_080F24BC },
    { 672, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F21CC[] = {
    { 0, &gUnk_080F2414 },
    { 420, &gUnk_080F2468 },
    { 467, &gUnk_080F24C8 },
    { 486, &gUnk_080F24D4 },
    { 600, &gUnk_080F24E0 },
    { 620, &gUnk_080F24BC },
    { 667, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F220C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F222C[] = {
    { 0, &gUnk_080F24EC },
    { 180, &gUnk_080F2414 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F224C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F226C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F228C[] = {
    { 0, &gUnk_080F24EC },
    { 180, &gUnk_080F2414 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F22AC[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F22CC[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F22EC[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F230C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F232C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F234C[] = {
    { 0, &gUnk_080F2414 },
};

ScheduleEntry const gUnk_080F2354[] = {
    { 0, &gUnk_080F2414 },
    { 240, &gUnk_080F2528 },
    { 250, &gUnk_080F2510 },
    { 300, &gUnk_080F251C },
    { 310, &gUnk_080F2414 },
};

ScheduleEntry const gUnk_080F237C[] = {
    { 0, &gUnk_080F2528 },
    { 10, &gUnk_080F2510 },
    { 60, &gUnk_080F251C },
    { 70, &gUnk_080F2414 },
};

ScheduleEntry const gUnk_080F239C[] = {
    { 0, &gUnk_080F2414 },
};

ScheduleEntry const gUnk_080F23A4[] = {
    { 0, &gUnk_080F2414 },
    { 120, &gUnk_080F2468 },
    { 167, &gUnk_080F24C8 },
    { 186, &gUnk_080F24D4 },
    { 240, &gUnk_080F24E0 },
    { 260, &gUnk_080F24BC },
    { 307, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F23E4[] = {
    { 0, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F23F4[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F2534 },
};

ScheduleEntry const gUnk_080F240C[] = {
    { 0, &gUnk_080F2504 },
};

PathInfo const gUnk_080F2414 = {
    (void const *)gUnk_080F2540,
    2,
    168,
    104,
    10,
    0,
    1,
};

PathInfo const gUnk_080F2420 = {
    (void const *)gUnk_080F2550,
    5,
    572,
    227,
    7,
    0,
    0,
};

PathInfo const gUnk_080F242C = {
    (void const *)gUnk_080F2578,
    8,
    1200,
    528,
    0,
    0,
    0,
};

PathInfo const gUnk_080F2438 = {
    (void const *)gUnk_080F25B8,
    4,
    984,
    416,
    0,
    0,
    1,
};

PathInfo const gUnk_080F2444 = {
    (void const *)gUnk_080F25D8,
    8,
    984,
    416,
    0,
    0,
    0,
};

PathInfo const gUnk_080F2450 = {
    (void const *)gUnk_080F2618,
    5,
    812,
    512,
    7,
    0,
    0,
};

PathInfo const gUnk_080F245C = {
    (void const *)gUnk_080F2640,
    2,
    168,
    72,
    11,
    0,
    1,
};

PathInfo const gUnk_080F2468 = {
    (void const *)gUnk_080F2650,
    7,
    572,
    227,
    7,
    0,
    0,
};

PathInfo const gUnk_080F2474 = {
    (void const *)gUnk_080F2688,
    5,
    1260,
    704,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2480 = {
    (void const *)gUnk_080F26B0,
    2,
    248,
    88,
    12,
    0,
    1,
};

PathInfo const gUnk_080F248C = {
    (void const *)gUnk_080F26C0,
    5,
    1232,
    156,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2498 = {
    (void const *)gUnk_080F26E8,
    2,
    220,
    0,
    6,
    0,
    0,
};

PathInfo const gUnk_080F24A4 = {
    (void const *)gUnk_080F26F8,
    2,
    280,
    352,
    6,
    0,
    1,
};

PathInfo const gUnk_080F24B0 = {
    (void const *)gUnk_080F2708,
    2,
    280,
    352,
    6,
    0,
    0,
};

PathInfo const gUnk_080F24BC = {
    (void const *)gUnk_080F2718,
    7,
    1272,
    0,
    7,
    0,
    0,
};

PathInfo const gUnk_080F24C8 = {
    (void const *)gUnk_080F2750,
    5,
    0,
    280,
    1,
    0,
    0,
};

PathInfo const gUnk_080F24D4 = {
    nullptr,
    0,
    256,
    232,
    1,
    3,
    0,
};

PathInfo const gUnk_080F24E0 = {
    (void const *)gUnk_080F2778,
    5,
    256,
    232,
    1,
    0,
    0,
};

PathInfo const gUnk_080F24EC = {
    (void const *)gUnk_080F27A0,
    4,
    256,
    152,
    29,
    0,
    1,
};

PathInfo const gUnk_080F24F8 = {
    (void const *)gUnk_080F27C0,
    4,
    112,
    76,
    29,
    0,
    1,
};

PathInfo const gUnk_080F2504 = {
    nullptr,
    0,
    440,
    -48,
    29,
    0,
    0,
};

PathInfo const gUnk_080F2510 = {
    nullptr,
    0,
    228,
    145,
    2,
    1,
    0,
};

PathInfo const gUnk_080F251C = {
    (void const *)gUnk_080F27E0,
    2,
    228,
    145,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2528 = {
    (void const *)gUnk_080F27F0,
    2,
    340,
    0,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2534 = {
    nullptr,
    0,
    0,
    0,
    564,
    1,
    0,
};

PathPointB const gUnk_080F2540[] = {
    { 224, 2, 120, 3, 0 },
    { 168, 2, 120, 2, 0 },
};

PathPointA const gUnk_080F2550[] = {
    { 1, 248, 1 },
    { 5, 472, 0 },
    { 9, 152, 1 },
    { 23, 812, 0 },
    { 38, 544, 1 },
};

PathPointA const gUnk_080F2578[] = {
    { 1, 1176, 0 },
    { 2, 512, 1 },
    { 3, 1160, 0 },
    { 4, 496, 1 },
    { 5, 1144, 0 },
    { 6, 480, 1 },
    { 12, 984, 0 },
    { 15, 416, 1 },
};

PathPointB const gUnk_080F25B8[] = {
    { 944, 2, 0, 0, 0 },
    { 374, 2, 120, 3, 1 },
    { 416, 2, 0, 0, 1 },
    { 984, 2, 120, 1, 0 },
};

PathPointA const gUnk_080F25D8[] = {
    { 3, 480, 1 },
    { 9, 1144, 0 },
    { 10, 496, 1 },
    { 11, 1160, 0 },
    { 12, 512, 1 },
    { 13, 1176, 0 },
    { 14, 528, 1 },
    { 16, 1216, 0 },
};

PathPointA const gUnk_080F2618[] = {
    { 14, 152, 1 },
    { 28, 472, 0 },
    { 32, 248, 1 },
    { 36, 572, 0 },
    { 37, 227, 1 },
};

PathPointB const gUnk_080F2640[] = {
    { 138, 2, 120, 1, 1 },
    { 72, 2, 120, 0, 1 },
};

PathPointA const gUnk_080F2650[] = {
    { 1, 248, 1 },
    { 5, 472, 0 },
    { 9, 152, 1 },
    { 40, 1248, 0 },
    { 41, 128, 1 },
    { 42, 1272, 0 },
    { 47, 0, 1 },
};

PathPointA const gUnk_080F2688[] = {
    { 19, 240, 1 },
    { 20, 1248, 0 },
    { 21, 216, 1 },
    { 22, 1232, 0 },
    { 24, 156, 1 },
};

PathPointB const gUnk_080F26B0[] = {
    { 280, 2, 120, 3, 0 },
    { 248, 2, 120, 2, 0 },
};

PathPointA const gUnk_080F26C0[] = {
    { 2, 216, 1 },
    { 3, 1248, 0 },
    { 4, 240, 1 },
    { 5, 1260, 0 },
    { 25, 736, 1 },
};

PathPointA const gUnk_080F26E8[] = {
    { 14, 352, 1 },
    { 16, 280, 0 },
};

PathPointB const gUnk_080F26F8[] = {
    { 344, 2, 120, 3, 0 },
    { 280, 2, 120, 2, 0 },
};

PathPointA const gUnk_080F2708[] = {
    { 3, 220, 0 },
    { 8, 480, 1 },
};

PathPointA const gUnk_080F2718[] = {
    { 5, 128, 1 },
    { 6, 1248, 0 },
    { 7, 152, 1 },
    { 38, 472, 0 },
    { 42, 248, 1 },
    { 46, 572, 0 },
    { 47, 227, 1 },
};

PathPointA const gUnk_080F2750[] = {
    { 3, 64, 0 },
    { 6, 360, 1 },
    { 8, 104, 0 },
    { 13, 232, 1 },
    { 19, 256, 0 },
};

PathPointA const gUnk_080F2778[] = {
    { 6, 104, 0 },
    { 11, 360, 1 },
    { 13, 64, 0 },
    { 16, 280, 1 },
    { 20, -16, 0 },
};

PathPointB const gUnk_080F27A0[] = {
    { 96, 2, 0, 0, 1 },
    { 328, 2, 120, 3, 0 },
    { 256, 2, 0, 0, 0 },
    { 152, 2, 120, 0, 1 },
};

PathPointB const gUnk_080F27C0[] = {
    { 108, 2, 120, 2, 1 },
    { 128, 2, 120, 3, 0 },
    { 76, 2, 120, 3, 1 },
    { 112, 2, 120, 2, 0 },
};

PathPointA const gUnk_080F27E0[] = {
    { 4, 340, 0 },
    { 10, 0, 1 },
};

PathPointA const gUnk_080F27F0[] = {
    { 6, 145, 1 },
    { 10, 228, 0 },
};
