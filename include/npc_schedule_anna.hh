#ifndef NPC_SCHEDULE_ANNA_HH
#define NPC_SCHEDULE_ANNA_HH

#include "npc_schedule.hh"

extern "C" u32 SelectAnnaSchedule(void const * context);

struct AnnaScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entries_0[9];
    ScheduleEntry entries_1[3];
    ScheduleEntry entries_2[12];
    ScheduleEntry entries_3[7];
    ScheduleEntry entries_4[1];
    PathInfo payload_storage[15];
    PathPointA points_2[5];
    PathPointA points_3[2];
    PathPointA points_5[2];
    PathPointA points_6[5];
    PathPointA points_7[5];
    PathPointA points_8[20];
    PathPointA points_10[20];
    PathPointA points_11[5];
    PathPointA points_12[3];
    PathPointA points_14[3];
};

extern "C" AnnaScheduleData const gAnnaScheduleData;

#endif // NPC_SCHEDULE_ANNA_HH
