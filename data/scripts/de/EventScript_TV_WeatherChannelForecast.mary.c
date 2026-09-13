#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_WeatherChannelForecast_SpringToSummerClear[] =
        "Das Wetter für morgen:\r\n"
        "Es wird sonnig und\r\n"
        "ziemlich heiß.{Press}";

    const char gText_TV_WeatherChannelForecast_SpringToSummerRain[] =
        "Das Wetter für morgen:\r\n"
        "Heute nacht ziehen Wolken \r\n"
        "auf und morgen wird es \r\n"
        "den ganzen Tag regnen. {Press}";

    const char gText_TV_WeatherChannelForecast_Shared_WarmSeasonTyphoon[] =
        "Das Wetter für morgen:\r\n"
        "Ein Taifun wird vorbei-\r\n"
        "ziehen, also halte alle\r\n"
        "Fenster und Türen ge-\r\n"
        "schlossen und lass die \r\n"
        "Tiere in der Scheune!{Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalSnow[] =
        "Schnee {Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalSnowstorm[] =
        "Ein Schneesturm!{Press}";

    const char gText_TV_WeatherChannelForecast_SpringClear[] =
        "Das Wetter für morgen:\r\n"
        "Morgen ist klarer Himmel \r\n"
        "über der ganzen  \r\n"
        "Region. {Press}";

    const char gText_TV_WeatherChannelForecast_SpringRain[] =
        "Das Wetter für morgen:\r\n"
        "Morgen früh beginnt es zu \r\n"
        "regnen und hört den\r\n"
        "ganzen Tag nicht auf. {Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalTyphoonWarmSeason[] =
        "Taifun!{Press}";

    const char gText_TV_WeatherChannelForecast_SummerToFallClear[] =
        "Das Wetter für morgen:\r\n"
        "Es wird ein schöner, \r\n"
        "klarer und warmer Herbsttag.{Press}";

    const char gText_TV_WeatherChannelForecast_SummerToFallRain[] =
        "Das Wetter für morgen:\r\n"
        "Morgen wird ein kalter \r\n"
        "und regnerischer Tag.{Press}";

    const char gText_TV_WeatherChannelForecast_SummerRain[] =
        "Schwere Gewitter!\r\n"
        "Heute nacht ziehen Wolken \r\n"
        "auf und morgen wird es \r\n"
        "den ganzen Tag regnen. {Press}";

    const char gText_TV_WeatherChannelForecast_FallToWinterClear[] =
        "Das Wetter für morgen:\r\n"
        "Es wird ein schöner \r\n"
        "Frühlingstag werden. {Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalRain[] =
        "Regen!{Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalTyphoonColdSeason[] =
        "Taifun! {Press}";

    const char gText_TV_WeatherChannelForecast_WinterSnow[] =
        "Das Wetter für morgen:\r\n"
        "Es wird schneien, also\r\n"
        "pass auf, dass du dich \r\n"
        "nicht erkältest. {Press}";

    const char gText_TV_WeatherChannelForecast_WinterSnowstorm[] =
        "Das Wetter für morgen:\r\n"
        "Ein Schneesturm zieht auf, \r\n"
        "also schließe alle Türen \r\n"
        "und Fenster und bring die\r\n"
        "Tiere in die Scheune!{Press}";
};

void EventScript_TV_WeatherChannelForecast(void)
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
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringToSummerClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringToSummerRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_TYPHOON);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_Shared_WarmSeasonTyphoon);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnowstorm);
                        break;
                }
            }
            else
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalTyphoonWarmSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnowstorm);
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
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SummerToFallClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SummerToFallRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalTyphoonWarmSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnowstorm);
                        break;
                }
            }
            else
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringToSummerClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SummerRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_TYPHOON);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_Shared_WarmSeasonTyphoon);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnowstorm);
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
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_FallToWinterClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalTyphoonColdSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOW);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_WinterSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOWSTORM);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_WinterSnowstorm);
                        break;
                }
            }
            else
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SummerToFallClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SummerToFallRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalTyphoonColdSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnowstorm);
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
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_RAIN);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalTyphoonColdSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalSnowstorm);
                        break;
                }
            }
            else
            {
                switch (VarGet(VAR_WEATHER_TOMORROW))
                {
                    case WEATHER_SUNNY:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_CLEAR);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_FallToWinterClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalTyphoonColdSeason);
                        break;
                    case WEATHER_SNOW:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOW);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_WinterSnow);
                        break;
                    case WEATHER_SNOWSTORM:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_SNOWSTORM);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_WinterSnowstorm);
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
            CallScript(EventScript_TV_ChannelDispatcher);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
    }
}
