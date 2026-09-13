#include "horse_race_text.hh"

#include "item.hh"

#if defined(REGION_JP)
#define FOMT_TEXT_HORSE_RACE_TICKET_CONTROLS
#include FOMT_TEXT_INCLUDE(horse_race.cc)
#undef FOMT_TEXT_HORSE_RACE_TICKET_CONTROLS
#else
#define FOMT_TEXT_HORSE_RACE_TICKET_CONTROLS
#include FOMT_TEXT_INCLUDE(horse_race.cc)
#undef FOMT_TEXT_HORSE_RACE_TICKET_CONTROLS
#endif

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

char const gCppRuntimeBadAlloc_HorseRaceTicketControls[] =
    "bad_alloc";

#if defined(REGION_JP)
#define FOMT_TEXT_HORSE_RACE_PRIZE_CATALOG
#include FOMT_TEXT_INCLUDE(horse_race.cc)
#undef FOMT_TEXT_HORSE_RACE_PRIZE_CATALOG
#else
#define FOMT_TEXT_HORSE_RACE_PRIZE_CATALOG
#include FOMT_TEXT_INCLUDE(horse_race.cc)
#undef FOMT_TEXT_HORSE_RACE_PRIZE_CATALOG
#endif

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

#if defined(REGION_JP)
#define FOMT_TEXT_HORSE_RACE_PRIZE_EXCHANGE
#include FOMT_TEXT_INCLUDE(horse_race.cc)
#undef FOMT_TEXT_HORSE_RACE_PRIZE_EXCHANGE
#else
#define FOMT_TEXT_HORSE_RACE_PRIZE_EXCHANGE
#include FOMT_TEXT_INCLUDE(horse_race.cc)
#undef FOMT_TEXT_HORSE_RACE_PRIZE_EXCHANGE
#endif

// The JP prize-exchange renderer reads a fixed twenty-glyph field and its
// original table has no terminator. The US counterpart retains its terminal.
u16 const gHorseRacePrizeExchangeCharacterCodes[] =
#if defined(REGION_JP)
    FOMT_GLYPH_SEQUENCE("０１２３４５６７８９枚倍Ｇ現在のメダル数");
#elif defined(REGION_DE)
    FOMT_GLYPH_SEQUENCE("0123456789 xGD. Medillen");
#else
    FOMT_GLYPH_TEXT("0123456789 xGYour medals");
#endif
