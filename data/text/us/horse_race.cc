#include "horse_race_text.hh"

// Static Horse Race text.  The text processor converts these UTF-8 strings
// and named controls into the exact regional ROM bytes during the build.

char const gText_HorseRace_BuyTicketDeclined[] SECTION(".rodata.horse_race_dialogue") =
    "Sure you don't want one?";

char const gText_HorseRace_Yes[] SECTION(".rodata.horse_race_dialogue") =
    "Yes";

char const gText_HorseRace_No[] SECTION(".rodata.horse_race_dialogue") =
    "No";

char const gText_HorseRace_ComeAgain[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Come again.{Press}";

char const gText_HorseRace_TakeYourTime[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Take your time.{Press}";

char const gText_HorseRace_TicketPurchaseConfirmation[] SECTION(".rodata.horse_race_dialogue") =
    "So this is what you want?";

char const gText_HorseRace_TicketPurchaseApproval[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Here you go.\r\n"
    "Best of luck to you!{Press}";

char const gText_HorseRace_ChangeMind[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Change your mind?{Press}";

char const gText_HorseRace_ExplanationQuestion[] SECTION(".rodata.horse_race_dialogue") =
    "Need to hear how to do it?";

char const gText_HorseRace_ExplanationBasics[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "OK, listen carefully.{Press}\r\n"
    "Use the A Button to spur\r\n"
    "your horse on faster.{Press}\r\n"
    "Remember, though, that your\r\n"
    "horse only has a certain\r\n"
    "amount of stamina.{Press}";

char const gText_HorseRace_ExplanationGreenStamina[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "When your horse is still in\r\n"
    "the green, it has plenty of\r\n"
    "stamina left.{Press}";

char const gText_HorseRace_ExplanationYellowStamina[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "If you speed up even more,\r\n"
    "your horse will go into\r\n"
    "the yellow.{Press}";

char const gText_HorseRace_ExplanationRedStamina[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Speed up even more,\r\n"
    "and you'll enter the red.{Press}\r\n"
    "Once you're in the red you\r\n"
    "can't speed up any more.{Press}";

char const gText_HorseRace_ExplanationStaminaRecovery[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Hold off on the A Button to\r\n"
    "allow your horse to regain\r\n"
    "Stamina.{Press}\r\n"
    "Pace your horse judiciously\r\n"
    "and you have a chance!{Press}";

char const gText_HorseRace_ExplanationUnderstoodQuestion[] SECTION(".rodata.horse_race_dialogue") =
    "Everything understood?";

char const gText_HorseRace_ExplanationUnderstood[] SECTION(".rodata.horse_race_dialogue") =
    "Got it.";

char const gText_HorseRace_ExplanationRepeat[] SECTION(".rodata.horse_race_dialogue") =
    "Come again?";

char const gText_HorseRace_StartRace[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Let's get started, then!{Press}";

char const gText_HorseRace_RaceStartAnnouncement[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "No.1 \xFC\r\n"
    "No.2 \xFD{Press}\r\n"
    "No.3 \xFE\r\n"
    "No.4 \xFF{Press}\r\n"
    "On your marks...{Press}\p"
    "Get set....{Press}";

char const gText_HorseRace_RaceResults[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Race Results:\r\n"
    "1st place \xFC\r\n"
    "2nd place \xFD{Press}\r\n"
    "3rd place \xFE\r\n"
    "4th place \xFF{Press}\r\n"
    "{Press}";

char const gText_HorseRace_RacePayouts[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Race \xFA payouts\r\n"
    "are as follows:{Press}";

char const gText_HorseRace_MedalExchangeExplanation[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Come to me if you want to\r\n"
    "exchange your medal\r\n"
    "for a prize.{Press}\r\n"
    "Just remember, you can\r\n"
    "only do it here.{Press}";

char const gText_HorseRace_TicketPurchaseTitle[] SECTION(".rodata.horse_race_ticket_ui") =
    "Race  Winning Ticket    ";

char const gText_HorseRace_TicketPurchaseConfirm[] SECTION(".rodata.horse_race_ticket_ui") =
    "   Enter";

char const gText_HorseRace_TicketPurchaseMedalsToWin[] SECTION(".rodata.horse_race_ticket_ui") =
    "  Medals to Win     ";

char const gText_HorseRace_TicketControls_DPadUpDown[] SECTION(".rodata.horse_race_ticket_ui") =
    "Control Pad Up/Down:";

char const gText_HorseRace_TicketControls_SelectHorse[] SECTION(".rodata.horse_race_ticket_ui") =
    "  Select a horse to bet on.";

char const gText_HorseRace_TicketControls_DPadLeftRight[] SECTION(".rodata.horse_race_ticket_ui") =
    "Control Pad Left/Right:";

char const gText_HorseRace_TicketControls_ChangeQuantity[] SECTION(".rodata.horse_race_ticket_ui") =
    "  Change number of tickets.";

char const gText_HorseRace_TicketControls_LRButtons[] SECTION(".rodata.horse_race_ticket_ui") =
    "L/R Buttons:";

char const gText_HorseRace_TicketControls_ChangeQuantityByTen[] SECTION(".rodata.horse_race_ticket_ui") =
    "  Change number of tickets";

char const gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation[] SECTION(".rodata.horse_race_ticket_ui") =
    "  by ten.";

char const gText_HorseRace_TicketControls_MoveCursorToConfirm[] SECTION(".rodata.horse_race_ticket_ui") =
    "Move the cursor to OK.";

char const gText_HorseRace_TicketControls_Buy[] SECTION(".rodata.horse_race_ticket_ui") =
    "Buy with the A Button.";

char const gText_HorseRace_TicketControls_Cancel[] SECTION(".rodata.horse_race_ticket_ui") =
    "Cancel with the B Button.";
