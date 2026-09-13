#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IDontUsuallyBakeCakesBut[] =
        "Ich backe sonst keine \r\n"
        "Kuchen, aber du weißt \r\n"
        "sicher, warum ich es {Press}\p"
        "heute getan habe, oder?{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsMyBirthday[] =
        "Mein Geburtstag.";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsYourBirthday[] =
        "Dein Geburtstag.";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}s Geburtstag.";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouBecomingSenileAlreadyI[] =
        "Wirst du schon senil...?\r\n"
        "Ich hoffe nicht!{Press}\p"
        "Es ist {Baby}s\r\n"
        "Geburtstag, du Dummer!{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich \r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ImFlatteredYoureThinkingOfMe[] =
        "Schmeichelhaft, dass du an\r\n"
        "mich denkst, aber es ist {Press}\r\n"
        "der Geburtstag deines, \r\n"
        "Sohnes, du Dummer!{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_OfCourseYouRememberBabyS[] =
        "Natürlich denkst du\r\n"
        "an {Baby}s Geburtstag!\r\n"
        "Wer vergisst schon den{Press}\r\n"
        "Geburtstag seines Sohnes?!{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IEnjoyWatchingHimGrowUp[] =
        "Ich liebe es zu sehen, wie\r\n"
        "er aufwächst, du nicht?{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ELLI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IDontUsuallyBakeCakesBut);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsMyBirthday, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsYourBirthday, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouBecomingSenileAlreadyI);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ImFlatteredYoureThinkingOfMe);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_ELLI, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_OfCourseYouRememberBabyS);
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
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IEnjoyWatchingHimGrowUp);
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
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}
