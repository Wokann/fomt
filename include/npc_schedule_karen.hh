#ifndef NPC_SCHEDULE_KAREN_HH
#define NPC_SCHEDULE_KAREN_HH

#include "npc_schedule.hh"

extern "C" u32 SelectKarenSchedule(void const * context);

struct NpcScheduleLargeStorage
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[24];
    Schedule table_storage[23];
    ScheduleEntry entry_storage[120];
    PathInfo payload_storage[35];
    NpcScheduleDetailEntry detail_storage[108];
};

extern "C" NpcScheduleLargeStorage const gUnk_080F35E4;

#endif // NPC_SCHEDULE_KAREN_HH
