#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_OpeningQuestion[] =
        "{Player}, \r\n"
        "Do you know what day it \r\n"
        "is today? {Press}";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_HarvestGoddessBirthdayChoice[] =
        "Your birthday";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_WeddingAnniversaryChoice[] =
        "Our anniversary";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_PlayerBirthdayChoice[] =
        "My birthday";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_IncorrectHarvestGoddessBirthdayResponse[] =
        "My birthday? \r\n"
        "Hmm...\r\n"
        "Bye now.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_CorrectAnniversaryResponse[] =
        "I didn't think you'd forget.\r\n"
        "Here's a present for you. {Press}";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_ImmediateGiftDelivery[] =
        "Here you are. {Press}";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_HandsOccupiedDeferredGiftPrompt[] =
        "I'm going to give you a \r\n"
        "present now, so get rid \r\n"
        "of what you're holding. {Press}";

    const char gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_IncorrectPlayerBirthdayResponse[] =
        "Your birthday? \r\n"
        "Hmm...\r\n"
        "Bye now.{Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice(void)
{
    int var_0;
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
    TalkMessage(gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_OpeningQuestion);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice3(gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_HarvestGoddessBirthdayChoice, gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_WeddingAnniversaryChoice, gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_PlayerBirthdayChoice);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
            TalkMessage(gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_IncorrectHarvestGoddessBirthdayResponse);
            TalkClose();
            VarSet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
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
            WaitFrames(60);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            TalkMessage(gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_CorrectAnniversaryResponse);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            if (IsPlayerHoldingNothing())
            {
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                TalkMessage(gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_ImmediateGiftDelivery);
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
                WaitFrames(60);
                VarSet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
                SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                TalkMessage(gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_HandsOccupiedDeferredGiftPrompt);
                TalkClose();
                EnableScriptedNpcControl();
                SetEntityEventScript(ENTITY_HARVEST_GODDESS, EventScript_FamilyEvent_HarvestGoddess_AnniversaryGiftDelivery);
                if (VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                {
                    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_HarvestGoddess_ChildPreWalkingInteraction);
                }
                VarSet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            }
            break;
        case CHOICE_OPTION_3:
            AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
            TalkMessage(gText_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice_IncorrectPlayerBirthdayResponse);
            TalkClose();
            VarSet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
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
            WaitFrames(60);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
    }
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
}
