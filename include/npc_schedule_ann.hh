#ifndef NPC_SCHEDULE_ANN_HH
#define NPC_SCHEDULE_ANN_HH

#include "npc_schedule.hh"

extern "C" u32 SelectAnnSchedule(void const * context);

struct AnnScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[19];
    Schedule table_storage[18];
    ScheduleEntry entries_0[11];
    ScheduleEntry entries_1[6];
    ScheduleEntry entries_2[11];
    ScheduleEntry entries_3[6];
    ScheduleEntry entries_4[3];
    ScheduleEntry entries_5[1];
    ScheduleEntry entries_6[5];
    ScheduleEntry entries_7[4];
    ScheduleEntry entries_8[4];
    ScheduleEntry entries_9[4];
    ScheduleEntry entries_10[4];
    ScheduleEntry entries_11[4];
    ScheduleEntry entries_12[4];
    ScheduleEntry entries_13[4];
    ScheduleEntry entries_14[4];
    ScheduleEntry entries_15[4];
    ScheduleEntry entries_16[3];
    ScheduleEntry entries_17[1];
    PathInfo payload_storage[15];
    PathPointB points_0[5];
    PathPointB points_1[2];
    PathPointB points_2[2];
    PathPointA points_3[3];
    PathPointA points_4[8];
    PathPointA points_6[8];
    PathPointA points_7[3];
    PathPointA points_8[2];
    PathPointB points_10[4];
    PathPointB points_12[4];
    PathPointA points_13[2];
};

extern "C" AnnScheduleData const gAnnScheduleData;

#endif // NPC_SCHEDULE_ANN_HH
