#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_DoesThisRemindYouOfSomething[] =
        "Erinnert dich das\r\n"
        "an etwas?{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_OurAnniversaryHuhInThatCase[] =
        "Unser Hochzeitstag, wie?{Press}\p"
        "Wenn das so ist... wann,\r\n"
        "denkst du, ist \r\n"
        "mein Geburtstag!?{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich \r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_CorrectsPlayerBirthdayAnswerBeforeChildbirth[] =
        "Ha! Manchmal benimmst du\r\n"
        "dich vielleicht ulkig!\r\n"
        "Es ist mein Geburtstag, {Press}\r\n"
        "du Trottel!{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ThatsRightTodayImAYear[] =
        "Richtig. \r\n"
        "Ich bin heute ein Jahr\r\n"
        "älter und hoffentlich{Press}\p"
        "weiser.{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday[] =
        "Es macht keinen Spaß,\r\n"
        "am Hochzeitstag seiner\r\n"
        "Eltern Geburtstag zu haben!{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}s Geburtstag";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_CorrectsPlayerBirthdayAnswerAfterChildbirth[] =
        "Ha! Manchmal benimmst du\r\n"
        "dich vielleicht ulkig!\r\n"
        "Es ist mein Geburtstag,{Press}\p"
        "du Trottel.{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_WhatKindOfAFatherDoesn[] =
        "Was ist das für ein Vater,\r\n"
        "der nicht die Geburtstage \r\n"
        "seiner Frau und seines {Press}\r\n"
        "Sohnes kennt?!{Press}\p"
        "Heute ist mein Geburtstag!{Press}";

    const char gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_MARY);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_DoesThisRemindYouOfSomething);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_OurAnniversaryHuhInThatCase);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_CorrectsPlayerBirthdayAnswerBeforeChildbirth);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_MARY, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ThatsRightTodayImAYear);
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
                        SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_BabySBirthday);
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
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_CorrectsPlayerBirthdayAnswerAfterChildbirth);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_MARY, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ThatsRightTodayImAYear);
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
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_WhatKindOfAFatherDoesn);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
}
