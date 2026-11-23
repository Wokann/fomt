#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0347_SystemMenu_CalendarDateAndTimeDisplay.mary.h"

void EventScript_0347_SystemMenu_CalendarDateAndTimeDisplay(void)
{
    TalkOpen();
    SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_YEAR));
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            SetTextVariableString(TEXT_VARIABLE_2, gText_SystemMenu_CalendarDateAndTimeDisplay_Spring);
            break;
        case SEASON_SUMMER:
            SetTextVariableString(TEXT_VARIABLE_2, gText_SystemMenu_CalendarDateAndTimeDisplay_Summer);
            break;
        case SEASON_FALL:
            SetTextVariableString(TEXT_VARIABLE_2, gText_SystemMenu_CalendarDateAndTimeDisplay_Fall);
            break;
        case SEASON_WINTER:
            SetTextVariableString(TEXT_VARIABLE_2, gText_SystemMenu_CalendarDateAndTimeDisplay_Winter);
            break;
    }
    SetTextVariableNumber(TEXT_VARIABLE_3, VarGet(VAR_DAY));
    switch (VarGet(VAR_DAY_OF_WEEK))
    {
        case DAY_OF_WEEK_SUNDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_CalendarDateAndTimeDisplay_Sunday);
            break;
        case DAY_OF_WEEK_MONDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_CalendarDateAndTimeDisplay_Monday);
            break;
        case DAY_OF_WEEK_TUESDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_CalendarDateAndTimeDisplay_Tuesday);
            break;
        case DAY_OF_WEEK_WEDNESDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_CalendarDateAndTimeDisplay_Wednesday);
            break;
        case DAY_OF_WEEK_THURSDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_CalendarDateAndTimeDisplay_Thursday);
            break;
        case DAY_OF_WEEK_FRIDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_CalendarDateAndTimeDisplay_Friday);
            break;
        case DAY_OF_WEEK_SATURDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_CalendarDateAndTimeDisplay_Saturday);
            break;
    }
    TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_CurrentDate);
    if (VarGet(VAR_HOUR) < 12)
    {
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR));
        SetTextVariableNumber(TEXT_VARIABLE_2, VarGet(VAR_MINUTE));
        if (VarGet(VAR_HOUR) < 10)
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeSpacedZeroPaddedMinutes);
#else
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_TimeWithZeroPaddedMinutes);
#endif
            }
            else
            {
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeSpacedMinutes);
#else
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_TimeWithMinutes);
#endif
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
#if defined(REGION_JP)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeZeroPaddedMinutes);
#elif defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeSpacedZeroPaddedMinutes);
#else
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_TimeWithZeroPaddedMinutes);
#endif
            }
            else
            {
#if defined(REGION_JP)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeMinutes);
#elif defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeSpacedMinutes);
#else
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_TimeWithMinutes);
#endif
            }
        }
    }
    else
    {
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR) - 12);
#else
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR));
#endif
        SetTextVariableNumber(TEXT_VARIABLE_2, VarGet(VAR_MINUTE));
        if (VarGet(VAR_HOUR) < 22)
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
#if defined(REGION_JP)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeSpacedZeroPaddedMinutes);
#elif defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeZeroPaddedMinutes);
#else
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_TimeWithZeroPaddedMinutes);
#endif
            }
            else
            {
#if defined(REGION_JP)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeSpacedMinutes);
#elif defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeMinutes);
#else
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_TimeWithMinutes);
#endif
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeZeroPaddedMinutes);
#else
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_TimeWithZeroPaddedMinutes);
#endif
            }
            else
            {
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeMinutes);
#else
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_TimeWithMinutes);
#endif
            }
        }
    }
    TalkClose();
}
