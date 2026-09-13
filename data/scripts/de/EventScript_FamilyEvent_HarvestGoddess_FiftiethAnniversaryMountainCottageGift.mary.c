#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_FiftiethAnniversaryMountainCottageGift_Announcement[] =
        "Guten Morgen, {Player}.\r\n"
        "Heute ist ein \r\n"
        "besonderer Tag. Es ist\r\n"
        "unser 50. Hochzeitstag. {Press}\p"
        "Ich habe dir als\r\n"
        "Geschenk eine Hütte in\r\n"
        "den Bergen gekauft.{Press}\p"
        "Wie ich das bezahlt habe?\r\n"
        "Denk nicht darüber nach!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_FiftiethAnniversaryMountainCottageGift_VisitSuggestion[] =
        "Geh später mal hin\r\n"
        "und sieh sie dir an.{Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_FiftiethAnniversaryMountainCottageGift(void)
{
    ChangeMap(MAP_FARMHOUSE, X(265), Y(138));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(265), Y(138), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    if (VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
        {
            SetEntityPosition(ENTITY_CHILD, X(292), Y(84), FACING_DOWN);
            if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
            }
            else
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
            }
        }
        else
        {
            SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_INFANT_SLEEPING);
        }
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_HARVEST_GODDESS_FIFTIETH_ANNIVERSARY_GIFT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) - 24), FACING_DOWN);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    SetEntityPosition(ENTITY_HARVEST_GODDESS, X(265), Y(114), FACING_DOWN);
    SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_FiftiethAnniversaryMountainCottageGift_Announcement);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_FiftiethAnniversaryMountainCottageGift_VisitSuggestion);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_HARVEST_GODDESS)), Y(GetEntityY(ENTITY_HARVEST_GODDESS) + 4), FACING_DOWN);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    HideEntity(ENTITY_HARVEST_GODDESS);
    WaitFrames(30);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_HARVEST_GODDESS_FIFTIETH_ANNIVERSARY_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    BuildMountainCottage();
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
    SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
