#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_AreYouDoneWorking[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_DoesThisRemindYouOfAnything[] =
        "Erinnert dich dies an \r\n"
        "irgendetwas?{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "Es ist mein Geburtstag.";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_ItsYourBirthday[] =
        "Es ist dein Geburtstag.";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}s Geburtstag.";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_VeryFunnySometimesIThinkYou[] =
        "Sehr witzig. Manchmal \r\n"
        "benimmst du dich \r\n"
        "vielleicht ulkig!{Press}\p"
        "Es ist {Baby}s\r\n"
        "Geburtstag.{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich \r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_WhatAreYouTalkingAboutI[] =
        "Wovon redest du denn!?\r\n"
        "Nicht zu fassen, dass du \r\n"
        "{Baby}s Geburtstag{Press}\r\n"
        "vergessen hast!{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_YoureAGraetFatherNickNameThanks[] =
        "Du bist ein toller\r\n"
        "Vater, {NickName}. {Press}\p"
        "Danke, dass du an\r\n"
        "{Baby}s Geburtstag\r\n"
        "gedacht hast.{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_ItsNoFunHavingYourBirthday[] =
        "Es macht keinen Spaß,\r\n"
        "am Hochzeitstag seiner\r\n"
        "Eltern Geburtstag zu haben!{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_MARY);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_DoesThisRemindYouOfAnything);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_ItsYourBirthday, gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_MARY);
                    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                    ShowTalkHeartIndicator(CHARACTER_MARY);
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_VeryFunnySometimesIThinkYou);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_MARY);
                    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_MARY);
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_WhatAreYouTalkingAboutI);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_MARY, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_MARY);
                    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_MARY);
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_YoureAGraetFatherNickNameThanks);
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
                    SetTalkNameplateCharacter(CHARACTER_MARY);
                    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_MARY);
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_ItsNoFunHavingYourBirthday);
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
                    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
}
