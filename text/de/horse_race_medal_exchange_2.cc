#include "config.h"
#include "horse_race_medal_exchange.hh"

char const gText_HorseRace_PrizeExchangePrompt[] =
#ifdef BUGFIX
    "Nicht gegen Preis tauschen?";
#else
    "Gegen Preis tauschen?";
#endif

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

u16 const gHorseRacePrizeExchangeCharacterCodes[] = {
    "0123456789 xGD. Medillen",
};
