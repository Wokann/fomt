#ifndef NPC_SCHEDULE_RICK_HH
#define NPC_SCHEDULE_RICK_HH

#include "npc_schedule.hh"

extern "C" u32 SelectRickSchedule(void const * context);

struct RickScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entries_0[17];
    ScheduleEntry entries_1[9];
    ScheduleEntry entries_2[17];
    ScheduleEntry entries_3[1];
    PathInfo payload_storage[23];
    PathPointA points_2[5];
    PathPointA points_4[5];
    PathPointA points_5[5];
    PathPointA points_6[7];
    PathPointA points_7[3];
    PathPointA points_9[3];
    PathPointA points_10[7];
    PathPointA points_11[2];
    PathPointB points_12[2];
    PathPointA points_13[2];
    PathPointA points_14[7];
    PathPointA points_15[5];
    PathPointA points_17[5];
    PathPointA points_18[3];
    PathPointB points_19[4];
    PathPointA points_20[3];
    PathPointA points_21[5];
    PathPointA points_22[7];
};

extern "C" RickScheduleData const gRickScheduleData;

#endif // NPC_SCHEDULE_RICK_HH
