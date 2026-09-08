#include "prelude.h"

#include "schedule_info.hh"

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

ScheduleInfo const ScheduleInfo_Unk_080F1A80 = {
    func_0803DA24,
    5,
    Unk_080F1A80_Schedules,
};

Schedule const * const Unk_080F1A80_Schedules[5] = {
    nullptr, &Unk_080F1A80_Schedule_1, &Unk_080F1A80_Schedule_2, &Unk_080F1A80_Schedule_3, &Unk_080F1A80_Schedule_4,
};

Schedule const Unk_080F1A80_Schedule_1 = { 17, Unk_080F1A80_Schedule_1_Entries };

Schedule const Unk_080F1A80_Schedule_2 = { 9, Unk_080F1A80_Schedule_2_Entries };

Schedule const Unk_080F1A80_Schedule_3 = { 17, Unk_080F1A80_Schedule_3_Entries };

Schedule const Unk_080F1A80_Schedule_4 = { 1, Unk_080F1A80_Schedule_4_Entries };

ScheduleEntry const Unk_080F1A80_Schedule_1_Entries[17] = {
    { 0, &Unk_080F1A80_19_Path },    /* 06:00 */
    { 60, &Unk_080F1A80_21_Path },   /* 07:00 */
    { 91, &Unk_080F1A80_2_Path },    /* 07:31 */
    { 139, &Unk_080F1A80_3_Path },   /* 08:19 */
    { 242, &Unk_080F1A80_4_Path },   /* 10:02 */
    { 291, &Unk_080F1A80_5_Path },   /* 10:51 */
    { 321, &Unk_080F1A80_1_Path },   /* 11:21 */
    { 423, &Unk_080F1A80_18_Path },  /* 13:03 */
    { 430, &Unk_080F1A80_19_Path },  /* 13:10 */
    { 600, &Unk_080F1A80_20_Path },  /* 16:00 */
    { 607, &Unk_080F1A80_1_Path },   /* 16:07 */
    { 780, &Unk_080F1A80_6_Path },   /* 19:00 */
    { 827, &Unk_080F1A80_7_Path },   /* 19:47 */
    { 861, &Unk_080F1A80_8_Path },   /* 20:21 */
    { 972, &Unk_080F1A80_9_Path },   /* 22:12 */
    { 1007, &Unk_080F1A80_10_Path }, /* 22:47 */
    { 1054, &Unk_080F1A80_0_Path },  /* 23:34 */
};

ScheduleEntry const Unk_080F1A80_Schedule_2_Entries[9] = {
    { 0, &Unk_080F1A80_19_Path },    /* 06:00 */
    { 60, &Unk_080F1A80_20_Path },   /* 07:00 */
    { 67, &Unk_080F1A80_0_Path },    /* 07:07 */
    { 780, &Unk_080F1A80_6_Path },   /* 19:00 */
    { 827, &Unk_080F1A80_7_Path },   /* 19:47 */
    { 861, &Unk_080F1A80_8_Path },   /* 20:21 */
    { 972, &Unk_080F1A80_9_Path },   /* 22:12 */
    { 1007, &Unk_080F1A80_10_Path }, /* 22:47 */
    { 1054, &Unk_080F1A80_0_Path },  /* 23:34 */
};

ScheduleEntry const Unk_080F1A80_Schedule_3_Entries[17] = {
    { 0, &Unk_080F1A80_19_Path },    /* 06:00 */
    { 60, &Unk_080F1A80_22_Path },   /* 07:00 */
    { 108, &Unk_080F1A80_11_Path },  /* 07:48 */
    { 117, &Unk_080F1A80_12_Path },  /* 07:57 */
    { 240, &Unk_080F1A80_13_Path },  /* 10:00 */
    { 250, &Unk_080F1A80_14_Path },  /* 10:10 */
    { 297, &Unk_080F1A80_1_Path },   /* 10:57 */
    { 420, &Unk_080F1A80_15_Path },  /* 13:00 */
    { 438, &Unk_080F1A80_16_Path },  /* 13:18 */
    { 600, &Unk_080F1A80_17_Path },  /* 16:00 */
    { 618, &Unk_080F1A80_1_Path },   /* 16:18 */
    { 780, &Unk_080F1A80_6_Path },   /* 19:00 */
    { 827, &Unk_080F1A80_7_Path },   /* 19:47 */
    { 861, &Unk_080F1A80_8_Path },   /* 20:21 */
    { 972, &Unk_080F1A80_9_Path },   /* 22:12 */
    { 1007, &Unk_080F1A80_10_Path }, /* 22:47 */
    { 1054, &Unk_080F1A80_0_Path },  /* 23:34 */
};

ScheduleEntry const Unk_080F1A80_Schedule_4_Entries[1] = {
    { 0, &Unk_080F1A80_0_Path }, /* 06:00 */
};

PathInfo const Unk_080F1A80_0_Path = {
    nullptr, /* points */
    0,       /* num_points */
    72,      /* x_start */
    80,      /* y_start */
    11,      /* location_start */
    0,       /* facing_start */
    0,       /* point_type_select */
};

PathInfo const Unk_080F1A80_1_Path = {
    nullptr, /* points */
    0,       /* num_points */
    64,      /* x_start */
    83,      /* y_start */
    10,      /* location_start */
    1,       /* facing_start */
    0,       /* point_type_select */
};

PathInfo const Unk_080F1A80_2_Path = {
    (void const *)Unk_080F1A80_2_Path_Points, /* points */
    5,                                        /* num_points */
    104,                                      /* x_start */
    704,                                      /* y_start */
    5,                                        /* location_start */
    0,                                        /* facing_start */
    0,                                        /* point_type_select */
};

PathInfo const Unk_080F1A80_3_Path = {
    nullptr, /* points */
    0,       /* num_points */
    776,     /* x_start */
    184,     /* y_start */
    5,       /* location_start */
    0,       /* facing_start */
    0,       /* point_type_select */
};

PathInfo const Unk_080F1A80_4_Path = {
    (void const *)Unk_080F1A80_4_Path_Points, /* points */
    5,                                        /* num_points */
    776,                                      /* x_start */
    184,                                      /* y_start */
    5,                                        /* location_start */
    0,                                        /* facing_start */
    0,                                        /* point_type_select */
};

PathInfo const Unk_080F1A80_5_Path = {
    (void const *)Unk_080F1A80_5_Path_Points, /* points */
    5,                                        /* num_points */
    104,                                      /* x_start */
    0,                                        /* y_start */
    7,                                        /* location_start */
    0,                                        /* facing_start */
    0,                                        /* point_type_select */
};

PathInfo const Unk_080F1A80_6_Path = {
    (void const *)Unk_080F1A80_6_Path_Points, /* points */
    7,                                        /* num_points */
    572,                                      /* x_start */
    227,                                      /* y_start */
    7,                                        /* location_start */
    0,                                        /* facing_start */
    0,                                        /* point_type_select */
};

PathInfo const Unk_080F1A80_7_Path = {
    (void const *)Unk_080F1A80_7_Path_Points, /* points */
    3,                                        /* num_points */
    1260,                                     /* x_start */
    704,                                      /* y_start */
    5,                                        /* location_start */
    0,                                        /* facing_start */
    0,                                        /* point_type_select */
};

PathInfo const Unk_080F1A80_8_Path = {
    nullptr, /* points */
    0,       /* num_points */
    232,     /* x_start */
    120,     /* y_start */
    21,      /* location_start */
    1,       /* facing_start */
    0,       /* point_type_select */
};

PathInfo const Unk_080F1A80_9_Path = {
    (void const *)Unk_080F1A80_9_Path_Points, /* points */
    3,                                        /* num_points */
    632,                                      /* x_start */
    488,                                      /* y_start */
    5,                                        /* location_start */
    0,                                        /* facing_start */
    0,                                        /* point_type_select */
};

PathInfo const Unk_080F1A80_10_Path = {
    (void const *)Unk_080F1A80_10_Path_Points, /* points */
    7,                                         /* num_points */
    1272,                                      /* x_start */
    0,                                         /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_11_Path = {
    (void const *)Unk_080F1A80_11_Path_Points, /* points */
    2,                                         /* num_points */
    220,                                       /* x_start */
    448,                                       /* y_start */
    6,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_12_Path = {
    (void const *)Unk_080F1A80_12_Path_Points, /* points */
    2,                                         /* num_points */
    376,                                       /* x_start */
    384,                                       /* y_start */
    6,                                         /* location_start */
    0,                                         /* facing_start */
    1,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_13_Path = {
    (void const *)Unk_080F1A80_13_Path_Points, /* points */
    2,                                         /* num_points */
    376,                                       /* x_start */
    384,                                       /* y_start */
    6,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_14_Path = {
    (void const *)Unk_080F1A80_14_Path_Points, /* points */
    7,                                         /* num_points */
    1272,                                      /* x_start */
    0,                                         /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_15_Path = {
    (void const *)Unk_080F1A80_15_Path_Points, /* points */
    5,                                         /* num_points */
    572,                                       /* x_start */
    227,                                       /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_16_Path = {
    nullptr, /* points */
    0,       /* num_points */
    88,      /* x_start */
    88,      /* y_start */
    38,      /* location_start */
    0,       /* facing_start */
    0,       /* point_type_select */
};

PathInfo const Unk_080F1A80_17_Path = {
    (void const *)Unk_080F1A80_17_Path_Points, /* points */
    5,                                         /* num_points */
    296,                                       /* x_start */
    116,                                       /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_18_Path = {
    (void const *)Unk_080F1A80_18_Path_Points, /* points */
    3,                                         /* num_points */
    572,                                       /* x_start */
    227,                                       /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_19_Path = {
    (void const *)Unk_080F1A80_19_Path_Points, /* points */
    4,                                         /* num_points */
    520,                                       /* x_start */
    352,                                       /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    1,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_20_Path = {
    (void const *)Unk_080F1A80_20_Path_Points, /* points */
    3,                                         /* num_points */
    520,                                       /* x_start */
    352,                                       /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_21_Path = {
    (void const *)Unk_080F1A80_21_Path_Points, /* points */
    5,                                         /* num_points */
    520,                                       /* x_start */
    352,                                       /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathInfo const Unk_080F1A80_22_Path = {
    (void const *)Unk_080F1A80_22_Path_Points, /* points */
    7,                                         /* num_points */
    520,                                       /* x_start */
    352,                                       /* y_start */
    7,                                         /* location_start */
    0,                                         /* facing_start */
    0,                                         /* point_type_select */
};

PathPointA const Unk_080F1A80_2_Path_Points[5] = {
    { 19, 240, 1 }, { 21, 144, 0 }, { 22, 216, 1 }, { 47, 776, 0 }, { 48, 184, 1 },
};

PathPointA const Unk_080F1A80_4_Path_Points[5] = {
    { 1, 216, 1 }, { 26, 144, 0 }, { 27, 240, 1 }, { 29, 104, 0 }, { 49, 736, 1 },
};

PathPointA const Unk_080F1A80_5_Path_Points[5] = {
    { 6, 152, 1 }, { 21, 472, 0 }, { 25, 248, 1 }, { 29, 572, 0 }, { 30, 227, 1 },
};

PathPointA const Unk_080F1A80_6_Path_Points[7] = {
    { 1, 248, 1 }, { 5, 472, 0 }, { 9, 152, 1 }, { 40, 1248, 0 }, { 41, 128, 1 }, { 42, 1272, 0 }, { 47, 0, 1 },
};

PathPointA const Unk_080F1A80_7_Path_Points[3] = {
    { 7, 536, 1 },
    { 32, 632, 0 },
    { 34, 488, 1 },
};

PathPointA const Unk_080F1A80_9_Path_Points[3] = {
    { 2, 536, 1 },
    { 27, 1260, 0 },
    { 35, 736, 1 },
};

PathPointA const Unk_080F1A80_10_Path_Points[7] = {
    { 5, 128, 1 }, { 6, 1248, 0 }, { 7, 152, 1 }, { 38, 472, 0 }, { 42, 248, 1 }, { 46, 572, 0 }, { 47, 227, 1 },
};

PathPointA const Unk_080F1A80_11_Path_Points[2] = {
    { 3, 384, 1 },
    { 9, 376, 0 },
};

PathPointB const Unk_080F1A80_12_Path_Points[2] = {
    { 304, 2, 120, 0, 1 },
    { 384, 2, 120, 1, 1 },
};

PathPointA const Unk_080F1A80_13_Path_Points[2] = {
    { 6, 220, 0 },
    { 10, 480, 1 },
};

PathPointA const Unk_080F1A80_14_Path_Points[7] = {
    { 5, 128, 1 }, { 6, 1248, 0 }, { 7, 152, 1 }, { 38, 472, 0 }, { 42, 248, 1 }, { 46, 572, 0 }, { 47, 227, 1 },
};

PathPointA const Unk_080F1A80_15_Path_Points[5] = {
    { 1, 248, 1 }, { 5, 472, 0 }, { 9, 152, 1 }, { 16, 296, 0 }, { 18, 116, 1 },
};

PathPointA const Unk_080F1A80_17_Path_Points[5] = {
    { 2, 152, 1 }, { 9, 472, 0 }, { 13, 248, 1 }, { 17, 572, 0 }, { 18, 227, 1 },
};

PathPointA const Unk_080F1A80_18_Path_Points[3] = {
    { 1, 248, 1 },
    { 3, 520, 0 },
    { 7, 352, 1 },
};

PathPointB const Unk_080F1A80_19_Path_Points[4] = {
    { 440, 2, 0, 0, 0 },
    { 256, 2, 120, 2, 1 },
    { 352, 2, 0, 0, 1 },
    { 520, 2, 120, 3, 0 },
};

PathPointA const Unk_080F1A80_20_Path_Points[3] = {
    { 4, 248, 1 },
    { 6, 572, 0 },
    { 7, 227, 1 },
};

PathPointA const Unk_080F1A80_21_Path_Points[5] = {
    { 4, 248, 1 }, { 6, 472, 0 }, { 10, 152, 1 }, { 25, 104, 0 }, { 31, 0, 1 },
};

PathPointA const Unk_080F1A80_22_Path_Points[7] = {
    { 4, 248, 1 }, { 6, 472, 0 }, { 10, 152, 1 }, { 41, 1248, 0 }, { 42, 128, 1 }, { 43, 1272, 0 }, { 48, 0, 1 },
};

// This ordinary C++ string occupies the final slot of the recovered schedule
// object.  Its terminator and the following four-byte boundary reproduce the
// original 12-byte runtime string slot without manual zero-byte padding.
extern char const gCppRuntimeBadAlloc_DataSchedules[] ALIGN(4) =
    "bad_alloc";

// Recovered schedule data at US ROM 0x080F1FC0 (JP 0x080F181C).
// The two regional payloads differ only in relocated function/data pointers.

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

ScheduleInfo const gUnk_080F1FC0 = {
    func_0803DA7C,
    24,
    gUnk_080F1FCC,
};

Schedule const * const gUnk_080F1FCC[] = {
    nullptr, &gUnk_080F202C, &gUnk_080F2034, &gUnk_080F203C,
    &gUnk_080F2044, &gUnk_080F204C, &gUnk_080F2054, &gUnk_080F205C,
    &gUnk_080F2064, &gUnk_080F206C, &gUnk_080F2074, &gUnk_080F207C,
    &gUnk_080F2084, &gUnk_080F208C, &gUnk_080F2094, &gUnk_080F209C,
    &gUnk_080F20A4, &gUnk_080F20AC, &gUnk_080F20B4, &gUnk_080F20BC,
    &gUnk_080F20C4, &gUnk_080F20CC, &gUnk_080F20D4, &gUnk_080F20DC,
};

Schedule const gUnk_080F202C = { 8, gUnk_080F20E4 };
Schedule const gUnk_080F2034 = { 2, gUnk_080F2124 };
Schedule const gUnk_080F203C = { 11, gUnk_080F2134 };
Schedule const gUnk_080F2044 = { 8, gUnk_080F218C };
Schedule const gUnk_080F204C = { 8, gUnk_080F21CC };
Schedule const gUnk_080F2054 = { 4, gUnk_080F220C };
Schedule const gUnk_080F205C = { 4, gUnk_080F222C };
Schedule const gUnk_080F2064 = { 4, gUnk_080F224C };
Schedule const gUnk_080F206C = { 4, gUnk_080F226C };
Schedule const gUnk_080F2074 = { 4, gUnk_080F228C };
Schedule const gUnk_080F207C = { 4, gUnk_080F22AC };
Schedule const gUnk_080F2084 = { 4, gUnk_080F22CC };
Schedule const gUnk_080F208C = { 4, gUnk_080F22EC };
Schedule const gUnk_080F2094 = { 4, gUnk_080F230C };
Schedule const gUnk_080F209C = { 4, gUnk_080F232C };
Schedule const gUnk_080F20A4 = { 1, gUnk_080F234C };
Schedule const gUnk_080F20AC = { 5, gUnk_080F2354 };
Schedule const gUnk_080F20B4 = { 4, gUnk_080F237C };
Schedule const gUnk_080F20BC = { 1, gUnk_080F239C };
Schedule const gUnk_080F20C4 = { 8, gUnk_080F23A4 };
Schedule const gUnk_080F20CC = { 2, gUnk_080F23E4 };
Schedule const gUnk_080F20D4 = { 3, gUnk_080F23F4 };
Schedule const gUnk_080F20DC = { 1, gUnk_080F240C };

ScheduleEntry const gUnk_080F20E4[] = {
    { 0, &gUnk_080F2414 },
    { 60, &gUnk_080F2420 },
    { 98, &gUnk_080F242C },
    { 113, &gUnk_080F2438 },
    { 240, &gUnk_080F2444 },
    { 256, &gUnk_080F2450 },
    { 293, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F2124[] = {
    { 0, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F2134[] = {
    { 0, &gUnk_080F2414 },
    { 180, &gUnk_080F2468 },
    { 227, &gUnk_080F2474 },
    { 251, &gUnk_080F2480 },
    { 421, &gUnk_080F248C },
    { 446, &gUnk_080F2498 },
    { 462, &gUnk_080F24A4 },
    { 600, &gUnk_080F24B0 },
    { 608, &gUnk_080F24BC },
    { 655, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F218C[] = {
    { 0, &gUnk_080F2414 },
    { 180, &gUnk_080F2468 },
    { 227, &gUnk_080F2474 },
    { 251, &gUnk_080F2480 },
    { 600, &gUnk_080F248C },
    { 625, &gUnk_080F24BC },
    { 672, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F21CC[] = {
    { 0, &gUnk_080F2414 },
    { 420, &gUnk_080F2468 },
    { 467, &gUnk_080F24C8 },
    { 486, &gUnk_080F24D4 },
    { 600, &gUnk_080F24E0 },
    { 620, &gUnk_080F24BC },
    { 667, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F220C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F222C[] = {
    { 0, &gUnk_080F24EC },
    { 180, &gUnk_080F2414 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F224C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F226C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F228C[] = {
    { 0, &gUnk_080F24EC },
    { 180, &gUnk_080F2414 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F22AC[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F22CC[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F22EC[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F230C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F232C[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F24EC },
    { 840, &gUnk_080F2504 },
};

ScheduleEntry const gUnk_080F234C[] = {
    { 0, &gUnk_080F2414 },
};

ScheduleEntry const gUnk_080F2354[] = {
    { 0, &gUnk_080F2414 },
    { 240, &gUnk_080F2528 },
    { 250, &gUnk_080F2510 },
    { 300, &gUnk_080F251C },
    { 310, &gUnk_080F2414 },
};

ScheduleEntry const gUnk_080F237C[] = {
    { 0, &gUnk_080F2528 },
    { 10, &gUnk_080F2510 },
    { 60, &gUnk_080F251C },
    { 70, &gUnk_080F2414 },
};

ScheduleEntry const gUnk_080F239C[] = {
    { 0, &gUnk_080F2414 },
};

ScheduleEntry const gUnk_080F23A4[] = {
    { 0, &gUnk_080F2414 },
    { 120, &gUnk_080F2468 },
    { 167, &gUnk_080F24C8 },
    { 186, &gUnk_080F24D4 },
    { 240, &gUnk_080F24E0 },
    { 260, &gUnk_080F24BC },
    { 307, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F23E4[] = {
    { 0, &gUnk_080F2414 },
    { 780, &gUnk_080F245C },
};

ScheduleEntry const gUnk_080F23F4[] = {
    { 0, &gUnk_080F24EC },
    { 300, &gUnk_080F24F8 },
    { 720, &gUnk_080F2534 },
};

ScheduleEntry const gUnk_080F240C[] = {
    { 0, &gUnk_080F2504 },
};

PathInfo const gUnk_080F2414 = {
    (void const *)gUnk_080F2540,
    2,
    168,
    104,
    10,
    0,
    1,
};

PathInfo const gUnk_080F2420 = {
    (void const *)gUnk_080F2550,
    5,
    572,
    227,
    7,
    0,
    0,
};

PathInfo const gUnk_080F242C = {
    (void const *)gUnk_080F2578,
    8,
    1200,
    528,
    0,
    0,
    0,
};

PathInfo const gUnk_080F2438 = {
    (void const *)gUnk_080F25B8,
    4,
    984,
    416,
    0,
    0,
    1,
};

PathInfo const gUnk_080F2444 = {
    (void const *)gUnk_080F25D8,
    8,
    984,
    416,
    0,
    0,
    0,
};

PathInfo const gUnk_080F2450 = {
    (void const *)gUnk_080F2618,
    5,
    812,
    512,
    7,
    0,
    0,
};

PathInfo const gUnk_080F245C = {
    (void const *)gUnk_080F2640,
    2,
    168,
    72,
    11,
    0,
    1,
};

PathInfo const gUnk_080F2468 = {
    (void const *)gUnk_080F2650,
    7,
    572,
    227,
    7,
    0,
    0,
};

PathInfo const gUnk_080F2474 = {
    (void const *)gUnk_080F2688,
    5,
    1260,
    704,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2480 = {
    (void const *)gUnk_080F26B0,
    2,
    248,
    88,
    12,
    0,
    1,
};

PathInfo const gUnk_080F248C = {
    (void const *)gUnk_080F26C0,
    5,
    1232,
    156,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2498 = {
    (void const *)gUnk_080F26E8,
    2,
    220,
    0,
    6,
    0,
    0,
};

PathInfo const gUnk_080F24A4 = {
    (void const *)gUnk_080F26F8,
    2,
    280,
    352,
    6,
    0,
    1,
};

PathInfo const gUnk_080F24B0 = {
    (void const *)gUnk_080F2708,
    2,
    280,
    352,
    6,
    0,
    0,
};

PathInfo const gUnk_080F24BC = {
    (void const *)gUnk_080F2718,
    7,
    1272,
    0,
    7,
    0,
    0,
};

PathInfo const gUnk_080F24C8 = {
    (void const *)gUnk_080F2750,
    5,
    0,
    280,
    1,
    0,
    0,
};

PathInfo const gUnk_080F24D4 = {
    nullptr,
    0,
    256,
    232,
    1,
    3,
    0,
};

PathInfo const gUnk_080F24E0 = {
    (void const *)gUnk_080F2778,
    5,
    256,
    232,
    1,
    0,
    0,
};

PathInfo const gUnk_080F24EC = {
    (void const *)gUnk_080F27A0,
    4,
    256,
    152,
    29,
    0,
    1,
};

PathInfo const gUnk_080F24F8 = {
    (void const *)gUnk_080F27C0,
    4,
    112,
    76,
    29,
    0,
    1,
};

PathInfo const gUnk_080F2504 = {
    nullptr,
    0,
    440,
    -48,
    29,
    0,
    0,
};

PathInfo const gUnk_080F2510 = {
    nullptr,
    0,
    228,
    145,
    2,
    1,
    0,
};

PathInfo const gUnk_080F251C = {
    (void const *)gUnk_080F27E0,
    2,
    228,
    145,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2528 = {
    (void const *)gUnk_080F27F0,
    2,
    340,
    0,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2534 = {
    nullptr,
    0,
    0,
    0,
    564,
    1,
    0,
};

PathPointB const gUnk_080F2540[] = {
    { 224, 2, 120, 3, 0 },
    { 168, 2, 120, 2, 0 },
};

PathPointA const gUnk_080F2550[] = {
    { 1, 248, 1 },
    { 5, 472, 0 },
    { 9, 152, 1 },
    { 23, 812, 0 },
    { 38, 544, 1 },
};

PathPointA const gUnk_080F2578[] = {
    { 1, 1176, 0 },
    { 2, 512, 1 },
    { 3, 1160, 0 },
    { 4, 496, 1 },
    { 5, 1144, 0 },
    { 6, 480, 1 },
    { 12, 984, 0 },
    { 15, 416, 1 },
};

PathPointB const gUnk_080F25B8[] = {
    { 944, 2, 0, 0, 0 },
    { 374, 2, 120, 3, 1 },
    { 416, 2, 0, 0, 1 },
    { 984, 2, 120, 1, 0 },
};

PathPointA const gUnk_080F25D8[] = {
    { 3, 480, 1 },
    { 9, 1144, 0 },
    { 10, 496, 1 },
    { 11, 1160, 0 },
    { 12, 512, 1 },
    { 13, 1176, 0 },
    { 14, 528, 1 },
    { 16, 1216, 0 },
};

PathPointA const gUnk_080F2618[] = {
    { 14, 152, 1 },
    { 28, 472, 0 },
    { 32, 248, 1 },
    { 36, 572, 0 },
    { 37, 227, 1 },
};

PathPointB const gUnk_080F2640[] = {
    { 138, 2, 120, 1, 1 },
    { 72, 2, 120, 0, 1 },
};

PathPointA const gUnk_080F2650[] = {
    { 1, 248, 1 },
    { 5, 472, 0 },
    { 9, 152, 1 },
    { 40, 1248, 0 },
    { 41, 128, 1 },
    { 42, 1272, 0 },
    { 47, 0, 1 },
};

PathPointA const gUnk_080F2688[] = {
    { 19, 240, 1 },
    { 20, 1248, 0 },
    { 21, 216, 1 },
    { 22, 1232, 0 },
    { 24, 156, 1 },
};

PathPointB const gUnk_080F26B0[] = {
    { 280, 2, 120, 3, 0 },
    { 248, 2, 120, 2, 0 },
};

PathPointA const gUnk_080F26C0[] = {
    { 2, 216, 1 },
    { 3, 1248, 0 },
    { 4, 240, 1 },
    { 5, 1260, 0 },
    { 25, 736, 1 },
};

PathPointA const gUnk_080F26E8[] = {
    { 14, 352, 1 },
    { 16, 280, 0 },
};

PathPointB const gUnk_080F26F8[] = {
    { 344, 2, 120, 3, 0 },
    { 280, 2, 120, 2, 0 },
};

PathPointA const gUnk_080F2708[] = {
    { 3, 220, 0 },
    { 8, 480, 1 },
};

PathPointA const gUnk_080F2718[] = {
    { 5, 128, 1 },
    { 6, 1248, 0 },
    { 7, 152, 1 },
    { 38, 472, 0 },
    { 42, 248, 1 },
    { 46, 572, 0 },
    { 47, 227, 1 },
};

PathPointA const gUnk_080F2750[] = {
    { 3, 64, 0 },
    { 6, 360, 1 },
    { 8, 104, 0 },
    { 13, 232, 1 },
    { 19, 256, 0 },
};

PathPointA const gUnk_080F2778[] = {
    { 6, 104, 0 },
    { 11, 360, 1 },
    { 13, 64, 0 },
    { 16, 280, 1 },
    { 20, -16, 0 },
};

PathPointB const gUnk_080F27A0[] = {
    { 96, 2, 0, 0, 1 },
    { 328, 2, 120, 3, 0 },
    { 256, 2, 0, 0, 0 },
    { 152, 2, 120, 0, 1 },
};

PathPointB const gUnk_080F27C0[] = {
    { 108, 2, 120, 2, 1 },
    { 128, 2, 120, 3, 0 },
    { 76, 2, 120, 3, 1 },
    { 112, 2, 120, 2, 0 },
};

PathPointA const gUnk_080F27E0[] = {
    { 4, 340, 0 },
    { 10, 0, 1 },
};

PathPointA const gUnk_080F27F0[] = {
    { 6, 145, 1 },
    { 10, 228, 0 },
};

#if defined(REGION_JP)
extern char const gUnk_080F280C[] =
#else
extern char const gUnk_080F2800[] =
#endif
    "bad_alloc";
