#include "horse_race_text.hh"

#include "item.hh"

u16 const gHorseRacePrizeItemIds[] SECTION(".rodata.horse_race_prize_item_ids") = {
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

char const * const gHorseRaceTicketControls[] SECTION(".rodata.horse_race_ticket_controls") = {
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

char const gCppRuntimeBadAlloc_HorseRaceTicketControls[]
    SECTION(".rodata.horse_race_ticket_controls_trailer") =
        "bad_alloc";
