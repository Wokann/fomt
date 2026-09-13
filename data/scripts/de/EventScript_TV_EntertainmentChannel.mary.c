#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_EntertainmentChannel_SilentPause[] =
        "............................\r\n"
        "............................\r\n"
        "............................{Press}";

    const char gText_TV_EntertainmentChannel_LateNightOffAirDashPattern[] =
        "------------------------------\r\n"
        "------------------------------\r\n"
        "------------------------------{Press}";
};

void EventScript_TV_EntertainmentChannel(void)
{
    int unused_0, var_1;
    TalkOpen();
    if ((VarGet(VAR_HOUR) == 4 || VarGet(VAR_HOUR) == 16) && VarGet(VAR_MINUTE) == 44)
    {
        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
    }
    else
    {
        if (VarGet(VAR_WEATHER_TODAY) == WEATHER_TYPHOON || VarGet(VAR_WEATHER_TODAY) == WEATHER_SNOWSTORM)
        {
            SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
            var_1 = ShowTelevisionMessage(gText_TV_EntertainmentChannel_SilentPause);
        }
        else
        {
            if (VarGet(VAR_HOUR) < 6)
            {
                SetTelevisionProgram(TELEVISION_PROGRAM_LATE_NIGHT);
                var_1 = ShowTelevisionMessage(gText_TV_EntertainmentChannel_LateNightOffAirDashPattern);
            }
            else
            {
                mary_switch_compact (VarGet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT))
                {
                    case 0:
                        CallScript(EventScript_TV_EntertainmentChannelWeatherForecast);
                        break;
                    case 3:
                        CallScript(EventScript_TV_HarvestTheater);
                        break;
                    case 1:
                        SetTelevisionProgram(TELEVISION_PROGRAM_F314M_GRAND_PRIX);
                        CallScript(EventScript_TV_F314MGrandPrix);
                        break;
                    case 2:
                        if (VarGet(VAR_SEASON) == SEASON_SPRING && (VarGet(VAR_DAY) == DAY_OF_MONTH_01 || VarGet(VAR_DAY) == DAY_OF_MONTH_02 || VarGet(VAR_DAY) == DAY_OF_MONTH_03 || VarGet(VAR_DAY) == DAY_OF_MONTH_04 || VarGet(VAR_DAY) == DAY_OF_MONTH_05) || VarGet(VAR_SEASON) == SEASON_WINTER && (VarGet(VAR_DAY) == DAY_OF_MONTH_29 || VarGet(VAR_DAY) == DAY_OF_MONTH_30))
                        {
                            CallScript(EventScript_TV_DailyProgramDispatcher);
                        }
                        else
                        {
                            switch (VarGet(VAR_DAY_OF_WEEK))
                            {
                                case DAY_OF_WEEK_SUNDAY:
                                    SetTelevisionProgram(TELEVISION_PROGRAM_MINE_RESEARCH_GROUP);
                                    CallScript(EventScript_TV_MineResearchGroup);
                                    break;
                                case DAY_OF_WEEK_MONDAY:
                                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                                    CallScript(EventScript_TV_FairyAndMeHisStory);
                                    break;
                                case DAY_OF_WEEK_TUESDAY:
                                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_THEATER);
                                    CallScript(EventScript_TV_FairyAndMeHerStory);
                                    break;
                                case DAY_OF_WEEK_WEDNESDAY:
                                    SetTelevisionProgram(TELEVISION_PROGRAM_MINERAL_TOWN_FRIENDS);
                                    CallScript(EventScript_TV_MineralTownFriends_CharacterProfiles);
                                    break;
                                case DAY_OF_WEEK_THURSDAY:
                                    SetTelevisionProgram(TELEVISION_PROGRAM_CARD_COLLECTOR_CHISATO);
                                    CallScript(EventScript_TV_CardCollectorChisato);
                                    break;
                                case DAY_OF_WEEK_FRIDAY:
                                    SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ZERO);
                                    CallScript(EventScript_TV_MechabotUltrorZero_EpisodeReminders);
                                    break;
                                case DAY_OF_WEEK_SATURDAY:
                                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_GODDESS_GAME);
                                    CallScript(EventScript_TV_HarvestGoddessRockPaperScissors);
                                    break;
                            }
                        }
                        break;
                }
            }
        }
    }
    EndTelevisionProgram();
    TalkClose();
    switch (var_1)
    {
        case TELEVISION_INPUT_UP_WEATHER:
        case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
        case TELEVISION_INPUT_RIGHT_NEWS:
        case TELEVISION_INPUT_LEFT_VARIETY:
            VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_1);
            CallScript(EventScript_TV_EntertainmentChannel);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
        mary_dead_jump:
    }
}
