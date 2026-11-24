mary_text_table
{
    const char gText_NPCEvent_Won_AppleChallenge_WonOffersThreeRareApples[] =
        "I brought 3 rare and \r\n"
        "valuable items for you \r\n"
        "today! These are special{Press}\r\n"
        "for you.{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExplainsApplesAreSpecial[] =
        "These 3 kinds of Apples are\r\n"
        "no ordinary Apples, \r\n"
        "you understand? {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesSUGDWApple[] =
        "This is the first kind. \r\n"
        "It's called SUGDW Apple. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsSUGDWName[] =
        "It's real name is very long:\r\n"
        "Super Ultra Great Delicious\r\n"
        "Wonderful Apple!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName[] =
#if defined(BUGFIX)
    // He is panting after the long name, not forgetting it.
        "*pant* *pant* *pant*...\r\n"
        "That's its name.{Press}";
#else
        "Sometimes I can't remember\r\n"
        "all of it...! {Press}";
#endif

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesHMSGBApple[] =
        "This is the second one: \r\n"
        "the HMSGB Apple! {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsHMSGBName[] =
        "That's short for Hyper \r\n"
        "Miracle Sweet Gorgeous \r\n"
        "Beautiful  Apple!{Press}";

#ifndef UNIFY_REGIONS
    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName_2[] =
#if defined(BUGFIX)
    // He is panting after the long name, not forgetting it.
        "*pant* *pant* *pant*...\r\n"
        "That's its name.{Press}";
#else
        "That one is hard to \r\n"
        "remember, too!{Press}";
#endif
#endif

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesAEPFEApple[] =
        "Finally, I have this. \r\n"
        "It's an AEPFE Apple!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsAEPFEName[] =
        "That's short for:\r\n"
        "Angel Eternal Pure \r\n"
        "Fresh Elegant Apple. {Press}";

#ifndef UNIFY_REGIONS
    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName_3[] =
#if defined(BUGFIX)
    // He is panting after the long name, not forgetting it.
        "*pant* *pant* *pant*...\r\n"
        "That's its name.{Press}";
#else
        "See? Even the name \r\n"
        "is wonderful!{Press}";
#endif
#endif

    const char gText_NPCEvent_Won_AppleChallenge_WonUrgesPlayerToTasteApple[] =
        "Of course, you have to eat\r\n"
        "each one to see how \r\n"
        "wonderful it really is!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonOffersEachAppleFor500G[] =
        "Price is 500G. \r\n"
        "Very cheap, very cheap. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_AppleSelectionPrompt[] =
        "Which will it be?";

    const char gText_NPCEvent_Won_AppleChallenge_SelectSUGDWApple[] =
        "SUGDW";

    const char gText_NPCEvent_Won_AppleChallenge_SelectHMSGBApple[] =
        "HMSGB";

    const char gText_NPCEvent_Won_AppleChallenge_SelectAEPFEApple[] =
        "AEPFE";

    const char gText_NPCEvent_Won_AppleChallenge_DeclineApplePurchase[] =
        "No thanks.";

    const char gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple[] =
        "Thanks very much!\r\n"
        "I didn't think anyone would\r\n"
        "ever -- I mean...{Press}\r\n"
        "You have a fine eye, sir!\r\n"
        "I'll be going now!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonMocksPlayerForLacking500G[] =
        "You don't even have 500G?\r\n"
        "What a poor man you are!{Press}";
};
