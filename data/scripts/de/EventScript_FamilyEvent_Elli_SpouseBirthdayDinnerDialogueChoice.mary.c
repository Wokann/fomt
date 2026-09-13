#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouThinkThisMealIsDifferent[] =
        "Findest du dieses Gericht \r\n"
        "ist anders als das, was \r\n"
        "ich sonst koche?{Press}\p"
        "Das kommt, weil heute\r\n"
        "ein besonderer Tag ist! \r\n"
        "Weißt du warum?{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ElliAsksForHerBirthday[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AnniversaryYoureJokingRightNoHusband[] =
        "...Hochzeitstag?\r\n"
        "Du machst Witze, oder?\r\n"
        "Kein Mann ist gleichgültig{Press}\r\n"
        "genug, den Geburtstag  \r\n"
        "seiner Frau zu vergessen...?{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich \r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouAlreadyBecomingSenileAt[] =
        "Wirst du schon senil in\r\n"
        "deinem Alter?...\r\n"
        "Erschreckend! Es ist {Press}\p"
        "mein Geburtstag, weißt du?{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyDidRememberYouWerent[] =
        "Du hast echt daran gedacht?\r\n"
        "Du hast nicht geraten?\r\n"
        "Ich freue mich so!{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ICantWaitToHaveA[] =
        "Ich möchte so gerne\r\n"
        "ein Baby haben. Ich liebe\r\n"
        "Kinder.{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_CorrectsBirthdayAnswerAfterChildbirth[] =
        "Wirst du schon senil in\r\n"
        "deinem Alter?...\r\n"
        "Erschreckend! Es ist{Press}\p"
        "mein Geburtstag, weißt du?{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ElliBabyBirthdayCorrectAnswerReaction[] =
        "Du hast echt daran gedacht?!\r\n"
        "Du hast nicht geraten?\r\n"
        "Ich freue mich so!{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_NoMatterHowManyBirthdaysI[] =
        "Egal, wie viele Geburtstage\r\n"
        "ich feiere, ich glaube, ich \r\n"
        "werde erst erwachsen, wenn{Press}\r\n"
        "ich ein Kind habe. {Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyAreAStrangeOne[] =
        "Du bist wirklich\r\n"
        "komisch, oder?{Press}\p"
        "Wie viele Leute vergessen\r\n"
        "schon ihren eigenen\r\n"
        "Geburtstag und den {Press}\p"
        "ihres Kindes...?{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ELLI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouThinkThisMealIsDifferent);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ElliAsksForHerBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AnniversaryYoureJokingRightNoHusband);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouAlreadyBecomingSenileAt);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ELLI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyDidRememberYouWerent);
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
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ICantWaitToHaveA);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ElliAsksForHerBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_CorrectsBirthdayAnswerAfterChildbirth);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ELLI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ElliBabyBirthdayCorrectAnswerReaction);
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
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_NoMatterHowManyBirthdaysI);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyAreAStrangeOne);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}
