#ifndef NPC_SCHEDULE_SASHA_HH
#define NPC_SCHEDULE_SASHA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectSashaSchedule(void const * context);

struct NpcScheduleFiveChoiceStorage
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage[22];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[45];
};

extern "C" NpcScheduleFiveChoiceStorage const gUnk_080F3FD8;

#endif // NPC_SCHEDULE_SASHA_HH
