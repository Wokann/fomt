#pragma implementation "player_actor_lifetimes.hh"
#include "player_actor_lifetimes.hh"

// Native player ABI: two metadata words and 42 virtual entry addresses.
// The complete RAM payload and natural compiler table are still under review.
asm_unified(
    ".section .rodata\n"
    ".align 2, 0\n"
    ".global gPlayerActorVTable\n"
    "gPlayerActorVTable:\n"
    "    .word 0\n"
    "    .word 0\n"
#if defined(REGION_JP)
    "    .word func_08024814\n"
    "    .word func_08024990\n"
    "    .word func_0802497C\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    .word func_08024A80\n"
    "    .word func_08024BFC\n"
    "    .word func_08024BE8\n"
#endif
    "    .word vfunc_14__7AEntity\n"
#if defined(REGION_JP)
    "    .word func_08024A64\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    .word func_08024CD0\n"
#endif
    "    .word Draw__7AEntityRC17EntityDrawContext\n"
#if defined(REGION_JP)
    "    .word func_080249E8\n"
    "    .word func_080249F8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    .word func_08024C54\n"
    "    .word func_08024C64\n"
#endif
    "    .word IsNormalUpdateSuspended__C7AEntity\n"
#if defined(REGION_JP)
    "    .word func_08024DAC\n"
    "    .word func_08024930\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    .word func_08025018\n"
    "    .word func_08024B9C\n"
#endif
    "    .word vfunc_34__12AActorEntity\n"
    "    .word SetEventScript__12AActorEntityi\n"
#if defined(REGION_JP)
    "    .word func_08031E08\n"
    "    .word IsRidingHorse__11PlayerActor\n"
    "    .word func_08031DE8\n"
    "    .word func_08027990\n"
    "    .word func_080283D8\n"
    "    .word func_080288E4\n"
    "    .word func_08028E10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    .word func_08032074\n"
    "    .word IsRidingHorse__11PlayerActor\n"
    "    .word func_08032054\n"
    "    .word func_08027BFC\n"
    "    .word func_08028644\n"
    "    .word func_08028B50\n"
    "    .word func_0802907C\n"
#endif
    "    .word PlayerEatFood\n"
#if defined(REGION_JP)
    "    .word func_08028E68\n"
    "    .word func_080292EC\n"
    "    .word func_08024DFC\n"
    "    .word func_08026AA8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    .word func_080290D4\n"
    "    .word func_08029558\n"
    "    .word func_08025068\n"
    "    .word func_08026D14\n"
#endif
    "    .word PlayerPrepareForScriptedAnimation\n"
    "    .word PlayerRestoreAfterScriptedAnimation\n"
    "    .word PlayerShowHoldingTool\n"
#if defined(REGION_JP)
    "    .word func_08031DE0\n"
    "    .word func_080260E0\n"
    "    .word func_080265C4\n"
    "    .word func_08031DD8\n"
    "    .word func_08031DD0\n"
    "    .word func_08031DC8\n"
    "    .word GetCaughtFish__11PlayerActor\n"
    "    .word func_08031DC0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    .word func_0803204C\n"
    "    .word func_0802634C\n"
    "    .word func_08026830\n"
    "    .word func_08032044\n"
    "    .word func_0803203C\n"
    "    .word func_08032034\n"
    "    .word GetCaughtFish__11PlayerActor\n"
    "    .word func_0803202C\n"
#endif
    "    .word IsClockPausedByAction__11PlayerActor\n"
    "    .word SetUpdateSuspended__11PlayerActorUc\n"
    "    .word GetUpdateSuspended__C11PlayerActor\n"
#if defined(REGION_JP)
    "    .word func_08024A08\n"
    "    .word func_08024A1C\n"
    "    .word func_08024A2C\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "    .word func_08024C74\n"
    "    .word func_08024C88\n"
    "    .word func_08024C98\n"
#endif
);
