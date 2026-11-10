#ifndef NPC_SCHEDULE_ANNA_HH
#define NPC_SCHEDULE_ANNA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectAnnaSchedule(void const * context);

struct NpcScheduleStorage_080F5540
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[32];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[70];
};

extern "C" NpcScheduleStorage_080F5540 const gUnk_080F5540;

#endif // NPC_SCHEDULE_ANNA_HH
