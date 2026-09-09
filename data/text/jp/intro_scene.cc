#include "intro_scene_text.hh"

// The physical order is the original childhood-visit sequence.  Its callers
// load these named strings directly from code literal pools.

char const gText_IntroScene_MotherName[] =
    "母";

char const gText_IntroScene_MotherTravelGreeting[] ALIGN(4) =
    "\p"
    "どう、\xFFちゃん。\r\n"
    "旅行に来てよかったでしょう？\r\n"
    "自然もいっぱいあるし。{Press}";

char const gText_IntroScene_FatherName[] ALIGN(4) =
    "父";

char const gText_IntroScene_FatherFishingInvitation[] ALIGN(4) =
    "\p"
    "父さんも思いきって休みをとっ\r\n"
    "てよかったよ。{Press}\r\n"
    "\xFF、\r\n"
    "川で魚釣りをやろうな。{Press}";

char const gText_IntroScene_MotherCannotFindPlayer[] ALIGN(4) =
    "\p"
    "\xFFちゃん？{Press}"
    "\p"
    "あ…あなたっ！！\r\n"
    "\xFFちゃんがいないわ\r\n"
    "よ？{Press}";

char const gText_IntroScene_PlayerResponseWhat[] ALIGN(4) =
    "\p"
    "な…なに？{Press}";

char const gText_IntroScene_OldManName[] ALIGN(4) =
    "おじいさん";

char const gText_IntroScene_OldManFindsPlayer[] ALIGN(4) =
    "\p"
    "おや、そこで泣いているのは誰\r\n"
    "だい？{Press}"
    "\p"
    "なんと、迷子になってしまった\r\n"
    "のか。\r\n"
    "かわいそうに…{Press}"
    "\p"
    "おお、連絡先のフダを下げとる\r\n"
    "な。{Press}\r\n"
    "どれ、わしが連絡してきて\r\n"
    "やろう。{Press}";

char const gText_IntroScene_MotherThanksOldMan[] ALIGN(4) =
    "\p"
    "どうも、お手数をおかけしまし\r\n"
    "て、申し訳ありません。{Press}";

char const gText_IntroScene_FatherExplainsVacation[] ALIGN(4) =
    "\p"
    "わたしたちは都会暮らしでして\r\n"
    "息子に自然を見せてやりたいと\r\n"
    "思い、今回の旅行を計画したん{Press}\r\n"
    "ですよ。{Press}";

char const gText_IntroScene_OldManOffersStay[] ALIGN(4) =
    "\p"
    "ほほう、なるほど。{Press}"
    "\p"
    "そうだ、よかったら、この牧場\r\n"
    "で何日か過ごされてはどうです\r\n"
    "か？{Press}";

char const gText_IntroScene_FatherAsksAboutStay[] ALIGN(4) =
    "\p"
    "ご迷惑ではないですか？{Press}";

char const gText_IntroScene_OldManWelcomesFamily[] ALIGN(4) =
    "\p"
    "わしには身内は一人もおりませ\r\n"
    "んし、気兼ねする必要はないで\r\n"
    "すよ。{Press}";

char const gText_IntroScene_MotherTellsPlayerToPlay[] ALIGN(4) =
    "\p"
    "よかったわね。\r\n"
    "\xFFちゃん、\r\n"
    "思いっきり遊んでらっしゃい。{Press}";

char const gText_IntroScene_UnknownName[] ALIGN(4) =
    "？？？";

char const gText_IntroScene_UnknownCallsPlayer[] ALIGN(4) =
    "\p"
    "い…{Press}"
    "\p"
    "～い…{Press}"
    "\p"
    "お～い。{Press}";

char const gText_IntroScene_UnknownFindsPlayer[] ALIGN(4) =
    "\p"
    "！{Press}";

char const gText_IntroScene_GirlName[] ALIGN(4) =
    "女の子";

char const gText_IntroScene_GirlThinksPlayerDead[] ALIGN(4) =
    "\p"
    "あんまりしずかだから、\r\n"
    "死んでるかと思ったわ。{Press}";

char const gText_IntroScene_GirlInvitesPlayerToPlay[] ALIGN(4) =
    "\p"
    "へぇ～、ちょうどいいわ。\r\n"
    "わたし、ヒマなの。\r\n"
    "遊んであげるわ。{Press}\r\n"
    "感謝しなさいよ。{Press}";

char const gText_IntroScene_GirlAsksPlayerStory[] ALIGN(4) =
    "\p"
    "ダマってたら、\r\n"
    "おもしろくないじゃない。{Press}"
    "\p"
    "そうねぇ、あんたの身の上話で\r\n"
    "も聞いてあげるわ。\r\n"
    "ほら、さっさと話しなさいよ。{Press}";

char const gText_IntroScene_OldManFarewell[] ALIGN(4) =
    "\p"
    "楽しかったかい？{Press}"
    "\p"
    "そうか、そうか。\r\n"
    "わしもマゴが出来たみたいで楽\r\n"
    "しかったわい。{Press}"
    "\p"
    "ご両親がもう帰ると言っておる\r\n"
    "ぞ。\r\n"
    "そろそろ、お別れじゃな。{Press}";

char const gText_IntroScene_OldManRequestsLetter[] ALIGN(4) =
    "\p"
    "おお、そうだ。\r\n"
    "ボウズさえよければ文通でもせ\r\n"
    "んか？{Press}";

char const gText_IntroScene_OldManGivesAddress[] ALIGN(4) =
    "\p"
    "そうか、やってくれるか。\r\n"
    "じゃ、わしの住所を教えておこ\r\n"
    "う。{Press}";

char const gText_IntroScene_GirlSaysGoodbye[] ALIGN(4) =
    "\p"
    "あれっ、もう行っちゃうの？{Press}";

char const gText_IntroScene_GirlAsksPlayerToReturn[] ALIGN(4) =
    "\p"
    "あんたが帰ったら、\r\n"
    "ヒマになっちゃうじゃないの。{Press}"
    "\p"
    "また、こっちに来たら遊んであ\r\n"
    "げるわ。{Press}";

char const gText_IntroScene_OldManNotesFriend[] ALIGN(4) =
    "\p"
    "友達ができたみたいじゃのう。\r\n"
    "また来るときの楽しみも増えた\r\n"
    "の。{Press}";

char const gText_IntroScene_OldManWaitsForLetter[] ALIGN(4) =
    "\p"
    "手紙待っとるからな………{Press}";
