#ifndef HORSE_RACE_TEXT_HH
#define HORSE_RACE_TEXT_HH

#include "prelude.h"

// The prize name is an inline field in the original 20-byte catalog entry,
// followed by the medal cost.  It is not a pointer to separately stored text.
struct HorseRacePrize {
    char name[16];
    u32 medal_cost;
};

extern char const gText_HorseRace_BuyTicketDeclined[];
extern char const gText_HorseRace_Yes[];
extern char const gText_HorseRace_No[];
extern char const gText_HorseRace_ComeAgain[];
extern char const gText_HorseRace_TakeYourTime[];
extern char const gText_HorseRace_TicketPurchaseConfirmation[];
extern char const gText_HorseRace_TicketPurchaseApproval[];
#if defined(REGION_JP)
extern char const gText_HorseRace_TicketPurchaseEncouragement[];
#endif
extern char const gText_HorseRace_ChangeMind[];
extern char const gText_HorseRace_ExplanationQuestion[];
extern char const gText_HorseRace_ExplanationBasics[];
extern char const gText_HorseRace_ExplanationGreenStamina[];
extern char const gText_HorseRace_ExplanationYellowStamina[];
extern char const gText_HorseRace_ExplanationRedStamina[];
extern char const gText_HorseRace_ExplanationStaminaRecovery[];
extern char const gText_HorseRace_ExplanationUnderstoodQuestion[];
extern char const gText_HorseRace_ExplanationUnderstood[];
extern char const gText_HorseRace_ExplanationRepeat[];
extern char const gText_HorseRace_StartRace[];
extern char const gText_HorseRace_RaceStartAnnouncement[];
extern char const gText_HorseRace_RaceResults[];
extern char const gText_HorseRace_RacePayouts[];
extern char const gText_HorseRace_MedalExchangeExplanation[];
// This ticket-rendering path reads one encoded glyph value at a time rather
// than a normal NUL-terminated text byte stream.
extern u16 const gHorseRaceTicketCharacterCodes[];
extern char const gText_HorseRace_TicketPurchaseTitle[];
extern char const gText_HorseRace_TicketPurchaseConfirm[];
extern char const gText_HorseRace_TicketPurchaseMedalsToWin[];
extern char const gText_HorseRace_TicketControls_DPadUpDown[];
extern char const gText_HorseRace_TicketControls_SelectHorse[];
extern char const gText_HorseRace_TicketControls_DPadLeftRight[];
extern char const gText_HorseRace_TicketControls_ChangeQuantity[];
extern char const gText_HorseRace_TicketControls_LRButtons[];
extern char const gText_HorseRace_TicketControls_ChangeQuantityByTen[];
extern char const gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation[];
extern char const gText_HorseRace_TicketControls_MoveCursorToConfirm[];
extern char const gText_HorseRace_TicketControls_Buy[];
extern char const gText_HorseRace_TicketControls_Cancel[];
extern char const gText_HorseRace_PrizeExchangePrompt[];
extern char const gText_HorseRace_PrizeExchangeYes[];
extern char const gText_HorseRace_PrizeExchangeNo[];
extern char const gText_HorseRace_PrizeExchangeComeAgain[];
extern char const gText_HorseRace_PrizeExchangeTakeYourTime[];
extern char const gText_HorseRace_PrizeSelectionConfirmation[];
extern char const gText_HorseRace_PrizeExchangeLeaveConfirmation[];
extern char const gText_HorseRace_PrizeExchangeInsufficientMedals[];
extern u16 const gHorseRacePrizeExchangeCharacterCodes[];
// One entry per gHorseRacePrizeCatalog entry. The native path distinguishes
// Article and Food values itself; the Power Berry slot retains its unused
// ARTICLE_MOON_DROP_GRASS placeholder because it has a dedicated branch.
extern u16 const gHorseRacePrizeItemIds[];
extern char const * const gHorseRaceTicketControls[];
extern char const gCppRuntimeBadAlloc_HorseRaceTicketControls[];
extern HorseRacePrize const gHorseRacePrizeCatalog[];

#endif
