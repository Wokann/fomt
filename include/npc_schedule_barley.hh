#ifndef NPC_SCHEDULE_BARLEY_HH
#define NPC_SCHEDULE_BARLEY_HH

#include "npc_schedule.hh"

extern "C" u32 SelectBarleySchedule(void const * context);

struct BarleyScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entries_0[4];
    ScheduleEntry entries_1[11];
    ScheduleEntry entries_2[8];
    ScheduleEntry entries_3[1];
    PathInfo payload_storage[13];
    PathPointB points_1[2];
    PathPointB points_2[2];
    PathPointA points_3[5];
    PathPointA points_4[6];
    PathPointA points_6[5];
    PathPointA points_7[9];
    PathPointB points_8[2];
    PathPointA points_9[9];
    PathPointA points_10[5];
    PathPointA points_11[7];
    PathPointA points_12[4];
};

extern "C" BarleyScheduleData const gBarleyScheduleData;

#endif // NPC_SCHEDULE_BARLEY_HH
