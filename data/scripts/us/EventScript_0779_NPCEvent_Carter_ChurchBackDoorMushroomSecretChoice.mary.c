#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0779_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice.mary.h"

void EventScript_0779_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice(void)
{
    int var_0;
    ChangeMap(MAP_CHURCH, X(236), Y(95));
    SetEntityPosition(ENTITY_PLAYER, X(185), Y(212), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    if (GetEntityLocation(ENTITY_CARTER) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CARTER);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(10);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerNoticesCarterMissing);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(309), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(30);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(60), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerFindsChurchBackDoorOpen);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_BEHIND_CHURCH, X(140), Y(115));
    SetEntityPosition(ENTITY_PLAYER, X(140), Y(267), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_CARTER, X(140), Y(76), FACING_UP);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterEnjoysAutumnMushroomGathering);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterWorriesOthersWillDiscoverArea);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(135), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksWhyPlayerFollowed);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerSaysDoorWasOpen);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsGatheringMushrooms);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerNotToJudge);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsBackAreaIsGoodForMushrooms);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerToKeepMushroomSpotSecret);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceKeepSecret, gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceRefuseSecret);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterThanksPlayerForKeepingSecret);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder);
            TalkClose();
            AddNpcFriendship(CHARACTER_CARTER, 20);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
            MoveEntityXTo(ENTITY_CARTER, X(103), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
            MoveEntityYTo(ENTITY_CARTER, Y(253), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            HideEntity(ENTITY_CARTER);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_AFRAID, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAcceptsPlayersRefusalToKeepSecret);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder);
            TalkClose();
            AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
            MoveEntityXTo(ENTITY_CARTER, X(103), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
            MoveEntityYTo(ENTITY_CARTER, Y(253), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            HideEntity(ENTITY_CARTER);
            break;
    }
    PanCameraTo(X(140), Y(135), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    MarkNpcSpokenTo(CHARACTER_CARTER);
    VarSet(VAR_CARTER_CHURCH_BACK_DOOR_MUSHROOM_SECRET_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
}
