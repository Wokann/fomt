#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessNotesChildNotYetStanding[] =
        "Hm? I thought that it was\r\n"
        "time {Baby} started\r\n"
        "standing, but I guess {Press}\r\n"
        "I was wrong. {Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessOffersWalkingAssistance[] =
        "I'll give him some\r\n"
        "help!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessCastsWalkingSpell[] =
        "Hhhrrr...\r\n"
        "Waaa!!....{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessCelebratesChildStanding[] =
        "There you go, \r\n"
        "{Baby}. \r\n"
        "You're standing!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_ChildRespondsAfterStanding[] =
        "Goo!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessDepartsAfterTeachingChildToStand[] =
        "Well, now that \r\n"
        "{Baby} is \r\n"
        "standing, I'll be off. {Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_ChildFirstSteps(void)
{
    ChangeMap(MAP_FARMHOUSE, X(332), Y(124));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(332), Y(124), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_CHILD, X(364), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER) + 16), Y(GetEntityY(ENTITY_PLAYER) + 24), FACING_DOWN);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    SetEntityPosition(ENTITY_HARVEST_GODDESS, X(348), Y(148), FACING_UP);
    SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessNotesChildNotYetStanding);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessOffersWalkingAssistance);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessCastsWalkingSpell);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_CHILD)), Y(GetEntityY(ENTITY_CHILD) + 2), FACING_DOWN);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    WaitFrames(60);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessCelebratesChildStanding);
    TalkClose();
    WaitFrames(30);
    SetEntityFacing(ENTITY_CHILD, FACING_DOWN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_ChildRespondsAfterStanding);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildFirstSteps_HarvestGoddessDepartsAfterTeachingChildToStand);
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
    AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
    AddNpcFriendship(CHARACTER_CHILD, 20);
    VarSet(VAR_CHILD_CAN_WALK, CHILD_WALKING_CAN_WALK);
    WaitFrames(60);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_HarvestGoddess_ChildPostFirstStepsInteraction);
    VarSet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
}
