#include "npc_schedule_karen.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectKarenSchedule\n"
    "SelectKarenSchedule:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r9\n"
    "    mov\tr6, r8\n"
    "    push\t{r6, r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    ldr r1, .Ljp_0803DC7C\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    movs\tr0, #12\n"
    "    ands\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DC80\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803DE08\n"
    "    .align 2, 0\n"
    ".Ljp_0803DC7C: .word 0x000021CA\n"
    ".Ljp_0803DC80:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    mov\tr8, r0\n"
    "    ldrb\tr7, [r4, #2]\n"
    "    ldrb\tr4, [r4, #3]\n"
    "    mov\tr9, r4\n"
    "    ldr r1, .Ljp_0803DCB4\n"
    "    adds\tr4, r5, r1\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetSpouseCharacterId__C13NpcCollection\n"
    "    adds\tr6, r0, #0\n"
    "    cmp\tr6, #19\n"
    "    bne .Ljp_0803DD5E\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #2\n"
    "    bne .Ljp_0803DCC0\n"
    "    cmp\tr7, #9\n"
    "    bne .Ljp_0803DCB8\n"
    "    movs\tr0, #21\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DCB4: .word 0x00001CD4\n"
    ".Ljp_0803DCB8:\n"
    "    cmp\tr7, #13\n"
    "    bne .Ljp_0803DCC0\n"
    "    movs\tr0, #22\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DCC0:\n"
    "    ldr r1, .Ljp_0803DCD4\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #27\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    bne .Ljp_0803DCD8\n"
    "    movs\tr0, #23\n"
    "    b .Ljp_0803DE08\n"
    "    .align 2, 0\n"
    ".Ljp_0803DCD4: .word 0x0000216C\n"
    ".Ljp_0803DCD8:\n"
    "    ldr r1, .Ljp_0803DD10\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr6, [r0, #0]\n"
    "    ldr r1, .Ljp_0803DD14\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetChild__C13NpcCollection\n"
    "    negs\tr1, r0\n"
    "    orrs\tr1, r0\n"
    "    lsrs\tr4, r1, #31\n"
    "    mov\tr0, r8\n"
    "    adds\tr1, r7, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DD04\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803DD04\n"
    "    cmp\tr0, #4\n"
    "    bne .Ljp_0803DD28\n"
    ".Ljp_0803DD04:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803DD1C\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803DD18\n"
    "    movs\tr0, #18\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD10: .word 0x00002148\n"
    ".Ljp_0803DD14: .word 0x00001CD4\n"
    ".Ljp_0803DD18:\n"
    "    movs\tr0, #17\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD1C:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803DD24\n"
    "    movs\tr0, #20\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD24:\n"
    "    movs\tr0, #19\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD28:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803DD42\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DD36\n"
    "    cmp\tr0, #2\n"
    "    bne .Ljp_0803DD42\n"
    ".Ljp_0803DD36:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803DD3E\n"
    "    movs\tr0, #13\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD3E:\n"
    "    movs\tr0, #16\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD42:\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803DD52\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803DD4E\n"
    "    movs\tr0, #12\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD4E:\n"
    "    movs\tr0, #11\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD52:\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_0803DD5A\n"
    "    movs\tr0, #15\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD5A:\n"
    "    movs\tr0, #14\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD5E:\n"
    "    ldr r1, .Ljp_0803DD7C\n"
    "    adds\tr0, r5, r1\n"
    "    bl GetRivalEventCount__C12Bachelorette\n"
    "    cmp\tr0, #4\n"
    "    bls .Ljp_0803DD8E\n"
    "    mov\tr0, r8\n"
    "    adds\tr1, r7, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DD80\n"
    "    movs\tr0, #10\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD7C: .word 0x00001EB8\n"
    ".Ljp_0803DD80:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DD8A\n"
    "    movs\tr0, #7\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD8A:\n"
    "    movs\tr0, #6\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DD8E:\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #19\n"
    "    bl GetBachelorette__C13NpcCollectionUi\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #3\n"
    "    bne .Ljp_0803DDCC\n"
    "    cmp\tr7, #14\n"
    "    bne .Ljp_0803DDCC\n"
    "    cmp\tr6, #0\n"
    "    bne .Ljp_0803DDCC\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DDCC\n"
    "    bl GetLove__C12Bachelorette\n"
    "    ldr r1, .Ljp_0803DDC4\n"
    "    cmp\tr0, r1\n"
    "    bls .Ljp_0803DDCC\n"
    "    ldr r1, .Ljp_0803DDC8\n"
    "    adds\tr0, r5, r1\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #25\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803DDCC\n"
    "    movs\tr0, #9\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DDC4: .word 0x0000270F\n"
    ".Ljp_0803DDC8: .word 0x000021A4\n"
    ".Ljp_0803DDCC:\n"
    "    mov\tr0, r8\n"
    "    adds\tr1, r7, #0\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DDDE\n"
    "    movs\tr0, #8\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DDDE:\n"
    "    mov\tr0, r9\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DDE8\n"
    "    movs\tr0, #3\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DDE8:\n"
    "    mov\tr1, r9\n"
    "    cmp\tr1, #2\n"
    "    bne .Ljp_0803DDFC\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DDF8\n"
    "    movs\tr0, #4\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DDF8:\n"
    "    movs\tr0, #5\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DDFC:\n"
    "    ldr\tr0, [r5, #8]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_0803DE06\n"
    "    movs\tr0, #2\n"
    "    b .Ljp_0803DE08\n"
    ".Ljp_0803DE06:\n"
    "    movs\tr0, #1\n"
    ".Ljp_0803DE08:\n"
    "    add\tsp, #4\n"
    "    pop\t{r3, r4}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

// This 24-choice selector follows immediately in ROM. The aggregate keeps
// its table pointers, entries, payloads, and pointed detail records in their
// original physical order while giving every actual pointer a C++ relocation.
extern "C" NpcScheduleLargeStorage const gUnk_080F35E4 = {
        {
            SelectKarenSchedule,
            24,
            gUnk_080F35E4.table_choices,
        },
        {
            nullptr,
            &gUnk_080F35E4.table_storage[0],
            &gUnk_080F35E4.table_storage[1],
            &gUnk_080F35E4.table_storage[2],
            &gUnk_080F35E4.table_storage[3],
            &gUnk_080F35E4.table_storage[4],
            &gUnk_080F35E4.table_storage[5],
            &gUnk_080F35E4.table_storage[6],
            &gUnk_080F35E4.table_storage[7],
            &gUnk_080F35E4.table_storage[8],
            &gUnk_080F35E4.table_storage[9],
            &gUnk_080F35E4.table_storage[10],
            &gUnk_080F35E4.table_storage[11],
            &gUnk_080F35E4.table_storage[12],
            &gUnk_080F35E4.table_storage[13],
            &gUnk_080F35E4.table_storage[14],
            &gUnk_080F35E4.table_storage[15],
            &gUnk_080F35E4.table_storage[16],
            &gUnk_080F35E4.table_storage[17],
            &gUnk_080F35E4.table_storage[18],
            &gUnk_080F35E4.table_storage[19],
            &gUnk_080F35E4.table_storage[20],
            &gUnk_080F35E4.table_storage[21],
            &gUnk_080F35E4.table_storage[22],
        },
        {
            { 13, &gUnk_080F35E4.entry_storage[0] },  // Choice 01.
            { 5, &gUnk_080F35E4.entry_storage[13] },  // Choice 02.
            { 6, &gUnk_080F35E4.entry_storage[18] },  // Choice 03.
            { 15, &gUnk_080F35E4.entry_storage[24] }, // Choice 04.
            { 13, &gUnk_080F35E4.entry_storage[39] }, // Choice 05.
            { 6, &gUnk_080F35E4.entry_storage[52] },  // Choice 06.
            { 7, &gUnk_080F35E4.entry_storage[58] },  // Choice 07.
            { 1, &gUnk_080F35E4.entry_storage[65] },  // Choice 08.
            { 5, &gUnk_080F35E4.entry_storage[66] },  // Choice 09.
            { 1, &gUnk_080F35E4.entry_storage[71] },  // Choice 10.
            { 4, &gUnk_080F35E4.entry_storage[72] },  // Choice 11.
            { 4, &gUnk_080F35E4.entry_storage[76] },  // Choice 12.
            { 4, &gUnk_080F35E4.entry_storage[80] },  // Choice 13.
            { 4, &gUnk_080F35E4.entry_storage[84] },  // Choice 14.
            { 4, &gUnk_080F35E4.entry_storage[88] },  // Choice 15.
            { 4, &gUnk_080F35E4.entry_storage[92] },  // Choice 16.
            { 4, &gUnk_080F35E4.entry_storage[96] },  // Choice 17.
            { 4, &gUnk_080F35E4.entry_storage[100] }, // Choice 18.
            { 4, &gUnk_080F35E4.entry_storage[104] }, // Choice 19.
            { 4, &gUnk_080F35E4.entry_storage[108] }, // Choice 20.
            { 4, &gUnk_080F35E4.entry_storage[112] }, // Choice 21.
            { 3, &gUnk_080F35E4.entry_storage[116] }, // Choice 22.
            { 1, &gUnk_080F35E4.entry_storage[119] }, // Choice 23.
        },
        {
            // Table 01.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[1] },
            { 0x007E, &gUnk_080F35E4.payload_storage[2] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[3] },
            { 0x00F6, &gUnk_080F35E4.payload_storage[0] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[4] },
            { 0x0258, &gUnk_080F35E4.payload_storage[0] },
            { 0x030C, &gUnk_080F35E4.payload_storage[5] },
            { 0x033A, &gUnk_080F35E4.payload_storage[6] },
            { 0x034B, &gUnk_080F35E4.payload_storage[7] },
            { 0x03C0, &gUnk_080F35E4.payload_storage[8] },
            { 0x03D2, &gUnk_080F35E4.payload_storage[9] },
            { 0x03FF, &gUnk_080F35E4.payload_storage[0] },
            // Table 02.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[4] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[0] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[4] },
            { 0x0258, &gUnk_080F35E4.payload_storage[0] },
            // Table 03.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[4] },
            { 0x030C, &gUnk_080F35E4.payload_storage[11] },
            { 0x0329, &gUnk_080F35E4.payload_storage[10] },
            { 0x03C9, &gUnk_080F35E4.payload_storage[12] },
            { 0x03E6, &gUnk_080F35E4.payload_storage[0] },
            // Table 04.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[1] },
            { 0x007E, &gUnk_080F35E4.payload_storage[2] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[3] },
            { 0x00F6, &gUnk_080F35E4.payload_storage[0] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[5] },
            { 0x01D2, &gUnk_080F35E4.payload_storage[13] },
            { 0x01E0, &gUnk_080F35E4.payload_storage[14] },
            { 0x0258, &gUnk_080F35E4.payload_storage[15] },
            { 0x0267, &gUnk_080F35E4.payload_storage[9] },
            { 0x0294, &gUnk_080F35E4.payload_storage[0] },
            { 0x030C, &gUnk_080F35E4.payload_storage[11] },
            { 0x0329, &gUnk_080F35E4.payload_storage[10] },
            { 0x03C9, &gUnk_080F35E4.payload_storage[12] },
            { 0x03E6, &gUnk_080F35E4.payload_storage[0] },
            // Table 05.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[4] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[0] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[5] },
            { 0x01D2, &gUnk_080F35E4.payload_storage[16] },
            { 0x01E9, &gUnk_080F35E4.payload_storage[17] },
            { 0x0258, &gUnk_080F35E4.payload_storage[18] },
            { 0x026F, &gUnk_080F35E4.payload_storage[9] },
            { 0x029C, &gUnk_080F35E4.payload_storage[0] },
            { 0x030C, &gUnk_080F35E4.payload_storage[11] },
            { 0x0329, &gUnk_080F35E4.payload_storage[10] },
            { 0x03C9, &gUnk_080F35E4.payload_storage[12] },
            { 0x03E6, &gUnk_080F35E4.payload_storage[0] },
            // Table 06.
            { 0x0000, &gUnk_080F35E4.payload_storage[20] },
            { 0x0078, &gUnk_080F35E4.payload_storage[21] },
            { 0x007D, &gUnk_080F35E4.payload_storage[22] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[23] },
            { 0x00F5, &gUnk_080F35E4.payload_storage[19] },
            { 0x030C, &gUnk_080F35E4.payload_storage[20] },
            // Table 07.
            { 0x0000, &gUnk_080F35E4.payload_storage[20] },
            { 0x0041, &gUnk_080F35E4.payload_storage[24] },
            { 0x005F, &gUnk_080F35E4.payload_storage[25] },
            { 0x008C, &gUnk_080F35E4.payload_storage[4] },
            { 0x030C, &gUnk_080F35E4.payload_storage[32] },
            { 0x033A, &gUnk_080F35E4.payload_storage[33] },
            { 0x0358, &gUnk_080F35E4.payload_storage[20] },
            // Table 08.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            // Table 09.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0168, &gUnk_080F35E4.payload_storage[26] },
            { 0x0172, &gUnk_080F35E4.payload_storage[27] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[31] },
            { 0x01AE, &gUnk_080F35E4.payload_storage[0] },
            // Table 10.
            { 0x0000, &gUnk_080F35E4.payload_storage[19] },
            // Table 11.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 12.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x00B4, &gUnk_080F35E4.payload_storage[4] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 13.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 14.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 15.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x00B4, &gUnk_080F35E4.payload_storage[4] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 16.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 17.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 18.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 19.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 20.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 21.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[34] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 22.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[34] },
            // Table 23.
            { 0x0000, &gUnk_080F35E4.payload_storage[29] },
        },
        {
            { &gUnk_080F35E4.detail_storage[0], 4, 104, 104, 16, 0, true },
            { &gUnk_080F35E4.detail_storage[4], 3, 688, 160, 5, 0, false },
            { nullptr, 0, 752, 184, 5, 0, false },
            { &gUnk_080F35E4.detail_storage[7], 3, 752, 184, 5, 0, false },
            { &gUnk_080F35E4.detail_storage[10], 2, 128, 80, 15, 0, true },
            { &gUnk_080F35E4.detail_storage[12], 5, 688, 160, 5, 0, false },
            { &gUnk_080F35E4.detail_storage[17], 5, 0, 280, 1, 0, false },
            { &gUnk_080F35E4.detail_storage[22], 2, 256, 296, 1, 0, true },
            { &gUnk_080F35E4.detail_storage[24], 5, 256, 296, 1, 0, false },
            { &gUnk_080F35E4.detail_storage[29], 5, 1260, 704, 5, 0, false },
            { nullptr, 0, 208, 120, 21, 1, false },
            { &gUnk_080F35E4.detail_storage[34], 5, 688, 160, 5, 0, false },
            { &gUnk_080F35E4.detail_storage[39], 5, 632, 488, 5, 0, false },
            { &gUnk_080F35E4.detail_storage[44], 8, 1200, 528, 0, 0, false },
            { nullptr, 0, 1008, 424, 0, 1, false },
            { &gUnk_080F35E4.detail_storage[52], 8, 1008, 424, 0, 0, false },
            { &gUnk_080F35E4.detail_storage[60], 3, 832, 0, 3, 0, false },
            { &gUnk_080F35E4.detail_storage[63], 2, 160, 160, 40, 0, true },
            { &gUnk_080F35E4.detail_storage[65], 3, 612, 244, 3, 0, false },
            { nullptr, 0, 88, 104, 10, 1, false },
            { nullptr, 0, 90, 80, 11, 0, false },
            { &gUnk_080F35E4.detail_storage[68], 3, 572, 227, 7, 0, false },
            { &gUnk_080F35E4.detail_storage[71], 2, 544, 312, 7, 0, true },
            { &gUnk_080F35E4.detail_storage[73], 3, 544, 312, 7, 0, false },
            { &gUnk_080F35E4.detail_storage[76], 5, 572, 227, 7, 0, false },
            { &gUnk_080F35E4.detail_storage[81], 5, 104, 704, 5, 0, false },
            { &gUnk_080F35E4.detail_storage[86], 2, 340, 0, 2, 0, false },
            { nullptr, 0, 228, 145, 2, 1, false },
            { &gUnk_080F35E4.detail_storage[88], 4, 112, 76, 29, 0, true },
            { nullptr, 0, 440, -48, 29, 0, false },
            { &gUnk_080F35E4.detail_storage[92], 4, 256, 152, 29, 0, true },
            { &gUnk_080F35E4.detail_storage[96], 2, 228, 145, 2, 0, false },
            { &gUnk_080F35E4.detail_storage[98], 5, 688, 160, 5, 0, false },
            { &gUnk_080F35E4.detail_storage[103], 5, 104, 0, 7, 0, false },
            { nullptr, 0, 0, 0, 564, 1, false },
        },
        {
            { 0x0040, 0x0002, 0x0000, 0x0000 },
            { 0x00E0, 0x0002, 0x0078, 0x0004 },
            { 0x0068, 0x0002, 0x0000, 0x0004 },
            { 0x0068, 0x0002, 0x0078, 0x0003 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0005, 0x02F0, 0x0000, 0x0000 },
            { 0x0006, 0x00B8, 0x0001, 0x0000 },
            { 0x0001, 0x00D8, 0x0001, 0x0000 },
            { 0x0004, 0x02B0, 0x0000, 0x0000 },
            { 0x0006, 0x00A0, 0x0001, 0x0000 },
            { 0x0038, 0x0002, 0x0078, 0x0002 },
            { 0x0080, 0x0002, 0x0078, 0x0003 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0018, 0x04E0, 0x0000, 0x0000 },
            { 0x0019, 0x00F0, 0x0001, 0x0000 },
            { 0x001A, 0x04EC, 0x0000, 0x0000 },
            { 0x002E, 0x02E0, 0x0001, 0x0000 },
            { 0x0003, 0x0040, 0x0000, 0x0000 },
            { 0x0006, 0x0168, 0x0001, 0x0000 },
            { 0x0008, 0x0068, 0x0000, 0x0000 },
            { 0x000B, 0x0128, 0x0001, 0x0000 },
            { 0x0011, 0x0100, 0x0000, 0x0000 },
            { 0x0150, 0x0002, 0x0078, 0x0007 },
            { 0x0128, 0x0002, 0x0078, 0x0007 },
            { 0x0006, 0x0068, 0x0000, 0x0000 },
            { 0x0009, 0x0168, 0x0001, 0x0000 },
            { 0x000B, 0x0040, 0x0000, 0x0000 },
            { 0x000E, 0x0118, 0x0001, 0x0000 },
            { 0x0012, 0xFFF0, 0x0000, 0x0000 },
            { 0x0013, 0x00F0, 0x0001, 0x0000 },
            { 0x0014, 0x04E0, 0x0000, 0x0000 },
            { 0x0015, 0x00D8, 0x0001, 0x0000 },
            { 0x002B, 0x02B0, 0x0000, 0x0000 },
            { 0x002D, 0x00A0, 0x0001, 0x0000 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0007, 0x0328, 0x0000, 0x0000 },
            { 0x0014, 0x0218, 0x0001, 0x0000 },
            { 0x001B, 0x0278, 0x0000, 0x0000 },
            { 0x001D, 0x01E8, 0x0001, 0x0000 },
            { 0x0002, 0x0218, 0x0001, 0x0000 },
            { 0x0009, 0x0328, 0x0000, 0x0000 },
            { 0x0016, 0x00D8, 0x0001, 0x0000 },
            { 0x001B, 0x02B0, 0x0000, 0x0000 },
            { 0x001D, 0x00A0, 0x0001, 0x0000 },
            { 0x0001, 0x0498, 0x0000, 0x0000 },
            { 0x0002, 0x0200, 0x0001, 0x0000 },
            { 0x0003, 0x0488, 0x0000, 0x0000 },
            { 0x0004, 0x01F0, 0x0001, 0x0000 },
            { 0x0005, 0x0478, 0x0000, 0x0000 },
            { 0x0006, 0x01E0, 0x0001, 0x0000 },
            { 0x000B, 0x03F0, 0x0000, 0x0000 },
            { 0x000E, 0x01A8, 0x0001, 0x0000 },
            { 0x0003, 0x01E0, 0x0001, 0x0000 },
            { 0x0008, 0x0478, 0x0000, 0x0000 },
            { 0x0009, 0x01F0, 0x0001, 0x0000 },
            { 0x000A, 0x0488, 0x0000, 0x0000 },
            { 0x000B, 0x0200, 0x0001, 0x0000 },
            { 0x000C, 0x0498, 0x0000, 0x0000 },
            { 0x000D, 0x0210, 0x0001, 0x0000 },
            { 0x000F, 0x04C0, 0x0000, 0x0000 },
            { 0x000C, 0x0128, 0x0001, 0x0000 },
            { 0x0015, 0x0266, 0x0000, 0x0000 },
            { 0x0017, 0x00F4, 0x0001, 0x0000 },
            { 0x00D8, 0x0002, 0x0078, 0x0003 },
            { 0x00A0, 0x0002, 0x0078, 0x0002 },
            { 0x0002, 0x0128, 0x0001, 0x0000 },
            { 0x000B, 0x0340, 0x0000, 0x0000 },
            { 0x0017, 0x0000, 0x0001, 0x0000 },
            { 0x0001, 0x00F8, 0x0001, 0x0000 },
            { 0x0002, 0x0220, 0x0000, 0x0000 },
            { 0x0005, 0x0138, 0x0001, 0x0000 },
            { 0x0258, 0x0002, 0x0078, 0x0003 },
            { 0x0220, 0x0002, 0x0078, 0x0002 },
            { 0x0003, 0x00F8, 0x0001, 0x0000 },
            { 0x0004, 0x023C, 0x0000, 0x0000 },
            { 0x0005, 0x00E3, 0x0001, 0x0000 },
            { 0x0001, 0x00F8, 0x0001, 0x0000 },
            { 0x0005, 0x01D8, 0x0000, 0x0000 },
            { 0x0009, 0x0098, 0x0001, 0x0000 },
            { 0x0018, 0x0068, 0x0000, 0x0000 },
            { 0x001E, 0x0000, 0x0001, 0x0000 },
            { 0x0013, 0x00F0, 0x0001, 0x0000 },
            { 0x0014, 0x0090, 0x0000, 0x0000 },
            { 0x0015, 0x00D8, 0x0001, 0x0000 },
            { 0x002B, 0x02B0, 0x0000, 0x0000 },
            { 0x002D, 0x00A0, 0x0001, 0x0000 },
            { 0x0006, 0x0091, 0x0001, 0x0000 },
            { 0x000A, 0x00E4, 0x0000, 0x0000 },
            { 0x006C, 0x0002, 0x0078, 0x0006 },
            { 0x0080, 0x0002, 0x0078, 0x0003 },
            { 0x004C, 0x0002, 0x0078, 0x0007 },
            { 0x0070, 0x0002, 0x0078, 0x0002 },
            { 0x0060, 0x0002, 0x0000, 0x0004 },
            { 0x0148, 0x0002, 0x0078, 0x0003 },
            { 0x0100, 0x0002, 0x0000, 0x0000 },
            { 0x0098, 0x0002, 0x0078, 0x0004 },
            { 0x0004, 0x0154, 0x0000, 0x0000 },
            { 0x000A, 0x0000, 0x0001, 0x0000 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0018, 0x0090, 0x0000, 0x0000 },
            { 0x0019, 0x00F0, 0x0001, 0x0000 },
            { 0x001A, 0x0068, 0x0000, 0x0000 },
            { 0x002E, 0x02E0, 0x0001, 0x0000 },
            { 0x0006, 0x0098, 0x0001, 0x0000 },
            { 0x0015, 0x01D8, 0x0000, 0x0000 },
            { 0x0019, 0x00F8, 0x0001, 0x0000 },
            { 0x001D, 0x023C, 0x0000, 0x0000 },
            { 0x001E, 0x00E3, 0x0001, 0x0000 },
        },
    };
