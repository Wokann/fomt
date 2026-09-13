#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzAsksAboutHarrisPatrol[] =
        "Wie läuft die Streife, \r\n"
        "Harris?{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisReportsTownIsSafe[] =
        "Mineralstadt ist sicher\r\n"
        "und friedlich, wie immer.{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzReportsMountainIsSafe[] =
        "Gut zu hören...\r\n"
        "Auf dem Berg ist auch\r\n"
        "alles in Ordnung. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisThanksGotzForPatrollingMountain[] =
        "Ich sollte wirklich den\r\n"
        "Berg kontrollieren,\r\n"
        "nicht du. {Press}\p"
        "Danke fürs\r\n"
        "Aushelfen, Gotz. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsHeKnowsMountainAndVolunteered[] =
        "Keine Ursache. Ich weiß\r\n"
        "mehr über den Berg als du.{Press}\p"
        "Außerdem war die\r\n"
        "Streife meine Idee. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisMentionsDeathOfGotzWifeAndDaughter[] =
        "Es ist ganz schön lange\r\n"
        "her, seit deine Frau und\r\n"
        "deine Tochter auf dem{Press}\r\n"
        "Berg gestorben sind. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsPatrolHonorsHisFamily[] =
        "...Ich denke, wenn ich\r\n"
        "anderen dieses Schicksal\r\n"
        "ersparen kann... werden{Press}\p"
        "die beiden ein wenig\r\n"
        "friedlicher ruhen...{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisAgreesTheyCanRestPeacefully[] =
        "...Das denke ich auch.{Press}";
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
