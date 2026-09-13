#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnPleadsWithDougAndDukeToStop[] =
        "Dad, please stop it now!{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DougTellsAnnToStayOut[] =
        "You shut up!{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeTellsAnnNotToIntervene[] =
        "Don't try to stop me, Ann!{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnAsksPlayerToStopFight[] =
        "{Player}! Please \r\n"
        "stop this fight for me!{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_ChoiceInterveneToStopFight[] =
        "Stop the fight.";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_ChoiceDoNotIntervene[] =
        "Don't intervene.";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnThanksPlayerForIntervening[] =
        "Thank you so much! . {Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DougTellsPlayerFightIsNoneOfTheirBusiness[] =
        "This is none of your\r\n"
        "business, {Player}!{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeOrdersPlayerOutOfWay[] =
        "Get out of my way, \r\n"
        "{Player}! {Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DougAsksWhatFightWasAbout[] =
        "Now what were we\r\n"
        "fighting about...?{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeTriesToRecallCause[] =
        "It was...umm...{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DougCannotRememberCause[] =
        "......I forget...{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeCannotRememberWhyHeWasAngry[] =
        "Now why was I so mad...?{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnScoldsDougAndDukeForForgettingCause[] =
        "I can't believe you two \r\n"
        "old men can't even remember\r\n"
        "what you're fighting over!{Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DougApologizesAndPromisesToStopFighting[] =
        "Sorry, {Player}. \r\n"
        "We won't fight any more. {Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeConfirmsFightEnded[] =
        "Yes, it's over now. {Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnThanksPlayerAndPromisesToWatchDoug[] =
        "Thanks for helping out, \r\n"
        "{Player}. {Press}\p"
        "I'll try to keep a handle \r\n"
        "on Dad from now on. {Press}";

    const char gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnRebukesPlayerForRefusingHelp[] =
        "I knew I shouldn't count on \r\n"
        "you, {Player}!{Press}";
};

void EventScript_NPCEvent_DougAndDuke_ArgumentChoice(void)
{
    int var_0;
    EnableScriptedNpcControl();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_DOUG, X(174), Y(136), FACING_RIGHT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(194), Y(136), FACING_LEFT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_ANN, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(80), Y(224), FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_HARRIS, X(16), Y(184), FACING_RIGHT);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_ANGRY, TRUE);
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_ANGRY, TRUE);
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_THINKING, TRUE);
    PanCameraTo(X(184), Y(128), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    MoveEntityYTo(ENTITY_PLAYER, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnPleadsWithDougAndDukeToStop);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DougTellsAnnToStayOut);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeTellsAnnNotToIntervene);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(196), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RUN_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(136), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_PLAYER, Y(120), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    StopEntityEffect(ENTITY_ANN);
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_POPURI);
    }
    TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnAsksPlayerToStopFight);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_DougAndDuke_ArgumentChoice_ChoiceInterveneToStopFight, gText_NPCEvent_DougAndDuke_ArgumentChoice_ChoiceDoNotIntervene);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnThanksPlayerForIntervening);
            TalkClose();
            SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
            MoveEntityXTo(ENTITY_ANN, X(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RUN_HOLDING_ITEM);
            }
            MoveEntityXTo(ENTITY_PLAYER, X(184), ENTITY_MOVE_SPEED_3_PIXELS_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            SetEntityFacing(ENTITY_ANN, FACING_DOWN);
            MoveEntityYTo(ENTITY_PLAYER, Y(128), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
            MoveEntityXTo(ENTITY_DOUG, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            MoveEntityXTo(ENTITY_DUKE, X(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DougTellsPlayerFightIsNoneOfTheirBusiness);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeOrdersPlayerOutOfWay);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
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
            SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DougAsksWhatFightWasAbout);
            StopEntityEffect(ENTITY_DOUG);
            StopEntityEffect(ENTITY_DUKE);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeTriesToRecallCause);
            TalkClose();
            StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_QUESTION, FALSE);
            StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_QUESTION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DougCannotRememberCause);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeCannotRememberWhyHeWasAngry);
            TalkClose();
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnScoldsDougAndDukeForForgettingCause);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DougApologizesAndPromisesToStopFighting);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_DukeConfirmsFightEnded);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnThanksPlayerAndPromisesToWatchDoug);
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
            AddCharacterLove(CHARACTER_ANN, 3000);
            AddNpcFriendship(CHARACTER_THOMAS, 20);
            AddNpcFriendship(CHARACTER_HARRIS, 20);
            AddNpcFriendship(CHARACTER_DOUG, 20);
            AddNpcFriendship(CHARACTER_DUKE, 20);
            VarSet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE, DOUG_DUKE_ARGUMENT_STOP_FIGHT);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            TalkMessage(gText_NPCEvent_DougAndDuke_ArgumentChoice_AnnRebukesPlayerForRefusingHelp);
            TalkClose();
            SetEntityFacing(ENTITY_ANN, FACING_DOWN);
            StopEntityEffect(ENTITY_DOUG);
            StopEntityEffect(ENTITY_DUKE);
            AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_THOMAS, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_HARRIS, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_DOUG, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_DUKE, mary_negated_int(-10));
            VarSet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE, DOUG_DUKE_ARGUMENT_DO_NOT_INTERVENE);
            break;
    }
    MarkNpcSpokenTo(CHARACTER_ANN);
    MarkNpcSpokenTo(CHARACTER_DOUG);
    MarkNpcSpokenTo(CHARACTER_DUKE);
    if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE) == DOUG_DUKE_ARGUMENT_STOP_FIGHT)
    {
        PanCameraTo(X(184), Y(128), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    }
    else
    {
        PanCameraTo(X(136), Y(120), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    }
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    VarSet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_ANN, EventScript_NPCEvent_DougAndDuke_Argument_FollowupAnnDialogue);
    SetEntityEventScript(ENTITY_DOUG, EventScript_NPCEvent_DougAndDuke_Argument_FollowupDougDialogue);
    SetEntityEventScript(ENTITY_DUKE, EventScript_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue);
    SetEntityEventScript(ENTITY_HARRIS, EventScript_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue);
    return;
}
