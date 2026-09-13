#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_SpouseCollapseRecovery_ElliBlamesPoorHealthManagement[] =
        "I'm ashamed that I haven't \r\n"
        "been taking sufficient care\r\n"
        "of my health...!{Press}";

    const char gText_FamilyEvent_Elli_SpouseCollapseRecovery_ElliPlansToRestForDay[] =
        "I think I'll just sleep for \r\n"
        "the rest of the day. \r\n"
        "Good night.{Press}";
};

void EventScript_FamilyEvent_Elli_SpouseCollapseRecovery(void)
{
    ChangeMap(MAP_FARMHOUSE, X(448), Y(100));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(448), Y(100), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLI, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IN_BED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IN_BED_AWAKE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_SpouseCollapseRecovery_ElliBlamesPoorHealthManagement);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
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
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_SpouseCollapseRecovery_ElliPlansToRestForDay);
    TalkClose();
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_SETTLE_IN_BED);
    WaitFrames(60);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
    VarSet(VAR_ELLI_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    RefreshAllNpcSchedules();
}
