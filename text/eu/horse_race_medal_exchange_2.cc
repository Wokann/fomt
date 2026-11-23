#include "config.h"
#include "horse_race_medal_exchange.hh"

char const gText_HorseRace_PrizeExchangePrompt[] =
#ifdef BUGFIX
    "Not exchange for a prize?";
#else
    "Exchange for a prize?";
#endif

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

u16 const gHorseRacePrizeExchangeCharacterCodes[] = {
    "0123456789 xGYour medals",
};
