#include "horse_race_data.hh"

#include "item.hh"

#include FOMT_TEXT_INCLUDE(horse_race_data_1.cc)

// This renderer walks a preloaded glyph-code list rather than a normal text
// byte stream. The selected regional fragment preserves its terminator form.
u16 const gHorseRaceTicketCharacterCodes[] =
#include FOMT_TEXT_INCLUDE(horse_race_data_2.cc)
;

#include FOMT_TEXT_INCLUDE(horse_race_data_3.cc)

char const * const gHorseRaceTicketControls[] = {
    gText_HorseRace_TicketControls_DPadUpDown,
    gText_HorseRace_TicketControls_SelectHorse,
    gText_HorseRace_TicketControls_DPadLeftRight,
    gText_HorseRace_TicketControls_ChangeQuantity,
    gText_HorseRace_TicketControls_LRButtons,
    gText_HorseRace_TicketControls_ChangeQuantityByTen,
    gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation,
    gText_HorseRace_TicketControls_MoveCursorToConfirm,
    gText_HorseRace_TicketControls_Buy,
    gText_HorseRace_TicketControls_Cancel,
    nullptr,
};

#include FOMT_TEXT_INCLUDE(horse_race_data_4.cc)

// Prize names are inline fields of the native catalog, not a pointer table.
HorseRacePrize const gHorseRacePrizeCatalog[] = {
#include FOMT_TEXT_INCLUDE(horse_race_data_5.cc)
};

u16 const gHorseRacePrizeItemIds[] = {
    ITEM_ARTICLE_JEWEL_OF_TRUTH,
    ITEM_ARTICLE_FLOWER_MOON_DROP, // Native placeholder; Power Berry has a dedicated branch.
    ITEM_ARTICLE_FACIAL_PACK,
    ITEM_ARTICLE_SKIN_LOTION,
    ITEM_ARTICLE_SUNBLOCK,
    ITEM_ARTICLE_NECKLACE,
    ITEM_ARTICLE_BROOCH,
    ITEM_ARTICLE_DIAMOND,
    ITEM_FOOD_TRUFFLE, // The only food entry; the native code selects its food branch.
    ITEM_ARTICLE_ADAMANTITE,
    ITEM_ARTICLE_DRESS,
    ITEM_ARTICLE_PERFUME,
};

#include FOMT_TEXT_INCLUDE(horse_race_data_6.cc)

// The native renderer reads this preloaded glyph-code list directly.
u16 const gHorseRacePrizeExchangeCharacterCodes[] =
#include FOMT_TEXT_INCLUDE(horse_race_data_7.cc)
;
