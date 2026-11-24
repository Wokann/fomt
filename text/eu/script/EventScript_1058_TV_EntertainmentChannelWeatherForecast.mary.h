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
#ifdef UNIFY_REGIONS
        "Here's tomorrow's forecast!\r\n"
        "It will begin raining in \r\n"
        "the morning and not stop\r\n"
        "all day. {Press}";
#else
        "Tomorrow's weather!\r\n"
        "It will rain all day!　\r\n"
        "Too bad!{Press}";
#endif

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoon[] =
        "Typhoon!{Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerToFallClear[] =
        "Here's tomorrow's forecast!\r\n"
        "It will be a nice, crisp \r\n"
        "and clear Fall day. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_SummerToFallRain[] =
        "Here's tomorrow's forecast!\r\n"
        "Morning will bring rain, and\r\n"
        "it will be a cold day.{Press}";

#ifdef UNIFY_REGIONS
    const char gText_TV_EntertainmentChannelWeatherForecast_SummerTyphoon[] =
        "Here's tomorrow's forecast!\r\n"
        "A typhoon will be passing\r\n"
        "through, so lock down all\r\n"
        "doors and windows, and put\r\n"
        "your animals in the Barn!{Press}";
#endif

    const char gText_TV_EntertainmentChannelWeatherForecast_FallToWinterClear[] =
        "Here's tomorrow's forecast!\r\n"
        "It will be a pleasant \r\n"
    // The next day is in winter, not spring.
#ifdef BUGFIX
        "mild Winter day. {Press}";
#else
        "early Spring day. {Press}";
#endif

    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalRain[] =
        "Rain!{Press}";

#ifndef UNIFY_REGIONS
    const char gText_TV_EntertainmentChannelWeatherForecast_NoSignalTyphoon_2[] =
        "Typhoon! {Press}";
#endif

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterSnow[] =
        "This is tomorrow's forecast!\r\n"
        "It will snow, so be careful\r\n"
        "not to catch cold. {Press}";

    const char gText_TV_EntertainmentChannelWeatherForecast_WinterSnowstorm[] =
        "Here's tomorrow's forecast!\r\n"
        "A snowstorm will hit, so \r\n"
        "lock down all doors and \r\n"
        "windows, and put your\r\n"
        "animals in the Barn!{Press}";

#ifndef UNIFY_REGIONS
    const char gText_TV_EntertainmentChannelWeatherForecast_SpringRain_2[] =
        "Here's tomorrow's forecast!\r\n"
        "It will begin raining in \r\n"
        "the morning and not stop\r\n"
        "all day. {Press}";
#endif

#ifndef UNIFY_REGIONS
    const char gText_TV_EntertainmentChannelWeatherForecast_WinterSnow_2[] =
        "Here's tomorrow's forecast!\r\n"
        "It will snow, so be careful\r\n"
        "not to catch cold. {Press}";
#endif
};
