#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaAsksWhyZackIsVisiting[] =
        "It's unusual to see you\r\n"
        "around here, Zack. \r\n"
        "Is anything wrong...?{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackClaimsHeWasPassingBy[] =
        "No...um...I was just\r\n"
        "passing by... {Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackAsksAboutLilliasHealth[] =
        "How are you feeling...?{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaSaysSheHasBeenWell[] =
        "Very well these days, \r\n"
        "thank you very much!{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackExpressesRelief[] =
        "I'm very relieved \r\n"
        "to hear that...!{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackAdmitsHerIllnessKeepsHimAwake[] =
        "Whenever I hear that you're \r\n"
        "sick, I worry so much I \r\n"
        "can hardly sleep!{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaThanksZackForCaring[] =
        "Thanks a lot, Zack...\r\n"
        "I'm touched you care\r\n"
        "so much. {Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackThanksLilliaForRecognizingHisConcern[] =
        "Thanks for noticing. {Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaPromisesToRecoverForZack[] =
        "I'll just have to get better\r\n"
        "for your sake then, \r\n"
        "won’t I? Hee hee.{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackHesitates[] =
        "...Hmm...{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaAsksWhatIsWrong[] =
        "Is anything the matter now?{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackUrgesLilliaToRecover[] =
        "No...You just get better \r\n"
        "soon, Lillia...{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaPromisesToDoHerBest[] =
        "I'll do my best. {Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackSaysGoodbye[] =
        "OK...I'll be going now...{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_LilliaTellsZackToTakeCare[] =
        "Take care!{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_ZackGreetsPlayerWhileLeaving[] =
        "Hi there, {Player}.\r\n"
        "Bye now...{Press}";
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
