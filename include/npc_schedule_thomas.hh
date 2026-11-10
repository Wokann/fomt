#ifndef NPC_SCHEDULE_THOMAS_HH
#define NPC_SCHEDULE_THOMAS_HH

#include "npc_schedule.hh"

extern "C" u32 SelectThomasSchedule(void const * context);

struct ThomasScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[8];
    Schedule table_storage[7];
    ScheduleEntry entries_0[1];
    ScheduleEntry entries_1[11];
    ScheduleEntry entries_2[9];
    ScheduleEntry entries_3[9];
    ScheduleEntry entries_4[7];
    ScheduleEntry entries_5[1];
    ScheduleEntry entries_6[5];
    PathInfo payload_storage[18];
    PathPointA points_1[3];
    PathPointA points_3[3];
    PathPointA points_5[5];
    PathPointA points_6[2];
    PathPointA points_8[2];
    PathPointA points_9[5];
    PathPointA points_10[5];
    PathPointA points_12[5];
    PathPointA points_13[3];
    PathPointA points_14[2];
    PathPointA points_16[2];
};

extern "C" ThomasScheduleData const gThomasScheduleData;

#endif // NPC_SCHEDULE_THOMAS_HH
