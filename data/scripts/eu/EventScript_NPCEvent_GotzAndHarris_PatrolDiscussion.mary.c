#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzAsksAboutHarrisPatrol[] =
        "How goes the patrol, Harris?{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisReportsTownIsSafe[] =
        "Mineral Town is safe \r\n"
        "and peaceful, as always. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzReportsMountainIsSafe[] =
        "Good to hear...\r\n"
        "Nothing wrong on the \r\n"
        "mountain, either. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisThanksGotzForPatrollingMountain[] =
        "It really should be me \r\n"
        "patrolling the mountain, \r\n"
        "not you. {Press}\p"
        "Thanks for helping out, \r\n"
        "Gotz. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsHeKnowsMountainAndVolunteered[] =
        "Don't worry about it. \r\n"
        "I know more about the \r\n"
        "mountain than you.{Press}\p"
        "Besides, patrolling it was\r\n"
        "my idea. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisMentionsDeathOfGotzWifeAndDaughter[] =
        "...........{Press}\p"
        "It's been quite a while\r\n"
        "since your wife and \r\n"
        "daughter died on the {Press}\r\n"
        "mountain. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsPatrolHonorsHisFamily[] =
        "...I think if I \r\n"
        "can prevent others from\r\n"
        "meeting the same fate...{Press}\p"
        "Those two will rest \r\n"
        "a little bit more \r\n"
        "peacefully...{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisAgreesTheyCanRestPeacefully[] =
        "...I think so, too. {Press}";
};

void EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion(void)
{
    EnableScriptedNpcControl();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_GOTZ, X(120), Y(80), FACING_LEFT);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    SetEntityPosition(ENTITY_HARRIS, X(100), Y(80), FACING_RIGHT);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(100), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzAsksAboutHarrisPatrol);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisReportsTownIsSafe);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzReportsMountainIsSafe);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisThanksGotzForPatrollingMountain);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsHeKnowsMountainAndVolunteered);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisMentionsDeathOfGotzWifeAndDaughter);
    TalkClose();
    StartEntityEffect(ENTITY_GOTZ, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsPatrolHonorsHisFamily);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisAgreesTheyCanRestPeacefully);
    TalkClose();
    EnableScriptedNpcControl();
    VarSet(VAR_GOTZ_AND_HARRIS_PATROL_DISCUSSION_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_GOTZ, EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupGotzDialogue);
    SetEntityEventScript(ENTITY_HARRIS, EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue);
    return;
}
