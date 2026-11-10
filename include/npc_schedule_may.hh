#ifndef NPC_SCHEDULE_MAY_HH
#define NPC_SCHEDULE_MAY_HH

#include "npc_schedule.hh"

extern "C" u32 SelectMaySchedule(void const * context);

struct MayScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[7];
    Schedule table_storage[6];
    ScheduleEntry entries_0[12];
    ScheduleEntry entries_1[10];
    ScheduleEntry entries_2[12];
    ScheduleEntry entries_3[1];
    ScheduleEntry entries_4[1];
    ScheduleEntry entries_5[4];
    PathInfo payload_storage[18];
    PathPointB points_0[2];
    PathPointB points_1[2];
    PathPointA points_2[3];
    PathPointB points_3[2];
    PathPointA points_4[3];
    PathPointA points_5[5];
    PathPointA points_6[11];
    PathPointA points_8[11];
    PathPointA points_9[5];
    PathPointA points_10[7];
    PathPointA points_11[5];
    PathPointA points_13[5];
    PathPointA points_14[7];
    PathPointA points_16[2];
    PathPointA points_17[2];
};

extern "C" MayScheduleData const gMayScheduleData;

#endif // NPC_SCHEDULE_MAY_HH
