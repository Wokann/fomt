#include "horse_race_data.hh"

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

// The JP prize-exchange renderer reads a fixed twenty-glyph field with no
// terminator in the original table.
u16 const gHorseRacePrizeExchangeCharacterCodes[] =
    FOMT_GLYPH_SEQUENCE("０１２３４５６７８９枚倍Ｇ現在のメダル数");
