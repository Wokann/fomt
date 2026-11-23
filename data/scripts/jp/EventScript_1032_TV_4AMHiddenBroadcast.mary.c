#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1032_TV_4AMHiddenBroadcast.mary.h"

void EventScript_1032_TV_4AMHiddenBroadcast(void)
{
    int var_0;
    var_0 = RandomIntInclusive(0, 9);
    do
    {
        if (VarGet(VAR_HOUR) == 4)
        {
            switch (VarGet(VAR_DAY_OF_WEEK))
            {
                case DAY_OF_WEEK_SUNDAY:
                    SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_CARD_COLLECTOR_CHISATO);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_LATE_NIGHT);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_MY_DEAR_PRINCESS);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_DUELING_CHEFS);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_FISHING_HOUR);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_F314M_GRAND_PRIX);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_LIFE_ON_THE_FARM_ADVANCED);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_LIFE_ON_THE_FARM_BEGINNER);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_AARON_CHANGES);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ZERO);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_MINERAL_TOWN_FRIENDS);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_CALENDAR);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_STAR_LILY_BANDIT_GIRL);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_ST_EMERALD_ACADEMY);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_MINE_RESEARCH_GROUP);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOWSTORM);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    SetTelevisionProgram(TELEVISION_PROGRAM_NEW_YEAR_WINTER_SPECIAL);
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ProgramTransitionBlank);
                    if (var_0 == 10)
                    {
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        TalkMessage(gText_TV_4AMHiddenBroadcast_FinalPrompt);
                    }
                    break;
                case DAY_OF_WEEK_MONDAY:
                    TalkMessage(gText_TV_4AMHiddenBroadcast_MondayTransmission);
                    break;
                case DAY_OF_WEEK_TUESDAY:
                    TalkMessage(gText_TV_4AMHiddenBroadcast_TuesdayTransmission);
                    break;
                case DAY_OF_WEEK_WEDNESDAY:
                    TalkMessage(gText_TV_4AMHiddenBroadcast_WednesdayTransmission);
                    break;
                case DAY_OF_WEEK_THURSDAY:
                    TalkMessage(gText_TV_4AMHiddenBroadcast_ThursdayTransmission);
                    break;
                case DAY_OF_WEEK_FRIDAY:
                    TalkMessage(gText_TV_4AMHiddenBroadcast_FridayTransmission);
                    break;
                case DAY_OF_WEEK_SATURDAY:
                    TalkMessage(gText_TV_4AMHiddenBroadcast_SaturdayTransmission);
                    break;
            }
        }
        else
        {
            if (VarGet(VAR_DAY) == DAY_04)
            {
                if (VarGet(VAR_YEAR) == 4)
                {
                    TalkMessage(gText_TV_4AMHiddenBroadcast_Day4Year4Pattern);
                }
                else
                {
                    if (VarGet(VAR_YEAR) == 44)
                    {
                        TalkMessage(gText_TV_4AMHiddenBroadcast_Day4Year44Pattern);
                    }
                    else
                    {
                        TalkMessage(gText_TV_4AMHiddenBroadcast_Day4OtherYearPattern);
                    }
                }
            }
            else
            {
                TalkMessage(gText_TV_4AMHiddenBroadcast_OtherDatePattern);
            }
        }
        var_0 = var_0 + 1;
    }
    while (var_0 <= 10);
    EndTelevisionProgram();
    TalkClose();
}
