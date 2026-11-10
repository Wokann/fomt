#ifndef NPC_SCHEDULE_ELLI_HH
#define NPC_SCHEDULE_ELLI_HH

#include "npc_schedule.hh"

extern "C" u32 SelectElliSchedule(void const * context);

struct ElliScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[17];
    Schedule table_storage[16];
    ScheduleEntry entries_0[3];
    ScheduleEntry entries_1[9];
    ScheduleEntry entries_2[3];
    ScheduleEntry entries_3[9];
    ScheduleEntry entries_4[1];
    ScheduleEntry entries_5[5];
    ScheduleEntry entries_6[1];
    ScheduleEntry entries_7[4];
    ScheduleEntry entries_8[4];
    ScheduleEntry entries_9[4];
    ScheduleEntry entries_10[4];
    ScheduleEntry entries_11[4];
    ScheduleEntry entries_12[4];
    ScheduleEntry entries_13[4];
    ScheduleEntry entries_14[3];
    ScheduleEntry entries_15[1];
    PathInfo payload_storage[15];
    PathPointB points_0[2];
    PathPointA points_2[3];
    PathPointB points_3[2];
    PathPointA points_4[3];
    PathPointA points_6[3];
    PathPointA points_7[3];
    PathPointA points_8[2];
    PathPointB points_10[4];
    PathPointB points_12[4];
    PathPointA points_13[2];
};

extern "C" ElliScheduleData const gElliScheduleData;

#endif // NPC_SCHEDULE_ELLI_HH
