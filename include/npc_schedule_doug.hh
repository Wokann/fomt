#ifndef NPC_SCHEDULE_DOUG_HH
#define NPC_SCHEDULE_DOUG_HH

#include "npc_schedule.hh"

extern "C" u32 SelectDougSchedule(void const * context);

struct DougScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[4];
    Schedule table_storage[3];
    ScheduleEntry entries_0[6];
    ScheduleEntry entries_1[1];
    ScheduleEntry entries_2[3];
    PathInfo payload_storage[5];
    PathPointB points_0[2];
    PathPointA points_4[2];
};

extern "C" DougScheduleData const gDougScheduleData;

#endif // NPC_SCHEDULE_DOUG_HH
