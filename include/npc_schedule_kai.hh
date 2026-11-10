#ifndef NPC_SCHEDULE_KAI_HH
#define NPC_SCHEDULE_KAI_HH

#include "npc_schedule.hh"

extern "C" u32 SelectKaiSchedule(void const * context);

struct KaiScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entries_0[13];
    ScheduleEntry entries_1[7];
    ScheduleEntry entries_2[1];
    ScheduleEntry entries_3[1];
    PathInfo payload_storage[12];
    PathPointA points_1[3];
    PathPointA points_2[6];
    PathPointA points_4[3];
    PathPointA points_6[3];
    PathPointA points_7[6];
    PathPointA points_8[3];
    PathPointA points_9[5];
    PathPointA points_11[5];
};

extern "C" KaiScheduleData const gKaiScheduleData;

#endif // NPC_SCHEDULE_KAI_HH
