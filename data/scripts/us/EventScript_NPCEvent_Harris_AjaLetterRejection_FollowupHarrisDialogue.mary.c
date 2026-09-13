#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisReturnsLateAtNight[] =
        "Sorry to bother you\r\n"
        "so late. {Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisExplainsConfessionLetterAndReply[] =
        "I don't look so well?\r\n"
        "Well, there's a reason.{Press}\p"
        "After talking to you, I \r\n"
        "wrote to Aja and told her\r\n"
        "everything how I feel {Press}\r\n"
        "about her. {Press}\p"
        "Her response came today.{Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisRevealsAjaHasBoyfriend[] =
        "Aja says that she already \r\n"
        "has a boyfriend \r\n"
        "in the city!{Press}\p"
        "No luck for me, I guess.{Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisThanksPlayerForHelpingHimMoveOn[] =
        "No, don't blame yourself. \r\n"
        "You see, I'm actually very \r\n"
        "thankful to you. {Press}\p"
        "If I hadn't written that \r\n"
        "letter, I never would have \r\n"
        "known Aja was in love{Press}\r\n"
        "with someone else.{Press}\p"
        "But, now I know\r\n"
        "to give up on her. Thanks \r\n"
        "again, {Player}. {Press}\r\n"
        "Don't forget to lock you \r\n"
        "doors at night. {Press}";
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
