#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterUrgesCliffToOpenUpToTownspeople[] =
        "Cliff, why don't you try \r\n"
        "opening up to the people\r\n"
        "here in town more? They're{Press}\r\n"
        "all very nice, you know. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffSaysNewPeopleAreHardToTalkTo[] =
        "I don't know why, but it's \r\n"
        "hard to talk to \r\n"
        "new people.{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterNotesCliffTalksComfortablyWithHim[] =
        "But you don't mind \r\n"
        "talking to me!{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffSaysCarterIsEasyToTalkTo[] =
        "For some reason, you're \r\n"
        "so easy to talk to. You're \r\n"
        "not like other people. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterReflectsOnCliffCallingHimDifferent[] =
        "Not like other people...?{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnGreetsCarterAndCliff[] =
        "Hello, Carter! \r\n"
        "Oh, hi Cliff! {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterGreetsAnn[] =
        "Hi, Ann. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffGreetsAnnShyly[] =
        "...Hello. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksWhyAnnCameToChurch[] =
        "It's unusual for you to come\r\n"
        "to Church, Ann. \r\n"
        "Is anything wrong? {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnDeliversCartersLunch[] =
        "Didn't you order lunch? \r\n"
        "I brought it. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterApologizesForForgettingLunch[] =
        "I totally forgot! \r\n"
        "I'm sorry. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnHandsLunchToCarter[] =
        "Here you are. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAsksWhyCliffIsAtChurch[] =
        "What are you doing \r\n"
        "here, Cliff? {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffAvoidsExplainingWhyHeIsAtChurch[] =
        "Um...nothing much...{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterReactsToCliffsEvasion[] =
        "Hmm...{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksAnnForAFavor[] =
        "Ann...I'd like to ask \r\n"
        "something of you. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAsksWhatFavorCarterNeeds[] =
        "What? {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterExplainsCliffHasDifficultyMakingFriends[] =
        "It's about Cliff. {Press}\p"
        "He's very shy, so it's hard\r\n"
        "for him to make friends. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffProtestsCartersExplanation[] =
        "Hey...! Wait a second...{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksAnnToHelpCliffMeetTownspeople[] =
        "So, will you help him \r\n"
        "meet new people around \r\n"
        "town? {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAgreesToHelpCliffMakeFriends[] =
        "No problem! \r\n"
        "That's a favor it will be \r\n"
        "fun to do!{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnReturnsToWorkAndSaysGoodbye[] =
        "I have to get back now, \r\n"
        "but I'll see you later. {Press}\p"
        "Bye Carter. Bye, Cliff. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterSaysGoodbyeToAnn[] =
        "Bye now!{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffAwkwardlySaysGoodbyeToAnn[] =
        "...See you, I guess...{Press}";
};

void EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest(void)
{
    ChangeMap(MAP_CHURCH, X(184), Y(136));
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
    SetEntityPosition(ENTITY_ANN, X(172), Y(248), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(196), Y(120), FACING_LEFT);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(172), Y(120), FACING_RIGHT);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
    }
    if (GetEntityLocation(ENTITY_DOCTOR) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DOCTOR);
    }
    if (GetEntityLocation(ENTITY_DUKE) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DUKE);
    }
    if (GetEntityLocation(ENTITY_MANNA) == MAP_CHURCH)
    {
        HideEntity(ENTITY_MANNA);
    }
    if (GetEntityLocation(ENTITY_POPURI) == MAP_CHURCH)
    {
        HideEntity(ENTITY_POPURI);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterUrgesCliffToOpenUpToTownspeople);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffSaysNewPeopleAreHardToTalkTo);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterNotesCliffTalksComfortablyWithHim);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffSaysCarterIsEasyToTalkTo);
    TalkClose();
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterReflectsOnCliffCallingHimDifferent);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnGreetsCarterAndCliff);
    TalkClose();
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterGreetsAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffGreetsAnnShyly);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksWhyAnnCameToChurch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnDeliversCartersLunch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterApologizesForForgettingLunch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnHandsLunchToCarter);
    TalkClose();
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAsksWhyCliffIsAtChurch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffAvoidsExplainingWhyHeIsAtChurch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterReactsToCliffsEvasion);
    TalkClose();
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksAnnForAFavor);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAsksWhatFavorCarterNeeds);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterExplainsCliffHasDifficultyMakingFriends);
    TalkClose();
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_CLIFF, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffProtestsCartersExplanation);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksAnnToHelpCliffMeetTownspeople);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAgreesToHelpCliffMakeFriends);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnReturnsToWorkAndSaysGoodbye);
    TalkClose();
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterSaysGoodbyeToAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffAwkwardlySaysGoodbyeToAnn);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(248), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    HideEntity(ENTITY_ANN);
    WaitFrames(80);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_CLIFF, EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCliffDialogue);
    SetEntityEventScript(ENTITY_CARTER, EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCarterDialogue);
    VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
