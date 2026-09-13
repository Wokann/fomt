#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerClear[] =
        "Here's tomorrow's forecast!\r\n"
        "It will be\r\n"
        "sunny and a little hot.{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerRain[] =
        "Here's tomorrow's forecast!\r\n"
        "Tonight will be cloudy, \r\n"
        "with rain falling all day \r\n"
        "tomorrow. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerTyphoon[] =
        "Here's tomorrow's forecast!\r\n"
        "A typhoon will be passing\r\n"
        "through, so lock down all\r\n"
        "doors and windows, and put\r\n"
        "your animals in the Barn!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow[] =
        "Snow {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm[] =
        "A snowstorm!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringClear[] =
        "Here's tomorrow's forecast!\r\n"
        "Morning will bring fair \r\n"
        "skies throughout the \r\n"
        "entire region. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringRain[] =
        "Tomorrow's weather!\r\n"
        "It will rain all day!　\r\n"
        "Too bad!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason[] =
        "Typhoon!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerToFallClear[] =
        "Here's tomorrow's forecast!\r\n"
        "It will be a nice, crisp \r\n"
        "and clear Fall day. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerToFallRain[] =
        "Here's tomorrow's forecast!\r\n"
        "Morning will bring rain, and\r\n"
        "it will be a cold day.{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_FallToWinterClear[] =
        "Here's tomorrow's forecast!\r\n"
        "It will be a pleasant \r\n"
        "early Spring day. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalRain[] =
        "Rain!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason[] =
        "Typhoon! {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterClear[] =
        "This is tomorrow's forecast!\r\n"
        "It will snow, so be careful\r\n"
        "not to catch cold. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_FallToWinterOrWinterSnowstorm[] =
        "Here's tomorrow's forecast!\r\n"
        "A snowstorm will hit, so \r\n"
        "lock down all doors and \r\n"
        "windows, and put your\r\n"
        "animals in the Barn!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterRain[] =
        "Here's tomorrow's forecast!\r\n"
        "It will begin raining in \r\n"
        "the morning and not stop\r\n"
        "all day. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterSnow[] =
        "Here's tomorrow's forecast!\r\n"
        "It will snow, so be careful\r\n"
        "not to catch cold. {Press}";
};

void EventScript_TV_EntertainmentChannelWeatherForecast(void)
{
    int var_0;
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            if (VarGet(VAR_DAY) == DAY_OF_MONTH_30)
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_TYPHOON);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerTyphoon);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm);
                        break;
                }
            }
            else
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm);
                        break;
                }
            }
            break;
        case SEASON_SUMMER:
            if (VarGet(VAR_DAY) == DAY_OF_MONTH_30)
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SummerToFallClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SummerToFallRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm);
                        break;
                }
            }
            else
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_TYPHOON);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerTyphoon);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm);
                        break;
                }
            }
            break;
        case SEASON_FALL:
            if (VarGet(VAR_DAY) == DAY_OF_MONTH_30)
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_FallToWinterClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOW);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_WinterClear);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOWSTORM);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_FallToWinterOrWinterSnowstorm);
                        break;
                }
            }
            else
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SummerToFallClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SummerToFallRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm);
                        break;
                }
            }
            break;
        case SEASON_WINTER:
            if (VarGet(VAR_DAY) == DAY_OF_MONTH_30)
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_WinterRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm);
                        break;
                }
            }
            else
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_FallToWinterClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOW);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_WinterSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOWSTORM);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_FallToWinterOrWinterSnowstorm);
                        break;
                }
            }
            break;
    }
    EndTelevisionProgram();
    TalkClose();
    switch (var_0)
    {
        case TELEVISION_INPUT_UP_WEATHER:
        case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
        case TELEVISION_INPUT_RIGHT_NEWS:
        case TELEVISION_INPUT_LEFT_VARIETY:
            VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
            CallScript(EventScript_TV_EntertainmentChannel);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
    }
}
