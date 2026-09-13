#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_WorkCompletionPrompt[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceFinishedWork[] =
        "Yes";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceStillWorking[] =
        "No";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_DateQuestion[] =
        "{Player}, \r\n"
        "Do you know what day it \r\n"
        "is today? {Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceWeddingAnniversary[] =
        "Our anniversary";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoicePlayerBirthday[] =
        "My anniversary";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceHarvestGoddessBirthday[] =
        "Your birthday";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectWeddingAnniversaryResponse[] =
        "Our anniversary? \r\n"
        "Hmm...\r\n"
        "Bye now.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerRegretsIncorrectAnswer[] =
        "I better apologize later on.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_CorrectPlayerBirthdayResponse[] =
        "That's right!\r\n"
        "Congratulations!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_HarvestGoddessDiscussesFutureChild[] =
        "I can't wait to have kids...!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerReflectsOnCelebration[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectHarvestGoddessBirthdayResponse[] =
        "My birthday? \r\n"
        "Hmm...\r\n"
        "Bye now.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoicePlayerBirthdayWithChild[] =
        "My birthday";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceChildBirthday[] =
        "{Baby}'s birthday";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_HarvestGoddessCelebratesPlayerMaturity[] =
        "You are now a grown man.\r\n"
        "Although, you still look \r\n"
        "more like a baby to me...{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectChildBirthdayResponse[] =
        "{Baby}'s birthday? \r\n"
        "Hmm...\r\n"
        "Bye now.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_StillWorkingResponse[] =
        "Hurry up and finish work. {Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_HARVEST_GODDESS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_WorkCompletionPrompt);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceFinishedWork, gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceStillWorking);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
            TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_DateQuestion);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceWeddingAnniversary, gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoicePlayerBirthday, gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceHarvestGoddessBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectWeddingAnniversaryResponse);
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
                        WaitFrames(60);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerRegretsIncorrectAnswer);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_CorrectPlayerBirthdayResponse);
                        TalkClose();
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
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
                        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_HarvestGoddessDiscussesFutureChild);
                        TalkClose();
                        WaitFrames(60);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerReflectsOnCelebration);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectHarvestGoddessBirthdayResponse);
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
                        WaitFrames(60);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerRegretsIncorrectAnswer);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoicePlayerBirthdayWithChild, gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceHarvestGoddessBirthday, gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceChildBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_CorrectPlayerBirthdayResponse);
                        TalkClose();
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
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
                        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_HarvestGoddessCelebratesPlayerMaturity);
                        TalkClose();
                        WaitFrames(60);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerReflectsOnCelebration);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectHarvestGoddessBirthdayResponse);
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
                        WaitFrames(60);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerRegretsIncorrectAnswer);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectChildBirthdayResponse);
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
                        WaitFrames(60);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerRegretsIncorrectAnswer);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
            TalkMessage(gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_StillWorkingResponse);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_DOWN);
}
