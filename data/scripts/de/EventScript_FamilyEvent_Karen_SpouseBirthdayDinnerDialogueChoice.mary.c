#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "Bist du mit deiner \r\n"
        "Arbeit fertig?{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "Ja";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_No[] =
        "Nein";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_LooksGoodDoesntItItsA[] =
        "Sieht gut aus, oder?\r\n"
        "Ein besonderes Gericht \r\n"
        "für einen besonderen Tag!{Press}\p"
        "Weißt du warum?{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_YourBirthday[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WrongItsMyBirthdayICant[] =
        "..........................\r\n"
        "Falsch! Es ist \r\n"
        "mein Geburtstag!{Press}\p"
        "Ich fasse nicht, dass du \r\n"
        "ihn vergessen hast!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "Ich entschuldige mich \r\n"
        "besser später...{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HaHaHaICantBelieve[] =
        "Ha ha ha! Unglaublich, dass\r\n"
        "du unsere Geburtstage \r\n"
        "verwechselt hast! Du bist{Press}\r\n"
        "süß , {NickName}.{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_ThatsRightYoullCelebrateWithMe[] =
        "Das ist richtig!\r\n"
        "Du feierst mit mir, \r\n"
        "oder?{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurAnniversaries[] =
        "Gut, wir werden unseren \r\n"
        "Hochzeitstag jetzt immer\r\n"
        "so feiern... IMMER!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "{Baby}s Geburtstag";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "Ha ha ha! Unglaublich, dass du \r\n"
        "unsere Geburtstage \r\n"
        "verwechselt hast!{Press}\r\n"
        "Du bist wirklich \r\n"
        "süß , {NickName}.{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_KarenBabyBirthdayCorrectAnswerCelebration[] =
        "Richtig! Lass \r\n"
        "uns die Nacht \r\n"
        "durchfeiern!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurFamily[] =
        "Gut, wir werden unsere \r\n"
        "Familienjahrestage jetzt  \r\n"
        "immer so feiern... IMMER!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IKnowYouLoveBabyBut[] =
        "Ich weiß, du liebst \r\n"
        "{Baby}, aber \r\n"
        "denk auch an mich, OK?{Press}\p"
        "Es ist mein Geburtstag!{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "Beeil dich und werde fertig.\r\n"
        "Es ist ein wichtiger Tag.{Press}";
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
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurAnniversaries);
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
                var_0 = TalkChoice3(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
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
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_BabySBirthday);
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
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurFamily);
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
