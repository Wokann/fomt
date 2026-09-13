#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "Yes";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_No[] =
        "No";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_LooksGoodDoesntItItsA[] =
        "Looks good, doesn't it?\r\n"
        "It's a special meal for a \r\n"
        "special day! Know why?{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Our anniversary";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "My birthday";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Your birthday";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WrongItsMyBirthdayICant[] =
        "..........................\r\n"
        "Wrong! It's my birthday!{Press}\p"
        "I can't believe you \r\n"
        "forgot!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "I'd better apologize \r\n"
        "later...{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HaHaHaICantBelieve[] =
        "Ha ha ha! I can't \r\n"
        "believe you mixed up our \r\n"
        "birthdays! You sure are {Press}\r\n"
        "cute, {NickName}.{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_ThatsRightYoullCelebrateWithMe[] =
        "That's right!\r\n"
        "You'll celebrate with me, \r\n"
        "right?{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurAnniversaries[] =
        "Well, we will celebrate our\r\n"
        "anniversaries just like \r\n"
        "this...Forever!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}'s birthday";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_KarenBabyBirthdayCorrectAnswerCelebration[] =
        "That's right! Let's \r\n"
        "spend the night \r\n"
        "celebrating!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurFamily[] =
        "Well, we will celebrate our\r\n"
        "family anniversaries just  \r\n"
        "like this...Forever!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IKnowYouLoveBabyBut[] =
        "I know you love \r\n"
        "{Baby}, but \r\n"
        "remember me, too, OK?{Press}\p"
        "It's my birthday!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Hurry up and finish.\r\n"
        "Today is an important day.{Press}";
};

void EventScript_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_KAREN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_LooksGoodDoesntItItsA);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WrongItsMyBirthdayICant);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HaHaHaICantBelieve);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_KAREN, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_ThatsRightYoullCelebrateWithMe);
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
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurAnniversaries);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HaHaHaICantBelieve);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_KAREN, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_KarenBabyBirthdayCorrectAnswerCelebration);
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
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurFamily);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IKnowYouLoveBabyBut);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
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
            TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
}
