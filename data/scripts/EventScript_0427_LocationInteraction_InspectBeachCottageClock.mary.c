#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0427_LocationInteraction_InspectBeachCottageClock.mary.h"

void EventScript_0427_LocationInteraction_InspectBeachCottageClock(void)
{
    TalkOpen();
    SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_YEAR));
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            SetTextVariableString(TEXT_VARIABLE_2, gText_LocationInteraction_InspectBeachCottageClock_Spring);
            break;
        case SEASON_SUMMER:
            SetTextVariableString(TEXT_VARIABLE_2, gText_LocationInteraction_InspectBeachCottageClock_Summer);
            break;
        case SEASON_FALL:
            SetTextVariableString(TEXT_VARIABLE_2, gText_LocationInteraction_InspectBeachCottageClock_Fall);
            break;
        case SEASON_WINTER:
            SetTextVariableString(TEXT_VARIABLE_2, gText_LocationInteraction_InspectBeachCottageClock_Winter);
            break;
    }
    SetTextVariableNumber(TEXT_VARIABLE_3, VarGet(VAR_DAY));
    switch (VarGet(VAR_DAY_OF_WEEK))
    {
        case DAY_OF_WEEK_SUNDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_LocationInteraction_InspectBeachCottageClock_Sunday);
            break;
        case DAY_OF_WEEK_MONDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_LocationInteraction_InspectBeachCottageClock_Monday);
            break;
        case DAY_OF_WEEK_TUESDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_LocationInteraction_InspectBeachCottageClock_Tuesday);
            break;
        case DAY_OF_WEEK_WEDNESDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_LocationInteraction_InspectBeachCottageClock_Wednesday);
            break;
        case DAY_OF_WEEK_THURSDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_LocationInteraction_InspectBeachCottageClock_Thursday);
            break;
        case DAY_OF_WEEK_FRIDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_LocationInteraction_InspectBeachCottageClock_Friday);
            break;
        case DAY_OF_WEEK_SATURDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_LocationInteraction_InspectBeachCottageClock_Saturday);
            break;
    }
    TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_DateFormat);
    if (VarGet(VAR_HOUR) < 12)
    {
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR));
        SetTextVariableNumber(TEXT_VARIABLE_2, VarGet(VAR_MINUTE));
        if (VarGet(VAR_HOUR) < 10)
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
#if defined(UNIFY_REGIONS) || defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedZeroPaddedMinutes);
#elif defined(REGION_DE)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_TimeWithZeroPaddedMinutes);
#endif
            }
            else
            {
#if defined(UNIFY_REGIONS) || defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedMinutes);
#elif defined(REGION_DE)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_TimeWithMinutes);
#endif
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
#if defined(UNIFY_REGIONS) || defined(REGION_JP)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeZeroPaddedMinutes);
#elif defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedZeroPaddedMinutes);
#elif defined(REGION_DE)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_TimeWithZeroPaddedMinutes);
#endif
            }
            else
            {
#if defined(UNIFY_REGIONS) || defined(REGION_JP)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeMinutes);
#elif defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedMinutes);
#elif defined(REGION_DE)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_TimeWithMinutes);
#endif
            }
        }
    }
    else
    {
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR) - 12);
#elif defined(REGION_DE)
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR));
#endif
        SetTextVariableNumber(TEXT_VARIABLE_2, VarGet(VAR_MINUTE));
        if (VarGet(VAR_HOUR) < 22)
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
#if defined(UNIFY_REGIONS) || defined(REGION_JP)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_AfternoonTimeSpacedZeroPaddedMinutes);
#elif defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_AfternoonTimeZeroPaddedMinutes);
#elif defined(REGION_DE)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_TimeWithZeroPaddedMinutes);
#endif
            }
            else
            {
#if defined(UNIFY_REGIONS) || defined(REGION_JP)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_AfternoonTimeSpacedMinutes);
#elif defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_AfternoonTimeMinutes);
#elif defined(REGION_DE)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_TimeWithMinutes);
#endif
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
#if defined(UNIFY_REGIONS) || defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_AfternoonTimeZeroPaddedMinutes);
#elif defined(REGION_DE)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_TimeWithZeroPaddedMinutes);
#endif
            }
            else
            {
#if defined(UNIFY_REGIONS) || defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_AfternoonTimeMinutes);
#elif defined(REGION_DE)
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_TimeWithMinutes);
#endif
            }
        }
    }
    TalkClose();
}
