#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliAsksIfPlayerNeedsHelp[] =
        "{Player}くん、\r\n"
        "どうしたの？\r\n"
        "どこか具合でも悪いの。{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliAcceptsPlayersReassurance[] =
        "そう、それならいいんだけど…{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_JeffCriesOutInPain[] =
        "イタタ………{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliChecksOnJeff[] =
        "ジェフさん！\r\n"
        "どうしたんですか？{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_JeffAsksForDoctor[] =
        "イタタ…\r\n"
        "ドクター呼んで…{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliCallsDoctor[] =
        "は…はい！\r\n"
        "ド…ドクター！\r\n"
        "ドクター！！{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliBringsJeffsMedicine[] =
        "先生、ジェフさんのお薬です。{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_DoctorThanksElli[] =
        "ああ、ありがとう………{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_DoctorDetectsWrongMedicine[] =
        "おいおい、\r\n"
        "ジェフさんの薬は\r\n"
        "これじゃないよ？{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliApologizesForMixup[] =
        "えっ…本当だわ。\r\n"
        "ご、ごめんなさい。\r\n"
        "すぐに取ってきます。{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_JeffWorriesAboutCondition[] =
        "大丈夫なのかな…{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliApologizesToDoctor[] =
        "ごめんなさい、先生。{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_DoctorReassuresElliAfterMistake[] =
        "ああ、まちがいは誰にでも\r\n"
        "あるからね。\r\n"
        "気にすることはないよ。{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_DoctorPrescribesCorrectMedicine[] =
        "じゃ、これを毎日飲んで\r\n"
        "ください。{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_JeffThanksDoctorAndLeaves[] =
        "ありがとう、ドクター。\r\n"
        "じゃ、店にもどるよ。{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliLosesConfidenceAfterMistake[] =
        "はぁ…\r\n"
        "また、まちがえちゃった…{Press}\p"
        "前にも、こんなことが\r\n"
        "あったのよ…こんなことで\r\n"
        "看護婦になれるのかしら？{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ChoiceEncourageElliAsGreatNurse[] =
        "いい看護婦さんになれるよ";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ChoiceHesitateToEncourageElli[] =
        "……………";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliThanksPlayerForEncouragement[] =
        "ありがとう、がんばるわ。\r\n"
        "じゃ、仕事に戻らなきゃ。{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliAcceptsNursingDoubts[] =
        "やっぱり、\r\n"
        "わたしにはムリなのかしら？{Press}";
};

void EventScript_LoveEvent_Elli_02_PurpleHeart_MedicineMixup(void)
{
    int var_0;
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(136), Y(107));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(136), Y(256), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(136), Y(107), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(244), Y(86), FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(136), Y(256), FACING_UP);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_ELLI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(140), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliAsksIfPlayerNeedsHelp);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliAcceptsPlayersReassurance);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_JeffCriesOutInPain);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
    MoveEntityYTo(ENTITY_JEFF, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_JEFF);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliChecksOnJeff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_JeffAsksForDoctor);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliCallsDoctor);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(232), Y(124));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(128), FACING_RIGHT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(216), Y(152), FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(216), Y(128), FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(232), Y(128), FACING_LEFT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliBringsJeffsMedicine);
    TalkClose();
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_DoctorThanksElli);
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_DoctorDetectsWrongMedicine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliApologizesForMixup);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_ELLI, Y(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_JeffWorriesAboutCondition);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_ELLI, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliApologizesToDoctor);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_DoctorReassuresElliAfterMistake);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_DoctorPrescribesCorrectMedicine);
    TalkClose();
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_JeffThanksDoctorAndLeaves);
    TalkClose();
    WaitFrames(40);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
    MoveEntityYTo(ENTITY_JEFF, Y(155), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_JEFF);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    MoveEntityXTo(ENTITY_JEFF, X(216), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_JEFF);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
    MoveEntityYTo(ENTITY_JEFF, Y(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_JEFF);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    HideEntity(ENTITY_JEFF);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(144), Y(144));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(144), Y(144), FACING_LEFT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(112), Y(144), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(244), Y(86), FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliLosesConfidenceAfterMistake);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Elli_02_PurpleHeart_ChoiceEncourageElliAsGreatNurse, gText_LoveEvent_Elli_02_PurpleHeart_ChoiceHesitateToEncourageElli);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ELLI, 3000);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliThanksPlayerForEncouragement);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityXTo(ENTITY_ELLI, X(64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_UP);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityXTo(ENTITY_ELLI, X(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(107), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            SetEntityEventScript(ENTITY_ELLI, EventScript_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupElliDialogue);
            SetEntityEventScript(ENTITY_DOCTOR, EventScript_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupDoctorDialogue);
            VarSet(VAR_ELLI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_ElliAcceptsNursingDoubts);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityXTo(ENTITY_ELLI, X(64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_UP);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityXTo(ENTITY_ELLI, X(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(107), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            SetEntityEventScript(ENTITY_ELLI, EventScript_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupElliDialogue);
            SetEntityEventScript(ENTITY_DOCTOR, EventScript_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupDoctorDialogue);
            VarSet(VAR_ELLI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
