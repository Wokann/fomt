#ifndef NPC_SCHEDULE_GRAY_HH
#define NPC_SCHEDULE_GRAY_HH

#include "npc_schedule.hh"

extern "C" u32 SelectGraySchedule(void const * context);

struct NpcScheduleStorage_080F7294
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[10];
    Schedule table_storage[9];
    ScheduleEntry entry_storage[68];
    PathInfo payload_storage[22];
    NpcScheduleDetailEntry detail_storage[55];
};

extern "C" NpcScheduleStorage_080F7294 const gUnk_080F7294;

#endif // NPC_SCHEDULE_GRAY_HH
