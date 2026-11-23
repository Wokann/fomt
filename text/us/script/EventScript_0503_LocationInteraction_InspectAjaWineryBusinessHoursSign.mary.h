mary_text_table
{
    const char gText_LocationInteraction_InspectAjaWineryBusinessHoursSign[] =
        "Aja Winery\r\n"
        "Open 10AM to noon\r\n"
// The sign says Sunday, but the winery shop actually closes on Saturday.
#ifdef BUGFIX
        "everyday except Saturday{Press}\r\n"
#else
        "everyday except Sunday{Press}\r\n"
#endif
        "We sell wine and juice.{Press}";
};
