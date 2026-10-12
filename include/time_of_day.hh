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

// Stored at +0x10 in the save image. The first byte encodes the year as
// seven times its high five bits plus its low three bits; the following
// fields are the packed date and clock used by the calendar consumers.
struct GameCalendar
{
    u8 year_remainder : 3;
    u8 year_quotient : 5;
    GameDate date;
    GameTime time;

    u32 GetYear() const { return year_quotient * 7 + year_remainder; }
};

typedef char GameCalendarSizeCheck[sizeof(GameCalendar) == 4 ? 1 : -1];
typedef char GameCalendarDateCheck[offsetof(GameCalendar, date) == 1 ? 1 : -1];
typedef char GameCalendarTimeCheck[offsetof(GameCalendar, time) == 2 ? 1 : -1];

extern "C" char const * func_0800E2E4(Season season);
extern "C" char const * func_0800E304(unsigned int week_day);
extern "C" u32 func_0800E324(GameCalendar const & arg_0);

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
