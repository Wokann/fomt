#include "horse_race_text.hh"

#include "item.hh"

#if defined(REGION_JP)
#include "data/text/jp/horse_race.cc"
#else
#include "data/text/us/horse_race.cc"
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
#include "data/text/jp/horse_race_prize_catalog.cc"
#else
#include "data/text/us/horse_race_prize_catalog.cc"
#endif

u16 const gHorseRacePrizeItemIds[] = {
    ARTICLE_JEWEL_OF_TRUTH,
    ARTICLE_MOON_DROP_GRASS, // Native placeholder; Power Berry has a dedicated branch.
    ARTICLE_FACIAL_PACK,
    ARTICLE_SKIN_LOTION,
    ARTICLE_SUNBLOCK,
    ARTICLE_NECKLACE,
    ARTICLE_BROACH,
    ARTICLE_DIAMOND,
    FOOD_TRUFFLE, // The only food entry; the native code selects its food branch.
    ARTICLE_ADAMANTITE,
    ARTICLE_DRESS,
    ARTICLE_PERFUME,
};

#if defined(REGION_JP)
#include "data/text/jp/horse_race_prize_exchange.cc"
#else
#include "data/text/us/horse_race_prize_exchange.cc"
#endif

// The JP prize-exchange renderer reads a fixed twenty-glyph field and its
// original table has no terminator. The US counterpart retains its terminal.
u16 const gHorseRacePrizeExchangeCharacterCodes[] =
#if defined(REGION_JP)
    FOMT_GLYPH_SEQUENCE("０１２３４５６７８９枚倍Ｇ現在のメダル数");
#else
    FOMT_GLYPH_TEXT("0123456789 xGYour medals");
#endif
