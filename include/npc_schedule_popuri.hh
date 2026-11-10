#ifndef NPC_SCHEDULE_POPURI_HH
#define NPC_SCHEDULE_POPURI_HH

#include "npc_schedule.hh"

extern "C" u32 SelectPopuriSchedule(void const * context);

struct PopuriScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[24];
    Schedule table_storage[23];
    ScheduleEntry entries_0[8];
    ScheduleEntry entries_1[2];
    ScheduleEntry entries_2[11];
    ScheduleEntry entries_3[8];
    ScheduleEntry entries_4[8];
    ScheduleEntry entries_5[4];
    ScheduleEntry entries_6[4];
    ScheduleEntry entries_7[4];
    ScheduleEntry entries_8[4];
    ScheduleEntry entries_9[4];
    ScheduleEntry entries_10[4];
    ScheduleEntry entries_11[4];
    ScheduleEntry entries_12[4];
    ScheduleEntry entries_13[4];
    ScheduleEntry entries_14[4];
    ScheduleEntry entries_15[1];
    ScheduleEntry entries_16[5];
    ScheduleEntry entries_17[4];
    ScheduleEntry entries_18[1];
    ScheduleEntry entries_19[8];
    ScheduleEntry entries_20[2];
    ScheduleEntry entries_21[3];
    ScheduleEntry entries_22[1];
    PathInfo payload_storage[25];
    PathPointB points_0[2];
    PathPointA points_1[5];
    PathPointA points_2[8];
    PathPointB points_3[4];
    PathPointA points_4[8];
    PathPointA points_5[5];
    PathPointB points_6[2];
    PathPointA points_7[7];
    PathPointA points_8[5];
    PathPointB points_9[2];
    PathPointA points_10[5];
    PathPointA points_11[2];
    PathPointB points_12[2];
    PathPointA points_13[2];
    PathPointA points_14[7];
    PathPointA points_15[5];
    PathPointA points_17[5];
    PathPointB points_18[4];
    PathPointB points_19[4];
    PathPointA points_22[2];
    PathPointA points_23[2];
};

extern "C" PopuriScheduleData const gPopuriScheduleData;

#endif // NPC_SCHEDULE_POPURI_HH
