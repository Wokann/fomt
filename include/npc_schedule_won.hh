#ifndef NPC_SCHEDULE_WON_HH
#define NPC_SCHEDULE_WON_HH

#include "npc_schedule.hh"

extern "C" u32 SelectWonSchedule(void const * context);

struct NpcScheduleStorage_080F597C
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entry_storage[2];
    PathInfo payload_storage[1];
};

extern "C" NpcScheduleStorage_080F597C const gUnk_080F597C;

#endif // NPC_SCHEDULE_WON_HH
