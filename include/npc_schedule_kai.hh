#ifndef NPC_SCHEDULE_KAI_HH
#define NPC_SCHEDULE_KAI_HH

#include "npc_schedule.hh"

extern "C" u32 SelectKaiSchedule(void const * context);

struct NpcScheduleStorage_080F6FF8
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage[22];
    PathInfo payload_storage[12];
    NpcScheduleDetailEntry detail_storage[34];
};

extern "C" NpcScheduleStorage_080F6FF8 const gUnk_080F6FF8;

#endif // NPC_SCHEDULE_KAI_HH
