#include "horse_race_medal_exchange.hh"

char const gText_HorseRace_PrizeExchangePrompt[] =
    "景品に替えないのかい？";

char const gText_HorseRace_PrizeExchangeYes[] =
    "はい";

char const gText_HorseRace_PrizeExchangeNo[] =
    "いいえ";

char const gText_HorseRace_PrizeExchangeComeAgain[] =
    "\p"
    "またおいで。{Press}";

char const gText_HorseRace_PrizeExchangeTakeYourTime[] =
    "\p"
    "ゆっくり選ぶといいよ。{Press}";

char const gText_HorseRace_PrizeSelectionConfirmation[] =
    "\xFF"
    "でいいかい？";

char const gText_HorseRace_PrizeExchangeLeaveConfirmation[] =
    "\p"
    "やめるのかい？{Press}";

char const gText_HorseRace_PrizeExchangeInsufficientMedals[] =
    "\p"
    "これだとメダルが足りないね。{Press}";

// The native renderer reads this preloaded glyph-code sequence directly.
u16 const gHorseRacePrizeExchangeCharacterCodes[] = {
    "０１２３４５６７８９枚倍Ｇ現在のメダル数",
};
