#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0745_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery.mary.h"

void EventScript_0745_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery(void)
{
    ChangeMap(MAP_ELLEN_HOUSE, X(129), Y(120));
    SetEntityPosition(ENTITY_ELLEN, X(128), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(150), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_STU, X(185), Y(103), FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(129), Y(120), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliGreetsPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuGreetsPlayerEnthusiastically);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenInvitesPlayerToStay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliAsksAboutFarmWork);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenAdmiresPlayerRunningFarmAlone);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliSaysSheCanLearnFromPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenPraisesElliStudyingMedicineOnDayOff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuPraisesHisSister);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliModestlyDismissesPraise);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliRemembersBookToReturnToDoctor);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_ELLI, Y(68), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliFindsLetterInsideMedicalBook);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenAsksWhatElliFound);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliExplainsLetterIsAddressedToEllen);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenReactsInSurprise);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_ELLI, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliIdentifiesLetterFromGrandfather);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuReactsToGrandfathersLetter);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliAsksEllenToReadLetter);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenBeginsReadingLetter);
    TalkClose();
    TalkOpen();
    TalkMessageSlow(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_GrandfathersHiddenLetterWrittenOnEllisBirthDay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliLearnsLetterWasWrittenOnHerBirthDay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenTreasuresLateHusbandsWrittenFeelings);
    TalkClose();
    AddNpcFriendship(CHARACTER_STU, 20);
    AddNpcFriendship(CHARACTER_ELLI, 20);
    AddNpcFriendship(CHARACTER_ELLEN, 20);
    MarkNpcSpokenTo(CHARACTER_STU);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    MarkNpcSpokenTo(CHARACTER_ELLEN);
    EnableScriptedNpcControl();
    VarSet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_ELLEN, EventScript_0746_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue);
    SetEntityEventScript(ENTITY_ELLI, EventScript_0747_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupElliDialogue);
    SetEntityEventScript(ENTITY_STU, EventScript_0748_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupStuDialogue);
}
