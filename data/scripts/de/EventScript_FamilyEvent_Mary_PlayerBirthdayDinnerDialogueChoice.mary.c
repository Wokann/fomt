#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_DoesThisGiveYouAnyIdeas[] =
        "Erinnert dich dies \r\n"
        "an irgendetwas?{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HaSometimesYouReallyAreLike[] =
        "Ha! Manchmal benimmst du\r\n"
        "dich vielleicht ulkig!\r\n"
        "Es ist dein Geburtstag,{Press}\r\n"
        "du Trottel!\r\n"
        "Happy Birthday!{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich \r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_WereYouPretendingToForgetJust[] =
        "Hast du so getan, als\r\n"
        "hättest du es vergessen,\r\n"
        "um mich zu testen?{Press}\p"
        "Du hast manchmal \r\n"
        "Ideen, {NickName}! {Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday[] =
        "Es macht keinen Spaß,\r\n"
        "am Jahrestag seiner\r\n"
        "Eltern Geburtstag zu haben!{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYouMixUp[] =
        "Ich fasse nicht, dass\r\n"
        "du deinen und meinen \r\n"
        "Geburtstag verwechselt hast!{Press}\r\n"
        "Manchmal frage ich mich, \r\n"
        "was in deinem Kopf vorgeht, \r\n"
        "{NickName}.{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}s Geburtstag";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HaveYouForgottenYourOwnBirthday[] =
        "Hast du deinen eigenen\r\n"
        "Geburtstag etwa genauso \r\n"
        "vergessen wie {Baby}s?{Press}\r\n"
        "Nächstes Jahr denkst du\r\n"
        "besser dran, oder ich werde\r\n"
        "echt sauer, {NickName}! {Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_MARY);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_DoesThisGiveYouAnyIdeas);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HaSometimesYouReallyAreLike);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_MARY, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_WereYouPretendingToForgetJust);
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
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYouMixUp);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_MARY, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_WereYouPretendingToForgetJust);
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
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
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
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYouMixUp);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HaveYouForgottenYourOwnBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
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
            TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
}
