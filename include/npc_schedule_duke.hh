#ifndef NPC_SCHEDULE_DUKE_HH
#define NPC_SCHEDULE_DUKE_HH

#include "npc_schedule.hh"

extern "C" u32 SelectDukeSchedule(void const * context);

struct DukeScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entries_0[12];
    ScheduleEntry entries_1[7];
    ScheduleEntry entries_2[12];
    ScheduleEntry entries_3[9];
    ScheduleEntry entries_4[1];
    PathInfo payload_storage[13];
    PathPointB points_0[2];
    PathPointB points_2[2];
    PathPointA points_3[2];
    PathPointA points_5[5];
    PathPointA points_6[4];
    PathPointA points_7[3];
    PathPointA points_9[3];
    PathPointA points_10[7];
    PathPointA points_12[7];
};

extern "C" DukeScheduleData const gDukeScheduleData;

#endif // NPC_SCHEDULE_DUKE_HH
