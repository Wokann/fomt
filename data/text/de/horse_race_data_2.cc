#include "horse_race_data.hh"

char const gText_HorseRace_PrizeExchangePrompt[] =
    "Gegen Preis tauschen?";

char const gText_HorseRace_PrizeExchangeYes[] =
    "Ja";

char const gText_HorseRace_PrizeExchangeNo[] =
    "Nein";

char const gText_HorseRace_PrizeExchangeComeAgain[] =
    "\p"
    "Komm jederzeit wieder.{Press}";

char const gText_HorseRace_PrizeExchangeTakeYourTime[] =
    "\p"
    "Nimm dir jetzt Zeit.{Press}";

char const gText_HorseRace_PrizeSelectionConfirmation[] =
    "Möchtest du \xFF\x3F";

char const gText_HorseRace_PrizeExchangeLeaveConfirmation[] =
    "\p"
    "Du möchtest also gehen?{Press}";

char const gText_HorseRace_PrizeExchangeInsufficientMedals[] =
    "\p"
    "Hierfür hast du nicht \r\n"
    "genug Medaillen. {Press}";

// The German prize-exchange renderer reads this fixed glyph field without a
// terminator in the original table.
u16 const gHorseRacePrizeExchangeCharacterCodes[] =
    FOMT_GLYPH_SEQUENCE("0123456789 xGD. Medillen");
