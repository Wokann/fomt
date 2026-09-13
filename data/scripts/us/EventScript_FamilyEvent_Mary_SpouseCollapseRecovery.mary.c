#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_SpouseCollapseRecovery_MaryAttributesCollapseToFarmLifeInexperience[] =
        "I guess I'm just not used to\r\n"
        "life on the farm, yet! I'll\r\n"
        "have to study it more...{Press}";

    const char gText_FamilyEvent_Mary_SpouseCollapseRecovery_MaryPlansToRecoverWithMedicineAndRest[] =
        "I took some medicine, so I \r\n"
        "think if I just go to bed\r\n"
        "now I should be alright.{Press}";
};

void EventScript_FamilyEvent_Mary_SpouseCollapseRecovery(void)
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
    SetEntityPosition(ENTITY_MARY, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IN_BED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IN_BED_AWAKE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_SpouseCollapseRecovery_MaryAttributesCollapseToFarmLifeInexperience);
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
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_SpouseCollapseRecovery_MaryPlansToRecoverWithMedicineAndRest);
    TalkClose();
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_SETTLE_IN_BED);
    WaitFrames(60);
    MarkNpcSpokenTo(CHARACTER_MARY);
    AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
    VarSet(VAR_MARY_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    RefreshAllNpcSchedules();
}
