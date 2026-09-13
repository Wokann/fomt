#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_ChildInjury_MaryWakesPlayerForEmergency[] =
        "{NickName}, wake up!\r\n"
        "Hurry! Wake up!{Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_MaryExplainsChildFellFromBed[] =
        "When I woke up this morning,\r\n"
        "{Baby} had fallen \r\n"
        "out of bed and gotten hurt.{Press}\r\n"
        "What should we do?!...{Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_ChildCriesAfterFall[] =
        "Waaa...!!!!{Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_ChoiceAssumeChildIsFine[] =
        "He'll be fine!";

    const char gText_FamilyEvent_Mary_ChildInjury_ChoiceTakeChildToClinic[] =
        "Let's go to the Clinic.";

    const char gText_FamilyEvent_Mary_ChildInjury_MaryWarnsInjuryCouldBeSerious[] =
        "Aren't you afraid that he \r\n"
        "could be hurt?!...{Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_MaryTakesChildToClinicAlone[] =
        "I'll take him to the Clinic\r\n"
        "myself, {NickName}.\r\n"
        "Come on, {Baby}.{Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_DoctorDiagnosesMinorScratch[] =
        "Don't worry, it's only \r\n"
        "a scratch. {Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_MaryBlamesHerselfForFall[] =
        "It's all my fault...!{Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_DoctorWarnsParentsToBeCareful[] =
        "He's OK this time, but you\r\n"
        "have to be especially\r\n"
        "watchful at this age.{Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_MaryPromisesToBeMoreCareful[] =
        "I understand. \r\n"
        "I'll be more careful.{Press}";

    const char gText_FamilyEvent_Mary_ChildInjury_ChildCallsPlayerDa[] =
        "Da-!{Press}";
};

void EventScript_FamilyEvent_Mary_ChildInjury(void)
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
    SetEntityPosition(ENTITY_MARY, X(450), Y(100), FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
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
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_ChildInjury_MaryWakesPlayerForEmergency);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_ChildInjury_MaryExplainsChildFellFromBed);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
    TalkMessage(gText_FamilyEvent_Mary_ChildInjury_ChildCriesAfterFall);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Mary_ChildInjury_ChoiceAssumeChildIsFine, gText_FamilyEvent_Mary_ChildInjury_ChoiceTakeChildToClinic);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_ChildInjury_MaryWarnsInjuryCouldBeSerious);
            TalkClose();
            SetEntityFacing(ENTITY_MARY, FACING_DOWN);
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_ChildInjury_MaryTakesChildToClinicAlone);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_MARY);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            VarSet(VAR_MARY_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_MARY, 3000);
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
            SetEntityPosition(ENTITY_MARY, X(228), Y(148), FACING_RIGHT);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
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
            TalkMessage(gText_FamilyEvent_Mary_ChildInjury_DoctorDiagnosesMinorScratch);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
            TalkMessage(gText_FamilyEvent_Mary_ChildInjury_MaryBlamesHerselfForFall);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FamilyEvent_Mary_ChildInjury_DoctorWarnsParentsToBeCareful);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            TalkMessage(gText_FamilyEvent_Mary_ChildInjury_MaryPromisesToBeMoreCareful);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_CHILD);
            SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
            TalkMessage(gText_FamilyEvent_Mary_ChildInjury_ChildCallsPlayerDa);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_MARY);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
            VarSet(VAR_MARY_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
