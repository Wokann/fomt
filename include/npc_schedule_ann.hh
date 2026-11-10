#ifndef NPC_SCHEDULE_ANN_HH
#define NPC_SCHEDULE_ANN_HH

#include "npc_schedule.hh"

extern "C" u32 SelectAnnSchedule(void const * context);

struct NpcScheduleStorage_080F43DC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[19];
    Schedule table_storage[18];
    ScheduleEntry entry_storage[83];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[43];
};

extern "C" NpcScheduleStorage_080F43DC const gUnk_080F43DC;

#endif // NPC_SCHEDULE_ANN_HH
