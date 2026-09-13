#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_ChildFirstSteps_ElliRevealsSurprise[] =
        "Ich möchte dir gerne \r\n"
        "etwas zeigen!{Press}";

    const char gText_FamilyEvent_Elli_ChildFirstSteps_ElliCallsChildToShowPlayer[] =
        "Komm zu mir, \r\n"
        "{Baby}.{Press}";

    const char gText_FamilyEvent_Elli_ChildFirstSteps_ChildCallsPlayerBeforeWalking[] =
        "Da-da.{Press}";

    const char gText_FamilyEvent_Elli_ChildFirstSteps_ElliCelebratesFirstSteps[] =
        "Ist das nicht toll!?{Press}";

    const char gText_FamilyEvent_Elli_ChildFirstSteps_ElliSaysChildTookFirstStepsThatDay[] =
        "Er hat heute seine \r\n"
        "ersten Schritte gemacht.\r\n"
        "Er ist weit für{Press}\p"
        "sein Alter. Reif, wie du!{Press}";

    const char gText_FamilyEvent_Elli_ChildFirstSteps_ElliMarvelsAtChildsGrowth[] =
        "Oder denken alle Eltern,\r\n"
        "ihr Kind ist das Klügste?{Press}";
};

void EventScript_FamilyEvent_Elli_ChildFirstSteps(void)
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
    SetEntityPosition(ENTITY_ELLI, X(360), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_CHILD, X(180), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_ChildFirstSteps_ElliRevealsSurprise);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    TalkMessage(gText_FamilyEvent_Elli_ChildFirstSteps_ElliCallsChildToShowPlayer);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
    TalkMessage(gText_FamilyEvent_Elli_ChildFirstSteps_ChildCallsPlayerBeforeWalking);
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
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_ChildFirstSteps_ElliCelebratesFirstSteps);
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
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_ChildFirstSteps_ElliSaysChildTookFirstStepsThatDay);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_ChildFirstSteps_ElliMarvelsAtChildsGrowth);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ELLI);
    MarkNpcSpokenTo(CHARACTER_CHILD);
    AddCharacterLove(CHARACTER_ELLI, 3000);
    AddNpcFriendship(CHARACTER_CHILD, 20);
    VarSet(VAR_CHILD_CAN_WALK, CHILD_WALKING_CAN_WALK);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_ELLI, EventScript_FamilyEvent_Elli_ChildFirstSteps_FollowupElliDialogue);
    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Elli_ChildFirstSteps_FollowupChildDialogue);
    VarSet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
}
