#ifndef NPC_SCHEDULE_GRAY_HH
#define NPC_SCHEDULE_GRAY_HH

#include "npc_schedule.hh"

extern "C" u32 SelectGraySchedule(void const * context);

struct GrayScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[10];
    Schedule table_storage[9];
    ScheduleEntry entries_0[10];
    ScheduleEntry entries_1[9];
    ScheduleEntry entries_2[7];
    ScheduleEntry entries_3[12];
    ScheduleEntry entries_4[10];
    ScheduleEntry entries_5[9];
    ScheduleEntry entries_6[9];
    ScheduleEntry entries_7[1];
    ScheduleEntry entries_8[1];
    PathInfo payload_storage[22];
    PathPointA points_1[3];
    PathPointA points_2[2];
    PathPointA points_3[2];
    PathPointA points_4[5];
    PathPointB points_5[4];
    PathPointA points_6[3];
    PathPointA points_7[3];
    PathPointA points_8[5];
    PathPointA points_9[5];
    PathPointA points_11[5];
    PathPointA points_13[2];
    PathPointA points_15[2];
    PathPointA points_16[3];
    PathPointA points_19[5];
    PathPointA points_20[3];
    PathPointA points_21[3];
};

extern "C" GrayScheduleData const gGrayScheduleData;

#endif // NPC_SCHEDULE_GRAY_HH
