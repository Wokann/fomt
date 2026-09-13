#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_WorkCompletionPrompt[] =
        "Bist du mit der \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoiceFinishedWork[] =
        "Ja";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoiceStillWorking[] =
        "Nein";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_DateQuestion[] =
        "Weißt du, welcher Tag \r\n"
        "heute ist?{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoicePlayerBirthday[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoiceHarvestGoddessBirthday[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoiceChildBirthday[] =
        "{Baby}s Geburtstag";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_IncorrectPlayerBirthdayResponse[] =
        "Dein Geburtstag? \r\n"
        "Hmm...\r\n"
        "Tschüss dann.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_PlayerRegretsIncorrectAnswer[] =
        "Ich entschuldige mich \r\n"
        "besser später. {Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_IncorrectHarvestGoddessBirthdayResponse[] =
        "Mein Geburtstag? \r\n"
        "Hmm...\r\n"
        "Tschüss dann.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_CorrectChildBirthdayResponseAndMeal[] =
        "Ich wusste, du würdest \r\n"
        "es nicht vergessen! \r\n"
        "Hier, ich habe ein{Press}\r\n"
        "Spezialgericht gekocht.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_HarvestGoddessWondersIfChildWillFly[] =
        "Ob {Baby} wohl auch\r\n"
        "so fliegen kann wie ich,\r\n"
        "wenn er älter wird...?{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_PlayerReflectsOnCelebration[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_StillWorkingResponse[] =
        "Beeil dich und werde\r\n"
        "fertig mit der Arbeit. {Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_HARVEST_GODDESS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_WorkCompletionPrompt);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoiceFinishedWork, gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoiceStillWorking);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_DateQuestion);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoicePlayerBirthday, gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoiceHarvestGoddessBirthday, gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_ChoiceChildBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_IncorrectPlayerBirthdayResponse);
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
                    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_PlayerRegretsIncorrectAnswer);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_HARVEST_GODDESS, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_IncorrectHarvestGoddessBirthdayResponse);
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
                    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_PlayerRegretsIncorrectAnswer);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_CorrectChildBirthdayResponseAndMeal);
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
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_HarvestGoddessWondersIfChildWillFly);
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
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_PlayerReflectsOnCelebration);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
            TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayDateChoice_StillWorkingResponse);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_DOWN);
}
