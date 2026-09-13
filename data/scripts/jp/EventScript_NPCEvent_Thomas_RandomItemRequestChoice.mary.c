#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerForHelp[] =
        "{Player}くん、\r\n"
        "キミを男と見込んで頼みが\r\n"
        "あるんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsBoastingMatchWithNeighboringMayor[] =
        "実はね…\r\n"
        "先日、隣町の町長と言い合いに\r\n"
        "なってね…{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsDiamondToday[] =
        "今日中に「ダイヤモンド」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBraceletToday[] =
        "今日中に「ブレスレット」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGreenPepperToday[] =
        "今日中に「ピーマン」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGoldenEggToday[] =
        "今日中に「金の卵」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBlackGrassToday[] =
        "今日中に「黒い草」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsWhiteGrassToday[] =
        "今日中に「白い草」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsTruffleToday[] =
        "今日中に「まつたけ」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsMoonStoneToday[] =
        "今日中に「ムーンストーン」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsAEPFEAppleToday[] =
        "今日中に「ＡＥＰＦＥりんご」\r\n"
        "を持っていかないとダメ\r\n"
        "なんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsRiceCakeToday[] =
        "今日中に「おもち」を\r\n"
        "持っていかないとダメなんだ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsUrgencyAndFearOfLosingFace[] =
        "そこでキミに用意してもらい\r\n"
        "たいんだ。{Press}\p"
        "こんなことを頼めるのはキミ\r\n"
        "ぐらいしかいなくてね。{Press}\p"
        "たのむ！{Press}\r\n"
        "わたしのメンツがかかってるん\r\n"
        "だよ！{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerToAcceptRequest[] =
        "どうだろう？\r\n"
        "ひきうけてくれるかね？{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceAcceptRequest[] =
        "ひきうける";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceDeclineRequest[] =
        "断る";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasThanksPlayerAndSchedulesSevenPmPickup[] =
        "ひきうけてくれるかね！\r\n"
        "さすが、{Player}くんだ！{Press}\p"
        "わたしは出かけるから、\r\n"
        "今日は夕方まで帰ってこれない\r\n"
        "んだ。{Press}\p"
        "ＰＭ７時ごろ取りに来るから、\r\n"
        "それまでにお願いするよ。\r\n"
        "じゃ、頼んだよ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExpressesDisappointmentAndHandlesRequestHimself[] =
        "そうか…\r\n"
        "キミがそんなヤツだったとは…{Press}\p"
        "わたしはキミを買いかぶって\r\n"
        "いたようだ。\r\n"
        "自分でなんとかしよう…{Press}";
};

void EventScript_NPCEvent_Thomas_RandomItemRequestChoice(void)
{
    int var_0, var_1;
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerForHelp);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsBoastingMatchWithNeighboringMayor);
    var_1 = RandomIntInclusive(0, 9);
    switch (var_1)
    {
        case 0:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsDiamondToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_DIAMOND);
            break;
        case 1:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBraceletToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_BRACELET);
            break;
        case 2:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGreenPepperToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_GREEN_PEPPER);
            break;
        case 3:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGoldenEggToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_GOLDEN_EGG);
            break;
        case 4:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBlackGrassToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_BLACK_GRASS);
            break;
        case 5:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsWhiteGrassToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_WHITE_GRASS);
            break;
        case 6:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsTruffleToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_TRUFFLE);
            break;
        case 7:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsMoonStoneToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_MOON_STONE);
            break;
        case 8:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsAEPFEAppleToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_AEPFE_APPLE);
            break;
        case 9:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsRiceCakeToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_RICE_CAKE);
            break;
    }
    TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsUrgencyAndFearOfLosingFace);
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerToAcceptRequest);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceAcceptRequest, gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceDeclineRequest);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasThanksPlayerAndSchedulesSevenPmPickup);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(30);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            AddNpcFriendship(CHARACTER_THOMAS, mary_negated_int(-10));
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_CHOICE, THOMAS_RANDOM_ITEM_REQUEST_ACCEPTED);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExpressesDisappointmentAndHandlesRequestHimself);
            TalkClose();
            AddNpcFriendship(CHARACTER_THOMAS, mary_negated_int(-10));
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_CHOICE, THOMAS_RANDOM_ITEM_REQUEST_DECLINED);
            break;
    }
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    MoveEntityXTo(ENTITY_THOMAS, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_UP);
    MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    HideEntity(ENTITY_THOMAS);
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    RefreshAllNpcSchedules();
    return;
}
