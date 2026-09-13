#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliSuggestsDoctorVisit[] =
        "ユウ、病院でドクターに\r\n"
        "診てもらいましょう。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_EllenAgreesDoctorVisit[] =
        "そうした方がいいわよ。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuInsistsHeFeelsFine[] =
        "いいって。元気だもん。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliPointsOutStusFever[] =
        "ダメよ！熱もあるじゃないの！{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuSaysElliWorriesTooMuch[] =
        "もう、お姉ちゃんは\r\n"
        "心配性だなぁ。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliPleadsStuToVisitClinic[] =
        "お願いだから病院行こう？{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuReluctantlyAgreesToClinicVisit[] =
        "お姉ちゃん…\r\n"
        "うん、わかった。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliGreetsPlayerAndRequestsHelp[] =
        "あっ、{Player}くん。\r\n"
        "ちょうどよかった。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliAsksPlayerToAccompanyStu[] =
        "ユウが病気みたいなの…\r\n"
        "悪いんだけど、ユウを病院まで\r\n"
        "連れていってくれるかな？{Press}\p"
        "わたしはドクターを\r\n"
        "探してくるから。{Press}\p"
        "今日は病院が休みだけど、\r\n"
        "ドクターにたのんでみるわ。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliThanksPlayerForHelping[] =
        "ありがとう。\r\n"
        "じゃあ、お願いね。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_DoctorDiagnosesColdAndPrescribesMedicine[] =
        "うん、大丈夫だよ。\r\n"
        "ただのカゼだよ。\r\n"
        "暖かくして寝てれば治るよ。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliRelievedByDiagnosis[] =
        "ホントですか？\r\n"
        "よかった～。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuSaysHeWasRight[] =
        "ほら、\r\n"
        "ボクの言ったとおりだろ？{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliScoldsStuForDismissiveResponse[] =
        "もう、この子ったら～。\r\n"
        "どれだけ心配したと\r\n"
        "思ってるのよ！{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuApologizesToElli[] =
        "うん…ごめんね。\r\n"
        "お姉ちゃん。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliRemindsStuToThankPlayer[] =
        "ほら、{Player}さんに、\r\n"
        "お礼を言って。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuThanksPlayer[] =
        "お兄ちゃん、ありがとう。{Press}";

    const char gText_NPCEvent_ElliAndStu_StuColdClinicVisit_DoctorAsksPlayerToEscortStuHome[] =
        "{Player}くん、念のために\r\n"
        "ユウくんを家まで送っていって\r\n"
        "くれないかな。{Press}";
};

void EventScript_NPCEvent_ElliAndStu_StuColdClinicVisit(void)
{
    ChangeMap(MAP_ELLEN_HOUSE, X(152), Y(120));
    SetEntityPosition(ENTITY_ELLEN, X(127), Y(97), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(154), Y(97), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_STU, X(157), Y(127), FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(121), Y(260), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliSuggestsDoctorVisit);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_EllenAgreesDoctorVisit);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuInsistsHeFeelsFine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliPointsOutStusFever);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuSaysElliWorriesTooMuch);
    TalkClose();
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliPleadsStuToVisitClinic);
    TalkClose();
    StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuReluctantlyAgreesToClinicVisit);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(127), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliGreetsPlayerAndRequestsHelp);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliAsksPlayerToAccompanyStu);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliThanksPlayerForHelping);
    TalkClose();
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
    MoveEntityXTo(ENTITY_ELLI, X(177), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    MoveEntityYTo(ENTITY_ELLI, Y(150), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
    MoveEntityXTo(ENTITY_ELLI, X(121), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    MoveEntityYTo(ENTITY_ELLI, Y(220), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    HideEntity(ENTITY_ELLI);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(211), Y(85));
    SetEntityPosition(ENTITY_DOCTOR, X(237), Y(85), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(195), Y(85), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_STU, X(216), Y(85), FACING_RIGHT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(200), Y(106), FACING_RIGHT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_DoctorDiagnosesColdAndPrescribesMedicine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliRelievedByDiagnosis);
    TalkClose();
    SetEntityFacing(ENTITY_STU, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuSaysHeWasRight);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliScoldsStuForDismissiveResponse);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuApologizesToElli);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityFacing(ENTITY_STU, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_ElliRemindsStuToThankPlayer);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_StuThanksPlayer);
    TalkClose();
    WaitFrames(30);
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_ElliAndStu_StuColdClinicVisit_DoctorAsksPlayerToEscortStuHome);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_NORTH_SIDE_TOWN, X(400), Y(168));
    SetEntityPosition(ENTITY_PLAYER, X(400), Y(168), FACING_DOWN);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    AddCharacterLove(CHARACTER_ELLI, 3000);
    AddNpcFriendship(CHARACTER_STU, 20);
    AddNpcFriendship(CHARACTER_ELLEN, 20);
    AddNpcFriendship(CHARACTER_DOCTOR, 20);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    MarkNpcSpokenTo(CHARACTER_STU);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    SetGameTime(15, 0);
    VarSet(VAR_ELLI_TREATS_STUS_COLD_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
