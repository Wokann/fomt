#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffNoticesAnnApproaching[] =
        "Ha...?{Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnGreetsCliff[] =
        "Hello, Cliff. {Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffReturnsAnnsGreeting[] =
        "Hi, Ann...{Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnNotesTheyHaveNotTalkedAloneBefore[] =
        "We haven't had much chance \r\n"
        "to talk, you know. {Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffAgreesTheyHaveNotTalkedMuch[] =
        "...I guess.{Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnAsksWhyCliffCameToMineralTown[] =
        "So, what brings you to \r\n"
        "this village? {Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffDeclinesToExplainWhyHeCame[] =
        "...I don't really want to \r\n"
        "say...\r\n"
        "...Sorry...{Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnApologizesForAskingAboutCliffsPast[] =
        "No...I'm sorry for asking! \r\n"
        "It's none of my business.{Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnOffersHelpBeforeReturningToWork[] =
        "Just let me know if you need\r\n"
        "anything, alright? {Press}\p"
        "I have to get back to work.{Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffStopsAnnBeforeSheLeaves[] =
        "Oh, um...{Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnAsksWhatCliffNeeds[] =
        "...What?{Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffThanksAnnForHerKindness[] =
        "Thanks, Ann. {Press}";

    const char gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnAcceptsCliffsThanks[] =
        "Sure!{Press}";
};

void EventScript_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer(void)
{
    ChangeMap(MAP_INN_2F, X(256), Y(80));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(40), Y(248), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ANN, X(276), Y(192), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(276), Y(64), FACING_UP);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    WaitFrames(30);
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffNoticesAnnApproaching);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnGreetsCliff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffReturnsAnnsGreeting);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnNotesTheyHaveNotTalkedAloneBefore);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffAgreesTheyHaveNotTalkedMuch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnAsksWhyCliffCameToMineralTown);
    TalkClose();
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffDeclinesToExplainWhyHeCame);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnApologizesForAskingAboutCliffsPast);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnOffersHelpBeforeReturningToWork);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffStopsAnnBeforeSheLeaves);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_UP);
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnAsksWhatCliffNeeds);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_CliffThanksAnnForHerKindness);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_AnnAcceptsCliffsThanks);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(192), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    HideEntity(ENTITY_ANN);
    WaitFrames(90);
    PanCameraTo(X(40), Y(248), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_CLIFF, EventScript_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer_FollowupCliffDialogue);
    VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
