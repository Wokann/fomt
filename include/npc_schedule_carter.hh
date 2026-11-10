#ifndef NPC_SCHEDULE_CARTER_HH
#define NPC_SCHEDULE_CARTER_HH

#include "npc_schedule.hh"

extern "C" u32 SelectCarterSchedule(void const * context);

struct CarterScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[10];
    Schedule table_storage[9];
    ScheduleEntry entries_0[5];
    ScheduleEntry entries_1[7];
    ScheduleEntry entries_2[1];
    ScheduleEntry entries_3[1];
    ScheduleEntry entries_4[1];
    ScheduleEntry entries_5[1];
    ScheduleEntry entries_6[1];
    ScheduleEntry entries_7[1];
    ScheduleEntry entries_8[5];
    PathInfo payload_storage[10];
    PathPointB points_0[2];
    PathPointA points_1[3];
    PathPointA points_4[2];
    PathPointA points_6[2];
    PathPointA points_7[1];
    PathPointA points_9[1];
};

extern "C" CarterScheduleData const gCarterScheduleData;

#endif // NPC_SCHEDULE_CARTER_HH
