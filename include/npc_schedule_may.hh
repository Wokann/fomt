#ifndef NPC_SCHEDULE_MAY_HH
#define NPC_SCHEDULE_MAY_HH

#include "npc_schedule.hh"

extern "C" u32 SelectMaySchedule(void const * context);

struct NpcScheduleStorage_080F81BC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[7];
    Schedule table_storage[6];
    ScheduleEntry entry_storage[40];
    PathInfo payload_storage[18];
    NpcScheduleDetailEntry detail_storage[72];
};

extern "C" NpcScheduleStorage_080F81BC const gUnk_080F81BC;

#endif // NPC_SCHEDULE_MAY_HH
