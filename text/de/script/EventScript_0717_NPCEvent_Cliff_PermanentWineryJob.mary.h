mary_text_table
{
    const char gText_NPCEvent_Cliff_PermanentWineryJob_AskToHelpAtWineryUntilFive[] =
        "Kannst du uns bis \r\n"
        "ca. 17 Uhr helfen?{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ChoiceAcceptWineryHelp[] =
#ifdef BUGFIX
        // The first answer accepts the request for help.
        "Gerne.";
#else
        "Sorry";
#endif

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ChoiceDeclineWineryHelp[] =
#ifdef BUGFIX
        // Keep the apology with the refusal.
        "Sorry, ich kann nicht.";
#else
        "ich kann nicht.";
#endif

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CannotWorkWhileHoldingItem[] =
        "Mit etwas in der Hand \r\n"
        "kannst du nicht arbeiten.{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_KeepUpTheGoodWork[] =
        "Mach deine Arbeit gut!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_BothOfYouKeepUpTheGoodWork[] =
        "Macht eure Arbeit gut!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeTellsPlayerToKeepWorking[] =
        "Nicht schlapp machen!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_WagesDeposited[] =
        "Danke fürs Aushelfen. \r\n"
        "Ich habe dir \r\n"
        "deinen Lohn gegeben. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ThanksForHelpOffersGrapeJuice[] =
        "Danke für deine Hilfe.\r\n"
        "Nimm etwas frischen Saft.{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeExplainsHarvestedGrapesBecomeWine[] =
        "Freu dich auf den Wein, \r\n"
        "wir aus den Trauben von\r\n"
        "heute machen werden! {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_PlayerOffersCliffPermanentJob[] =
        "Cliff, was hältst du davon,\r\n"
        "Vollzeit auf dem Aja\r\n"
        "Weingut zu arbeiten?{Press}\p"
        "Die Ernte ist vorbei, aber\r\n"
        "Weinkeltern ist ein\r\n"
        "Ganzjahresjob!<Wait>";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffAsksIfJobOfferIsSerious[] =
        "Echt!?...\r\n"
        "Meinst du das ernst?{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_WineryNeedsHelpAfterAjaLeft[] =
        "Seit Aja in die Stadt \r\n"
        "gegangen ist, ist es sehr\r\n"
// Manna is speaking about working with Duke, not with herself.
#ifdef BUGFIX
        "schwer f r Duke\r\n"
#else
        "schwer f r Manna\r\n"
#endif
        "und mich allein. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffAcceptsPermanentJob[] =
        "Vielen Dank! \r\n"
        "Du wirst es nicht \r\n"
        "bereuen!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffThanksPlayerForWineryOpportunity[] =
        "Das verdanken wir dir, \r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeSaysNoNeedToApologizeAndReturnsToWork[] =
#ifdef BUGFIX
        // Restore Duke's reply when the player declines and Cliff is absent.
        "Du musst dich nicht ent-\r\n"
        "schuldigen. Ich weiß, dass\r\n"
        "du deine eigene Arbeit hast.{Press}\p"
        "Ich werde einfach tun,\r\n"
        "was ich kann.{Press}";
#else
        "Ich bin froh, dich bei \r\n"
        "uns zu haben, Cliff.{Press}\p"
        "Nun lass mich dir ein\r\n"
        "paar andere Dinge zeigen, \r\n"
        "die hier gemacht werden...{Press}";
#endif

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeReturnsEveryoneToWork[] =
        "An die Arbeit, schätze ich!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeThanksPlayerForInvitingCliff[] =
        "Danke, {Player}, dass\r\n"
        "du daran gedacht hast,\r\n"
        "Cliff einzuladen. {Press}\r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_PlayerContinuesWineryWork[] =
        "Nun... Wieder an die Arbeit!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_InspiredByCliffsWineryWork[] =
        "Gut, Cliff so zufrieden \r\n"
        "mit der Arbeit zu sehen. {Press}";
};
