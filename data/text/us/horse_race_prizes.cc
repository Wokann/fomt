#include "horse_race_text.hh"

HorseRacePrize const gHorseRacePrizeCatalog[] SECTION(".rodata.horse_race_prize_catalog") = {
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

char const gText_HorseRace_PrizeExchangePrompt[] SECTION(".rodata.horse_race_prize_exchange") =
    "Exchange for a prize?";

char const gText_HorseRace_PrizeExchangeYes[] SECTION(".rodata.horse_race_prize_exchange") =
    "Yes";

char const gText_HorseRace_PrizeExchangeNo[] SECTION(".rodata.horse_race_prize_exchange") =
    "No";

char const gText_HorseRace_PrizeExchangeComeAgain[] SECTION(".rodata.horse_race_prize_exchange") =
    "\p"
    "Come again any time.{Press}";

char const gText_HorseRace_PrizeExchangeTakeYourTime[] SECTION(".rodata.horse_race_prize_exchange") =
    "\p"
    "Take your time now.{Press}";

char const gText_HorseRace_PrizeSelectionConfirmation[] SECTION(".rodata.horse_race_prize_exchange") =
    "So want \xFF?";

char const gText_HorseRace_PrizeExchangeLeaveConfirmation[] SECTION(".rodata.horse_race_prize_exchange") =
    "\p"
    "So you want to leave?{Press}";

char const gText_HorseRace_PrizeExchangeInsufficientMedals[] SECTION(".rodata.horse_race_prize_exchange") =
    "\p"
    "You don't have enough\r\n"
    "medals for this.{Press}";
