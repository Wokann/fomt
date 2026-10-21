#ifndef LIVESTOCK_HH
#define LIVESTOCK_HH

#include "prelude.h"

#include "animal.hh"
#include "fomt_constants.hh"

struct LivestockDayUpdateInfo
{
    struct AgeDeathRateEntry
    {
        /* +00 */ u16 age;
        /* +02 */ u8 death_rate;
    };

    /* +00 */ u8 fed_happy_rate;
    /* +01 */ u8 unfed_unhappy_rate;
    /* +02 */ u8 unhappy_sick_rates[7];
    /* +09 */ u8 neglect_death_rates[5];
    /* +10 */ AgeDeathRateEntry natural_death_rates[4];
};

typedef char LivestockDayUpdateInfoSizeCheck[sizeof(LivestockDayUpdateInfo) == 0x20 ? 1 : -1];
typedef char LivestockAgeDeathRateEntrySizeCheck[sizeof(LivestockDayUpdateInfo::AgeDeathRateEntry) == 4 ? 1 : -1];
typedef char LivestockNaturalDeathRatesOffsetCheck[offsetof(LivestockDayUpdateInfo, natural_death_rates) == 0x10 ? 1 : -1];
typedef char LivestockLifeStateWidthCheck[sizeof(MaryLivestockLifeState) == 4 ? 1 : -1];

struct Livestock : public Animal
{
    enum ProductRank
    {
        PRODUCT_RANK_0,
        PRODUCT_RANK_1,
        PRODUCT_RANK_2,
        PRODUCT_RANK_3,
        PRODUCT_RANK_4,
        PRODUCT_RANK_5,
    };

    Livestock(char const * name, ActorLocation const & location, u32 age, u32 days_fed);
    Livestock(ActorLocation const & location, u32 age, u32 days_fed);

    u32 GetDaysFed() const;
    bool HasBeenFed() const;
    bool IsUnhappy() const;
    bool IsSick() const;
    // Native callers compare the complete enum result, not a truncated byte.
    MaryLivestockLifeState GetLifeState() const;
    u32 GetCurrentOutdoorMinutes() const;
    u32 GetOutdoorMinutes() const;
    ProductRank GetProductRank() const;
    void AddOutdoorMinutes(u32 minutes);
    void ResetCurrentOutdoorMinutes();
    void SetSick();
    void ResetSick();
    void SetUnhappy();
    void ResetUnhappy();
    void SetFed();
    void DayUpdate(LivestockDayUpdateInfo const * info);

    /* +1C */ u32 days_fed : 5;
    /* +1C */ bool fed : 1;
    /* +1C */ bool unhappy : 1;
    /* +1C */ bool sick : 1;
    /* +1D */ u32 life_state : 2;
    /* +1D */ u32 days_unhappy : 3;
    /* +1D */ u32 days_sick : 3;
    /* +1E */ u32 current_outdoor_minutes : 9;
    /* +1E */ u32 total_outdoor_minutes : 16;
};

typedef char LivestockSizeCheck[sizeof(Livestock) == 0x24 ? 1 : -1];

#endif // LIVESTOCK_HH
