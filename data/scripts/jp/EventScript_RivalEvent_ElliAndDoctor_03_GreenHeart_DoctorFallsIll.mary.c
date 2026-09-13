#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorCoughs[] =
        "ゲホゲホッ…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAsksIfDoctorIsAllRight[] =
        "ドクター、大丈夫ですか。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorClaimsHeIsFine[] =
        "ああ、大丈夫だよ…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliUrgesDoctorToTakeTheDayOff[] =
        "今日はムリせず、\r\n"
        "休んでください。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorRefusesToLetDownHisPatients[] =
        "そうもいかないよ。\r\n"
        "医者が病気で病院を休むなんて\r\n"
        "笑い話にもならないからね。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliObjects[] =
        "でも…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorSaysHeCanCareForHimselfAndHasElli[] =
        "心配ないよ。\r\n"
        "これでも医者なんだから、{Press}\p"
        "自分の体のことはわかってる\r\n"
        "つもりだよ。\r\n"
        "それにエリィもいるからね。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAcceptsButWarnsDoctorNotToOverwork[] =
        "わかりました。\r\n"
        "でも、ムリだけは\r\n"
        "しないでくださいね。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliSaysSheWillBeAngryIfDoctorOverworks[] =
        "ムリしてたら、\r\n"
        "怒りますからね。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorComparesEllisConcernToAWife[] =
        "ああ、わかったよ。\r\n"
        "キミは、まるでボクの\r\n"
        "奥さんみたいだなぁ。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorSaysElliWillMakeAGoodWife[] =
        "キミはいい奥さんになるよ。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_ElliAsksIfDoctorIsTeasingHer[] =
        "やだっ、ドクターったら…{Press}";
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
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_DoctorComparesEllisConcernToAWife);
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
