#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliAsksIfPlayerNeedsHelp[] =
        "{Player}, ist  \r\n"
        "irgendetwas?{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliAcceptsPlayersReassurance[] =
        "Wenn du es sagst...{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_JeffCriesOutInPain[] =
        "Autsch!...{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliChecksOnJeff[] =
        "Jeff! Was ist los?!...{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_JeffAsksForDoctor[] =
        "Es tut weh! \r\n"
        "Ruf den Doktor...!!{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliCallsDoctor[] =
        "OK! \r\n"
        "Doktor! Doktor!{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliBringsJeffsMedicine[] =
        "Hier ist Jeffs Medizin. {Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_DoctorThanksElli[] =
        "Vielen Dank!{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_DoctorDetectsWrongMedicine[] =
        "Hey, das ist nicht  \r\n"
        "Jeffs Medizin! {Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliApologizesForMixup[] =
        "Du hast Recht! \r\n"
        "Tut mir sehr leid. \r\n"
        "Ich bringe sofort die{Press}\r\n"
        "Richtige. {Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_JeffWorriesAboutCondition[] =
        "Ob sie wohl in Ordnung ist?{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliApologizesToDoctor[] =
        "Tut mir sehr leid, Doktor. {Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_DoctorReassuresElliAfterMistake[] =
        "Jeder macht mal \r\n"
        "Fehler. Versuch nur,\r\n"
        "besser aufzupassen. {Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_DoctorPrescribesCorrectMedicine[] =
        "Nimm dies jeden Tag. {Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_JeffThanksDoctorAndLeaves[] =
        "Danke, Doktor. \r\n"
        "Nun muss ich zum\r\n"
        "Laden zurückgehen. {Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliLosesConfidenceAfterMistake[] =
        "Ich kann nicht fassen,\r\n"
        "dass ich denselben  \r\n"
        "Fehler gemacht habe!{Press}\p"
        "Ich hoffe, ich kann immer-\r\n"
        "noch Schwester werden...{Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ChoiceEncourageElliAsGreatNurse[] =
        "Du wirst mal gut!";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ChoiceHesitateToEncourageElli[] =
        "Hmm...";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliThanksPlayerForEncouragement[] =
        "Danke, dass du \r\n"
        "mich aufheiterst. \r\n"
        "Ich muss jetzt {Press}\r\n"
        "weiterarbeiten. {Press}";

    const char gText_LoveEvent_Elli_02_PurpleHeart_ElliAcceptsNursingDoubts[] =
        "Ich wusste, dass ich \r\n"
        "nicht dafür gemacht bin...{Press}";
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
