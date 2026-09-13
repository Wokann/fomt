#include "horse_race_data.hh"

// Static Horse Race text.  The text processor converts these UTF-8 strings
// and named controls into the exact regional ROM bytes during the build.

char const gText_HorseRace_BuyTicketDeclined[] =
    "Sicher keine haben?";

char const gText_HorseRace_Yes[] =
    "Ja";

char const gText_HorseRace_No[] =
    "Nein";

char const gText_HorseRace_ComeAgain[] =
    "\p"
    "Komm wieder.{Press}";

char const gText_HorseRace_TakeYourTime[] =
    "\p"
    "Nimm dir Zeit.{Press}";

char const gText_HorseRace_TicketPurchaseConfirmation[] =
    "Das willst du also?";

char const gText_HorseRace_TicketPurchaseApproval[] =
    "\p"
    "Bitte sehr.\r\n"
    "Viel Glück!{Press}";

char const gText_HorseRace_ChangeMind[] =
    "\p"
    "Deine Meinung geändert?{Press}";

char const gText_HorseRace_ExplanationQuestion[] =
    "Lernen, wie es geht?";

char const gText_HorseRace_ExplanationBasics[] =
    "\p"
    "OK, hör gut zu.{Press}\r\n"
    "Benutze Knopf A, um dein\r\n"
    "Pferd anzuspornen.{Press}\r\n"
    "Denke aber daran, dass\r\n"
    "dein Pferd nur über\r\n"
    "bestimmte Ausdauer verfügt.{Press}";

char const gText_HorseRace_ExplanationGreenStamina[] =
    "\p"
    "Wenn dein Pferd noch im\r\n"
    "grünen Bereich ist, hat es\r\n"
    "noch genügend Ausdauer.{Press}";

char const gText_HorseRace_ExplanationYellowStamina[] =
    "\p"
    "Wenn du es noch schneller\r\n"
    "rennen lässt, springt die\r\n"
    "Anzeige auf gelb.{Press}";

char const gText_HorseRace_ExplanationRedStamina[] =
    "\p"
    "Werde noch schneller\r\n"
    "und du kommst in\r\n"
    "den roten Bereich.{Press}\r\n"
    "Bist du einmal im roten\r\n"
    "Bereich, kannst du nicht\r\n"
    "mehr schneller werden.{Press}";

char const gText_HorseRace_ExplanationStaminaRecovery[] =
    "\p"
    "Halt dich zurück mit\r\n"
    "Knopf A, damit dein Pferd\r\n"
    "wieder an Ausdauer gewinnt.{Press}\r\n"
    "Führe dein Pferd\r\n"
    "vernünftig, und du\r\n"
    "kannst gewinnen!{Press}";

char const gText_HorseRace_ExplanationUnderstoodQuestion[] =
    "Alles verstanden?";

char const gText_HorseRace_ExplanationUnderstood[] =
    "Verstanden.";

char const gText_HorseRace_ExplanationRepeat[] =
    "Noch einmal bitte.";

char const gText_HorseRace_StartRace[] =
    "\p"
    "Dann lass uns anfangen!{Press}";

char const gText_HorseRace_RaceStartAnnouncement[] =
    "\p"
    "Nr.1 \xFC\x0D\n"
    "Nr.2 \xFD{Press}\r\n"
    "Nr.3 \xFE\r\n"
    "Nr.4 \xFF\x05\r\n"
    "Auf die Plätze...{Press}\p"
    "Fertig.... {Press}";

char const gText_HorseRace_RaceResults[] =
    "\p"
    "Rennergebnisse:\r\n"
    "1. Platz \xFC\x0D\n"
    "2. Platz \xFD{Press}\r\n"
    "3. Platz \xFE\r\n"
    "4. Platz \xFF\x05\r\n"
    "{Press}";

char const gText_HorseRace_RacePayouts[] =
    "\p"
    "Auszahlungen\r\n"
    "wie folgt:{Press}";

char const gText_HorseRace_MedalExchangeExplanation[] =
    "\p"
    "Komm zu mir, wenn du\r\n"
    "deine Medaille gegen einen\r\n"
    "Gewinn eintauschen willst.{Press}\r\n"
    "Denke daran, du kannst\r\n"
    "das nur hier tun.{Press}";

u16 const gHorseRaceTicketCharacterCodes[] =
    FOMT_GLYPH_SEQUENCE("0123456789 xGD. Medillen");

char const gText_HorseRace_TicketPurchaseTitle[] =
    "Renngewinnticket        ";

char const gText_HorseRace_TicketPurchaseConfirm[] =
    "    Mitmach.";

char const gText_HorseRace_TicketPurchaseMedalsToWin[] =
    "  Siegermedaillen   ";

char const gText_HorseRace_TicketControls_DPadUpDown[] =
    "Steuerkreuz nach Oben/Unten:";

char const gText_HorseRace_TicketControls_SelectHorse[] =
    "  Wähle Pferd zum Wetten.";

char const gText_HorseRace_TicketControls_DPadLeftRight[] =
    "Steuerkreuz nach ";

char const gText_HorseRace_TicketControls_ChangeQuantity[] =
    "Links/Rechts:";

char const gText_HorseRace_TicketControls_LRButtons[] =
    "  Ticketanzahl ändern";

char const gText_HorseRace_TicketControls_ChangeQuantityByTen[] =
    "Knöpfe L/R:";

char const gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation[] =
    "  Ticketanzahl um 10 ändern.";

char const gText_HorseRace_TicketControls_MoveCursorToConfirm[] =
    "Bewege den Cursor auf OK.";

char const gText_HorseRace_TicketControls_Buy[] =
    "Kaufe mit Knopf A.";

char const gText_HorseRace_TicketControls_Cancel[] =
    "Brich ab mit Knopf B.";
