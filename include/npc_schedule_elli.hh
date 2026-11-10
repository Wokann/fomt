#ifndef NPC_SCHEDULE_ELLI_HH
#define NPC_SCHEDULE_ELLI_HH

#include "npc_schedule.hh"

extern "C" u32 SelectElliSchedule(void const * context);

struct NpcScheduleStorage_080F5D94
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[17];
    Schedule table_storage[16];
    ScheduleEntry entry_storage[63];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[28];
};

extern "C" NpcScheduleStorage_080F5D94 const gUnk_080F5D94;

#endif // NPC_SCHEDULE_ELLI_HH
