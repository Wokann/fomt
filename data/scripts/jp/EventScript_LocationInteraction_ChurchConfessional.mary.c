#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_ChurchConfessional_InitialServicePrompt[] =
        "どうかされましたか？{Press}";

    const char gText_LocationInteraction_ChurchConfessional_FollowupConcernPrompt[] =
        "他にはありますか？{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceRemoveCursedTool[] =
        "呪われた道具をはずす";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfess[] =
        "ざんげする";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceJustSayingHi[] =
        "あいさつだけ";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalFeePrompt[] =
        "１０００Ｇになりますが？";

    const char gText_LocationInteraction_ChurchConfessional_ChoicePayRemovalFee[] =
        "はい";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceDeclineRemoval[] =
        "いいえ";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalPrayer[] =
        "では、祈りましょう…{Press}\p"
        "この方は、不幸にも道具の呪い\r\n"
        "にかかってしまいました。この\r\n"
        "方の不幸を取り除き下さい…{Press}";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientMoneyForCursedToolRemoval[] =
        "残念ながら、お金が足りないよ\r\n"
        "うですね。申し訳無いのですが\r\n"
        "はずす事は出来ませんね。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedToolRemovalConfirmationPrompt[] =
        "おや、よろしいのですか？{Press}";

    const char gText_LocationInteraction_ChurchConfessional_NoCursedToolEquipped[] =
        "呪われた道具を装備してないよ\r\n"
        "うですね。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionAvailableOncePerDay[] =
        "ざんげは１日１回だけですよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionTopicPrompt[] =
        "どんな事についてざんげするの\r\n"
        "ですか？{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessInsufficientSleep[] =
        "毎日ほとんど寝てない";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessOverworkingHarvestSprites[] =
        "コロボックルをこき使ってる";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessDesireToMarryHarvestGoddess[] =
        "女神様と結婚したい";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionForgiven[] =
        "睡眠というのは人間にとって、\r\n"
        "とても重要なものです。{Press}\p"
        "いそがしいのはわかりますが、\r\n"
        "時には、ゆったりとした気持ち\r\n"
        "で休む事をお勧めしますよ。{Press}大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionRejected[] =
        "睡眠をしないとは何事ですか！\r\n"
        "あなたは神がお作りになった自\r\n"
        "然の営みを崩すつもりですか！{Press}\p"
        "神に対するぼうとくですよ！！{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんでした。\r\n"
        "いつか天罰が下りますよ！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionForgiven[] =
        "コロボックルさんたちは、好意\r\n"
        "で仕事を手伝ってくれているの\r\n"
        "です。{Press}\p"
        "日頃のおれいに感謝の品なんか\r\n"
        "を送ったらどうでしょう？\r\n"
        "きっと彼らは喜んでくれると思\r\n"
        "いますよ。{Press}\p"
        "大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionRejected[] =
        "コロボックルをこき使ってるっ\r\n"
        "てどういうことなの？{Press}\p"
        "ボクたちは親切で働いてるの！\r\n"
        "感謝もしないでこき使ったら許\r\n"
        "さないの～！！{Press}\p"
        "ってコロボックルたちに怒られ\r\n"
        "ても知りませんよ！{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんの。\r\n"
        "いつか天罰が下りますの！{Press}\p"
        "ああっ、いけない、いけない。\r\n"
        "口ぐせになってしまうの。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionForgiven[] =
        "女神様と結婚したいのですか…\r\n"
        "女神様の事をそこまで強く思わ\r\n"
        "れているのですね。{Press}\p"
        "あなたの熱意は、きっと女神様\r\n"
        "に届いているでしょう。{Press}\p"
        "大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionRejected[] =
        "な…なんですって…\r\n"
        "女神様と結婚したい？\r\n"
        "なんて事を言うのですか！{Press}\p"
        "相手は神様なのですよ？\r\n"
        "わたしだって出来るのであれば\r\n"
        "結婚したいですよ！{Press}\p"
        "ゴホン、ゴホン…いやいや、今\r\n"
        "のは聞き流してください。\r\n"
        "とにかく………{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんでした。\r\n"
        "いつか天罰が下りますよ！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessNeglectingAnimals[] =
        "全然動物の世話をしてない";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceWorkedUntilCollapsed[] =
        "倒れるまで道具を使い続けた";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceTownspeopleDislikePlayer[] =
        "街の人に嫌がられた";

    const char gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionForgiven[] =
        "あなたが飼っている動物は、\r\n"
        "あなたに自分の牛乳や毛をくれ\r\n"
        "るわけですから、{Press}\p"
        "そのおれいのつもりで、世話を\r\n"
        "してやりましょう。{Press}\p"
        "大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionRejected[] =
        "あなたは自分の飼っている動物\r\n"
        "をなんだと思っているのです？{Press}\p"
        "あなたに自分の牛乳や毛をわけ\r\n"
        "てくれるのでしょう？{Press}\p"
        "そのおれいに世話をしてやろう\r\n"
        "とは思わないのですか？{Press}\p"
        "そんな飼い主に飼われている動\r\n"
        "物たちがとてもかわいそうです\r\n"
        "よ。{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんでした。\r\n"
        "いつか天罰が下りますよ！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionForgiven[] =
        "倒れるまで働くとは、あなたは\r\n"
        "働き者ですね。でも、少しは体\r\n"
        "の事を考えてあげて下さい。{Press}\p"
        "倒れるということは、それだけ\r\n"
        "体が疲れているという証拠なの\r\n"
        "です。{Press}\p"
        "今度からは、疲れたら栄養補給\r\n"
        "するとか、疲れをとってから仕\r\n"
        "事をして下さいね。{Press}\p"
        "大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionRejected[] =
        "あなたは親からもらった体を何\r\n"
        "だと思っているのです？{Press}\p"
        "そんなに体を痛めつけて楽しい\r\n"
        "のですか？\r\n"
        "体をもっといたわりなさい！{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんでした。\r\n"
        "いつか天罰が下りますよ！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ForgivesPoorRelationsAndImprovesFriendship[] =
        "理由がなく街の人が嫌がるわけ\r\n"
        "はありません。\r\n"
        "きっと、原因があるはずです。{Press}\p"
        "胸に手を当ててじっくり考えて\r\n"
        "みるのです。もし、思い当たる\r\n"
        "事があれば反省して下さい。{Press}\p"
        "大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_PoorRelationsConfessionRejected[] =
        "なにか、わたしまで嫌な気分に\r\n"
        "なってきました。早く終わらせ\r\n"
        "てしまいましょう。{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんでした。\r\n"
        "いつか天罰が下りますよ！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessAnimalCruelty[] =
        "動物をいじめた";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessSleepingLate[] =
        "寝坊した";

    const char gText_LocationInteraction_ChurchConfessional_ChoiceConfessLittering[] =
        "道にゴミを捨てた";

    const char gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionForgiven[] =
        "人の心は弱いものです。そのた\r\n"
        "め、時に、さらに弱いものを苦\r\n"
        "しめて、救われようとします。{Press}\p"
        "しかし、実はそれが弱いである\r\n"
        "がための行動なために、それに\r\n"
        "気がつかない人は、{Press}\p"
        "いつまでも、救われないでいる\r\n"
        "のですよ。{Press}\p"
        "大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionRejected[] =
        "な…なんという事を…\r\n"
        "あなたがそんな人だとは思いま\r\n"
        "せんでしたよ…{Press}\p"
        "あなたは弱いものをいじめて楽\r\n"
        "しいのですか？{Press}\p"
        "楽しいと感じているならば、も\r\n"
        "はや救うことは出来ませんね…{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんでした。\r\n"
        "いつか天罰が下りますよ！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ForgivesSleepingLateAndReducesFatigue[] =
        "人の体は、心とちがって、とて\r\n"
        "も正直です。寝坊そのものは、\r\n"
        "悪い事ではありません。{Press}\p"
        "大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_SleepingLateConfessionRejected[] =
        "寝坊というのは日々の心がけを\r\n"
        "ちゃんとしていないから起こる\r\n"
        "ものなのです。{Press}\p"
        "あなたが寝坊をすることによっ\r\n"
        "て予定がたたない人もいるかも\r\n"
        "知れません。{Press}\p"
        "時間にルーズな人は、嫌われて\r\n"
        "しまいますよ。{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんでした。\r\n"
        "いつか天罰が下りますよ！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_LitteringConfessionForgiven[] =
        "あなたが出したゴミならば、\r\n"
        "あなたがゴミ箱に捨てるのが当\r\n"
        "然です。{Press}\p"
        "他人が出したゴミならば、あな\r\n"
        "たがゴミ箱に捨てるのは、やさ\r\n"
        "しさです。{Press}\p"
        "大丈夫、神はあなたを、お許し\r\n"
        "になられましたよ。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_LitteringConfessionRejected[] =
        "……………………………………\r\n"
        "……………………………………\r\n"
        "……………………………………{Press}\p"
        "あきれてものも言えません…\r\n"
        "あなたは自分の家にゴミを捨て\r\n"
        "る人がいたらどう思いますか？{Press}\p"
        "イヤな気分になるでしょう？\r\n"
        "それと同じ事です。{Press}\p"
        "神はあなたをお許しになられま\r\n"
        "せんでした。\r\n"
        "いつか天罰が下りますよ！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionSessionComplete[] =
        "今日のざんげは、ここまでにし\r\n"
        "ておきましょう。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_Greeting[] =
        "はい、こんにちは。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_Farewell[] =
        "またいつでも来て下さいね。{Press}";

    const char gText_LocationInteraction_ChurchConfessional_ConfessionalClosed[] =
        "カギがかかっている…{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedHoePurified[] =
        "呪われたクワの\r\n"
        "呪いがとけた！{Press}";

    const char gText_LocationInteraction_ChurchConfessional_CursedWateringCanPurified[] =
        "呪われたじょうろの\r\n"
        "呪いがとけた！{Press}";
};

void EventScript_LocationInteraction_ChurchConfessional(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, unused_6, var_7, var_8, var_9;
    var_7 = 0;
    var_3 = FALSE;
    var_5 = VarGet(VAR_DAY_OF_WEEK);
    var_4 = VarGet(VAR_HOUR);
    if (VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MUSIC_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
    {
        var_3 = FALSE;
    }
    else
    {
        if (GetEntityLocation(ENTITY_CARTER) != MAP_NORTH_SIDE_TOWN && GetEntityLocation(ENTITY_CARTER) != MAP_CHURCH)
        {
            var_3 = TRUE;
        }
        else
        {
            var_3 = FALSE;
        }
    }
    if (var_3 == TRUE)
    {
        var_2 = FALSE;
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        OpenDoor(DOOR_SLOT_11);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
        }
        MoveEntityXTo(ENTITY_PLAYER, X(60), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        MoveEntityYTo(ENTITY_PLAYER, Y(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        do
        {
            if (var_2 != TRUE)
            {
                TalkMessage(gText_LocationInteraction_ChurchConfessional_InitialServicePrompt);
            }
            else
            {
                TalkMessage(gText_LocationInteraction_ChurchConfessional_FollowupConcernPrompt);
            }
            var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceRemoveCursedTool, gText_LocationInteraction_ChurchConfessional_ChoiceConfess, gText_LocationInteraction_ChurchConfessional_ChoiceJustSayingHi);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    if (GetPlayerHeldToolId() == ITEM_TOOL_SICKLE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_HOE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_AXE_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_HAMMER_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_WATERING_CAN_CURSED || GetPlayerHeldToolId() == ITEM_TOOL_FISHING_ROD_CURSED)
                    {
                        var_0 = TalkPromptChoice2(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalFeePrompt, gText_LocationInteraction_ChurchConfessional_ChoicePayRemovalFee, gText_LocationInteraction_ChurchConfessional_ChoiceDeclineRemoval);
                        switch (var_0)
                        {
                            case PROMPT_CHOICE_OPTION_1:
                                if (GetMoney() >= 1000)
                                {
                                    TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalPrayer);
                                    PlaySong(AUDIO_START, AUDIO_SFX_HEAL_OR_PURIFY);
                                    WaitFrames(60);
                                    SubtractMoney(1000);
                                    var_2 = FALSE;
                                    var_8 = GetPlayerHeldToolId();
                                    var_9 = var_8 + 1;
                                    var_7 = AttemptChurchCursedToolRemoval(var_8);
                                    if (var_7)
                                    {
                                        SetPlayerHeldTool(var_9, 1);
                                    }
                                    CycleBackwardToNonCursedTool();
                                }
                                else
                                {
                                    TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientMoneyForCursedToolRemoval);
                                    var_2 = TRUE;
                                }
                                break;
                            case PROMPT_CHOICE_OPTION_2:
                                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedToolRemovalConfirmationPrompt);
                                var_2 = TRUE;
                                break;
                        }
                    }
                    else
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_NoCursedToolEquipped);
                        var_2 = TRUE;
                    }
                    break;
                case CHOICE_OPTION_2:
                    if (VarGet(VAR_CHURCH_CONFESSION_USED_TODAY) == TRUE)
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionAvailableOncePerDay);
                        var_2 = TRUE;
                    }
                    else
                    {
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionTopicPrompt);
                        if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_HARVEST_GODDESS_MARRIAGE_BLESSING_RECEIVED) == TRUE)
                        {
                            var_1 = RandomIntInclusive(1, 4);
                        }
                        else
                        {
                            var_1 = RandomIntInclusive(0, 4);
                        }
                        switch (var_1)
                        {
                            case 0:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessInsufficientSleep, gText_LocationInteraction_ChurchConfessional_ChoiceConfessOverworkingHarvestSprites, gText_LocationInteraction_ChurchConfessional_ChoiceConfessDesireToMarryHarvestGoddess);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionForgiven);
                                                ChangePlayerStaminaAndFatigue(10, 0);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_InsufficientSleepConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionForgiven);
                                                AddNpcFriendship(CHARACTER_STAID, 2);
                                                AddNpcFriendship(CHARACTER_NAPPY, 2);
                                                AddNpcFriendship(CHARACTER_BOLD, 2);
                                                AddNpcFriendship(CHARACTER_CHEF, 2);
                                                AddNpcFriendship(CHARACTER_AQUA, 2);
                                                AddNpcFriendship(CHARACTER_HOGGY, 2);
                                                AddNpcFriendship(CHARACTER_TIMID, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_OverworkingHarvestSpritesConfessionRejected);
                                                break;
                                        }
                                        break;
                                    mary_dead_jump:
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 9);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionForgiven);
                                                VarSet(VAR_HARVEST_GODDESS_MARRIAGE_BLESSING_RECEIVED, TRUE);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                            case 4:
                                            case 5:
                                            case 6:
                                            case 7:
                                            case 8:
                                            case 9:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_HarvestGoddessMarriageConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                            case 1:
                            case 2:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessNeglectingAnimals, gText_LocationInteraction_ChurchConfessional_ChoiceWorkedUntilCollapsed, gText_LocationInteraction_ChurchConfessional_ChoiceTownspeopleDislikePlayer);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionForgiven);
                                                AddAffectionToAllFarmAnimals(5);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_NeglectingAnimalsConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionForgiven);
                                                ChangePlayerStaminaAndFatigue(10, 0);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_WorkingUntilCollapseConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_ForgivesPoorRelationsAndImprovesFriendship);
                                                AddNpcFriendship(CHARACTER_LILLIA, 2);
                                                AddNpcFriendship(CHARACTER_RICK, 2);
                                                AddNpcFriendship(CHARACTER_POPURI, 2);
                                                AddNpcFriendship(CHARACTER_BARLEY, 2);
                                                AddNpcFriendship(CHARACTER_MAY, 2);
                                                AddNpcFriendship(CHARACTER_SAIBARA, 2);
                                                AddNpcFriendship(CHARACTER_GRAY, 2);
                                                AddNpcFriendship(CHARACTER_DUKE, 2);
                                                AddNpcFriendship(CHARACTER_MANNA, 2);
                                                AddNpcFriendship(CHARACTER_BASIL, 2);
                                                AddNpcFriendship(CHARACTER_ANNA, 2);
                                                AddNpcFriendship(CHARACTER_MARY, 2);
                                                AddNpcFriendship(CHARACTER_THOMAS, 2);
                                                AddNpcFriendship(CHARACTER_HARRIS, 2);
                                                AddNpcFriendship(CHARACTER_ELLEN, 2);
                                                AddNpcFriendship(CHARACTER_STU, 2);
                                                AddNpcFriendship(CHARACTER_JEFF, 2);
                                                AddNpcFriendship(CHARACTER_SASHA, 2);
                                                AddNpcFriendship(CHARACTER_KAREN, 2);
                                                AddNpcFriendship(CHARACTER_DOCTOR, 2);
                                                AddNpcFriendship(CHARACTER_ELLI, 2);
                                                AddNpcFriendship(CHARACTER_CARTER, 2);
                                                AddNpcFriendship(CHARACTER_CLIFF, 2);
                                                AddNpcFriendship(CHARACTER_DOUG, 2);
                                                AddNpcFriendship(CHARACTER_ANN, 2);
                                                AddNpcFriendship(CHARACTER_KAI, 2);
                                                AddNpcFriendship(CHARACTER_GOTZ, 2);
                                                AddNpcFriendship(CHARACTER_ZACK, 2);
                                                AddNpcFriendship(CHARACTER_WON, 2);
                                                AddNpcFriendship(CHARACTER_GOURMET, 2);
                                                AddNpcFriendship(CHARACTER_HARVEST_GODDESS, 2);
                                                AddNpcFriendship(CHARACTER_VAN, 2);
                                                AddNpcFriendship(CHARACTER_LOU_OR_RUBY, 2);
                                                AddNpcFriendship(CHARACTER_CHILD, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_PoorRelationsConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                            case 3:
                            case 4:
                                var_0 = TalkChoice3(gText_LocationInteraction_ChurchConfessional_ChoiceConfessAnimalCruelty, gText_LocationInteraction_ChurchConfessional_ChoiceConfessSleepingLate, gText_LocationInteraction_ChurchConfessional_ChoiceConfessLittering);
                                switch (var_0)
                                {
                                    case CHOICE_OPTION_1:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionForgiven);
                                                AddAffectionToAllFarmAnimals(5);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_AnimalCrueltyConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_2:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_ForgivesSleepingLateAndReducesFatigue);
                                                ChangePlayerStaminaAndFatigue(0, mary_negated_int(-2));
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_SleepingLateConfessionRejected);
                                                break;
                                        }
                                        break;
                                    case CHOICE_OPTION_3:
                                        var_1 = RandomIntInclusive(0, 3);
                                        switch (var_1)
                                        {
                                            case 0:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_LitteringConfessionForgiven);
                                                AddNpcFriendship(CHARACTER_LILLIA, 2);
                                                AddNpcFriendship(CHARACTER_RICK, 2);
                                                AddNpcFriendship(CHARACTER_POPURI, 2);
                                                AddNpcFriendship(CHARACTER_BARLEY, 2);
                                                AddNpcFriendship(CHARACTER_MAY, 2);
                                                AddNpcFriendship(CHARACTER_SAIBARA, 2);
                                                AddNpcFriendship(CHARACTER_GRAY, 2);
                                                AddNpcFriendship(CHARACTER_DUKE, 2);
                                                AddNpcFriendship(CHARACTER_MANNA, 2);
                                                AddNpcFriendship(CHARACTER_BASIL, 2);
                                                AddNpcFriendship(CHARACTER_ANNA, 2);
                                                AddNpcFriendship(CHARACTER_MARY, 2);
                                                AddNpcFriendship(CHARACTER_THOMAS, 2);
                                                AddNpcFriendship(CHARACTER_HARRIS, 2);
                                                AddNpcFriendship(CHARACTER_ELLEN, 2);
                                                AddNpcFriendship(CHARACTER_STU, 2);
                                                AddNpcFriendship(CHARACTER_JEFF, 2);
                                                AddNpcFriendship(CHARACTER_SASHA, 2);
                                                AddNpcFriendship(CHARACTER_KAREN, 2);
                                                AddNpcFriendship(CHARACTER_DOCTOR, 2);
                                                AddNpcFriendship(CHARACTER_ELLI, 2);
                                                AddNpcFriendship(CHARACTER_CARTER, 2);
                                                AddNpcFriendship(CHARACTER_CLIFF, 2);
                                                AddNpcFriendship(CHARACTER_DOUG, 2);
                                                AddNpcFriendship(CHARACTER_ANN, 2);
                                                AddNpcFriendship(CHARACTER_KAI, 2);
                                                AddNpcFriendship(CHARACTER_GOTZ, 2);
                                                AddNpcFriendship(CHARACTER_ZACK, 2);
                                                AddNpcFriendship(CHARACTER_WON, 2);
                                                AddNpcFriendship(CHARACTER_GOURMET, 2);
                                                AddNpcFriendship(CHARACTER_HARVEST_GODDESS, 2);
                                                AddNpcFriendship(CHARACTER_VAN, 2);
                                                AddNpcFriendship(CHARACTER_LOU_OR_RUBY, 2);
                                                AddNpcFriendship(CHARACTER_CHILD, 2);
                                                break;
                                            case 1:
                                            case 2:
                                            case 3:
                                                TalkMessage(gText_LocationInteraction_ChurchConfessional_LitteringConfessionRejected);
                                                break;
                                        }
                                        break;
                                }
                                break;
                        }
                        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionSessionComplete);
                        VarSet(VAR_CHURCH_CONFESSION_USED_TODAY, TRUE);
                        var_2 = FALSE;
                    }
                    break;
                case CHOICE_OPTION_3:
                    TalkMessage(gText_LocationInteraction_ChurchConfessional_Greeting);
                    var_2 = FALSE;
                    break;
            }
        }
        while (var_2 == TRUE);
        TalkMessage(gText_LocationInteraction_ChurchConfessional_Farewell);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
        }
        MoveEntityYTo(ENTITY_PLAYER, Y(64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        CloseDoor(DOOR_SLOT_11);
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_ChurchConfessional_ConfessionalClosed);
        TalkClose();
    }
    if (var_7)
    {
        switch (var_9)
        {
            case ITEM_TOOL_HOE_BLESSED:
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                    ShowPlayerHoldingTool(ITEM_TOOL_HOE_BLESSED);
                    WaitFrames(90);
                }
                TalkOpen();
                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedHoePurified);
                TalkClose();
                break;
            case ITEM_TOOL_WATERING_CAN_BLESSED:
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                    ShowPlayerHoldingTool(ITEM_TOOL_WATERING_CAN_BLESSED);
                    WaitFrames(90);
                }
                TalkOpen();
                TalkMessage(gText_LocationInteraction_ChurchConfessional_CursedWateringCanPurified);
                TalkClose();
                break;
        }
    }
}
