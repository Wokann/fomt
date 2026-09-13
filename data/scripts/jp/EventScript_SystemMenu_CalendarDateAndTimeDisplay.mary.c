#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Spring[] =
        "春";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Summer[] =
        "夏";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Fall[] =
        "秋";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Winter[] =
        "冬";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Sunday[] =
        "日";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Monday[] =
        "月";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Tuesday[] =
        "火";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Wednesday[] =
        "水";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Thursday[] =
        "木";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Friday[] =
        "金";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_Saturday[] =
        "土";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_CurrentDate[] =
        "{Var1}年目\r\n"
        "{Var2}の月　{Var3}日　（{Var4}）{Press}";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeSpacedZeroPaddedMinutes[] =
        "午前　{Var1}時０{Var2}分{Press}";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeSpacedMinutes[] =
        "午前　{Var1}時{Var2}分{Press}";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeZeroPaddedMinutes[] =
        "午前{Var1}時０{Var2}分{Press}";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeMinutes[] =
        "午前{Var1}時{Var2}分{Press}";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeSpacedZeroPaddedMinutes[] =
        "午後　{Var1}時０{Var2}分{Press}";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeSpacedMinutes[] =
        "午後　{Var1}時{Var2}分{Press}";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeZeroPaddedMinutes[] =
        "午後{Var1}時０{Var2}分{Press}";

    const char gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeMinutes[] =
        "午後{Var1}時{Var2}分{Press}";
};

void EventScript_SystemMenu_CalendarDateAndTimeDisplay(void)
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
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeSpacedZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeSpacedMinutes);
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_MorningTimeMinutes);
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
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeSpacedZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeSpacedMinutes);
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_SystemMenu_CalendarDateAndTimeDisplay_AfternoonTimeMinutes);
            }
        }
    }
    TalkClose();
}
