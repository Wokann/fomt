#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_AnniversaryDeferredGiftDelivery_GiftDelivery[] =
        "Here you are, {NickName}.{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDeferredGiftDelivery_HandsOccupiedReminder[] =
        "I'm going to give you a \r\n"
        "present, so empty your \r\n"
        "hands, OK?{Press}";
};

void EventScript_FamilyEvent_Mary_AnniversaryDeferredGiftDelivery(void)
{
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    ShowTalkHeartIndicator(CHARACTER_MARY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    if (IsPlayerHoldingNothing())
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        TalkMessage(gText_FamilyEvent_Mary_AnniversaryDeferredGiftDelivery_GiftDelivery);
        TalkClose();
        SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_GESTURE);
        WaitFrames(60);
        SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
        PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
        SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        WaitFrames(60);
        VarSet(VAR_MARY_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        DisableScriptedNpcControl();
        ClearEntityEventScript(ENTITY_MARY);
        if (VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
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
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        TalkMessage(gText_FamilyEvent_Mary_AnniversaryDeferredGiftDelivery_HandsOccupiedReminder);
        TalkClose();
    }
    MarkNpcSpokenTo(CHARACTER_MARY);
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
}
