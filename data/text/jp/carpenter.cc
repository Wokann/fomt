#include "carpenter_text.hh"

#if defined(FOMT_TEXT_CARPENTER_MENU)

char const gText_Carpenter_Lumber[] =
    "資材";

char const gText_Carpenter_GoldenLumber[] =
    "黄金の資材";

char const gText_Carpenter_HouseExtension[] =
    "自宅を増築する";

char const gText_Carpenter_HouseExtensionFirstCost[] =
    "自宅の増築に必要な物\r\n"
    "お金　　　　　　　３０００Ｇ\r\n"
    "資材　　　　　　　　２００本";

char const gText_Carpenter_HouseExtensionSecondCost[] =
    "自宅の増築に必要な物\r\n"
    "お金　　　　　　１００００Ｇ\r\n"
    "資材　　　　　　　　７００本";

char const gText_Carpenter_AddBathtub[] =
    "お風呂を増築する";

char const gText_Carpenter_BathtubCost[] =
    "お風呂の増築に必要な物\r\n"
    "お金　　　　　　３００００Ｇ\r\n"
    "資材　　　　　　　　５８０本";

char const gText_Carpenter_ExpandChickenCoop[] =
    "鶏小屋を増築する";

char const gText_Carpenter_ChickenCoopCost[] =
    "鶏小屋の増築に必要な物\r\n"
    "お金　　　　　　　５０００Ｇ\r\n"
    "資材　　　　　　　　４２０本";

char const gText_Carpenter_ExpandBarn[] =
    "動物小屋を増築する";

char const gText_Carpenter_BarnCost[] =
    "動物小屋の増築に必要な物\r\n"
    "お金　　　　　　　６８００Ｇ\r\n"
    "資材　　　　　　　　５００本";

char const gText_Carpenter_BuildVacationHouse[] =
    "別荘を建てる";

char const gText_Carpenter_VacationHouseCost[] =
    "別荘を建てるのに必要な物\r\n"
    "お金　　１００００００００Ｇ\r\n"
    "資材　　　　　　　　９９９本";

char const gText_Carpenter_RemodelWindow[] =
    "自宅窓を建て替える";

char const gText_Carpenter_Rebuild[] =
    "建て替え。";

char const gText_Carpenter_RemodelDoghouse[] =
    "犬小屋を建て替える";

char const gText_Carpenter_RemodelMailbox[] =
    "ポストを建て替える";

char const gText_Carpenter_SquareWindowWithShutters[] =
    "雨戸がある四角い窓";

char const gText_Carpenter_WindowCost[] =
    "お金　　　　　　２５０００Ｇ\r\n"
    "資材　　　　　　　　３００本";

char const gText_Carpenter_SquareWindowWithoutShutters[] =
    "雨戸がない四角い窓";

char const gText_Carpenter_RoundWindow[] =
    "丸い窓";

char const gText_Carpenter_RedDoghouse[] =
    "赤い犬小屋";

char const gText_Carpenter_DoghouseCost[] =
    "お金　　　　　　２００００Ｇ\r\n"
    "資材　　　　　　　　５００本";

char const gText_Carpenter_BlueDoghouse[] =
    "青い犬小屋";

char const gText_Carpenter_StrangeDoghouse[] =
    "奇妙な形の犬小屋";

char const gText_Carpenter_RedMailbox[] =
    "赤いポスト";

char const gText_Carpenter_MailboxCost[] =
    "お金　　　　　　１００００Ｇ\r\n"
    "資材　　　　　　　　２００本";

char const gText_Carpenter_BlueMailbox[] =
    "青いポスト";

char const gText_Carpenter_StrangeMailbox[] =
    "奇妙な形のポスト";

#elif defined(FOMT_TEXT_CARPENTER_DIALOGUE)

char const gText_Carpenter_RebuildRequirements[] ALIGN(4) =
    "これに建て替えるのに必要な物\r\n";

char const gText_Carpenter_InsufficientGold[] =
    "おい、金が足りねぇぞ。{Press}";

char const gText_Carpenter_LumberBinFull[] =
    "すでに資材置き場が、\r\n"
    "資材でいっぱいだ…{Press}";

char const gText_Carpenter_LumberHeader[] =
    "資材\r\n"
    "\r\n";

char const gText_Carpenter_EquipmentFull[] =
    "おい、\r\n"
    "これ以上持てねぇみたいだぞ。{Press}";

char const gText_Carpenter_GoldenLumberHeader[] =
    "黄金の資材\r\n"
    "\r\n";

char const gText_Carpenter_CannotAcceptAnotherJob[] =
    "受けた仕事を終わらさないと、\r\n"
    "次の仕事は受けねぇ。\r\n"
    "それがオレのやり方だ。{Press}";

char const gText_Carpenter_InsufficientLumber[] =
    "おい、資材が足りねぇぞ。{Press}";

char const gText_Carpenter_ThreeDayConfirmation[] =
    "そうだなぁ…\r\n"
    "完成までに３日かかるけどいい\r\n"
    "か？{Press}";

char const gText_Carpenter_NeedAnythingElse[] =
    "他にいるものはないのか？{Press}";

char const gText_Carpenter_AreYouSureNow[] =
    "どうした、いいのか？{Press}";

char const gText_Carpenter_SameCurrentShape[] =
    "それは、今の形と同じだぞ？{Press}";

char const gText_Carpenter_StoreLumber[] =
    "よし、じゃあ資材置き場に資材\r\n"
    "を入れておくからな。{Press}";

char const gText_Carpenter_DeliveryAll[] =
    "ありがとよ。{Press}\p"
    "もう持てねぇみたいだな。\r\n"
    "家の方に持っていっておいてや\r\n"
    "るよ。{Press}";

char const gText_Carpenter_DeliverySome[] =
    "ありがとよ。{Press}\p"
    "何個か持てねぇみたいだな。\r\n"
    "家の方に持っていっておいてや\r\n"
    "るよ。{Press}";

char const gText_Carpenter_PurchaseComplete[] =
    "ありがとよ。{Press}";

char const gText_Carpenter_Build[] =
    "建てる";

char const gText_Carpenter_DontBuild[] =
    "建てない";

char const gText_Carpenter_Upgrade[] =
    "増築する";

char const gText_Carpenter_DontUpgrade[] =
    "増築しない";

char const gText_Carpenter_StartUpgradeTomorrow[] =
    "それじゃあ、\r\n"
    "増築は明日から始めるからな。{Press}";

char const gText_Carpenter_NeedAnythingMore[] =
    "他に何かいるか？{Press}";

#else
#error "Select one carpenter text fragment before including this file."
#endif
