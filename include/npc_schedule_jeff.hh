#ifndef NPC_SCHEDULE_JEFF_HH
#define NPC_SCHEDULE_JEFF_HH

#include "npc_schedule.hh"

extern "C" u32 SelectJeffSchedule(void const * context);

struct NpcScheduleExtendedStorage
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage_0[3];
    ScheduleEntry entry_storage_1[7];
    ScheduleEntry entry_storage_2[5];
    ScheduleEntry entry_storage_3[1];
    PathInfo payload_storage[10];
    NpcScheduleDetailEntry detail_storage_0[3];
    NpcScheduleDetailEntry detail_storage_1[3];
    NpcScheduleDetailEntry detail_storage_2[3];
    NpcScheduleDetailEntry detail_storage_3[5];
    NpcScheduleDetailEntry detail_storage_4[5];
};

extern "C" NpcScheduleExtendedStorage const gUnk_080F3408;

#endif // NPC_SCHEDULE_JEFF_HH
