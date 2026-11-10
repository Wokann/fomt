#include "npc_schedule_ellen.hh"
#include "game_state.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start SelectEllenSchedule\n"
    "SelectEllenSchedule:\n"
    "    push\t{r4, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr1, r0, #0\n"
    "    ldr r2, .Ljp_0803DBDC\n"
    "    adds\tr0, r1, r2\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsls\tr0, r0, #26\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_0803DBE0\n"
    "    movs\tr0, #0\n"
    "    b .Ljp_0803DBFE\n"
    "    .align 2, 0\n"
    ".Ljp_0803DBDC: .word 0x000021CA\n"
    ".Ljp_0803DBE0:\n"
    "    mov\tr4, sp\n"
    "    adds\tr1, #16\n"
    "    mov\tr0, sp\n"
    "    bl DecodeGameDayDate\n"
    "    ldrb\tr0, [r4, #1]\n"
    "    ldrb\tr1, [r4, #2]\n"
    "    bl IsNpcScheduleDateListed\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_0803DBFC\n"
    "    movs\tr0, #1\n"
    "    b .Ljp_0803DBFE\n"
    ".Ljp_0803DBFC:\n"
    "    movs\tr0, #2\n"
    ".Ljp_0803DBFE:\n"
    "    add\tsp, #4\n"
    "    pop\t{r4}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
);

// The physical order below is descriptor, table-choice array, two tables,
// two entries, the shared payload, and the C++ runtime string immediately
// following it.  Keeping it as one aggregate preserves the real internal
// relocations rather than embedding raw ROM addresses.
extern "C" EllenScheduleData const gEllenScheduleData = {
    { SelectEllenSchedule, ARRAY_COUNT(gEllenScheduleData.table_choices), gEllenScheduleData.table_choices },
    {
            nullptr,
            &gEllenScheduleData.table_storage[0],
            &gEllenScheduleData.table_storage[1],
        },
    {
        { ARRAY_COUNT(gEllenScheduleData.entries_0), gEllenScheduleData.entries_0 },
        { ARRAY_COUNT(gEllenScheduleData.entries_1), gEllenScheduleData.entries_1 },
    },
    { { 0, &gEllenScheduleData.payload } },
    { { 0, &gEllenScheduleData.payload } },
    { nullptr, 0, 128, 96, 14, 0, false },
};
