#include "horse_race_text.hh"

// Static Horse Race text.  The text processor converts these UTF-8 strings
// and named controls into the exact regional ROM bytes during the build.

char const gText_HorseRace_BuyTicketDeclined[] SECTION(".rodata.horse_race_dialogue") =
    "買わないのかい？";

char const gText_HorseRace_Yes[] SECTION(".rodata.horse_race_dialogue") =
    "はい";

char const gText_HorseRace_No[] SECTION(".rodata.horse_race_dialogue") =
    "いいえ";

char const gText_HorseRace_ComeAgain[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "またおいで。{Press}";

char const gText_HorseRace_TakeYourTime[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "ゆっくり選ぶといいよ。{Press}";

char const gText_HorseRace_TicketPurchaseConfirmation[] SECTION(".rodata.horse_race_dialogue") =
    "これでいいかい？";

char const gText_HorseRace_TicketPurchaseApproval[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "はい、どうぞ。\r\n"
    "幸運を祈っているよ。{Press}";

char const gText_HorseRace_TicketPurchaseEncouragement[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "はい、どうぞ。\r\n"
    "頑張るんだよ。{Press}";

char const gText_HorseRace_ChangeMind[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "やめるのかい？{Press}";

char const gText_HorseRace_ExplanationQuestion[] SECTION(".rodata.horse_race_dialogue") =
    "草競馬の説明を聞くかい？";

char const gText_HorseRace_ExplanationBasics[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "それじゃあ、今からレースの\r\n"
    "説明を始めるよ。{Press}\r\n"
    "馬の走るスピードを上げたい\r\n"
    "時は、Ａボタンをおしてね。{Press}\r\n"
    "ただし、馬のスピードが上がる\r\n"
    "と、その分馬のスタミナも\r\n"
    "なくなってしまうよ。{Press}";

char const gText_HorseRace_ExplanationGreenStamina[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "馬のふきだしが緑のときは\r\n"
    "スタミナが十分ある状態だよ。{Press}";

char const gText_HorseRace_ExplanationYellowStamina[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "加速してスタミナがなくなると\r\n"
    "ふきだしが黄色に変わるよ。{Press}";

char const gText_HorseRace_ExplanationRedStamina[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "さらに加速していくと\r\n"
    "ふきだしが赤になるよ。{Press}\r\n"
    "赤のときはＡボタンを押しても\r\n"
    "加速しないから気をつけてね。{Press}";

char const gText_HorseRace_ExplanationStaminaRecovery[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "Ａボタンをおしていない間は、\r\n"
    "馬のスタミナが戻っていくよ。{Press}\r\n"
    "自分の馬のふきだしを見ながら\r\n"
    "上手にボタンを押しましょう。{Press}";

char const gText_HorseRace_ExplanationUnderstoodQuestion[] SECTION(".rodata.horse_race_dialogue") =
    "分かったかい？";

char const gText_HorseRace_ExplanationUnderstood[] SECTION(".rodata.horse_race_dialogue") =
    "分かった";

char const gText_HorseRace_ExplanationRepeat[] SECTION(".rodata.horse_race_dialogue") =
    "もう１度説明を聞く";

char const gText_HorseRace_StartRace[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "じゃあ、始めよう。{Press}";

char const gText_HorseRace_RaceStartAnnouncement[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "１番\xFC\r\n"
    "２番\xFD{Press}\r\n"
    "３番\xFE\r\n"
    "４番\xFF{Press}\r\n"
    "まもなく出走いたします。{Press}\p"
    "よーい………{Press}";

char const gText_HorseRace_RaceResults[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "ただいまのレース\r\n"
    "１着\xFC\r\n"
    "２着\xFD{Press}\r\n"
    "３着\xFE\r\n"
    "４着\xFF{Press}\r\n"
    "以上のように確定しました。{Press}";

char const gText_HorseRace_RacePayouts[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "第\xFAレースの配当は\r\n"
    "このようになっております。{Press}";

char const gText_HorseRace_MedalExchangeExplanation[] SECTION(".rodata.horse_race_dialogue") =
    "\p"
    "メダルを景品に替えたい時は、\r\n"
    "受付にいる私に言って下さい。{Press}\r\n"
    "メダルは草競馬でしか景品に\r\n"
    "替えることが出来ないから、\r\n"
    "忘れないようにね。{Press}";

char const gText_HorseRace_TicketPurchaseTitle[] SECTION(".rodata.horse_race_ticket_ui") =
    "第　レース　勝ち馬投票券";

char const gText_HorseRace_TicketPurchaseConfirm[] SECTION(".rodata.horse_race_ticket_ui") =
    "　　決定";

char const gText_HorseRace_TicketPurchaseMedalsToWin[] SECTION(".rodata.horse_race_ticket_ui") =
    "　もらえるメダル数　";

char const gText_HorseRace_TicketControls_DPadUpDown[] SECTION(".rodata.horse_race_ticket_ui") =
    " 十字ボタン上下";

char const gText_HorseRace_TicketControls_SelectHorse[] SECTION(".rodata.horse_race_ticket_ui") =
    " 　…チケットを買う馬を選ぶ";

char const gText_HorseRace_TicketControls_DPadLeftRight[] SECTION(".rodata.horse_race_ticket_ui") =
    " 十字ボタン左右";

char const gText_HorseRace_TicketControls_ChangeQuantity[] SECTION(".rodata.horse_race_ticket_ui") =
    " 　…チケットの数を変える";

char const gText_HorseRace_TicketControls_LRButtons[] SECTION(".rodata.horse_race_ticket_ui") =
    " Ｌボタン·Ｒボタン";

char const gText_HorseRace_TicketControls_ChangeQuantityByTen[] SECTION(".rodata.horse_race_ticket_ui") =
    " 　…チケット１０枚ずつ変える";

// JP keeps the whole “by ten” instruction in the preceding UI field.
char const gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation[] SECTION(".rodata.horse_race_ticket_ui") =
    " ";

char const gText_HorseRace_TicketControls_MoveCursorToConfirm[] SECTION(".rodata.horse_race_ticket_ui") =
    " カーソルを決定にあわせて";

char const gText_HorseRace_TicketControls_Buy[] SECTION(".rodata.horse_race_ticket_ui") =
    " Ａボタンで購入。買わない時は";

char const gText_HorseRace_TicketControls_Cancel[] SECTION(".rodata.horse_race_ticket_ui") =
    " Ｂボタンでキャンセル。";
