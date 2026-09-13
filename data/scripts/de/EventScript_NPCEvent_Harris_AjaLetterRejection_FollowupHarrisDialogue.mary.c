#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisReturnsLateAtNight[] =
        "Tut mir leid, dass ich so\r\n"
        "spät noch störe. {Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisExplainsConfessionLetterAndReply[] =
        "Ich sehe nicht gut aus?\r\n"
        "Nicht ohne Grund.{Press}\p"
        "Nachdem ich mit dir \r\n"
        "gesprochen habe, habe ich\r\n"
        "Aja geschrieben, was {Press}\r\n"
        "ich für sie fühle. {Press}\p"
        "Heute hat sie geantwortet.{Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisRevealsAjaHasBoyfriend[] =
        "in der Stadt schon einen \r\n"
        "Freund hat!{Press}\p"
        "Schätze, ich habe \r\n"
        "kein Glück.{Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisThanksPlayerForHelpingHimMoveOn[] =
        "Gib dir keine Schuld.\r\n"
        "Ich bin dir eigentlich \r\n"
        "sehr dankbar. {Press}\p"
        "Hätte ich diesen Brief \r\n"
        "nicht geschrieben, hätte ich\r\n"
        "nie erfahren, dass Aja {Press}\r\n"
        "einen Freund hat.{Press}\p"
        "Jetzt weiß ich, dass\r\n"
        "ich keine Chance habe. Danke\r\n"
        "noch mal, {Player}. {Press}\r\n"
        "Vergiss nicht, deine Türen\r\n"
        "nachts zu schließen. {Press}";
};

void EventScript_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue(void)
{
    SetEntityPosition(ENTITY_HARRIS, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisReturnsLateAtNight);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisExplainsConfessionLetterAndReply);
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisRevealsAjaHasBoyfriend);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisThanksPlayerForHelpingHimMoveOn);
    TalkClose();
    AddNpcFriendship(CHARACTER_HARRIS, 20);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_WALK);
    SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
    MoveEntityXTo(ENTITY_HARRIS, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_UP);
    MoveEntityYTo(ENTITY_HARRIS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_HARRIS);
    HideEntity(ENTITY_HARRIS);
    VarSet(VAR_HARRIS_AJA_LETTER_REJECTION_FOLLOWUP_STATE, EVENT_LIFECYCLE_COMPLETED);
    MarkNpcSpokenTo(CHARACTER_HARRIS);
}
