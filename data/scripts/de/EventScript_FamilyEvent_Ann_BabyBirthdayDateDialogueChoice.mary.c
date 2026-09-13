#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_TodayIsASpecialDayYou[] =
        "Es ist ein besonderer Tag!\r\n"
        "Du weißt warum, oder...?{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "Mein Geburtstag.";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_YourBirthday[] =
        "Dein Geburtstag.";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}s Geburtstag.";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HowCanYouForgetYourOwn[] =
        "Wie kannst du den\r\n"
        "Geburtstag deines \r\n"
        "eigenen Sohnes vergessen!?{Press}\p"
        "Ich kann dir nicht glauben!{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich\r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouSureYoureNotWorking[] =
        "Bist du sicher, dass du\r\n"
        "nicht zu viel arbeitest?{Press}\p"
        "Ich hoffe du leidest nicht\r\n"
        "an Gedächtnisschwund...{Press}\p"
        "Es ist {Baby}s \r\n"
        "Geburtstag!{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_OfCourseYouWouldRememberBaby[] =
        "Natürlich denkst du\r\n"
        "an {Baby}s\r\n"
        "Geburtstag!{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AYearGoesSoQuicklyI[] =
        "Ein Jahr ist so \r\n"
        "schnell vorbei...\r\n"
        "Ich frage mich, wie er{Press}\p"
        "nächstes Jahr aussieht!...{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
};

void EventScript_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ANN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_TodayIsASpecialDayYou);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_YourBirthday, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HowCanYouForgetYourOwn);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouSureYoureNotWorking);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_ANN, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_OfCourseYouWouldRememberBaby);
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
                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AYearGoesSoQuicklyI);
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
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}
