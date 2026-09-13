#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_AnniversaryDeferredGiftDelivery_GiftDelivery[] =
        "はい、あげる。{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDeferredGiftDelivery_HandsOccupiedReminder[] =
        "プレゼントあげるから、\r\n"
        "手に持ってる物しまってね。{Press}";
};

void EventScript_FamilyEvent_Ann_AnniversaryDeferredGiftDelivery(void)
{
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    ShowTalkHeartIndicator(CHARACTER_ANN);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    if (IsPlayerHoldingNothing())
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
        TalkMessage(gText_FamilyEvent_Ann_AnniversaryDeferredGiftDelivery_GiftDelivery);
        TalkClose();
        SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_GESTURE);
        WaitFrames(60);
        SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
        PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
        SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        WaitFrames(60);
        VarSet(VAR_ANN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        DisableScriptedNpcControl();
        ClearEntityEventScript(ENTITY_ANN);
        if (VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
        {
            ClearEntityEventScript(ENTITY_CHILD);
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
        SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
        TalkMessage(gText_FamilyEvent_Ann_AnniversaryDeferredGiftDelivery_HandsOccupiedReminder);
        TalkClose();
    }
    MarkNpcSpokenTo(CHARACTER_ANN);
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}
