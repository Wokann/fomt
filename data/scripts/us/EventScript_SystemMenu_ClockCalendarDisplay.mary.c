#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_ClockCalendarDisplay_Spring[] =
        "Spring";

    const char gText_SystemMenu_ClockCalendarDisplay_Summer[] =
        "Summer";

    const char gText_SystemMenu_ClockCalendarDisplay_Fall[] =
        "Fall";

    const char gText_SystemMenu_ClockCalendarDisplay_Winter[] =
        "Winter";

    const char gText_SystemMenu_ClockCalendarDisplay_Sunday[] =
        "Sunday";

    const char gText_SystemMenu_ClockCalendarDisplay_Monday[] =
        "Monday";

    const char gText_SystemMenu_ClockCalendarDisplay_Tuesday[] =
        "Tuesday";

    const char gText_SystemMenu_ClockCalendarDisplay_Wednesday[] =
        "Wednesday";

    const char gText_SystemMenu_ClockCalendarDisplay_Thursday[] =
        "Thursday";

    const char gText_SystemMenu_ClockCalendarDisplay_Friday[] =
        "Friday";

    const char gText_SystemMenu_ClockCalendarDisplay_Saturday[] =
        "Saturday";

    const char gText_SystemMenu_ClockCalendarDisplay_CurrentDate[] =
        "Year {Var1}\r\n"
        "{Var2}　Day {Var3} ({Var4}){Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_MorningTimeSpacedZeroPaddedMinutes[] =
        "{Var1}:0{Var2} AM{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_MorningTimeSpacedMinutes[] =
        "{Var1}:{Var2} AM{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeZeroPaddedMinutes[] =
        "{Var1}:0{Var2} PM{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeMinutes[] =
        "{Var1}:{Var2} PM{Press}";
};

void EventScript_SystemMenu_ClockCalendarDisplay(void)
{
    TalkOpen();
    SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_YEAR));
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            SetTextVariableString(TEXT_VARIABLE_2, gText_SystemMenu_ClockCalendarDisplay_Spring);
            break;
        case SEASON_SUMMER:
            SetTextVariableString(TEXT_VARIABLE_2, gText_SystemMenu_ClockCalendarDisplay_Summer);
            break;
        case SEASON_FALL:
            SetTextVariableString(TEXT_VARIABLE_2, gText_SystemMenu_ClockCalendarDisplay_Fall);
            break;
        case SEASON_WINTER:
            SetTextVariableString(TEXT_VARIABLE_2, gText_SystemMenu_ClockCalendarDisplay_Winter);
            break;
    }
    SetTextVariableNumber(TEXT_VARIABLE_3, VarGet(VAR_DAY));
    switch (VarGet(VAR_DAY_OF_WEEK))
    {
        case DAY_OF_WEEK_SUNDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_ClockCalendarDisplay_Sunday);
            break;
        case DAY_OF_WEEK_MONDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_ClockCalendarDisplay_Monday);
            break;
        case DAY_OF_WEEK_TUESDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_ClockCalendarDisplay_Tuesday);
            break;
        case DAY_OF_WEEK_WEDNESDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_ClockCalendarDisplay_Wednesday);
            break;
        case DAY_OF_WEEK_THURSDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_ClockCalendarDisplay_Thursday);
            break;
        case DAY_OF_WEEK_FRIDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_ClockCalendarDisplay_Friday);
            break;
        case DAY_OF_WEEK_SATURDAY:
            SetTextVariableString(TEXT_VARIABLE_4, gText_SystemMenu_ClockCalendarDisplay_Saturday);
            break;
    }
    TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_CurrentDate);
    if (VarGet(VAR_HOUR) < 12)
    {
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR));
        SetTextVariableNumber(TEXT_VARIABLE_2, VarGet(VAR_MINUTE));
        if (VarGet(VAR_HOUR) < 10)
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_MorningTimeSpacedZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_MorningTimeSpacedMinutes);
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_MorningTimeSpacedZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_MorningTimeSpacedMinutes);
            }
        }
    }
    else
    {
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR) - 12);
        SetTextVariableNumber(TEXT_VARIABLE_2, VarGet(VAR_MINUTE));
        if (VarGet(VAR_HOUR) < 22)
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeMinutes);
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeMinutes);
            }
        }
    }
    TalkClose();
}
