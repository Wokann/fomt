#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriRevealsSurprise[] =
        "I have a surprise for you,\r\n"
        "{NickName}!{Press}";

    const char gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriCallsChildToShowPlayer[] =
        "Come here and show\r\n"
        "us, {Baby}.{Press}";

    const char gText_FamilyEvent_Popuri_ChildFirstSteps_ChildBabblesBeforeWalking[] =
        "Goo-goo.{Press}";

    const char gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriCelebratesChildsFirstSteps[] =
        "Can you believe that?{Press}";

    const char gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriSaysChildStartedWalkingThatMorning[] =
        "He started walking just this\r\n"
        "morning! I almost cried!{Press}";

    const char gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriMarvelsAtChildGrowingQuickly[] =
        "They just grow up so \r\n"
        "quickly!{Press}";
};

void EventScript_FamilyEvent_Popuri_ChildFirstSteps(void)
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
    SetEntityPosition(ENTITY_POPURI, X(360), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_CHILD, X(180), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriRevealsSurprise);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    TalkMessage(gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriCallsChildToShowPlayer);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
    TalkMessage(gText_FamilyEvent_Popuri_ChildFirstSteps_ChildBabblesBeforeWalking);
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
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriCelebratesChildsFirstSteps);
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
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriSaysChildStartedWalkingThatMorning);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_ChildFirstSteps_PopuriMarvelsAtChildGrowingQuickly);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_POPURI);
    MarkNpcSpokenTo(CHARACTER_CHILD);
    AddCharacterLove(CHARACTER_POPURI, 3000);
    AddNpcFriendship(CHARACTER_CHILD, 20);
    VarSet(VAR_CHILD_CAN_WALK, CHILD_WALKING_CAN_WALK);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_POPURI, EventScript_FamilyEvent_Popuri_ChildFirstSteps_FollowupPopuriDialogue);
    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Popuri_ChildFirstSteps_FollowupChildDialogue);
    VarSet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
}
