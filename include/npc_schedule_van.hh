#ifndef NPC_SCHEDULE_VAN_HH
#define NPC_SCHEDULE_VAN_HH

#include "npc_schedule.hh"

extern "C" u32 IsVanWednesdayScheduleActive(void const * context);

struct VanScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[2];
    Schedule table_storage[1];
    ScheduleEntry entries_0[1];
    PathInfo payload_storage[1];
};

extern "C" VanScheduleData const gVanScheduleData;

#endif // NPC_SCHEDULE_VAN_HH
