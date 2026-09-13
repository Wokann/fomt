#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_ChildFirstSteps_AnnRevealsSurprise[] =
        "今からビックリすることが\r\n"
        "起こると思うよ。{Press}";

    const char gText_FamilyEvent_Ann_ChildFirstSteps_AnnCallsChildToShowPlayer[] =
        "{Baby}ちゃ～ん。\r\n"
        "お父さんに見せてあげて。{Press}";

    const char gText_FamilyEvent_Ann_ChildFirstSteps_ChildBabblesBeforeWalking[] =
        "だぁ。{Press}";

    const char gText_FamilyEvent_Ann_ChildFirstSteps_AnnCelebratesFirstSteps[] =
        "スゴイでしょう？{Press}";

    const char gText_FamilyEvent_Ann_ChildFirstSteps_AnnSaysChildStartedWalkingThatMorning[] =
        "朝、いきなり歩き出したん\r\n"
        "だよ。わたしもビックリ\r\n"
        "したよ。{Press}";

    const char gText_FamilyEvent_Ann_ChildFirstSteps_AnnLooksForwardToWatchingChildGrow[] =
        "わたし、この子の成長が楽しみ\r\n"
        "でしかたがないんだ。{Press}";
};

void EventScript_FamilyEvent_Ann_ChildFirstSteps(void)
{
    ChangeMap(MAP_FARMHOUSE, X(332), Y(124));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(332), Y(124), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ANN, X(360), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_CHILD, X(180), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_ChildFirstSteps_AnnRevealsSurprise);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    TalkMessage(gText_FamilyEvent_Ann_ChildFirstSteps_AnnCallsChildToShowPlayer);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
    TalkMessage(gText_FamilyEvent_Ann_ChildFirstSteps_ChildBabblesBeforeWalking);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_FIRST_STEPS_WALK);
    MoveEntityXTo(ENTITY_CHILD, X(245), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CHILD);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_ChildFirstSteps_AnnCelebratesFirstSteps);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_ChildFirstSteps_AnnSaysChildStartedWalkingThatMorning);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_ChildFirstSteps_AnnLooksForwardToWatchingChildGrow);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ANN);
    MarkNpcSpokenTo(CHARACTER_CHILD);
    AddCharacterLove(CHARACTER_ANN, 3000);
    AddNpcFriendship(CHARACTER_CHILD, 20);
    VarSet(VAR_CHILD_CAN_WALK, CHILD_WALKING_CAN_WALK);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_ANN, EventScript_FamilyEvent_Ann_ChildFirstSteps_FollowupAnnDialogue);
    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Ann_ChildFirstSteps_FollowupChildDialogue);
    VarSet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
}
