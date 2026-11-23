#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1058_TV_EntertainmentChannelWeatherForecast.mary.h"

void EventScript_1058_TV_EntertainmentChannelWeatherForecast(void)
{
    int var_0;
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            if (VarGet(VAR_DAY) == DAY_30)
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
            if (VarGet(VAR_DAY) == DAY_30)
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
#if defined(REGION_JP)
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SummerTyphoon);
#else
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerTyphoon);
#endif
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
            if (VarGet(VAR_DAY) == DAY_30)
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
#if defined(REGION_JP)
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason);
#else
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason);
#endif
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
#if defined(REGION_JP)
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason);
#else
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason);
#endif
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
            if (VarGet(VAR_DAY) == DAY_30)
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
#if defined(REGION_JP)
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SpringRain);
#else
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_WinterRain);
#endif
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
#if defined(REGION_JP)
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason);
#else
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason);
#endif
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
#if defined(REGION_JP)
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason);
#else
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason);
#endif
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOW);
#if defined(REGION_JP)
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_WinterClear);
#else
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_WinterSnow);
#endif
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
            CallScript(EventScript_0540_TV_EntertainmentChannel);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
    }
}
