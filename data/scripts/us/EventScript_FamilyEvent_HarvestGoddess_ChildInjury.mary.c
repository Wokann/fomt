#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_PlayerHearsUnseenVoice[] =
        "I think I hear a voice...!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_PlayerReactsToChildCrying[] =
        "!!!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_ChildCriesFromBedFall[] =
        "Waaahh!!!...{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessDiagnosesBedFallInjury[] =
        "Oh dear! \r\n"
        "I see that {Baby}\r\n"
        "has fallen from bed!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessOffersToHealChild[] =
        "Don't worry. \r\n"
        "I'll take care of this. {Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessCastsHealingSpell[] =
        "Hhhrrr...\r\n"
        "Waaa!!....{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessConfirmsChildHealed[] =
        "There you go...\r\n"
        "All fixed!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_ChildRespondsAfterHealing[] =
        "Goo!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessDepartsAfterHealing[] =
        "Now that {Baby}'s\r\n"
        "boo-boo has been healed,\r\n"
        "I' ll be going now. Bye.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildInjury_PlayerReflectsOnHealingPower[] =
        "She really can \r\n"
        "do anything...{Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_ChildInjury(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    ChangeMap(MAP_FARMHOUSE, X(400), Y(100));
    SetEntityPosition(ENTITY_PLAYER, X(400), Y(100), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_CHILD, X(432), Y(100), FACING_LEFT);
    if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
    {
        SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    }
    else
    {
        SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
    }
    TalkOpen();
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_PlayerHearsUnseenVoice);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_BABY_CRY);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_BABY_CRY);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_PlayerReactsToChildCrying);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_ChildCriesFromBedFall);
    TalkClose();
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER) + 16), Y(GetEntityY(ENTITY_PLAYER) + 24), FACING_DOWN);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    SetEntityPosition(ENTITY_HARVEST_GODDESS, X(416), Y(124), FACING_UP);
    SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessDiagnosesBedFallInjury);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessOffersToHealChild);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessCastsHealingSpell);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_CHILD)), Y(GetEntityY(ENTITY_CHILD) + 2), FACING_DOWN);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    WaitFrames(60);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessConfirmsChildHealed);
    TalkClose();
    WaitFrames(30);
    SetEntityFacing(ENTITY_CHILD, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_ChildRespondsAfterHealing);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_HarvestGoddessDepartsAfterHealing);
    TalkClose();
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
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    MarkNpcSpokenTo(CHARACTER_CHILD);
    VarSet(VAR_HARVEST_GODDESS_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildInjury_PlayerReflectsOnHealingPower);
    TalkClose();
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
