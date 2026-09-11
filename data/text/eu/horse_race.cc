#include "horse_race_text.hh"

#if defined(FOMT_TEXT_HORSE_RACE_TICKET_CONTROLS)

// Static Horse Race text.  The text processor converts these UTF-8 strings
// and named controls into the exact regional ROM bytes during the build.

char const gText_HorseRace_BuyTicketDeclined[] =
    "Sure you don't want one?";

char const gText_HorseRace_Yes[] =
    "Yes";

char const gText_HorseRace_No[] =
    "No";

char const gText_HorseRace_ComeAgain[] =
    "\p"
    "Come again.{Press}";

char const gText_HorseRace_TakeYourTime[] =
    "\p"
    "Take your time.{Press}";

char const gText_HorseRace_TicketPurchaseConfirmation[] =
    "So this is what you want?";

char const gText_HorseRace_TicketPurchaseApproval[] =
    "\p"
    "Here you go.\r\n"
    "Best of luck to you!{Press}";

char const gText_HorseRace_ChangeMind[] =
    "\p"
    "Change your mind?{Press}";

char const gText_HorseRace_ExplanationQuestion[] =
    "Need to hear how to do it?";

char const gText_HorseRace_ExplanationBasics[] =
    "\p"
    "OK, listen carefully.{Press}\r\n"
    "Use the A Button to spur\r\n"
    "your horse on faster.{Press}\r\n"
    "Remember, though, that your\r\n"
    "horse only has a certain\r\n"
    "amount of stamina.{Press}";

char const gText_HorseRace_ExplanationGreenStamina[] =
    "\p"
    "When your horse is still in\r\n"
    "the green, it has plenty of\r\n"
    "stamina left.{Press}";

char const gText_HorseRace_ExplanationYellowStamina[] =
    "\p"
    "If you speed up even more,\r\n"
    "your horse will go into\r\n"
    "the yellow.{Press}";

char const gText_HorseRace_ExplanationRedStamina[] =
    "\p"
    "Speed up even more,\r\n"
    "and you'll enter the red.{Press}\r\n"
    "Once you're in the red you\r\n"
    "can't speed up any more.{Press}";

char const gText_HorseRace_ExplanationStaminaRecovery[] =
    "\p"
    "Hold off on the A Button to\r\n"
    "allow your horse to regain\r\n"
    "Stamina.{Press}\r\n"
    "Pace your horse judiciously\r\n"
    "and you have a chance!{Press}";

char const gText_HorseRace_ExplanationUnderstoodQuestion[] =
    "Everything understood?";

char const gText_HorseRace_ExplanationUnderstood[] =
    "Got it.";

char const gText_HorseRace_ExplanationRepeat[] =
    "Come again?";

char const gText_HorseRace_StartRace[] =
    "\p"
    "Let's get started, then!{Press}";

char const gText_HorseRace_RaceStartAnnouncement[] =
    "\p"
    "No.1 \xFC\r\n"
    "No.2 \xFD{Press}\r\n"
    "No.3 \xFE\r\n"
    "No.4 \xFF{Press}\r\n"
    "On your marks...{Press}\p"
    "Get set....{Press}";

char const gText_HorseRace_RaceResults[] =
    "\p"
    "Race Results:\r\n"
    "1st place \xFC\r\n"
    "2nd place \xFD{Press}\r\n"
    "3rd place \xFE\r\n"
    "4th place \xFF{Press}\r\n"
    "{Press}";

char const gText_HorseRace_RacePayouts[] =
    "\p"
    "Race \xFA payouts\r\n"
    "are as follows:{Press}";

char const gText_HorseRace_MedalExchangeExplanation[] =
    "\p"
    "Come to me if you want to\r\n"
    "exchange your medal\r\n"
    "for a prize.{Press}\r\n"
    "Just remember, you can\r\n"
    "only do it here.{Press}";

u16 const gHorseRaceTicketCharacterCodes[] =
    FOMT_GLYPH_TEXT("0123456789 xGYour medals");

char const gText_HorseRace_TicketPurchaseTitle[] =
    "Race  Winning Ticket    ";

char const gText_HorseRace_TicketPurchaseConfirm[] =
    "   Enter";

char const gText_HorseRace_TicketPurchaseMedalsToWin[] =
    "  Medals to Win     ";

char const gText_HorseRace_TicketControls_DPadUpDown[] =
    "Control Pad Up/Down:";

char const gText_HorseRace_TicketControls_SelectHorse[] =
    "  Select a horse to bet on.";

char const gText_HorseRace_TicketControls_DPadLeftRight[] =
    "Control Pad Left/Right:";

char const gText_HorseRace_TicketControls_ChangeQuantity[] =
    "  Change number of tickets.";

char const gText_HorseRace_TicketControls_LRButtons[] =
    "L/R Buttons:";

char const gText_HorseRace_TicketControls_ChangeQuantityByTen[] =
    "  Change number of tickets";

char const gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation[] =
    "  by ten.";

char const gText_HorseRace_TicketControls_MoveCursorToConfirm[] =
    "Move the cursor to OK.";

char const gText_HorseRace_TicketControls_Buy[] =
    "Buy with the A Button.";

char const gText_HorseRace_TicketControls_Cancel[] =
    "Cancel with the B Button.";

#elif defined(FOMT_TEXT_HORSE_RACE_PRIZE_CATALOG)

HorseRacePrize const gHorseRacePrizeCatalog[] = {
    { "Jewel of Truth", 1000 },
    { "Power Berry", 900 },
    { "Facial Pack", 42 },
    { "Skin Lotion", 35 },
    { "Sunblock", 30 },
    { "Necklace", 20 },
    { "Broach", 18 },
    { "Diamond", 14 },
    { "Truffle", 10 },
    { "Adamantite", 4 },
    { "Dress", 250 },
    { "Perfume", 150 },
};

#elif defined(FOMT_TEXT_HORSE_RACE_PRIZE_EXCHANGE)

char const gText_HorseRace_PrizeExchangePrompt[] =
    "Exchange for a prize?";

char const gText_HorseRace_PrizeExchangeYes[] =
    "Yes";

char const gText_HorseRace_PrizeExchangeNo[] =
    "No";

char const gText_HorseRace_PrizeExchangeComeAgain[] =
    "\p"
    "Come again any time.{Press}";

char const gText_HorseRace_PrizeExchangeTakeYourTime[] =
    "\p"
    "Take your time now.{Press}";

char const gText_HorseRace_PrizeSelectionConfirmation[] =
    "So want \xFF?";

char const gText_HorseRace_PrizeExchangeLeaveConfirmation[] =
    "\p"
    "So you want to leave?{Press}";

char const gText_HorseRace_PrizeExchangeInsufficientMedals[] =
    "\p"
    "You don't have enough\r\n"
    "medals for this.{Press}";

#else
#error "Select one horse_race text fragment before including this file."
#endif
