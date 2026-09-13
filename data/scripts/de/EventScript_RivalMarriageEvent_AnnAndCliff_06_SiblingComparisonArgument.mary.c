#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffCriticizesAnnForNotActingFeminine[] =
        "Warum kannst du dich\r\n"
        "nicht mehr wie ein \r\n"
        "Mädchen benehmen?{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnDefendsHerPersonality[] =
        "Ich bin, wie ich bin!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffComparesAnnToHisSister[] =
        "Meine Schwester war\r\n"
        "mädchenhafter als du...{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnObjectsToComparisonAndQuestionsCliffsLove[] =
        "Ich bin nicht \r\n"
        "deine Schwester! \r\n"
        "Magst du mich nicht ?...{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffSaysHePaysAttentionToAnn[] =
        "Natürlich mag ich dich!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnSaysLoveMeansAcceptingHerAsSheIs[] =
        "Wenn du mich wirklich\r\n"
        "möchtest, dann würdest\r\n"
        "du mich nehmen, wie ich bin!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnDemandsCliffStopComparingHerToHisSister[] =
        "Du würdest mich auch\r\n"
        "nicht mit deiner \r\n"
        "Schwester vergleichen!\r\n"
        "Du würdest nicht {Press}\r\n"
        "wollen, dass ich mich\r\n"
        "änderte!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffApologizesForHurtingAnn[] =
        "Tut mir leid...\r\n"
        "Du hast Recht, Ann. {Press}\p"
        "Ich wollte deine Gefühle\r\n"
        "nicht verletzen. {Press}\p"
        "Ich mag dich wirklich \r\n"
        "genau so, wie du bist!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnApologizesForOverreacting[] =
        "...Tut mir auch leid. \r\n"
        "Ich wollte nicht so \r\n"
        "sauer werden.{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_AnnPromisesToTryActingMoreFeminine[] =
        "Und... ich versuche, mich \r\n"
        "etwas mädchenhafter\r\n"
        "zu benehmen. Ab und zu...{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_06_SiblingComparisonArgument_CliffAcceptsAnnPromise[] =
        "Schon ok...{Press}";
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
