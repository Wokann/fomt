#ifndef NPC_SCHEDULE_LOU_HH
#define NPC_SCHEDULE_LOU_HH

#include "npc_schedule.hh"

extern "C" u32 IsLouSundayScheduleActive(void const * context);

struct LouScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[2];
    Schedule table_storage[1];
    ScheduleEntry entries_0[1];
    PathInfo payload_storage[1];
    PathPointB points_0[2];
};

extern "C" LouScheduleData const gLouScheduleData;

#endif // NPC_SCHEDULE_LOU_HH
