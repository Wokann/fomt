#ifndef NPC_SCHEDULE_STU_HH
#define NPC_SCHEDULE_STU_HH

#include "npc_schedule.hh"

extern "C" u32 SelectStuSchedule(void const * context);

struct NpcScheduleStorage_080F61FC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[13];
    PathInfo payload_storage[7];
    NpcScheduleDetailEntry detail_storage[12];
};

extern "C" NpcScheduleStorage_080F61FC const gUnk_080F61FC;

#endif // NPC_SCHEDULE_STU_HH
