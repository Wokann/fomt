#ifndef TIME_OF_DAY_DATA_HH
#define TIME_OF_DAY_DATA_HH

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

extern TimeOfDayTransition const * const
    gTimeOfDayTransitionTables[NUM_SEASONS][TIME_OF_DAY_PERIOD_COUNT];

#endif // TIME_OF_DAY_DATA_HH
