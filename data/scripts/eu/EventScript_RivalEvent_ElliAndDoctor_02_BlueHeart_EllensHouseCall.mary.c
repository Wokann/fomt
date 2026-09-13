#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliAsksEllenHowSheFeels[] =
        "How do you feel? {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenSaysSheFeelsMuchBetter[] =
        "I feel much better. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_StuIsRelievedEllenFeelsBetter[] =
        "That's good. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorDiagnosesEllenWithAColdAndPrescribesRest[] =
        "I think you have a cold. \r\n"
        "Drink lots of fluids and \r\n"
        "get plenty of rest. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenThanksDoctor[] =
        "Thank you, Doctor. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorSaysHeIsDoingHisDutyAndAsksAboutEllensLegs[] =
        "I'm just doing my duty. \r\n"
        "How do your legs feel? {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenSaysHerLegsStillHurt[] =
        "They hurt, as always. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliFallsSilentOverEllensLegs[] =
        ".........{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorRegretsBeingUnableToHealEllensLegs[] =
        "I should be able to do \r\n"
        "more for you...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenTellsDoctorNotToApologize[] =
        "Don't apologize, Doctor. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliSaysDoctorAlreadyDoesMoreThanEnough[] =
        "You do more than enough\r\n"
        "for all of us! {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorThanksElliAndEllen[] =
        "......Thank you. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliRemindsDoctorToReturnToClinic[] =
        "Doctor, you should be \r\n"
        "getting back to the Clinic. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorAgreesAndTellsEllenToTakeCare[] =
        "You're right. \r\n"
        "Take care now. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenThanksDoctorAgain[] =
        "Thanks again, Doctor. {Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall(void)
{
    ChangeMap(MAP_ELLEN_HOUSE, X(120), Y(96));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(216), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLI, X(112), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(128), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_ELLEN, X(120), Y(72), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_STU, X(208), Y(112), FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WALK);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_DOCTOR, Y(112), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitFrames(40);
    MoveEntityYTo(ENTITY_ELLI, Y(112), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DOCTOR);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    WaitFrames(60);
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_THINKING, FALSE);
    StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliAsksEllenHowSheFeels);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenSaysSheFeelsMuchBetter);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_StuIsRelievedEllenFeelsBetter);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorDiagnosesEllenWithAColdAndPrescribesRest);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenThanksDoctor);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorSaysHeIsDoingHisDutyAndAsksAboutEllensLegs);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenSaysHerLegsStillHurt);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliFallsSilentOverEllensLegs);
    TalkClose();
    StartEntityEffect(ENTITY_DOCTOR, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorRegretsBeingUnableToHealEllensLegs);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_AFRAID, FALSE);
    StartEntityEffect(ENTITY_ELLEN, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenTellsDoctorNotToApologize);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliSaysDoctorAlreadyDoesMoreThanEnough);
    TalkClose();
    StartEntityEffect(ENTITY_DOCTOR, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorThanksElliAndEllen);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliRemindsDoctorToReturnToClinic);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorAgreesAndTellsEllenToTakeCare);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenThanksDoctorAgain);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WALK);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_DOCTOR, Y(224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_ELLI, Y(224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DOCTOR);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    HideEntity(ENTITY_DOCTOR);
    HideEntity(ENTITY_ELLI);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    PanCameraTo(X(120), Y(144), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_ELLEN, EventScript_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_FollowupEllenDialogue);
    SetEntityEventScript(ENTITY_STU, EventScript_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_FollowupStuDialogue);
    VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
