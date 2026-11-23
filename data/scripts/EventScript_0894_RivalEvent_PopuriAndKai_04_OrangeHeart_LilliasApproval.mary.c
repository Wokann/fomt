#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0894_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval.mary.h"

void EventScript_0894_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval(void)
{
    ChangeMap(MAP_POULTRY_FARM_HOUSE_1F, X(120), Y(95));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_POPURI, X(200), Y(128), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_KAI, X(176), Y(128), FACING_UP);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_RICK, X(200), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_LILLIA, X(176), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    if (GetEntityLocation(ENTITY_SASHA) == MAP_POULTRY_FARM_HOUSE_1F)
    {
        SetEntityPosition(ENTITY_SASHA, X(64), Y(84), FACING_UP);
        SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiSaysPopuriWantsToMoveToAnotherTownWithHim);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_LILLIA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickAsksWhetherPopuriReallyPlansToLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriConfirmsShePlansToLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaWondersWhatToDoAboutPopurisPlan);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiSaysHeTriedToConvincePopuriToStay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickAccusesKaiOfEncouragingPopuriToLeave);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriSaysLeavingWasHerOwnIdea);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickRefusesToLetPopuriLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriInsistsSheWillLeaveDespiteRicksObjection);
    TalkClose();
    StartEntityEffect(ENTITY_LILLIA, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaAllowsPopuriToLeave);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickChallengesLilliasDecision);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriCelebratesLilliasPermission);
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaExplainsSheWillNotStopTheirDecision);
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaRequiresKaiToMakePopuriHappy);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_AFRAID, FALSE);
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HEART, FALSE);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
#if defined(REGION_JP)
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriReactsToLilliasMarriageCondition);
#else
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriOrRickReactsToLilliasMarriageCondition);
#endif
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiIsSurprisedByLilliasMarriageCondition);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_RICK);
#if defined(REGION_JP)
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickReactsToLilliasMarriageCondition);
#else
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriOrRickReactsToLilliasMarriageCondition);
#endif
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaTellsKaiToConsiderHerCondition);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiLeavesToConsiderLilliasCondition);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityYTo(ENTITY_KAI, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityFacing(ENTITY_KAI, FACING_LEFT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityXTo(ENTITY_KAI, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityYTo(ENTITY_KAI, Y(224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    HideEntity(ENTITY_KAI);
    PanCameraTo(X(120), Y(208), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_RICK, EventScript_0895_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupRickDialogue);
    SetEntityEventScript(ENTITY_POPURI, EventScript_0896_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupPopuriDialogue);
    SetEntityEventScript(ENTITY_LILLIA, EventScript_0897_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupLilliaDialogue);
    VarSet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
