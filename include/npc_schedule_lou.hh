#ifndef NPC_SCHEDULE_LOU_HH
#define NPC_SCHEDULE_LOU_HH

#include "npc_schedule.hh"

extern "C" u32 IsLouSundayScheduleActive(void const * context);

struct NpcScheduleStorage_080F4974
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[2];
    Schedule table_storage[1];
    ScheduleEntry entry_storage[1];
    PathInfo payload_storage[1];
    NpcScheduleDetailEntry detail_storage[2];
};

extern "C" NpcScheduleStorage_080F4974 const gUnk_080F4974;

#endif // NPC_SCHEDULE_LOU_HH
