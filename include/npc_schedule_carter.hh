#ifndef NPC_SCHEDULE_CARTER_HH
#define NPC_SCHEDULE_CARTER_HH

#include "npc_schedule.hh"

extern "C" u32 SelectCarterSchedule(void const * context);

struct NpcScheduleStorage_080F6DE8
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[10];
    Schedule table_storage[9];
    ScheduleEntry entry_storage[23];
    PathInfo payload_storage[10];
    NpcScheduleDetailEntry detail_storage[11];
};

extern "C" NpcScheduleStorage_080F6DE8 const gUnk_080F6DE8;

#endif // NPC_SCHEDULE_CARTER_HH
