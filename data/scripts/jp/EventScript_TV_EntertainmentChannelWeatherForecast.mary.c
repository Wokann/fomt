#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerClear[] =
        "明日の天気予報っちょ！　　　\r\n"
        "一日快晴になって、少し暑い　\r\n"
        "日になるっちょ！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerRain[] =
        "明日の天気予報っちょ！　　　\r\n"
        "今夜から朝にかけて、雲が　　\r\n"
        "広がって、明日は一日中雨が　\r\n"
        "降り続けるっちょ！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringToSummerTyphoon[] =
        "明日の天気予報っちょ！　　　\r\n"
        "台風が直撃するっちょ！　　　\r\n"
        "みんな戸締りは厳重にっちょ！\r\n"
        "動物は小屋に入れるっちょ！！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnow[] =
        "雪！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalSnowstorm[] =
        "大雪！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringClear[] =
        "明日の天気予報っちょ！　　　\r\n"
        "全国的に朝から晴れで、　　　\r\n"
        "青空がひろがるっちょ！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SpringRain[] =
        "明日の天気予報っちょ！　　　\r\n"
        "朝から雨になって、一日中　　\r\n"
        "降り続けるもようっちょ！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason[] =
        "台風！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerToFallClear[] =
        "明日の天気予報っちょ！　　　\r\n"
        "カラッとした、気持ちいい　　\r\n"
        "秋晴れになるっちょ！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerToFallRain[] =
        "明日の天気予報っちょ！　　　\r\n"
        "朝から雨で、少し肌寒い一日に\r\n"
        "なるっちょ！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerTyphoon[] =
        "明日の天気予報っちょ！　　　\r\n"
        "台風が直撃するもようっちょ！\r\n"
        "みんな戸締りは厳重にっちょ！\r\n"
        "動物は小屋に入れるっちょ！！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_FallToWinterClear[] =
        "明日の天気予報っちょ！　　　\r\n"
        "小春びよりで、すごしやすい　\r\n"
        "一日になるっちょ！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalRain[] =
        "雨！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterClear[] =
        "明日の天気予報っちょ！　　　\r\n"
        "雪が降るっちょ！　　　　　　\r\n"
        "カゼなんかひかないように気を\r\n"
        "つけるっちょ！{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_FallToWinterOrWinterSnowstorm[] =
        "明日の天気予報っちょ！　　　\r\n"
        "大雪になるっちょ！　　　　　\r\n"
        "みんな戸締りは厳重にっちょ！\r\n"
        "動物は小屋に入れるっちょ！！{Press}";
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
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_SummerTyphoon);
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
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason);
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
                        var_0 = ShowTelevisionMessage(gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoonWarmSeason);
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
