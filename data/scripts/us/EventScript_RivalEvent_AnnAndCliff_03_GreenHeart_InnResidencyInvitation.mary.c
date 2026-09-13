#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougWondersHowLongCliffCanStay[] =
        "I wonder how long Cliff will\r\n"
        "be able to stay...? {Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnAsksWhyDougSuddenlyWorriesAboutCliff[] =
        "What?\r\n"
        "What's wrong all of\r\n"
        "a sudden? {Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougSaysCliffSeemsHauntedByHisPastAndHopesHeStays[] =
        "Sometimes he looks like he's\r\n"
        "remembering something \r\n"
        "unpleasant, right? {Press}\p"
        "I think he must have had \r\n"
        "something really bad happen \r\n"
        "to him before he came here.{Press}\p"
        "I hope he stays, so we can \r\n"
        "make him forget! {Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnAgreesWithDougsConcernForCliff[] =
        "You're right...{Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_CliffAsksWhatDougAndAnnAreDiscussing[] =
        "What are you talking about?{Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougInitiallyAvoidsAnsweringCliff[] =
        "Nothing in particular...{Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnAsksHowLongCliffPlansToStay[] =
        "We were wondering how long\r\n"
        "you were planning on \r\n"
        "staying here...{Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_CliffReactsToBeingAskedAboutStaying[] =
        "What?{Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnInvitesCliffToLiveAtTheInnPermanently[] =
        "Well, Dad and I were \r\n"
        "thinking that...if you \r\n"
        "wanted to... {Press}\r\n"
        "You could stay forever...{Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougAsksWhetherCliffWillAcceptTheirInvitation[] =
        "What do you think, Cliff?{Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_CliffThanksDougAndAnnAndAsksIfTheyAreCertain[] =
        "Doug...Ann...\r\n"
        "Thank you so much. \r\n"
        "Are you sure?{Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougConfirmsCliffCanStay[] =
        "Of course! {Press}";

    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnWelcomesCliffToHisNewHome[] =
        "Make yourself at home,\r\n"
        "Cliff.{Press}";
};

void EventScript_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation(void)
{
    ChangeMap(MAP_INN_1F, X(250), Y(112));
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
    SetEntityPosition(ENTITY_ANN, X(292), Y(80), FACING_RIGHT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(315), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(315), Y(80), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougWondersHowLongCliffCanStay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnAsksWhyDougSuddenlyWorriesAboutCliff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougSaysCliffSeemsHauntedByHisPastAndHopesHeStays);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnAgreesWithDougsConcernForCliff);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    WaitFrames(60);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WALK);
    MoveEntityYTo(ENTITY_CLIFF, Y(116), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_CliffAsksWhatDougAndAnnAreDiscussing);
    TalkClose();
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougInitiallyAvoidsAnsweringCliff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnAsksHowLongCliffPlansToStay);
    TalkClose();
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_CliffReactsToBeingAskedAboutStaying);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnInvitesCliffToLiveAtTheInnPermanently);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougAsksWhetherCliffWillAcceptTheirInvitation);
    TalkClose();
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_CliffThanksDougAndAnnAndAsksIfTheyAreCertain);
    TalkClose();
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_HAPPY, FALSE);
    StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_DougConfirmsCliffCanStay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_AnnWelcomesCliffToHisNewHome);
    TalkClose();
    PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_CLIFF, EventScript_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupCliffDialogue);
    SetEntityEventScript(ENTITY_DOUG, EventScript_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupDougDialogue);
    SetEntityEventScript(ENTITY_ANN, EventScript_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupAnnDialogue);
    VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
