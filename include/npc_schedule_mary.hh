#ifndef NPC_SCHEDULE_MARY_HH
#define NPC_SCHEDULE_MARY_HH

#include "npc_schedule.hh"

extern "C" u32 SelectMarySchedule(void const * context);

struct MaryScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[19];
    Schedule table_storage[18];
    ScheduleEntry entries_0[7];
    ScheduleEntry entries_1[12];
    ScheduleEntry entries_2[7];
    ScheduleEntry entries_3[7];
    ScheduleEntry entries_4[9];
    ScheduleEntry entries_5[9];
    ScheduleEntry entries_6[5];
    ScheduleEntry entries_7[1];
    ScheduleEntry entries_8[1];
    ScheduleEntry entries_9[4];
    ScheduleEntry entries_10[4];
    ScheduleEntry entries_11[4];
    ScheduleEntry entries_12[4];
    ScheduleEntry entries_13[4];
    ScheduleEntry entries_14[4];
    ScheduleEntry entries_15[4];
    ScheduleEntry entries_16[3];
    ScheduleEntry entries_17[1];
    PathInfo payload_storage[26];
    PathPointB points_0[2];
    PathPointB points_1[2];
    PathPointA points_2[3];
    PathPointA points_4[3];
    PathPointA points_5[5];
    PathPointA points_6[20];
    PathPointB points_7[2];
    PathPointA points_8[20];
    PathPointA points_9[5];
    PathPointA points_10[3];
    PathPointA points_12[3];
    PathPointB points_13[4];
    PathPointB points_15[4];
    PathPointA points_16[2];
    PathPointA points_18[2];
    PathPointA points_19[3];
    PathPointA points_21[3];
    PathPointA points_23[2];
    PathPointA points_25[2];
};

extern "C" MaryScheduleData const gMaryScheduleData;

#endif // NPC_SCHEDULE_MARY_HH
