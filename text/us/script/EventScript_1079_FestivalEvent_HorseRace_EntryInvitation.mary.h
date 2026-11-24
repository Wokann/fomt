mary_text_table
{
#ifdef BUGFIX
    const char gText_FestivalEvent_HorseRace_EntryInvitation_NoHorse[] =
#else
    const char gText_FestivalEvent_HorseRace_EntryInvitation_SharedNoHorseOrYoungHorse[] =
#endif
        "The Horse Races are \r\n"
        "tomorrow at the Square, you\r\n"
        "know...{Press}\p"
#ifdef BUGFIX
    // The player has no horse to enter.
        "If you had a Horse,\r\n"
        "I would have liked you\r\n"
        "to enter...{Press}";
#else
        "If you've got a Horse, you\r\n"
        "should consider competing!{Press}";
#endif

#ifdef BUGFIX
    const char gText_FestivalEvent_HorseRace_EntryInvitation_YoungHorse[] =
        "The Horse Races are \r\n"
        "tomorrow at the Square, you\r\n"
        "know...{Press}\p"
    // The player needs an adult horse to enter.
        "If you had an adult Horse,\r\n"
        "I would have liked you\r\n"
        "to enter...{Press}";
#endif

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAsksPlayerToEnterAdultHorse[] =
        "Hi there, {Player}. \r\n"
        "Are you going to compete\r\n"
        "in the Horse Races in the {Press}\r\n"
        "Square tomorrow?{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceEnterHorse[] =
        "I'll compete.";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceDeclineEntry[] =
        "I don't think so.";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAcceptsHorseRaceEntry[] =
        "In that case, bring\r\n"
        "{Horse} to \r\n"
        "the Square by 10AM. {Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasSuggestsSpectatingAndBettingAfterDecline[] =
        "Really?...\r\n"
        "Well, you can still \r\n"
        "place bets on the Race.{Press}\r\n"
        "It's fun - you should come!{Press}";
};
