#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyGreetsJoannaOnPhone[] =
        "Ich bin es. Wie geht es dir?{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyAcknowledgesJoannaWillNotReturn[] =
        "Du bist noch nicht \r\n"
        "bereit zurückzukommen?{Press}\p"
        "...Verstehe.{Press}\p"
        "Ich rufe wieder an. \r\n"
        "Pass auf dich auf. {Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougAsksWhetherCallerWasJoanna[] =
        "War das Joanna?{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyExplainsMayWaitsForJoanna[] =
        "..Ja...{Press}\p"
        "May wartet jeden Tag,\r\n"
        "dass sie nach Hause{Press}\r\n"
        "kommt, aber sie \r\n"
        "kommt nicht...!{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougSuggestsJoannaHasReasons[] =
        "Sie hat bestimmt Gründe.{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyQuestionsPriorityOverDaughter[] =
        "Kann es etwas Wichtigeres\r\n"
        "geben als ihre eigene\r\n"
        "Tochter?!{Press}\p"
        "Arme May...{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougRecallsJoannaLeavingMayWithBarley[] =
        "Ich weiß noch...\r\n"
        "Sie war für lange Zeit \r\n"
        "verschwunden, und als sie {Press}\r\n"
        "schließlich zurückkam,\r\n"
        "hat sie May bei dir \r\n"
        "gelassen und ist wieder weg!{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyExplainsJoannaHandlesProblemsAlone[] =
        "Joanna ist immer so\r\n"
        "gewesen. Sie versucht, alles{Press}\p"
        "allein zu lösen. {Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyCondemnsJoannaForAbandoningMayWithoutExplanation[] =
        "Diesmal kann ich ihr \r\n"
        "trotzdem nicht verzeihen!{Press}\p"
        "May bei mir zu lassen und \r\n"
        "in die Stadt zu gehen...\r\n"
        "ohne mir zu sagen, warum!{Press}\p"
        "May versucht tapfer zu \r\n"
        "sein, aber sie vermisst \r\n"
        "ihre Mama. {Press}\p"
        "Das macht mich so sauer...!!{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_DougNotesMayStillNeedsMother[] =
        "Sie ist immer noch in \r\n"
        "dem Alter, wo sie ihre\r\n"
        "Mutter braucht, oder...?{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyQuestionsJoannasUnfinishedBusiness[] =
        "Joanna sagt immer, sie \r\n"
        "hat andere Dinge, um die\r\n"
        "sie sich kümmern muss...{Press}\p"
        "Was könnte das sein!?{Press}";

    const char gText_NPCEvent_BarleyAndDoug_DiscussJoannasPhoneCall_BarleyPlansToCookMaysFavoriteAndLeaves[] =
        "Ich mache heute Mays\r\n"
        "Lieblingsspeise. \r\n"
        "Tschüss dann.{Press}";
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
