mary_text_table
{
    const char gText_LocationInteraction_InspectTownCottageClock_Spring[] =
        "Frühling";

    const char gText_LocationInteraction_InspectTownCottageClock_Summer[] =
        "Sommer";

    const char gText_LocationInteraction_InspectTownCottageClock_Fall[] =
        "Herbst";

    const char gText_LocationInteraction_InspectTownCottageClock_Winter[] =
        "Winter";

    const char gText_LocationInteraction_InspectTownCottageClock_Sunday[] =
        "Sonntag";

    const char gText_LocationInteraction_InspectTownCottageClock_Monday[] =
        "Montag";

    const char gText_LocationInteraction_InspectTownCottageClock_Tuesday[] =
        "Dienstag";

    const char gText_LocationInteraction_InspectTownCottageClock_Wednesday[] =
        "Mittwoch";

    const char gText_LocationInteraction_InspectTownCottageClock_Thursday[] =
        "Donnerstag";

    const char gText_LocationInteraction_InspectTownCottageClock_Friday[] =
        "Freitag";

    const char gText_LocationInteraction_InspectTownCottageClock_Saturday[] =
        "Samstag";

    const char gText_LocationInteraction_InspectTownCottageClock_DateFormat[] =
        "Jahr {Var1}\r\n"
        "{Var2} Tag {Var3} ({Var4}){Press}";

#if defined(UNIFY_REGIONS)
    const char gText_LocationInteraction_InspectTownCottageClock_MorningTimeSpacedZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectTownCottageClock_MorningTimeSpacedMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectTownCottageClock_MorningTimeZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectTownCottageClock_MorningTimeMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectTownCottageClock_AfternoonTimeSpacedZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectTownCottageClock_AfternoonTimeSpacedMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectTownCottageClock_AfternoonTimeZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectTownCottageClock_AfternoonTimeMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";
#else
    const char gText_LocationInteraction_InspectTownCottageClock_TimeWithZeroPaddedMinutes[] =
        "{Var1}:0{Var2} Uhr{Press}";

    const char gText_LocationInteraction_InspectTownCottageClock_TimeWithMinutes[] =
        "{Var1}:{Var2} Uhr{Press}";
#endif
};
