mary_text_table
{
    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickAsksWhereYouAreGoing[] =
        "Where are you going?{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_LilliaSaysUpstairsIsNotCleaned[] =
        "I haven't cleaned \r\n"
        "upstairs yet.\r\n"
        "Please don't go up yet.{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickSaysUpstairsIsNotTidied[] =
        "I haven't picked up\r\n"
        "upstairs yet.\r\n"
        "Please don't go up yet.{Press}";

#ifndef UNIFY_REGIONS
    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_Shared_RickLilliaAndPopuriSayDoNotGoUpstairs[] =
        "Please don't go upstairs.{Press}";
#endif

#ifdef UNIFY_REGIONS
    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickSaysDoNotGoUpstairs[] =
        "Please don't go upstairs.{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_LilliaSaysDoNotGoUpstairs[] =
        "Please don't go upstairs.{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_PopuriSaysDoNotGoUpstairs[] =
        "Please don't go upstairs.{Press}";
#endif
};
