#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffCriticizesAnnForNotActingFeminine[] =
        "Why can't you act more\r\n"
        "like a girl?{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnDefendsHerPersonality[] =
        "I am who I am!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffComparesAnnToHisSister[] =
        "My sister was more \r\n"
        "girl-like than you are...{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnObjectsToComparisonAndQuestionsCliffsLove[] =
        "I'm not your sister! \r\n"
        "Don't you like me?...{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffSaysHePaysAttentionToAnn[] =
        "Of course I like you!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnSaysLoveMeansAcceptingHerAsSheIs[] =
        "If you really liked me, \r\n"
        "you'd like me just\r\n"
        "how I am! {Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnDemandsCliffStopComparingHerToHisSister[] =
        "And you wouldn't compare me\r\n"
        "with your sister, either!\r\n"
        "You wouldn't want me {Press}\r\n"
        "to change!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffApologizesForHurtingAnn[] =
        "I'm sorry...\r\n"
        "You're right, Ann. {Press}\p"
        "I didn't mean to hurt your\r\n"
        "feelings. {Press}\p"
        "I really do like you just \r\n"
        "the way you are!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnApologizesForOverreacting[] =
        "...I'm sorry too. \r\n"
        "I didn't mean to get \r\n"
        "so mad.{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnPromisesToTryActingMoreFeminine[] =
        "And...I'll even try to act \r\n"
        "a little more girl-like \r\n"
        "for you. Once in a while...{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffAcceptsAnnPromise[] =
        "That’s alright...{Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ANN, X(124), Y(192), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(104), Y(192), FACING_RIGHT);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(114), Y(192), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffCriticizesAnnForNotActingFeminine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnDefendsHerPersonality);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffComparesAnnToHisSister);
    TalkClose();
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnObjectsToComparisonAndQuestionsCliffsLove);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffSaysHePaysAttentionToAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnSaysLoveMeansAcceptingHerAsSheIs);
    TalkClose();
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnDemandsCliffStopComparingHerToHisSister);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffApologizesForHurtingAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnApologizesForOverreacting);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnPromisesToTryActingMoreFeminine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffAcceptsAnnPromise);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_UP);
    SetEntityFacing(ENTITY_CLIFF, FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(72), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_CLIFF, Y(72), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    HideEntity(ENTITY_ANN);
    HideEntity(ENTITY_CLIFF);
    PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_ANN_AND_CLIFF_SIBLING_COMPARISON_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
