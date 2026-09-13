#include "data_schedules.hh"

// This eight-byte object has no terminator: gUnk_080F2DC0 addresses its final
// character in the original JP ROM and must remain independently relocatable.
char const gCppRuntimeBadAllocPrefix_FourthSchedule[] = {
    'b', 'a', 'd', '_', 'a', 'l', 'l', 'o',
};

char const gUnk_080F2DC0[] =
    "c";
