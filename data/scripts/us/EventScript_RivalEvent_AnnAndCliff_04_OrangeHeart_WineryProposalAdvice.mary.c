#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnBringsCliffHisForgottenLunch[] =
        "You forgot to bring  \r\n"
        "lunch along today, didn't \r\n"
        "you? Here it is. {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffThanksAnnAndApologizesForTheTrouble[] =
        "Thanks!\r\n"
        "Sorry to trouble you. {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnSaysBringingLunchWasNoTrouble[] =
        "It's no trouble at all. {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeWelcomesAnnToTheWinery[] =
        "Hi, Ann. \r\n"
        "Welcome. {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnGreetsDukeAndApologizesForTheVisit[] =
        "Sorry to bug you, Duke. {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeAsksWhyAnnCame[] =
        "What's your errand?{Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffExplainsAnnBroughtHisLunch[] =
        "I forgot my lunch, so Ann \r\n"
        "brought it for me. {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeTeasesAnnAndCliffAsNewlyweds[] =
        "That's nice of you, Ann. \r\n"
        "You two are almost like \r\n"
        "an old married couple! {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnOrCliffFallsSilentAtDukesNewlywedRemark[] =
        "..........{Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffRebukesDukeForTeasingThem[] =
        "Duke! {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeAsksWhatIsWrongWithHisRemark[] =
        "What?...{Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnLeavesTheWineryEmbarrassed[] =
        "I'll be getting back, now. \r\n"
        "Bye. {Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffCallsAfterAnnAsSheLeaves[] =
        "Ann! Wait...{Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeSaysTheyLoveEachOtherAndSuggestsAProposal[] =
        "She likes you...I can tell. \r\n"
        "You like her, too, right?{Press}\p"
        "Why bother waiting? \r\n"
        "You could go propose to her\r\n"
        "right now, if you wanted...{Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffRejectsDukesProposalSuggestion[] =
        "Wh-what are you talking \r\n"
        "about!?...{Press}";

    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeCallsCliffLikeASonAndApprovesAnn[] =
        "You're like my own son, \r\n"
        "you know. {Press}\p"
        "I think Ann and you would \r\n"
        "make a good couple. {Press}";
};

void EventScript_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice(void)
{
    ChangeMap(MAP_AJA_WINERY_STORAGE_1F, X(120), Y(96));
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
    SetEntityPosition(ENTITY_ANN, X(120), Y(208), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(170), Y(68), FACING_UP);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(120), Y(208), FACING_UP);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(132), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityXTo(ENTITY_ANN, X(170), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityXTo(ENTITY_ANN, X(194), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(68), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
    WaitFrames(60);
    SetEntityFacing(ENTITY_CLIFF, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnBringsCliffHisForgottenLunch);
    TalkClose();
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffThanksAnnAndApologizesForTheTrouble);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnSaysBringingLunchWasNoTrouble);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    WaitFrames(60);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
    MoveEntityYTo(ENTITY_DUKE, Y(132), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityFacing(ENTITY_DUKE, FACING_RIGHT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
    MoveEntityXTo(ENTITY_DUKE, X(170), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityFacing(ENTITY_DUKE, FACING_UP);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
    MoveEntityYTo(ENTITY_DUKE, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeWelcomesAnnToTheWinery);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnGreetsDukeAndApologizesForTheVisit);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeAsksWhyAnnCame);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffExplainsAnnBroughtHisLunch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeTeasesAnnAndCliffAsNewlyweds);
    TalkClose();
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnOrCliffFallsSilentAtDukesNewlywedRemark);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffRebukesDukeForTeasingThem);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeAsksWhatIsWrongWithHisRemark);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
    SetEntityFacing(ENTITY_CLIFF, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnLeavesTheWineryEmbarrassed);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffCallsAfterAnnAsSheLeaves);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(110), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityXTo(ENTITY_ANN, X(160), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    SetEntityFacing(ENTITY_DUKE, FACING_DOWN);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(140), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityXTo(ENTITY_ANN, X(120), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(208), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    HideEntity(ENTITY_ANN);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    WaitFrames(30);
    SetEntityFacing(ENTITY_DUKE, FACING_UP);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeSaysTheyLoveEachOtherAndSuggestsAProposal);
    TalkClose();
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_CliffRejectsDukesProposalSuggestion);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_DukeCallsCliffLikeASonAndApprovesAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_AnnOrCliffFallsSilentAtDukesNewlywedRemark);
    TalkClose();
    PanCameraTo(X(120), Y(132), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(132), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_CLIFF, EventScript_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_FollowupCliffDialogue);
    SetEntityEventScript(ENTITY_DUKE, EventScript_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_FollowupDukeDialogue);
    VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
