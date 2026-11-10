#ifndef NPC_SCHEDULE_SAIBARA_HH
#define NPC_SCHEDULE_SAIBARA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectSaibaraSchedule(void const * context);

struct SaibaraScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entries_0[8];
    ScheduleEntry entries_1[19];
    ScheduleEntry entries_2[8];
    ScheduleEntry entries_3[1];
    ScheduleEntry entries_4[1];
    PathInfo payload_storage[15];
    PathPointB points_0[2];
    PathPointA points_2[3];
    PathPointA points_3[5];
    PathPointA points_5[5];
    PathPointA points_6[3];
    PathPointA points_8[3];
    PathPointA points_9[3];
    PathPointA points_10[3];
    PathPointA points_11[2];
    PathPointA points_13[2];
    PathPointA points_14[3];
};

extern "C" SaibaraScheduleData const gSaibaraScheduleData;

#endif // NPC_SCHEDULE_SAIBARA_HH
