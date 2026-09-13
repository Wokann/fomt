#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_01_BlackHeart_StuOffersToShowElliSomething[] =
        "Ich möchte dir etwas\r\n"
        "Schönes zeigen, Schwester!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliAsksWhatStuFound[] =
        "Was ist es?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuShowsElliBug[] =
        "Hier!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliScoldsStuForPrank[] =
        "Stu! \r\n"
        "Spiel nicht solche \r\n"
        "Spielchen mit mir! {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuTeasesAngryElli[] =
        "Werd nicht gleich sauer! \r\n"
        "Du willst keine grauen\r\n"
        "Haare kriegen, oder?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliReactsToStuLeaving[] =
        "Was!!??...{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliCallsAfterStu[] =
        "Hey! \r\n"
        "Wo willst du denn hin!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliAsksIfPlayerIsNew[] =
        "Hallo. Du bist \r\n"
        "nicht von hier, oder?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliRecognizesNewFarmer[] =
        "Oh, tut mir Leid. \r\n"
        "Du musst der Neue auf\r\n"
        "der Farm sein, richtig?{Press}\p"
        "Ich habe Gerüchte \r\n"
        "über dich gehört! {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliIntroducesHerselfAndClinic[] =
        "Ich heiße Elli. \r\n"
        "Ich arbeite in der Klinik.{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliAsksIfPlayerFeelsUnwell[] =
        "Fühlst du dich unwohl,\r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliRecommendsRegularCheckups[] =
        "Wirklich? Es ist\r\n"
        "immer besser, sich vom \r\n"
        "Doktor untersuchen zu {Press}\r\n"
        "lassen, wenn man müde ist.{Press}\r\n"
        "Pass auf dich auf. {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliChangesSubject[] =
        "Übrigens...{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliRevealsStuIsHiding[] =
        "Merkst du, dass sich \r\n"
        "jemand hinter dir versteckt?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuAsksElliNotToBeAngry[] =
        "Werd nicht gleich sauer!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliComplainsAboutStusPranks[] =
        "Stu ist so schwierig!\r\n"
        "Tut mir Leid, dass er \r\n"
        "eine Plage ist!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuExplainsHisIntent[] =
        "Werd nicht so sauer. \r\n"
        "Ich habe dir nur einen\r\n"
        "Käfer gezeigt!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliExplainsFearOfBugs[] =
        "Weißt du nicht, dass \r\n"
        "ich Käfer hasse?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuThoughtElliWouldLikeBug[] =
        "Ich dachte, diesen magst\r\n"
        "du vielleicht!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliWarnsStuNotToPrankHer[] =
        "Mach keine Scherze mit\r\n"
        "mir, Stu! {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuAsksPlayerToTakeHisSide[] =
        "Du verstehst mich oder\r\n"
        "nicht, {Player}?\r\n"
        "Du bist ein Junge.{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ChoiceAgreeWithStu[] =
        "Na klar.";

    const char gText_LoveEvent_Elli_01_BlackHeart_ChoiceDisagreeWithStu[] =
        "Eher nicht.";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuLikesPlayerAndInvitesPlay[] =
        "Ich mag dich! \r\n"
        "Spielen wir. {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliSaysNotToHumorStu[] =
        "Du musst ihm nicht zu-\r\n"
        "stimmen, {Player}.{Press}\p"
        "Er wird dich nur \r\n"
        "vereimern. {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuCriesAfterRejection[] =
        "..........\r\n"
        "Waaah!!....{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliExplainsStusCrying[] =
        "Kümmer dich nicht um \r\n"
        "sein Geschrei. Er ist nur \r\n"
        "nicht gewöhnt, von An-{Press}\r\n"
        "deren geschimpft zu werden. {Press}\p"
        "Vielleicht hört er jetzt \r\n"
        "auf, mir so viele  \r\n"
        "Streiche zu spielen!{Press}";
};

void EventScript_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu(void)
{
    int var_0;
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(120), Y(140));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(272), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(120), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_STU, X(180), Y(272), FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(244), Y(86), FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    MoveEntityYTo(ENTITY_STU, Y(212), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityFacing(ENTITY_STU, FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    MoveEntityXTo(ENTITY_STU, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityFacing(ENTITY_STU, FACING_UP);
    StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_STU, FACING_LEFT);
    MoveEntityXTo(ENTITY_STU, X(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityFacing(ENTITY_STU, FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    MoveEntityYTo(ENTITY_STU, Y(140), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityFacing(ENTITY_STU, FACING_RIGHT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuOffersToShowElliSomething);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliAsksWhatStuFound);
    TalkClose();
    StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuShowsElliBug);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliScoldsStuForPrank);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuTeasesAngryElli);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliReactsToStuLeaving);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    PanCameraTo(X(120), Y(200), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    SetEntityFacing(ENTITY_STU, FACING_DOWN);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    MoveEntityYTo(ENTITY_STU, Y(216), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityFacing(ENTITY_STU, FACING_RIGHT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    MoveEntityXTo(ENTITY_STU, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityFacing(ENTITY_STU, FACING_UP);
    WaitForCameraMovement();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliCallsAfterStu);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_ELLI, Y(176), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    if (HasMetNpc(CHARACTER_ELLI) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        ShowTalkHeartIndicator(CHARACTER_ELLI);
        TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliAsksIfPlayerIsNew);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        ShowTalkHeartIndicator(CHARACTER_ELLI);
        TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliRecognizesNewFarmer);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        ShowTalkHeartIndicator(CHARACTER_ELLI);
        TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliIntroducesHerselfAndClinic);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        ShowTalkHeartIndicator(CHARACTER_ELLI);
        TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliAsksIfPlayerFeelsUnwell);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        ShowTalkHeartIndicator(CHARACTER_ELLI);
        TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliRecommendsRegularCheckups);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliChangesSubject);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliRevealsStuIsHiding);
    TalkClose();
    StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuAsksElliNotToBeAngry);
    TalkClose();
    SetEntityFacing(ENTITY_STU, FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    MoveEntityXTo(ENTITY_STU, X(104), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityFacing(ENTITY_STU, FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    MoveEntityYTo(ENTITY_STU, Y(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliComplainsAboutStusPranks);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuExplainsHisIntent);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliExplainsFearOfBugs);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuThoughtElliWouldLikeBug);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliWarnsStuNotToPrankHer);
    TalkClose();
    SetEntityFacing(ENTITY_STU, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuAsksPlayerToTakeHisSide);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    WaitFrames(60);
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Elli_01_BlackHeart_ChoiceAgreeWithStu, gText_LoveEvent_Elli_01_BlackHeart_ChoiceDisagreeWithStu);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_DOCTOR, 20);
            AddNpcFriendship(CHARACTER_STU, 20);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuLikesPlayerAndInvitesPlay);
            TalkClose();
            SetEntityFacing(ENTITY_STU, FACING_DOWN);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
            MoveEntityYTo(ENTITY_STU, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            WaitForEntityMovement(ENTITY_STU);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            SetEntityFacing(ENTITY_STU, FACING_RIGHT);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
            MoveEntityXTo(ENTITY_STU, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_STU);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            SetEntityFacing(ENTITY_STU, FACING_DOWN);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
            MoveEntityYTo(ENTITY_STU, Y(335), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_STU);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            HideEntity(ENTITY_STU);
            StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_ANGRY, FALSE);
            WaitFrames(60);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliSaysNotToHumorStu);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_STU);
            SetEntityEventScript(ENTITY_ELLI, EventScript_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupElliDialogue);
            SetEntityEventScript(ENTITY_DOCTOR, EventScript_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupDoctorDialogue);
            VarSet(VAR_ELLI_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ELLI, 3000);
            AddNpcFriendship(CHARACTER_STU, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_CRYING);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_StuCriesAfterRejection);
            TalkClose();
            SetEntityFacing(ENTITY_STU, FACING_DOWN);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
            MoveEntityYTo(ENTITY_STU, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            WaitForEntityMovement(ENTITY_STU);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            SetEntityFacing(ENTITY_STU, FACING_RIGHT);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
            MoveEntityXTo(ENTITY_STU, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_STU);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            SetEntityFacing(ENTITY_STU, FACING_DOWN);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
            MoveEntityYTo(ENTITY_STU, Y(335), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_STU);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            HideEntity(ENTITY_STU);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_ElliExplainsStusCrying);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_STU);
            SetEntityEventScript(ENTITY_ELLI, EventScript_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupElliDialogue);
            SetEntityEventScript(ENTITY_DOCTOR, EventScript_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupDoctorDialogue);
            VarSet(VAR_ELLI_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
