#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_DoesntThisCakeLookGoodYou[] =
        "Toller Kuchen, was?\r\n"
        "Du weißt, warum ich\r\n"
        "ihn gebacken habe, oder?{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "Mein Geburtstag.";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_YourBirthday[] =
        "Dein Geburtstag.";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}s Geburtstag.";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantBelieveYouWouldConfuse[] =
        "Ich fasse nicht, dass du den\r\n"
        "Geburtstag deines Sohnes\r\n"
        "mit deinem verwechselst!{Press}\p"
        "Du bist echt lustig, \r\n"
        "{NickName}.{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich\r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ThanksForThinkingAboutMeBut[] =
        "Danke, dass du an mich\r\n"
        "denkst, aber vergisst du\r\n"
        "nicht gerade {Baby}?{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabyIsLuckyToHaveSuch[] =
        "{Baby} hat Glück,\r\n"
        "einen so aufmerksamen Vater\r\n"
        "zu haben!{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantWaitUntilHeGrows[] =
        "Ich kann nicht abwarten, \r\n"
        "bis er groß ist und wir\r\n"
        "zusammen ausgehen können!{Press}\p"
        "Sein Vater würde mich\r\n"
        "nicht mitnehmen...{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_KAREN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_DoesntThisCakeLookGoodYou);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_YourBirthday, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantBelieveYouWouldConfuse);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ThanksForThinkingAboutMeBut);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_KAREN, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabyIsLuckyToHaveSuch);
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
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantWaitUntilHeGrows);
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
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
}
