#include "horse_race_medal_exchange.hh"

// Prize names are inline fields of the native catalog, not a pointer table.
HorseRacePrize const gHorseRacePrizeCatalog[HORSE_RACE_PRIZE_COUNT] = {
    /* HORSE_RACE_PRIZE_JEWEL_OF_TRUTH */ { "真実の玉", 1000 },
    /* HORSE_RACE_PRIZE_POWER_BERRY */    { "力の木の実", 900 },
    /* HORSE_RACE_PRIZE_FACIAL_PACK */    { "フェイスパック", 42 },
    /* HORSE_RACE_PRIZE_SKIN_LOTION */    { "化粧水", 35 },
    /* HORSE_RACE_PRIZE_SUNBLOCK */       { "日焼け止め", 30 },
    /* HORSE_RACE_PRIZE_NECKLACE */       { "ネックレス", 20 },
    /* HORSE_RACE_PRIZE_BROOCH */         { "ブローチ", 18 },
    /* HORSE_RACE_PRIZE_DIAMOND */        { "ダイヤモンド", 14 },
    /* HORSE_RACE_PRIZE_TRUFFLE */        { "まつたけ", 10 },
    /* HORSE_RACE_PRIZE_ADAMANTITE */     { "アダマンタイト", 4 },
    /* HORSE_RACE_PRIZE_DRESS */          { "ドレス", 250 },
    /* HORSE_RACE_PRIZE_PERFUME */        { "香水", 150 },
};
