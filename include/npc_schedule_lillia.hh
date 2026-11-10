#ifndef NPC_SCHEDULE_LILLIA_HH
#define NPC_SCHEDULE_LILLIA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectLilliaSchedule(void const * context);

struct LilliaScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[4];
    Schedule table_storage[3];
    ScheduleEntry entries_0[3];
    ScheduleEntry entries_1[8];
    ScheduleEntry entries_2[1];
    PathInfo payload_storage[7];
    PathPointA points_2[7];
    PathPointA points_3[5];
    PathPointA points_5[5];
    PathPointA points_6[7];
};

extern "C" LilliaScheduleData const gLilliaScheduleData;

#endif // NPC_SCHEDULE_LILLIA_HH
