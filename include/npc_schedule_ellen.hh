#ifndef NPC_SCHEDULE_ELLEN_HH
#define NPC_SCHEDULE_ELLEN_HH

#include "npc_schedule.hh"

extern "C" u32 SelectEllenSchedule(void const * context);

struct EllenScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entries_0[1];
    ScheduleEntry entries_1[1];
    PathInfo payload;
};

extern "C" EllenScheduleData const gEllenScheduleData;

#endif // NPC_SCHEDULE_ELLEN_HH
