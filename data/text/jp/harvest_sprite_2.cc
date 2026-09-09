#include "harvest_sprite.hh"

char const gCppRuntimeBadAlloc_HarvestSpriteMiniGameAnimalHusbandry[] =
    "bad_alloc";

char const gText_HarvestSpriteMiniGameAnimalHusbandryEmpty[] ALIGN(1) =
    "\0\0";

// Direct-indexed chicken-festival contestant names. The fixed 13-byte rows
// retain the original JP display-space padding.
char const gText_ChickenFestival_ContestantNames[CHICKEN_FESTIVAL_CONTESTANT_NAME_COUNT][CHICKEN_FESTIVAL_CONTESTANT_NAME_WIDTH] ALIGN(1) = {
    "ここりターン",
    "こじろー",
    "だーく",
    "バクバク",
    "ピヨリン",
    "ピヨたろう",
    "ヨチスケ",
    "へっぽこ",
    "カタきち",
    "とさのすけ",
    "ぴよまろ",
    "しんえもん",
    "キング",
    "テン",
    "フランソワ",
    "ピッピヨ",
    "コテツ",
    "ライライ",
    "コッケ",
    "スイート"
};


char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsAnnouncement[] =
    "\p"
    "準決勝を始めるよ。{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalRoundAnnouncement[] =
    "\p"
    "さぁ、いよいよ第３試合だよ。\r\n"
    "これで優勝者が決まるから、\r\n"
    "どちらもがんばってね。{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationQuestion[] =
    "試合の説明はしなくていいか？";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationNo[] =
    "しなくていい";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationYes[] =
    "もう１度聞く";

char const gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStart[] =
    "\p"
    "一回戦、よーい………、{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStart[] =
    "\p"
    "準決勝、よーい………、{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStart[] =
    "\p"
    "決勝、よーい………、{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_Start[] =
    "\p"
    "はじめっ！{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_Stop[] =
    "\p"
    "それまでっ！{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_WinnerSuffix[] =
    "の勝ちです！{Press}";
