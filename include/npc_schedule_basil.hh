#ifndef NPC_SCHEDULE_BASIL_HH
#define NPC_SCHEDULE_BASIL_HH

#include "npc_schedule.hh"

extern "C" u32 SelectBasilSchedule(void const * context);

struct BasilScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entries_0[8];
    ScheduleEntry entries_1[13];
    ScheduleEntry entries_2[8];
    ScheduleEntry entries_3[1];
    PathInfo payload_storage[10];
    PathPointB points_0[2];
    PathPointA points_2[7];
    PathPointA points_4[7];
    PathPointA points_5[19];
    PathPointA points_7[19];
    PathPointA points_8[5];
    PathPointA points_9[5];
};

extern "C" BasilScheduleData const gBasilScheduleData;

#endif // NPC_SCHEDULE_BASIL_HH
