#ifndef NPC_SCHEDULE_STU_HH
#define NPC_SCHEDULE_STU_HH

#include "npc_schedule.hh"

extern "C" u32 SelectStuSchedule(void const * context);

struct StuScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entries_0[5];
    ScheduleEntry entries_1[1];
    ScheduleEntry entries_2[1];
    ScheduleEntry entries_3[1];
    ScheduleEntry entries_4[5];
    PathInfo payload_storage[7];
    PathPointB points_0[2];
    PathPointA points_1[3];
    PathPointA points_3[3];
    PathPointA points_5[2];
    PathPointA points_6[2];
};

extern "C" StuScheduleData const gStuScheduleData;

#endif // NPC_SCHEDULE_STU_HH
