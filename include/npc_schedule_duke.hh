#ifndef NPC_SCHEDULE_DUKE_HH
#define NPC_SCHEDULE_DUKE_HH

#include "npc_schedule.hh"

extern "C" u32 SelectDukeSchedule(void const * context);

struct NpcScheduleStorage_080F6370
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[41];
    PathInfo payload_storage[13];
    NpcScheduleDetailEntry detail_storage[35];
};

extern "C" NpcScheduleStorage_080F6370 const gUnk_080F6370;

#endif // NPC_SCHEDULE_DUKE_HH
