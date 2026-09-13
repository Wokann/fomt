#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_LooksGoodDoesntItItsA[] =
        "Looks good, doesn't it?\r\n"
        "It's a special meal for a \r\n"
        "special day! Know why?{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Our anniversary";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "My birthday";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Your birthday";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_HmmItsEvenMoreImportantTo[] =
        "Hmm...It's even more \r\n"
        "important to me than our \r\n"
        "anniversary. {Press}\p"
        "It's your birthday, silly!{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayLetsHaveAGlass[] =
        "Happy birthday!\r\n"
        "Let's have a glass of \r\n"
        "wine to celebrate!{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurAnniversaries[] =
        "Well, we will celebrate our\r\n"
        "anniversaries just like \r\n"
        "this...Forever!{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_TeasesPlayerForConfusingSpousesBirthdays[] =
        "Ha ha ha! I can't \r\n"
        "believe you mixed up our \r\n"
        "birthdays! You sure are {Press}\r\n"
        "cute, {NickName}.{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_ThatsRightLetsSpendTheNight[] =
        "That's right! Let's \r\n"
        "spend the night \r\n"
        "celebrating!{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurFamily[] =
        "Well, we will celebrate our\r\n"
        "family anniversaries just  \r\n"
        "like this...Forever!{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_TeasesPlayerForConfusingPlayerAndChildBirthdays[] =
        "Ha ha ha! I can't \r\n"
        "believe you mixed up your \r\n"
        "birthday with {Press}\r\n"
        "{Baby}'s! {Press}\p"
        "You sure are cute!{Press}";

    const char gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_KAREN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_LooksGoodDoesntItItsA);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_HmmItsEvenMoreImportantTo);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_KAREN, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayLetsHaveAGlass);
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
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurAnniversaries);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_TeasesPlayerForConfusingSpousesBirthdays);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_KAREN, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_ThatsRightLetsSpendTheNight);
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
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurFamily);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_TeasesPlayerForConfusingSpousesBirthdays);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_TeasesPlayerForConfusingPlayerAndChildBirthdays);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
}
