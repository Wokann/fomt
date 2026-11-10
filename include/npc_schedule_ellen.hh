#ifndef NPC_SCHEDULE_ELLEN_HH
#define NPC_SCHEDULE_ELLEN_HH

#include "npc_schedule.hh"

extern "C" u32 SelectEllenSchedule(void const * context);

struct NpcScheduleStorage
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entry_storage[2];
    PathInfo payload;
};

extern "C" NpcScheduleStorage const gUnk_080F33B8;

#endif // NPC_SCHEDULE_ELLEN_HH
