#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorCoughs[] =
        "Cough...cough...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAsksIfDoctorIsAllRight[] =
        "Doctor, are you alright?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorClaimsHeIsFine[] =
        "I'm fine...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliUrgesDoctorToTakeTheDayOff[] =
        "Why don't you take \r\n"
        "the day off? {Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorRefusesToLetDownHisPatients[] =
        "I could never let down \r\n"
        "the people who need me! {Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliObjects[] =
        "But...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorSaysHeCanCareForHimselfAndHasElli[] =
        "Don't worry about me. \r\n"
        "I know how to take care \r\n"
        "of myself. {Press}\p"
        "Besides, I have you with me.{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAcceptsButWarnsDoctorNotToOverwork[] =
        "If you say so, Doctor.\r\n"
        "Just don't overdo it! {Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliSaysSheWillBeAngryIfDoctorOverworks[] =
        "If you do, I'll get mad \r\n"
        "at you! {Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorComparesEllisConcernToHisMother[] =
        "Ha ha!\r\n"
        "You sound like my mother,\r\n"
        "you know. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorSaysElliWillMakeAGoodWife[] =
        "You'll be a good wife to \r\n"
        "somebody, Elli. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAsksIfDoctorIsTeasingHer[] =
        "Are you teasing me...? {Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll(void)
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
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorCoughs);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAsksIfDoctorIsAllRight);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorClaimsHeIsFine);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliUrgesDoctorToTakeTheDayOff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorRefusesToLetDownHisPatients);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliObjects);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorSaysHeCanCareForHimselfAndHasElli);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAcceptsButWarnsDoctorNotToOverwork);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliSaysSheWillBeAngryIfDoctorOverworks);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorComparesEllisConcernToHisMother);
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorSaysElliWillMakeAGoodWife);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAsksIfDoctorIsTeasingHer);
    TalkClose();
    PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_FollowupDoctorDialogue);
    SetEntityEventScript(ENTITY_ELLI, EventScript_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_FollowupElliDialogue);
    VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
