#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaAsksWhyZackIsVisiting[] =
        "家にザクちゃんが来るなんて\r\n"
        "珍しいわね～。\r\n"
        "どうかしたの～？{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackClaimsHeWasPassingBy[] =
        "あ、い…いえ、ちょうど前を\r\n"
        "通ったんで…{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackAsksAboutLilliasHealth[] =
        "か…体の具合はどうっスか？\r\n"
        "{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaSaysSheHasBeenWell[] =
        "この頃、とても調子いいの～。\r\n"
        "ごめんねぇ～。\r\n"
        "心配かけちゃって～。{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackExpressesRelief[] =
        "い…いえ、リ…リリアさんが\r\n"
        "元気ならよかったっス。{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackAdmitsHerIllnessKeepsHimAwake[] =
        "リリアさんが病気になったって\r\n"
        "聞くと、心配で夜も寝られない\r\n"
        "っスから。{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaThanksZackForCaring[] =
        "ザクちゃん…\r\n"
        "ありがとう～。そんなに\r\n"
        "思っててくれたんだ～。{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackThanksLilliaForRecognizingHisConcern[] =
        "そ…　そうっス！\r\n"
        "や…　やっと気付いてくれた\r\n"
        "っスね。{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaPromisesToRecoverForZack[] =
        "うん。ザクちゃんに心配\r\n"
        "かけないように、\r\n"
        "早く病気を治すから～。{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackHesitates[] =
        "えっ？\r\n"
        "{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaAsksWhatIsWrong[] =
        "ザクちゃん、どうしたの～？\r\n"
        "{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackUrgesLilliaToRecover[] =
        "あっ、いや…そうっスね…\r\n"
        "早く病気を治してください。{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaPromisesToDoHerBest[] =
        "うん。わかった～。\r\n"
        "{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackSaysGoodbye[] =
        "じゃ、オレ…\r\n"
        "帰ります。{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaTellsZackToTakeCare[] =
        "気をつけて帰ってねぇ～。\r\n"
        "{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackGreetsPlayerWhileLeaving[] =
        "よう…\r\n"
        "{Player}、元気か…\r\n"
        "じゃあな…はぁ…{Press}";
};

void EventScript_NPCEvent_Zack_VisitsSickLillia(void)
{
    EnableScriptedNpcControl();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_LILLIA, X(216), Y(160), FACING_LEFT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_ZACK, X(176), Y(160), FACING_RIGHT);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(160), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    MoveEntityYTo(ENTITY_PLAYER, Y(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_LilliaAsksWhyZackIsVisiting);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackClaimsHeWasPassingBy);
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackAsksAboutLilliasHealth);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_LilliaSaysSheHasBeenWell);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackExpressesRelief);
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackAdmitsHerIllnessKeepsHimAwake);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_LilliaThanksZackForCaring);
    TalkClose();
    StartEntityEffect(ENTITY_ZACK, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackThanksLilliaForRecognizingHisConcern);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_LilliaPromisesToRecoverForZack);
    TalkClose();
    StartEntityEffect(ENTITY_ZACK, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackHesitates);
    TalkClose();
    StartEntityEffect(ENTITY_LILLIA, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_LilliaAsksWhatIsWrong);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackUrgesLilliaToRecover);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_LilliaPromisesToDoHerBest);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackSaysGoodbye);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_LilliaTellsZackToTakeCare);
    TalkClose();
    SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityXTo(ENTITY_ZACK, X(140), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_ZackGreetsPlayerWhileLeaving);
    TalkClose();
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityYTo(ENTITY_ZACK, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
    MoveEntityXTo(ENTITY_ZACK, X(128), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    MoveEntityYTo(ENTITY_ZACK, Y(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    HideEntity(ENTITY_ZACK);
    MarkNpcSpokenTo(CHARACTER_ZACK);
    EnableScriptedNpcControl();
    VarSet(VAR_ZACK_VISITS_SICK_LILLIA_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_LILLIA, EventScript_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue);
    return;
}
