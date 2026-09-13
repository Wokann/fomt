#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyGreetsJoannaOnPhone[] =
        "It's me. How are you?{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyAcknowledgesJoannaWillNotReturn[] =
        "You're not ready to \r\n"
        "come back yet...?{Press}\p"
        "...I see.{Press}\p"
        "I'll call again. Take care.{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougAsksWhetherCallerWasJoanna[] =
        "Was that Joanna? {Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyExplainsMayWaitsForJoanna[] =
        "..Yes...{Press}\p"
        "May waits everyday for her\r\n"
        "to come home, {Press}\r\n"
        "but she won't...!{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougSuggestsJoannaHasReasons[] =
        "I bet she has her reasons.{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyQuestionsPriorityOverDaughter[] =
        "Could there be anything\r\n"
        "more important than her own\r\n"
        "daughter?!{Press}\p"
        "Poor May...{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougRecallsJoannaLeavingMayWithBarley[] =
        "I remember...\r\n"
        "She was away for a long \r\n"
        "time, and when she finally {Press}\r\n"
        "did come back home she left\r\n"
        "May with you and then \r\n"
        "took off again!{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyExplainsJoannaHandlesProblemsAlone[] =
        "Joanna's always been that \r\n"
        "way. {Press}\p"
        "She tries to solve all her \r\n"
        "problems by herself. {Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyCondemnsJoannaForAbandoningMayWithoutExplanation[] =
        "I can't forgive her this \r\n"
        "time, though!{Press}\p"
        "Leaving May with me and \r\n"
        "going off to the city...\r\n"
        "all without telling me why!{Press}\p"
        "May tries to act brave, \r\n"
        "but she misses her mother. {Press}\p"
        "It makes me so mad...!!{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougNotesMayStillNeedsMother[] =
        "She's still at that age \r\n"
        "where she needs her mom, \r\n"
        "isn't she...?{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyQuestionsJoannasUnfinishedBusiness[] =
        "Joanna keeps insisting she \r\n"
        "has more business to take\r\n"
        "care of...{Press}\p"
        "What could it be!?{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyPlansToCookMaysFavoriteAndLeaves[] =
        "I'll make May's\r\n"
        "favorite today. Bye now. {Press}";
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
