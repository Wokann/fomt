#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_SpouseCollapseRecovery_KarenFeelsAshamedByUnexpectedCollapse[] =
        "This has never happened to \r\n"
        "me before...I'm so ashamed!{Press}";

    const char gText_FamilyEvent_Karen_SpouseCollapseRecovery_KarenPlansToRestForNight[] =
        "I think I'm going to hit the\r\n"
        "sack early tonight, \r\n"
        "{NickName}.{Press}";
};

void EventScript_FamilyEvent_Karen_SpouseCollapseRecovery(void)
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
    SetEntityPosition(ENTITY_KAREN, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IN_BED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IN_BED_AWAKE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_SpouseCollapseRecovery_KarenFeelsAshamedByUnexpectedCollapse);
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
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_SpouseCollapseRecovery_KarenPlansToRestForNight);
    TalkClose();
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_SETTLE_IN_BED);
    WaitFrames(60);
    MarkNpcSpokenTo(CHARACTER_KAREN);
    AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
    VarSet(VAR_KAREN_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    RefreshAllNpcSchedules();
}
