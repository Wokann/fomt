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

// Recovered schedule data at US ROM 0x080F280C (JP 0x080F2068).
// The two regional payloads differ only in relocated function/data pointers.

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

#if defined(REGION_JP)
ScheduleInfo const gUnk_080F2068 = {
#else
ScheduleInfo const gUnk_080F280C = {
#endif
    func_0803DC64,
    4,
    gUnk_080F2818,
};

Schedule const * const gUnk_080F2818[] = {
    nullptr, &gUnk_080F2828, &gUnk_080F2830, &gUnk_080F2838,
};

Schedule const gUnk_080F2828 = { 3, gUnk_080F2840 };
Schedule const gUnk_080F2830 = { 8, gUnk_080F2858 };
Schedule const gUnk_080F2838 = { 1, gUnk_080F2898 };

ScheduleEntry const gUnk_080F2840[] = {
    { 0, &gUnk_080F28A0 },
    { 300, &gUnk_080F28AC },
    { 780, &gUnk_080F28A0 },
};

ScheduleEntry const gUnk_080F2858[] = {
    { 0, &gUnk_080F28A0 },
    { 300, &gUnk_080F28AC },
    { 421, &gUnk_080F28B8 },
    { 468, &gUnk_080F28C4 },
    { 507, &gUnk_080F28D0 },
    { 600, &gUnk_080F28DC },
    { 640, &gUnk_080F28E8 },
    { 687, &gUnk_080F28A0 },
};

ScheduleEntry const gUnk_080F2898[] = {
    { 0, &gUnk_080F28A0 },
};

PathInfo const gUnk_080F28A0 = {
    nullptr,
    0,
    112,
    130,
    11,
    3,
    0,
};

PathInfo const gUnk_080F28AC = {
    nullptr,
    0,
    215,
    160,
    10,
    2,
    0,
};

PathInfo const gUnk_080F28B8 = {
    (void const *)gUnk_080F28F4,
    7,
    572,
    227,
    7,
    0,
    0,
};

PathInfo const gUnk_080F28C4 = {
    (void const *)gUnk_080F292C,
    5,
    1260,
    704,
    5,
    0,
    0,
};

PathInfo const gUnk_080F28D0 = {
    nullptr,
    0,
    40,
    246,
    19,
    3,
    0,
};

PathInfo const gUnk_080F28DC = {
    (void const *)gUnk_080F2954,
    5,
    856,
    164,
    5,
    0,
    0,
};

PathInfo const gUnk_080F28E8 = {
    (void const *)gUnk_080F297C,
    7,
    1272,
    0,
    7,
    0,
    0,
};

PathPointA const gUnk_080F28F4[] = {
    { 1, 248, 1 },
    { 5, 472, 0 },
    { 9, 152, 1 },
    { 40, 1248, 0 },
    { 41, 128, 1 },
    { 42, 1272, 0 },
    { 47, 0, 1 },
};

PathPointA const gUnk_080F292C[] = {
    { 19, 240, 1 },
    { 20, 1248, 0 },
    { 21, 216, 1 },
    { 37, 856, 0 },
    { 39, 164, 1 },
};

PathPointA const gUnk_080F2954[] = {
    { 2, 216, 1 },
    { 18, 1248, 0 },
    { 19, 240, 1 },
    { 20, 1260, 0 },
    { 40, 736, 1 },
};

PathPointA const gUnk_080F297C[] = {
    { 5, 128, 1 },
    { 6, 1248, 0 },
    { 7, 152, 1 },
    { 38, 472, 0 },
    { 42, 248, 1 },
    { 46, 572, 0 },
    { 47, 227, 1 },
};

#if defined(REGION_US)
extern char const gUnk_080F29B4[] =
    "bad_alloc";
#endif

// JP keeps this runtime string before the following schedule data.
#if defined(REGION_JP)
extern char const gUnk_080F29C0[] =
    "bad_alloc";
#endif

// Recovered schedule data at US ROM 0x080F29C0 (JP 0x080F221C).
// The two regional payloads differ only in relocated function/data pointers.

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

#if defined(REGION_JP)
ScheduleInfo const gUnk_080F221C = {
#else
ScheduleInfo const gUnk_080F29C0 = {
#endif
    func_0803DCB4,
    6,
    gUnk_080F29CC,
};

Schedule const * const gUnk_080F29CC[] = {
    nullptr, &gUnk_080F29E4, &gUnk_080F29EC, &gUnk_080F29F4,
    &gUnk_080F29FC, &gUnk_080F2A04,
};

Schedule const gUnk_080F29E4 = { 4, gUnk_080F2A0C };
Schedule const gUnk_080F29EC = { 4, gUnk_080F2A2C };
Schedule const gUnk_080F29F4 = { 1, gUnk_080F2A4C };
Schedule const gUnk_080F29FC = { 3, gUnk_080F2A54 };
Schedule const gUnk_080F2A04 = { 2, gUnk_080F2A6C };

ScheduleEntry const gUnk_080F2A0C[] = {
    { 0, &gUnk_080F2A7C },
    { 180, &gUnk_080F2A88 },
    { 720, &gUnk_080F2A7C },
    { 840, &gUnk_080F2A88 },
};

ScheduleEntry const gUnk_080F2A2C[] = {
    { 0, &gUnk_080F2A7C },
    { 300, &gUnk_080F2A88 },
    { 720, &gUnk_080F2A7C },
    { 840, &gUnk_080F2A88 },
};

ScheduleEntry const gUnk_080F2A4C[] = {
    { 0, &gUnk_080F2A88 },
};

ScheduleEntry const gUnk_080F2A54[] = {
    { 0, &gUnk_080F2A94 },
    { 300, &gUnk_080F2AA0 },
    { 720, &gUnk_080F2A88 },
};

ScheduleEntry const gUnk_080F2A6C[] = {
    { 0, &gUnk_080F2A7C },
    { 180, &gUnk_080F2A88 },
};

PathInfo const gUnk_080F2A7C = {
    nullptr,
    0,
    0,
    0,
    564,
    1,
    0,
};

PathInfo const gUnk_080F2A88 = {
    nullptr,
    0,
    416,
    -48,
    29,
    0,
    0,
};

PathInfo const gUnk_080F2A94 = {
    (void const *)gUnk_080F2AAC,
    4,
    352,
    128,
    29,
    0,
    1,
};

PathInfo const gUnk_080F2AA0 = {
    (void const *)gUnk_080F2ACC,
    4,
    56,
    128,
    29,
    0,
    1,
};

PathPointB const gUnk_080F2AAC[] = {
    { 408, 2, 120, 3, 0 },
    { 160, 2, 120, 0, 1 },
    { 352, 2, 120, 2, 0 },
    { 128, 2, 120, 1, 1 },
};

PathPointB const gUnk_080F2ACC[] = {
    { 160, 2, 120, 0, 1 },
    { 104, 2, 120, 3, 0 },
    { 128, 2, 120, 1, 1 },
    { 56, 2, 120, 2, 0 },
};

#if defined(REGION_US)
extern char const gUnk_080F2AEC[] =
    "bad_alloc";
#endif

// JP keeps this runtime string before the following schedule data.
#if defined(REGION_JP)
extern char const gUnk_080F2AF8[] =
    "bad_alloc";
#endif

// Recovered schedule data at US ROM 0x080F2AF8 (JP 0x080F2354).
// The two regional payloads differ only in relocated function/data pointers.

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

#if defined(REGION_JP)
ScheduleInfo const ScheduleInfo_Unk_080F2354 = {
#else
ScheduleInfo const gUnk_080F2AF8 = {
#endif
    func_0803DDE8,
    6,
    gUnk_080F2B04,
};

Schedule const * const gUnk_080F2B04[] = {
    nullptr, &gUnk_080F2B1C, &gUnk_080F2B24, &gUnk_080F2B2C,
    &gUnk_080F2B34, &gUnk_080F2B3C,
};

Schedule const gUnk_080F2B1C = { 5, gUnk_080F2B44 };
Schedule const gUnk_080F2B24 = { 9, gUnk_080F2B6C };
Schedule const gUnk_080F2B2C = { 6, gUnk_080F2BB4 };
Schedule const gUnk_080F2B34 = { 1, gUnk_080F2BE4 };
Schedule const gUnk_080F2B3C = { 1, gUnk_080F2BEC };

ScheduleEntry const gUnk_080F2B44[] = {
    { 0, &gUnk_080F2BF4 },
    { 180, &gUnk_080F2C00 },
    { 224, &gUnk_080F2C0C },
    { 605, &gUnk_080F2C18 },
    { 646, &gUnk_080F2BF4 },
};

ScheduleEntry const gUnk_080F2B6C[] = {
    { 0, &gUnk_080F2BF4 },
    { 240, &gUnk_080F2C24 },
    { 265, &gUnk_080F2C30 },
    { 420, &gUnk_080F2C3C },
    { 427, &gUnk_080F2C48 },
    { 600, &gUnk_080F2C54 },
    { 667, &gUnk_080F2C0C },
    { 783, &gUnk_080F2C18 },
    { 824, &gUnk_080F2BF4 },
};

ScheduleEntry const gUnk_080F2BB4[] = {
    { 0, &gUnk_080F2BF4 },
    { 420, &gUnk_080F2C60 },
    { 611, &gUnk_080F2C00 },
    { 655, &gUnk_080F2C0C },
    { 780, &gUnk_080F2C6C },
    { 824, &gUnk_080F2BF4 },
};

ScheduleEntry const gUnk_080F2BE4[] = {
    { 0, &gUnk_080F2BF4 },
};

ScheduleEntry const gUnk_080F2BEC[] = {
    { 0, &gUnk_080F2C78 },
};

PathInfo const gUnk_080F2BF4 = {
    nullptr,
    0,
    272,
    72,
    23,
    0,
    0,
};

PathInfo const gUnk_080F2C00 = {
    (void const *)gUnk_080F2C84,
    7,
    632,
    488,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C0C = {
    nullptr,
    0,
    104,
    155,
    12,
    1,
    0,
};

PathInfo const gUnk_080F2C18 = {
    (void const *)gUnk_080F2CBC,
    5,
    1232,
    156,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C24 = {
    (void const *)gUnk_080F2CE4,
    7,
    632,
    488,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C30 = {
    (void const *)gUnk_080F2D1C,
    2,
    176,
    88,
    34,
    0,
    1,
};

PathInfo const gUnk_080F2C3C = {
    (void const *)gUnk_080F2D2C,
    2,
    314,
    456,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C48 = {
    nullptr,
    0,
    456,
    476,
    5,
    1,
    0,
};

PathInfo const gUnk_080F2C54 = {
    (void const *)gUnk_080F2D3C,
    8,
    456,
    476,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C60 = {
    nullptr,
    0,
    64,
    136,
    21,
    0,
    0,
};

PathInfo const gUnk_080F2C6C = {
    (void const *)gUnk_080F2D7C,
    7,
    1232,
    160,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2C78 = {
    nullptr,
    0,
    432,
    232,
    19,
    0,
    0,
};

PathPointA const gUnk_080F2C84[] = {
    { 2, 536, 1 },
    { 27, 1260, 0 },
    { 39, 240, 1 },
    { 40, 1248, 0 },
    { 41, 216, 1 },
    { 42, 1232, 0 },
    { 44, 156, 1 },
};

PathPointA const gUnk_080F2CBC[] = {
    { 2, 216, 1 },
    { 19, 808, 0 },
    { 32, 536, 1 },
    { 39, 632, 0 },
    { 41, 488, 1 },
};

PathPointA const gUnk_080F2CE4[] = {
    { 2, 536, 1 },
    { 18, 232, 0 },
    { 20, 480, 1 },
    { 21, 265, 0 },
    { 22, 476, 1 },
    { 24, 316, 0 },
    { 25, 460, 1 },
};

PathPointB const gUnk_080F2D1C[] = {
    { 208, 2, 120, 1, 0 },
    { 176, 2, 120, 1, 0 },
};

PathPointA const gUnk_080F2D2C[] = {
    { 1, 476, 1 },
    { 7, 456, 0 },
};

PathPointA const gUnk_080F2D3C[] = {
    { 8, 265, 0 },
    { 9, 496, 1 },
    { 10, 232, 0 },
    { 12, 536, 1 },
    { 35, 808, 0 },
    { 48, 216, 1 },
    { 65, 1232, 0 },
    { 67, 156, 1 },
};

PathPointA const gUnk_080F2D7C[] = {
    { 2, 216, 1 },
    { 3, 1248, 0 },
    { 4, 240, 1 },
    { 5, 1260, 0 },
    { 17, 536, 1 },
    { 42, 632, 0 },
    { 44, 488, 1 },
};

#if defined(REGION_JP)
// The original JP label gUnk_080F2DC0 starts at the final character of this
// runtime string, so keep its suffix as a separately addressable C string.
extern char const gCppRuntimeBadAllocPrefix_FourthSchedule[] = {
    'b', 'a', 'd', '_', 'a', 'l', 'l', 'o',
};
extern char const gUnk_080F2DC0[] =
    "c";
#else
extern char const gUnk_080F2DB4[] =
    "bad_alloc";
#endif

// Recovered schedule data at US ROM 0x080F2DC0 (JP 0x080F261C).
// The two regional payloads differ only in relocated function/data pointers.

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

#if defined(REGION_JP)
ScheduleInfo const ScheduleInfo_Unk_080F261C = {
#else
ScheduleInfo const gUnk_080F2DC0 = {
#endif
    func_0803DECC,
    3,
    gUnk_080F2DCC,
};

Schedule const * const gUnk_080F2DCC[] = {
    nullptr, &gUnk_080F2DD8, &gUnk_080F2DE0,
};

Schedule const gUnk_080F2DD8 = { 15, gUnk_080F2DE8 };
Schedule const gUnk_080F2DE0 = { 1, gUnk_080F2E60 };

#if defined(REGION_JP)
// The original JP gUnk_080F3010 label starts at entry 6 of this table.
ScheduleEntry const gUnk_080F2DE8[] = {
    { 0, &gUnk_080F2E68 },
    { 60, &gUnk_080F2E74 },
    { 82, &gUnk_080F2E80 },
    { 127, &gUnk_080F2E8C },
    { 240, &gUnk_080F2E98 },
};

ScheduleEntry const gUnk_080F3010[] = {
    { 286, &gUnk_080F2EA4 },
    { 308, &gUnk_080F2E68 },
    { 630, &gUnk_080F2E74 },
    { 652, &gUnk_080F2EB0 },
    { 663, &gUnk_080F2EBC },
    { 720, &gUnk_080F2EC8 },
    { 731, &gUnk_080F2ED4 },
    { 786, &gUnk_080F2EE0 },
    { 833, &gUnk_080F2EA4 },
    { 855, &gUnk_080F2E68 },
};
#else
ScheduleEntry const gUnk_080F2DE8[] = {
    { 0, &gUnk_080F2E68 },
    { 60, &gUnk_080F2E74 },
    { 82, &gUnk_080F2E80 },
    { 127, &gUnk_080F2E8C },
    { 240, &gUnk_080F2E98 },
    { 286, &gUnk_080F2EA4 },
    { 308, &gUnk_080F2E68 },
    { 630, &gUnk_080F2E74 },
    { 652, &gUnk_080F2EB0 },
    { 663, &gUnk_080F2EBC },
    { 720, &gUnk_080F2EC8 },
    { 731, &gUnk_080F2ED4 },
    { 786, &gUnk_080F2EE0 },
    { 833, &gUnk_080F2EA4 },
    { 855, &gUnk_080F2E68 },
};
#endif

ScheduleEntry const gUnk_080F2E60[] = {
    { 0, &gUnk_080F2E68 },
};

PathInfo const gUnk_080F2E68 = {
    (void const *)gUnk_080F2EEC,
    2,
    176,
    88,
    13,
    0,
    1,
};

PathInfo const gUnk_080F2E74 = {
    (void const *)gUnk_080F2EFC,
    6,
    212,
    108,
    1,
    0,
    0,
};

PathInfo const gUnk_080F2E80 = {
    (void const *)gUnk_080F2F2C,
    5,
    1260,
    704,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2E8C = {
    nullptr,
    0,
    232,
    264,
    15,
    2,
    0,
};

PathInfo const gUnk_080F2E98 = {
    (void const *)gUnk_080F2F54,
    5,
    688,
    160,
    5,
    0,
    0,
};

PathInfo const gUnk_080F2EA4 = {
    (void const *)gUnk_080F2F7C,
    6,
    0,
    280,
    1,
    0,
    0,
};

PathInfo const gUnk_080F2EB0 = {
    (void const *)gUnk_080F2FAC,
    3,
    340,
    0,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2EBC = {
    nullptr,
    0,
    244,
    171,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2EC8 = {
    (void const *)gUnk_080F2FC4,
    3,
    244,
    171,
    2,
    0,
    0,
};

PathInfo const gUnk_080F2ED4 = {
    nullptr,
    0,
    88,
    88,
    38,
    0,
    0,
};

PathInfo const gUnk_080F2EE0 = {
    (void const *)gUnk_080F2FDC,
    5,
    296,
    116,
    7,
    0,
    0,
};

PathPointB const gUnk_080F2EEC[] = {
    { 128, 2, 120, 0, 0 },
    { 176, 2, 120, 0, 0 },
};

PathPointA const gUnk_080F2EFC[] = {
    { 1, 136, 1 },
    { 5, 104, 0 },
    { 14, 360, 1 },
    { 16, 64, 0 },
    { 19, 280, 1 },
    { 22, 0, 0 },
};

PathPointA const gUnk_080F2F2C[] = {
    { 19, 240, 1 },
    { 20, 1248, 0 },
    { 21, 216, 1 },
    { 43, 688, 0 },
    { 45, 160, 1 },
};

PathPointA const gUnk_080F2F54[] = {
    { 2, 216, 1 },
    { 24, 1248, 0 },
    { 25, 240, 1 },
    { 26, 1260, 0 },
    { 46, 736, 1 },
};

PathPointA const gUnk_080F2F7C[] = {
    { 3, 64, 0 },
    { 6, 360, 1 },
    { 8, 104, 0 },
    { 17, 136, 1 },
    { 21, 212, 0 },
    { 22, 108, 1 },
};

PathPointA const gUnk_080F2FAC[] = {
    { 6, 145, 1 },
    { 10, 244, 0 },
    { 11, 171, 1 },
};

PathPointA const gUnk_080F2FC4[] = {
    { 1, 145, 1 },
    { 5, 340, 0 },
    { 11, 0, 1 },
};

PathPointA const gUnk_080F2FDC[] = {
    { 2, 152, 1 },
    { 40, 1248, 0 },
    { 41, 128, 1 },
    { 42, 1272, 0 },
    { 47, 0, 1 },
};

#if defined(REGION_JP)
extern char const gCppRuntimeBadAlloc_FifthSchedule[] =
    "bad_alloc";
#else
extern char const gUnk_080F3004[] =
    "bad_alloc";
#endif
