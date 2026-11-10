#ifndef NPC_SCHEDULE_THOMAS_HH
#define NPC_SCHEDULE_THOMAS_HH

#include "npc_schedule.hh"

extern "C" u32 SelectThomasSchedule(void const * context);

struct NpcScheduleStorage_080F59CC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[8];
    Schedule table_storage[7];
    ScheduleEntry entry_storage[43];
    PathInfo payload_storage[18];
    NpcScheduleDetailEntry detail_storage[37];
};

extern "C" NpcScheduleStorage_080F59CC const gUnk_080F59CC;

#endif // NPC_SCHEDULE_THOMAS_HH
