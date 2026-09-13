#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_ChildInjury_ElliWakesPlayerForEmergency[] =
        "{NickName}, wake up!\r\n"
        "Hurry!{Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_ElliExplainsChildFellFromBed[] =
        "When I woke up this morning,\r\n"
        "{Baby} had fallen \r\n"
        "out of bed and gotten hurt.{Press}\r\n"
        "We should do something!...{Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_ChildCriesAfterFall[] =
        "Waaa...!!!!{Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_ChoiceAssumeChildIsFine[] =
        "He'll be fine!";

    const char gText_FamilyEvent_Elli_ChildInjury_ChoiceTakeChildToClinic[] =
        "Let's go to the Clinic.";

    const char gText_FamilyEvent_Elli_ChildInjury_ElliWarnsInjuryCouldBeSerious[] =
        "But he could be \r\n"
        "seriously injured!{Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_ElliInsistsOnDoctorExamination[] =
        "No, I definitely want the\r\n"
        "Doctor to look at him. \r\n"
        "Come on, {Baby}. {Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_DoctorDiagnosesMinorScratch[] =
        "Don't worry, it's only \r\n"
        "a scratch. {Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_ElliExpressesRelief[] =
        "I'm so relieved!{Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_DoctorWarnsParentsToBeCareful[] =
        "He's OK this time, but you\r\n"
        "have to be especially\r\n"
        "watchful at this age.{Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_ElliApologizesToChild[] =
        "I understand. \r\n"
        "I'm sorry, {Baby}.{Press}";

    const char gText_FamilyEvent_Elli_ChildInjury_ChildCallsPlayerDa[] =
        "Da-!{Press}";
};

void EventScript_FamilyEvent_Elli_ChildInjury(void)
{
    int var_0;
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    ChangeMap(MAP_FARMHOUSE, X(400), Y(100));
    SetEntityPosition(ENTITY_PLAYER, X(400), Y(100), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLI, X(450), Y(100), FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_CHILD, X(432), Y(100), FACING_LEFT);
    if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
    {
        SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    }
    else
    {
        SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_ChildInjury_ElliWakesPlayerForEmergency);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_ChildInjury_ElliExplainsChildFellFromBed);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
    TalkMessage(gText_FamilyEvent_Elli_ChildInjury_ChildCriesAfterFall);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Elli_ChildInjury_ChoiceAssumeChildIsFine, gText_FamilyEvent_Elli_ChildInjury_ChoiceTakeChildToClinic);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_ChildInjury_ElliWarnsInjuryCouldBeSerious);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_ChildInjury_ElliInsistsOnDoctorExamination);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            VarSet(VAR_ELLI_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ELLI, 3000);
            AddNpcFriendship(CHARACTER_CHILD, 20);
            AddNpcFriendship(CHARACTER_DOCTOR, 20);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_MINERAL_CLINIC_1F, X(228), Y(148));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(228), Y(124), FACING_RIGHT);
            if (IsPlayerHoldingNothing())
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            SetEntityPosition(ENTITY_ELLI, X(228), Y(148), FACING_RIGHT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityPosition(ENTITY_DOCTOR, X(262), Y(124), FACING_LEFT);
            SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
            SetEntityPosition(ENTITY_CHILD, X(262), Y(148), FACING_LEFT);
            if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
            }
            else
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FamilyEvent_Elli_ChildInjury_DoctorDiagnosesMinorScratch);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            TalkMessage(gText_FamilyEvent_Elli_ChildInjury_ElliExpressesRelief);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FamilyEvent_Elli_ChildInjury_DoctorWarnsParentsToBeCareful);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            TalkMessage(gText_FamilyEvent_Elli_ChildInjury_ElliApologizesToChild);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_CHILD);
            SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
            TalkMessage(gText_FamilyEvent_Elli_ChildInjury_ChildCallsPlayerDa);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
            VarSet(VAR_ELLI_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
