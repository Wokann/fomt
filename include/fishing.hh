#ifndef FISHING_HH
#define FISHING_HH

#include "prelude.h"
#include "fomt_constants.hh"
#include "rucksack_item.hh"
#include "fishing_area.hh"

struct Location;
struct GameTime;
struct GameStateSaveImage;

struct FishingAttemptParameters {
    u16 bite_delay_frames;
    u16 reaction_window_frames;
    u32 area;
};

// The default text has one definition in the fishing implementation.
extern char const gText_Fishing_NoCatch[];

struct FishingCatchResult {
    // The native selector constructs this empty result before choosing a catch.
    FishingCatchResult()
        : name(gText_Fishing_NoCatch),
          size(0), item(), power_berry(false), king_fish(false),
          king_fish_record(FISHING_RECORD_COUNT), new_size_record(false) {}

    char const * name;
    u16 size;
    RucksackItem item;
    bool power_berry;
    bool king_fish;
    MaryFishingRecordId king_fish_record;
    bool new_size_record;
};

// One record per MaryFishingRecordId. The native reader uses a 32-byte stride.
// The old ARM ABI rounds these 30 bytes to 32; the tail is padding.
// Each seasonal row selects one of seven fishing areas: zero excludes a catch,
// abs(value) - 1 selects the rod level, and the sign selects the 70/30 pool.
// Level 7 in a row accepts any charge; mythic charge 6 accepts every level.
struct FishingCatchConfiguration {
    u8 minimum_size;
    u8 maximum_size;
    i8 rod_level_by_season[4][FISHING_AREA_COUNT];
};

EXTERN_C
FishingAttemptParameters GetFishingAttemptParameters(Location const & location, GameTime const & time);
FishingCatchResult SelectFishingCatch(u32 area, u8 charge_level, GameStateSaveImage * save);
EXTERN_C_END

extern u32 const gFishingCatchArticleIds[];
extern u16 const gFishingBiteDelaySeconds[][4];
extern u8 const gFishingCatchCategoryWeights[][5];
extern FishingCatchConfiguration const gFishingCatchConfigurations[];

typedef char FishingAttemptParametersSizeCheck[sizeof(FishingAttemptParameters) == 8 ? 1 : -1];
typedef char FishingCatchResultSizeCheck[sizeof(FishingCatchResult) == 24 ? 1 : -1];
typedef char FishingCatchResultItemCheck[offsetof(FishingCatchResult, item) == 8 ? 1 : -1];
typedef char FishingCatchResultRecordCheck[offsetof(FishingCatchResult, king_fish_record) == 16 ? 1 : -1];
typedef char FishingCatchConfigurationSizeCheck[sizeof(FishingCatchConfiguration) == 32 ? 1 : -1];

#endif // FISHING_HH
