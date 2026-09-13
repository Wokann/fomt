#ifndef DATA_SCHEDULES_HH
#define DATA_SCHEDULES_HH

#include "prelude.h"

struct PathPointA
{
    u16 instant;
    i16 coord;
    bool is_y_coord : 1;
};

struct PathPointB
{
    u16 coord;
    u16 speed;
    u16 unk_04; /* duration? */
    u16 facing : 2;
    bool is_y_coord : 1;
};

struct PathInfo
{
    void const * points;
    u16 num_points;
    i16 x_start;
    i16 y_start;
    u32 location_start : 10;
    u32 facing_start : 2;
    bool point_type_select : 1;
};

struct ScheduleEntry
{
    u16 time;
    PathInfo const * path;
};

struct Schedule
{
    u16 num_time_entries;
    ScheduleEntry const * time_entries;
};

struct ScheduleInfo
{
    u32 (*select_schedule)(void const * unk_arg_0);
    u32 num_schedules;
    Schedule const * const * schedules;
};

// These C++ runtime strings are physically interleaved with the schedule data.
extern char const gCppRuntimeBadAlloc_DataSchedules[];
#if defined(REGION_JP)
extern char const gUnk_080F280C[];
extern char const gUnk_080F29C0[];
extern char const gUnk_080F2AF8[];
extern char const gCppRuntimeBadAllocPrefix_FourthSchedule[];
extern char const gUnk_080F2DC0[];
extern char const gCppRuntimeBadAlloc_FifthSchedule[];
#else
extern char const gUnk_080F2800[];
extern char const gUnk_080F29B4[];
extern char const gUnk_080F2AEC[];
extern char const gUnk_080F2DB4[];
extern char const gUnk_080F3004[];
#endif
extern char const gUnk_080F33AC[];

// Schedule tables and path records, declared in their physical ROM order.
extern "C" u32 func_0803DA24(void const *);

extern ScheduleInfo const ScheduleInfo_Unk_080F1A80;
extern Schedule const * const Unk_080F1A80_Schedules[5];
extern Schedule const Unk_080F1A80_Schedule_1;
extern Schedule const Unk_080F1A80_Schedule_2;
extern Schedule const Unk_080F1A80_Schedule_3;
extern Schedule const Unk_080F1A80_Schedule_4;
extern ScheduleEntry const Unk_080F1A80_Schedule_1_Entries[17];
extern ScheduleEntry const Unk_080F1A80_Schedule_2_Entries[9];
extern ScheduleEntry const Unk_080F1A80_Schedule_3_Entries[17];
extern ScheduleEntry const Unk_080F1A80_Schedule_4_Entries[1];
extern PathInfo const Unk_080F1A80_0_Path;
extern PathInfo const Unk_080F1A80_1_Path;
extern PathInfo const Unk_080F1A80_2_Path;
extern PathInfo const Unk_080F1A80_3_Path;
extern PathInfo const Unk_080F1A80_4_Path;
extern PathInfo const Unk_080F1A80_5_Path;
extern PathInfo const Unk_080F1A80_6_Path;
extern PathInfo const Unk_080F1A80_7_Path;
extern PathInfo const Unk_080F1A80_8_Path;
extern PathInfo const Unk_080F1A80_9_Path;
extern PathInfo const Unk_080F1A80_10_Path;
extern PathInfo const Unk_080F1A80_11_Path;
extern PathInfo const Unk_080F1A80_12_Path;
extern PathInfo const Unk_080F1A80_13_Path;
extern PathInfo const Unk_080F1A80_14_Path;
extern PathInfo const Unk_080F1A80_15_Path;
extern PathInfo const Unk_080F1A80_16_Path;
extern PathInfo const Unk_080F1A80_17_Path;
extern PathInfo const Unk_080F1A80_18_Path;
extern PathInfo const Unk_080F1A80_19_Path;
extern PathInfo const Unk_080F1A80_20_Path;
extern PathInfo const Unk_080F1A80_21_Path;
extern PathInfo const Unk_080F1A80_22_Path;
extern PathPointA const Unk_080F1A80_2_Path_Points[5];
extern PathPointA const Unk_080F1A80_4_Path_Points[5];
extern PathPointA const Unk_080F1A80_5_Path_Points[5];
extern PathPointA const Unk_080F1A80_6_Path_Points[7];
extern PathPointA const Unk_080F1A80_7_Path_Points[3];
extern PathPointA const Unk_080F1A80_9_Path_Points[3];
extern PathPointA const Unk_080F1A80_10_Path_Points[7];
extern PathPointA const Unk_080F1A80_11_Path_Points[2];
extern PathPointB const Unk_080F1A80_12_Path_Points[2];
extern PathPointA const Unk_080F1A80_13_Path_Points[2];
extern PathPointA const Unk_080F1A80_14_Path_Points[7];
extern PathPointA const Unk_080F1A80_15_Path_Points[5];
extern PathPointA const Unk_080F1A80_17_Path_Points[5];
extern PathPointA const Unk_080F1A80_18_Path_Points[3];
extern PathPointB const Unk_080F1A80_19_Path_Points[4];
extern PathPointA const Unk_080F1A80_20_Path_Points[3];
extern PathPointA const Unk_080F1A80_21_Path_Points[5];
extern PathPointA const Unk_080F1A80_22_Path_Points[7];

extern "C" u32 func_0803DA7C(void const *);

extern ScheduleInfo const gUnk_080F1FC0;
extern Schedule const * const gUnk_080F1FCC[];
extern Schedule const gUnk_080F202C;
extern Schedule const gUnk_080F2034;
extern Schedule const gUnk_080F203C;
extern Schedule const gUnk_080F2044;
extern Schedule const gUnk_080F204C;
extern Schedule const gUnk_080F2054;
extern Schedule const gUnk_080F205C;
extern Schedule const gUnk_080F2064;
extern Schedule const gUnk_080F206C;
extern Schedule const gUnk_080F2074;
extern Schedule const gUnk_080F207C;
extern Schedule const gUnk_080F2084;
extern Schedule const gUnk_080F208C;
extern Schedule const gUnk_080F2094;
extern Schedule const gUnk_080F209C;
extern Schedule const gUnk_080F20A4;
extern Schedule const gUnk_080F20AC;
extern Schedule const gUnk_080F20B4;
extern Schedule const gUnk_080F20BC;
extern Schedule const gUnk_080F20C4;
extern Schedule const gUnk_080F20CC;
extern Schedule const gUnk_080F20D4;
extern Schedule const gUnk_080F20DC;
extern ScheduleEntry const gUnk_080F20E4[];
extern ScheduleEntry const gUnk_080F2124[];
extern ScheduleEntry const gUnk_080F2134[];
extern ScheduleEntry const gUnk_080F218C[];
extern ScheduleEntry const gUnk_080F21CC[];
extern ScheduleEntry const gUnk_080F220C[];
extern ScheduleEntry const gUnk_080F222C[];
extern ScheduleEntry const gUnk_080F224C[];
extern ScheduleEntry const gUnk_080F226C[];
extern ScheduleEntry const gUnk_080F228C[];
extern ScheduleEntry const gUnk_080F22AC[];
extern ScheduleEntry const gUnk_080F22CC[];
extern ScheduleEntry const gUnk_080F22EC[];
extern ScheduleEntry const gUnk_080F230C[];
extern ScheduleEntry const gUnk_080F232C[];
extern ScheduleEntry const gUnk_080F234C[];
extern ScheduleEntry const gUnk_080F2354[];
extern ScheduleEntry const gUnk_080F237C[];
extern ScheduleEntry const gUnk_080F239C[];
extern ScheduleEntry const gUnk_080F23A4[];
extern ScheduleEntry const gUnk_080F23E4[];
extern ScheduleEntry const gUnk_080F23F4[];
extern ScheduleEntry const gUnk_080F240C[];
extern PathInfo const gUnk_080F2414;
extern PathInfo const gUnk_080F2420;
extern PathInfo const gUnk_080F242C;
extern PathInfo const gUnk_080F2438;
extern PathInfo const gUnk_080F2444;
extern PathInfo const gUnk_080F2450;
extern PathInfo const gUnk_080F245C;
extern PathInfo const gUnk_080F2468;
extern PathInfo const gUnk_080F2474;
extern PathInfo const gUnk_080F2480;
extern PathInfo const gUnk_080F248C;
extern PathInfo const gUnk_080F2498;
extern PathInfo const gUnk_080F24A4;
extern PathInfo const gUnk_080F24B0;
extern PathInfo const gUnk_080F24BC;
extern PathInfo const gUnk_080F24C8;
extern PathInfo const gUnk_080F24D4;
extern PathInfo const gUnk_080F24E0;
extern PathInfo const gUnk_080F24EC;
extern PathInfo const gUnk_080F24F8;
extern PathInfo const gUnk_080F2504;
extern PathInfo const gUnk_080F2510;
extern PathInfo const gUnk_080F251C;
extern PathInfo const gUnk_080F2528;
extern PathInfo const gUnk_080F2534;
extern PathPointB const gUnk_080F2540[];
extern PathPointA const gUnk_080F2550[];
extern PathPointA const gUnk_080F2578[];
extern PathPointB const gUnk_080F25B8[];
extern PathPointA const gUnk_080F25D8[];
extern PathPointA const gUnk_080F2618[];
extern PathPointB const gUnk_080F2640[];
extern PathPointA const gUnk_080F2650[];
extern PathPointA const gUnk_080F2688[];
extern PathPointB const gUnk_080F26B0[];
extern PathPointA const gUnk_080F26C0[];
extern PathPointA const gUnk_080F26E8[];
extern PathPointB const gUnk_080F26F8[];
extern PathPointA const gUnk_080F2708[];
extern PathPointA const gUnk_080F2718[];
extern PathPointA const gUnk_080F2750[];
extern PathPointA const gUnk_080F2778[];
extern PathPointB const gUnk_080F27A0[];
extern PathPointB const gUnk_080F27C0[];
extern PathPointA const gUnk_080F27E0[];
extern PathPointA const gUnk_080F27F0[];

extern "C" u32 func_0803DC64(void const *);

// JP already assigns gUnk_080F280C to the preceding runtime string.
#if defined(REGION_JP)
extern ScheduleInfo const gUnk_080F2068;
#else
extern ScheduleInfo const gUnk_080F280C;
#endif
extern Schedule const * const gUnk_080F2818[];
extern Schedule const gUnk_080F2828;
extern Schedule const gUnk_080F2830;
extern Schedule const gUnk_080F2838;
extern ScheduleEntry const gUnk_080F2840[];
extern ScheduleEntry const gUnk_080F2858[];
extern ScheduleEntry const gUnk_080F2898[];
extern PathInfo const gUnk_080F28A0;
extern PathInfo const gUnk_080F28AC;
extern PathInfo const gUnk_080F28B8;
extern PathInfo const gUnk_080F28C4;
extern PathInfo const gUnk_080F28D0;
extern PathInfo const gUnk_080F28DC;
extern PathInfo const gUnk_080F28E8;
extern PathPointA const gUnk_080F28F4[];
extern PathPointA const gUnk_080F292C[];
extern PathPointA const gUnk_080F2954[];
extern PathPointA const gUnk_080F297C[];

extern "C" u32 func_0803DCB4(void const *);

#if defined(REGION_JP)
extern ScheduleInfo const gUnk_080F221C;
#else
extern ScheduleInfo const gUnk_080F29C0;
#endif
extern Schedule const * const gUnk_080F29CC[];
extern Schedule const gUnk_080F29E4;
extern Schedule const gUnk_080F29EC;
extern Schedule const gUnk_080F29F4;
extern Schedule const gUnk_080F29FC;
extern Schedule const gUnk_080F2A04;
extern ScheduleEntry const gUnk_080F2A0C[];
extern ScheduleEntry const gUnk_080F2A2C[];
extern ScheduleEntry const gUnk_080F2A4C[];
extern ScheduleEntry const gUnk_080F2A54[];
extern ScheduleEntry const gUnk_080F2A6C[];
extern PathInfo const gUnk_080F2A7C;
extern PathInfo const gUnk_080F2A88;
extern PathInfo const gUnk_080F2A94;
extern PathInfo const gUnk_080F2AA0;
extern PathPointB const gUnk_080F2AAC[];
extern PathPointB const gUnk_080F2ACC[];

extern "C" u32 func_0803DDE8(void const *);

#if defined(REGION_JP)
extern ScheduleInfo const ScheduleInfo_Unk_080F2354;
#else
extern ScheduleInfo const gUnk_080F2AF8;
#endif
extern Schedule const * const gUnk_080F2B04[];
extern Schedule const gUnk_080F2B1C;
extern Schedule const gUnk_080F2B24;
extern Schedule const gUnk_080F2B2C;
extern Schedule const gUnk_080F2B34;
extern Schedule const gUnk_080F2B3C;
extern ScheduleEntry const gUnk_080F2B44[];
extern ScheduleEntry const gUnk_080F2B6C[];
extern ScheduleEntry const gUnk_080F2BB4[];
extern ScheduleEntry const gUnk_080F2BE4[];
extern ScheduleEntry const gUnk_080F2BEC[];
extern PathInfo const gUnk_080F2BF4;
extern PathInfo const gUnk_080F2C00;
extern PathInfo const gUnk_080F2C0C;
extern PathInfo const gUnk_080F2C18;
extern PathInfo const gUnk_080F2C24;
extern PathInfo const gUnk_080F2C30;
extern PathInfo const gUnk_080F2C3C;
extern PathInfo const gUnk_080F2C48;
extern PathInfo const gUnk_080F2C54;
extern PathInfo const gUnk_080F2C60;
extern PathInfo const gUnk_080F2C6C;
extern PathInfo const gUnk_080F2C78;
extern PathPointA const gUnk_080F2C84[];
extern PathPointA const gUnk_080F2CBC[];
extern PathPointA const gUnk_080F2CE4[];
extern PathPointB const gUnk_080F2D1C[];
extern PathPointA const gUnk_080F2D2C[];
extern PathPointA const gUnk_080F2D3C[];
extern PathPointA const gUnk_080F2D7C[];

extern "C" u32 func_0803DECC(void const *);

#if defined(REGION_JP)
extern ScheduleInfo const ScheduleInfo_Unk_080F261C;
#else
extern ScheduleInfo const gUnk_080F2DC0;
#endif
extern Schedule const * const gUnk_080F2DCC[];
extern Schedule const gUnk_080F2DD8;
extern Schedule const gUnk_080F2DE0;
extern ScheduleEntry const gUnk_080F2DE8[];
#if defined(REGION_JP)
extern ScheduleEntry const gUnk_080F3010[];
#endif
extern ScheduleEntry const gUnk_080F2E60[];
extern PathInfo const gUnk_080F2E68;
extern PathInfo const gUnk_080F2E74;
extern PathInfo const gUnk_080F2E80;
extern PathInfo const gUnk_080F2E8C;
extern PathInfo const gUnk_080F2E98;
extern PathInfo const gUnk_080F2EA4;
extern PathInfo const gUnk_080F2EB0;
extern PathInfo const gUnk_080F2EBC;
extern PathInfo const gUnk_080F2EC8;
extern PathInfo const gUnk_080F2ED4;
extern PathInfo const gUnk_080F2EE0;
extern PathPointB const gUnk_080F2EEC[];
extern PathPointA const gUnk_080F2EFC[];
extern PathPointA const gUnk_080F2F2C[];
extern PathPointA const gUnk_080F2F54[];
extern PathPointA const gUnk_080F2F7C[];
extern PathPointA const gUnk_080F2FAC[];
extern PathPointA const gUnk_080F2FC4[];
extern PathPointA const gUnk_080F2FDC[];

extern "C" u32 func_0803DEF8(void const *);

#if defined(REGION_JP)
extern ScheduleInfo const ScheduleInfo_Unk_080F286C;
#else
extern ScheduleInfo const gUnk_080F3010;
#endif
extern Schedule const * const gUnk_080F301C[];
extern Schedule const gUnk_080F3030;
extern Schedule const gUnk_080F3038;
extern Schedule const gUnk_080F3040;
extern Schedule const gUnk_080F3048;
extern ScheduleEntry const gUnk_080F3050[];
extern ScheduleEntry const gUnk_080F3068[];
extern ScheduleEntry const gUnk_080F30C8[];
extern ScheduleEntry const gUnk_080F3118[];
extern PathInfo const gUnk_080F3120;
extern PathInfo const gUnk_080F312C;
extern PathInfo const gUnk_080F3138;
extern PathInfo const gUnk_080F3144;
extern PathInfo const gUnk_080F3150;
extern PathInfo const gUnk_080F315C;
extern PathInfo const gUnk_080F3168;
extern PathInfo const gUnk_080F3174;
extern PathInfo const gUnk_080F3180;
extern PathInfo const gUnk_080F318C;
extern PathInfo const gUnk_080F3198;
extern PathInfo const gUnk_080F31A4;
extern PathInfo const gUnk_080F31B0;
extern PathPointB const gUnk_080F31BC[];
extern PathPointA const gUnk_080F31DC[];
extern PathPointA const gUnk_080F3204[];
extern PathPointB const gUnk_080F3284[];
extern PathPointA const gUnk_080F32A4[];
extern PathPointA const gUnk_080F3324[];
extern PathPointA const gUnk_080F334C[];
extern PathPointA const gUnk_080F3364[];
extern PathPointA const gUnk_080F337C[];
extern PathPointA const gUnk_080F3394[];

#endif // DATA_SCHEDULES_HH
