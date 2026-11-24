mary_text_table
{
    const char gText_NPCEvent_Won_AppleChallenge_WonOffersThreeRareApples[] =
        "Ich habe dir heute 3 seltene\r\n"
        "und sehr wertvolle \r\n"
        "Gegenstände mitgebracht!{Press}\r\n"
        "Die sind speziell\r\n"
        "für dich.{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExplainsApplesAreSpecial[] =
        "Diese 3 Apfelsorten sind\r\n"
        "keine gewöhnlichen Äpfel,\r\n"
        "verstehst du. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesSUGDWApple[] =
        "Dies ist die erste Sorte.\r\n"
        "Der SUGDW Apfel. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsSUGDWName[] =
        "Sein voller Name ist lang:\r\n"
        "Super-Ultra-Guter-Delikater-\r\n"
        "Wunder-Apfel!{Press}";

#if defined(BUGFIX)
    // He is panting after the long name, not forgetting it.
    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName[] =
        "*keuch* *keuch* *keuch*...\r\n"
        "So heißt er.{Press}";
#else
    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName[] =
        "Manchmal vergesse ich\r\n"
        "Teile des Namens...! {Press}";
#endif

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesHMSGBApple[] =
        "Dies ist die zweite Sorte:\r\n"
        "Der HMSGB Apfel! {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsHMSGBName[] =
        "Die Abkürzung für Hyper-\r\n"
        "Magischer-Süßer-Guter-\r\n"
        "Galaktischer-Bombiger Apfel!{Press}";

#if defined(BUGFIX)
#ifndef UNIFY_REGIONS
    // He is panting after the long name, not forgetting it.
    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName_2[] =
        "*keuch* *keuch* *keuch*...\r\n"
        "So heißt er.{Press}";
#endif
#else
    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName_2[] =
        "Ebenfalls schwer zu \r\n"
        "merken!{Press}";
#endif

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesAEPFEApple[] =
        "Und schließlich dieser. \r\n"
        "Das ist ein HKEFG Apfel!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsAEPFEName[] =
        "Die Abkürzung für:\r\n"
        "Himmlisch-Knackig-Ewig-\r\n"
        "Frischer-Geschmackvoller.{Press}";

#if defined(BUGFIX)
#ifndef UNIFY_REGIONS
    // He is panting after the long name, not forgetting it.
    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName_3[] =
        "*keuch* *keuch* *keuch*...\r\n"
        "So heißt er.{Press}";
#endif
#else
    const char gText_NPCEvent_Won_AppleChallenge_ReactsToLongAppleName_3[] =
        "Siehst du? Sogar der Name\r\n"
        "ist wundervoll!{Press}";
#endif

    const char gText_NPCEvent_Won_AppleChallenge_WonUrgesPlayerToTasteApple[] =
        "Natürlich musst du alle 3\r\n"
        "probieren, damit du siehst,\r\n"
        "wie gut sie sind!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonOffersEachAppleFor500G[] =
        "Der Preis ist 500G. \r\n"
        "Sehr günstig, sehr günstig.{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_AppleSelectionPrompt[] =
        "Welcher darf es sein?";

    const char gText_NPCEvent_Won_AppleChallenge_SelectSUGDWApple[] =
        "SUGDW";

    const char gText_NPCEvent_Won_AppleChallenge_SelectHMSGBApple[] =
        "HMSGB";

    const char gText_NPCEvent_Won_AppleChallenge_SelectAEPFEApple[] =
        "HKEFG";

    const char gText_NPCEvent_Won_AppleChallenge_DeclineApplePurchase[] =
        "Nein, danke.";

    const char gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple[] =
        "Sehr vielen Dank!\r\n"
        "Ich hätte nicht gedacht,\r\n"
        "dass je einer ? Ich meine...{Press}\r\n"
        "Sehr gute Augen, mein Herr!\r\n"
        "Ich gehe jetzt!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonMocksPlayerForLacking500G[] =
        "Du hast keine 500G?\r\n"
        "Du armer Mann!{Press}";
};
