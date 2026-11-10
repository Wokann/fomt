#ifndef NPC_SCHEDULE_MANNA_HH
#define NPC_SCHEDULE_MANNA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectMannaSchedule(void const * context);

struct MannaScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entries_0[9];
    ScheduleEntry entries_1[7];
    ScheduleEntry entries_2[11];
    ScheduleEntry entries_3[11];
    ScheduleEntry entries_4[1];
    PathInfo payload_storage[19];
    PathPointB points_0[2];
    PathPointA points_2[3];
    PathPointA points_3[2];
    PathPointA points_5[2];
    PathPointA points_6[3];
    PathPointA points_7[5];
    PathPointA points_9[7];
    PathPointA points_10[7];
    PathPointA points_12[5];
    PathPointA points_13[7];
    PathPointA points_15[7];
    PathPointA points_17[7];
    PathPointB points_18[2];
};

extern "C" MannaScheduleData const gMannaScheduleData;

#endif // NPC_SCHEDULE_MANNA_HH
