#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_AnniversaryGiftDelivery_GiftDelivery[] =
        "はい。{Press}";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryGiftDelivery_HandsOccupiedReminder[] =
        "プレゼントあげるから、\r\n"
        "手に持ってる物しまってね。{Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_AnniversaryGiftDelivery(void)
{
    SetEntityFacing(ENTITY_HARVEST_GODDESS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    if (IsPlayerHoldingNothing())
    {
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        TalkMessage(gText_FamilyEvent_HarvestGoddess_AnniversaryGiftDelivery_GiftDelivery);
        TalkClose();
        SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_HAND_OVER_ITEM);
        WaitFrames(60);
        SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_IDLE);
        PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
        SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        WaitFrames(60);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_HARVEST_GODDESS)), Y(GetEntityY(ENTITY_HARVEST_GODDESS) + 2), FACING_DOWN);
        SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
        HideEntity(ENTITY_HARVEST_GODDESS);
        WaitFrames(30);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        WaitFrames(60);
        VarSet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        DisableScriptedNpcControl();
        ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
        if (VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
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
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
        TalkMessage(gText_FamilyEvent_HarvestGoddess_AnniversaryGiftDelivery_HandsOccupiedReminder);
        TalkClose();
    }
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_DOWN);
}
