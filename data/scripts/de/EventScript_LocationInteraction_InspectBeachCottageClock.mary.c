#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBeachCottageClock_Spring[] =
        "Frühling";

    const char gText_LocationInteraction_InspectBeachCottageClock_Summer[] =
        "Sommer";

    const char gText_LocationInteraction_InspectBeachCottageClock_Fall[] =
        "Herbst";

    const char gText_LocationInteraction_InspectBeachCottageClock_Winter[] =
        "Winter";

    const char gText_LocationInteraction_InspectBeachCottageClock_Sunday[] =
        "Sonntag";

    const char gText_LocationInteraction_InspectBeachCottageClock_Monday[] =
        "Montag";

    const char gText_LocationInteraction_InspectBeachCottageClock_Tuesday[] =
        "Dienstag";

    const char gText_LocationInteraction_InspectBeachCottageClock_Wednesday[] =
        "Mittwoch";

    const char gText_LocationInteraction_InspectBeachCottageClock_Thursday[] =
        "Donnerstag";

    const char gText_LocationInteraction_InspectBeachCottageClock_Friday[] =
        "Freitag";

    const char gText_LocationInteraction_InspectBeachCottageClock_Saturday[] =
        "Samstag";

    const char gText_LocationInteraction_InspectBeachCottageClock_DateFormat[] =
        "Jahr {Var1}\r\n"
        "{Var2} Tag {Var3} ({Var4}){Press}";

    const char gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";
};

void EventScript_LocationInteraction_InspectBeachCottageClock(void)
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
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedMinutes);
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedMinutes);
            }
        }
    }
    else
    {
        SetTextVariableNumber(TEXT_VARIABLE_1, VarGet(VAR_HOUR));
        SetTextVariableNumber(TEXT_VARIABLE_2, VarGet(VAR_MINUTE));
        if (VarGet(VAR_HOUR) < 22)
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedMinutes);
            }
        }
        else
        {
            if (VarGet(VAR_MINUTE) < 10)
            {
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedZeroPaddedMinutes);
            }
            else
            {
                TalkAppendMessage(gText_LocationInteraction_InspectBeachCottageClock_MorningTimeSpacedMinutes);
            }
        }
    }
    TalkClose();
}
