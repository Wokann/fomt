#ifndef NPC_SCHEDULE_CHILD_HH
#define NPC_SCHEDULE_CHILD_HH

#include "npc_schedule.hh"

extern "C" u32 SelectChildSchedule(void const * context);

struct ChildScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entries_0[4];
    ScheduleEntry entries_1[4];
    ScheduleEntry entries_2[1];
    ScheduleEntry entries_3[3];
    ScheduleEntry entries_4[2];
    PathInfo payload_storage[4];
    PathPointB points_2[4];
    PathPointB points_3[4];
};

extern "C" ChildScheduleData const gChildScheduleData;

#endif // NPC_SCHEDULE_CHILD_HH
