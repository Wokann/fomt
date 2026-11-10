#ifndef TIME_OF_DAY_HH
#define TIME_OF_DAY_HH

#include "time_of_day_types.hh"
#include <algorithm>

// Some native readers apply an upper bound; raw saved-year readers do not.
inline u32 GameCalendar::GetYear(u32 maximum) const
{
    return std::min<u32>(maximum, GetYear());
}

extern "C" u32 GetTimeOfDayTransitionValue(u8 hour, u8 minute, u32 season, TimeOfDayPeriod period);

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
