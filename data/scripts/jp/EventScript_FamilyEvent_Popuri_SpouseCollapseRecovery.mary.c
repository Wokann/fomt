#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_SpouseCollapseRecovery_PopuriAdmitsOverworkCausedCollapse[] =
        "あ～あ、つまんないなぁ。\r\n"
        "たおれるまで気がつかないなん\r\n"
        "て、ポプリってバカだよねぇ？{Press}";

    const char gText_FamilyEvent_Popuri_SpouseCollapseRecovery_PopuriPlansToSleepAndRecover[] =
        "明日にはよくなると思うから。\r\n"
        "何だか、ねむくなっちゃった。{Press}";
};

void EventScript_FamilyEvent_Popuri_SpouseCollapseRecovery(void)
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
    SetEntityPosition(ENTITY_POPURI, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IN_BED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_REACTION);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_SpouseCollapseRecovery_PopuriAdmitsOverworkCausedCollapse);
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
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_SpouseCollapseRecovery_PopuriPlansToSleepAndRecover);
    TalkClose();
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_SETTLE_IN_BED);
    WaitFrames(60);
    MarkNpcSpokenTo(CHARACTER_POPURI);
    AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
    VarSet(VAR_POPURI_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    RefreshAllNpcSchedules();
}
