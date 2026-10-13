#include "fishing_results_data.hh"

FishingRecords::FishingRecords() {
    FishingRecord * record = records;
    for (i32 remaining = FISHING_RECORD_COUNT - 1; remaining != -1; --remaining) {
        record->count = 0;
        record->maximum_size = 0;
        ++record;
    }
}

// A catch always updates its counter, including when it is not a new size
// record. The return value reports only a change to the maximum size.
bool FishingRecords::RegisterCatch(u32 index, u32 size) {
    u32 new_maximum = size;
    bool changed = false;
    u32 * count = &records[index].count;
    if (*count <= 999999999) ++*count;
    u8 * maximum_base = reinterpret_cast<u8 *>(&records[0].maximum_size);
    u32 * maximum = reinterpret_cast<u32 *>(maximum_base + index * sizeof(FishingRecord));
    if (new_maximum > *maximum) {
        *maximum = new_maximum;
        changed = true;
    }
    return changed;
}

bool FishingRecords::HasCaughtEveryFishSpecies() const {
    bool result = true;
    for (u32 index = FISHING_RECORD_ROCK_TROUT; index <= FISHING_RECORD_SQUID; ++index)
        if (records[index].count == 0) result = false;
    return result;
}

u32 FishingRecords::GetTotalFishCaught() const {
    u32 result = 0;
    for (u32 index = FISHING_RECORD_ROCK_TROUT; index <= FISHING_RECORD_SQUID; ++index) {
        // Preserve the native word-sized addition before applying its cap.
        result += records[index].count;
        if (result > 999999999) result = 1000000000;
    }
    return result;
}

u32 FishingRecords::GetCatchCount(u32 index) const {
    FishingRecord const * record = records + index;
    return record->count;
}

u32 FishingRecords::GetMaximumSize(u32 index) const {
    u32 offset = index * sizeof(FishingRecord);
    u8 const * maximum = reinterpret_cast<u8 const *>(&records[0].maximum_size);
    return *reinterpret_cast<u32 const *>(maximum + offset);
}

// The record-screen caller consumes these six mapped values. Their precise
// resource meaning remains unverified, so do not give them guessed names.
u32 FishingRecords::GetUnknownRecordValue(u32 index) const {
    switch (index) {
    default: return 0xFC;
    case FISHING_RECORD_JAPANESE_HUCHEN: return 0xFC;
    case FISHING_RECORD_MONKFISH: return 0xF9;
    case FISHING_RECORD_CATFISH: return 0xFE;
    case FISHING_RECORD_CARP: return 0xFD;
    case FISHING_RECORD_COELACANTH: return 0xFA;
    case FISHING_RECORD_SQUID: return 0xFB;
    }
}

char const * FishingRecords::GetName(u32 index) const {
    return gFishingRecordNames[index];
}

#include FOMT_TEXT_INCLUDE(fishing_results_data_1.cc)

// Indexed directly by the native MaryFishingRecordId domain.  When a regional
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
    // The JP ROM has an independent name object for this record.
    gText_FishingRecord_SilverCarp37,
#else
    // The US-derived ROMs reuse the record-22 text pointer here.
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
#if defined(REGION_DE)
    // The DE ROM reuses the Bonito text pointer for this record.
    gText_FishingRecord_Bonito,
#else
    gText_FishingRecord_Tuna,
#endif
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

#include FOMT_TEXT_INCLUDE(fishing_results_data_2.cc)
