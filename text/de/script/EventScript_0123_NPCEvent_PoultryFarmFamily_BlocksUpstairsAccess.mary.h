mary_text_table
{
    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickAsksWhereYouAreGoing[] =
        "Wo willst du denn hin?{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_LilliaSaysUpstairsIsNotCleaned[] =
        "Ich habe oben noch \r\n"
        "nicht geputzt.\r\n"
        "Bitte geh noch nicht hoch.{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickSaysUpstairsIsNotTidied[] =
        "Ich habe oben noch \r\n"
        "nicht aufgeräumt.\r\n"
        "Bitte geh noch nicht hoch.{Press}";

#ifndef UNIFY_REGIONS
    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_Shared_RickLilliaAndPopuriSayDoNotGoUpstairs[] =
        "Bitte geh nicht nach oben.{Press}";
#endif

#ifdef UNIFY_REGIONS
    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickSaysDoNotGoUpstairs[] =
        "Bitte geh nicht nach oben.{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_LilliaSaysDoNotGoUpstairs[] =
        "Bitte geh nicht nach oben.{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_PopuriSaysDoNotGoUpstairs[] =
        "Bitte geh nicht nach oben.{Press}";
#endif
};
