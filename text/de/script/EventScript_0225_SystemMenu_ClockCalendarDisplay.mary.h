mary_text_table
{
    const char gText_SystemMenu_ClockCalendarDisplay_Spring[] =
        "Frühling";

    const char gText_SystemMenu_ClockCalendarDisplay_Summer[] =
        "Sommer";

    const char gText_SystemMenu_ClockCalendarDisplay_Fall[] =
        "Herbst";

    const char gText_SystemMenu_ClockCalendarDisplay_Winter[] =
        "Winter";

    const char gText_SystemMenu_ClockCalendarDisplay_Sunday[] =
        "Sonntag";

    const char gText_SystemMenu_ClockCalendarDisplay_Monday[] =
        "Montag";

    const char gText_SystemMenu_ClockCalendarDisplay_Tuesday[] =
        "Dienstag";

    const char gText_SystemMenu_ClockCalendarDisplay_Wednesday[] =
        "Mittwoch";

    const char gText_SystemMenu_ClockCalendarDisplay_Thursday[] =
        "Donnerstag";

    const char gText_SystemMenu_ClockCalendarDisplay_Friday[] =
        "Freitag";

    const char gText_SystemMenu_ClockCalendarDisplay_Saturday[] =
        "Samstag";

    const char gText_SystemMenu_ClockCalendarDisplay_CurrentDate[] =
        "Jahr {Var1}\r\n"
        "{Var2} Tag {Var3} ({Var4}){Press}";

#if defined(UNIFY_REGIONS)
    const char gText_SystemMenu_ClockCalendarDisplay_MorningTimeSpacedZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_MorningTimeSpacedMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_MorningTimeZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_MorningTimeMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeSpacedZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeSpacedMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_AfternoonTimeMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";
#else
    const char gText_SystemMenu_ClockCalendarDisplay_TimeWithZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_SystemMenu_ClockCalendarDisplay_TimeWithMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";
#endif
};
