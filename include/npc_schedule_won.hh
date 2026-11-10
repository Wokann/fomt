#ifndef NPC_SCHEDULE_WON_HH
#define NPC_SCHEDULE_WON_HH

#include "npc_schedule.hh"

extern "C" u32 SelectWonSchedule(void const * context);

struct WonScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entries_0[1];
    ScheduleEntry entries_1[1];
    PathInfo payload_storage[1];
};

extern "C" WonScheduleData const gWonScheduleData;

#endif // NPC_SCHEDULE_WON_HH
