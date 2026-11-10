#ifndef NPC_SCHEDULE_HARRIS_HH
#define NPC_SCHEDULE_HARRIS_HH

#include "npc_schedule.hh"

extern "C" u32 SelectHarrisSchedule(void const * context);

struct NpcScheduleStorage_080F6B4C
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entry_storage[17];
    PathInfo payload_storage[14];
    NpcScheduleDetailEntry detail_storage[39];
};

extern "C" NpcScheduleStorage_080F6B4C const gUnk_080F6B4C;

#endif // NPC_SCHEDULE_HARRIS_HH
