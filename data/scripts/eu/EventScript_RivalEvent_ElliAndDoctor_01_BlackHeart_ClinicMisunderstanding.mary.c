#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliSighsFromFatigue[] =
        "Whew...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAsksWhetherElliIsTired[] =
        "Tired? {Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliSaysSheIsFine[] =
        "No, I'm fine. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorWarnsElliNotToOverwork[] =
        "Don't push yourself too \r\n"
        "much, now. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliHopesDoctorIsPersonallyConcerned[] =
        "Doctor...I'm touched you're \r\n"
        "worried about me! {Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorExplainsPracticalOrMedicalReasonForConcern[] =
        "Well, I couldn't run the \r\n"
        "Clinic without you! {Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliIsDisappointedByDoctorsReason[] =
        "Is that all...?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAsksWhatIsWrong[] =
        "What's wrong now? {Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliDeniesAnythingIsWrong[] =
        "No-nothing. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAcceptsEllisAnswer[] =
        "OK, if you say so...{Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding(void)
{
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(247), Y(128));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLI, X(232), Y(128), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(264), Y(128), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliSighsFromFatigue);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAsksWhetherElliIsTired);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliSaysSheIsFine);
    TalkClose();
    StartEntityEffect(ENTITY_DOCTOR, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorWarnsElliNotToOverwork);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliHopesDoctorIsPersonallyConcerned);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorExplainsPracticalOrMedicalReasonForConcern);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliIsDisappointedByDoctorsReason);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    StartEntityEffect(ENTITY_DOCTOR, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAsksWhatIsWrong);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliDeniesAnythingIsWrong);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAcceptsEllisAnswer);
    TalkClose();
    PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_FollowupDoctorDialogue);
    SetEntityEventScript(ENTITY_ELLI, EventScript_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_FollowupElliDialogue);
    VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
