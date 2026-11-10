#ifndef NPC_SCHEDULE_SAIBARA_HH
#define NPC_SCHEDULE_SAIBARA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectSaibaraSchedule(void const * context);

struct NpcScheduleStorage_080F77FC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[37];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[34];
};

extern "C" NpcScheduleStorage_080F77FC const gUnk_080F77FC;

#endif // NPC_SCHEDULE_SAIBARA_HH
