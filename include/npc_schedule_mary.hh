#ifndef NPC_SCHEDULE_MARY_HH
#define NPC_SCHEDULE_MARY_HH

#include "npc_schedule.hh"

extern "C" u32 SelectMarySchedule(void const * context);

struct NpcScheduleStorage_080F4D74
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[19];
    Schedule table_storage[18];
    ScheduleEntry entry_storage[90];
    PathInfo payload_storage[26];
    NpcScheduleDetailEntry detail_storage[90];
};

extern "C" NpcScheduleStorage_080F4D74 const gUnk_080F4D74;

#endif // NPC_SCHEDULE_MARY_HH
