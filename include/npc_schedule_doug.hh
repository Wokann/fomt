#ifndef NPC_SCHEDULE_DOUG_HH
#define NPC_SCHEDULE_DOUG_HH

#include "npc_schedule.hh"

extern "C" u32 SelectDougSchedule(void const * context);

struct NpcScheduleStorage_080F42F0
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[4];
    Schedule table_storage[3];
    ScheduleEntry entry_storage[10];
    PathInfo payload_storage[5];
    NpcScheduleDetailEntry detail_storage[4];
};

extern "C" NpcScheduleStorage_080F42F0 const gUnk_080F42F0;

#endif // NPC_SCHEDULE_DOUG_HH
