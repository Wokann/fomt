#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0794_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument.mary.h"

void EventScript_0794_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ANN, X(124), Y(192), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(104), Y(192), FACING_RIGHT);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(114), Y(192), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffCriticizesAnnForNotActingFeminine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnDefendsHerPersonality);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffComparesAnnToHisSister);
    TalkClose();
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnObjectsToComparisonAndQuestionsCliffsLove);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffSaysHePaysAttentionToAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnSaysLoveMeansAcceptingHerAsSheIs);
    TalkClose();
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnDemandsCliffStopComparingHerToHisSister);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffApologizesForHurtingAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnApologizesForOverreacting);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnPromisesToTryActingMoreFeminine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffAcceptsAnnPromise);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_UP);
    SetEntityFacing(ENTITY_CLIFF, FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(72), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_CLIFF, Y(72), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    HideEntity(ENTITY_ANN);
    HideEntity(ENTITY_CLIFF);
    PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_ANN_AND_CLIFF_SIBLING_COMPARISON_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
