#include "blacksmith_text.hh"

#if defined(FOMT_TEXT_BLACKSMITH_MENU)

char const gText_Blacksmith_ToolUpgradeMenuLabel[] =
    "　　　　　　の改造";

char const gText_Blacksmith_ToolUpgradeTitle[] =
    "道具の改造";

char const gText_Blacksmith_Empty[] =
    "";

char const gText_Blacksmith_MakeMayonnaiseMaker[] =
    "マヨネーズメーカーを作る";

char const gText_Blacksmith_CostAdamantite[] =
    "これを作るのに必要な物\r\n"
    "お金　　　　　　２００００Ｇ\r\n"
    "鉱石　　　　　アダマンタイト";

char const gText_Blacksmith_MakeCheeseMaker[] =
    "チーズメーカーを作る";

char const gText_Blacksmith_MakeYarnMaker[] =
    "毛糸玉メーカーを作る";

char const gText_Blacksmith_MakeNecklace[] =
    "ネックレスを作る";

char const gText_Blacksmith_CostOrichalc[] =
    "これを作るのに必要な物\r\n"
    "お金　　　　　　　１０００Ｇ\r\n"
    "鉱石　　　　　　オリハルコン";

char const gText_Blacksmith_MakeEarrings[] =
    "イヤリングを作る";

char const gText_Blacksmith_MakeBracelet[] =
    "ブレスレットを作る";

char const gText_Blacksmith_MakeBroach[] =
    "ブローチを作る";

#elif defined(FOMT_TEXT_BLACKSMITH_DIALOGUE)

char const gText_Blacksmith_InsufficientGoldAdamantite[] =
    "これを作るには、アダマンタイ\r\n"
    "トという鉱石と、２００００Ｇ\r\n"
    "が必要だが…{Press}\p"
    "むむ、金がないのか？\r\n"
    "それは残念。{Press}";

char const gText_Blacksmith_InsufficientGoldOrichalc[] =
    "これを作るには、\r\n"
    "オリハルコンという鉱石と、\r\n"
    "１０００Ｇが必要だが…{Press}\p"
    "むむ、金がないのか？\r\n"
    "それは残念。{Press}";

char const gText_Blacksmith_MakerFiveDays[] =
    "作業には５日ほど、かかるが…\r\n"
    "よろしいかな？{Press}";

char const gText_Blacksmith_MakerOneDay[] =
    "作業には１日ほど、かかるが…\r\n"
    "よろしいかな？{Press}";

char const gText_Blacksmith_InsufficientOreAdamantite[] =
    "これを作るには、アダマンタイ\r\n"
    "トという鉱石と、２００００Ｇ\r\n"
    "が必要だが…{Press}\p"
    "むむ、鉱石がないのか？\r\n"
    "これを作るのに使う鉱石は泉の\r\n"
    "鉱石場で見つかるぞ。{Press}";

char const gText_Blacksmith_InsufficientOreOrichalc[] =
    "これを作るには、\r\n"
    "オリハルコンという鉱石と、\r\n"
    "１０００Ｇが必要だが…{Press}\p"
    "むむ、鉱石がないのか？\r\n"
    "これを作るのに使う鉱石は泉の\r\n"
    "鉱石場で見つかるぞ。{Press}";

char const gText_Blacksmith_SelectToolAndOre[] =
    "では、改造させる道具と改造に\r\n"
    "使う鉱石を選ぶのだ。{Press}";

char const gText_Blacksmith_InsufficientGold[] =
    "金が足りないみたいだな。{Press}";

char const gText_Blacksmith_EquipmentFull[] =
    "これ以上、\r\n"
    "装備は持てないみたいだぞ？{Press}";

char const gText_Blacksmith_NeedAnythingElse[] =
    "他に必要なものはないのか？{Press}";

char const gText_Blacksmith_NothingElse[] =
    "なんだ、何もいらないのか。{Press}";

char const gText_Blacksmith_PurchaseComplete[] =
    "たしかに、いただきましたぞ。{Press}";

char const gText_Blacksmith_Delivery[] =
    "たしかに、いただきましたぞ。\r\n"
    "おや、装備がいっぱいのようだ\r\n"
    "な。{Press}\p"
    "後でグレイに持っていかせるか\r\n"
    "ら楽しみに待っていなさい。{Press}";

char const gText_Blacksmith_PurchaseMore[] =
    "他にも何か買うのかな。{Press}";

char const gText_Blacksmith_MakeIt[] =
    "作ってもらう";

char const gText_Blacksmith_DontMakeIt[] =
    "作ってもらわない";

char const gText_Blacksmith_StartWork[] =
    "うぉっほん…！\r\n"
    "これから作業に入るのだ。\r\n"
    "出ていってもらいたい。{Press}";

char const gText_Blacksmith_CannotChangeMind[] =
    "男が一度決めたことは、\r\n"
    "そう変えるものではないぞ。{Press}";

char const gText_Blacksmith_NoToolToUpgrade[] =
    "道具を持ってきておらんようだ\r\n"
    "な。改造したい道具を持ってき\r\n"
    "なさい。{Press}";

char const gText_Blacksmith_NoOreToUpgrade[] =
    "道具を改造するのに使える鉱石\r\n"
    "を持っていないようだな。鉱石\r\n"
    "は泉の鉱石場で見つかるぞ。{Press}";

char const gCppRuntimeBadAlloc_BlacksmithDialogueTrailer[] =
    "bad_alloc";

#elif defined(FOMT_TEXT_BLACKSMITH_UPGRADE)

char const gText_BlacksmithUpgrade_EmptyDescription[] =
    "";

char const gText_BlacksmithUpgrade_Tools[] =
    "装備";

char const gText_BlacksmithUpgrade_Items[] =
    "持ち物";

char const gText_BlacksmithUpgrade_SelectTool[] =
    "まず、改造させたい道具を選ぶ\r\n"
    "のだ。{Press}";

char const gText_BlacksmithUpgrade_CursedTool[] =
    "の…呪われているではないか！\r\n"
    "な…何を考えておる！！！{Press}";

char const gText_BlacksmithUpgrade_SelectOre[] =
    "次に、その道具を改造する鉱石\r\n"
    "を選ぶのだ。{Press}";

char const gText_BlacksmithUpgrade_CannotUpgradeTool[] =
    "それは改造できんぞ。{Press}";

char const gText_BlacksmithUpgrade_InvalidUpgradeOre[] =
    "それは道具の改造には使えない\r\n"
    "のだ。道具を改造するにはそれ\r\n"
    "なりの鉱石が必要なのだ。{Press}";

char const gText_BlacksmithUpgrade_CannotChangeMind[] =
    "男が一度決めたことは、\r\n"
    "そう変えるものではないぞ。{Press}";

char const gText_BlacksmithUpgrade_InsufficientExperience[] =
    "その道具を改造するには\r\n"
    "経験が足りないぞ。{Press}";

char const gText_BlacksmithUpgrade_AlreadyUpgradedWithOre[] =
    "その道具はすでに、同じ鉱石を\r\n"
    "使って強くしたものだ。{Press}";

char const gText_BlacksmithUpgrade_DowngradeConfirmation[] =
    "ふん…、それではかえって道具\r\n"
    "が悪くなってしまうぞ。\r\n"
    "いいのか？{Press}";

char const gText_BlacksmithUpgrade_WorkOrderPrefix[] =
    "その道具は、\r\n";

char const gText_BlacksmithUpgrade_WorkOrderGoldSuffix[] =
    "Ｇで";

char const gText_BlacksmithUpgrade_WorkOrderDaysSuffix[] =
    "日かかるぞ。\r\n"
    "よろしいかな？{Press}";

char const gText_BlacksmithUpgrade_InsufficientGoldPageBreak[] =
    "\p";

char const gText_BlacksmithUpgrade_InsufficientGold[] =
    "…………………\r\n"
    "金が足りんぞ？\r\n"
    "その金額では受けられんな。{Press}";

char const gText_BlacksmithUpgrade_ResultYes[] =
    "はい";

char const gText_BlacksmithUpgrade_ResultNo[] =
    "いいえ";

#else
#error "Select one blacksmith text fragment before including this file."
#endif
