#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerClear[] =
        "Hier das Wetter für morgen!\r\n"
        "Es wird sonnig und\r\n"
        "ziemlich heiß.{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerRain[] =
        "Hier das Wetter für morgen!\r\n"
        "Heute nacht ziehen Wolken \r\n"
        "auf und morgen wird es \r\n"
        "den ganzen Tag regnen. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerTyphoon[] =
        "Hier das Wetter für morgen!\r\n"
        "Ein Taifun wird vorbei-\r\n"
        "ziehen, also halte alle\r\n"
        "Fenster und Türen ge-\r\n"
        "schlossen und lass die \r\n"
        "Tiere in der Scheune!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow[] =
        "Schnee {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm[] =
        "Ein Schneesturm!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringClear[] =
        "Hier das Wetter für morgen!\r\n"
        "Morgen ist klarer Himmel \r\n"
        "über der ganzen \r\n"
        "Region. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringRain[] =
        "Das Wetter von heute!\r\n"
        "Regen den ganzen Tag! \r\n"
        "Zu schade!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason[] =
        "Taifun!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerToFallClear[] =
        "Hier das Wetter für morgen!\r\n"
        "Es wird ein schöner, \r\n"
        "klarer und warmer Herbsttag.{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerToFallRain[] =
        "Hier das Wetter für morgen!\r\n"
        "Morgen wird ein kalter \r\n"
        "und regnerischer Tag.{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_FallToWinterClear[] =
        "Hier das Wetter für morgen!\r\n"
        "Es wird ein schöner \r\n"
        "Frühlingstag werden. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalRain[] =
        "Regen!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonColdSeason[] =
        "Taifun! {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterClear[] =
        "Das Wetter für morgen:\r\n"
        "Es wird schneien, also\r\n"
        "pass auf, dass du dich \r\n"
        "nicht erkältest. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_FallToWinterOrWinterSnowstorm[] =
        "Hier das Wetter für morgen!\r\n"
        "Ein Schneesturm zieht auf, \r\n"
        "also schließe alle Türen \r\n"
        "und Fenster und bring die\r\n"
        "Tiere in die Scheune!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterRain[] =
        "Hier das Wetter für morgen!\r\n"
        "Morgen früh beginnt es zu \r\n"
        "regnen und hört den\r\n"
        "ganzen Tag nicht auf. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterSnow[] =
        "Hier das Wetter für morgen!\r\n"
        "Es wird schneien, also\r\n"
        "pass auf, dass du dich \r\n"
        "nicht erkältest. {Press}";
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
