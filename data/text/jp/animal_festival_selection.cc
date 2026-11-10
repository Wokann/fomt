#include "animal_festival_selection.hh"

char const gText_AnimalStatusScreen_Unavailable[] =
    "なし";

// The renderer reads ten halfword glyph codes, without a string terminator.
u16 const gAnimalStatusScreenDigitGlyphs[] ALIGN(2) = {
    "０１２３４５６７８９",
};

char const gText_AnimalStatusScreen_Healthy[] =
    "健康";

char const gText_AnimalStatusScreen_Unhappy[] =
    "不機嫌";

char const gText_AnimalStatusScreen_Sick[] =
    "病気";

char const gText_AnimalStatusScreen_Spring[] =
    "春";

char const gText_AnimalStatusScreen_Summer[] =
    "夏";

char const gText_AnimalStatusScreen_Autumn[] =
    "秋";

char const gText_AnimalStatusScreen_Winter[] =
    "冬";

char const gText_AnimalStatusScreen_Age[] =
    "才";

char const gText_AnimalStatusScreen_Day[] =
    "日";

char const gText_AnimalContest_ChickenConfirmation[] =
    "その鶏でいいんだね？";

char const gText_AnimalContest_Yes[] =
    "はい";

char const gText_AnimalContest_No[] =
    "いいえ";

char const gText_AnimalContest_CowConfirmation[] =
    "その牛でいいんじゃな？";

char const gText_AnimalContest_SheepConfirmation[] =
    "その羊でいいんじゃな？";

char const gText_AnimalContest_BabyChickIneligible[] =
    "ヒヨコは参加できないよ。\r\n"
    "他の鶏を選んでくれる？{Press}";

char const gText_AnimalContest_AdultCowIneligible[] =
    "大人の牛しか出られんよ。\r\n"
    "もう一回選んどくれ。{Press}";

char const gText_AnimalContest_AdultSheepIneligible[] =
    "大人の羊しか出られんよ。\r\n"
    "もう一回選んどくれ。{Press}";

char const gText_AnimalContest_SickChickenIneligible[] =
    "病気の鶏は参加できないよ。\r\n"
    "他の鶏を選んでくれる？{Press}";

char const gText_AnimalContest_SickCowIneligible[] =
    "病気の牛は出られんよ。\r\n"
    "他の牛を選んどくれ。{Press}";

char const gText_AnimalContest_SickSheepIneligible[] =
    "病気の羊は出られんよ。\r\n"
    "他の羊を選んどくれ。{Press}";

char const gText_AnimalContest_PregnantCowIneligible[] =
    "妊娠中の牛は出られんよ。\r\n"
    "他の牛を選んどくれ。{Press}";

char const gText_AnimalContest_PregnantSheepIneligible[] =
    "妊娠中の羊は出られんよ。\r\n"
    "他の羊を選んどくれ。{Press}";

char const gText_AnimalContest_ShornSheepIneligible[] =
    "毛を刈った羊は出られんよ。\r\n"
    "他の羊を選んどくれ。{Press}";

char const gText_AnimalContest_ChickenEntryAccepted[] =
    "わかった。じゃあ、その鶏を\r\n"
    "連れていくよ。{Press}";

char const gText_AnimalContest_ChickenSelectionPrompt[] =
    "じゃあエントリーする鶏を\r\n"
    "選んでね。{Press}";

char const gText_AnimalContest_CowEntryAccepted[] =
    "わかった。じゃあ、その牛を\r\n"
    "連れていくよ。{Press}";

char const gText_AnimalContest_CowSelectionPrompt[] =
    "だったら参加する牛を\r\n"
    "選んでくれるかの？{Press}";

char const gText_AnimalContest_SheepEntryAccepted[] =
    "わかった。じゃあ、その羊を\r\n"
    "連れていくよ。{Press}";

char const gText_AnimalContest_SheepSelectionPrompt[] =
    "だったら参加する羊を\r\n"
    "選んでくれるかの？{Press}";

char const gText_AnimalContest_ChickenEntryDeclinedQuestion[] =
    "エントリーしないのかい？";

char const gText_AnimalContest_LivestockEntryDeclinedQuestion[] =
    "参加しないのかの？";

char const gText_AnimalContest_ChickenEntryDeclinedResponse[] =
    "わかった。今回は\r\n"
    "エントリーしないんだね。{Press}";

char const gText_AnimalContest_LivestockEntryDeclinedResponse[] =
    "わかった。今回は\r\n"
    "参加しないんじゃな。{Press}";
