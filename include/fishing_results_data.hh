#ifndef FISHING_RESULTS_DATA_HH
#define FISHING_RESULTS_DATA_HH

#include "prelude.h"

#include "fomt_constants.hh"

// Saved at GameStateSaveImage +0x2C80. The first eight record IDs are
// non-fish catches; the completion and total-count queries start at ID 8.
struct FishingRecord {
    u32 count;
    u32 maximum_size; // Centimetres, as used by the fishing-record screen.
};

struct FishingRecords {
    FishingRecords();
    bool RegisterCatch(u32 index, u32 size);
    bool HasCaughtEveryFishSpecies() const;
    u32 GetTotalFishCaught() const;
    u32 GetCatchCount(u32 index) const;
    u32 GetMaximumSize(u32 index) const;
    u32 GetUnknownRecordValue(u32 index) const;
    char const * GetName(u32 index) const;

    FishingRecord records[FISHING_RECORD_COUNT];
};

typedef char FishingRecordSizeCheck[sizeof(FishingRecord) == 8 ? 1 : -1];
typedef char FishingRecordMaximumCheck[offsetof(FishingRecord, maximum_size) == 4 ? 1 : -1];
typedef char FishingRecordsSizeCheck[sizeof(FishingRecords) == 0x1D8 ? 1 : -1];

extern char const gText_FishingRecord_PirateFortune[];
extern char const gText_FishingRecord_FossilOfFish[];
extern char const gText_FishingRecord_PowerBerry[];
extern char const gText_FishingRecord_MessageBottle[];
extern char const gText_FishingRecord_EmptyCan[];
extern char const gText_FishingRecord_Branch[];
extern char const gText_FishingRecord_FishBones[];
extern char const gText_FishingRecord_Boots[];
extern char const gText_FishingRecord_RockTrout[];
extern char const gText_FishingRecord_Scad[];
extern char const gText_FishingRecord_Fatminnow[];
extern char const gText_FishingRecord_CherrySalmon[];
extern char const gText_FishingRecord_Pigfish[];
extern char const gText_FishingRecord_Sardine[];
extern char const gText_FishingRecord_MountainTrout[];
extern char const gText_FishingRecord_Whitefish[];
extern char const gText_FishingRecord_Eel[];
extern char const gText_FishingRecord_Bitterling[];
extern char const gText_FishingRecord_Bonito[];
extern char const gText_FishingRecord_Fluke[];
extern char const gText_FishingRecord_Filefish[];
extern char const gText_FishingRecord_GoldenCarp[];
extern char const gText_FishingRecord_SilverCarp22[];
extern char const gText_FishingRecord_KelpBass[];
extern char const gText_FishingRecord_Bighead[];
extern char const gText_FishingRecord_Salmon[];
extern char const gText_FishingRecord_Mackerel[];
extern char const gText_FishingRecord_Needlefish[];
extern char const gText_FishingRecord_SpanishMackerel[];
extern char const gText_FishingRecord_SauryPike[];
extern char const gText_FishingRecord_Dorado[];
extern char const gText_FishingRecord_RedSnapper[];
extern char const gText_FishingRecord_Cod[];
extern char const gText_FishingRecord_Roach[];
extern char const gText_FishingRecord_BrownHakeling[];
extern char const gText_FishingRecord_RainbowTrout[];
extern char const gText_FishingRecord_Herring[];
extern char const gText_FishingRecord_SilverCarp37[];
extern char const gText_FishingRecord_Sandfish[];
extern char const gText_FishingRecord_Flounder[];
extern char const gText_FishingRecord_Blowfish[];
extern char const gText_FishingRecord_BlackBass[];
extern char const gText_FishingRecord_Yellowtail[];
extern char const gText_FishingRecord_Bluegill[];
extern char const gText_FishingRecord_CrucianCarp[];
extern char const gText_FishingRecord_Greenling[];
extern char const gText_FishingRecord_Tuna[];
extern char const gText_FishingRecord_OceanSunfish[];
extern char const gText_FishingRecord_Lionfish[];
extern char const gText_FishingRecord_Rockfish[];
extern char const gText_FishingRecord_LargeSalmon[];
extern char const gText_FishingRecord_Snakehead[];
extern char const gText_FishingRecord_LakeSmelt[];
extern char const gText_FishingRecord_JapaneseHuchen[];
extern char const gText_FishingRecord_Monkfish[];
extern char const gText_FishingRecord_Catfish[];
extern char const gText_FishingRecord_Carp[];
extern char const gText_FishingRecord_Coelacanth[];
extern char const gText_FishingRecord_Squid[];

extern char const * const gFishingRecordNames[FISHING_RECORD_COUNT];
extern char const gCppRuntimeBadAlloc_FishingResultsTrailer[];

#endif // FISHING_RESULTS_DATA_HH
