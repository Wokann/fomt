#ifndef NPC_SCHEDULE_GOTZ_HH
#define NPC_SCHEDULE_GOTZ_HH

#include "npc_schedule.hh"

extern "C" u32 SelectGotzSchedule(void const * context);

struct GotzScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[15];
    Schedule table_storage[14];
    ScheduleEntry entries_0[7];
    ScheduleEntry entries_1[11];
    ScheduleEntry entries_2[12];
    ScheduleEntry entries_3[7];
    ScheduleEntry entries_4[1];
    ScheduleEntry entries_5[1];
    ScheduleEntry entries_6[1];
    ScheduleEntry entries_7[1];
    ScheduleEntry entries_8[1];
    ScheduleEntry entries_9[1];
    ScheduleEntry entries_10[1];
    ScheduleEntry entries_11[1];
    ScheduleEntry entries_12[1];
    ScheduleEntry entries_13[1];
    PathInfo payload_storage[24];
    PathPointA points_1[8];
    PathPointA points_2[16];
    PathPointB points_3[2];
    PathPointA points_4[16];
    PathPointA points_5[8];
    PathPointA points_6[3];
    PathPointB points_7[2];
    PathPointA points_8[3];
    PathPointA points_9[5];
    PathPointB points_10[2];
    PathPointA points_11[3];
    PathPointA points_13[5];
    PathPointA points_14[3];
    PathPointA points_15[2];
    PathPointA points_17[2];
    PathPointB points_18[3];
    PathPointB points_19[3];
    PathPointB points_20[3];
    PathPointB points_21[3];
    PathPointB points_22[3];
    PathPointB points_23[5];
};

extern "C" GotzScheduleData const gGotzScheduleData;

#endif // NPC_SCHEDULE_GOTZ_HH
