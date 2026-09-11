#include "fishing_results_text.hh"
#include "item.hh"

// The selected regional record names directly precede their native pointer
// table and runtime trailer in both ROMs.
#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(fishing_results.cc)
#else
#include FOMT_TEXT_INCLUDE(fishing_results.cc)
#endif

// Indexed directly by the native FishingRecordId domain.  When a regional
// ROM uses one physical string for multiple records, the table repeats that
// same pointer instead of introducing an assembler alias.
char const * const gFishingRecordNames[FISHING_RECORD_COUNT] = {
    gText_FishingRecord_PirateFortune,
    gText_FishingRecord_FossilOfFish,
    gText_FishingRecord_PowerBerry,
    gText_FishingRecord_MessageBottle,
    gText_FishingRecord_EmptyCan,
    gText_FishingRecord_Branch,
    gText_FishingRecord_FishBones,
    gText_FishingRecord_Boots,
    gText_FishingRecord_RockTrout,
    gText_FishingRecord_Scad,
    gText_FishingRecord_Fatminnow,
    gText_FishingRecord_CherrySalmon,
    gText_FishingRecord_Pigfish,
    gText_FishingRecord_Sardine,
    gText_FishingRecord_MountainTrout,
    gText_FishingRecord_Whitefish,
    gText_FishingRecord_Eel,
    gText_FishingRecord_Bitterling,
    gText_FishingRecord_Bonito,
    gText_FishingRecord_Fluke,
    gText_FishingRecord_Filefish,
    gText_FishingRecord_GoldenCarp,
    gText_FishingRecord_SilverCarp22,
    gText_FishingRecord_KelpBass,
    gText_FishingRecord_Bighead,
    gText_FishingRecord_Salmon,
    gText_FishingRecord_Mackerel,
    gText_FishingRecord_Needlefish,
    gText_FishingRecord_SpanishMackerel,
    gText_FishingRecord_SauryPike,
    gText_FishingRecord_Dorado,
    gText_FishingRecord_RedSnapper,
    gText_FishingRecord_Cod,
    gText_FishingRecord_Roach,
    gText_FishingRecord_BrownHakeling,
    gText_FishingRecord_RainbowTrout,
    gText_FishingRecord_Herring,
#if defined(REGION_JP)
    gText_FishingRecord_SilverCarp37,
#else
    gText_FishingRecord_SilverCarp22,
#endif
    gText_FishingRecord_Sandfish,
    gText_FishingRecord_Flounder,
    gText_FishingRecord_Blowfish,
    gText_FishingRecord_BlackBass,
    gText_FishingRecord_Yellowtail,
    gText_FishingRecord_Bluegill,
    gText_FishingRecord_CrucianCarp,
    gText_FishingRecord_Greenling,
    gText_FishingRecord_Tuna,
    gText_FishingRecord_OceanSunfish,
    gText_FishingRecord_Lionfish,
    gText_FishingRecord_Rockfish,
    gText_FishingRecord_LargeSalmon,
    gText_FishingRecord_Snakehead,
    gText_FishingRecord_LakeSmelt,
    gText_FishingRecord_JapaneseHuchen,
    gText_FishingRecord_Monkfish,
    gText_FishingRecord_Catfish,
    gText_FishingRecord_Carp,
    gText_FishingRecord_Coelacanth,
    gText_FishingRecord_Squid,
};

extern char const gCppRuntimeBadAlloc_FishingResultsTrailer[] =
    "bad_alloc";

// The Power Berry result follows the native UI's dedicated branch.  Its table
// slot deliberately preserves the original ARTICLE_WEEDS placeholder.
u32 const gFishingRecordArticleIds[] SECTION(".rodata.fishing_record_article_ids") = {
    ARTICLE_PIRATE_TREASURE,
    ARTICLE_FOSSIL_OF_FISH,
    ARTICLE_WEEDS,
    ARTICLE_MESSAGE_IN_A_BOTTLE,
    ARTICLE_EMPTY_CAN,
    ARTICLE_BRANCHES,
    ARTICLE_FISH_BONES,
    ARTICLE_BOOTS,
};
