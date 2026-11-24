mary_text_table
{
#ifdef BUGFIX
    const char gText_FestivalEvent_HorseRace_EntryInvitation_NoHorse[] =
#else
    const char gText_FestivalEvent_HorseRace_EntryInvitation_SharedNoHorseOrYoungHorse[] =
#endif
        "Die Pferderennen sind \r\n"
        "morgen auf dem Rosen-\r\n"
        "platz...{Press}\p"
#ifdef BUGFIX
    // The player has no horse to enter.
        "Wenn du ein Pferd hättest,\r\n"
        "hätte ich dich gern im\r\n"
        "Rennen gesehen...{Press}";
#else
        "Wenn du ein Pferd hast,\r\n"
        "solltest du mitmachen!{Press}";
#endif

#ifdef BUGFIX
    const char gText_FestivalEvent_HorseRace_EntryInvitation_YoungHorse[] =
        "Die Pferderennen sind \r\n"
        "morgen auf dem Rosen-\r\n"
        "platz...{Press}\p"
    // The player needs an adult horse to enter.
        "Mit einem erwachsenen Pferd\r\n"
        "hätte ich dich gern im\r\n"
        "Rennen gesehen...{Press}";
#endif

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAsksPlayerToEnterAdultHorse[] =
        "Hi, {Player}. \r\n"
        "Machst du morgen bei\r\n"
        "den Pferderennen auf dem{Press}\r\n"
        "Rosenplatz mit?{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceEnterHorse[] =
        "Ich nehme teil.";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceDeclineEntry[] =
        "Nehme nicht teil.";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAcceptsHorseRaceEntry[] =
        "Dann bring \r\n"
        "{Horse} um \r\n"
        "10 Uhr zum Rosenplatz.{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasSuggestsSpectatingAndBettingAfterDecline[] =
        "Wirklich?...\r\n"
        "Du kannst immer noch \r\n"
        "Wetten abschließen.{Press}\r\n"
        "Du solltest kommen!{Press}";
};
