#ifndef NPC_SCHEDULE_KAREN_HH
#define NPC_SCHEDULE_KAREN_HH

#include "npc_schedule.hh"

extern "C" u32 SelectKarenSchedule(void const * context);

struct KarenScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[24];
    Schedule table_storage[23];
    ScheduleEntry entries_0[13];
    ScheduleEntry entries_1[5];
    ScheduleEntry entries_2[6];
    ScheduleEntry entries_3[15];
    ScheduleEntry entries_4[13];
    ScheduleEntry entries_5[6];
    ScheduleEntry entries_6[7];
    ScheduleEntry entries_7[1];
    ScheduleEntry entries_8[5];
    ScheduleEntry entries_9[1];
    ScheduleEntry entries_10[4];
    ScheduleEntry entries_11[4];
    ScheduleEntry entries_12[4];
    ScheduleEntry entries_13[4];
    ScheduleEntry entries_14[4];
    ScheduleEntry entries_15[4];
    ScheduleEntry entries_16[4];
    ScheduleEntry entries_17[4];
    ScheduleEntry entries_18[4];
    ScheduleEntry entries_19[4];
    ScheduleEntry entries_20[4];
    ScheduleEntry entries_21[3];
    ScheduleEntry entries_22[1];
    PathInfo payload_storage[35];
    PathPointB points_0[4];
    PathPointA points_1[3];
    PathPointA points_3[3];
    PathPointB points_4[2];
    PathPointA points_5[5];
    PathPointA points_6[5];
    PathPointB points_7[2];
    PathPointA points_8[5];
    PathPointA points_9[5];
    PathPointA points_11[5];
    PathPointA points_12[5];
    PathPointA points_13[8];
    PathPointA points_15[8];
    PathPointA points_16[3];
    PathPointB points_17[2];
    PathPointA points_18[3];
    PathPointA points_21[3];
    PathPointB points_22[2];
    PathPointA points_23[3];
    PathPointA points_24[5];
    PathPointA points_25[5];
    PathPointA points_26[2];
    PathPointB points_28[4];
    PathPointB points_30[4];
    PathPointA points_31[2];
    PathPointA points_32[5];
    PathPointA points_33[5];
};

extern "C" KarenScheduleData const gKarenScheduleData;

#endif // NPC_SCHEDULE_KAREN_HH
