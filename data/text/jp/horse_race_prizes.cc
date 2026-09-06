#include "horse_race_text.hh"

HorseRacePrize const gHorseRacePrizeCatalog[] SECTION(".rodata.horse_race_prize_catalog") = {
    { "真実の玉", 1000 },
    { "力の木の実", 900 },
    { "フェイスパック", 42 },
    { "化粧水", 35 },
    { "日焼け止め", 30 },
    { "ネックレス", 20 },
    { "ブローチ", 18 },
    { "ダイヤモンド", 14 },
    { "まつたけ", 10 },
    { "アダマンタイト", 4 },
    { "ドレス", 250 },
    { "香水", 150 },
};

char const gText_HorseRace_PrizeExchangePrompt[] SECTION(".rodata.horse_race_prize_exchange") =
    "景品に替えないのかい？";

char const gText_HorseRace_PrizeExchangeYes[] SECTION(".rodata.horse_race_prize_exchange") =
    "はい";

char const gText_HorseRace_PrizeExchangeNo[] SECTION(".rodata.horse_race_prize_exchange") =
    "いいえ";

char const gText_HorseRace_PrizeExchangeComeAgain[] SECTION(".rodata.horse_race_prize_exchange") =
    "\p"
    "またおいで。{Press}";

char const gText_HorseRace_PrizeExchangeTakeYourTime[] SECTION(".rodata.horse_race_prize_exchange") =
    "\p"
    "ゆっくり選ぶといいよ。{Press}";

char const gText_HorseRace_PrizeSelectionConfirmation[] SECTION(".rodata.horse_race_prize_exchange") =
    "\xFF"
    "でいいかい？";

char const gText_HorseRace_PrizeExchangeLeaveConfirmation[] SECTION(".rodata.horse_race_prize_exchange") =
    "\p"
    "やめるのかい？{Press}";

char const gText_HorseRace_PrizeExchangeInsufficientMedals[] SECTION(".rodata.horse_race_prize_exchange") =
    "\p"
    "これだとメダルが足りないね。{Press}";
