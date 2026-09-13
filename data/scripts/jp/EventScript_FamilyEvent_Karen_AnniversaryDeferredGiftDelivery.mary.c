#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_AnniversaryDeferredGiftDelivery_GiftDelivery[] =
        "はい、{NickName}。{Press}";

    const char gText_FamilyEvent_Karen_AnniversaryDeferredGiftDelivery_HandsOccupiedReminder[] =
        "プレゼントあげるから、\r\n"
        "手に持ってる物しまってね。{Press}";
};

void EventScript_FamilyEvent_Karen_AnniversaryDeferredGiftDelivery(void)
{
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    if (IsPlayerHoldingNothing())
    {
        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
        TalkMessage(gText_FamilyEvent_Karen_AnniversaryDeferredGiftDelivery_GiftDelivery);
        TalkClose();
        SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_GESTURE);
        WaitFrames(60);
        SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
        PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
        SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        WaitFrames(60);
        VarSet(VAR_KAREN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        DisableScriptedNpcControl();
        ClearEntityEventScript(ENTITY_KAREN);
        if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
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
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        TalkMessage(gText_FamilyEvent_Karen_AnniversaryDeferredGiftDelivery_HandsOccupiedReminder);
        TalkClose();
    }
    MarkNpcSpokenTo(CHARACTER_KAREN);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
}
