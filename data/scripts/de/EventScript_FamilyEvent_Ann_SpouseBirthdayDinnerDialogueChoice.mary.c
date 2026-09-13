#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWithWork[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs[] =
        "Du weißt, was für ein\r\n"
        "Tag heute ist, oder...?{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_ItMayNotMatterToYou[] =
        "Das mag dir ja egal sein, \r\n"
        "aber mir nicht!{Press}\p"
        "Es ist mein Geburtstag!{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich \r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_AreYouFeelingOKNickNameIf[] =
        "Geht es dir gut, \r\n"
        "{NickName}?{Press}\p"
        "Wenn du nicht krank bist,\r\n"
        "gibt es keine Entschuldigung\r\n"
        "daf r, dass du meinen {Press}\r\n"
        "Geburtstag vergessen hast!{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLaterAfterWrongAnswer[] =
        "Ich entschuldige mich \r\n"
        "bes ser sp ter...{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_AwwwYouRememberedYoureSoBusy[] =
        "Ahhhh... Du hast dran gedacht!\r\n"
        "Du bist immer beschäftigt;\r\n"
        "ich hatte Angst, du würdest {Press}\r\n"
        "nicht daran denken.{Press}\p"
        "Hätte nicht an dir \r\n"
        "zweifeln sollen!{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_SorryAllMyFoodIsThe[] =
        "Sorry, mein Essen ist \r\n"
        "dasselbe wie im Gasthof. {Press}\p"
        "Habe ich von Papa gelernt!{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}s Geburtstag";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_AreYouFeelingOKAfterChildbirth[] =
        "Geht es dir gut, \r\n"
        "{NickName}?{Press}\p"
        "Wenn du nicht krank bist,\r\n"
        "gibt es keine\r\n"
        "Entschuldigung,{Press}\r\n"
        "dafür, dass du meinen \r\n"
        "Geburtstag vergessen hast!{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_RememberedBirthdayAfterChildbirth[] =
        "Ahhhh...Du hast dran gedacht!\r\n"
        "Du bist immer beschäftigt; \r\n"
        "ich hatte Angst, du würdest{Press}\p"
        "nicht daran denken\r\n"
        ".Hätte nicht an dir \r\n"
        "zweifeln sollen!{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_InnCookingAfterChildbirth[] =
        "Sorry, mein Essen ist \r\n"
        "dasselbe wie im Gasthof.{Press}\p"
        "Habe ich von Papa gelernt!{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_ItDoesntTakeMuchToRemember[] =
        "Ist ja wohl nicht so schwer, \r\n"
        "sich den Geburtstag seiner  \r\n"
        "Frau und seines Kindes {Press}\p"
        "zu merken! \r\n"
        "Nächstes Mal denkst \r\n"
        "du besser dran!{Press}";

    const char gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ANN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_ItMayNotMatterToYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_AreYouFeelingOKNickNameIf);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLaterAfterWrongAnswer);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ANN, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_AwwwYouRememberedYoureSoBusy);
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
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_SorryAllMyFoodIsThe);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_AreYouFeelingOKAfterChildbirth);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ANN, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_RememberedBirthdayAfterChildbirth);
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
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_InnCookingAfterChildbirth);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_ItDoesntTakeMuchToRemember);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}
