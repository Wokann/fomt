#ifndef NPC_SCHEDULE_JEFF_HH
#define NPC_SCHEDULE_JEFF_HH

#include "npc_schedule.hh"

extern "C" u32 SelectJeffSchedule(void const * context);

struct JeffScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entries_0[3];
    ScheduleEntry entries_1[7];
    ScheduleEntry entries_2[5];
    ScheduleEntry entries_3[1];
    PathInfo payload_storage[10];
    PathPointA points_2[3];
    PathPointA points_4[3];
    PathPointA points_6[3];
    PathPointA points_7[5];
    PathPointA points_9[5];
};

extern "C" JeffScheduleData const gJeffScheduleData;

#endif // NPC_SCHEDULE_JEFF_HH
