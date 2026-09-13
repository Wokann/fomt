#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWithWork[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs[] =
        "Du weißt, was für ein\r\n"
        "Tag heute ist, oder...?{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYoureSoBusy[] =
        "Ich fasse nicht, dass du\r\n"
        "so beschäftigt bist, dass \r\n"
        "du deinen eigenen {Press}\p"
        "Geburtstag vergisst!\r\n"
        "Iss das und geh früh \r\n"
        "ins Bett, {NickName}.{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich \r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis[] =
        "Happy Birthday! \r\n"
        "Ich habe das hier schon\r\n"
        "lange Zeit geplant!{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HowCanYouConfuseMyBirthday[] =
        "Wie kannst du meinen\r\n"
        "Geburtstag mit deinem\r\n"
        "verwechseln?!{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}s Geburtstag";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_ConfusedSpouseBirthdayAfterChildbirth[] =
        "Lass uns für immer\r\n"
        "zusammenbleiben, OK? \r\n"
        "Egal, wie alt wir auch {Press}\p"
        "werden...{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_LetsAlwaysBeTogether[] =
        "Wie kannst du meinen\r\n"
        "Geburtstag mit deinem\r\n"
        "verwechseln?!{Press}\p"
        "Unglaublich!{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_WhatAreYouTalkingAboutHow[] =
        "Wovon redest du denn!?\r\n"
        "Wie kannst du deinen \r\n"
        "Geburtstag vergessen?{Press}\p"
        "Ich fasse es nicht...!{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_POPURI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYoureSoBusy);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis);
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
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HowCanYouConfuseMyBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis);
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
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_ConfusedSpouseBirthdayAfterChildbirth);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_LetsAlwaysBeTogether);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_WhatAreYouTalkingAboutHow);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}
