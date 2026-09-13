#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliSighsFromFatigue[] =
        "ふぅ…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAsksWhetherElliIsTired[] =
        "つかれたかい？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliSaysSheIsFine[] =
        "いいえ、大丈夫です。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorWarnsElliNotToOverwork[] =
        "ムリしないでくれよ。\r\n"
        "キミが倒れたら、こまる人が\r\n"
        "たくさんいるんだから。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliHopesDoctorIsPersonallyConcerned[] =
        "ド…ドクター。\r\n"
        "心配してくれているんですか？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorExplainsPracticalOrMedicalReasonForConcern[] =
        "当然だろう。\r\n"
        "病人が増えて喜ぶ医者なんて\r\n"
        "いないよ。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliIsDisappointedByDoctorsReason[] =
        "………はぁ、\r\n"
        "そういうことですか…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAsksWhatIsWrong[] =
        "どうしたんだい？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_ElliDeniesAnythingIsWrong[] =
        "いいえ、なんでもないです。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_DoctorAcceptsEllisAnswer[] =
        "？\r\n"
        "だったらいいんだけど。{Press}";
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
