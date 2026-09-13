#ifndef TIME_OF_DAY_HH
#define TIME_OF_DAY_HH

#include "unknown_types.hh"

enum TimeOfDayPeriod
{
    TIME_OF_DAY_PERIOD_MORNING,
    TIME_OF_DAY_PERIOD_AFTERNOON,
    TIME_OF_DAY_PERIOD_EVENING,
    TIME_OF_DAY_PERIOD_NIGHT,
    TIME_OF_DAY_PERIOD_COUNT,
};

// The native lookup scans start_minute in ascending order and returns value
// from the last transition not later than the supplied clock time.
struct TimeOfDayTransition
{
    u16 start_minute;
    u8 value;
};

extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Spring_Morning[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Spring_Afternoon[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Spring_Evening[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Spring_Night[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Summer_Morning[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Summer_Afternoon[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Summer_Evening[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Summer_Night[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Autumn_Morning[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Autumn_Afternoon[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Autumn_Evening[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Autumn_Night[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Winter_Morning[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Winter_Afternoon[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Winter_Evening[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Winter_Night[];

extern TimeOfDayTransition const * const
    gTimeOfDayTransitionTables[NUM_SEASONS][TIME_OF_DAY_PERIOD_COUNT];

#endif // TIME_OF_DAY_HH
