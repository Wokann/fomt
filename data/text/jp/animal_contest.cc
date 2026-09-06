#include "animal_contest_text.hh"

#define ANIMAL_CONTEST_TEXT SECTION(".rodata.animal_contest")
#define ANIMAL_CONTEST_CONFIRMATION_TEXT SECTION(".rodata.animal_contest_confirmation")

char const gText_AnimalContest_ChickenConfirmation[] ANIMAL_CONTEST_TEXT =
    "その鶏でいいんだね？";

char const gText_AnimalContest_Yes[] ANIMAL_CONTEST_TEXT =
    "はい";

char const gText_AnimalContest_No[] ANIMAL_CONTEST_TEXT =
    "いいえ";

char const gText_AnimalContest_CowConfirmation[] ANIMAL_CONTEST_TEXT =
    "その牛でいいんじゃな？";

char const gText_AnimalContest_SheepConfirmation[] ANIMAL_CONTEST_TEXT =
    "その羊でいいんじゃな？";

char const gText_AnimalContest_BabyChickIneligible[] ANIMAL_CONTEST_TEXT =
    "ヒヨコは参加できないよ。\r\n"
    "他の鶏を選んでくれる？{Press}";

char const gText_AnimalContest_AdultCowIneligible[] ANIMAL_CONTEST_TEXT =
    "大人の牛しか出られんよ。\r\n"
    "もう一回選んどくれ。{Press}";

char const gText_AnimalContest_AdultSheepIneligible[] ANIMAL_CONTEST_TEXT =
    "大人の羊しか出られんよ。\r\n"
    "もう一回選んどくれ。{Press}";

char const gText_AnimalContest_SickChickenIneligible[] ANIMAL_CONTEST_TEXT =
    "病気の鶏は参加できないよ。\r\n"
    "他の鶏を選んでくれる？{Press}";

char const gText_AnimalContest_SickCowIneligible[] ANIMAL_CONTEST_TEXT =
    "病気の牛は出られんよ。\r\n"
    "他の牛を選んどくれ。{Press}";

char const gText_AnimalContest_SickSheepIneligible[] ANIMAL_CONTEST_TEXT =
    "病気の羊は出られんよ。\r\n"
    "他の羊を選んどくれ。{Press}";

char const gText_AnimalContest_PregnantCowIneligible[] ANIMAL_CONTEST_TEXT =
    "妊娠中の牛は出られんよ。\r\n"
    "他の牛を選んどくれ。{Press}";

char const gText_AnimalContest_PregnantSheepIneligible[] ANIMAL_CONTEST_TEXT =
    "妊娠中の羊は出られんよ。\r\n"
    "他の羊を選んどくれ。{Press}";

char const gText_AnimalContest_ShornSheepIneligible[] ANIMAL_CONTEST_TEXT =
    "毛を刈った羊は出られんよ。\r\n"
    "他の羊を選んどくれ。{Press}";

char const gText_AnimalContest_ChickenEntryAccepted[] ANIMAL_CONTEST_TEXT =
    "わかった。じゃあ、その鶏を\r\n"
    "連れていくよ。{Press}";

char const gText_AnimalContest_ChickenSelectionPrompt[] ANIMAL_CONTEST_TEXT =
    "じゃあエントリーする鶏を\r\n"
    "選んでね。{Press}";

char const gText_AnimalContest_CowEntryAccepted[] ANIMAL_CONTEST_TEXT =
    "わかった。じゃあ、その牛を\r\n"
    "連れていくよ。{Press}";

char const gText_AnimalContest_CowSelectionPrompt[] ANIMAL_CONTEST_TEXT =
    "だったら参加する牛を\r\n"
    "選んでくれるかの？{Press}";

char const gText_AnimalContest_SheepEntryAccepted[] ANIMAL_CONTEST_TEXT =
    "わかった。じゃあ、その羊を\r\n"
    "連れていくよ。{Press}";

char const gText_AnimalContest_SheepSelectionPrompt[] ANIMAL_CONTEST_TEXT =
    "だったら参加する羊を\r\n"
    "選んでくれるかの？{Press}";

char const gText_AnimalContest_ChickenEntryDeclinedQuestion[] ANIMAL_CONTEST_TEXT =
    "エントリーしないのかい？";

char const gText_AnimalContest_LivestockEntryDeclinedQuestion[] ANIMAL_CONTEST_TEXT =
    "参加しないのかの？";

char const gText_AnimalContest_ChickenEntryDeclinedResponse[] ANIMAL_CONTEST_TEXT =
    "わかった。今回は\r\n"
    "エントリーしないんだね。{Press}";

char const gText_AnimalContest_LivestockEntryDeclinedResponse[] ANIMAL_CONTEST_TEXT =
    "わかった。今回は\r\n"
    "参加しないんじゃな。{Press}";

char const gText_AnimalContest_FinalConfirmation[] ANIMAL_CONTEST_CONFIRMATION_TEXT =
    "これでいい？";

char const gText_AnimalContest_FinalYes[] ANIMAL_CONTEST_CONFIRMATION_TEXT =
    "はい";

char const gText_AnimalContest_FinalNo[] ANIMAL_CONTEST_CONFIRMATION_TEXT =
    "いいえ";

extern AnimalContestStatusPrefixText const gAnimalContestStatusPrefixText
    ANIMAL_CONTEST_STATUS_PREFIX_TEXT = {
        "なし",
        "O１２３４５６７８９\x82",
    };

extern AnimalContestStatusText const gAnimalContestStatusText
    ANIMAL_CONTEST_STATUS_TEXT = {
        "健康",
        "不機嫌",
        "病気",
        "春",
        "夏",
        "秋",
        "冬",
        "才",
        "日",
    };

#undef ANIMAL_CONTEST_CONFIRMATION_TEXT
#undef ANIMAL_CONTEST_TEXT
