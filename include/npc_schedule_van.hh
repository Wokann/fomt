#ifndef NPC_SCHEDULE_VAN_HH
#define NPC_SCHEDULE_VAN_HH

#include "npc_schedule.hh"

extern "C" u32 IsVanWednesdayScheduleActive(void const * context);

struct NpcScheduleStorage_080F6B10
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[2];
    Schedule table_storage[1];
    ScheduleEntry entry_storage[1];
    PathInfo payload_storage[1];
};

extern "C" NpcScheduleStorage_080F6B10 const gUnk_080F6B10;

#endif // NPC_SCHEDULE_VAN_HH
