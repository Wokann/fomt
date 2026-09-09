#include "horse_race_text.hh"

#if defined(FOMT_TEXT_HORSE_RACE_TICKET_CONTROLS)

// Static Horse Race text.  The text processor converts these UTF-8 strings
// and named controls into the exact regional ROM bytes during the build.

char const gText_HorseRace_BuyTicketDeclined[] =
    "買わないのかい？";

char const gText_HorseRace_Yes[] =
    "はい";

char const gText_HorseRace_No[] =
    "いいえ";

char const gText_HorseRace_ComeAgain[] =
    "\p"
    "またおいで。{Press}";

char const gText_HorseRace_TakeYourTime[] =
    "\p"
    "ゆっくり選ぶといいよ。{Press}";

char const gText_HorseRace_TicketPurchaseConfirmation[] =
    "これでいいかい？";

char const gText_HorseRace_TicketPurchaseApproval[] =
    "\p"
    "はい、どうぞ。\r\n"
    "幸運を祈っているよ。{Press}";

char const gText_HorseRace_TicketPurchaseEncouragement[] =
    "\p"
    "はい、どうぞ。\r\n"
    "頑張るんだよ。{Press}";

char const gText_HorseRace_ChangeMind[] =
    "\p"
    "やめるのかい？{Press}";

char const gText_HorseRace_ExplanationQuestion[] =
    "草競馬の説明を聞くかい？";

char const gText_HorseRace_ExplanationBasics[] =
    "\p"
    "それじゃあ、今からレースの\r\n"
    "説明を始めるよ。{Press}\r\n"
    "馬の走るスピードを上げたい\r\n"
    "時は、Ａボタンをおしてね。{Press}\r\n"
    "ただし、馬のスピードが上がる\r\n"
    "と、その分馬のスタミナも\r\n"
    "なくなってしまうよ。{Press}";

char const gText_HorseRace_ExplanationGreenStamina[] =
    "\p"
    "馬のふきだしが緑のときは\r\n"
    "スタミナが十分ある状態だよ。{Press}";

char const gText_HorseRace_ExplanationYellowStamina[] =
    "\p"
    "加速してスタミナがなくなると\r\n"
    "ふきだしが黄色に変わるよ。{Press}";

char const gText_HorseRace_ExplanationRedStamina[] =
    "\p"
    "さらに加速していくと\r\n"
    "ふきだしが赤になるよ。{Press}\r\n"
    "赤のときはＡボタンを押しても\r\n"
    "加速しないから気をつけてね。{Press}";

char const gText_HorseRace_ExplanationStaminaRecovery[] =
    "\p"
    "Ａボタンをおしていない間は、\r\n"
    "馬のスタミナが戻っていくよ。{Press}\r\n"
    "自分の馬のふきだしを見ながら\r\n"
    "上手にボタンを押しましょう。{Press}";

char const gText_HorseRace_ExplanationUnderstoodQuestion[] =
    "分かったかい？";

char const gText_HorseRace_ExplanationUnderstood[] =
    "分かった";

char const gText_HorseRace_ExplanationRepeat[] =
    "もう１度説明を聞く";

char const gText_HorseRace_StartRace[] =
    "\p"
    "じゃあ、始めよう。{Press}";

char const gText_HorseRace_RaceStartAnnouncement[] =
    "\p"
    "１番\xFC\r\n"
    "２番\xFD{Press}\r\n"
    "３番\xFE\r\n"
    "４番\xFF{Press}\r\n"
    "まもなく出走いたします。{Press}\p"
    "よーい………{Press}";

char const gText_HorseRace_RaceResults[] =
    "\p"
    "ただいまのレース\r\n"
    "１着\xFC\r\n"
    "２着\xFD{Press}\r\n"
    "３着\xFE\r\n"
    "４着\xFF{Press}\r\n"
    "以上のように確定しました。{Press}";

char const gText_HorseRace_RacePayouts[] =
    "\p"
    "第\xFAレースの配当は\r\n"
    "このようになっております。{Press}";

char const gText_HorseRace_MedalExchangeExplanation[] =
    "\p"
    "メダルを景品に替えたい時は、\r\n"
    "受付にいる私に言って下さい。{Press}\r\n"
    "メダルは草競馬でしか景品に\r\n"
    "替えることが出来ないから、\r\n"
    "忘れないようにね。{Press}";

u16 const gHorseRaceTicketCharacterCodes[] =
    FOMT_GLYPH_TEXT("０１２３４５６７８９枚倍Ｇ現在のメダル数");

char const gText_HorseRace_TicketPurchaseTitle[] =
    "第　レース　勝ち馬投票券";

char const gText_HorseRace_TicketPurchaseConfirm[] =
    "　　決定";

char const gText_HorseRace_TicketPurchaseMedalsToWin[] =
    "　もらえるメダル数　";

char const gText_HorseRace_TicketControls_DPadUpDown[] =
    " 十字ボタン上下";

char const gText_HorseRace_TicketControls_SelectHorse[] =
    " 　…チケットを買う馬を選ぶ";

char const gText_HorseRace_TicketControls_DPadLeftRight[] =
    " 十字ボタン左右";

char const gText_HorseRace_TicketControls_ChangeQuantity[] =
    " 　…チケットの数を変える";

char const gText_HorseRace_TicketControls_LRButtons[] =
    " Ｌボタン·Ｒボタン";

char const gText_HorseRace_TicketControls_ChangeQuantityByTen[] =
    " 　…チケット１０枚ずつ変える";

// JP keeps the whole “by ten” instruction in the preceding UI field.
char const gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation[] =
    " ";

char const gText_HorseRace_TicketControls_MoveCursorToConfirm[] =
    " カーソルを決定にあわせて";

char const gText_HorseRace_TicketControls_Buy[] =
    " Ａボタンで購入。買わない時は";

char const gText_HorseRace_TicketControls_Cancel[] =
    " Ｂボタンでキャンセル。";

#elif defined(FOMT_TEXT_HORSE_RACE_PRIZE_CATALOG)

HorseRacePrize const gHorseRacePrizeCatalog[] = {
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

#elif defined(FOMT_TEXT_HORSE_RACE_PRIZE_EXCHANGE)

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

#else
#error "Select one horse_race text fragment before including this file."
#endif
