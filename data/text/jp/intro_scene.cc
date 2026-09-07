#include "intro_scene_text.hh"

// The physical order is the original childhood-visit sequence.  Its callers
// load these named strings directly from code literal pools.

char const gCppRuntimeBadAlloc_IntroScenePrefix[]
    SECTION(".rodata.intro_scene_prefix_runtime") =
        "bad_alloc";

char const gText_IntroScene_MotherName[] SECTION(".rodata.intro_scene_text") =
    "母";

char const gText_IntroScene_MotherTravelGreeting[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "どう、\xFFちゃん。\r\n"
    "旅行に来てよかったでしょう？\r\n"
    "自然もいっぱいあるし。{Press}";

char const gText_IntroScene_FatherName[] SECTION(".rodata.intro_scene_text") =
    "父";

char const gText_IntroScene_FatherFishingInvitation[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "父さんも思いきって休みをとっ\r\n"
    "てよかったよ。{Press}\r\n"
    "\xFF、\r\n"
    "川で魚釣りをやろうな。{Press}";

char const gText_IntroScene_MotherCannotFindPlayer[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "\xFFちゃん？{Press}"
    "\p"
    "あ…あなたっ！！\r\n"
    "\xFFちゃんがいないわ\r\n"
    "よ？{Press}";

char const gText_IntroScene_PlayerResponseWhat[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "な…なに？{Press}";

char const gText_IntroScene_OldManName[] SECTION(".rodata.intro_scene_text") =
    "おじいさん";

char const gText_IntroScene_OldManFindsPlayer[] SECTION(".rodata.intro_scene_text") =
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

char const gText_IntroScene_MotherThanksOldMan[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "どうも、お手数をおかけしまし\r\n"
    "て、申し訳ありません。{Press}";

char const gText_IntroScene_FatherExplainsVacation[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "わたしたちは都会暮らしでして\r\n"
    "息子に自然を見せてやりたいと\r\n"
    "思い、今回の旅行を計画したん{Press}\r\n"
    "ですよ。{Press}";

char const gText_IntroScene_OldManOffersStay[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "ほほう、なるほど。{Press}"
    "\p"
    "そうだ、よかったら、この牧場\r\n"
    "で何日か過ごされてはどうです\r\n"
    "か？{Press}";

char const gText_IntroScene_FatherAsksAboutStay[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "ご迷惑ではないですか？{Press}";

char const gText_IntroScene_OldManWelcomesFamily[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "わしには身内は一人もおりませ\r\n"
    "んし、気兼ねする必要はないで\r\n"
    "すよ。{Press}";

char const gText_IntroScene_MotherTellsPlayerToPlay[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "よかったわね。\r\n"
    "\xFFちゃん、\r\n"
    "思いっきり遊んでらっしゃい。{Press}";

char const gText_IntroScene_UnknownName[] SECTION(".rodata.intro_scene_text") =
    "？？？";

char const gText_IntroScene_UnknownCallsPlayer[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "い…{Press}"
    "\p"
    "～い…{Press}"
    "\p"
    "お～い。{Press}";

char const gText_IntroScene_UnknownFindsPlayer[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "！{Press}";

char const gText_IntroScene_GirlName[] SECTION(".rodata.intro_scene_text") =
    "女の子";

char const gText_IntroScene_GirlThinksPlayerDead[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "あんまりしずかだから、\r\n"
    "死んでるかと思ったわ。{Press}";

char const gText_IntroScene_GirlInvitesPlayerToPlay[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "へぇ～、ちょうどいいわ。\r\n"
    "わたし、ヒマなの。\r\n"
    "遊んであげるわ。{Press}\r\n"
    "感謝しなさいよ。{Press}";

char const gText_IntroScene_GirlAsksPlayerStory[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "ダマってたら、\r\n"
    "おもしろくないじゃない。{Press}"
    "\p"
    "そうねぇ、あんたの身の上話で\r\n"
    "も聞いてあげるわ。\r\n"
    "ほら、さっさと話しなさいよ。{Press}";

char const gText_IntroScene_OldManFarewell[] SECTION(".rodata.intro_scene_text") =
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

char const gText_IntroScene_OldManRequestsLetter[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "おお、そうだ。\r\n"
    "ボウズさえよければ文通でもせ\r\n"
    "んか？{Press}";

char const gText_IntroScene_OldManGivesAddress[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "そうか、やってくれるか。\r\n"
    "じゃ、わしの住所を教えておこ\r\n"
    "う。{Press}";

char const gText_IntroScene_GirlSaysGoodbye[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "あれっ、もう行っちゃうの？{Press}";

char const gText_IntroScene_GirlAsksPlayerToReturn[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "あんたが帰ったら、\r\n"
    "ヒマになっちゃうじゃないの。{Press}"
    "\p"
    "また、こっちに来たら遊んであ\r\n"
    "げるわ。{Press}";

char const gText_IntroScene_OldManNotesFriend[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "友達ができたみたいじゃのう。\r\n"
    "また来るときの楽しみも増えた\r\n"
    "の。{Press}";

char const gText_IntroScene_OldManWaitsForLetter[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "手紙待っとるからな………{Press}";

char const gCppRuntimeBadAlloc_IntroSceneTextTrailer[]
    SECTION(".rodata.intro_scene_text_trailer") =
        "bad_alloc";
