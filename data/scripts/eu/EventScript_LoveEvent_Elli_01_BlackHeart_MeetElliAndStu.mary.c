#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_01_BlackHeart_StuOffersToShowElliSomething[] =
        "I want to show you something\r\n"
        "nice, Sis!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliAsksWhatStuFound[] =
        "What is it?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuShowsElliBug[] =
        "Here!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliScoldsStuForPrank[] =
        "Stu! \r\n"
        "Don't play tricks on me \r\n"
        "like that! {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuTeasesAngryElli[] =
        "Don't get so mad, Sis!\r\n"
        "You don't want to get\r\n"
        "grey hair, do you? {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliReactsToStuLeaving[] =
        "What!!??...{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliCallsAfterStu[] =
        "Hey! Where are you going!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliAsksIfPlayerIsNew[] =
        "Hello. You're not from \r\n"
        "around here, are you?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliRecognizesNewFarmer[] =
        "Oh, I'm sorry. \r\n"
        "You must be the new fellow\r\n"
        "at the farm, right? {Press}\p"
        "I've heard rumors \r\n"
        "about you! {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliIntroducesHerselfAndClinic[] =
        "My name's Elli. \r\n"
        "I work at the Clinic. {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliAsksIfPlayerFeelsUnwell[] =
        "Are you feeling unwell, \r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliRecommendsRegularCheckups[] =
        "Really? It's always a good\r\n"
        "idea to have the Doctor \r\n"
        "look at you if you're {Press}\r\n"
        "feeling very tired. {Press}\r\n"
        "Take care of yourself. {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliChangesSubject[] =
        "By the way...{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliRevealsStuIsHiding[] =
        "Do you realize there's \r\n"
        "someone hiding behind you?{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuAsksElliNotToBeAngry[] =
        "Don't get so mad, Sis!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliComplainsAboutStusPranks[] =
        "Stu is so much trouble!\r\n"
        "I'm sorry he's a bother!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuExplainsHisIntent[] =
        "Don't get so mad. \r\n"
        "All I did was show you\r\n"
        "a bug!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliExplainsFearOfBugs[] =
        "Don't you know \r\n"
        "I hate bugs? {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuThoughtElliWouldLikeBug[] =
        "I thought maybe you\r\n"
        "would like that one!{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliWarnsStuNotToPrankHer[] =
        "Don't play games with me,\r\n"
        "Stu! {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuAsksPlayerToTakeHisSide[] =
        "You understand me, don't\r\n"
        "you, {Player}?\r\n"
        "You're a boy, like me.{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ChoiceAgreeWithStu[] =
        "Sure I do.";

    const char gText_LoveEvent_Elli_01_BlackHeart_ChoiceDisagreeWithStu[] =
        "Not really.";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuLikesPlayerAndInvitesPlay[] =
        "I like you! \r\n"
        "Let's play together later. {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliSaysNotToHumorStu[] =
        "You don't need to humor him,\r\n"
        "{Player}.{Press}\p"
        "He'll just start playing \r\n"
        "his pranks on you, instead. {Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_StuCriesAfterRejection[] =
        "..........\r\n"
        "Waaah!!....{Press}";

    const char gText_LoveEvent_Elli_01_BlackHeart_ElliExplainsStusCrying[] =
        "Don't worry about his \r\n"
        "crying. He's just not used \r\n"
        "to being scolded by other {Press}\r\n"
        "people, that's all. {Press}\p"
        "Maybe now he'll stop \r\n"
        "playing so many pranks \r\n"
        "on me!{Press}";
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
