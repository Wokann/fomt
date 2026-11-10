#ifndef NPC_SCHEDULE_MANNA_HH
#define NPC_SCHEDULE_MANNA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectMannaSchedule(void const * context);

struct NpcScheduleStorage_080F66C4
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[39];
    PathInfo payload_storage[19];
    NpcScheduleDetailEntry detail_storage[59];
};

extern "C" NpcScheduleStorage_080F66C4 const gUnk_080F66C4;

#endif // NPC_SCHEDULE_MANNA_HH
