#ifndef NPC_SCHEDULE_BASIL_HH
#define NPC_SCHEDULE_BASIL_HH

#include "npc_schedule.hh"

extern "C" u32 SelectBasilSchedule(void const * context);

struct NpcScheduleStorage_080F49C0
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage[30];
    PathInfo payload_storage[10];
    NpcScheduleDetailEntry detail_storage[64];
};

extern "C" NpcScheduleStorage_080F49C0 const gUnk_080F49C0;

#endif // NPC_SCHEDULE_BASIL_HH
