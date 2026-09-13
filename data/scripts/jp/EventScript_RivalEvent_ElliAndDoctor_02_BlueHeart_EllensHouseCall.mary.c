#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliAsksEllenHowSheFeels[] =
        "おばあちゃん、具合どう？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenSaysSheFeelsMuchBetter[] =
        "だいぶ、いいわよ。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_StuIsRelievedEllenFeelsBetter[] =
        "よかったぁ～。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorDiagnosesEllenWithAColdAndPrescribesRest[] =
        "どうやら、カゼだね\r\n"
        "今夜はあたたかくして、\r\n"
        "ねてください。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenThanksDoctor[] =
        "ありがとう、ドクター。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorSaysHeIsDoingHisDutyAndAsksAboutEllensLegs[] =
        "いえ、いいんですよ。\r\n"
        "それより、\r\n"
        "足の方はどうですか？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenSaysHerLegsStillHurt[] =
        "足はいつも通りですよ。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliFallsSilentOverEllensLegs[] =
        "………{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorRegretsBeingUnableToHealEllensLegs[] =
        "すいません。\r\n"
        "ボクの力が足りないせいで…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenTellsDoctorNotToApologize[] =
        "ドクターがあやまることは\r\n"
        "ないんですよ。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliSaysDoctorAlreadyDoesMoreThanEnough[] =
        "そうですよ。\r\n"
        "ドクターはよくやってくれて\r\n"
        "います！{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorThanksElliAndEllen[] =
        "………ありがとう。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_ElliRemindsDoctorToReturnToClinic[] =
        "…ドクター、\r\n"
        "そろそろ病院に戻らないと。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_DoctorAgreesAndTellsEllenToTakeCare[] =
        "そうだね。\r\n"
        "それじゃ、お大事に。{Press}";
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
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_EllenThanksDoctor);
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
