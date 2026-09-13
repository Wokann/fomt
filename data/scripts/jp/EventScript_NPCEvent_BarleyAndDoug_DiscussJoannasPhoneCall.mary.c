#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyGreetsJoannaOnPhone[] =
        "わしじゃよ。元気にしとるか…\r\n"
        "……………………………………{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyAcknowledgesJoannaWillNotReturn[] =
        "…こっちに帰ってこれんの\r\n"
        "かの？{Press}\p"
        "…わかった。{Press}\p"
        "…また、電話するよ…{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougAsksWhetherCallerWasJoanna[] =
        "電話の相手はジョアンナかい？\r\n"
        "{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyExplainsMayWaitsForJoanna[] =
        "…そうじゃ…{Press}\p"
        "メイも待っとるというのに、\r\n"
        "いつまでたっても帰ってこよう\r\n"
        "とせんのじゃ…{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougSuggestsJoannaHasReasons[] =
        "ジョアンナにも色々と事情が\r\n"
        "あるんだろうよ。{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyQuestionsPriorityOverDaughter[] =
        "自分の娘と暮らすよりも大事な\r\n"
        "事なんてあるんじゃろうか？\r\n"
        "メイがかわいそうじゃ…{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougRecallsJoannaLeavingMayWithBarley[] =
        "そういや、\r\n"
        "ジョアンナが久しぶりに帰って\r\n"
        "きたと思ったら、{Press}\p"
        "メイちゃんをじいさんの所に\r\n"
        "おいてジョアンナは町に行った\r\n"
        "んだったよな。{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyExplainsJoannaHandlesProblemsAlone[] =
        "昔から、あの子は\r\n"
        "そうじゃった。{Press}\p"
        "何かあっても、わしに心配を\r\n"
        "かけまいとして自分だけで\r\n"
        "解決するフシがあったんじゃ。{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyCondemnsJoannaForAbandoningMayWithoutExplanation[] =
        "でも、今回だけは許せん。\r\n"
        "理由もつげずにメイをおいて\r\n"
        "いきおって…{Press}\p"
        "メイは明るくふるまっておる\r\n"
        "が、時々さみしそうな顔をする\r\n"
        "んじゃ。{Press}\p"
        "母親が恋しいんじゃろうな。\r\n"
        "そんなメイを見てると\r\n"
        "いたたまれなくなってな…{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougNotesMayStillNeedsMother[] =
        "メイちゃんもまだまだ母親が\r\n"
        "必要な時期だからな…{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyQuestionsJoannasUnfinishedBusiness[] =
        "ジョアンナに電話をかけては、\r\n"
        "もどってくるように言ってるん\r\n"
        "じゃが…{Press}\p"
        "まだやる事があるのの一点張り\r\n"
        "で、もどってこようとはせんの\r\n"
        "じゃ…{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyPlansToCookMaysFavoriteAndLeaves[] =
        "さて…{Press}\p"
        "今日はメイの好きな物でも\r\n"
        "作ってやろうかの。\r\n"
        "ジャマしたの。{Press}";
};

void EventScript_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_DOUG, X(316), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    MoveEntityYTo(ENTITY_PLAYER, Y(248), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_BARLEY, X(184), Y(336), FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityYTo(ENTITY_BARLEY, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
    MoveEntityXTo(ENTITY_BARLEY, X(208), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityYTo(ENTITY_BARLEY, Y(196), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
    MoveEntityXTo(ENTITY_BARLEY, X(336), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    PanCameraTo(X(336), Y(120), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    MoveEntityYTo(ENTITY_BARLEY, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyGreetsJoannaOnPhone);
    TalkClose();
    StartEntityEffect(ENTITY_BARLEY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(120);
    StartEntityEffect(ENTITY_BARLEY, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(120);
    StartEntityEffect(ENTITY_BARLEY, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_SLOW);
    WaitFrames(60);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_SLOW);
    StartEntityEffect(ENTITY_BARLEY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyAcknowledgesJoannaWillNotReturn);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityXTo(ENTITY_BARLEY, X(316), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougAsksWhetherCallerWasJoanna);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyExplainsMayWaitsForJoanna);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougSuggestsJoannaHasReasons);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyQuestionsPriorityOverDaughter);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougRecallsJoannaLeavingMayWithBarley);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyExplainsJoannaHandlesProblemsAlone);
    TalkClose();
    StartEntityEffect(ENTITY_BARLEY, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyCondemnsJoannaForAbandoningMayWithoutExplanation);
    TalkClose();
    StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougNotesMayStillNeedsMother);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyQuestionsJoannasUnfinishedBusiness);
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    TalkMessage(gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyPlansToCookMaysFavoriteAndLeaves);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityXTo(ENTITY_BARLEY, X(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
    MoveEntityYTo(ENTITY_BARLEY, Y(224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    HideEntity(ENTITY_BARLEY);
    WaitFrames(100);
    PanCameraTo(X(184), Y(248), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_BARLEY_AND_DOUG_DISCUSS_JOANNAS_PHONE_CALL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
