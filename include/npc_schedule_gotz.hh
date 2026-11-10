#ifndef NPC_SCHEDULE_GOTZ_HH
#define NPC_SCHEDULE_GOTZ_HH

#include "npc_schedule.hh"

extern "C" u32 SelectGotzSchedule(void const * context);

struct NpcScheduleStorage_080F7B40
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[15];
    Schedule table_storage[14];
    ScheduleEntry entry_storage[47];
    PathInfo payload_storage[24];
    NpcScheduleDetailEntry detail_storage[100];
};

extern "C" NpcScheduleStorage_080F7B40 const gUnk_080F7B40;

#endif // NPC_SCHEDULE_GOTZ_HH
