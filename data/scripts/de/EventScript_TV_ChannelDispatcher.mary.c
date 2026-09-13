#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_ChannelDispatcher_StormGoldenLumberSignalInterference[] =
        "................aber..........\r\n"
        "............................\r\n"
        "............................{Press}";

    const char gText_TV_ChannelDispatcher_StormRareSignalInterference[] =
        "............................\r\n"
        "............................\r\n"
        "............................\r\n"
        "............................\r\n"
        "............................\r\n"
        "............................\r\n"
        "............................\r\n"
        "............................\r\n"
        "..-ness.....................\r\n"
        "............................\r\n"
        "............................\r\n"
        "............................{Press}";

    const char gText_TV_ChannelDispatcher_StormCommonSignalInterferenceA[] =
        "............................\r\n"
        "................Kuh.........\r\n"
        "............................{Press}";

    const char gText_TV_ChannelDispatcher_StormCommonSignalInterferenceB[] =
        ".......Göttin.............\r\n"
        "............................\r\n"
        "............................{Press}";

    const char gText_TV_ChannelDispatcher_LateNightGoldenLumberSignalInterference[] =
        "-----------solche-------------\r\n"
        "----------------------------\r\n"
        "----------------------------{Press}";

    const char gText_TV_ChannelDispatcher_LateNightRareSignalInterference[] =
        "----------------------------\r\n"
        "----------------------------\r\n"
        "----------------------------\r\n"
        "----------------------------\r\n"
        "----------------------------\r\n"
        "----------------------------\r\n"
        "-----------jetzt--------------\r\n"
        "----------------------------\r\n"
        "----------------------------\r\n"
        "----------------------------\r\n"
        "----------------------------\r\n"
        "---------------für----------{Press}";

    const char gText_TV_ChannelDispatcher_Shared_LateNightCommonSignalInterferenceAAndB[] =
        "----------------------------\r\n"
        "----------------------------\r\n"
        "----------------------------{Press}";
};

void EventScript_TV_ChannelDispatcher(void)
{
    int var_0, var_1;
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
            if (HasGoldenLumberOnFarm())
            {
                var_1 = ShowTelevisionMessage(gText_TV_ChannelDispatcher_StormGoldenLumberSignalInterference);
            }
            else
            {
                var_0 = RandomIntInclusive(0, 10);
                switch (var_0)
                {
                    case 0:
                        var_1 = ShowTelevisionMessage(gText_TV_ChannelDispatcher_StormRareSignalInterference);
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                        var_1 = ShowTelevisionMessage(gText_TV_ChannelDispatcher_StormCommonSignalInterferenceA);
                        break;
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                        var_1 = ShowTelevisionMessage(gText_TV_ChannelDispatcher_StormCommonSignalInterferenceB);
                        break;
                }
            }
        }
        else
        {
            if (VarGet(VAR_HOUR) < 6)
            {
                SetTelevisionProgram(TELEVISION_PROGRAM_LATE_NIGHT);
                if (HasGoldenLumberOnFarm())
                {
                    var_1 = ShowTelevisionMessage(gText_TV_ChannelDispatcher_LateNightGoldenLumberSignalInterference);
                }
                else
                {
                    var_0 = RandomIntInclusive(0, 10);
                    switch (var_0)
                    {
                        case 0:
                            var_1 = ShowTelevisionMessage(gText_TV_ChannelDispatcher_LateNightRareSignalInterference);
                            break;
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                            var_1 = ShowTelevisionMessage(gText_TV_ChannelDispatcher_Shared_LateNightCommonSignalInterferenceAAndB);
                            break;
                        case 6:
                        case 7:
                        case 8:
                        case 9:
                        case 10:
                            var_1 = ShowTelevisionMessage(gText_TV_ChannelDispatcher_Shared_LateNightCommonSignalInterferenceAAndB);
                            break;
                    }
                }
            }
            else
            {
                mary_switch_compact (VarGet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT))
                {
                    case 0:
                        CallScript(EventScript_TV_WeatherChannelForecast);
                        break;
                    case 3:
                        SetTelevisionProgram(TELEVISION_PROGRAM_CALENDAR);
                        CallScript(EventScript_TV_Calendar_Program);
                        break;
                    case 1:
                        if (VarGet(VAR_HOUR) < 12)
                        {
                            SetTelevisionProgram(TELEVISION_PROGRAM_LIFE_ON_THE_FARM_ADVANCED);
                            CallScript(EventScript_TV_LifeOnTheFarm_Advanced);
                        }
                        else
                        {
                            SetTelevisionProgram(TELEVISION_PROGRAM_LIFE_ON_THE_FARM_BEGINNER);
                            CallScript(EventScript_TV_LifeOnTheFarm_Beginner);
                        }
                        break;
                    case 2:
                        if (VarGet(VAR_SEASON) == SEASON_SPRING && (VarGet(VAR_DAY) == DAY_OF_MONTH_01 || VarGet(VAR_DAY) == DAY_OF_MONTH_02 || VarGet(VAR_DAY) == DAY_OF_MONTH_03 || VarGet(VAR_DAY) == DAY_OF_MONTH_04 || VarGet(VAR_DAY) == DAY_OF_MONTH_05))
                        {
                            var_0 = RandomIntInclusive(0, 1);
                            switch (var_0)
                            {
                                case 0:
                                    CallScript(EventScript_TV_NewYearSpecial_Programs);
                                    break;
                                case 1:
                                    SetTelevisionProgram(TELEVISION_PROGRAM_HARVEST_GODDESS_GAME);
                                    CallScript(EventScript_TV_HarvestGoddessNumberGuessing);
                                    break;
                            }
                        }
                        else
                        {
                            if (VarGet(VAR_SEASON) == SEASON_WINTER && (VarGet(VAR_DAY) == DAY_OF_MONTH_29 || VarGet(VAR_DAY) == DAY_OF_MONTH_30))
                            {
                                CallScript(EventScript_TV_NewYearSpecial_Programs);
                            }
                            else
                            {
                                switch (VarGet(VAR_DAY_OF_WEEK))
                                {
                                    case DAY_OF_WEEK_SUNDAY:
                                        SetTelevisionProgram(TELEVISION_PROGRAM_MY_DEAR_PRINCESS);
                                        CallScript(EventScript_TV_MyDearPrincess);
                                        break;
                                    case DAY_OF_WEEK_MONDAY:
                                        SetTelevisionProgram(TELEVISION_PROGRAM_FISHING_HOUR);
                                        CallScript(EventScript_TV_FishingHour);
                                        break;
                                    case DAY_OF_WEEK_TUESDAY:
                                        SetTelevisionProgram(TELEVISION_PROGRAM_DUELING_CHEFS);
                                        CallScript(EventScript_TV_DuelingChefs);
                                        break;
                                    case DAY_OF_WEEK_WEDNESDAY:
                                        SetTelevisionProgram(TELEVISION_PROGRAM_AARON_CHANGES);
                                        CallScript(EventScript_TV_AaronChanges);
                                        break;
                                    case DAY_OF_WEEK_THURSDAY:
                                        SetTelevisionProgram(TELEVISION_PROGRAM_STAR_LILY_BANDIT_GIRL);
                                        CallScript(EventScript_TV_StarLilyBanditGirl);
                                        break;
                                    case DAY_OF_WEEK_FRIDAY:
                                        SetTelevisionProgram(TELEVISION_PROGRAM_MECHABOT_ULTROR);
                                        CallScript(EventScript_TV_MechabotUltror);
                                        break;
                                    case DAY_OF_WEEK_SATURDAY:
                                        CallScript(EventScript_TV_Shopping_ProductBroadcasts);
                                        break;
                                }
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
