#ifndef NPC_SCHEDULE_BARLEY_HH
#define NPC_SCHEDULE_BARLEY_HH

#include "npc_schedule.hh"

extern "C" u32 SelectBarleySchedule(void const * context);

struct NpcScheduleStorage_080F8678
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage[24];
    PathInfo payload_storage[13];
    NpcScheduleDetailEntry detail_storage[56];
};

extern "C" NpcScheduleStorage_080F8678 const gUnk_080F8678;

#endif // NPC_SCHEDULE_BARLEY_HH
