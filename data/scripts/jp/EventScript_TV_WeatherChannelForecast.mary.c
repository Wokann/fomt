#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_WeatherChannelForecast_SpringToSummerClear[] =
        "明日の天気予報ですっ！　　　\r\n"
        "一日快晴となり、少し暑い日と\r\n"
        "なるでしょう。{Press}";

    const char gText_TV_WeatherChannelForecast_SpringToSummerRain[] =
        "明日の天気予報ですっ！　　　\r\n"
        "今夜から朝にかけて、雲が　　\r\n"
        "広がり、明日は一日中雨が　　\r\n"
        "降り続けるでしょう。{Press}";

    const char gText_TV_WeatherChannelForecast_SpringToSummerTyphoon[] =
        "明日の天気予報ですっ！　　　\r\n"
        "台風が直撃するもようです！　\r\n"
        "みなさん、戸締りは厳重に！　\r\n"
        "動物は小屋に入れましょう！！{Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalSnow[] =
        "雪！{Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalSnowstorm[] =
        "大雪！{Press}";

    const char gText_TV_WeatherChannelForecast_SpringClear[] =
        "明日の天気予報ですっ！　　　\r\n"
        "全国的に朝から晴れで、　　　\r\n"
        "青空がひろがるでしょう。{Press}";

    const char gText_TV_WeatherChannelForecast_SpringRain[] =
        "明日の天気予報ですっ！　　　\r\n"
        "朝から雨となり、一日中　　　\r\n"
        "降り続けるもようです。{Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalTyphoonWarmSeason[] =
        "台風！{Press}";

    const char gText_TV_WeatherChannelForecast_SummerToFallClear[] =
        "明日の天気予報ですっ！　　　\r\n"
        "カラッとした、気持ちのよい　\r\n"
        "秋晴れとなるでしょう。{Press}";

    const char gText_TV_WeatherChannelForecast_SummerToFallRain[] =
        "明日の天気予報ですっ！　　　\r\n"
        "朝から雨で、少し肌寒い一日と\r\n"
        "なるでしょう。{Press}";

    const char gText_TV_WeatherChannelForecast_FallToWinterClear[] =
        "明日の天気予報ですっ！　　　\r\n"
        "小春びよりで、すごしやすい　\r\n"
        "一日となるでしょう。{Press}";

    const char gText_TV_WeatherChannelForecast_NoSignalRain[] =
        "雨！{Press}";

    const char gText_TV_WeatherChannelForecast_WinterSnow[] =
        "明日の天気予報ですっ！　　　\r\n"
        "雪が降ります。　　　　　　　\r\n"
        "カゼなどひかないように気を　\r\n"
        "つけて下さい。{Press}";

    const char gText_TV_WeatherChannelForecast_WinterSnowstorm[] =
        "明日の天気予報ですっ！　　　\r\n"
        "大雪になります。　　　　　　\r\n"
        "みなさん、戸締りは厳重に！　\r\n"
        "動物は小屋に入れましょう！！{Press}";
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
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringToSummerTyphoon);
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
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringToSummerRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_WEATHER_TYPHOON);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_SpringToSummerTyphoon);
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
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalTyphoonWarmSeason);
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
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_FallToWinterClear);
                        break;
                    case WEATHER_RAIN:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalRain);
                        break;
                    case WEATHER_TYPHOON:
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_WeatherChannelForecast_NoSignalTyphoonWarmSeason);
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
