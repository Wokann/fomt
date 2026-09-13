#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_ChildInjury_PopuriWakesPlayerForEmergency[] =
        "{NickName}, wake up!\r\n"
        "You have to wake up!{Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_PopuriExplainsChildFellFromBed[] =
        "When I woke up this morning,\r\n"
        "{Baby}had fallen \r\n"
        "out of bed and hurt himself.{Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_ChildCriesAfterFall[] =
        "Waaa...!!!!{Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_ChoiceAssumeChildIsFine[] =
        "He'll be fine!";

    const char gText_FamilyEvent_Popuri_ChildInjury_ChoiceTakeChildToClinic[] =
        "Let's go to the Clinic.";

    const char gText_FamilyEvent_Popuri_ChildInjury_PopuriRejectsIgnoringInjury[] =
        "What are you talking about!?\r\n"
        "{Baby}'s injured,\r\n"
        "Don't you see!?{Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_PopuriTakesChildToClinicAlone[] =
        "I'm taking {Baby}\r\n"
        "to the Doctor now, even if\r\n"
        "I have to kick him out{Press}\r\n"
        "of bed!{Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_DoctorDiagnosesMinorScratch[] =
        "Don't worry, it's only \r\n"
        "a scratch. {Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_PopuriExpressesRelief[] =
        "Really?{Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_DoctorWarnsParentsToBeCareful[] =
        "He's OK this time, but you\r\n"
        "have to be especially\r\n"
        "watchful at this age.{Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_PopuriApologizesToChild[] =
        "I understand. \r\n"
        "I'm sorry, {Baby}.{Press}";

    const char gText_FamilyEvent_Popuri_ChildInjury_ChildCallsPlayerDa[] =
        "Da-!{Press}";
};

void EventScript_FamilyEvent_Popuri_ChildInjury(void)
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
    SetEntityPosition(ENTITY_POPURI, X(450), Y(100), FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
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
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_PopuriWakesPlayerForEmergency);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_PopuriExplainsChildFellFromBed);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
    TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_ChildCriesAfterFall);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Popuri_ChildInjury_ChoiceAssumeChildIsFine, gText_FamilyEvent_Popuri_ChildInjury_ChoiceTakeChildToClinic);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_PopuriRejectsIgnoringInjury);
            TalkClose();
            SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_PopuriTakesChildToClinicAlone);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_POPURI);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            VarSet(VAR_POPURI_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_POPURI, 3000);
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
            SetEntityPosition(ENTITY_POPURI, X(228), Y(148), FACING_RIGHT);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
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
            TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_DoctorDiagnosesMinorScratch);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_PopuriExpressesRelief);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_DoctorWarnsParentsToBeCareful);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_PopuriApologizesToChild);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_CHILD);
            SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
            TalkMessage(gText_FamilyEvent_Popuri_ChildInjury_ChildCallsPlayerDa);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_POPURI);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
            VarSet(VAR_POPURI_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
