#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_SpouseCollapseRecovery_AnnLamentsUnexpectedCollapse[] =
        "Ich fasse nicht, dass ich \r\n"
        "zusammengebrochen bin!\r\n"
        "Ich werde nie krank!{Press}";

    const char gText_FamilyEvent_Ann_SpouseCollapseRecovery_AnnPlansToSleepAndRecover[] =
        "Ich glaube, ich geh\r\n"
        "früh schlafen und \r\n"
        "fühle mich morgen besser.{Press}";
};

void EventScript_FamilyEvent_Ann_SpouseCollapseRecovery(void)
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
    SetEntityPosition(ENTITY_ANN, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IN_BED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IN_BED_AWAKE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_SpouseCollapseRecovery_AnnLamentsUnexpectedCollapse);
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
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_SpouseCollapseRecovery_AnnPlansToSleepAndRecover);
    TalkClose();
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_SETTLE_IN_BED);
    WaitFrames(60);
    MarkNpcSpokenTo(CHARACTER_ANN);
    AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
    VarSet(VAR_ANN_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    RefreshAllNpcSchedules();
}
