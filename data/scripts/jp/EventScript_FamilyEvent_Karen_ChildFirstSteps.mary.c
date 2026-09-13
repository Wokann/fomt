#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_ChildFirstSteps_KarenRevealsSurprise[] =
        "{NickName}！！\r\n"
        "{Baby}が大変よ！{Press}";

    const char gText_FamilyEvent_Karen_ChildFirstSteps_KarenCallsChildToShowPlayer[] =
        "{Baby}くん。\r\n"
        "おいで。{Press}";

    const char gText_FamilyEvent_Karen_ChildFirstSteps_ChildBabblesBeforeWalking[] =
        "だぁ。{Press}";

    const char gText_FamilyEvent_Karen_ChildFirstSteps_KarenCelebratesFirstSteps[] =
        "ビックリした？{Press}";

    const char gText_FamilyEvent_Karen_ChildFirstSteps_KarenSaysChildStartedWalkingThatMorning[] =
        "こっちだってビックリした\r\n"
        "わよ。昨日まで歩かなかった\r\n"
        "のに、急に歩き出すんだから。{Press}";

    const char gText_FamilyEvent_Karen_ChildFirstSteps_KarenMarvelsAtChildGrowingQuickly[] =
        "子供って、成長がはやいね。\r\n"
        "はやく大きくならないかな？{Press}";
};

void EventScript_FamilyEvent_Karen_ChildFirstSteps(void)
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
    SetEntityPosition(ENTITY_KAREN, X(360), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_CHILD, X(180), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_ChildFirstSteps_KarenRevealsSurprise);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    TalkMessage(gText_FamilyEvent_Karen_ChildFirstSteps_KarenCallsChildToShowPlayer);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
    TalkMessage(gText_FamilyEvent_Karen_ChildFirstSteps_ChildBabblesBeforeWalking);
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
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_ChildFirstSteps_KarenCelebratesFirstSteps);
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
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_ChildFirstSteps_KarenSaysChildStartedWalkingThatMorning);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_ChildFirstSteps_KarenMarvelsAtChildGrowingQuickly);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_KAREN);
    MarkNpcSpokenTo(CHARACTER_CHILD);
    AddCharacterLove(CHARACTER_KAREN, 3000);
    AddNpcFriendship(CHARACTER_CHILD, 20);
    VarSet(VAR_CHILD_CAN_WALK, CHILD_WALKING_CAN_WALK);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_KAREN, EventScript_FamilyEvent_Karen_ChildFirstSteps_FollowupKarenDialogue);
    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Karen_ChildFirstSteps_FollowupChildDialogue);
    VarSet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
}
