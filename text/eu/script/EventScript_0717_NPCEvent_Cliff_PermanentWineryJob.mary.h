mary_text_table
{
    const char gText_NPCEvent_Cliff_PermanentWineryJob_AskToHelpAtWineryUntilFive[] =
        "Can you help out \r\n"
        "until about 5PM?{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ChoiceAcceptWineryHelp[] =
        "Of course.";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ChoiceDeclineWineryHelp[] =
        "Sorry, I can't.";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CannotWorkWhileHoldingItem[] =
        "You can't work with \r\n"
        "something in your hand, \r\n"
        "you know!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_KeepUpTheGoodWork[] =
        "Do a good job, now!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_BothOfYouKeepUpTheGoodWork[] =
        "Do a good job, you two!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeTellsPlayerToKeepWorking[] =
        "No sloughing off, now!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_WagesDeposited[] =
        "Thanks for helping out. \r\n"
        "I've deposited your pay.{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_ThanksForHelpOffersGrapeJuice[] =
        "Thanks for all your help.\r\n"
        "Here is fresh grape juice.{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeExplainsHarvestedGrapesBecomeWine[] =
        "Look forward to tasting\r\n"
        "the Wine made of the\r\n"
        "Grapes you picked! {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_PlayerOffersCliffPermanentJob[] =
        "Cliff, what do you think \r\n"
        "about working here at Aja\r\n"
        "Winery full time? {Press}\p"
        "The harvest is over, but \r\n"
        "Wine making is a year-\r\n"
        "round job!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffAsksIfJobOfferIsSerious[] =
        "Really!?...\r\n"
        "You're serious?{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_WineryNeedsHelpAfterAjaLeft[] =
        "With Aja gone off to \r\n"
        "the city, it's awful hard \r\n"
// Manna is speaking about working with Duke, not with herself.
#ifdef BUGFIX
        "for just Duke and me. {Press}";
#else
        "for just Manna and me. {Press}";
#endif

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffAcceptsPermanentJob[] =
        "Thanks. You won't \r\n"
        "regret it!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_CliffThanksPlayerForWineryOpportunity[] =
        "This is all thanks to you, \r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeSaysNoNeedToApologizeAndReturnsToWork[] =
#ifdef BUGFIX
        // Restore Duke's reply when the player declines and Cliff is absent.
        "There's no need to\r\n"
        "apologize. I know you have\r\n"
        "your own work.{Press}\p"
        "I'll just do what I can.{Press}";
#else
        "I'm glad to have you \r\n"
        "with us, Cliff.{Press}\p"
        "Now, let me show you how\r\n"
        "some other things are \r\n"
        "done around here...{Press}";
#endif

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeReturnsEveryoneToWork[] =
        "Back to work, I guess!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_DukeThanksPlayerForInvitingCliff[] =
        "Thanks for thinking of \r\n"
        "inviting Cliff, \r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_PlayerContinuesWineryWork[] =
        "Now...Back to work!{Press}";

    const char gText_NPCEvent_Cliff_PermanentWineryJob_InspiredByCliffsWineryWork[] =
        "It's good to see Cliff \r\n"
        "so happy about his work. {Press}";
};
