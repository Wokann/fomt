#ifndef NPC_SCHEDULE_HARRIS_HH
#define NPC_SCHEDULE_HARRIS_HH

#include "npc_schedule.hh"

extern "C" u32 SelectHarrisSchedule(void const * context);

struct HarrisScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entries_0[16];
    ScheduleEntry entries_1[1];
    PathInfo payload_storage[14];
    PathPointB points_0[2];
    PathPointA points_1[5];
    PathPointA points_2[7];
    PathPointA points_3[5];
    PathPointA points_5[3];
    PathPointA points_7[3];
    PathPointA points_8[3];
    PathPointA points_10[5];
    PathPointA points_11[3];
    PathPointA points_13[3];
};

extern "C" HarrisScheduleData const gHarrisScheduleData;

#endif // NPC_SCHEDULE_HARRIS_HH
