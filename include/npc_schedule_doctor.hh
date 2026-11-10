#ifndef NPC_SCHEDULE_DOCTOR_HH
#define NPC_SCHEDULE_DOCTOR_HH

#include "npc_schedule.hh"

extern "C" u32 SelectDoctorSchedule(void const * context);

struct DoctorScheduleData
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entries_0[3];
    ScheduleEntry entries_1[12];
    ScheduleEntry entries_2[10];
    ScheduleEntry entries_3[1];
    PathInfo payload_storage[13];
    PathPointB points_0[4];
    PathPointA points_2[5];
    PathPointA points_3[16];
    PathPointB points_4[4];
    PathPointA points_5[16];
    PathPointA points_6[5];
    PathPointA points_7[3];
    PathPointA points_9[3];
    PathPointA points_10[3];
    PathPointA points_12[3];
};

extern "C" DoctorScheduleData const gDoctorScheduleData;

#endif // NPC_SCHEDULE_DOCTOR_HH
