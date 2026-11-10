#ifndef NPC_SCHEDULE_CLIFF_HH
#define NPC_SCHEDULE_CLIFF_HH

#include "npc_schedule.hh"

extern "C" u32 SelectCliffSchedule(void const * context);

struct CliffScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entries_0[5];
    ScheduleEntry entries_1[9];
    ScheduleEntry entries_2[6];
    ScheduleEntry entries_3[1];
    ScheduleEntry entries_4[1];
    PathInfo payload_storage[12];
    PathPointA points_1[7];
    PathPointA points_3[5];
    PathPointA points_4[7];
    PathPointB points_5[2];
    PathPointA points_6[2];
    PathPointA points_8[8];
    PathPointA points_10[7];
};

extern "C" CliffScheduleData const gCliffScheduleData;

#endif // NPC_SCHEDULE_CLIFF_HH
