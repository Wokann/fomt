#ifndef NPC_SCHEDULE_ZACK_HH
#define NPC_SCHEDULE_ZACK_HH

#include "npc_schedule.hh"

extern "C" u32 SelectZackSchedule(void const * context);

struct ZackScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entries_0[15];
    ScheduleEntry entries_1[1];
    PathInfo payload_storage[11];
    PathPointB points_0[2];
    PathPointA points_1[6];
    PathPointA points_2[5];
    PathPointA points_4[5];
    PathPointA points_5[6];
    PathPointA points_6[3];
    PathPointA points_8[3];
    PathPointA points_10[5];
};

extern "C" ZackScheduleData const gZackScheduleData;

#endif // NPC_SCHEDULE_ZACK_HH
