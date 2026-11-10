#ifndef NPC_SCHEDULE_SASHA_HH
#define NPC_SCHEDULE_SASHA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectSashaSchedule(void const * context);

struct SashaScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entries_0[7];
    ScheduleEntry entries_1[3];
    ScheduleEntry entries_2[11];
    ScheduleEntry entries_3[1];
    PathInfo payload_storage[15];
    PathPointB points_0[2];
    PathPointA points_1[5];
    PathPointA points_2[2];
    PathPointA points_4[2];
    PathPointA points_5[5];
    PathPointA points_6[7];
    PathPointA points_8[7];
    PathPointA points_10[5];
    PathPointA points_11[5];
    PathPointB points_12[2];
    PathPointA points_14[3];
};

extern "C" SashaScheduleData const gSashaScheduleData;

#endif // NPC_SCHEDULE_SASHA_HH
